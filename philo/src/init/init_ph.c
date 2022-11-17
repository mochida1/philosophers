/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ph.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:50:51 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/16 22:00:15 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int	sub_init_ph3(t_phil *ph, t_init *data)
{
	unsigned int	i;
	pthread_mutex_t	*geral_tmp;

	i = 0;
	geral_tmp = ft_calloc(sizeof (*geral_tmp), 1);
	pthread_mutex_init(geral_tmp, NULL);
	while (i < data->nop)
	{
		ph->geral = geral_tmp;
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

static int	init_mutex(pthread_mutex_t *mut, pthread_mutex_t *ct, t_init *data)
{
	unsigned int	i;
	unsigned int	rv;

	i = 0;
	rv = 0;
	while (i < data->nop)
	{
		if (pthread_mutex_init(&mut[i], NULL))
			rv = 1;
		if (pthread_mutex_init(&ct[i], NULL) && rv)
			rv += 2;
		if (rv)
			destroy_all_mutexes(mut, i);
		if (rv == 3)
			destroy_all_mutexes(ct, i);
		if (rv == 2 && i)
			destroy_all_mutexes(ct, i - 1);
		i++;
	}
	return (i);
}

static int	sub_init_ph1(t_phil *ph, t_init *data)
{
	unsigned int	i;
	pthread_mutex_t	*mut;
	pthread_mutex_t	*ct;
	long long		*to_eat;
	long long		*to_sleep;

	i = 0;
	mut = ft_calloc(data->nop, sizeof(*mut));
	ct = ft_calloc(data->nop, sizeof(*ct));
	init_mutex(mut, ct, data);
	to_eat = ft_calloc(data->nop, sizeof(long long int));
	to_sleep = ft_calloc(data->nop, sizeof(long long int));
	while (i < data->nop)
	{
		ph[i].philo = i;
		ph[i].fasted = i;
		ph[i].data = data;
		ph[i].mutex = mut;
		ph[i].ctrl = ct;
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
