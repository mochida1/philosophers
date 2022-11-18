/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:31:00 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/17 21:39:54 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H
# define MS 1000
# define EAT_ST 0
# define SLEEP_ST 1
# define THINK_ST 2
# define STOP_ST 3

typedef struct s_init
{
	unsigned int	nop;
	int				ttd;
	int				tte;
	int				tts;
	volatile int	should_end;
	int				endwhen;
	int				stop;
	unsigned char	*is_delay;
	pthread_mutex_t	geral;
	pthread_t		*threads;
}	t_init;

typedef struct s_phil
{
	unsigned int	philo;
	int				fasted;
	t_init			*data;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*ctrl;
	char			*forks;
	unsigned int	own_fork;
	unsigned int	other_fork;
	long long		*timer_eat;
	long long		*timer_sleep;
	long long		*timer_die;
	int				*num_eat;
}	t_phil;

#endif // DEFS_H
