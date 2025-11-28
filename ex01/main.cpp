/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:13:53 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/28 11:06:02 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"
#include "contact.class.hpp"
#include "utils.hpp"
#include <iostream>


int	main(void)
{
	std::string	str = "";
	bool		first = true;
	Phonebook	Phonebook;

	while (!std::cin.eof() )
	{
		if (first)
			start_ui();
		std::cin >> str;
		if (str == "ADD" || str == "1")
		{
			Phonebook.add();
			first = true;
		}
		else if (str == "SEARCH" || str == "2")
		{
			Phonebook.search();
			first = true;
		}
		else if (str == "EXIT" || str == "3")
			break;
		else
			first = false;
	}
	std::cout << "See you !" << std::endl;
	return 0;
}
