README : 

C'est ce que j'ai fait pour le graph et l'affichage de données sur QT en C++.
J'ai simplement importé le dossier projet de QT.

Les fichiers modifiés :

  - mainwindow.h :
      - Ajout de la class Vecteur,
      - Ajout de la class List.
  
  - mainwindow.cpp :
      - Ajout des méthodes de la class Vecteur,
      - Ajout des méthodes de la class List,
      - Test QPainter en commentaire.
      
  - main.cpp : (dans l'orde d'apparition) 
      - Ajout d'une fonction 'fonction' qui renvoie le class Vecteur v+1 en prenant en argument le class Vecteur v,
      - Création du class Vecteur v0,
      - Création de la class List liste,
      - Calcul des n vecteurs demandés et remplissage de class List liste, 
      - Création de la MainWindow et du QTableWidget (ce sont les deux fenêtres d'affichage),
      - Remplissage des lignes du tableau (v0 à vn & header x y),
      - Remplissage de la Serie de point pour le graphique et du tableau en parcourant la class List liste,
      - Changement graphique du graph,
      - Affichage de la MainWindow et du QTableWidget.
