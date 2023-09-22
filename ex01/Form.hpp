/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:10:58 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/23 01:31:08 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FORM_HPP_
# define _FORM_HPP_

# include <string>
# include <stdexcept>

class Bureaucrat;

class Form
{
private:
	const std::string		_name;
	const int				_signGrade;
	const int				_execGrade;
	bool					_signed;
	std::underflow_error 	GradeTooLowException;
	std::overflow_error		GradeTooHighException;
public:
	Form(std::string name, int sign_grade, int exec_grade);
	~Form();
	Form(const Form& b);
	Form& operator=(const Form& b);
	const std::string	getName() const;
	int 				getSignGrade() const;
	int 				getExecGrade() const;
	void				beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif