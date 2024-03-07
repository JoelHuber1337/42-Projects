/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:25:26 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/27 15:25:27 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		write(1, &str[x], 1);
		x++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x] != '\0' && s2[x] != '\0')
	{
		if (s1[x] != s2[x])
			return (s1[x] - s2[x]);
		x++;
	}
	return (s1[x] - s2[x]);
}

void	ft_swap(char **a, char **b)
{
	char	*n;

	n = *a;
	*a = *b;
	*b = n;
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	y = 1;
	while (y < argc)
	{
		x = 1;
		while (x < argc - 1)
		{
			if (ft_strcmp(argv[x], argv[x + 1]) > 0)
			{
				ft_swap(&argv[x], &argv[x + 1]);
			}
			x++;
		}
		y++;
	}
	y = 1;
	while (y < argc)
	{
		put_putstr(argv[y++]);
		write(1, "\n", 1);
	}
}
