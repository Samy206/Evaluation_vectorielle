run: a.out affichage3D.py
	./a.out

a.out: main.c
	g++ main.c -I/usr/include/python3.8 -lpython3.8 -lcrypt -lpthread -ldl -lutil -lrt -lm 

clean: 
	rm -f a.out 
	rm -f affichage3D.pyc
	