/*
 * clasa.cpp
 *
 *  Created on: 06-03-2014
 *      Author: root
 */
#include "clasa.hh"

/**
 * \brief funkcja zamienia elementy o podanym indexie
 * \details elementy indexowane sa od 0,
 * @param a element pierwszy
 * @param b element drugi
 * @return zwraca false jesli index jest zbyt duzy
 */
bool dane::Zamien_elementy(int a,int b)
{
	if(a==b)return true;
	if(a>rozmiar||b>rozmiar)return false;
	int zmienna_a, zmienna_b;
	zmienna_a=wejsciowe[a];
	zmienna_b=wejsciowe[b];
	wejsciowe[a]=zmienna_b;
	wejsciowe[b]=zmienna_a;
	return true;
}

/**
 *  \brief funkcja kolejnosc wystepowania elementow
 */
void dane::odwroc()
{

	for(int i=0;(i<rozmiar/2);i++)
		Zamien_elementy(i,(rozmiar-i-1));
}

/**
 * \brief funkcja dodaje element we wskazane miejsce
 * @param element ktory ma zostac wstawiony
 * @param miejsce w ktore ma zostac wstawiony element
 * @return zwraca false jesli index jest zbyt duzy
 */

bool dane::dodaj(int element, int miejsce)
{
	if(miejsce>rozmiar)return false;
	vector<int>::iterator it=wejsciowe.begin()+miejsce-1;
	wejsciowe.insert(it, element);
	rozmiar=wejsciowe.size();
	return true;
}

/**
 * \brief dodaje element na koniec wektora
 * @param element ktory ma zostac dodany
 */
void dane::dodaj_koniec(int element)
{
	wejsciowe.push_back(element);
	rozmiar=wejsciowe.size();
}
/**
 * \brief dodaje element na poczatek
 * @param element ktory ma zostac dodany
 */
void dane::dodaj_poczatek(int element)
{
	vector<int>::iterator it=wejsciowe.begin();
	wejsciowe.insert(it,element);
	rozmiar=wejsciowe.size();
}

/**
 * \brief dodaje tablice elementow
 * \details elementy sa dodawane we wskazane miejsce indeksujemy od 1
 * @param tab wskaznik na tablice elementow
 * @param ilosc elementow do dodania
 * @param miejsce index miejsca w ktore ma zostawc wstawiona tablica
 * @return
 */
bool dane::dodaj(int* tab, int ilosc, int miejsce)
{
	if(miejsce>rozmiar) return false;
	vector<int>::iterator it=wejsciowe.begin()+miejsce-1;
	for(int i=0;i<ilosc;i++)
	{
		wejsciowe.insert(it+i,*(tab+i));
	}
	rozmiar=wejsciowe.size();
	return true;
}

/**
 * \brief porownuje vektor zewnetrzny z wektorem klasy
 * @param wektor zewnetrzny
 * @return
 */
bool dane::operator ==(vector<int> wektor)
{
	if( wejsciowe.size() != wektor.size())return false;
	for(int i=0;i<wejsciowe.size();i++)
	{
		if(wejsciowe[i]!=wektor[i])return false;
	}
	return true;
}
/**
 *\brief dodaje vektor do vektora w klasie
 * @param element vektor ktory ma zostac dodany
 */
void dane::operator + (vector<int> element)
{
	vector<int>::iterator it_b, it_e;
	it_b=element.begin();
	it_e=element.end();
	for(;it_b<it_e;it_b++)
	{
		wejsciowe.push_back(*it_b);
	}
	rozmiar=wejsciowe.size();
}


/**
 *\brief porownuje dwie klasy dane
 * @param drugi
 * @return
 */
bool dane::operator ==(dane drugi)
{
	if(rozmiar==drugi.rozmiar&&wejsciowe==drugi.wejsciowe)return true;
	return false;
}










