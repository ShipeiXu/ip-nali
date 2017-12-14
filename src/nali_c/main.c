/*
 * read from stdin
 * analyse  line to line
 * fprintf to stdout
 */

#include <stdio.h>
#include <unistd.h>
#include "ipip.h"

static char *optstring = "h:f:";

static void help(void) {
    printf("-h ip to translate\n");
    printf("-f file to translate\n");
    printf("defautl read from stdin\n");
}

int process_readin(void) {
    return 0;
}

int main(int argc, char **argv) {
    int ret, ch;

    /*
     * read from stdin
     */
    if (argc == 1) {
        ret = process_readin();

        return ret;
    } 

    while ((ch = getopt(argc, argv, optstring)) != -1) {
        switch (ch) {
            case 'h':
                break;
            case 'f':
                break;
            case '?':
                help();
                break;
            default:
                break;
        }
    }


    init(IP_BASE);
    //find(ip, result);
    //printf("%s -> %s\n", ip, result);
    destroy();

    return 0;
}
