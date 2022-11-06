/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:05:18 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/06 13:25:40 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int	give_forks_back(t_phil *ph)
{
	if (ph->data->should_end)
		ph->num_eat[ph->philo]--;
	pthread_mutex_unlock(&ph->mutex[ph->own_fork]);
	ph->forks[ph->own_fork] = 0;
	pthread_mutex_unlock(&ph->mutex[ph->other_fork]);
	ph->forks[ph->other_fork] = 0;
	return (0);
}

static void	do_think(t_phil *ph, int *estad)
{
	if (ph->data->stop)
	{
		*estad = 3;
		return ;
	}
	printf("%lld\t%u is thiking;\n", get_current_time(ph->data), ph->philo + 1);
	check_forks(ph);
	*estad = *estad + 1;
}

static void	do_eat(t_phil *ph, int *estad)
{
	ph->timer_eat[ph->philo] = get_current_time(ph->data) + ph->data->tte;
	if (ph->data->stop)
	{
		*estad = 3;
		return ;
	}
	printf ("%lld\t%u is eating\n", get_current_time(ph->data), ph->philo + 1);
	while (get_current_time(ph->data) < ph->timer_eat[ph->philo])
	{
		usleep(0.5 * MS);
		continue ;
	}
	if (ph->data->stop)
	{
		*estad = 3;
		return ;
	}
	give_forks_back(ph);
	ph->timer_die[ph->philo] = get_current_time(ph->data) + ph->data->ttd;
	*estad = 2;
}

static void	do_sleep(t_phil *ph, int *estad)
{
	ph->timer_sleep[ph->philo] = get_current_time(ph->data) + ph->data->tts;
	if (ph->data->stop)
	{
		*estad = 3;
		return ;
	}
	printf("%lld\t%u is sleeping\n", get_current_time(ph->data), ph->philo + 1);
	while (get_current_time(ph->data) < ph->timer_sleep[ph->philo])
	{
		if (ph->data->stop)
		{
			*estad = 3;
			return ;
		}
		usleep(0.5 * MS);
	}
	*estad = 0;
}

void	*do_stuff(void *arg)
{
	t_phil	*ph;
	int		estad;

	ph = arg;
	estad = 0;
	wait_for_start(ph);
	ph->timer_die[ph->philo] = get_current_time(ph->data) + ph->data->ttd;
	while (1)
	{
		if (estad == 0)
			do_think(ph, &estad);
		if (estad == 1)
			do_eat(ph, &estad);
		if (estad == 2)
			do_sleep(ph, &estad);
		if (estad == 3)
			return (NULL);
	}
	return (NULL);
}
