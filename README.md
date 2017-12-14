# 1. iptool

> 点分十进制与32位数的转化

### 下载与编译（posix标准环境，linux、unix、mac均可）

> git clone https://github.com/ShipeiXu/ip-tools.git

> cd ip-tools/src

> gcc ip_tool.c
 
> 即可得到可执行文件 a.out

### 运行参数
> 点分十进制ipv4地址或者32位数的ipv4地址，并做了简单的容错处理，输入如果是32位数，则输出点分十进制，反之亦可：

> ➜  src git:(master) ✗ ./a.out 113.31.27.229

> 0x711f1be5, 1897864165

> ➜  src git:(master) ✗ ./a.out 1897864165

> 113.31.27.229

> 如果是十六进制，需要使用0x010F030D的格式。

# 2. nali 工具
- 基于ipip提供的工具，制作的更方便易用的ip查询工具。

- ip库请前往ipip下载：https://www.ipip.net/index.html#down

- 示例: dig www.google.com | nali

➜  src git:(master) ✗ dig www.google.com | nali


; <<>> DiG 9.11.2 <<>> www.google.com

;; global options: +cmd

;; Got answer:

;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 22163

;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 4, ADDITIONAL: 4

;; QUESTION SECTION:

;www.google.com.    		IN	A

;; ANSWER SECTION:

www.google.com.		43	IN	A	69.63.186.30 (美国 弗吉尼亚州 阿什本  facebook.com)

;; AUTHORITY SECTION:

google.com.		63454	IN	NS	ns2.google.com.

google.com.		63454	IN	NS	ns1.google.com.

google.com.		63454	IN	NS	ns3.google.com.

google.com.		63454	IN	NS	ns4.google.com.

;; ADDITIONAL SECTION:

ns1.google.com.		63394	IN	A	216.239.32.10 (GOOGLE.COM GOOGLE.COM   google.com)

ns2.google.com.		63400	IN	A	216.239.34.10 (GOOGLE.COM GOOGLE.COM   google.com)

ns3.google.com.		63406	IN	A	216.239.36.10 (GOOGLE.COM GOOGLE.COM   google.com)

ns4.google.com.		63554	IN	A	216.239.38.10 (GOOGLE.COM GOOGLE.COM   google.com)


;; Query time: 4 msec

;; SERVER: 192.168.3.1 (局域网 局域网   )#53(192.168.3.1 (局域网 局域网   ))

;; WHEN: Thu Dec 14 22:58:35 CST 2017

;; MSG SIZE  rcvd: 184
