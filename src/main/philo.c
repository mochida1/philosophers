/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:33:23 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/05 18:37:44 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

int destroy_all_mutexes(pthread_mutex_t *mut, int tot_to_destroy)
{
	while (tot_to_destroy < 0)
	{
		pthread_mutex_destroy(&mut[tot_to_destroy]);
		tot_to_destroy--;
	}
	return (0);
}

int	sub_init_ph3(t_phil *ph, t_init *data)
{
	unsigned int	i;
	char			*tmp_forks;

	i = 0;
	tmp_forks = ft_calloc(data->nop, sizeof(char));
	while (i < data->nop)
	{
		ph[i].forks = tmp_forks;
		ph[i].own_fork = ph[i].philo;
		if (ph[i].philo == ph[i].data->nop - 1)
			ph[i].other_fork = 0;
		else
			ph[i].other_fork = ph[i].philo + 1;
		i++;
	}
	return (0);
}

int	sub_init_ph2(t_phil *ph, t_init *data)
{
	unsigned int	i;
	long long		*to_die;
	int				*eats;

	i = 0;
	to_die = ft_calloc(data->nop, sizeof(long long int));
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

int init_mutex(pthread_mutex_t *mut, t_init *data)
{
	unsigned int	i = 0;
	while (i < data->nop)
	{
		if (pthread_mutex_init(&mut[i], NULL))
			return (destroy_all_mutexes(mut, i));
		i++;
	}
	return (i);
}

int	sub_init_ph1(t_phil *ph, t_init *data)
{
	unsigned int	i;
	pthread_mutex_t	*mut;
	long long				*to_eat;
	long long				*to_sleep;

	i = 0;
	mut = ft_calloc(data->nop, sizeof(*mut));
	init_mutex(mut, data);
	to_eat = ft_calloc(data->nop, sizeof(long long int));
	to_sleep = ft_calloc(data->nop, sizeof(long long int));
	while (i < data->nop)
	{
		ph[i].philo = i;
		ph[i].data = data;
		ph[i].mutex = mut;
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
	static unsigned int	start;
	if (!ph->philo % 2 && start < ph->data->nop / 2)
	{
		usleep(200);
		start++;
	}
	if (!ph->forks[ph->own_fork] && !ph->forks[ph->other_fork])
	{
		ph->forks[ph->own_fork] = 1;
		ph->forks[ph->other_fork] = 1;
		pthread_mutex_lock(&ph->mutex[ph->own_fork]);
		printf ("%lld\t%u has taken a fork\n", get_current_time(ph->data), ph->philo);
		pthread_mutex_lock(&ph->mutex[ph->other_fork]);
		printf ("%lld\t%u has taken a fork\n", get_current_time(ph->data), ph->philo);
	}
	return (0);
}

int	give_forks_back(t_phil *ph)
{
	pthread_mutex_unlock(&ph->mutex[ph->own_fork]);
	ph->forks[ph->own_fork] = 0;
	pthread_mutex_unlock(&ph->mutex[ph->other_fork]);
	ph->forks[ph->other_fork] = 0;
	printf ("%lld\t%u gives fork back\n", get_current_time(ph->data), ph->philo);
	// printf ("%lld\t%u gives fork back\n", get_current_time(ph->data), ph->philo);
	return (0);
}

void	*do_stuff(void *arg)
{
	t_phil	*ph = arg;
	int		estad;

	ph = arg;
	estad = 0;
	while (!ph->data->start)
		continue;
	ph->timer_die[ph->philo] = get_current_time(ph->data) + ph->data->ttd;
	while (1)
	{
		if (estad == 0)
		{
			printf("%lld\t%u is thiking;\n", get_current_time(ph->data), ph->philo);
			check_forks(ph);
			estad++;
		}

		if (estad == 1)
		{
			ph->timer_eat[ph->philo] = get_current_time(ph->data) + ph->data->tte;
			printf ("%lld\t%u is eating;\n", get_current_time(ph->data), ph->philo);
			while (get_current_time(ph->data) < ph->timer_eat[ph->philo])
			{
				usleep(MS);
				continue ;
			}
			give_forks_back(ph);
			ph->timer_die[ph->philo] = get_current_time(ph->data) + ph->data->ttd;
			estad = 2;
		}

		if (estad == 2)
		{
			ph->timer_sleep[ph->philo] = get_current_time(ph->data) + ph->data->tts;
			printf ("%lld\t%u is sleeping;\n", get_current_time(ph->data), ph->philo);
			while (get_current_time(ph->data) < ph->timer_sleep[ph->philo])
			{
				usleep(MS);
				continue ;
			}
			estad = 0;
		}
	}
	return (0);
}

long long	get_start_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec / MS) + (time.tv_sec * MS);
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
		if (ph->timer_die[i] < get_current_time(ph->data))
		{
			ph->data->stop = 1;
			printf("%lld\tphilo %u has died \n", get_current_time(ph->data), i);
			break;
		}
		if (ph->data->should_end && ph->num_eat[i] < 1)
		{
			ph->data->stop = 1;
			break;
		}
		i++;
		if (i == ph->data->nop)
			i = 0;
		usleep(MS);
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
	philo_manager(ph);
	return (1);
}

void PRINT_PHILOS(t_phil *ph)
{
	unsigned int i = 0;
	unsigned int j = 0;

	while (i < ph->data->nop)
	{
		printf ("ph[%u].philo:			%u\n", i, ph[i].philo);
		printf ("ph[%u].data:			%p\n", i, ph[i].data);
		printf ("ph[%u].mutex:			%p\n", i, ph[i].mutex);
		printf ("ph[%u].own_fork:			%u\n", i, ph[i].own_fork);
		printf ("ph[%u].other_fork:		%u\n", i, ph[i].other_fork);
		while (j < ph->data->nop)
		{
			printf ("ph[%u].timEat[%u]:		%lld\n", i, j, ph[i].timer_eat[j]);
			printf ("ph[%u].timSleep[%u]:		%lld\n", i, j, ph[i].timer_sleep[j]);
			printf ("ph[%u].timDie[%u]:		%lld\n", i, j, ph[i].timer_die[j]);
			if (ph->data->should_end)
				printf ("ph[%u].num_eat[%u]:		%d\n", i, j, ph[i].num_eat[j]);
			j++;
		}
		j = 0;
		i++;
	}
	exit (0);
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
// PRINT_DATA(data);
// PRINT_PHILOS(ph);
	if (philosophers(ph))
		return (1);
}
