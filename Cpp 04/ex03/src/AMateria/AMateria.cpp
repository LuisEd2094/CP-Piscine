/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:29:21 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:29:22 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


Node* AMateria::list = NULL;
Node* AMateria::curr = NULL;


void AMateria::addMateria(AMateria *materia)
{
    if (!list)
    {
        list = new Node;
        curr = list;
    }

    Node *temp = list->next;

    while(temp)
    {
        if (temp->materia == materia)
            return;
        temp = temp->next;
    }
    curr->next = new Node;
    curr->next->materia = materia;
    curr = curr->next;
}

Node *AMateria::getMateriaList()
{
    return list->next;
}

void AMateria::cleanList(void) {

    Node *head = getMateriaList();
    Node *temp;
    while (head) 
    {
        temp = head->next;
        delete head;
        head = temp;
    }
    delete AMateria::list;
}

AMateria::AMateria(void) : _type("default") {}
AMateria::AMateria(std::string const& type) : _type(type) {}
AMateria::AMateria(const AMateria& src): _type(src._type) {}

AMateria& AMateria::operator=(const AMateria& rhs)
{
    (void)rhs;
    return (*this);
}

AMateria::~AMateria() {}

std::string const& AMateria::getType(void) const
{
    return (_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
