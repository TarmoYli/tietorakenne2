#pragma once
#ifndef QUE
#define QUE
#include <array>
#include <iostream>

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
			data[end % N] = item;			// modulot palauttaa aina kokonaislukuja, siksi me käytetään niitä tässä paljon.
			++end;
		}
		else
		{
			throw std::runtime_error("Jono Täynnä!");
		}
	}

	T readFirst()
	{
		if (!isEmpty())
		{
			++start;						// kasvatetaan arvoa
			return data[(start - 1) % N];	// mutta otetaan siitä yksi pois koska sitä ei olla vielä käsitelty
		}
		else
		{
			throw std::runtime_error("Jono Tyhjä!");
		}
		return T();							// tämä on täällä koska ilman sitä ei käänny
	}

	bool isFull()
	{
		return end - start >= N;			// päätetään että jos endin ja startin välinen erotus on suurempi kuin N niin jono on täynnä.
	}										// vaikka tässä versiossa jonoa ei voi koskaan throwin takia mennä ympäri.

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


