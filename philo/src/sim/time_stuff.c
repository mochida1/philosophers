/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:02:55 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/16 20:39:35 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

long long	get_start_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / MS) + (time.tv_sec * MS));
}

long long	get_current_time(t_init *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / MS + time.tv_sec * MS) - (data->start_time));
}

void	wait_for_start(t_phil *ph)
{
	pthread_mutex_lock(&ph->ctrl[ph->philo]);
	pthread_mutex_unlock(&ph->ctrl[ph->philo]);
	if (ph->data->nop % 2)
		return ;
	else
		usleep(20);
}
