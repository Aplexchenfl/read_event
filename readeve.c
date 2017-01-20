#include <stdio.h>
#include <linux/input.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>



int main(int argc, char **argv)
{
    struct readdata
    {
        struct timeval time;
        unsigned short type;
        unsigned short code;
        int value;
    } tsdata;

    int reval, evefd;

    evefd = open(argv[1], O_RDONLY);
    if (evefd < 0)
    {
        perror(argv[1]);
        return -1;
    }

    while (1)
    {
        reval = read(evefd, &tsdata, sizeof(tsdata));
        switch(tsdata.code)
        {
        case ABS_Y:
            printf("typd: %d      code: %d     value_Y: %d\n", tsdata.type, tsdata.code, tsdata.value);
            break;
        case ABS_X:
            printf("typd: %d      code: %d     value_X: %d\n", tsdata.type, tsdata.code, tsdata.value);
            break;
        case ABS_PRESSURE:
            printf("typd: %d      code: %d     value_PRESSURE: %d\n", tsdata.type, tsdata.code, tsdata.value);
            break;
        default:
            break;
        }

    //usleep(10);
    }

    return 0;
}

