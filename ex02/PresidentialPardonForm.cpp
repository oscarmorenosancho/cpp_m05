/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:40:30 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/27 14:09:20 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PresidentialPardonForm.hpp"
#include "./Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
	AForm(target + "_PresidentialPardonForm", 
		PRESIDENTIALPARDONSIGNGRADE, PRESIDENTIALPARDONEXECGRADE),
	_target(target),
	NotSignedException(std::string(RED EXC_T + getName() + N_SIGN R_COL))
{
	std::cout << "PresidentialPardonForm constructor called for ";
	std::cout << getName() << " with target " << _target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called for ";
	std::cout << getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& b) : 
	AForm(b._target + "_ShrubberyCreationForm", 
		PRESIDENTIALPARDONSIGNGRADE, PRESIDENTIALPARDONEXECGRADE),
	_target(b._target),
	NotSignedException(std::string(RED EXC_T + b.getName() + N_SIGN R_COL))
{
	std::cout << "PresidentialPardonForm copy constructor called for ";
	std::cout << getName() << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& b)
{
	std::cout << "PresidentialPardonForm copy assignment operator called for ";
	std::cout << getName() << " to become " << b.getName() << std::endl;
	if (this != &b)
	{
		delete this;
		PresidentialPardonForm* tmp = new PresidentialPardonForm(b);
		return (*tmp);
	}
	return (*this);
}

const std::runtime_error& 	PresidentialPardonForm::getNotSignedException() const
{
	return (NotSignedException);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw getGradeTooLowException();
	if (!getSigned())
		throw NotSignedException;
	std::cout << YELLOW << getTarget() << " has been pardoned by Zaphod Beeblebrox" << R_COL << std::endl;
	std::cout << GREEN << getName() << " executed on target " << getTarget() << R_COL << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b)
{
	os << b.getName() << ", PresidentialPardonForm signing grade " << b.getSignGrade();
	os << ", and execution grade " << b.getExecGrade()  << " with target " << b.getTarget();
	return (os);
}
