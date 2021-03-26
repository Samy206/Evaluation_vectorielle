run : exe
	./exe

exe : target/gestion_fichier.o
	g++ -o exe  target/gestion_fichier.o  src/Main.cc

target/gestion_fichier.o : headers/gestion_fichier.h
	g++ src/gestion_fichier.cc -c

clean :
	rm target/*

