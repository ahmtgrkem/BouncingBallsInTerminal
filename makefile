all: compile run

compile:
	g++ -c ./src/Main.cpp -o ./lib/Main.o
	g++ ./lib/Main.o -o ./bin/program
run:
	./bin/program