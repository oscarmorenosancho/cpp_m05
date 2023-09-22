/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:22:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/22 23:34:18 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_HPP_
# define _BUREAUCRAT_HPP_

# include <string>
# include <stdexcept>

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