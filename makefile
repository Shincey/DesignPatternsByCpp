
demo : main.o
	g++ -o demo main.o

main.o : main.cpp
	g++ -c main.cpp

clean :
	rm demo main.o
	