# ip-tools
all usages about ipv4 and ipv6

# 用法:

# 下载与编译（posix标准环境，linux、unix、mac均可）
- git clone https://github.com/ShipeiXu/ip-tools.git
- cd ip-tools/src
- gcc ip_tool.c
  即可得到可执行文件 a.out

# 运行参数
- 点分十进制ipv4地址或者32位数的ipv4地址，并做了简单的容错处理，输入如果是32位数，则输出点分十进制，反之亦可：

➜  src git:(master) ✗ ./a.out 113.31.27.229
0x711f1be5, 1897864165


➜  src git:(master) ✗ ./a.out 1897864165
113.31.27.229
