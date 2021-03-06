/*
 * main.c
 *
 *  Created on: 28-02-2014
 *      Author: root
 */

#define  SREDNIA_Z 3

#include <iostream>
#include "funkcje.hh"
#include "clasa.hh"
#include <fstream>
#include <vector>
#include "generator.hh"
#include "quick.hh"
#include "merge.hh"
#include "heap.hh"
#include "stoper.hh"

using namespace std;

fstream in;
fstream wynik;

int main()
{
srand( time( NULL ) );
dane wejsciowe;
fstream losowe, posortowane;
ofstream wynik;

czas stoper;
int il=100, sr;
double suma;

wynik.open("qucik_losowe_piwot_srodkowy.txt");
for(int b=0;b<6;b++)
	{
	il*=10;
	generuj("losowe.txt",il);
		for(sr=0;sr<SREDNIA_Z;sr++)
		{
			losowe.open("losowe.txt");
			losowe>>wejsciowe;
			losowe.close();
			stoper.start();
			quick(wejsciowe,0,il);
			stoper.stop();
//			cout<<wejsciowe;
			suma+=stoper.wynik();

			wejsciowe.wejsciowe.clear();
		}
		cout<<"srednia dla: "<<wejsciowe.rozmiar<<"  "<<suma/sr<<"\n";
		wynik<<wejsciowe.rozmiar<<"  "<<suma/sr<<"\n";
		suma=0;
	}
wynik.close();

il=100;

wynik.open("qucik_posortowane_piwot_srodkowy.txt");
for(int b=0;b<6;b++)
	{
	il*=10;
	generuj("losowe.txt",il);
	losowe.open("losowe.txt");
	losowe>>wejsciowe;

	losowe.close();
	quick(wejsciowe,0,il);
	//wejsciowe.odwroc();

	for(sr=0;sr<SREDNIA_Z;sr++)
		{
			stoper.start();
			quick(wejsciowe,0,il);
			stoper.stop();
			wejsciowe.odwroc();
			suma+=stoper.wynik();
		}

		cout<<"srednia dla: "<<wejsciowe.rozmiar<<"  "<<suma/sr<<"\n";
		wynik<<wejsciowe.rozmiar<<"  "<<suma/sr<<"\n";
		suma=0;
		wejsciowe.wejsciowe.clear();
	}

wynik.close();
 }


