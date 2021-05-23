# Gestion d'évaluation vectorielle

<h2>Groupe</h2>
Alexis Laplanche, Antoine Leuridan, Baptiste Devylder, Chloé Helain, Gwennael Cannenpasse, Nicolas Dias, 
Pierre-Louis Chardon, Samy Boumali

## Sommaire
### But du projet
### Éléments / applications nécessaires
### Portabilité
### Lancement de l'application
### Language de la machine

## But du projet :
Le projet qui a été réalisé est conforme à ce qui a été demandé dans le sujet, c'est-à-dire l'étude d'une fonction 
couplée à un vecteur initial de dimensions variables. Cette application peut-être utile dans de multiples domaines 
d'application, parmis eux on retrouve l'étude des temps de réactions en chimie et la ballistique.<br />
De plus notre application offre une interface ergonomique donnant accés à différents services tels que l'affichage 
graphique des données initiales quand les dimensions le permettent, une vaste étude statistique allant de la moyenne à
l'autocorrelation, ainsi que la possibilité de garder une trace de ce qui a été calculé via une image du graphe et
un fichier pdf contenant les statistiques évoquées précédemment. 

## Éléments / applications nécessaires :
Notre application fait appel à deux trois externes qu'il faut impérativement avoir :<br />
<b>Gnuplot</b> : Utilisée afin de générer l'image du graphique. <br />
<b>Postscript / ps2pdf</b> : Utilisée afin de générer un script qui sera converti par la suite avec la commande système 
correspondante à l'OS.<br />
<b>Librairies Pyhton</b> : Une API est utilisée dans notre programme.<br />


## Portabilité :
Ce point est directement relié au précédent dans la mesure où selon votre machine il faudra peut-être installer les
applications que nous avons cité.<br />
Pour <b>Linux</b> et <b>Mac</b> il faudra vérifier que les commandes `ps2pdf` et `gnuplot -c` sont bien reconnues par
votre terminal. Et pour <b>Windows</b> il faudra avoir les versions portables de Gnuplot et Ghostscript ( permet aussi
d'avoir la commande `ps2pdf`) , voici comment les obtenir soit via terminal soit via télécharement internet : <br />
`python -m pip install -U pip`<br />
`python -m pip install -U matplotlib`<br />
`python pip install PyQt5`<br />
<b>ps2pdf : </b> `https://www.ghostscript.com/download/gsdnld.html` <br />
<b>Gnuplot : </b> `https://sourceforge.net/projects/gnuplot/files/gnuplot/5.4.1/gp541-win64-mingw.7z/download` <br />


## Lancement de l'application :
L'application peut-être lancée de trois manières différentes :<br />
Dans tout les cas dans un premier temps utiliser la commande:
`./configure.sh`

### cmake :
Pour utiliser le cmake il vous faudra les chemins des libraires Qt, Pyhton et Pthread de disponibles. Si c'est le cas
il suffira d'entrer la commande `cmake CMakeLists.txt` qui générera un Makefile qu'il faudra logiquement lancer lui aussi
avec `make` afin de finalement obtenir un éxecutable qui se nommera <b>Evaluation_vectorielle</b>. <br />

### qmake :
Pour utiliser le qmake il suffira d'appeler la commande `qmake ; make` et suivant l'OS de votre machine l'éxecutable peut
se retrouver dans deux endroits différents : <br />
<b>Linux</b> : Sous cet OS il se trouvera sûrement dans votre dossier courant. <br />
<b>Mac</b> : L'éxecutable sera au chemin suivant `Gestion_Evaluation_Vectorielle.app/Contents/MacOS/Gestion_Evaluation_Vectorielle`.
<br />

### IDE QtCreator :
Encore plus simple, il vous suffira d'ouvrir le fichier `Gestion_Evaluation_Vectorielle.pro` avec QtCreator et de lancer
le programme depuis le bouton correspondant (flèche verte en bas à gauche de la fenêtre).<br />

## Language de la machine :
En dernier point il faut que dans l'environnement de la machine le language soit à l'anglais car notre application effectue des conversions en double, l'écriture angloplohne des chiffres décimaux doit être choisie (exemple : 1.111 au lieu de 1,111).
    
