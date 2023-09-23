/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:11:05 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/23 01:33:51 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"
#include "./Bureaucrat.hpp"
#include <iostream>

AForm::AForm(std::string name, int sign_grade, int exec_grade): _name(name), 
	_signGrade(sign_grade), _execGrade(exec_grade),
	GradeTooLowException(std::string("Exception. Grade Too Low for ") + _name),
	GradeTooHighException(std::string("Exception. Grade Too High for " + _name))
{
	_signed = false;
	std::cout << "AForm constructor called for ";
	std::cout << _name << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException;
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called for ";
	std::cout << _name << std::endl;
}

AForm::AForm(const AForm& b) : _name(b._name + "_copy"),
	_signGrade(b._signGrade), _execGrade(b._execGrade), _signed(b._signed),
	GradeTooLowException(std::string("Exception. Grade Too Low for ") + _name),
	GradeTooHighException(std::string("Exception. Grade Too High for " + _name))
{
	std::cout << "AForm copy constructor called for ";
	std::cout << _name << std::endl;
}

AForm& AForm::operator=(const AForm& b)
{
	AForm& ref = *(AForm *)&b;
	std::cout << "AForm copy assignment operator called for ";
	std::cout << _name << " to become " << b._name << std::endl;
	std::cout << "Since AForm is Abstract can't be created a new one, ";
	std::cout << "the same reference is returned" << std::endl;
	return (ref);
}

const std::underflow_error& 	AForm::getGradeTooLowException() const
{
	return (GradeTooLowException);
}

const std::overflow_error&	AForm::getGradeTooHighException() const
{
	return (GradeTooHighException);
}

const std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecGrade() const
{
	return (_execGrade);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException;
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& b)
{
	os << b.getName() << ", signing grade " << b.getSignGrade();
	os << ", and execution grade " << b.getExecGrade();
	os << ", is";
	if (!b.getSigned())
		os << " NOT";
	os << " signed";
	return (os);
}