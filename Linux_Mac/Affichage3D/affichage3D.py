import PyQt5
import sys
import matplotlib
matplotlib.use('Qt5Agg')
from matplotlib.figure import Figure
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import * 
from PyQt5.QtGui import * 
from PyQt5.QtCore import * 
import math

def Affichage3D_equations(self):
    # on crée un QListWidget et définissons sa géométrie
    liste_widget = QListWidget(self)
    liste_widget.setGeometry(230, 20,840, 20)
    
    # ouvrir et extraire les données 'Transfert_equations.txt'
    temp_filename = "Transfert_equations.txt"
    temp_name_file = open(temp_filename, 'r')
    liste_equations = temp_name_file.readlines()

    # boucle pour l'ajout des vecteurs dans la widget d'affichage
    for i in range(0, len(liste_equations)):
        # conversion de la valeur de la liste en item QListWidgetItem
        item_temp = QListWidgetItem(liste_equations[i].replace('\n',''))
        # ajout de l'item dans la liste
        liste_widget.addItem(item_temp)

    
    # ajout d'une scroll bar et définition de son style
    scroller_bar = QScrollBar(self)
    scroller_bar.setStyleSheet("background : lightgreen;")

    # ajout d'une scroll bar verticale
    liste_widget.setVerticalScrollBar(scroller_bar)

    # création d'un label et définission de sa géométrie
    label = QLabel("Equation: ", self)
    label.setGeometry(230, 5, 150, 10)

 
def Affichage3D_donnees_statistiques(self):
    # on crée un QListWidget et définissons sa géométrie
    liste_widget = QListWidget(self)
    liste_widget.setGeometry(10, 350,200, 270)

    # ouvrir et extraire les valeurs de 'Transfert_donnees_statistiques_API.txt'
    temp_filename = "Transfert_donnees_statistiques_API.txt"
    temp_name_file = open(temp_filename, 'r')
    liste_donnees_statistiques = temp_name_file.readlines()

    # boucle pour l'ajout des statistiques dans la widget d'affichage
    for i in range(0, len(liste_donnees_statistiques)):
        # conversion de la valeur de la liste en item QListWidgetItem
        item_temp = QListWidgetItem(liste_donnees_statistiques[i].replace('\n',''))
        # ajout de l'item dans la liste
        liste_widget.addItem(item_temp)

    # ajout d'une scroll bar et définition de son style
    scroller_bar = QScrollBar(self)
    scroller_bar.setStyleSheet("background : lightgreen;")

    # ajout d'une scroll bar verticale
    liste_widget.setVerticalScrollBar(scroller_bar)

    # création d'un label et définission de sa géométrie
    label = QLabel("Statistic data: ", self)
    label.setGeometry(10, 335, 150, 10)

