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
			data[end % N] = item;			// modulot palauttaa aina kokonaislukuja, siksi me k�ytet��n niit� t�ss� paljon.
			++end;
		}
		else
		{
			throw std::runtime_error("Jono T�ynn�!");
		}
	}

	T readFirst()
	{
		if (!isEmpty())
		{
			++start;						// kasvatetaan arvoa
			return data[(start - 1) % N];	// mutta otetaan siit� yksi pois koska sit� ei olla viel� k�sitelty
		}
		else
		{
			throw std::runtime_error("Jono Tyhj�!");
		}
		return T();							// t�m� on t��ll� koska ilman sit� ei k��nny
	}

	bool isFull()
	{
		return end - start >= N;			// p��tet��n ett� jos endin ja startin v�linen erotus on suurempi kuin N niin jono on t�ynn�.
	}										// vaikka t�ss� versiossa jonoa ei voi koskaan throwin takia menn� ymp�ri.

	bool isEmpty()
	{
		return end == start;
	}
};

#endif // !QUE
/*
jono kuvataan luokkana, jossa luokkamuuttujina ovat indeksit alku ja loppu
data toteutetaan jono-objektissa yksinkertaisena taulukkona, joka indeksien avulla muodostaa rengasrakenteen (esimerkiksi 3-paikkaisen jonon loppu-indeksi voi saada arvot 0->1->2->0->1...)
jonoon tallennettava tieto voi olla m��riteltyn� geneeriseksi (template) tai joksikin perustietotyypiksi
metodi kirjoita() kirjoittaa uuden tiedon jonon loppuun
metodi lue() lukee tiedon jonon alusta
kirjoitettaessa t�yteen jonoon tai luettaessa tyhj�st� jonosta tulostuu virheilmoitus [ja/tai generoituu poikkeus (exception)]
on mahdollisesti testimetodit onko_taynna() ja onko_tyhja()
Tee my�s p��ohjelma, jolla voit yksinkertaista jonoa testata.
*/


