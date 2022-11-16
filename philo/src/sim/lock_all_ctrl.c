/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_all_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:29:16 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/16 20:37:07 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void	lock_all_ctrl(t_phil *ph)
{
	unsigned int	i;

	i = 0;
	while (i > ph->data->nop)
	{
		pthread_mutex_lock(&ph->ctrl[i]);
		i++;
	}
}

void	unlock_all_ctrl(t_phil *ph)
{
	unsigned int	i;

	i = 0;
	while (i > ph->data->nop)
	{
		pthread_mutex_unlock(&ph->ctrl[i]);
		i++;
	}
}