class Affichage3D_fenetre(QMainWindow):
    def __init__(self, parent=None):
        # initialisation de la fenetre
        QMainWindow.__init__(self, parent)
        self.setWindowTitle('Display Window 3D')
        dim_fenetre_A_x = 0
        dim_fenetre_A_y = 0
        dim_fenetre_B_x = 1280
        dim_fenetre_B_y = 720
        self.setGeometry(dim_fenetre_A_x,dim_fenetre_A_y,dim_fenetre_B_x,dim_fenetre_B_y)

        # début fenetre
        self.fenetre = QWidget()
         
        # creation de la figure et du canevas, et de ses dimensions
        self.dpi = 100
        self.fig = Figure((12.0, 12.0), dpi=self.dpi)
        self.canvas = FigureCanvas(self.fig)
        self.canvas.setParent(self.fenetre)
        
        # définition de la figure du plot, en version 3D
        self.courbe_a_afficher = self.fig.add_subplot(111, projection = '3d')

        # contrôles de la barre en bas de l'écran
        # textbox pour choisir un vecteur en particulier
        self.entree_numerique = QLineEdit()
        self.entree_numerique.setMinimumWidth(200)
        self.entree_numerique.editingFinished.connect(self.Affichage3D_vecteurs)
        
        # label d'info pour la textbox
        self.label_info_select = QtWidgets.QLabel()
        self.label_info_select.setText("enter index of a vector\nto know more info\nabout it:")

		# boutton d'actualisation / entrer le nouveau vecteur
        self.bouton_entrer = QPushButton("&Apply changes")
        self.bouton_entrer.clicked.connect(self.Affichage3D_vecteurs)
        # pour incrementer/décrementer
        self.bouton_moins = QPushButton("-")
        self.bouton_moins.clicked.connect(self.clicked_moins)
        self.bouton_plus = QPushButton("+")
        self.bouton_plus.clicked.connect(self.clicked_plus)
        # permet d'afficher ou enlever la grille
        self.grid_cb = QCheckBox("Show &Grid")
        self.grid_cb.setChecked(False)
        self.grid_cb.stateChanged.connect(self.Affichage3D_vecteurs)
        
        # label d'information pour afficher les info sur le vecteur selectionné
        self.msg_coord_vect_choisi = QtWidgets.QLabel()
        self.msg_coord_vect_choisi.setText("non updated")
        #
        # Layout with box sizers
        # 
        hbox = QHBoxLayout()
        
        # ajout des nouveaux controles
        for w in [  self.label_info_select, self.bouton_moins, self.entree_numerique, self.bouton_plus, self.bouton_entrer, self.grid_cb, self.msg_coord_vect_choisi]:
            hbox.addWidget(w)
            hbox.setAlignment(w, Qt.AlignVCenter)
        
        vbox = QVBoxLayout()
        vbox.addWidget(self.canvas)
        vbox.addLayout(hbox)
        
        self.fenetre.setLayout(vbox)
        self.setCentralWidget(self.fenetre)

        # fonctions d'affichage du module
        Affichage3D_donnees_statistiques(self)
        Affichage3D_equations(self)

        # textbox de selection de vecteur assignée a 0
        self.entree_numerique.setText('0')
        self.Affichage3D_vecteurs()
    
    def Affichage3D_vecteurs(self): # redéssine la figure / met a jour

        #lecture de la textbox et enregistrement des infos dans 'num_vect_choisi'
        read_textbox = self.entree_numerique.text().encode('utf-8')
        
        # test d'erreur pour voir si l'entrée est un int
        try: 
            self.data = [int(s) for s in read_textbox.split()]
            num_vect_choisi = self.data
        except ValueError:
            num_vect_choisi = [-1]*1 # va display une erreur
     
        # nettoyage du plot 
        self.courbe_a_afficher.clear()   
        # update de l'affichage ou non de la grille     
        self.courbe_a_afficher.grid(self.grid_cb.isChecked())

        # ouverir et extraire les valeurs de 'Transfert_liste_vecteurs.txt'
        temp_filename = "Transfert_liste_vecteurs.txt"
        temp_name_file = open(temp_filename, 'r')
        liste_vecteurs = temp_name_file.readlines()
        for i in range(0,len(liste_vecteurs)):
            liste_vecteurs[i] = liste_vecteurs[i].replace('\n','')
        temp_name_file.close()

        # initialisation des valeurs du plot
        array_x = [None]*int(len(liste_vecteurs)/3)
        array_y = [None]*int(len(liste_vecteurs)/3)
        array_z = [None]*int(len(liste_vecteurs)/3)
        
        #somme des vecteurs pour l'affichage
        array_x[0] = somme_vect_x = float(liste_vecteurs[0])
        array_y[0] = somme_vect_y = float(liste_vecteurs[1])
        array_z[0] = somme_vect_z = float(liste_vecteurs[2])

        # boucle de remplissage des valeurs du plot
        for i in range (3,len(liste_vecteurs)):
            if i%3==0:
                array_x[int(i/3)] = float(liste_vecteurs[i]) + somme_vect_x 
                array_y[int(i/3)] = float(liste_vecteurs[i+1]) + somme_vect_y
                array_z[int(i/3)] = float(liste_vecteurs[i+2]) + somme_vect_z

                somme_vect_x += float(liste_vecteurs[i])
                somme_vect_y += float(liste_vecteurs[i+1])
                somme_vect_z += float(liste_vecteurs[i+2])

        self.courbe_a_afficher.plot(array_x, array_y, array_z)

        # ajout des descriptions des axes
        self.courbe_a_afficher.set_xlabel("x axis")
        self.courbe_a_afficher.set_ylabel("y axis")
        self.courbe_a_afficher.set_zlabel("z axis")

        # on surligne le vecteur selectioné
        if num_vect_choisi[0] < int(len(liste_vecteurs)/3)-1 and num_vect_choisi[0] >= 0: 
            # initialisation des array
            vecteur_select_x = [None]*2
            vecteur_select_y = [None]*2
            vecteur_select_z = [None]*2
            
            # passage des valeurs du vecteur selectionné depuis l'array principal
            vecteur_select_x[0] = array_x[int(num_vect_choisi[0])]
            vecteur_select_y[0] = array_y[int(num_vect_choisi[0])]
            vecteur_select_z[0] = array_z[int(num_vect_choisi[0])] 
            vecteur_select_x[1] = array_x[int(num_vect_choisi[0]+1)]
            vecteur_select_y[1] = array_y[int(num_vect_choisi[0]+1)]
            vecteur_select_z[1] = array_z[int(num_vect_choisi[0]+1)] 
            
            # enregistrement des nouveaux arrays dans le plot avec une nouvelle couleur (rouge)
            self.courbe_a_afficher.plot(vecteur_select_x, vecteur_select_y, vecteur_select_z, color = 'r')
            
            # mise a jour du label avec les normes et coordonnées de vecteurs
            string_vecteur_label = "Selected vector: v"+str(num_vect_choisi[0]) 
            norm = pow(float(liste_vecteurs[num_vect_choisi[0]*3+3]),2) 
            norm += pow(float(liste_vecteurs[num_vect_choisi[0]*3+4]),2)
            norm += pow(float(liste_vecteurs[num_vect_choisi[0]*3+5]),2)
            norm = math.sqrt(norm)
            string_vecteur_label +="\nnorm: " +str(norm)
            string_vecteur_label +="\ncoordinates x: ("+str(float(vecteur_select_x[0])) +", "+ str(float(vecteur_select_x[1]))+")" 
            string_vecteur_label +="\ncoordinates y: ("+str(float(vecteur_select_y[0])) +", "+ str(float(vecteur_select_y[1]))+")"  
            string_vecteur_label +="\ncoordinates z: ("+str(float(vecteur_select_z[0])) +", "+ str(float(vecteur_select_z[1]))+")"  
            self.msg_coord_vect_choisi.setText(string_vecteur_label)
        
        else :
            # message d'erreur dans l'affichage 3D
            self.msg_coord_vect_choisi.setText("\n\nError: The selected vector doesn't exist!\n\n")
        
        # actualisaton du canevas
        self.canvas.draw()

        # liste vecteurs
        # creating a QListWidget
        liste_widget = QListWidget(self)

        # setting geometry to it
        liste_widget.setGeometry(10, 20,200, 270)

        # boucle pour l'ajout des vecteurs dans la liste d'affichage
        for i in range(3, len(liste_vecteurs)):
            if i%3==0:
                # conversion de la valeur de la liste en item QListWidgetItem
                item_temp = QListWidgetItem("v"+str(int(i/3)-1)+": X: "+liste_vecteurs[i].replace('\n','')+" Y: "+liste_vecteurs[i+1].replace('\n','')+" Z: "+liste_vecteurs[i+2].replace('\n',''))
                # ajout de l'item dans la liste
                liste_widget.addItem(item_temp)

        # ajout d'une scroll bar et définition de sa géométrie
        scroller_bar = QScrollBar(self)
        scroller_bar.setStyleSheet("background : lightgreen;")

        # ajout d'une scroll bar verticale
        liste_widget.setVerticalScrollBar(scroller_bar)

        # création d'un label et définition de sa géométrie
        label = QLabel("List of vectors: ", self)
        label.setGeometry(10, 5, 150, 10)

    def clicked_plus(self):
    	#lecture de la textbox et enregistrement des infos dans 'num_vect_choisi'
    	read_textbox = self.entree_numerique.text().encode('utf-8')
    	# test d'erreur pour voir si l'entrée est un int
    	try: 
        	self.data = [int(s) for s in read_textbox.split()]
        	self.entree_numerique.setText(str((self.data[0])+1))
    	except ValueError:
    		pass
        
 
    def clicked_moins(self):
    	#lecture de la textbox et enregistrement des infos dans 'num_vect_choisi'
    	read_textbox = self.entree_numerique.text().encode('utf-8')
    	# test d'erreur pour voir si l'entrée est un int
    	try: 
        	self.data = [int(s) for s in read_textbox.split()]
        	self.entree_numerique.setText(str((self.data[0])-1))
    	except ValueError:
        	pass


application = QApplication(sys.argv)
form = Affichage3D_fenetre()
form.show()
application.exec_()