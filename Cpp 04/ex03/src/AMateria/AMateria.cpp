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

Node *AMateria::list = NULL;
Node *AMateria::curr = NULL;

AMateria::AMateria(void) : _type("default") {}
AMateria::AMateria(std::string const &type) : _type(type) {}
AMateria::AMateria(const AMateria &src) : _type(src._type) {}

AMateria &AMateria::operator=(const AMateria &rhs)
{
    (void)rhs;
    return (*this);
}

AMateria::~AMateria() {}

std::string const &AMateria::getType(void) const
{
    return (_type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "Used default Materia against " << target.getName() << std::endl;
}

void AMateria::addToDropped(AMateria *materia)
{
    Node *temp;

    //Init list if first add
    if (!list)
    {
        list = new Node;
        list->next = NULL;
        list->materia = NULL;
        curr = list;
    }
    //Check if materia already on the list
    temp = list->next;
    while (temp)
    {
        if (temp->materia == materia)
            return;
        temp = temp->next;
    }
    //Create node and add pointer to list
    curr->next = new Node;
    curr = curr->next;
    curr->materia = materia;
    curr->next = NULL;
}

Node *AMateria::getMateriaList()
{
    return list ? list->next : NULL;
}

void AMateria::cleanList(void)
{

    Node *head = getMateriaList();
    Node *temp;
    while (head)
    {
        temp = head->next;
        delete head->materia;
        delete head;
        head = temp;
    }
    delete AMateria::list;
}
