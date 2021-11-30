/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:19:35 by lucille           #+#    #+#             */
/*   Updated: 2021/11/30 17:13:41 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->sc->write);
	if (philo->sc->isdead == 1)
	{
		pthread_mutex_unlock(&philo->sc->write);
		return ;
	}
	ft_putnbr_fd(philo->sc->now - philo->sc->start, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(philo->who, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(str, 1);
	pthread_mutex_unlock(&philo->sc->write);
}
