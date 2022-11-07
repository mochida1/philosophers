/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ph.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:50:51 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/07 20:39:39 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int	sub_init_ph3(t_phil *ph, t_init *data)
{
	unsigned int	i;
	char			*tmp_forks;

	i = 0;
	tmp_forks = ft_calloc(data->nop, sizeof(char));
	while (i < data->nop)
	{
		ph[i].forks = tmp_forks;
		ph[i].own_fork = ph[i].philo;
		if (ph[i].philo == ph[i].data->nop - 1)
			ph[i].other_fork = 0;
		else
			ph[i].other_fork = ph[i].philo + 1;
		i++;
	}
	return (0);
}

static int	sub_init_ph2(t_phil *ph, t_init *data)
{
	unsigned int	i;
	long long		*to_die;
	int				*eats;

	i = 0;
	to_die = ft_calloc(data->nop, sizeof(long long int));
	if (!to_die)
		return (1);
	if (data->endwhen)
	{
		eats = ft_calloc(data->nop, sizeof(int));
		if (!eats)
			return (1);
	}
	else
		eats = NULL;
	while (i < data->nop)
	{
		ph[i].timer_die = to_die;
		ph[i].num_eat = eats;
		i++;
	}
	return (0);
}

static int	init_mutex(pthread_mutex_t *mut, t_init *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nop)
	{
		if (pthread_mutex_init(&mut[i], NULL))
			return (destroy_all_mutexes(mut, i));
		i++;
	}
	return (i);
}

static int	sub_init_ph1(t_phil *ph, t_init *data)
{
	unsigned int	i;
	pthread_mutex_t	*mut;
	long long		*to_eat;
	long long		*to_sleep;

	i = 0;
	mut = ft_calloc(data->nop, sizeof(*mut));
	init_mutex(mut, data);
	to_eat = ft_calloc(data->nop, sizeof(long long int));
	to_sleep = ft_calloc(data->nop, sizeof(long long int));
	while (i < data->nop)
	{
		ph[i].philo = i;
		ph[i].fasted = i;
		ph[i].data = data;
		ph[i].mutex = mut;
		ph[i].timer_eat = to_eat;
		ph[i].timer_sleep = to_sleep;
		i++;
	}
	return (0);
}

int	init_ph(t_phil *ph, t_init *data)
{
	if (sub_init_ph1(ph, data))
		return (1);
	if (sub_init_ph2(ph, data))
		return (1);
	if (sub_init_ph3(ph, data))
		return (1);
	if (ph->num_eat)
		if (cpy_to_ph(ph, data))
			return (1);
	return (0);
}
