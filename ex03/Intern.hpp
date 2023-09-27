/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:20:42 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/27 12:57:53 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INTERN_HPP_
# define _INTERN_HPP_
# include <string>
# include "AForm.hpp"
# ifndef BLACK
#  define BLACK "\e[0;30m"
#  define RED "\e[0;31m"
#  define GREEN "\e[0;32m"
#  define YELLOW "\e[0;33m"
#  define BLUE "\e[0;34m"
#  define PURPLE "\e[0;35m"
#  define CYAN "\e[0;36m"
#  define WHITE "\e[0;37m"
#  define R_COL "\e[0m"
# endif

class Intern
{
private:
	static AForm		*CreateShrubberyCreationForm(std::string target);
	static AForm		*CreateRobotomyRequestForm(std::string target);
	static AForm		*CreatePresidentialPardonForm(std::string target);
	static AForm 		*(*creator[3])(std::string target);
	static std::string	types[3];
public:
	Intern();
	~Intern();
	Intern(const Intern& b);
	Intern& operator=(const Intern& b);
	AForm	*makeForm(std::string form, std::string target);
};

#endif