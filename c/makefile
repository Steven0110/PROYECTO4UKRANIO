NumArchivos: NumArchivos.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ NumArchivos.cpp -o NumArchivos
status: status.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ status.cpp -o status
principal: principal.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ principal.cpp -o principal
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
