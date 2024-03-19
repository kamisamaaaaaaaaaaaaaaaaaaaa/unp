include ../Make.defines

PROGS =	udpcli01 udpserv01 udpcli02_dgcliaddr udpcli03_dgcliinetaddr udpcli04_dgcliconnect \
		udpcli06_dgcliloop1 udpserv06_dgecholoop1 udpserv07_dgecholoop2 udpcli08_dgcliloop3 udpcli09 udpcli10_dgclibig \
		udpservselect01_sigchldwaitpid 

all:	${PROGS}

udpcli01:	udpcli01.o
		${CC} ${CFLAGS} -o $@ udpcli01.o ${LIBS}

udpserv01:	udpserv01.o
		${CC} ${CFLAGS} -o $@ udpserv01.o ${LIBS}

udpcli02_dgcliaddr:	udpcli02.o dgcliaddr.o
		${CC} ${CFLAGS} -o $@ udpcli02.o dgcliaddr.o ${LIBS}

udpcli03_dgcliinetaddr:	udpcli03.o dgcliinetaddr.o
		${CC} ${CFLAGS} -o $@ udpcli03.o dgcliinetaddr.o ${LIBS}

udpcli04_dgcliconnect:	udpcli04.o dgcliconnect.o
		${CC} ${CFLAGS} -o $@ udpcli04.o dgcliconnect.o ${LIBS}

udpcli06_dgcliloop1:	udpcli06.o dgcliloop1.o
		${CC} ${CFLAGS} -o $@ udpcli06.o dgcliloop1.o ${LIBS}

udpserv06_dgecholoop1:	udpserv06.o dgecholoop1.o
		${CC} ${CFLAGS} -o $@ udpserv06.o dgecholoop1.o ${LIBS}

# udpcli07_dgcliloop2:	udpcli07.o dgcliloop2.o
# 		${CC} ${CFLAGS} -o $@ udpcli07.o dgcliloop2.o ${LIBS}

udpserv07_dgecholoop2:	udpserv07.o dgecholoop2.o
		${CC} ${CFLAGS} -o $@ udpserv07.o dgecholoop2.o ${LIBS}

udpcli08_dgcliloop3:	udpcli08.o dgcliloop3.o
		${CC} ${CFLAGS} -o $@ udpcli08.o dgcliloop3.o ${LIBS}

udpcli09:	udpcli09.o
		${CC} ${CFLAGS} -o $@ udpcli09.o ${LIBS}

udpcli10_dgclibig:	udpcli10.o dgclibig.o
		${CC} ${CFLAGS} -o $@ udpcli10.o dgclibig.o ${LIBS}

udpservselect01_sigchldwaitpid:	udpservselect01.o sigchldwaitpid.o
		${CC} ${CFLAGS} -o $@ udpservselect01.o sigchldwaitpid.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
