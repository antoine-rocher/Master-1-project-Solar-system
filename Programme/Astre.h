#ifndef ASTRE_H
#define ASTRE_H

#include <iostream>
using namespace std;


class astre {
	public:
	double x[3]; double v[3]; double a[3]; double m; double G;   // double x,y,z,vx,vy,vz,ax,ay,az; //0=x, 1=y, 2=z
	
	
	astre(); //Constructeur

	double distance( astre A); // renvoie la distance à un astre donné  INUTILE POUR L'INSTANT

	void accel(astre A); //Pour ajouter l'acceleration due à un astre donné -> à chaque itération on va sommer sur tout les autres astres pour 					ajouter leur contribution a l'accel totale de l'astre donné      On ajoute aussi a accel de astre A l'acceleration 					due  a l'astre sur lequel on est; dans systeme, on iterera donc pas sur tout les astres

	void reset_acc(); //Remettre l'acceleration a 0 au début de chaque iteration 
	void pos(double h); // position pour l'algo verlet
	void coordcdm(double x0[3]); //change les coord de l'astre dans une nouvelle base, le tableau x0 donne les coord du centre de la nouvelle base exprimée dans l'ancienne base (cad dit comment transformer les coord de l'astre)  --on garde un RON, simplement centré ailleurs ---- Cette méthode n'est pas utilisé dans le programme, puisque les coordonnées récupérées pour initialiser sont déja dans le centre de masse
	void vitesse(double h); //calcule les vitesses pour Verlet, avec le pas en argument
	void vlov (astre A, double vl);


};	
#endif
