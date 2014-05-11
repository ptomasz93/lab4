/*
 * clasa.hh
 *
 *  Created on: 10-03-2014
 *      Author: root
 */

#ifndef CLASA_HH_
#define CLASA_HH_
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
class dane
{
	public:
	vector <int> wejsciowe;//wektor danych wejsciowych
	int rozmiar;

	friend ostream& operator << (ostream &wyjscie, dane  &wej)
	{
	   wyjscie<<wej.wejsciowe.size()<<"\n";
	   for(int i=0;i<wej.wejsciowe.size();i++)
	   		{
	   			wyjscie<<wej.wejsciowe[i]<<"\n";
	   		}
	   	   return wyjscie;
	}

	friend fstream& operator >> (fstream & plik, dane &wej)
	{
			int liczba;
			plik>>wej.rozmiar;
			for(int i=0;i<wej.rozmiar;i++)
			{
				plik>>liczba;
				wej.wejsciowe.push_back(liczba);
			}
		return plik;
	}

	bool Zamien_elementy(int a,int b);

	void odwroc();

	bool dodaj(int element, int miejsce);

	void dodaj_koniec(int element);

	void dodaj_poczatek(int element);

	bool dodaj(int* tab, int ilosc, int miejsce);

	bool operator ==(vector<int> wektor);

	void operator + (vector<int> element);

	bool operator ==(dane drugi);


};




#endif /* CLASA_HH_ */
