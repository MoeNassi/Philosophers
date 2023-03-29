/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onewhile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:20:23 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/27 11:25:08 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_onewhile(t_list *philoso)
{
	while (1)
	{
		pthread_mutex_lock(&philoso->printactiv);
		if (philoso->ghbiy->stop)
		{
			if (philoso->eating > philoso->ghbiy->stop)
				philoso->ghbiy->philo_nb -= 1;
			if (!philoso->ghbiy->philo_nb)
			{
				philoso->flag = 0;
				return (0);
			}
		}
		if ((currenttime() - philoso->lasttime) > philoso->ghbiy->time_die)
		{
			printactivity(philoso, "died");
			philoso->flag = 0;
			return (0);
		}
		pthread_mutex_unlock(&philoso->printactiv);
		philoso = philoso->next;
	}
	return (1);
}
