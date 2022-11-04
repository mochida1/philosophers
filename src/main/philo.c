/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:33:23 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/03 21:53:09 by hmochida         ###   ########.fr       */
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

int	sub_init_ph3(t_phil *ph, t_init *data)
{
	char			*tmp_forks;
	int				*tmp_stop;
	unsigned int	i;

	tmp_forks = ft_calloc(data->nop, sizeof(char));
	tmp_stop = ft_calloc(1, sizeof(int));
	if (!tmp_forks)
		return (1);
	i = 0;
	while (i < data->nop)
	{
		ph[i].forks = tmp_forks;
		ph[i].stop = tmp_stop;
		i++;
	}
	return (0);
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
	if (sub_init_ph3(ph, data))
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

int	check_forks(t_phil *ph)
{
	unsigned int	other_fork;

	if (ph->philo == 0)
		other_fork = ph->data->nop;
	else if (ph->philo == ph->data->nop)
		other_fork = 0;
	else
		other_fork = ph->philo + 1;
	if (!ph->forks[ph->philo] && !ph->forks[other_fork])
	{
		pthread_mutex_lock(&ph->mutex[ph->philo]);
		ph->forks[ph->philo] = 1;
		printf ("%01.03f\t%u has taken a fork\n", ((float) get_current_time(ph->data)/MS), ph->philo);
		pthread_mutex_lock(&ph->mutex[other_fork]);
		ph->forks[other_fork] = 1;
		printf ("%01.03f\t%u has taken a fork\n", ((float) get_current_time(ph->data)/MS), ph->philo);
		return (0);
	}
	usleep(10);
	return (1);
}

int	give_forks_back(t_phil *ph)
{
	unsigned int	other_fork;

	if (ph->philo == 0)
		other_fork = ph->data->nop;
	else if (ph->philo == ph->data->nop)
		other_fork = 0;
	else
		other_fork = ph->philo + 1;
	ph->forks[ph->philo] = 0;
	ph->forks[other_fork] = 0;
	pthread_mutex_unlock(&ph->mutex[ph->philo]);
	printf ("%01.03f\t%u gives fork back\n", ((float) get_current_time(ph->data)/MS), ph->philo);
	pthread_mutex_unlock(&ph->mutex[other_fork]);
	printf ("%01.03f\t%u gives fork back\n", ((float) get_current_time(ph->data)/MS), ph->philo);
	return (0);
}

void	*do_stuff(void *arg)
{
	t_phil *ph = arg;

	ph->timer_die[ph->philo] = get_current_time(ph->data) + ph->data->ttd;
	while (1)
	{
		ph->timer_sleep[ph->philo] = get_current_time(ph->data) + ph->data->tts;
		printf ("%01.03f\t%u is sleeping\n", ((float) get_current_time(ph->data)/MS), ph->philo);
		while (get_current_time(ph->data) < ph->timer_sleep[ph->philo])
			continue ;

		printf ("%01.03f\t%u is thiking\n", ((float) get_current_time(ph->data)/MS), ph->philo);
		while (check_forks(ph))
			continue ;

		ph->timer_eat[ph->philo] = get_current_time(ph->data) + ph->data->tte;
		printf ("%01.03f\t%u is eating;\n", ((float) get_current_time(ph->data)/MS), ph->philo);
		while (get_current_time(ph->data) < ph->timer_eat[ph->philo])
			continue ;

		give_forks_back(ph);

		ph->timer_die[ph->philo] = get_current_time(ph->data) + ph->data->ttd;
	}
	return (0);
}

int	philo_manager(t_phil *ph)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		if (ph->timer_die[i] < get_current_time(ph->data))
		{
			*ph->stop = 1;
			break;
		}
		if (ph->data->should_end && ph->num_eat[i] < 1)
		{
			*ph->stop = 1;
			break;
		}
		i++;
		if (i > ph->data->nop)
			i = 0;
	}
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
	while (1)
		;
	// philo_manager(ph);
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
