#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Astre.h"
#include "systeme.h"
#include <fstream>
using namespace std;

systeme::systeme(int na) //constructeur    
{
	N=na;  //nb d'astres dans le systeme
	syst= new astre [N];   //tableau d'astre 
	M=0;
}
void systeme::initialisation ()  //on renseigne les valeurs des attributs de chaque objet astre qui se trouvent dans un fichier txt
{
    ifstream f;
    f.open("dieu.txt");  //qqsoit le nom du fichier txt qui contient les info
    for(int i=0;i<N;i++)
    {
	
	f >> syst[i].m;
	f >> syst[i].x[0];  //xyz
	f >> syst[i].x[1]; 
	f >> syst[i].x[2];
	f >> syst[i].v[0]; //vx vy vz
	f >> syst[i].v[1];
	f >> syst[i].v[2];
	M=M+syst[i].m;
	
    }
	f.close();
}

void systeme::cdm() 
{
	double cdm[3];
	for(int i=0; i<3;i++)	{cdm[i]=0;} 
	for(int n=0; n<N;n++)  //somme sur tout les astres---cette boucle calcule les coord du cdm dans la base actuelle 
	{
 		for(int j=0; j<3;j++)			//j = x,y,z  n= numéro de l'astre
		{
			cdm[j]=cdm[j]+(syst[n].m*syst[n].x[j]/M);   //cord cdm = (somme sur les astres (pos*masse))/(somme des masses)
		}
	}
	for(int n=0; n<N; n++)
	{ syst[n].coordcdm(cdm);}  //dans cette méthode de syst on apelle directement la methode coordcdm de astre qui réécrit les coords de l'astre dans la nouvelle base donnée en argument
}



		
void systeme::accelerations()
{
	for(int j=0; j<N;j++)
	{
		syst[j].reset_acc(); // On remet les acc a 0 a cause de la forme du calcul des nouvelles acc
	}
	for(int i=0; i<N; i++)  //La méthode de Astre calcule son accel par rapport a un autre astre
	{
 		for (int k=0; k<N; k++)
		{
			if(i!=k) { syst[i].accel(syst[k]); } //pour l'astre i, calcul son accel due a l'astre k
		}
	}
}










