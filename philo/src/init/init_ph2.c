/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ph2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:51:52 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/06 11:53:49 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int	cpy_to_ph(t_phil *ph, t_init *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nop)
	{
		ph->num_eat[i] = data->endwhen;
		i++;
	}
	return (0);
}
