/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:40:42 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/23 19:26:40 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRESIDENTIALPARDONFORM_HPP_
# define _PRESIDENTIALPARDONFORM_HPP_

# include <string>
# include <stdexcept>
# include "./AForm.hpp"
# define PRESIDENTIALPARDONSIGNGRADE 25
# define PRESIDENTIALPARDONEXECGRADE 5
# define EXC_T "Exception. "
# define N_SIGN " NOT signed"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
	std::string				_target;
	std::runtime_error 		NotSignedException;
protected:
	const std::runtime_error& 	getNotSignedException() const;
public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& b);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& b);
	std::string			getTarget() const;
	void				execute(Bureaucrat const & executor) const;
};

#endif