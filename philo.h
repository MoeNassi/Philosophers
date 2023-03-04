/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:38:27 by mnassi            #+#    #+#             */
/*   Updated: 2023/03/04 17:03:14 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	l_list
{
	struct l_list	*next;
	struct l_list	*prev;
	int				content;
}				t_list;

int		numberofphilo(char **checker);
int		ft_atoi(const char *str);
int		abovesixteen(char **sechecker);
int		intchecker(char	**arguments);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);

#endif