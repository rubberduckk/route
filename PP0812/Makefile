CFLAGS = -W -Wall
OBJECTS = main.o Packet.o PacketParser.o

all : packet
packet : $(OBJECTS)
	g++ $(CFLAGS) -o packet $(OBJECTS) -lpcap

main.o : PacketParser.h Packet.h

Packet.o : Packet.h

PacketParser.o : PacketParser.h

clean :
	rm packet $(OBJECTS)
