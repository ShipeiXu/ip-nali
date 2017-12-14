#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ipip.h"

static struct ipip ipip;

int destroy() {
    if (!ipip.offset) {
        return 0;
    }

    free(ipip.flag);
    free(ipip.index);
    free(ipip.data);
    ipip.offset = 0;
    return 0;
}

int init(const char *ipdb) 
{
    if (ipip.offset) {
        return 0;
    }

    FILE *file = fopen(ipdb, "rb");
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    ipip.data = (byte *) malloc(size * sizeof(byte));
    size_t r = fread(ipip.data, sizeof(byte), (size_t) size, file);

    if (r == 0) {
        return 0;
    }

    fclose(file);

    uint length = B2IU(ipip.data);

    ipip.index = (byte *) malloc(length * sizeof(byte));
    memcpy(ipip.index, ipip.data + 4, length);

    ipip.offset = length;

    ipip.flag = (uint *) malloc(256 * sizeof(uint));
    memcpy(ipip.flag, ipip.index, 256 * sizeof(uint));

    return 0;
}

int find(const char *ip, char *result) 
{
    uint ips[4];
    int num = sscanf(ip, "%d.%d.%d.%d", &ips[0], &ips[1], &ips[2], &ips[3]);
    if (num == 4) {
        uint ip_prefix_value = ips[0];
        uint ip2long_value = B2IU(ips);
        uint start = ipip.flag[ip_prefix_value];
        uint max_comp_len = ipip.offset - 1028;
        uint index_offset = 0;
        uint index_length = 0;
        uint count = 0;
        for (start = start * 8 + 1024; start < max_comp_len; start += 8) {
            if (B2IU(ipip.index + start) >= ip2long_value) {
                index_offset = B2IL(ipip.index + start + 4) & 0x00FFFFFF;
                index_length = ipip.index[start + 7];
                break;
            }
            count ++;
        }
        memcpy(result, ipip.data + ipip.offset + index_offset - 1024, index_length);
        result[index_length] = '\0';
    }
    return 0;
}
