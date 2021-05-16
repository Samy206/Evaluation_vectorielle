set terminal png
set output "ressources/test2.png"
Graph = "ressources/test2.txt"
plot Graph using 1:2 with lines
