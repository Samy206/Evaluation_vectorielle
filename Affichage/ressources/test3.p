set terminal png
set output "ressources/test3.png"
Graph = "ressources/test3.txt"
plot Graph using 1:2 with lines
