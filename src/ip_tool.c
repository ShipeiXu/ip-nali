#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MIN_VALID_IP_VALUE 0x00000000
#define MAX_VALID_IP_VALUE 0xffffffff

int main(int argc, char **argv)
{
    struct in_addr result;
    int ret = 0;
    unsigned long ip;
    char *endptr; 
    char input[INET_ADDRSTRLEN] = {'0'};
    char output[INET_ADDRSTRLEN] = {'0'};

    if (argc != 2) {
        fprintf(stderr, "usage: tool ip|a.b.c.d\n");
        exit(-1);
    }

    if (strnlen(argv[1], sizeof(input)) >= 16) {
        fprintf(stderr, "param %s is error!\n", argv[1]);
        exit(-1);
    }

    ret = snprintf(input, sizeof(input), "%s", argv[1]); 
    if (ret >= sizeof(input)) {
        fprintf(stderr, "param %s is error!\n", argv[1]);
        exit(-1);
    }

    ip = strtol(input, &endptr, 0);
    if ((errno == ERANGE && (ip == LONG_MAX || ip == LONG_MIN)) 
            || (ip == 0 && errno != 0)) {
        perror ("failed parse params!");
        exit(-1);
    }

    if (*endptr == '\0') {
        if ( ip < MIN_VALID_IP_VALUE || (ip > MAX_VALID_IP_VALUE)) {
            fprintf(stderr, "param %s is too min or too big!\n", argv[1]);
            exit(-1);
        }
        result.s_addr = htonl(ip);
        inet_ntop(PF_INET, &result, output, sizeof(output));
        printf("%s\n", output);
    } else {
        ret = inet_pton(PF_INET, input, &result);
        if (ret != 1) {
            fprintf(stderr, "param %s is invalid!\n", argv[1]);
            exit(-1);
        }
        printf("0x%x, %u\n", ntohl(result.s_addr), ntohl(result.s_addr));
    }

    return 0;
}
