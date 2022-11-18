/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:39:16 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/17 20:30:59 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	check_stops(t_phil *ph)
{
	pthread_mutex_lock(&ph->data->geral);
	if (ph->data->stop)
	{
		pthread_mutex_unlock(&ph->data->geral);
		return (1);
	}
	pthread_mutex_unlock(&ph->data->geral);
	return (0);
}
