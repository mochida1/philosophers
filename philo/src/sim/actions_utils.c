/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:08:05 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/06 16:16:36 by hmochida         ###   ########.fr       */
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
	static unsigned int	start;

	if (!ph->philo % 2 && start < ph->data->nop / 2)
	{
		usleep(2 * MS);
		start++;
	}
	if (!ph->forks[ph->own_fork] && !ph->forks[ph->other_fork])
	{
		ph->forks[ph->own_fork] = 1;
		ph->forks[ph->other_fork] = 1;
		pthread_mutex_lock(&ph->mutex[ph->own_fork]);
		print_fork(ph);
		pthread_mutex_lock(&ph->mutex[ph->other_fork]);
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
