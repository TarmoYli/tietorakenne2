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
			data[end % N] = item;			// modulot palauttaa aina kokonaislukuja, siksi k�ytet��n niit�.
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
	}

	bool isFull()
	{
		return end - start >= N;			// p��tet��n ett� jos endin ja startin v�linen erotus on suurempi tai yht�suuri kuin kuin N niin jono on t�ynn�.
	}										// vaikkakaan me ei t�ss� anneta mahdollisuutta ylikirjoittaa dataa. mutta JOS annettaisiin niin >= olisi tarpeen.

	bool isEmpty()
	{
		return end == start;
	}
};

#endif // !QUE