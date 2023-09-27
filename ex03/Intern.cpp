/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:20:36 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/27 13:00:27 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(/* args */)
{
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& b)
{
	(void)b;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& b)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	if (this != &b)
	{
		delete this;
		Intern* tmp = new Intern(b);
		return (*tmp);
	}
	return (*this);
}

AForm	*Intern::CreateShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::CreateRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::CreatePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

std::string 	Intern::types[3] = 
					{"shrubbery creation",
					"robotomy request",
					"presidential pardon"};
					
AForm 			*(*Intern::creator[3])(std::string target) = 
					{Intern::CreateShrubberyCreationForm,
					Intern::CreateRobotomyRequestForm,
					Intern::CreatePresidentialPardonForm};

AForm *Intern::makeForm(std::string form, std::string target)
{
	AForm		*ret = nullptr;

	int i = 0;
	while (i < 3 && types[i] != form)
		i++;
	switch (i)
	{
	case 0:
		ret = new ShrubberyCreationForm(target);
		break;
	case 1:
		ret = new RobotomyRequestForm(target);
		break;
	case 2:
		ret = new PresidentialPardonForm(target);
		break;
	default:
		std::cout << RED "Form of type " << form << " non existent!" R_COL << std::endl;
		return (ret);
	}
	std::cout << "Intern creates " << form << std::endl;
	return (ret);
}

