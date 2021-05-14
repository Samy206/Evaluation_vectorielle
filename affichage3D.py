import sys
import matplotlib
matplotlib.use('Qt5Agg')
from matplotlib.figure import Figure
import matplotlib.pyplot as plt
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import * 
from PyQt5.QtGui import * 
from PyQt5.QtCore import * 

def Affichage3D_equations(self):
    # on crée un QListWidget et définissons sa géométrie
    list_widget = QListWidget(self)
    list_widget.setGeometry(230, 20,840, 60)
    
    # ouvrir et extraire les données 'Transfert_equations.txt'
    temp_filename = "Transfert_equations.txt"
    temp_name_file = open(temp_filename, 'r')
    liste_equations = temp_name_file.readlines()

    # boucle pour l'ajout des vecteurs dans la widget d'affichage
    for i in range(0, len(liste_equations)):
        # conversion de la valeur de la liste en item QListWidgetItem
        item_temp = QListWidgetItem(liste_equations[i].replace('\n',''))
        # ajout de l'item dans la liste
        list_widget.addItem(item_temp)

    
    # ajout d'une scroll bar et définition de son style
    scroll_bar = QScrollBar(self)
    scroll_bar.setStyleSheet("background : lightgreen;")

    # ajout d'une scroll bar verticale
    list_widget.setVerticalScrollBar(scroll_bar)

    # création d'un label et définission de sa géométrie
    label = QLabel("équations: ", self)
    label.setGeometry(230, 5, 150, 10)
 
def Affichage3D_donnees_statistiques(self):
    # on crée un QListWidget et définissons sa géométrie
    list_widget = QListWidget(self)
    list_widget.setGeometry(10, 350,200, 270)

    # ouvrir et extraire les valeurs de 'Transfert_donnees_statistiques_API.txt'
    temp_filename = "Transfert_donnees_statistiques_API.txt"
    temp_name_file = open(temp_filename, 'r')
    liste_donnees_statistiques = temp_name_file.readlines()

    # boucle pour l'ajout des statistiques dans la widget d'affichage
    for i in range(0, len(liste_donnees_statistiques)):
        # conversion de la valeur de la liste en item QListWidgetItem
        item_temp = QListWidgetItem(liste_donnees_statistiques[i].replace('\n',''))
        # ajout de l'item dans la liste
        list_widget.addItem(item_temp)

    # ajout d'une scroll bar et définition de son style
    scroll_bar = QScrollBar(self)
    scroll_bar.setStyleSheet("background : lightgreen;")

    # ajout d'une scroll bar verticale
    list_widget.setVerticalScrollBar(scroll_bar)

    # création d'un label et définission de sa géométrie
    label = QLabel("Données statistiques: ", self)
    label.setGeometry(10, 335, 150, 10)

