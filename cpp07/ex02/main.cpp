/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:04:18 by jubaldo           #+#    #+#             */
/*   Updated: 2024/10/09 17:12:59 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750

int main()
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	
	// SCOPE (verification de la copie)
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		tmp[0] = 999;
		if (numbers[0] == 999)
			std::cerr << "Error : Deep copy failed between `tmp` and `numbers`." << std::endl;
		else
			std::cout << "Deep copy success for `tmp`." << std::endl;

		test[0] = 555;
		if (numbers[0] == 555)
			std::cerr << "Error : Deep copy failed between `tmp` and `numbers`.." << std::endl;
		else
			std::cout << "Deep copy success for `test`." << std::endl;
	}

	// verification de l'egalite des tableaux
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			delete[] mirror;
			return 1;
		}
	}
	std::cout << "All values are correctly saved!" << std::endl;
	
	// test d'acces hors limites
	try {
		numbers[-2] = 0;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	delete[] mirror; //
	
	return 0;
}
