/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:58:55 by hmochida          #+#    #+#             */
/*   Updated: 2022/10/26 21:54:55 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"


static int	print_help_4(char *argv[])
{
	if (!ft_strcmp("time_to_sleep ", argv[2]) || \
		!ft_strcmp("[time_to_sleep]", argv[2]))
	{
		printf("\n\e[96m-------PHILOSOPHERS-------\e[0m\n");
		printf("\e[35m[time_to_sleep ]\n\e[0m");
		printf("The time a philosopher will spend sleeping.\n");
		printf("\e[96m ------------------------ \e\n[0m");
		return (1);
	}
	return (0);
}

static int	print_help_3(char *argv[])
{
	if (!ft_strcmp("time_to_eat", argv[2]) || \
		!ft_strcmp("[time_to_eat]", argv[2]))
	{
		printf("\n\e[96m-------PHILOSOPHERS-------\e[0m\n");
		printf("\e[35m[time_to_eat]\n\e[0m");
		printf("The time it takes for a philosopher to eat. ");
		printf("During that time, they will need to hold two forks.\n");
		printf("\e[96m ------------------------ \e\n[0m");
		return (1);
	}
	return (0);
}

static int	print_help_2(char *argv[])
{
	if (!ft_strcmp("time_to_die", argv[2]) || \
		!ft_strcmp("[time_to_die]", argv[2]))
	{
		printf("\n\e[96m-------PHILOSOPHERS-------\e[0m\n");
		printf("\e[35m[time_to_die]\n\e[0m");
		printf("If a philosopher didn't start eating time_to_die \n");
		printf("milliseconds since the beginning of their last meal or the \n");
		printf("beginning of the simulation, they die.\n");
		printf("\e[96m ------------------------ \e\n[0m");
		return (1);
	}
	return (0);
}

static int	print_help_1(char *argv[])
{
	if (!ft_strcmp("number_of_philosophers", argv[2]) || \
		!ft_strcmp("[number_of_philosophers]", argv[2]))
	{
		printf("\n\e[96m-------PHILOSOPHERS-------\e[0m\n");
		printf("\e[35m[number_of_philosophers]\n\e[0m");
		printf("The number of philosophers and also the number of forks.\n");
		printf("\e[96m ------------------------ \e\n[0m");
		return (1);
	}
	return (0);
}

// wrapper to print all the helps
void	print_help_arg(char *argv[])
{
	int	rc;
	
	rc = 0;
	rc += print_help_1(argv);
	rc += print_help_2(argv);
	rc += print_help_3(argv);
	rc += print_help_4(argv);
	rc += print_help_5(argv);
	if (!rc)
		print_help_6(argv);
}