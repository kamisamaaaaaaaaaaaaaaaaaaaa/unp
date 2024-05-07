include ../Make.defines

OBJS = main.o cleanup.o pcap.o udpcksum.o senddnsquery-raw.o udpread.o udpwrite.o
OBJSNET = main.o cleanup.o pcap.o udpcksum.o senddnsquery-libnet.o udpread.o
PROGS =	udpcksum udpcksum-libnet

all:	${PROGS}

udpcksum:	${OBJS}
		${CC} ${CFLAGS} -o $@ ${OBJS} -lpcap ${LIBS}

# Include special linking flags from libnet-config program
udpcksum-libnet:	${OBJSNET}
		${CC} ${CFLAGS} -o $@ ${OBJSNET} -lpcap -lnet ${LIBS}

# Include special compilation flags from libnet-config program
senddnsquery-libnet.o:	senddnsquery-libnet.c
		${CC} ${CFLAGS} -lnet -c -o $@ $<

clean:
		rm -f ${PROGS} ${CLEANFILES}
