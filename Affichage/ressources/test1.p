set terminal png
set output "ressources/test1.png"
Graph = "ressources/test1.txt"
plot Graph using 1:2 with lines
