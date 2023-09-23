/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:10:58 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/23 18:38:43 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AFORM_HPP_
# define _AFORM_HPP_

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