#include "Que.h"

#include <iostream>
char userChoice;
char userInterface();

int main()
{
	Que<int, 5> intjono;
	bool isRunning = true;
	std::cout << "jono alustettu: 'Que<int, 5> intjono' " << std::endl;
	while (isRunning)
	{

		switch (userInterface())
		{
		case ('a'):
			int addNum;
			std::cout << "anna kokonaisluku " << std::endl;
			std::cin >> addNum;
			try
			{
				intjono.append(addNum);
			}
			catch (const std::runtime_error& e)
			{
				std::cout << e.what() << std::endl;
			}
			break;
		case ('b'):
			try
			{
				std::cout << "Luettu: " << intjono.readFirst() << std::endl;
			}
			catch (const std::runtime_error& e)
			{
				std::cout << e.what() << std::endl;
			}
			break;
		case ('c'):
			if (intjono.isEmpty())
			{
				std::cout << "Jono on tyhjä." << std::endl;
				std::cin;
			}
			else
			{
				std::cout << "jono ei ole tyhjä." << std::endl;
				std::cin;
			}
			break;
		case ('d'):
			if (intjono.isFull())
			{
				std::cout << "Jono on täynnä!" << std::endl;
			}
			else
			{
				std::cout << "jono ei ole täynnä." << std::endl;
			}
			break;
		case ('0'):
			isRunning = false;
			return 0;
			break;
		}
	}
}

char userInterface()
{
	std::cout << "a. kirjoita jonoon" << std::endl;
	std::cout << "b. lue jonosta" << std::endl;
	std::cout << "c. onko tyhjä?" << std::endl;
	std::cout << "d. onko täynnä?" << std::endl;
	std::cout << "0. lopeta" << std::endl;
	std::cin >> userChoice;
	return userChoice;
}