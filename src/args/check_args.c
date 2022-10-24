/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:07:08 by hmochida          #+#    #+#             */
/*   Updated: 2022/10/23 22:15:42 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

// Checks if argument value is too big to fit in here;
static int	is_too_big(char *argv)
{
	int count;
	unsigned long long big;

	count = 0;
	big = 0;
	while (argv[count])
	{
		big *= 10;
		big += argv[count] - 48;
		count++;
	}
	if (big > __UINT32_MAX__)
	{
		printf("\e[31mInvalid argument: %s is too big\e[0m\n", argv);
		return (1);
	}
	return (0);
}

// Checks wether the number of arguments is valid;
static int	check_arg_numbers(int argc)
{
	if (argc < 2)
	{
		write (2, "No arguments. Try -h or --help for help.\n", 41);
		return (1);
	}
	if (argc > 6)
	{
		write (2, "Too many arguments. Get --help or -h\n", 37);
		return (1);
	}
	return (0);
}

// Checks wether the user asked for help;
static int	check_for_help(int argc, char *argv[])
{
	if (!ft_strcmp("-h", argv[1]) || !ft_strcmp("--help", argv[1]))
	{
		if (argc > 3)
		{
			write (2, "Try -h or -h argument.\n", 23);
			return (1);
		}
		if (argc == 2)
		{
			print_help();
			return (1);
		}
		if (argc == 3)
		{
			print_help_arg(argv);
			return (1);
		}
	}
	return (0);
}

// Checks if the argument values are all valid integers;
static int	check_arg_values(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j++]))
			{
				printf("\e[31mInvalid argument format: %s\n", argv[i]);
				printf("\e[0mPlease use only positive integer numbers.\n");
				return (1);
			}
		}
		if (is_too_big(argv[i]))
			return (1);
		j = 0;
		i++;
	}
	return (0);
}

// Checks for anything the user might try to screw you with before stuff starts.
int	check_args(int argc, char *argv[])
{
	if (check_arg_numbers(argc))
		return (1);
	if (check_for_help(argc, argv))
		return (1);
	if (check_arg_values(argv))
		return (1);
	return (0);
}