class Affichage3D_fenetre(QMainWindow):
    def __init__(self, parent=None):
        # initialisation de la fenetre
        QMainWindow.__init__(self, parent)
        self.setWindowTitle('Affichage 3D')
        self.setGeometry(0,0,1280,720)

        # début main frame
        self.main_frame = QWidget()
         
        # creation de la figure et du canevas, et de ses dimensions
        self.dpi = 100
        self.fig = Figure((12.0, 12.0), dpi=self.dpi)
        self.canvas = FigureCanvas(self.fig)
        self.canvas.setParent(self.main_frame)
        
        # définition de la figure du plot, en version 3D
        self.axes = self.fig.add_subplot(111, projection = '3d')

        # contrôles de la barre en bas de l'écran
        # textbox pour choisir un vecteur en particulier
        self.textbox_select = QLineEdit()
        self.textbox_select.setMinimumWidth(200)
        self.textbox_select.editingFinished.connect(self.Affichage3D_vecteurs)
        
        # label d'info pour la textbox
        self.label_info_select = QtWidgets.QLabel()
        self.label_info_select.setText("enter index of a vector\nto know more info\nabout it:")

        # boutton d'actualisation / entrer le nouveau vecteur
        self.draw_button = QPushButton("&Apply changes")
        self.draw_button.clicked.connect(self.Affichage3D_vecteurs)
        
        # permet d'afficher ou enlever la grille
        self.grid_cb = QCheckBox("Show &Grid")
        self.grid_cb.setChecked(False)
        self.grid_cb.stateChanged.connect(self.Affichage3D_vecteurs)
        
        # label d'information pour afficher les info sur le vecteur selectionné
        self.label_vecteur = QtWidgets.QLabel()
        self.label_vecteur.setText("non updated")
        #
        # Layout with box sizers
        # 
        hbox = QHBoxLayout()
        
        # ajout des nouveaux controles
        for w in [  self.label_info_select, self.textbox_select, self.draw_button, self.grid_cb, self.label_vecteur]:
            hbox.addWidget(w)
            hbox.setAlignment(w, Qt.AlignVCenter)
        
        vbox = QVBoxLayout()
        vbox.addWidget(self.canvas)
        vbox.addLayout(hbox)
        
        self.main_frame.setLayout(vbox)
        self.setCentralWidget(self.main_frame)

        # fonctions d'affichage du module
        Affichage3D_donnees_statistiques(self)
        Affichage3D_equations(self)
        # end main frame

        self.textbox_select.setText('0')
        self.Affichage3D_vecteurs()
    
    def Affichage3D_vecteurs(self): # redéssine la figure / met a jour

        #lecture de la textbox et enregistrement des infos dans 'v_select'
        read_textbox = self.textbox_select.text().encode('utf-8')
        self.data = [int(s) for s in read_textbox.split()]
        v_select = self.data
        
        # nettoyage du plot 
        self.axes.clear()   
        # update de l'affichage ou non de la grille     
        self.axes.grid(self.grid_cb.isChecked())

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
        
        # boucle de remplissage des valeurs du plot
        for i in range (0,len(liste_vecteurs)):
            if i%3==0:
                array_x[int(i/3)] = float(liste_vecteurs[i]) - float(liste_vecteurs[0])
                array_y[int(i/3)] = float(liste_vecteurs[i+1]) - float(liste_vecteurs[1])
                array_z[int(i/3)] = float(liste_vecteurs[i+2]) - float(liste_vecteurs[2])
        
        self.axes.plot(array_x, array_y, array_z)

        # ajout des descriptions des axes
        self.axes.set_xlabel("x axis")
        self.axes.set_ylabel("y axis")
        self.axes.set_zlabel("z axis")

        # on surligne le vecteur selectioné
        if v_select[0] < int(len(liste_vecteurs)/3)-1 and v_select[0] >= 0: 
            # initialisation des array
            vecteur_select_x = [None]*2
            vecteur_select_y = [None]*2
            vecteur_select_z = [None]*2
            
            # passage des valeurs du vecteur selectionné depuis l'array principal
            vecteur_select_x[0] = array_x[int(v_select[0])]
            vecteur_select_y[0] = array_y[int(v_select[0])]
            vecteur_select_z[0] = array_z[int(v_select[0])] 
            vecteur_select_x[1] = array_x[int(v_select[0]+1)]
            vecteur_select_y[1] = array_y[int(v_select[0]+1)]
            vecteur_select_z[1] = array_z[int(v_select[0]+1)] 
            
            # enregistrement des nouveaux arrays dans le plot avec une nouvelle couleur (rouge)
            self.axes.plot(vecteur_select_x, vecteur_select_y, vecteur_select_z, color = 'r')
            
            # mise a jour du label avec les normes de vecteurs
            string_vecteur_label = "vecteur selectioné: "+str(v_select[0]) 
            string_vecteur_label +="\nnormes:"
            string_vecteur_label +="\nx: "+str(float((vecteur_select_x[1]) - vecteur_select_x[0]))  
            string_vecteur_label +="\ny: "+str(float((vecteur_select_y[1]) - vecteur_select_y[0]))  
            string_vecteur_label +="\nz: "+str(float((vecteur_select_z[1]) - vecteur_select_z[0]))  
            self.label_vecteur.setText(string_vecteur_label)
        
        else :
            # message d'erreur dans l'affichage 3D
            self.label_vecteur.setText("\n\nErreur: Le vecteur selectioné n'existe pas\n\n")
        
        # actualisaton du canevas
        self.canvas.draw()

        # liste vecteurs
        # creating a QListWidget
        list_widget = QListWidget(self)

        # setting geometry to it
        list_widget.setGeometry(10, 20,200, 270)

        # boucle pour l'ajout des vecteurs dans la liste d'affichage
        for i in range(0, len(liste_vecteurs)):
            #print(liste_vecteurs[i])
            if i%3==0:
                # conversion de la valeur de la liste en item QListWidgetItem
                item_temp = QListWidgetItem("X: "+liste_vecteurs[i].replace('\n','')+" Y: "+liste_vecteurs[i+1].replace('\n','')+" Z: "+liste_vecteurs[i+2].replace('\n',''))
                # ajout de l'item dans la liste
                list_widget.addItem(item_temp)

        # ajout d'une scroll bar et définition de sa géométrie
        scroll_bar = QScrollBar(self)
        scroll_bar.setStyleSheet("background : lightgreen;")

        # ajout d'une scroll bar verticale
        list_widget.setVerticalScrollBar(scroll_bar)

        # création d'un label et définition de sa géométrie
        label = QLabel("Liste des vecteurs: ", self)
        label.setGeometry(10, 5, 150, 10)

app = QApplication(sys.argv)
form = Affichage3D_fenetre()
form.show()
app.exec_()