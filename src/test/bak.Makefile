
CC = g++
CFLAGS = -g
CXXFLAGS = -g

BIN_DIR = bin
SRC_DIR = src
OBJS_DIR = objects

PROGS = ${BIN_DIR}/hello.out  ${BIN_DIR}/pageget.out ${BIN_DIR}/localip.out ${BIN_DIR}/sizeof.out
#OBJS = ${OBJS_DIR}/

all : ${PROGS}

${BIN_DIR}/hello.out : ${SRC_DIR}/hello.cpp
	${CC} ${CXXFLAGS} ${SRC_DIR}/hello.cpp -o ${BIN_DIR}/hello.out

#${BIN_DIR}/pageget.out : ${SRC_DIR}/pageget.cpp
#	${CC} ${CXXFLAGS} ${SRC_DIR}/pageget.cpp -o ${BIN_DIR}/pageget.out

${BIN_DIR}/localip.out : ${SRC_DIR}/localip.cpp
	${CC} ${CXXFLAGS} ${SRC_DIR}/localip.cpp -o ${BIN_DIR}/localip.out

${BIN_DIR}/sizeof.out : ${SRC_DIR}/sizeof.cpp
	${CC} ${CXXFLAGS} ${SRC_DIR}/sizeof.cpp -o ${BIN_DIR}/sizeof.out

.PHONY : all clean

clean:
	-rm -rf ${PROGS}
#	-rm -rf	${OBJS_DIR}/*  ${PROGS}

