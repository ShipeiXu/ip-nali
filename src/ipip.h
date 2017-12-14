#ifndef __IPIP_H__
#define __IPIP_H__

typedef unsigned char byte;
typedef unsigned int uint;
#define B2IL(b) (((b)[0] & 0xFF) | (((b)[1] << 8) & 0xFF00) | (((b)[2] << 16) & 0xFF0000) | (((b)[3] << 24) & 0xFF000000))
#define B2IU(b) (((b)[3] & 0xFF) | (((b)[2] << 8) & 0xFF00) | (((b)[1] << 16) & 0xFF0000) | (((b)[0] << 24) & 0xFF000000))

struct ipip {
    byte *data;
    byte *index;
    uint *flag;
    uint offset;
};

int destroy(void);
int init(const char *ipdb);
int find(const char *ip, char *result);

#endif
