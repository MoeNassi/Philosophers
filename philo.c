/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:10:49 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/20 15:33:10 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	currenttime(void)
{
	struct timeval				time;
	long long				stockthetime;

	gettimeofday(&time, NULL);
	stockthetime = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (stockthetime);
}

void	printactivity(t_list *philo, char *message)
{
	printf("%lld %d %s\n", currenttime() - philo->ghbiy->timee, philo->content, message);
}

void	*philoeatorsleep(void *philo)
{
	t_list			*philos;

	philos = (t_list *)philo;
	while (philos)
	{
		pthread_mutex_lock(&philos->fork);
		printactivity(philos, "has taken a fork");
		pthread_mutex_lock(&philos->next->fork);
		printactivity(philos, "has taken a fork");
		printactivity(philos, "is eating");
		philos->lasttime = currenttime();
		usleep(philos->time_eat * 1000);
		pthread_mutex_unlock(&philos->next->fork);
		pthread_mutex_unlock(&philos->fork);
		printactivity(philos, "is sleeping");
		usleep(philos->time_sleep * 1000);
		printactivity(philos, "is thinking");
		if ((currenttime() - philos->lasttime) > philos->time_die)
		{
			printactivity(philos, "died");
			philos->flag = 0;
		}
	}
	return (NULL);
}

int main(int ac, char **av)
{
	int			i;
	t_list		*philoso;
	t_list		*head;
	t_stock		all;
	int			stock;

	i = 1;
	stock = ft_atoi(av[1]);
	if (ac - 1 > 3 && ac - 1 < 6)
	{
		if (intchecker(av) && numberofphilo(av) && abovesixteen(av))
		{
			while (i <= stock)
				ft_lstadd_back(&philoso, ft_lstnew(i++, &all, av));
			pthread_mutex_init(&philoso->fork, NULL);
			head = philoso;
			all.timee = currenttime();
			while (philoso)
			{
				if (philoso->content % 2)
					usleep(100);
				philoso->lasttime = currenttime();
				if (pthread_create(&head->hawahed, NULL, &philoeatorsleep, head) != 0)
					return (printf("%s\n", "Error"));
				pthread_detach(head->hawahed);
				head = head->next;
				if (head == philoso || philoso->flag == 0)
					break ;
			}
			while(philoso->flag);
		}
		else
			return (printf("%s\n", "Error"));
	}
	else
		return (printf("%s\n", "Error"));
}