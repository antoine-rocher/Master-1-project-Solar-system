Bonjour !

Voici quelques conseils/détails pour faire fonctionner et utiliser notre programme : 

-Pour compiler, il suffit de lancer un terminal et d'utiliser /make
-Cela crée ainsi caturne.exe
-Qu'on lance en tapant ./caturne

-On se retrouve alors face à un menu, et on choisit quelle partie executer : tracer les orbites, vérifier une vitesse de libération, vérifier la loi des aires
-Il faut alors renseigner un temps total et un pas : un pas de 3600 (secondes) est raisonnable, même si on peut baisser à moins de 1, mais pour un résultat pas necessairement meilleur.
 Le temps total, pour le calcul des orbites par exemples, pourra etre de 250 ans, afin que toutes les planètes aient pu faire un tour complet
-Un graphique sera généré automatiquement à la fin du programme. Pour les tracés d'orbites, si on veut pouvoir "manipuler" et "bouger" les orbites (qui sont en 3 dimensions), on pourra lancer gnuplot et 
 y copier intégralement le contenu de "affichage.gp"

-Pour les vitesses de libération, on rapelle les vitesses théoriques des corps du systeme solaire (en m/s) : 

Mercure : 67700
Vénus : 49000
Terre : 42110
Mars : 34120
Jupiter : 18460
Saturne : 13600
Uranus : 9600
Neptune : 7600

-On peut même générer un .gif des orbites : il suffit d'enlever les " // " de la derniere ligne de L_UNIVERS_EST_GRAND.cpp (afin de faire en sorte que la ligne de code ne soit plus en commentaire
NOTES : -afin d'accelerer la production du gif et limiter son poids, on peut remplacer la ligne 118 de ce fichier par :    S=floor(31536000.0/(100*h));
	-Cette partie du code par défaut est "désactivée" car produire un gif est long et lourd pour l'ordinateur
	-Il est donc préférable de renseigner un temps cours (~5 ans max) et un pas pas trop bas (~3600)
	-Le gif correspond aux orbites de la Terre et de Mars, si on veut avoir un résultat il faut donc demander au programme de prendre au moins 5 astres en compte
