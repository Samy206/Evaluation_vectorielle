
import sys
import matplotlib
matplotlib.use('Qt5Agg')


from matplotlib.figure import Figure

from PyQt5.QtWidgets import * 
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtGui import * 
from PyQt5.QtCore import * 

from PyQt5 import QtCore, QtGui, QtWidgets
import matplotlib
import matplotlib.pyplot as plt
matplotlib.use('Qt5Agg')
from PyQt5 import QtCore, QtWidgets
from PyQt5.QtWidgets import QFileDialog
#import numpy as np
from matplotlib.figure import Figure

from matplotlib.widgets import TextBox


import sys, os, random
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *

import matplotlib
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt5agg import NavigationToolbar2QT as NavigationToolbar
from matplotlib.figure import Figure

def Affichage3D_equations(self):
    # creating a QListWidget
    list_widget = QListWidget(self)

    # setting geometry to it
    list_widget.setGeometry(150, 20,400, 40)
    
    # opening and extracting values from 'Transfert_equations.txt'
    temp_filename = "Transfert_equations.txt"
    temp_name_file = open(temp_filename, 'r')
    liste_equations = temp_name_file.readlines()

    # boucle pour l'ajout des vecteurs dans la liste d'affichage
    for i in range(0, len(liste_equations)):
        print(liste_equations[i])
        # conversion de la valeur de la liste en item QListWidgetItem
        item_temp = QListWidgetItem(liste_equations[i].replace('\n',''))
        # ajout de l'item dans la liste
        list_widget.addItem(item_temp)

    
    # ajout d'une scroll bar
    scroll_bar = QScrollBar(self)

    # setting style sheet to the scroll bar
    scroll_bar.setStyleSheet("background : lightgreen;")

    # setting vertical scroll bar to it
    list_widget.setVerticalScrollBar(scroll_bar)

    # creating a label
    label = QLabel("équations: ", self)

    # setting geometry to the label
    label.setGeometry(150, 5, 150, 10)

    # making label multi line
    label.setWordWrap(True)


def Affichage3D_vecteurs(self):
    # creating a QListWidget
    list_widget = QListWidget(self)

    # setting geometry to it
    list_widget.setGeometry(10, 20,150, 170)
    
    # opening and extracting values from 'Transfert_liste_vecteurs.txt'
    temp_filename = "Transfert_liste_vecteurs.txt"
    temp_name_file = open(temp_filename, 'r')
    liste_vecteurs = temp_name_file.readlines()
    for i in range(0,len(liste_vecteurs)):
        liste_vecteurs[i] = liste_vecteurs[i].replace('\n','')
    #print (liste_vecteurs)

    # boucle pour l'ajout des vecteurs dans la liste d'affichage
    for i in range(0, len(liste_vecteurs)):
        print(liste_vecteurs[i])
        if i%3==0:
            # conversion de la valeur de la liste en item QListWidgetItem
            item_temp = QListWidgetItem("X: "+liste_vecteurs[i].replace('\n','')+" Y: "+liste_vecteurs[i+1].replace('\n','')+" Z: "+liste_vecteurs[i+2].replace('\n',''))
            # ajout de l'item dans la liste
            list_widget.addItem(item_temp)

    
    # ajout d'une scroll bar
    scroll_bar = QScrollBar(self)

    # setting style sheet to the scroll bar
    scroll_bar.setStyleSheet("background : lightgreen;")

    # setting vertical scroll bar to it
    list_widget.setVerticalScrollBar(scroll_bar)

    # creating a label
    label = QLabel("Liste des vecteurs: ", self)

    # setting geometry to the label
    label.setGeometry(10, 5, 150, 10)

    # making label multi line
    label.setWordWrap(True)
      
def Affichage3D_donnees_statistiques(self):
    # creating a QListWidget
    list_widget = QListWidget(self)

    # setting geometry to it
    list_widget.setGeometry(10, 210,150, 150)

    # opening and extracting values from 'Transfert_donnees_statistiques_API.txt'
    temp_filename = "Transfert_donnees_statistiques_API.txt"
    temp_name_file = open(temp_filename, 'r')
    liste_donnees_statistiques = temp_name_file.readlines()
    #print (liste_donnees_statistiques)

    # boucle pour l'ajout des vecteurs dans la liste d'affichage
    for i in range(0, len(liste_donnees_statistiques)):
        print(liste_donnees_statistiques[i])
        # conversion de la valeur de la liste en item QListWidgetItem
        item_temp = QListWidgetItem(liste_donnees_statistiques[i].replace('\n',''))
        # ajout de l'item dans la liste
        list_widget.addItem(item_temp)

    # scroll bar
    scroll_bar = QScrollBar(self)

    # setting style sheet to the scroll bar
    scroll_bar.setStyleSheet("background : lightgreen;")

    # setting vertical scroll bar to it
    list_widget.setVerticalScrollBar(scroll_bar)

    # creating a label
    label = QLabel("Données statistiques: ", self)

    # setting geometry to the label
    label.setGeometry(10, 195, 150, 10)

    # making label multi line
    label.setWordWrap(True)

