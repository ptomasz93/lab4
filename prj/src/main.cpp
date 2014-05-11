/*
 * main.c
 *
 *  Created on: 28-02-2014
 *      Author: root
 */

#define  SREDNIA_Z 5

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
dane wejsciowe;
fstream losowe, posortowane;
ofstream wynik;
czas stoper;
int il=0, sr;
double suma;

wynik.open("pos_los");
for(int b=0;b<15;b++)
	{
	il+=100000;
	generuj("losowe.txt",il);
	losowe.open("losowe.txt");
	losowe>>wejsciowe;
	losowe.close();
	quick(wejsciowe,0,il);
		for(sr=0;sr<SREDNIA_Z;sr++)
		{
			stoper.start();
			quick(wejsciowe,0,il);
			stoper.stop();
			suma+=stoper.wynik();
			wejsciowe.wejsciowe.clear();

		}

		cout<<"srednia dla: "<<wejsciowe.rozmiar<<"  "<<suma/sr<<"\n";
		wynik<<wejsciowe.rozmiar<<"  "<<suma/sr<<"\n";
		suma=0;
		wejsciowe.wejsciowe.clear();
	}

wynik.close();

 }


