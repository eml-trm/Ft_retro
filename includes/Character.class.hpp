
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 14:31:59 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 14:32:00 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class Character
{

public:
	Character( void );
	Character( Character const & src);
	~Character( void );
	
	Character & operator=( Character const & rhs);

private:
	std::string _name;
	std::string _type;
};

#endif