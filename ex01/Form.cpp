/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:11:05 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/23 01:33:51 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"
#include "./Bureaucrat.hpp"
#include <iostream>

Form::Form(std::string name, int sign_grade, int exec_grade): _name(name), 
	_signGrade(sign_grade), _execGrade(exec_grade),
	GradeTooLowException(std::string("Exception. Grade Too Low for ") + _name),
	GradeTooHighException(std::string("Exception. Grade Too High for " + _name))
{
	_signed = false;
	std::cout << "Form constructor called for ";
	std::cout << _name << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException;
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException;
}

Form::~Form()
{
	std::cout << "Form destructor called for ";
	std::cout << _name << std::endl;
}

Form::Form(const Form& b) : _name(b._name + "_copy"),
	_signGrade(b._signGrade), _execGrade(b._execGrade), _signed(b._signed),
	GradeTooLowException(std::string("Exception. Grade Too Low for ") + _name),
	GradeTooHighException(std::string("Exception. Grade Too High for " + _name))
{
	std::cout << "Form copy constructor called for ";
	std::cout << _name << std::endl;
}

Form& Form::operator=(const Form& b)
{
	std::cout << "Form copy assignment operator called for ";
	std::cout << _name << " to become " << b._name << std::endl;
	return (*new Form(b));
}

const std::string	Form::getName() const
{
	return (_name);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecGrade() const
{
	return (_execGrade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException;
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
	os << b.getName() << ", form signing grade " << b.getSignGrade();
	os << ", and execution grade " << b.getExecGrade();
	return (os);
}