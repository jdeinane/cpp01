/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:03:35 by jubaldo           #+#    #+#             */
/*   Updated: 2024/12/12 14:48:34 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define  MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &other) : std::stack<T>(other) {}
	MutantStack &operator=(const MutantStack &other) {
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack() {}

	// types d'iterateurs basés sur le conteneur sous-jacent de std::stack
	// en utilisant container_type, on accede aux types d'itérateurs de ce conteneur
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() {
		return this->c.begin(); // 'c' est un membre protégé de std::stack, utilisé pour accéder au conteneur sous-jacent
	}
	iterator end() {
		return this->c.end();
	}
	const_iterator cbegin() const {
		return this ->c.begin();
	}
	const_iterator cend() const {
		return this->c.end();
	}
	reverse_iterator rbegin() {
		return this->c.rbegin();
	}
	reverse_iterator rend() {
		return this->c.rend();
	}
	const_reverse_iterator crbegin() const {
		return this->c.rbegin();
	}
	const_reverse_iterator crend() const {
		return this->c.rend();
	}
};

#endif