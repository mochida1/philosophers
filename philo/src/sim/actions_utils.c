/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:08:05 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/19 16:38:41 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void	get_hungry(t_phil *ph)
{
	if (ph->data->nop % 2 && ph->fasted % ph->data->nop == 0)
	{
		while ((ph->timer_die[ph->philo] - get_current_time()
				> ph->data->ttd * 0.6) && !ph->data->stop)
			usleep(10);
		ph->fasted++;
	}
	else
		ph->fasted++;
}

static void	print_fork(t_phil *ph)
{
	if(check_stops(ph))
		return ;
pthread_mutex_lock(&ph->data->geral);
	printf ("%lld\t%u has taken a fork\n",
		get_current_time(), ph->philo + 1);
	printf ("%lld\t%u has taken a fork\n",
		get_current_time(), ph->philo + 1);
pthread_mutex_unlock(&ph->data->geral);
}

int	check_forks(t_phil *ph)
{
	if ((ph->philo % 2) && (!ph->data->is_delay[ph->philo]))
	{
		usleep(1 * MS);
		ph->data->is_delay[ph->philo]++;
	}
	if(check_stops(ph))
		return (0);
	pthread_mutex_lock(&ph->mutex[ph->own_fork]);
	// ph->forks[ph->own_fork] = 1;
	// if (ph->forks[ph->other_fork])
	// {
		// ph->forks[ph->own_fork] = 0;
	// 	pthread_mutex_unlock(&ph->mutex[ph->own_fork]);
	// 	return (1);
	// }
	pthread_mutex_lock(&ph->mutex[ph->other_fork]);
	// ph->forks[ph->other_fork] = 1;
	print_fork(ph);
	return (0);
}

int	just_die(t_phil *ph)
{
	printf("%lld\t%u is thiking;\n", get_current_time(), ph->philo + 1);
	while (!ph->data->stop)
		usleep(100);
	return (1);
}
