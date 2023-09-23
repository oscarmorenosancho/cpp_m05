/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:36:04 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/24 01:08:50 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ShrubberyCreationForm.hpp"
#include "./Bureaucrat.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>

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

void	ShrubberyCreationForm::CreateGreenTree(std::ostream& os) const
{
	os << GREEN;
	os << "            .        +          .      .          .   " << std::endl;
	os << "     .            _        .                    .     " << std::endl;
	os << "  ,              /;-._,-.____        ,-----.__        " << std::endl;
	os << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,    " << std::endl;
	os << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /      " << std::endl;
	os << "                      ,    `./  \\:. `.   )==-'  .     " << std::endl;
	os << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           . " << std::endl;
	os << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o         " << std::endl;
	os << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .  " << std::endl;
	os << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
	os << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/  " << std::endl;
	os << "              \\:  `  X` _| _,\\/'   .-'                " << std::endl;
	os << ".               \":._:\\`\\____  /:\'  /      .           ." << std::endl;
	os << "                    \\::.  :\\/:'  /              +     " << std::endl;
	os << "   .                 `.:.  /:'  }      .              " << std::endl;
	os << "           .           ):_(:;   \\           .         " << std::endl;
	os << "                      /:. _/ ,  |                     " << std::endl;
	os << "                   . (|::.     ,`                  .  " << std::endl;
	os << "     .                |::.    {\\                      " << std::endl;
	os << "                      |::.\\  \\ `.                     " << std::endl;
	os << "                      |:::(\\    |                     " << std::endl;
	os << "              O       |:::/{ }  |                  (o " << std::endl;
	os << "               )  ___/#\\::`/ (O \"==._____   O, (O  /\\` " << std::endl;
	os << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~ " << std::endl;
	os << "      ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~     " << std::endl;
	os << R_COL;
}
void	ShrubberyCreationForm::CreateGoldenTree(std::ostream& os) const
{
	os << YELLOW;
	os << "	                                              .       " << std::endl;
	os << "                                   .         ;         " << std::endl;
	os << "      .              .              ;%     ;;          " << std::endl;
	os << "        ,           ,                :;%  %;           " << std::endl;
	os << "         :         ;                   :;%;'     .,    " << std::endl;
	os << ",.        %;     %;            ;        %;'    ,;      " << std::endl;
	os << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'       " << std::endl;
	os << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'        " << std::endl;
	os << "    ;%;      %;        ;%;        % ;%;  ,%;'          " << std::endl;
	os << "     `%;.     ;%;     %;'         `;%%;.%;'            " << std::endl;
	os << "      `:;%.    ;%%. %@;        %; ;@%;%'               " << std::endl;
	os << "         `:%;.  :;bd%;          %;@%;'                 " << std::endl;
	os << "           `@%:.  :;%.         ;@@%;'                  " << std::endl;
	os << "             `@%.  `;@%.      ;@@%;                    " << std::endl;
	os << "               `@%%. `@%%    ;@@%;                     " << std::endl;
	os << "                 ;@%. :@%%  %@@%;                      " << std::endl;
	os << "                   %@bd%%%bd%%:;                       " << std::endl;
	os << "                     #@%%%%%:;;                        " << std::endl;
	os << "                     %@@%%%::;                         " << std::endl;
	os << "                     %@@@%(o);  . '                    " << std::endl;
	os << "                     %@@@o%;:(.,'                      " << std::endl;
	os << "                 `.. %@@@o%::;                         " << std::endl;
	os << "                    `)@@@o%::;                         " << std::endl;
	os << "                     %@@(o)::;                         " << std::endl;
	os << "                    .%@@@@%::;                         " << std::endl;
	os << "                    ;%@@@@%::;.                        " << std::endl;
	os << "                   ;%@@@@%%:;;;.                       " << std::endl;
	os << "               ...;%@@@@@%%:;;;;,..                    " << std::endl;
	os << R_COL;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw getGradeTooLowException();
	if (!getSigned())
		throw NotSignedException;
	std::cout << GREEN;
	std::cout << getName() << " executed on target " << getTarget() << std::endl;
	std::cout << R_COL;
	std::string filename(_target);
	filename += std::string("_shrubbery.txt");
	std::ofstream fout;
    fout.open(filename.c_str(), std::ios::trunc | std::ios::out);
	if (!fout.is_open())
	{
		std::cerr << RED "Error" << std::endl;
		std::cerr << "file: " << filename << " could not be opened to write";
		std::cerr << R_COL << std::endl;
		return;
	}
	srand(time(0));
	for (int i = std::rand() % 5; i >=0 ; i--)
    	if (rand() % 2)
			CreateGreenTree(fout);
		else
			CreateGoldenTree(fout);
	fout.close();
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& b)
{
	os << b.getName() << ", ShrubberyCreationForm signing grade " << b.getSignGrade();
	os << ", and execution grade " << b.getExecGrade()  << " with target " << b.getTarget();
	return (os);
}
