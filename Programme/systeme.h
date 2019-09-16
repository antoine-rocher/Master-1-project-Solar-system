#ifndef SYSTEME_H_INCLUDED
#define SYSTEME_H_INCLUDED
#include <iostream>

using namespace std;

class systeme
{
public:
  astre *syst;
  int N;
  double M; //masse totale dans le systeme

  systeme(int na); // constructeur
  void initialisation();   //lis un fichier et initialise les astres
  void cdm();  //dans le ref actuel, calcule le nouveau cdm, écris les coord des astres dans ce nouveau ref   ---- Comme pour la methode cdm de astre : Cette méthode n'est pas utilisé dans le programme, puisque les coordonnées récupérées pour initialiser sont déja dans le centre de masse
  void etat(); //pour récuperer l'etat du syst a un instant donné 
  void accelerations(); //Calcul des nouvelles acc dans le systeme

};




#endif // SYSTEME_H_INCLUDED
