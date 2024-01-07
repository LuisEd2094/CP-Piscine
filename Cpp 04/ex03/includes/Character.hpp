/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:29:33 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:29:33 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"


class Character : public ICharacter
{
    public:
        Character(const std::string& name);
	    Character(const Character& other);
	
    	Character& operator=(const Character& rhs);
	    ~Character(void);

        std::string const & getName(void) const;
	    
        void equip(AMateria* m);
	    void unequip(int idx);
	    void use(int idx, ICharacter& target);
    private:
        Character(void);
        AMateria*   _inventory[4];
        std::string _name;
};

#endif
