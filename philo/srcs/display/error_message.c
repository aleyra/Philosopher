/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:17:16 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/09 13:07:32 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_message(int err)
{
	if (err == WRONG_NB_ARG)
	{
		printf("Wrong number of arguments\nNeed 4 or 5 : ");
		printf("number_of_philosophers\ttime_to_die\ttime_to_eat\t");
		printf("time_to_sleep\t[number_of_times_each_philosopher_must_eat]\n");
	}
	if (err == ERROR_MALLOC)
		printf("Malloc failed\n");
	if (err == NOT_AN_INT)
		printf("argument is not an int\n");
	if (err == NOT_POS)
		printf("argument is inferior or equal to zero\n");
}
