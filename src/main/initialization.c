/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:45:37 by hmochida          #+#    #+#             */
/*   Updated: 2022/11/04 21:30:46 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

static int	check_this_for_zeros(t_init *this, char	*argv[])
{
	if (!this->nop)
		return (printf("\e[91mNumber of philos must be greater than 0\e[0m\n"));
	if (!this->ttd)
		return (printf("\e[91mAre we genociding philosophers now?\e[0m\n"));
	if (argv[5] && this->endwhen == 0)
		return (printf("\e[92mInsta win? Ok... Simulation successful!\e[0m\n"));
	return (0);
}

static void	convert_args(t_init *this, char *argv[])
{

	this->nop = ft_atoi(argv[1]);
	this->ttd = ft_atoi(argv[2]);
	this->tte = ft_atoi(argv[3]);
	this->tts = ft_atoi(argv[4]);
	if (argv[5])
	{
		this->should_end = 1;
		this->endwhen = ft_atoi(argv[5]);
	}
}

t_init *init_data(char *argv[])
{
	t_init	*this;

	this = ft_calloc(1, (sizeof(*this)));
	convert_args(this, argv);
	if (check_this_for_zeros(this, argv))
			this = safe_free(this);
	return (this);
}