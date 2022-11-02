/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:33:23 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/01 21:25:25 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int destroy_all_mutexes(t_phil *ph, int tot_to_destroy)
{
	while (tot_to_destroy < 0)
	{
		pthread_mutex_destroy(ph->mutex + tot_to_destroy);
		tot_to_destroy--;
	}
	return (1);
}

int	sub_init_ph2(t_phil *ph, t_init *data)
{
	unsigned int	i;
	int	*to_die;
	int	*eats;

	i = 0;
	to_die = ft_calloc(data->nop, sizeof(int));
	if (!to_die)
		return (1);
	if (data->endwhen)
	{
		eats = ft_calloc(data->nop, sizeof(int));
		if (!eats)
			return (1);
	}
	else
		eats = NULL;
	while (i < data->nop)
	{
		ph[i].timer_die = to_die;
		ph[i].num_eat = eats;
		i++;
	}
	return (0);
}

int	sub_init_ph1(t_phil *ph, t_init *data)
{
	unsigned int	i;
	pthread_mutex_t	*mut;
	int				*to_eat;
	int				*to_sleep;

	i = 0;
	mut = ft_calloc(data->nop, sizeof(*mut));
	to_eat = ft_calloc(data->nop, sizeof(int));
	to_sleep = ft_calloc(data->nop, sizeof(int));
	while (i < data->nop)
	{
		ph[i].philo = i + 1;
		ph[i].data = data;
		ph[i].mutex = mut;
		if (pthread_mutex_init(mut + i, NULL))
			return (destroy_all_mutexes(ph, i));
		ph[i].timer_eat = to_eat;
		ph[i].timer_sleep = to_sleep;
		i++;
	}
	return (0);
}

int cpy_to_ph(t_phil *ph, t_init *data)
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

int	init_ph(t_phil *ph, t_init *data)
{
	if (sub_init_ph1(ph, data))
		return (1);
	if (sub_init_ph2(ph, data))
		return (1);
	if (ph->num_eat)
		if (cpy_to_ph(ph, data))
			return (1);
	return (0);
}

long long	get_current_time(t_init *data)
{
	struct timeval	time;
	gettimeofday(&time, NULL);

	return ((time.tv_usec / MS + time.tv_sec * MS) - (data->start_time));
}

void	*do_stuff(void *arg)
{
	t_phil *ph = arg;
	// printf ("philo: [%d]\n", ph->philo);
	// while (1)
		printf ("philo [%u] time is: %01.03f \n", ph->philo, ((float) get_current_time(ph->data)/MS));
	
	ph->timer_sleep[ph->philo] = get_current_time(ph->data) + ph->data->tts;
	printf ("%01.03f\t\tphilo[%u] started sleeping;\n", ((float) get_current_time(ph->data)/MS), ph->philo);
	while (get_current_time(ph->data) < ph->timer_sleep[ph->philo])
		continue ;
	printf ("%01.03f\t\tphilo[%u] started thiking;\n", ((float) get_current_time(ph->data)/MS), ph->philo);
	return (0);
}

int	philosophers(t_phil *ph)
{
	unsigned int	i;
	pthread_t		*tid;

int ERR;
	tid = malloc (sizeof(pthread_t) * ph->data->nop);
	i = 0;
	while (i < ph->data->nop)
	{
		ERR = pthread_create(&tid[i], NULL, do_stuff, &ph[i]);
		if (ERR)
			printf ("ERROR: %d!\n", ERR);
			//dosomeerrorshit;
		i++;
	}
	sleep (1);
	// while (1)
	// 	continue ;
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
		return (1);
	
	
	

	// unsigned int i = 0;
	// while (i < data->nop)
	// {
	// 	printf ("p.philo: %d\n", ph[i].philo);
	// 	printf ("p.mut: %p\n", ph[i].mutex);
	// 	printf ("p.data: %p\n", ph[i].data);
	// 	printf ("p.timer_eat: %p\n", ph[i].timer_eat);
	// 	printf ("p.timer_sleep: %p\n", ph[i].timer_sleep);
	// 	printf ("p.timer_die: %p\n", ph[i].timer_die);
	// 	printf ("p.num_eat: %p\n", ph[i].num_eat);
	// 	if (ph[i].num_eat)
	// 		printf ("p.num_eatd: %d\n", ph[i].num_eat[0]);
	// 	i++;
	// }
}
