/*
 * merge.cpp
 *
 *  Created on: 21-03-2014
 *      Author: root
 */

#include "merge.hh"

/**
 *  \brief scala zbiory sortujac je
 * @param zbior dane wejsciowe
 * @param poczatek wskaznik na poczatek zbioru
 * @param srodek wskaznik na srodek zbioru
 * @param koniec wskaznik na koniec zbioru
 */
void merge(dane &zbior, int poczatek , int srodek, int koniec) {
	int *pomocnicza = new int[(koniec - poczatek)+1]; // utworzenie tablicy pomocniczej
	int i = poczatek, j = srodek + 1, k = 0; // zmienne pomocnicze

	while (i <= srodek && j <= koniec) {
		if (zbior.wejsciowe[j] < zbior.wejsciowe[i]) {
			pomocnicza [k] = zbior.wejsciowe[j];
			j++;
		} else {
			pomocnicza [k] = zbior.wejsciowe[i];
			i++;
		}
		k++;
	}

	if (i <= srodek) {
		while (i <= srodek) {
			pomocnicza [k] = zbior.wejsciowe[i];
			i++;
			k++;
		}
	} else {
		while (j <= koniec) {
			pomocnicza [k] = zbior.wejsciowe[j];
			j++;
			k++;
		}
	}

	for (i = 0; i <= koniec - poczatek; i++)
		zbior.wejsciowe[poczatek + i] = pomocnicza [i];

	delete[] pomocnicza;
}
/**
 * \brief dzieli wektor na mniejsze czesci
 * \details poprzez rekurencyjne wywolywanie funkcji 'dzieli' vector na jednoelementowe
 * czesci. Nastepnie poprzez wywyolanie funkcji merge() scala i sortuje je.
 * @param zbior
 * @param poczatek
 * @param koniec
 */
void merge_sort(dane& zbior, int poczatek, int koniec) {
	int srodek;

	if (poczatek != koniec) {
		srodek = (poczatek + koniec) / 2;
		merge_sort(zbior, poczatek, srodek);
		merge_sort(zbior, srodek + 1, koniec);
		merge(zbior, poczatek, srodek, koniec);
	}
}
