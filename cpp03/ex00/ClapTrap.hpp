/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:48:30 by jubaldo           #+#    #+#             */
/*   Updated: 2024/06/26 14:43:24 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);

	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif

// L'heritage en C++ OOP permet a une classe de deriver des proprietes (attributs et methodes) 
// d'une autre classe.