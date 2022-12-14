/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:02:55 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/16 21:16:35 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

long long	get_current_time(void)
{
	static size_t	initial_time;
	struct timeval	tv;
	size_t			time;

	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	if (!initial_time)
		initial_time = time;
	return (time - initial_time);
}

void	wait_for_start(t_phil *ph)
{
	pthread_mutex_lock(&ph->ctrl[ph->philo]);
	pthread_mutex_unlock(&ph->ctrl[ph->philo]);
	if (ph->data->nop % 2)
		return ;
	else
		usleep(500);
}
