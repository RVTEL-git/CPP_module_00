/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:59:38 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/28 11:24:59 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"
#include "contact.class.hpp"
#include "utils.hpp"
#include <iostream>
#include <sstream>

Phonebook::Phonebook(void)
{
	std::cout << "Wecolme in your wonderful Phonebook" << std::endl;
	this->_index = 0;
	this->_count = 0;
	return ;
}

Phonebook::~Phonebook(void)
{
}

bool	Phonebook::_overwrite(std::string str)
{
	static bool	overwriting;
	
	if (this->_index > 7 || overwriting)
	{
		overwriting = true;
		std::cout << "Warning: about to overwrite " << this->_contact[this->_index % 8].get_first_name() << std::endl;
		std::cout << "Yes/no" << std::endl;
		while (!std::cin.eof() && str.length() == 0)
		{
			std::getline(std::cin, str);
			if (str == "yes")
			{
				this->_count = 7;
				if (this->_index > 7)
					this->_index = 0;
				return (true);
			}
			else if (str == "no")
				return (false);
			else if (str.length() != 0)
				str.clear();
		}
	}
	return (true);
}

void	Phonebook::add(void)
{
	std::string	str = "";
	int			field = 0;

	std::getline(std::cin, str);
	if (!_overwrite(str) && !std::cin.eof())
		return ;
	str.clear();
	while (field < 5 && !std::cin.eof())
	{
		if (field == 0)
		{
			std::cout << "Enter first name's contact" << std::endl;
			std::getline(std::cin, str);
			if(str.length() != 0)
			{
				this->_contact[_index].set_first_name(str);
				field++;
				str.clear();
			}
		}
		if (field == 1)
		{
			std::cout << "Enter " << this->_contact[_index].get_first_name() << " last name" << std::endl;
			std::getline(std::cin, str);
			if(str.length() != 0)
			{
				this->_contact[_index].set_last_name(str);
				field++;
				str.clear();
			}
		}
		if (field == 2)
		{
			std::cout << "Enter " << this->_contact[_index].get_first_name() << " nickname" << std::endl;
			std::getline(std::cin, str);
			if(str.length() != 0)
			{
				this->_contact[_index].set_nickname(str);
				field++;
				str.clear();
			}
		}
		if (field == 3)
		{
			std::cout << "Enter " << this->_contact[_index].get_first_name() << " phone number" << std::endl;
			std::getline(std::cin, str);
			if(str.length() != 0)
			{
				this->_contact[_index].set_phone(str);
				field++;
				str.clear();
			}
		}
		if (field == 4)
		{
			std::cout << "Now if you can spit " << this->_contact[_index].get_first_name() << "'s secret" << std::endl;
			std::getline(std::cin, str);
			if(str.length() != 0)
			{
				this->_contact[_index].set_secret(str);
				field++;
				str.clear();
				_index++;
				_count++;
				std::cout << "Contact number [" << this->_index << "/8] has been added" << std::endl;
			}
		}
	}
	return ;
}

int	Phonebook::get_count(void) const
{
	return (this->_count);
}


void	Phonebook::search(void)
{
	Contact				contact;
	std::string			str = "";
	std::stringstream	ss;
	int					index;

	std::getline(std::cin, str);
	if (_index == _count)
		std::cout << "Empty phonebook, please add contacts first" << std::endl;
	else
	{
		display_ui(*this);
		std::string	str = "";
		std::cout << "Who do you wanna print ?" << std::endl;
		std::getline(std::cin, str);
		while(str.length() != 0)
		{
			ss << str;
			ss >> index;
			if (index > 0 && index <= 8)
			{
				index -= 1;
				print(getcontact(index));
				return ;
			}
			else
			{
				ss << "";
				ss.clear();
				str.clear();
				std::getline(std::cin, str);
			}
		}
	}
	return ;
}
void	Phonebook::print(Contact contact) const
{
	std::cout << "First name: " << contact.get_first_name() << std::endl;
	std::cout << contact.get_first_name() << "'s last name: " << contact.get_last_name() << std::endl;
	std::cout << contact.get_first_name() << "'s nickname: " << contact.get_nickname() << std::endl;
	std::cout << contact.get_first_name() << "'s phone number: " << contact.get_phone() << std::endl;
	std::cout << contact.get_first_name() << "'s darkest secret: " << contact.get_secret() << std::endl;
	return ;
}

Contact	Phonebook::getcontact(int index) const
{
	return (this->_contact[index]);
}
