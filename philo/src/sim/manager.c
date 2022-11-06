/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:59:34 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/06 13:21:45 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int	check_eats(t_phil *ph)
{
	unsigned int	i;

	i = 0;
	while (i < ph->data->nop)
	{
		if (ph->num_eat[i] > 0)
			return (0);
		i++;
	}
	return (1);
}

static int	dead_checker(t_phil *ph, unsigned int i)
{
	if (ph->timer_die[i] < get_current_time(ph->data))
	{
		ph->data->stop = 1;
		printf("%lld\tphilo %u has died \n",
			get_current_time(ph->data), i + 1);
		return (1);
	}
	return (0);
}

static int	eat_checker(t_phil *ph)
{
	if (ph->data->should_end && check_eats(ph))
	{
		ph->data->stop = 1;
		printf("All philosophers have eaten at least %d times!\n",
			ph->data->endwhen);
		return (1);
	}
	return (0);
}

int	philo_manager(t_phil *ph)
{
	unsigned int	i;

	i = 0;
	ph->data->start = 1;
	ph->data->start_time = get_start_time();
	usleep (ph->data->ttd * MS);
	while (!ph->data->stop)
	{
		if (dead_checker(ph, i))
			break ;
		if (eat_checker(ph))
			break ;
		i++;
		if (i == ph->data->nop)
			i = 0;
		usleep(5 * MS);
	}
	return (0);
}
