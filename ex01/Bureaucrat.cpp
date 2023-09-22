/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:22:34 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/23 01:39:44 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name),
	GradeTooLowException(std::string("Exception. Grade Too Low for ") + _name),
	GradeTooHighException(std::string("Exception. Grade Too High for " + _name))
{
	std::cout << "Bureaucrat constructor called for ";
	std::cout << _name << std::endl;
	if (grade < 1)
		throw GradeTooHighException;
	if (grade > 150)
		throw GradeTooLowException;
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called for ";
	std::cout << _name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b._name + "_copy"), _grade(b._grade),
	GradeTooLowException(std::string("Exception. Grade Too Low for ") + _name),
	GradeTooHighException(std::string("Exception. Grade Too High for " + _name))
{
	std::cout << "Bureaucrat copy constructor called for ";
	std::cout << _name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	this->_grade = b._grade;
	std::cout << "Bureaucrat copy assignment operator called for ";
	std::cout << _name << " to become " << b._name << std::endl;
	return (*new Bureaucrat(b));
}

const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(int amount)
{
	if (_grade - amount < 1)
		throw GradeTooHighException;
	_grade -= amount;
}

void	Bureaucrat::decrementGrade(int amount)
{
	if (_grade + amount > 150)
		throw GradeTooLowException;
	_grade += amount;
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn’t sign " << form.getName();
		std::cout << " because " << e.what();
		std::cout << ", its grade is lower than ";
		std::cout << form.getSignGrade() << " needed by form" << std::endl;
	}
	std::cout << _name <<" signed " << form.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}