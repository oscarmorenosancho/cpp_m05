/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:39:34 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/23 19:27:02 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ROBOTOMYREQUESTFORM_HPP_
# define _ROBOTOMYREQUESTFORM_HPP_

# include <string>
# include <stdexcept>
# include "./AForm.hpp"
# define ROBOTOMYREQUESTSIGNGRADE 72
# define ROBOTOMYREQUESTEXECGRADE 45
# define EXC_T "Exception. "
# define N_SIGN " NOT signed"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
	std::string				_target;
	std::runtime_error 		NotSignedException;
protected:
	const std::runtime_error& 	getNotSignedException() const;
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& b);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& b);
	std::string			getTarget() const;
	void				execute(Bureaucrat const & executor) const;
};

#endif