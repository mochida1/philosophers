/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:59:34 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/19 18:06:51 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int	check_eats(t_phil *ph)
{
	unsigned int	i;

	i = 0;
	while (i < ph->data->nop)
	{
		pthread_mutex_lock(&ph->data->geral);
		if (ph->num_eat[i] > 0)
		{
			pthread_mutex_unlock(&ph->data->geral);
			return (0);
		}
		pthread_mutex_unlock(&ph->data->geral);
		i++;
	}
	return (1);
}

static int	dead_checker(t_phil *ph)
{
	unsigned int	i;

	i = 0;
	while (i < ph->data->nop)
	{
		pthread_mutex_lock(&ph->data->geral);
		if (ph->timer_die[i] < get_current_time())
		{
			ph->data->stop = 1;
			pthread_mutex_unlock(&ph->data->geral);
			printf("%lld\tphilo %u has died \n",
				get_current_time(), i + 1);
			return (1);
		}
		pthread_mutex_unlock(&ph->data->geral);
		i++;
	}
	return (0);
}

static int	eat_checker(t_phil *ph)
{
	if (ph->data->should_end && check_eats(ph))
	{
		pthread_mutex_lock(&ph->data->geral);
		ph->data->stop = 1;
		pthread_mutex_unlock(&ph->data->geral);
		usleep(MS);
		printf("All philosophers have eaten at least %d times!\n",
			ph->data->endwhen);
		return (1);
	}
	return (0);
}

int	philo_manager(t_phil *ph)
{
	unlock_all_ctrl(ph);
	usleep (ph->data->ttd * MS);
	while (!ph->data->stop)
	{
		if (dead_checker(ph))
			break ;
		if (eat_checker(ph))
			break ;
		usleep(100);
	}
	return (0);
}
