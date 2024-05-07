#include "unp.h"
#include <pcap.h>

#include <netinet/in_systm.h> /* required for ip.h */
#include <netinet/in.h>
#include <netinet/ip.h>
// #include <netinet/ip_var.h>
#include <netinet/udp.h>
// #include <netinet/udp_var.h>
#include <net/if.h>
#include <netinet/if_ether.h>

#define TTL_OUT 64 /* outgoing TTL */

struct ipvolg
{
    u_char ih_x1[9];       // 9 bytes
    u_char ih_pr;          // 1 bytes
    u_short ih_len;        // 2 bytes
    struct in_addr ih_src; // 4 bytes;
    struct in_addr ih_dst; // 4 bytes;
};
struct udpiphdr
{
    struct ipvolg ui_i;
    struct udphdr ui_u;
};

#define ui_x1 ui_i.ih_x1
#define ui_pr ui_i.ih_pr
#define ui_len ui_i.ih_len
#define ui_src ui_i.ih_src
#define ui_dst ui_i.ih_dst
#define ui_sport ui_u.source
#define ui_dport ui_u.dest
#define ui_ulen ui_u.len
#define ui_sum ui_u.check

/* declare global variables */
extern struct sockaddr *dest,
    *local;
extern socklen_t destlen, locallen;
extern int datalink;
extern char *device;
extern pcap_t *pd;
extern int rawfd;
extern int snaplen;
extern int verbose;
extern int zerosum;

/* function prototypes */
void cleanup(int);
char *next_pcap(int *);
void open_output(void);
void open_pcap(void);
void send_dns_query(void);
void test_udp(void);
void udp_write(char *, int);
struct udpiphdr *udp_read(void);
