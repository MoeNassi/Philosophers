/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:10:49 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/03 14:45:04 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	(void)av;
	if (ac - 1 > 3 && ac - 1 < 6)
	{
		if (intchecker(av) && numberofphilo(av) && abovesixteen(av))
		{
			return (puts("hi"), 0);
		}
	}
	return (printf("%s\n", "Error"));
}