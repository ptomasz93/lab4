/*
 * generator.cpp
 *
 *  Created on: 15-03-2014
 *      Author: root
 */
using namespace std;

#include "generator.hh"

/**
 * \brief generuje plik *.txt o zadanej ilosci danych i nazwie
 * \details W pliku umieszczane sa liczby naturalne od 1 wzwyrz
 * w pierwszym wierszu umieszczana jest liczba mowiaca o ilosci wierszy danych.
 * @param nazwa - utworzonego pliku
 * @param rozmiar - ilosc wierszy sanych
 */

void generuj(char* nazwa,int rozmiar)
{

	ofstream test;
	test.open(nazwa);
	test<<rozmiar<<"\n";
	for(int i=0; i<rozmiar; i++)
	{
		test<<(rand()%rozmiar+1)<<"\n";
	}
	test.close();
}


