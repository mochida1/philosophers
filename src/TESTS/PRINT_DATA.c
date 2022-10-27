/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PRINT_DATA.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:59:15 by hmochida          #+#    #+#             */
/*   Updated: 2022/10/26 21:15:19 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void	PRINT_DATA(t_init *data)
{
	printf("number of philosophers:\t%u\n", data->nop);
	printf("time to die:\t\t%u\n", data->ttd);
	printf("time to eat:\t\t%u\n", data->tte);
	printf("time to sleep:\t\t%u\n", data->tts);
	printf("should_end:\t\t%u\n", data->should_end);
	printf("end when:\t\t%u\n", data->endwhen);
}