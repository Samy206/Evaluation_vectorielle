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
Notre application fait appel à quatre librairies et commandes terminal tierces qu'il faut impérativement 
avoir :<br />
<b>Commande système gnuplot</b> : Utilisée afin de générer l'image du graphique. <br />
<b>Commande système ps2pdf</b> : Utilisée afin de générer un script qui sera converti par la suite en pdf
(qui vient avec Ghostscript sur windows et qui est installable via le terminale sur Linux et Mac). <br />
<b>Librairies Python</b> : Une API est utilisée dans notre programme.<br />
<b>Librairie Tinyexpr</b> : Évaluatueur de fonctions mathématiques.<br />


## Portabilité :
Ce point est directement relié au précédent dans la mesure où selon votre machine il faudra peut-être installer les
applications que nous avons cité.<br />
Pour <b>Linux</b> et <b>Mac</b> il faudra vérifier que les commandes `ps2pdf` et `gnuplot -c` sont bien reconnues par
votre terminal. Et pour <b>Windows</b> il faudra avoir les versions portables de Gnuplot et Ghostscript ( permet aussi
d'avoir la commande `ps2pdf`) , voici comment les obtenir soit via terminal soit via télécharement internet : <br />
<b>Librairies Python : </b>`python -m pip install -U pip`<br />
`python -m pip install -U matplotlib`<br />
`python pip install PyQt5`<br />
<b>ps2pdf : </b> `https://www.ghostscript.com/download/gsdnld.html` <br />
<b>Gnuplot : </b> `https://sourceforge.net/projects/gnuplot/files/gnuplot/5.4.1/gp541-win64-mingw.7z/download` <br />


## Lancement de l'application :
### Premier lancement :
Dans le cas d'un premier lancement de l'application effectuer les configurations suivantes :<br />
`./configure.sh` sous Linux. <br />
`./configure_mac.sh` sous Mac. <br />
Appuyer sur le script exécutable `WINDOWS_installer.bat` contenu dans le répertoire <b>WINDOWS</b> sous Windows.<br />
### Lancements suivants : 
Sous Mac et Linux il suffit d'appeler l'éxécutable <b>Gestion_evaluation_vectorielle</b>, et sous Windows il faut faire
de  même mais avec le script <b>Run.bat</b> ( toujours contenu dans le répertoire WINDOWS ).
## Language de la machine :
En dernier point il faut que dans l'environnement de la machine le language soit l'anglais car notre application effectue des conversions en double, l'écriture angloplohne des chiffres décimaux doit être choisie (exemple : 1.111 au lieu de 1,111).
    
