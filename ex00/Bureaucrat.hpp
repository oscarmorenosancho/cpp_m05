/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:22:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/23 18:32:50 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_HPP_
# define _BUREAUCRAT_HPP_
# include <string>
# include <stdexcept>
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
# define EXC_GTL "Exception. Grade Too Low for "
# define EXC_GTH "Exception. Grade Too HIGH for "

class Bureaucrat
{
private:
	const std::string		_name;
	int						_grade;
	std::underflow_error 	GradeTooLowException;
	std::overflow_error		GradeTooHighException;
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& b);
	Bureaucrat& operator=(const Bureaucrat& b);
	const std::string	getName() const;
	int 				getGrade() const;
	void				incrementGrade(int amount);
	void				decrementGrade(int amount);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif