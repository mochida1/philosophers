/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:31:00 by hmochida          #+#    #+#             */
/*   Updated: 2022/10/23 20:58:49 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

/*
** COLOURS **
COL_RESET		\e[0m
BLACK_FG		\e[30m
RED_FG			\e[31m
GREEN_FG		\e[32m
YELLOW_FG		\e[33m
BLUE_FG			\e[34m
MAGEN_FG		\e[35m
CYAN_FG			\e[36m
LI_GREY_FG		\e[37m
GREY_FG			\e[90m
LI_RED_FG		\e[91m
LI_GREEN_FG		\e[92m
LI_YELLOW_FG	\e[93m
LI_BLUE_FG		\e[94m
LI_MAGEN_FG		\e[95m
LI_CYAN_FG		\e[96m
WHITE_FG		\e[97m
*/

typedef struct s_phil
{
	unsigned int nop;
	unsigned int ttd;
	unsigned int tte;
	unsigned int tts;
	unsigned int endwhen;
} t_phil;

#endif // DEFS_H