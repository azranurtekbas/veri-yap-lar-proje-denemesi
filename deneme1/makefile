

all:derle bagla calistir

derle:
	g++ -g -c -I "./include" -c ./src/main.cpp -o ./lib/main.o
	g++ -g -c -I "./include" -c ./src/SatirDugum.cpp -o ./lib/SatirDugum.o
	g++ -g -c -I "./include" -c ./src/SatirListe.cpp -o ./lib/SatirListe.o
	g++ -g -c -I "./include" -c ./src/YoneticiListe.cpp -o ./lib/YoneticiListe.o
	g++ -g -c -I "./include" -c ./src/YoneticiDugum.cpp -o ./lib/YoneticiDugum.o
bagla:
	g++ -g ./lib/SatirListe.o ./lib/SatirDugum.o ./lib/YoneticiDugum.o ./lib/YoneticiListe.o ./lib/main.o ./bin/program.o

calistir:
	./bin/program