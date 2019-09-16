#include <cmath> 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>	
using namespace std;
#include "Astre.h"

astre::astre() 
{ 
	for (int i=0; i<3; i++) 
	{
		x[i]=0;
		v[i]=0;
		a[i]=0;
		
	
	}	
	m=0; G=6.67408*pow(10,-11);


}

void astre::accel(astre A)
{ 
	double r=0;
	for (int i=0; i<3;i++)
	{
		r=r+(x[i]-A.x[i])*(x[i]-A.x[i]);   // r carré en fait, r² = a²+b²
		
	}
	double f;
	f=G*m*A.m/(pow(r,1.5));

	for(int i=0; i<3; i++)
	{
		a[i]=a[i]+f*(A.x[i]-x[i])/m;        
	}   
}


void astre::reset_acc() { for(int i=0; i<3;i++) {a[i]=0;}}


void astre::coordcdm(double x0[3])
{
	for(int i=0; i<3;i++)
	{
		x[i]=x[i]-x0[i];
	}

}

void astre::vitesse(double h)
{
	for (int i=0; i<3;i++)
	{
		v[i]=v[i]+0.5*a[i]*h;
	}
}


void astre::pos(double h)
{
	for(int i=0;i<3;i++)
	{
		x[i]=x[i]+v[i]*h;
	}
}



void astre::vlov (astre A, double vl)  //méthode de la classe astre donc il faut passer le soleil en argument
{
	double r=0;
	
	for (int i=0;i<3;i++) {r=r+(x[i]-A.x[i])*(x[i]-A.x[i]);     //on calcule le rayon 
				A.x[i]=0;
				x[i]=0; A.v[i]=0; v[i]=0;}

	x[0]=sqrt(r);
	v[0]=vl;
}
























