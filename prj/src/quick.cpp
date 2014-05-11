/*
 * quick.cpp
 *
 *  Created on: 20-03-2014
 *      Author: root
 */


#include "quick.hh"


using namespace std;


/**
 * \brief implementacja algorytmu quicksort
 * \details	mozna wybrac sposob obliczenie piwotu
 * @param plik dane do posortowania
 * @param lewy poczatek ciagu
 * @param prawy koniec ciagu
 */

void quick(dane &plik ,int lewy, int prawy)
{
  int i,j,srodek;
  srand( time( NULL ) );
  i=(rand()%(prawy-lewy+1)+lewy);
  //i = (lewy + prawy) / 2;
  srodek = plik.wejsciowe[i];
  plik.Zamien_elementy(prawy, i);
  for(j = i = lewy; i < prawy; i++)
  {
	  if(plik.wejsciowe[i] < srodek)
	  {
		plik.Zamien_elementy(i,j);
		j++;
	  }
  }
  plik.Zamien_elementy(j,prawy);
   if(lewy < j - 1)  quick(plik ,lewy, j-1 );
  if(j + 1 < prawy) quick(plik, j + 1, prawy);
}




