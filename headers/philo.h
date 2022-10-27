/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:31:38 by hmochida          #+#    #+#             */
/*   Updated: 2022/10/26 21:15:19 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
*/

# include <unistd.h> // write
# include <stdlib.h> // malloc, free
# include <stdio.h> // printf
# include <pthread.h> //pthread_*
# include <sys/time.h> // gettimeofday
# include "defs.h"
# include "../libft/libft.h"

# include "../src/TESTS/tests.h" // DELETAR ESSE CARA

t_init	*init_data(char *argv[]);

/* ARGS */
int		check_args(int argc, char *argv[]);
void	print_help_arg(char *argv[]);
void	print_help(void);
int		print_help_5(char *argv[]);
int		print_help_6(char *argv[]);

#endif // PHILO_H
