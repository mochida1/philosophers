/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:04:41 by hmochida          #+#    #+#             */
/*   Updated: 2022/10/26 19:36:56 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void	print_help(void)
{
	write (1, "\n\e[96m-------PHILOSOPHERS-------\n\e[92mUsage: ", 46);
	write (1, "\e[0m./philo [number_of_philosophers] ", 38);
	write (1, "[time_to_die time_to_eat] [time_to_sleep]", 42);
	write (1, " \e[90m[number_of_times_each_philosopher_must_eat]\n\n", 52);
	write (1, "\e[0mALL arguments take an \e[31m", 32);
	write (1, "INTEGER as miliseconds. \e[0m", 29);
	write (1, "Last argument is optional.\n", 28);
	write (1, "Have fun! :)\n\e[0m", 18);
	write (1, "\e[96m ------------------------ \e\n[0m", 37);
}

int	print_help_5(char *argv[])
{
	if (!ft_strcmp("number_of_times_each_philosopher_must_eat ", argv[2]) || \
		!ft_strcmp("[number_of_times_each_philosopher_must_eat]", argv[2]))
	{
		printf("\n\e[96m-------PHILOSOPHERS-------\e[0m\n");
		printf("\e[35m[number_of_times_each_philosopher_must_eat]\n\e[0m");
		printf("If all philosophers have eaten at least ");
		printf("number_of_times_each_philosopher_must_eat times, ");
		printf("the simulation stops. If not specified, the simulation ");
		printf("stops when a philosopher dies.\n");
		printf("\e[96m ------------------------ \e\n[0m");
		return (1);
	}
	return (0);
}

int	print_help_6(char *argv[])
{
	printf("\n\e[96m-------PHILOSOPHERS-------\e[0m\n");
	printf("%s %s: You must used a valid argument.\n", argv[0], argv[1]);
	printf("\e[91m%s\e[0m: invalid argument\n", argv[2]);
	printf("Try \e[32m[number_of_philosophers] [time_to_die] [time_to_eat] ");
	printf("[time_to_sleep] \e[33m");
	printf("[number_of_times_each_philosopher_must_eat]\e[0m\n");
	printf("\e[96m ------------------------ \e\n[0m");
	return (1);
}

