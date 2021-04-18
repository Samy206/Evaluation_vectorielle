set xrange[-30:30]
set yrange[-30:30]
set zrange[-30:30]
splot "fic1_gnup.txt" using 1:2:3:(1):(1):(1) with lines