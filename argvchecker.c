/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argvchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:10:33 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/20 12:22:43 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	numberofphilo(char **checker)
{
	int		i;

	i = ft_atoi(checker[1]);
	if (i >= 1 && i <= 200)
		return (1);
	return (0);
}

int	abovesixteen(char **sechecker)
{
	int		i;

	i = 2;
	while (i < 5)
	{
		if (ft_atoi(sechecker[i]) < 60)
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	intchecker(char	**arguments)
{
	int	i;
	int	j;

	i = 1;
	while (arguments[i])
	{
		j = 0;
		if (arguments[i][j] == '-' && arguments[i][j + 1])
			j++;
		while (arguments[i][j])
		{
			if (!ft_isdigit(arguments[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	copythisht(char **stocking, t_list *full)
{
	full->time_eat = ft_atoi(stocking[3]);
	full->time_sleep = ft_atoi(stocking[4]);
	full->time_die = ft_atoi(stocking[2]);
}