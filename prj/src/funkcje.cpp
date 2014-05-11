/*
 * funkcje.cpp
 *
 *  Created on: 01-03-2014
 *      Author: Tomasz Piotroswki
 */

#include "funkcje.hh"

using namespace std;

/**
 *\brief otwiera plik o zadajnej nazwie
 * @param nazwa sciezka do pliku
 * @param plik uchwyt do pliku
 * @return
 */
bool otworz(char* nazwa,fstream &plik)
{
	plik.open(nazwa,ios::in);
	return plik.good();
}

/**
 * \brief kopiuje dane z pliku do wektora
 * \details Funkcja pobiera wiersz danych z strumienia wejsciwego i zapisuje go w postaci
 * zmiennej int do wektora
 * \param wejsciowe referencja wekstora przechowywujacego dane wejsciowe
 * \param plik strumien wejscia zachaczony na pliku z danymi wejsciowymi
 * \return zwraca rozmiar tablic
 */
int kopiuj(vector <int> &wejsciowe, fstream &plik)

{
int wiersz, rozmiar;
plik>>rozmiar;
for(int i=0;i<rozmiar;i++)
	{
	plik>>wiersz;
	wejsciowe.push_back(wiersz);
	}
return rozmiar;
}
/**
 *\brief implementacja pomiatu czasu oraz algorytmu mnozenia
 *\details w fuknkcji zostaje zmierzona ilość taktów procesora potrzebnych na wykonanie
 *\details zadanej ilości opercji mnożenia. Następnie ilość taktów zostaje podzielona przez
 *\details stała PER_TO_SEC
 * @param wejsciowe dane ktore przetworzy algorytm
 * @param wyjsciowe tablica wynikow mnozenia
 * @param powt liczba powtorzen algorytmu
 */

double obliczenia(const vector <int> &wejsciowe,int* wyjsciowe,int powt)
{

	double time;
	double czasy[3];
	clock_t start=0,stop=0;
	cout.setf(ios::fixed);
	cout.precision(5);
		for(int sr=0;sr<5;sr++)
		{
			start=clock();
				for(int i=0;i<powt;i++)
				{
					for(int b=0;b<(int)wejsciowe.size();b++)
					{
					wyjsciowe[b]=2*wejsciowe[b];
					}
				}
			stop=clock();
			time=(double)(stop-start)/(double)CLOCKS_PER_SEC;
			czasy[sr]=time;
		}
	time=(czasy[0]+czasy[1]+czasy[2]+czasy[3]+czasy[4])/5;
	return time;

}
/**
 * \brief funkcja kopiuje zawartosc tablicy wynikow do pliku
 * @param tablica
 * @param plik
 * @param rozmiar
 */

void zapisz(int* tablica, fstream &plik, int rozmiar)
{
	for(int i=0;i<rozmiar;i++)
	{
		plik<<tablica[i]<<"\n";;
	}
}
