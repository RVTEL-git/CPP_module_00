/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:27:15 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/28 11:01:26 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "contact.class.hpp"

class Phonebook {
	public:
		Phonebook(void);
		~Phonebook(void);
		void	add(void);
		void	search(void);
		void	print(Contact contact) const;

		int		get_count(void) const;
		Contact	getcontact(int index) const;

	private:
		Contact _contact[8];
		int		_index;
		int		_count;

		bool	_overwrite(std::string str);
};

#endif