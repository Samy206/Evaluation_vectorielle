set terminal png
set output "ressources/test.png"
Graph = "ressources/test.txt"
plot Graph using 1:2 with lines
