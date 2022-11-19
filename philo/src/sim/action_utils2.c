/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:38:17 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/19 17:47:17 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	check_if_stop(t_phil *ph, int *estad, int is_eat)
{
	pthread_mutex_lock(&ph->data->geral);
	if (ph->data->stop)
	{
		pthread_mutex_unlock(&ph->data->geral);
		if (is_eat)
			give_forks_back(ph);
		*estad = STOP_ST;
		return (0);
	}
	pthread_mutex_unlock(&ph->data->geral);
	return (1);
}
