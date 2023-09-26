/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:39:27 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/26 11:43:10 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RobotomyRequestForm.hpp"
#include "./Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
	AForm(target + "_RobotomyRequestForm", 
		ROBOTOMYREQUESTSIGNGRADE, ROBOTOMYREQUESTEXECGRADE),
	_target(target),
	NotSignedException(std::string(RED EXC_T + getName() + N_SIGN R_COL))
{
	std::cout << "RobotomyRequestForm constructor called for ";
	std::cout << getName() << " with target " << _target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called for ";
	std::cout << getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& b) : 
	AForm(b._target + "_ShrubberyCreationForm", 
		ROBOTOMYREQUESTSIGNGRADE, ROBOTOMYREQUESTEXECGRADE),
	_target(b._target),
	NotSignedException(std::string(RED EXC_T + b.getName() + N_SIGN R_COL))
{
	std::cout << "RobotomyRequestForm copy constructor called for ";
	std::cout << getName() << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& b)
{
	std::cout << "RobotomyRequestForm copy assignment operator called for ";
	std::cout << getName() << " to become " << b.getName() << std::endl;
	return (*new RobotomyRequestForm(b));
}

const std::runtime_error& 	RobotomyRequestForm::getNotSignedException() const
{
	return (NotSignedException);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw getGradeTooLowException();
	if (!getSigned())
		throw NotSignedException;
	std::cout << PURPLE "Drrrrrrrilllling...." R_COL << std::endl;
	srand(time(0));
    if (rand() % 2)
		std::cout << BLUE << getTarget() << " has been robotomized" << R_COL << std::endl;	
	else
		std::cout << PURPLE << "Robotomy failed on " << getTarget() << R_COL << std::endl;	
	std::cout << GREEN << getName() << " executed on target " << getTarget() << R_COL << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& b)
{
	os << b.getName() << ", RobotomyRequestForm signing grade " << b.getSignGrade();
	os << ", and execution grade " << b.getExecGrade()  << " with target " << b.getTarget();
	return (os);
}
