/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:38:17 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/19 19:01:17 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	check_if_dead(t_phil *ph, int *estad)
{
	pthread_mutex_lock(&ph->data->geral);
	if (ph->data->stop)
	{
		pthread_mutex_unlock(&ph->data->geral);
		*estad = STOP_ST;
		return (1);
	}
	pthread_mutex_unlock(&ph->data->geral);
	return (0);
}

int	eat_check_stop(t_phil *ph, int *estad)
{
	pthread_mutex_lock(&ph->data->geral);
	if (ph->data->stop)
	{
		pthread_mutex_unlock(&ph->data->geral);
		give_forks_back(ph);
		*estad = STOP_ST;
		return (1);
	}
	pthread_mutex_unlock(&ph->data->geral);
	return (0);
}

int	atomic_eat(t_phil *ph, int *estad)
{
	while (get_current_time() < ph->timer_eat[ph->philo])
	{
		pthread_mutex_lock(&ph->data->geral);
		if (ph->data->stop)
		{
			pthread_mutex_unlock(&ph->data->geral);
			give_forks_back(ph);
			*estad = STOP_ST;
			return (1);
		}
		pthread_mutex_unlock(&ph->data->geral);
		usleep(10);
		continue ;
	}
	return (0);
}
