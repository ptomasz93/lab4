/*
 * heap.cpp
 *
 *  Created on: 23-03-2014
 *      Author: root
 */
#include "heap.hh"

using namespace std;

/**
 * \brief funkcja oblicza indeksy galezi wezla.
 * \details wezly sa indeksowane od 1 wiec w oniesieniu do wektora trzeba odjac 1.
 * @param pozycja bierzacy wezele
 * @param wyzej wezel mlodszy
 * @param lewy wezel starszy
 * @param prawy wezel starszy
 */
void sasiedzi(int pozycja, int* wyzej, int* lewy , int* prawy)
{
	*wyzej=pozycja/2;
	*lewy=pozycja*2;
	*prawy=pozycja*2+1;
}
/**
 * \brief porzadkuje kopiec
 * \details funkcja przeglada kopiec od dolnego rzedu wezlow w gore.
 * Po przez operacje porownania wypycha wieksze elemnty w gore kopca.
 * @param zbior zbior elementow do posortowania
 * @param rozmiar rozmiar problemu
 */
void heap(dane& zbior, int rozmiar)
{
	int wyzej, lewy , prawy ;
	int bierzacy=rozmiar/2; ///przegladamy wezly a nie liscie
	while(bierzacy)
	{
		sasiedzi(bierzacy,&wyzej,&lewy,&prawy);
		if(lewy<=rozmiar&& zbior.wejsciowe[lewy-1]>zbior.wejsciowe[bierzacy-1])/// wezly sa indekowane od 1
			zbior.Zamien_elementy(lewy-1,bierzacy-1);
		if(prawy<=rozmiar&& zbior.wejsciowe[prawy-1]>zbior.wejsciowe[bierzacy-1])
			zbior.Zamien_elementy(prawy-1,bierzacy-1);
		bierzacy-=1;
	}
}

/**
 * \brief przeklada najstarszy wezel (najwieksza wartosc) na koniec wektora
 * @param zbior dane do upozadkowania
 * @param rozmiar problemu
 */
void wez(dane &zbior ,int &rozmiar)
{
	zbior.Zamien_elementy(0,rozmiar-1);/// znowu te indeksy
	rozmiar-=1;
}

/**
 * \brief wywoluje w petli funkcje budujaca kopiec oraz sciagajaca najwieksza wartosc
 * @param zbior
 */
void heap_sort(dane& zbior)
{
	int rozmiar=zbior.rozmiar;
	while(rozmiar-1)
	{
		heap(zbior, rozmiar);
		wez(zbior, rozmiar);
	}

}
