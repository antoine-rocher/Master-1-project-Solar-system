set title "Orbites du système solaire"

set key outside right


splot "Affichage.txt" u 1:2:3 pointsize 0.05 title "Soleil", "" u 4:5:6 pointsize 0.05 title "Mercure", "" u 7:8:9 pointsize 0.05 title "Vénus" , "" u 10:11:12 pointsize 0.05 title "Terre" , "" u  13:14:15 pointsize 0.05 title "Mars" , "" u  16:17:18 pointsize 0.05 title "Pluton" , "" u  19:20:21 pointsize 0.05 title "Jupiter" , "" u  22:23:24 pointsize 0.05 title "Saturne" , "" u  25:26:27 pointsize 0.05 title "Uranus", "" u  28:29:30 pointsize 0.05 title "Neptune"
