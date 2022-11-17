/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:05:18 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/16 21:21:14 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int	give_forks_back(t_phil *ph)
{
	if (ph->data->should_end)
		ph->num_eat[ph->philo]--;
	pthread_mutex_unlock(&ph->mutex[ph->own_fork]);
	pthread_mutex_unlock(&ph->mutex[ph->other_fork]);
	return (0);
}

static void	do_think(t_phil *ph, int *estad)
{
	get_hungry(ph);
	if (ph->data->stop)
	{
		*estad = STOP_ST;
		return ;
	}
	printf("%lld\t%u is thiking\n", get_current_time(), ph->philo + 1);
	check_forks(ph);
	if (ph->data->stop)
	{
		*estad = STOP_ST;
		return ;
	}
	*estad = EAT_ST;
}

static void	do_eat(t_phil *ph, int *estad)
{
	ph->timer_eat[ph->philo] = get_current_time() + ph->data->tte;
	if (ph->data->stop)
	{
		*estad = STOP_ST;
		return ;
	}
	printf ("%lld\t%u is eating\n", get_current_time(), ph->philo + 1);
	while (get_current_time() < ph->timer_eat[ph->philo])
	{
		usleep(10);
		continue ;
	}
	if (ph->data->stop)
	{
		give_forks_back(ph);
		*estad = STOP_ST;
		return ;
	}
	give_forks_back(ph);
	ph->timer_die[ph->philo] = get_current_time() + ph->data->ttd;
	*estad = SLEEP_ST;
}

static void	do_sleep(t_phil *ph, int *estad)
{
	ph->timer_sleep[ph->philo] = get_current_time() + ph->data->tts;
	if (ph->data->stop)
	{
		*estad = STOP_ST;
		return ;
	}
	printf("%lld\t%u is sleeping\n", get_current_time(), ph->philo + 1);
	while (get_current_time() < ph->timer_sleep[ph->philo])
	{
		if (ph->data->stop)
		{
			*estad = STOP_ST;
			return ;
		}
		usleep(10);
	}
	*estad = THINK_ST;
}

void	*do_stuff(void *arg)
{
	t_phil	*ph;
	int		estad;

	ph = arg;
	estad = THINK_ST;
	wait_for_start(ph);
	ph->timer_die[ph->philo] = get_current_time() + ph->data->ttd;
	if (ph->data->nop == 1)
		estad = STOP_ST;
	while (1)
	{
		pthread_mutex_lock(&ph->ctrl[ph->philo]);
		pthread_mutex_unlock(&ph->ctrl[ph->philo]);
		if (estad == EAT_ST)
			do_eat(ph, &estad);
		if (estad == SLEEP_ST)
			do_sleep(ph, &estad);
		if (estad == THINK_ST)
			do_think(ph, &estad);
		if (estad == STOP_ST)
			return (NULL);
	}
	return (NULL);
}
