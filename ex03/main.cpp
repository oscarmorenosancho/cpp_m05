/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:22:38 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/27 14:32:50 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Bureaucrat.hpp"
#include "./Intern.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

void	ft_print_status(Bureaucrat **bureaucrats, AForm **forms)
{
	std::cout << YELLOW "#Status" << std::endl;
	std::cout << *bureaucrats[0] << std::endl;
	std::cout << *bureaucrats[1] << std::endl;
	std::cout << *bureaucrats[2] << std::endl;
	std::cout << *bureaucrats[3] << std::endl;
	std::cout << *forms[0] << std::endl;
	std::cout << *forms[1] << std::endl;
	std::cout << *forms[2] << std::endl;
	std::cout << *forms[3] << std::endl;
	std::cout << R_COL;
}

int main(void)
{
	Bureaucrat a("A", 4);
	Bureaucrat b("B", 35);
	Bureaucrat c(a);
	Bureaucrat& d = *new Bureaucrat("D", 150);
	Intern  someRandomIntern;
    AForm*   rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	ShrubberyCreationForm form("Garden");
	RobotomyRequestForm robForm("HAL");
	PresidentialPardonForm strictForm("Guilty");
	AForm*	forms[4] ={&form, &robForm, rrf, &strictForm};
	Bureaucrat*	bureaucrats[4] ={&a, &b, &c, &d};

	ft_print_status(bureaucrats, forms);
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
	ft_print_status(bureaucrats, forms);
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
	ft_print_status(bureaucrats, forms);
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
	ft_print_status(bureaucrats, forms);
	std::cout << BLUE "#Try execute before signing" R_COL << std::endl;
	a.executeForm(robForm);
	c.executeForm(form);
	b.executeForm(strictForm);
	ft_print_status(bureaucrats, forms);
	std::cout << BLUE "#Try sign" R_COL << std::endl;
	c.signForm(form);
	b.signForm(robForm);
	b.signForm(*rrf);
	a.signForm(strictForm);
	ft_print_status(bureaucrats, forms);
	std::cout << BLUE "#Try execute after signing" R_COL << std::endl;
	a.executeForm(form);
	a.executeForm(robForm);
	a.executeForm(*rrf);
	b.executeForm(strictForm);
	c.executeForm(strictForm);
	a.executeForm(strictForm);
	ft_print_status(bureaucrats, forms);
	delete &d;
	delete rrf;
	return 0;
}
