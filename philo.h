/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:38:27 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/27 11:27:58 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct l_stock
{
	size_t			timee;
	long long		time_eat;
	long long		time_sleep;
	long long		time_die;
	long long		philo_nb;
	long long		stop;
	struct l_list	*head;
}				t_stock;

typedef struct l_list
{
	struct l_list	*next;
	struct l_list	*prev;
	pthread_t		hawahed;
	pthread_mutex_t	fork;
	pthread_mutex_t	printactiv;
	pthread_mutex_t	hadiankhdembiha;
	int				content;
	int				flag;
	struct l_stock	*ghbiy;
	long long		lasttime;
	int				eating;
}				t_list;

int			numberofphilo(char **checker);
int			ft_atoi(const char *str);
int			abovesixteen(char **sechecker);
int			intchecker(char	**arguments);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(int content, t_stock *l);
void		copythisht(char **stocking, t_list *full);
long long	currenttime(void);
void		ft_go_sleep(long long how);
int			countingnb(t_list *philoso);
int			ft_onewhile(t_list *philoso);
void		printactivity(t_list *philo, char *message);

#endif