/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:31:00 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/05 21:24:27 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H
# define MS 1000

typedef struct s_init
{
	unsigned int	nop;
	int				ttd;
	int				tte;
	int				tts;
	volatile int	should_end;
	int				endwhen;
	long long		start_time;
	volatile int	start;
	int				stop;
	pthread_t		*threads;
}	t_init;

typedef struct s_phil
{
	unsigned int	philo;
	t_init			*data;
	pthread_mutex_t	*mutex;
	char			*forks;
	unsigned int	own_fork;
	unsigned int	other_fork;
	long long		*timer_eat;
	long long		*timer_sleep;
	long long		*timer_die;
	int				*num_eat;
}	t_phil;

#endif // DEFS_H