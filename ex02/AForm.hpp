/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:10:58 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/23 17:16:52 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AFORM_HPP_
# define _AFORM_HPP_

# include <string>
# include <stdexcept>

class Bureaucrat;

class AForm
{
private:
	const std::string		_name;
	const int				_signGrade;
	const int				_execGrade;
	bool					_signed;
	std::underflow_error 	GradeTooLowException;
	std::overflow_error		GradeTooHighException;
protected:
	const std::underflow_error& 	getGradeTooLowException() const;
	const std::overflow_error&		getGradeTooHighException() const;
public:
	AForm(std::string name, int sign_grade, int exec_grade);
	virtual ~AForm();
	AForm(const AForm& b);
	AForm& operator=(const AForm& b);
	const std::string				getName() const;
	bool							getSigned() const;
	int 							getSignGrade() const;
	int 							getExecGrade() const;
	void							beSigned(const Bureaucrat& bureaucrat);
	virtual void					execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif