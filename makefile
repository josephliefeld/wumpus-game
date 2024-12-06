CC = g++ -std=c++11 -g
exe = asm4

$(exe): main.o game.o event.o room.o gold.o stalactites.o bats.o wumpus.o
	$(CC) main.o game.o event.o room.o gold.o stalactites.o bats.o wumpus.o -o $(exe) 

main.o: main.cpp 
	$(CC) -c main.cpp 

game.o: game.cpp 
	$(CC) -c game.cpp

event.o: event.cpp 
	$(CC) -c event.cpp 
  
room.o: room.cpp 
	$(CC) -c room.cpp

gold.o: gold.cpp 
	$(CC) -c gold.cpp	

stalactites.o: stalactites.cpp 
	$(CC) -c stalactites.cpp

bats.o: bats.cpp 
	$(CC) -c bats.cpp	

wumpuss.o: wumpus.cpp 
	$(CC) -c wumpus.cpp	

clean:
	rm -f *.out *.o $(exe) 