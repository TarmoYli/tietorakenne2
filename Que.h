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
			data[end % N] = item;			// modulot palauttaa aina kokonaislukuja, siksi käytetään niitä.
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
	}

	bool isFull()
	{
		return end - start >= N;			// päätetään että jos endin ja startin välinen erotus on suurempi tai yhtäsuuri kuin kuin N niin jono on täynnä.
	}										// vaikkakaan me ei tässä anneta mahdollisuutta ylikirjoittaa dataa. mutta JOS annettaisiin niin >= olisi tarpeen.

	bool isEmpty()
	{
		return end == start;
	}
};

#endif // !QUE