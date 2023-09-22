/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:22:38 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/23 01:38:47 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat a("A", 5);
	Bureaucrat b("B", 5);
	Bureaucrat c(a);
	Bureaucrat d("D", 150);
	Form form("Permission", 100, 50);
	Form strictForm("Strict Permission", 1, 50);
	std::cerr << "#Try contructor with grade 0" << std::endl;
	try
	{
		Bureaucrat omega("Omega", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "#Try contructor with grade 151" << std::endl;
	try
	{
		Bureaucrat eta("Eta", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "#Status" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	d = b;
	std::cout << "#Try grade increments" << std::endl;
	try
	{
		a.incrementGrade(1);
		b.incrementGrade(5);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "#Status" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << "#Try grade decrements" << std::endl;
	try
	{
		a.decrementGrade(1);
		b.decrementGrade(150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "#Status" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	a.signForm(form);
	b.signForm(strictForm);
	return 0;
}
