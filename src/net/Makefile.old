
CC = g++
CFLAGS = -g
CXXFLAGS = -g
INCLUDEDIR = include
LINK = -lboost_date_time -lboost_system -lboost_thread-mt -pthread

BIN_DIR = bin
SRC_DIR = src
OBJ_DIR = object

PROGS = ${BIN_DIR}/boost_asio_server.out  ${BIN_DIR}/main_epollserver.out  ${BIN_DIR}/main_epollclient.out
#PROGS = ${BIN_DIR}/boost_asio_server.out  ${BIN_DIR}/epool_server.out  ${BIN_DIR}/epool_client.out \
#		${BIN_DIR}/test_epool_server.out ${BIN_DIR}/main_epollserver.out ${BIN_DIR}/main_epollclient.out

OBJ = ${OBJ_DIR}/

all : ${PROGS}

${BIN_DIR}/boost_asio_server.out : ${SRC_DIR}/boost_asio_server.cpp
	${CC} ${CXXFLAGS} ${LINK} ${SRC_DIR}/boost_asio_server.cpp -o ${BIN_DIR}/boost_asio_server.out

${BIN_DIR}/epool_server.out : ${SRC_DIR}/epool_server.cpp ${INCLUDEDIR}/utils.h ${INCLUDEDIR}/local.h
	${CC} ${CXXFLAGS} -I${INCLUDEDIR} ${SRC_DIR}/epool_server.cpp -o ${BIN_DIR}/epool_server.out ${LINK}

${BIN_DIR}/epool_client.out : ${SRC_DIR}/epool_client.cpp ${INCLUDEDIR}/utils.h ${INCLUDEDIR}/local.h
	${CC} ${CXXFLAGS} -I${INCLUDEDIR} ${SRC_DIR}/epool_client.cpp -o ${BIN_DIR}/epool_client.out ${LINK}

${BIN_DIR}/test_epool_server.out : ${SRC_DIR}/test_epool_server.cpp ${INCLUDEDIR}/utils.h ${INCLUDEDIR}/local.h
	${CC} ${CXXFLAGS} -I${INCLUDEDIR} ${SRC_DIR}/test_epool_server.cpp -o ${BIN_DIR}/test_epool_server.out ${LINK}

${BIN_DIR}/main_epollserver.out : ${SRC_DIR}/main_epollserver.cpp ${SRC_DIR}/cepollserver.cpp ${INCLUDEDIR}/cepollserver.h
	${CC} ${CXXFLAGS} -I${INCLUDEDIR} ${SRC_DIR}/main_epollserver.cpp ${SRC_DIR}/cepollserver.cpp -o ${BIN_DIR}/main_epollserver.out ${LINK}
	
${BIN_DIR}/main_epollclient.out : ${SRC_DIR}/main_epollclient.cpp ${SRC_DIR}/cepollclient.cpp ${INCLUDEDIR}/cepollclient.h
	${CC} ${CXXFLAGS} -I${INCLUDEDIR} ${SRC_DIR}/main_epollclient.cpp ${SRC_DIR}/cepollclient.cpp -o ${BIN_DIR}/main_epollclient.out ${LINK}
		
.PHONY : all clean

clean:
	-rm -rf ${PROGS}
#	-rm -rf	${OBJ_DIR}/*  ${PROGS}

