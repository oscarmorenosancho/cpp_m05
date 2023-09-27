/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:20:36 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/27 20:32:45 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
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
	(void)b;
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
	AForm			*ret = (AForm *)NULL;
	unsigned int	i = 0;

	while (i < 3 && types[i] != form)
		i++;
	if (i > 2)
	{
		std::cout << RED "Form of type " << form << " non existent!" R_COL << std::endl;
		return (ret);
	}
	ret = creator[i](target);
	std::cout << "Intern creates " << ret->getName() << std::endl;
	return (ret);
}

