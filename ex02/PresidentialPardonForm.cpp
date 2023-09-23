/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:40:30 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/23 19:09:36 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PresidentialPardonForm.hpp"
#include "./Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
	AForm(target + "_PresidentialPardonForm", 
		PRESIDENTIALPARDONSIGNGRADE, PRESIDENTIALPARDONEXECGRADE),
	_target(target),
	NotSignedException(std::string("Exception. " + getName() + " NOT signed"))
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
	AForm(_target + "_PresidentialPardonForm", 
		PRESIDENTIALPARDONSIGNGRADE, PRESIDENTIALPARDONEXECGRADE),
	_target(b._target),
	NotSignedException(std::string("Exception. " + getName() + " NOT signed"))
{
	std::cout << "PresidentialPardonForm copy constructor called for ";
	std::cout << getName() << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& b)
{
	std::cout << "PresidentialPardonForm copy assignment operator called for ";
	std::cout << getName() << " to become " << b.getName() << std::endl;
	return (*new PresidentialPardonForm(b));
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
	std::cout << getName() << " executed on target " << getTarget() << std::endl;
	//TODO actual execution
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b)
{
	os << b.getName() << ", PresidentialPardonForm signing grade " << b.getSignGrade();
	os << ", and execution grade " << b.getExecGrade()  << " with target " << b.getTarget();
	return (os);
}
