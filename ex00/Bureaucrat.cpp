/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:22:34 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/22 23:03:41 by omoreno-         ###   ########.fr       */
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
	;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b._name),
	GradeTooLowException(std::string("Exception. Grade Too Low for ") + _name),
	GradeTooHighException(std::string("Exception. Grade Too High for " + _name))
{
	std::cout << "Bureaucrat copy constructor called for ";
	std::cout << _name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
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

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException;
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException;
	_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}