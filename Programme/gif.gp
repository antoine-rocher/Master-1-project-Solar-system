
set xrange [-4e+11:4e+11]
set yrange [-4e+11:4e+11]
set zrange [-0.8e+10:0.8e+10]


stats 'Affichage.txt' using 1 nooutput; n = STATS_records
set key off


set term gif animate
set output 'output.gif'


do for [j=1:n] {

 splot "Affichage.txt"  u 10:11:12 every ::1::j w l lw 2, "" u 13:14:15 every ::1::j w l lw 2,  \
       "Affichage.txt"  u 10:11:12 every ::j::j w p pt 7 ps 2,"" u 13:14:15 every ::j::j w p pt 7 ps 2
}




