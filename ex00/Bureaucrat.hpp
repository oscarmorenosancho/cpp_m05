/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:22:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/22 17:57:58 by omoreno-         ###   ########.fr       */
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
	Bureaucrat(std::string name, u_int8_t grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& b);
	Bureaucrat& operator=(const Bureaucrat& b);
	const std::string	getName() const;
	int 				getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
};

#endif