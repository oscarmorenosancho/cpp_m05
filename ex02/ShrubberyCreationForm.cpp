/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:36:04 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/23 19:33:15 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ShrubberyCreationForm.hpp"
#include "./Bureaucrat.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
	AForm(target + "_ShrubberyCreationForm", 
		SHRUBBERYCREATIONSIGNGRADE, SHRUBBERYCREATIONEXECGRADE),
	_target(target),
	NotSignedException(std::string(RED EXC_T + getName() + N_SIGN R_COL))
{
	std::cout << "ShrubberyCreationForm constructor called for ";
	std::cout << getName() << " with target " << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called for ";
	std::cout << getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& b) : 
	AForm(_target + "_ShrubberyCreationForm", 
		SHRUBBERYCREATIONSIGNGRADE, SHRUBBERYCREATIONEXECGRADE),
	_target(b._target),
	NotSignedException(std::string(RED EXC_T + getName() + N_SIGN R_COL))
{
	std::cout << "ShrubberyCreationForm copy constructor called for ";
	std::cout << getName() << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& b)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called for ";
	std::cout << getName() << " to become " << b.getName() << std::endl;
	return (*new ShrubberyCreationForm(b));
}

const std::runtime_error& 	ShrubberyCreationForm::getNotSignedException() const
{
	return (NotSignedException);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw getGradeTooLowException();
	if (!getSigned())
		throw NotSignedException;
	std::cout << getName() << " executed on target " << getTarget() << std::endl;
	//TODO actual execution
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& b)
{
	os << b.getName() << ", ShrubberyCreationForm signing grade " << b.getSignGrade();
	os << ", and execution grade " << b.getExecGrade()  << " with target " << b.getTarget();
	return (os);
}
