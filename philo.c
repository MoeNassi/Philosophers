/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:10:49 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/27 14:17:33 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	currenttime(void)
{
	struct timeval				time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	printactivity(t_list *philo, char *message)
{
	pthread_mutex_lock(&philo->hadiankhdembiha);
	printf("%lld %d %s\n", currenttime()
		- philo->ghbiy->timee, philo->content, message);
	if (philo->flag)
		pthread_mutex_unlock(&philo->hadiankhdembiha);
}

void	*philoeatorsleep(void *philo)
{
	t_list			*philos;

	philos = (t_list *)philo;
	if (philos->content % 2)
		usleep(200);
	while (philos->flag)
	{
		pthread_mutex_lock(&philos->fork);
		printactivity(philos, "has taken a fork");
		pthread_mutex_lock(&philos->next->fork);
		printactivity(philos, "has taken a fork");
		pthread_mutex_lock(&philos->printactiv);
		philos->lasttime = currenttime();
		philos->eating++;
		printactivity(philos, "is eating");
		pthread_mutex_unlock(&philos->printactiv);
		ft_go_sleep(philos->ghbiy->time_eat);
		pthread_mutex_unlock(&philos->fork);
		pthread_mutex_unlock(&philos->next->fork);
		printactivity(philos, "is sleeping");
		ft_go_sleep(philos->ghbiy->time_sleep);
		printactivity(philos, "is thinking");
	}
	return (NULL);
}

int	ft_allem(t_list *philo)
{
	t_list	*head;

	head = philo;
	while (philo)
	{
		head->lasttime = currenttime();
		if (pthread_create(&head->hawahed, NULL, &philoeatorsleep, head) != 0)
			return (printf("%s\n", "Error"));
		pthread_detach(head->hawahed);
		head = head->next;
		if (head == philo)
			break ;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list		*philoso;
	t_stock		all;
	int			stock;
	int			i;

	i = 1;
	if (ac - 1 > 3 && ac - 1 < 6)
	{
		if (intchecker(av) && numberofphilo(av) && abovesixteen(av))
		{
			stock = ft_atoi(av[1]);
			while (i <= stock)
				ft_lstadd_back(&philoso, ft_lstnew(i++, &all));
			copythisht(av, philoso);
			all.timee = currenttime();
			ft_allem(philoso);
			if (!ft_onewhile(philoso))
				return (0);
			pthread_mutex_unlock(&philoso->printactiv);
		}
		else
			return (printf("%s\n", "Error"));
	}
	else
		return (printf("%s\n", "Error"));
}
