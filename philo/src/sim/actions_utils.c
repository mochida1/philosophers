/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:08:05 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/06 17:10:53 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static void	print_fork(t_phil *ph)
{
	printf ("%lld\t%u has taken a fork\n",
		get_current_time(ph->data), ph->philo + 1);
}

int	check_forks(t_phil *ph)
{
	if ((ph->philo % 2) && (!ph->data->is_delay[ph->philo]))
	{
		usleep(1 * MS);
		ph->data->is_delay[ph->philo]++;
	}
	if (!ph->forks[ph->own_fork] && !ph->forks[ph->other_fork])
	{
		pthread_mutex_lock(&ph->mutex[ph->own_fork]);
		pthread_mutex_lock(&ph->mutex[ph->other_fork]);
		ph->forks[ph->own_fork] = 1;
		ph->forks[ph->other_fork] = 1;
		print_fork(ph);
		print_fork(ph);
	}
	return (0);
}

void	just_die(t_phil *ph)
{
	printf("%lld\t%u is thiking;\n", get_current_time(ph->data), ph->philo + 1);
	while (!ph->data->stop)
		usleep(1 * MS);
}
