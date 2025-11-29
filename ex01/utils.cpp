/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:37:59 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/29 10:32:12 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>
#include <iomanip>

void	start_ui(void)
{
	std::cout << "What sould we do ?" << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "| 1.ADD | 2.SEARCH | 3.EXIT |" << std::endl;
	std::cout << "=============================" << std::endl;
}

bool	check_lenght(std::string str, size_t max)
{
	if (str.length() > max)
		return (false);
	return (true);
}

void	display_ui(Phonebook book)
{
	int	count = book.get_count();

	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int num = 0 ; num != count ; num ++)
		display_contact(num, book);
	std::cout << "---------------------------------------------" << std::endl;
}

void	display_contact(int index, Phonebook book)
{
	std::string	str;
	
	Contact contact = book.getcontact(index);;
	std::cout << "|         " << index + 1 << "|";
	str = contact.get_first_name();
	display_field(str);
	str = contact.get_last_name();
	display_field(str);
	str = contact.get_nickname();
	display_field(str);	
	std::cout << std::endl;
}

void	display_field(std::string str)
{

	if (!check_lenght(str, 10))
	{
		str.resize(9);
		unsigned sz = str.size();
		str.resize(sz+1, '.');
		std::cout << str << "|";
	}
	else
		std::cout << std::setw(10) << str << "|";
}
