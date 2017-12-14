#include <stdio.h>

#include "ipip.h"

/*
 * read from stdin
 * analyse  line to line
 * fprintf to stdout
 */
int main(int argc, char **argv) {
    char *ip = "192.168.3.55";
    char result[128] = {0};

    init("mydata4vipweek2.dat");
    find(ip, result);
    printf("%s -> %s\n", ip, result);
    destroy();

    return 0;
}
