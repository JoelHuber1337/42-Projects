/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:45:31 by johuber           #+#    #+#             */
/*   Updated: 2025/12/10 19:44:53 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

char	*strToLower(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		str[x] = tolower(str[x]);
		x++;
	}
	return (str);
}

int	main(int arc, char **arv)
{
	if (arc != 2)
	{
		std::cout << "Wrong input. Only takes one argument from the Complain levels.\n";
		return (1);
	}
	arv[1] = strToLower(arv[1]);
	Harl	Harl;
	Harl.complain(arv[1]);
	return (0);
}