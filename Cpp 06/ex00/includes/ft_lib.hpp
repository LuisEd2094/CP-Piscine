/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:52:43 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:52:44 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_HPP
# define FT_LIB_HPP

# include <iostream>
# include <cstdlib>

std::string remove_white_space(std::string str);
bool        check_if_only_zeros(const std::string &str);
bool        is_only_numbers(const std::string &str);

#endif
