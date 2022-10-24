/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:33:23 by hmochida          #+#    #+#             */
/*   Updated: 2022/10/23 21:34:58 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void	convert_args(t_phil *this, char *argv[])
{
	this->nop = ft_atoui(argv[1]);
	this->ttd = ft_atoui(argv[2]);
	this->tte = ft_atoui(argv[3]);
	this->tts = ft_atoui(argv[4]);
	if (argv[5])
		this->endwhen = ft_atoui(argv[5]);
print_data(this);
}

t_phil *init_data(char *argv[])
{
	t_phil	*this;

	this = ft_calloc(1, (sizeof(this)));
	convert_args(this, argv);
	return (this);
}

int	main(int argc, char *argv[])
{
	t_phil	*data;

	if (check_args(argc, argv))
		return (1);
	data = init_data(argv);
}
