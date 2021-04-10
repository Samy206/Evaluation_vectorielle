T := target/
S := src/
H := headers/

run : $(T)exe
	@./$(T)exe


$(T)exe : $(T)tinyexpr.o $(T)vecteurs.o $(T)liste_vecteurs.o $(T)statistiques.o $(T)gestion_fichier.o
	@gcc -Wall -o $(T)exe  $(T)tinyexpr.o $(T)vecteurs.o $(T)liste_vecteurs.o $(T)statistiques.o $(T)gestion_fichier.o $(S)Main.c


$(T)tinyexpr.o : $(H)tinyexpr.h
	@gcc -Wall -o $(T)tinyexpr.o $(S)tinyexpr.c -c

$(T)vecteurs.o : $(H)vecteurs.h
	@gcc -Wall -o $(T)vecteurs.o $(S)vecteurs.c -c

$(T)liste_vecteurs.o : $(H)liste_vecteurs.h
	@gcc -Wall -o $(T)liste_vecteurs.o $(S)liste_vecteurs.c -c

$(T)statistiques.o : $(H)statistiques.h
	@gcc -Wall -o $(T)statistiques.o  $(S)statistiques.c -c

$(T)gestion_fichier.o : $(H)gestion_fichier.h
	@gcc -Wall -o $(T)gestion_fichier.o $(S)gestion_fichier.c -c

clean :
	rm $(T)*.o
	rm $(T)exe