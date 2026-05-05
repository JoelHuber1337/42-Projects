/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:26:15 by johuber           #+#    #+#             */
/*   Updated: 2025/12/05 20:26:17 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int arc, char **arv)
{
	if (arc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int y = 1; arv[y]; y++)
	{
		for (int x = 0; arv[y][x]; x++)
		{
			if (isprint(arv[y][x]))
				std::cout << (char)toupper(arv[y][x]);
		}
	}
	std::cout << std::endl;
	return (0);
}