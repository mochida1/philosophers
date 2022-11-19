/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:33:23 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/19 16:37:42 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void	unlock_all(t_phil *ph)
{
	unsigned int	i;

	i = 0;
	while (i < ph->data->nop)
	{
		pthread_mutex_unlock(&ph->mutex[i]);
		pthread_mutex_unlock(&ph->ctrl[i]);
		i++;
	}
	pthread_mutex_unlock(&ph->data->geral);
}

void	lock_all(t_phil *ph)
{
	unsigned int	i;

	i = 0;
	while (i < ph->data->nop)
	{
		pthread_mutex_lock(&ph->mutex[i]);
		pthread_mutex_lock(&ph->ctrl[i]);
		i++;
	}
	pthread_mutex_lock(&ph->data->geral);
}

static int	philosophers(t_phil *ph)
{
	unsigned int	i;
	pthread_t		*tid;
	int				rc;

	tid = malloc (sizeof(pthread_t) * ph->data->nop);
	i = 0;
	rc = 0;
	while (i < ph->data->nop)
	{
		rc = pthread_create(&tid[i], NULL, do_stuff, &ph[i]);
		if (rc)
		{
			printf ("ERROR: %d!\n", rc);
			return (0);
		}
		i++;
	}
	philo_manager(ph);
	i = 0;
	lock_all(ph);
	usleep (10 * MS);
	unlock_all(ph);
	while (i < ph->data->nop)
		pthread_join(tid[i++], NULL);
	tid = safe_free(tid);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_init	*data;
	t_phil	*ph;

	if (check_args(argc, argv))
		return (1);
	data = init_data(argv);
	if (!data)
		return (1);
	ph = ft_calloc(data->nop, sizeof(t_phil));
	if (init_ph(ph, data))
		return (1);
	if (philosophers(ph))
	{
		free_all_things(ph);
		return (0);
	}
}
