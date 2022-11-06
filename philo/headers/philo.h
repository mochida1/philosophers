/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:31:38 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/06 14:54:42 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
*************************ALLOWED FUNCTIONS**************************************
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
********************************************************************************
*/

# include <unistd.h> // write
# include <stdlib.h> // malloc, free
# include <stdio.h> // printf
# include <pthread.h> //pthread_*
# include <sys/time.h> // gettimeofday
# include "defs.h"

t_init		*init_data(char *argv[]);

/* ARGS */
int			check_args(int argc, char *argv[]);
void		print_help_arg(char *argv[]);
void		print_help(void);
int			print_help_5(char *argv[]);
int			print_help_6(char *argv[]);
/* INIT */
int			cpy_to_ph(t_phil *ph, t_init *data);
int			init_ph(t_phil *ph, t_init *data);
/* CLEANUP */
void		free_all_things(t_phil *ph);
int			destroy_all_mutexes(pthread_mutex_t *mut, int tot_to_destroy);
/* SIM */
int			philo_manager(t_phil *ph);
long long	get_start_time(void);
void		wait_for_start(t_phil *ph);
long long	get_current_time(t_init *data);
void		*do_stuff(void *arg);
int			check_forks(t_phil *ph);
void		just_die(t_phil *ph);
/* UTILS */
void		*ft_calloc(size_t count, size_t size);
int			ft_strcmp(char *str1, char *str2);
void		*safe_free(void *this);
void		*ft_memset(void *b, int c, size_t len);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

#endif // PHILO_H
