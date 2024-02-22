all: compile bind launch

compile:
	g++ -I "./include" -c ./src/linkedList.cpp -o ./lib/linkedList.o

	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o

bind:
	g++ ./lib/linkedList.o ./lib/main.o -o ./bin/program1

launch:
	./bin/program1.exe