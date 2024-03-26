#pragma once
#ifndef QUE
#define QUE
#include <array>

template<typename T, std::size_t N>
class Que
{
public:
	Que():data(),start(0),end(0){}
	std::array<T,N> data;
	int start;
	int end;
	void append(T item)
	{
		if (!isFull())
		{
			data[end % N] = item;
			++end;
		}
	}

	T readFirst()
	{
		if (!isEmpty())
		{
			++start;
			return data[(start - 1) % N];
		}
		return T();
	}

	bool isFull()
	{
		return end - start == N;
	}

	bool isEmpty()
	{
		return end == start;
	}
};

#endif // !QUE
/*
jono kuvataan luokkana, jossa luokkamuuttujina ovat indeksit alku ja loppu
data toteutetaan jono-objektissa yksinkertaisena taulukkona, joka indeksien avulla muodostaa rengasrakenteen (esimerkiksi 3-paikkaisen jonon loppu-indeksi voi saada arvot 0->1->2->0->1...)
jonoon tallennettava tieto voi olla määriteltynä geneeriseksi (template) tai joksikin perustietotyypiksi
metodi kirjoita() kirjoittaa uuden tiedon jonon loppuun
metodi lue() lukee tiedon jonon alusta
kirjoitettaessa täyteen jonoon tai luettaessa tyhjästä jonosta tulostuu virheilmoitus [ja/tai generoituu poikkeus (exception)]
on mahdollisesti testimetodit onko_taynna() ja onko_tyhja()
Tee myös pääohjelma, jolla voit yksinkertaista jonoa testata.
*/


