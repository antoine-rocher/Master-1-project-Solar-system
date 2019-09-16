#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
#include "Astre.h"
#include "systeme.h"


int main()
{
	int M;
	cout<<"Choisir un programme à effectuer : "<<endl<<"1 : Faire tourner et afficher les orbites des planètes"<<endl<<"2 : Vérifier la 2e loi de Kepler "<<endl<<"3 : Calcul de vitesse de libération"<<endl<<"4 : Affichage des orbites vues depuis un corps spécifique"<<endl; cin>>M;

	if ((M!=1)&&(M!=2)&&(M!=3)&&(M!=4)) {cout<<endl<<"1, 2, 3 ou 4 ! Quel programme effectuer ?"<<endl;  cin>>M;}

	int N; //nombre d'astres
	double T; //temps total pendant lequel on veut faire tourner le systeme
	double h; //pas
	int S;	  //On s'en sert pour ne garder qu'un point sur mille quand on trace les orbites
	int planete;  //Pour les parties où on demande une planete avec la quelle travailler
	long ta;  //temps pendant le quel on veut calculer l'aire parcourue
	double surface=0;  //pour calculer la surface parcourue
	double dr[3]; double r[3]; //Pour calculer les aires on va calculer r vectoriel dr   
	double vlov;  //Quand on s'interesse aux vitesses de libération

//-------------------------------

	if(M==1)  //Initialisation de qq données pour faire tourner
	{	
		cout<<"Nb d'astres ? (Max 10, soleil inclus) "<<endl;
		cin>>N;
		while((N>10)||(N<2))
		{
			cout<<endl<<"Le nombre d'astre doit etre compris entre 2 et 10 ! Nb d'astres ? "<<endl; cin>>N;
		}
		cout<<endl<<"Temps total, en année ? ";cin>>T;
		T=31536000*T;  //Conversion en secondes
		cout<<endl<<"Pas, en secondes = ";
		cin>>h;
		T=T/h;   //correspond au nombre total d'iteration qu'on va faire, pour que nb d'iteration*pas = T le temps T renseigné, et le pas h, dépendent de la partie du programme qu'on effectue
		
	}

//--------------- Orbites vues par une planète
	if (M==4)
	{
		cout<<endl<<"Sur quel astre se place t-on ?"<<endl<<"0 : Soleil "<<endl<<"1 : Mercure"<<endl<<"2 : Venus"<<endl<<"3 : Terre"<<endl<<"4 : Mars"<<endl<< "5 : Pluton"<<endl<<"6 : Jupiter"<<endl<<"7 : Saturne"<<endl<<"8 : Uranus"<<endl<<"9 : Neptune"<<endl;	
		cin>>planete;

		while((planete>9)||(planete<0))
		{
			cout<<endl<<"Le numéro doit etre compris entre 0 et 9 ! Quelle astre choisir ? "<<endl; cin>>planete;
		}
		cout<<endl<<"Temps total, en année ? ";cin>>T;
		T=31536000*T;  //Conversion en secondes
		cout<<endl<<"Pas, en secondes = ";
		cin>>h;
		T=T/h;   
		N=10;  //on va considérer tout les astres, une fois le programme fini et gnuplot lancé on décide de quelles orbites tracer
		
	}
		



//-----------------------------------


	if(M==2)
	{
		cout<<endl<<"Pour quelle planète ?"<<endl<<"1 : Mercure"<<endl<<"2 : Venus"<<endl<<"3 : Terre"<<endl<<"4 : Mars"<<endl<< "5 : Pluton"<<endl<<"6 : Jupiter"<<endl<<"7 : Saturne"<<endl<<"8 : Uranus"<<endl<<"9 : Neptune"<<endl;
		
		cin>>planete;        //Pour que le programme sache avec quelle planete on va travailler

		while((planete>9)||(planete<1))
		{
			cout<<endl<<"Le numéro doit etre compris entre 1 et 9 ! Quelle planète choisir ? "<<endl; cin>>planete;
		}

		cout<<endl<<"Sur quelle période veut on regarder l'aire ? Renseigner un temps (en mois, entier) : ";
		cin>>ta;
		ta=ta*30*24*3600;//on approxime a 30 jours par mois, ce qui compte c'est qu'on calcule la surface parcourue pendant des temps egaux, pas qu'on mesure la surface parcourue pendant x mois avec 1 mois précisément egal a 365.25/12 (ca evite des problemes de calculs) , puis conversion en secondes
		

		cout<<"Pas (en secondes)? "<<endl;	
		cin>>h;
		T=100*ta;  //On va calculer 100 fois (aribtraire) l'aire parcourue pendant ta 		
		T=T/h;
		S=1; //on le pose différent de 1 car non utilisé si m=2 mais il y a quand même un if qui teste une divison par S
	}


//-----------------Vitesse lib


	if(M==3)
	{
		cout<<endl<<"Pour quelle planète ?"<<endl<<"1 : Mercure"<<endl<<"2 : Venus"<<endl<<"3 : Terre"<<endl<<"4 : Mars"<<endl<< "5 : Pluton"<<endl<<"6 : Jupiter"<<endl<<"7 : Saturne"<<endl<<"8 : Uranus"<<endl<<"9 : Neptune"<<endl;	
		cin>>planete;
		while((planete>9)||(planete<1))
		{
			cout<<endl<<"Le numéro doit etre compris entre 1 et 9 ! Quelle planète choisir ? "<<endl; cin>>planete;
		}
		cout<<endl<<"Vitesse de libération a tester (en m/s) : ";   
		cin>>vlov;
		cout<<endl<<"Nombre d'années ?"<<endl;
		cin>>T;
		cout<<endl<<"Pas (en secondes): ";
		cin>>h;
		T=T*31536000.0/h; // T en seconde par unité de h 
		
	}
	if (M==1 || M==3 || M==4)
	{
		S=floor(31536000.0/(4000*h)); // on écrit dans le fichier 4000 points pour 1 année (calculé pour avoir environ 1000 point/an sur l'orbite de mercure)
		if (S==0)
		{
			S=50; //A partir d'un certain pas, S vaut 0 : alors le pas est tel qu'on aurait moins de 4000 points-iterations par an, donc on décide de fixer S=50 cad on ne garde qu'un point sur 50  (il vaut mieux garder peu de points, tout en essayant d'en garder suffisament pour avoir une "continuité" surtout pour les planetes a plus faible periode de revolution

		}   
	}

//--------------- Vitesse lib et loi des aires
	if (M==2||M==3) {N=planete+1;}     //on crée le fichier en allant chercher jusqu'a la planete qui nous interesse 




//Initialisation du systeme, calcul des accelerations correspondant aux conditions initiales

	systeme Zeus(N);      
	Zeus.initialisation();
	Zeus.accelerations();    
	
	
	
//--------------- Vitesse lib et loi des aires, partie qui necessite que le systeme ait été initialisé
	if (M==2||M==3)      //si on veut verifier la loi des aires ou a la vitesse de libération, on met la planete a laquelle on s'interesse dans la 2e case du tableau de la classe qui gere le systeme, et on met N a 2 cad on ne va travailler qu'avec le soleil et la planete en question
	{
		for (int i=0;i<3;i++)
		{
			Zeus.syst[1].x[i]=Zeus.syst[planete].x[i];
			Zeus.syst[1].v[i]=Zeus.syst[planete].v[i];
		}
		Zeus.syst[1].m=Zeus.syst[planete].m;	
		Zeus.N=2;  		
	}
	if (M==3)  //on peut mettre ce if avant le if précedent, remplacer dans ce if le 1 par "planete" mais c'est strictement équivalent
	{
			Zeus.syst[1].vlov(Zeus.syst[0],vlov); 
	}
	
	cout<<endl<<endl<<"Et ainsi apparurent le soleil et "<<Zeus.N-1<<" astres en orbite."<<endl<<"Cependant la lumière de ce système doit parcourir l'espace pour nous parvenir... Attendons !"<<endl; //La ligne de code la plus importante de tout le programme et sans laquelle rien ne fonctionnerait (veuillez donc ne pas l'enlever svp)

	ofstream f; 
	f.open("Affichage.txt");   //Le fichier dans lequel on va écrire 
	int C=T/10; int p=0;         //Pour avoir un pourcentage qui permet d'afficher l'évolution du programme (il est parfois long, ca permet de controler ou on en est)

//Tout est pret pour qu'on commence à faire tourner le systeme !	

//---------------------------------------------------------------------------------------
	for(int t=0; t<T+1; t++)
	{
		if(M==2) 
		{ 	
			// dans r vectoriel dr, on utilise le r avant déplacement 
			for (int i=0; i<3;i++) 
			{r[i]=Zeus.syst[1].x[i];} 
		}

//-------------------"Timer"   
		if(t%C==0) {cout<<p<<"%"<<endl; p=p+10;}     
		
//------------Les 2 boucles suivantes sont communes qqsoit ce qu'on veut, puisque elles calculent le mouvement
		
		for(int j=0;j<N;j++)  //verlet fait calculer v(t+h/2), puis x(t+h), donc on le fait pour chaque astre
		{
			Zeus.syst[j].vitesse(h);
			Zeus.syst[j].pos(h);
		}

		Zeus.accelerations(); //les nouvelles accelerations

		for(int j=0;j<N;j++)  //verlet fait calculer v(t+h)
		{
			Zeus.syst[j].vitesse(h);
		}
				
//----------M=1 cad partie affichage orbites
		if (((t%S==0) || (t==0)) && (M==1))    //a la premiere iteration, puis quand t est un multiple de S, on garde les coord pour l'aff  ET qu'on est dans la partie M=1 du menu cad qu'on veut afficher les orbites des planetes
		{		
			for (int i=0; i<N;i++)
			{
				for (int j=0; j<3; j++)
				{
					f<<Zeus.syst[i].x[j]<<" ";
				}
			}
			f<<endl;
	
		}

//---------M=4 affichage orbites vues par une planete précise

		if (((t%S==0) || (t==0)) && (M==4))    //exactement comme pour M=1 
		{		
			for (int i=0; i<N;i++)
			{
				for (int j=0; j<3; j++)
				{
					f<<Zeus.syst[i].x[j]-Zeus.syst[planete].x[j]<<" ";
				}
			}
			f<<endl;
	
		}


//---------M=2 cad loi des aires
		if(M==2)
		{
			for (int i=0; i<3;i++) {dr[i]=Zeus.syst[1].x[i]-r[i];} //On ecrit dr=r'-r. Avec r' nouvelle position calculée

			double ds=0.5*sqrt( (r[1]*dr[2]-r[2]*dr[1])*(r[1]*dr[2]-r[2]*dr[1])+(r[2]*dr[0]-r[0]*dr[2])*(r[2]*dr[0]-r[0]*dr[2])+(r[0]*dr[1]-r[1]*dr[0])*(r[0]*dr[1]-r[1]*dr[0]));   //produit vect    1/2 *norme du produit vectoriel = surface triangle
			
			surface=surface+ds; //Calcul de l'aire parcourue

			int tprime=ta/h; // pour l'operation suivante il faut 2 entiers  h est def comme un double donc le produit est considéré comme un double (si "t*h" apparait dans un calcul il est considéré comme un double, mais on peut quand meme def un entier a partir de t*h)

//On prend ta/h car t va de 0 a T, T etant le temps total en secondes par unité de pas

			if(t%(tprime)==0 && t!=0)   //quand on est pas a un temps multiple de ta, et en 0 (car 0 modulo x = 0 donc il faut 							    l'exclure)) on augmente S=surface totale parcourue  et qu'on est pas a la 1ere iteration 
			{	   
				f<<t*h/ta<<" "<<surface<<endl;  
				surface=0;
			}
		}
	

		if( (M==3) && (t%S==0))  //pareil que pour M=1
		{
	
			f<<t*h<<"   "<<Zeus.syst[1].x[0]<<"   "<<Zeus.syst[1].v[0]<<"   "<<Zeus.syst[1].a[0]<<endl; 
		}
	}
	f.close();
	

	if (M==1 || M==4) {system("gnuplot -p   affichage.gp");} //Pour tracer les orbites
	if (M==2||M==3) {system("gnuplot -p   aires.gp");} //Pour les aires ou la vitesse de lib
//	system("gnuplot -p   gif.gp");   //Commande pour produire un gif    
return 0;

}






