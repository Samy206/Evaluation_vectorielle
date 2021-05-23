mkdir ressources
cd Affichage3D
sudo apt-get install python3.8 -y 
sudo apt-get install python3.8-dev -y 
sudo apt install python3-pip -y 
pip install pyqt5 
pip install matplotlib 
cmake . 
make
cd ..
cmake .
make
./Gestion_evaluation_vectorielle