#include "Que.h"

#include <iostream>

int main()
{
	Que<int, 10> intjono;

	for (int i = 0; i < 10; i++)
	{
		intjono.append(i);
		std::cout << intjono.readFirst() << "\n" << i << std::endl;
	}
}


/*
Tee tietorakenteena jono siten, ett�:

jono kuvataan luokkana, jossa luokkamuuttujina ovat indeksit alku ja loppu
data toteutetaan jono-objektissa yksinkertaisena taulukkona, joka indeksien avulla muodostaa rengasrakenteen (esimerkiksi 3-paikkaisen jonon loppu-indeksi voi saada arvot 0->1->2->0->1...)
jonoon tallennettava tieto voi olla m��riteltyn� geneeriseksi (template) tai joksikin perustietotyypiksi
metodi kirjoita() kirjoittaa uuden tiedon jonon loppuun
metodi lue() lukee tiedon jonon alusta
kirjoitettaessa t�yteen jonoon tai luettaessa tyhj�st� jonosta tulostuu virheilmoitus [ja/tai generoituu poikkeus (exception)]
on mahdollisesti testimetodit onko_taynna() ja onko_tyhja()
Tee my�s p��ohjelma, jolla voit yksinkertaista jonoa testata.
*/