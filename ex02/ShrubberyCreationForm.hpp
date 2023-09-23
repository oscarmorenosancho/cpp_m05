/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:35:47 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/24 00:31:13 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SHRUBBERYCREATIONFORM_HPP_
# define _SHRUBBERYCREATIONFORM_HPP_

# include <string>
# include <stdexcept>
# include "./AForm.hpp"
# define SHRUBBERYCREATIONSIGNGRADE 145
# define SHRUBBERYCREATIONEXECGRADE 137
# define EXC_T "Exception. "
# define N_SIGN " NOT signed"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
	std::string				_target;
	std::runtime_error 		NotSignedException;
	void					CreateGreenTree(std::ostream& os) const;
	void					CreateGoldenTree(std::ostream& os) const;
protected:
	const std::runtime_error& 	getNotSignedException() const;
public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& b);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& b);
	std::string			getTarget() const;
	void				execute(Bureaucrat const & executor) const;
};

#endif