class AppForm(QMainWindow):
    def __init__(self, parent=None):
        QMainWindow.__init__(self, parent)
        self.setWindowTitle('Affichage 3D')

        self.create_main_frame()

        self.textbox.setText('-1')
        self.on_draw()
    
    def on_draw(self):
        """ Redraws the figure
        """
        read_textbox = self.textbox.text().encode('utf-8')
        self.data = [int(s) for s in read_textbox.split()]
        
        x = self.data
        
        # clear the axes and redraw the plot anew
        #
        self.axes.clear()        
        self.axes.grid(self.grid_cb.isChecked())

        # opening and extracting values from 'Transfert_liste_vecteurs.txt'
        temp_filename = "Transfert_liste_vecteurs.txt"
        temp_name_file = open(temp_filename, 'r')
        liste_vecteurs = temp_name_file.readlines()
        for i in range(0,len(liste_vecteurs)):
            liste_vecteurs[i] = liste_vecteurs[i].replace('\n','')
        #print (liste_vecteurs)
        temp_name_file.close()

        #initialisation des valeurs du plot
        array_x = [None]*int(len(liste_vecteurs)/3)
        array_y = [None]*int(len(liste_vecteurs)/3)
        array_z = [None]*int(len(liste_vecteurs)/3)
        
       
        
        for i in range (0,len(liste_vecteurs)):
            if i%3==0:
                array_x[int(i/3)] = float(liste_vecteurs[i])
                array_y[int(i/3)] = float(liste_vecteurs[i+1])
                array_z[int(i/3)] = float(liste_vecteurs[i+2])
        
        self.axes.plot(array_x, array_y, array_z)
        
        self.label_1 = QtWidgets.QLabel()
        self.label_1.move(300, 300)


        # on surligne le vecteur selectioné
        if x[0] < int(len(liste_vecteurs)/3)-1 and x[0] >= 0 : 
            # initialisation des array
            vecteur_select_x = [None]*2
            vecteur_select_y = [None]*2
            vecteur_select_z = [None]*2
            
            # passage des valeurs du vecteur selectionné depuis l'array principal
            vecteur_select_x[0] = array_x[int(x[0])]
            vecteur_select_y[0] = array_y[int(x[0])]
            vecteur_select_z[0] = array_z[int(x[0])] 
            vecteur_select_x[1] = array_x[int(x[0]+1)]
            vecteur_select_y[1] = array_y[int(x[0]+1)]
            vecteur_select_z[1] = array_z[int(x[0]+1)] 
            
            # enregistrement des nouveaux arrays dans le plot avec une nouvelle couleur (rouge)
            self.axes.plot(vecteur_select_x, vecteur_select_y, vecteur_select_z, color = 'r')
            
            # mise a jour du label avec les normes de vecteurs
            string_vecteur_label = "vecteur selectioné: "+str(x[0]) 
            string_vecteur_label +="\nnormes:"
            string_vecteur_label +="\nx: "+str(float((vecteur_select_x[1]) - vecteur_select_x[0]))  
            string_vecteur_label +="\ny: "+str(float((vecteur_select_y[1]) - vecteur_select_y[0]))  
            string_vecteur_label +="\nz: "+str(float((vecteur_select_z[1]) - vecteur_select_z[0]))  
            
            self.label_vecteur.setText(string_vecteur_label)
        
        else :

            self.label_vecteur.setText("Le vecteur selectioné n'existe pas")
            #print("Le vecteur selectioné n'existe pas")
        
        self.canvas.draw()


    
    def create_main_frame(self):
        self.main_frame = QWidget()
        
        # Create the mpl Figure and FigCanvas objects. 
        # 5x4 inches, 100 dots-per-inch
        #
        self.dpi = 100
        self.fig = Figure((5.0, 4.0), dpi=self.dpi)
        self.canvas = FigureCanvas(self.fig)
        self.canvas.setParent(self.main_frame)
        
        # Since we have only one plot, we can use add_axes 
        # instead of add_subplot, but then the subplot
        # configuration tool in the navigation toolbar wouldn't
        # work.
        #
        self.axes = self.fig.add_subplot(111, projection = '3d')

        # Other GUI controls
        # 
        self.textbox = QLineEdit()
        self.textbox.setMinimumWidth(200)
        self.textbox.editingFinished.connect(self.on_draw)
        
        self.draw_button = QPushButton("&Draw")
        self.draw_button.clicked.connect(self.on_draw)
        
        self.grid_cb = QCheckBox("Show &Grid")
        self.grid_cb.setChecked(False)
        self.grid_cb.stateChanged.connect(self.on_draw)
        
        self.label_vecteur = QtWidgets.QLabel()
        self.label_vecteur.setText("non updated")
        #
        # Layout with box sizers
        # 
        hbox = QHBoxLayout()
        
        for w in [  self.textbox, self.draw_button, self.grid_cb, self.label_vecteur]:
            hbox.addWidget(w)
            hbox.setAlignment(w, Qt.AlignVCenter)
        
        vbox = QVBoxLayout()
        vbox.addWidget(self.canvas)
        vbox.addLayout(hbox)
        
        self.main_frame.setLayout(vbox)
        self.setCentralWidget(self.main_frame)

        # fonctions d'affichage du module
        Affichage3D_donnees_statistiques(self)
        Affichage3D_vecteurs(self)
        Affichage3D_equations(self)

def main():
    app = QApplication(sys.argv)
    form = AppForm()
    form.show()
    app.exec_()

main()