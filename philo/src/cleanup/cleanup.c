/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:57:35 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/19 20:59:20 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void	free_all_things(t_phil *ph)
{
	destroy_all_mutexes(ph->mutex, ph->data->nop - 1);
	destroy_all_mutexes(ph->ctrl, ph->data->nop - 1);
	ph->mutex = safe_free(ph->mutex);
	ph->ctrl = safe_free(ph->ctrl);
	ph->timer_eat = safe_free (ph->timer_eat);
	ph->timer_sleep = safe_free (ph->timer_sleep);
	ph->timer_die = safe_free (ph->timer_die);
	ph->forks = safe_free (ph->forks);
	ph->num_eat = safe_free (ph->num_eat);
	ph->data->is_delay = safe_free(ph->data->is_delay);
	ph->data = safe_free(ph->data);
	ph = safe_free(ph);
}

int	destroy_all_mutexes(pthread_mutex_t *mut, int tot_to_destroy)
{
	while (tot_to_destroy > 0)
	{
		pthread_mutex_destroy(&mut[tot_to_destroy]);
		tot_to_destroy--;
	}
	return (0);
}
