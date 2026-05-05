/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:45:31 by johuber           #+#    #+#             */
/*   Updated: 2025/12/10 18:44:24 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	Harl;
	Harl.complain("debug");
	Harl.complain("info");
	Harl.complain("error");
	Harl.complain("warning");
	Harl.complain("lalala");
}