/*
 * funkcje.h
 *
 *  Created on: 01-03-2014
 *      Author: root
 */

#ifndef FUNKCJE_H_
#define FUNKCJE_H_
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#define CLOCKS_PER_SEC 1000000
using namespace std;

void zapisz(int* tablica,fstream &plik, int rozmiar);
double obliczenia(const vector <int> &wejsciowe,int* wyjsciowe,int powt);
bool otworz(char* nazwa,fstream &plik);
int kopiuj(vector <int> &wejsciowe, fstream &plik);

#endif /* FUNKCJE_H_ */
