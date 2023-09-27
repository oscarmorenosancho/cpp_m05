/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:22:38 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/27 14:31:09 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat a("A", 4);
	Bureaucrat b("B", 35);
	Bureaucrat c(a);
	Bureaucrat& d = *new Bureaucrat("D", 150);
	ShrubberyCreationForm form("Garden");
	RobotomyRequestForm robForm("HAL");
	PresidentialPardonForm strictForm("Guilty");
	std::cout << BLUE "#Try contructor with grade 0" R_COL << std::endl;
	try
	{
		Bureaucrat omega("Omega", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << BLUE "#Try contructor with grade 151" R_COL << std::endl;
	try
	{
		Bureaucrat eta("Eta", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << YELLOW "#Status" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << form << std::endl;
	std::cout << robForm << std::endl;
	std::cout << strictForm << std::endl;
	std::cout << BLUE "#Try grade increments" R_COL << std::endl;
	try
	{
		a.incrementGrade(1);
		b.incrementGrade(5);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << YELLOW "#Status" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << form << std::endl;
	std::cout << robForm << std::endl;
	std::cout << strictForm << std::endl;
	std::cout << R_COL;
	std::cout << BLUE "#Try grade decrements" R_COL << std::endl;
	try
	{
		a.decrementGrade(1);
		b.decrementGrade(150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	//d = b;
	std::cout << YELLOW "#Status" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << form << std::endl;
	std::cout << robForm << std::endl;
	std::cout << strictForm << std::endl;
	std::cout << R_COL;
	std::cout << BLUE "#Try execute before signing" R_COL << std::endl;
	a.executeForm(robForm);
	c.executeForm(form);
	b.executeForm(strictForm);
	std::cout << YELLOW "#Status" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << form << std::endl;
	std::cout << robForm << std::endl;
	std::cout << strictForm << std::endl;
	std::cout << R_COL;
	std::cout << BLUE "#Try sign" R_COL << std::endl;
	c.signForm(form);
	b.signForm(robForm);
	a.signForm(strictForm);
	std::cout << YELLOW "#Status" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << form << std::endl;
	std::cout << robForm << std::endl;
	std::cout << strictForm << std::endl;
	std::cout << R_COL;
	std::cout << BLUE "#Try execute after signing" R_COL << std::endl;
	a.executeForm(form);
	a.executeForm(robForm);
	b.executeForm(strictForm);
	c.executeForm(strictForm);
	a.executeForm(strictForm);
	std::cout << YELLOW "#Status" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << form << std::endl;
	std::cout << robForm << std::endl;
	std::cout << strictForm << std::endl;
	std::cout << R_COL;
	delete &d;
	return 0;
}
