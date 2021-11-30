/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:06:47 by lucille           #+#    #+#             */
/*   Updated: 2021/11/30 17:05:14 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->sc->forks[philo->rfork]);
	print_message(philo, "has taken a fork\n");
	// if (philo->rfork != philo->lfork)
	// {
		pthread_mutex_lock(&philo->sc->forks[philo->lfork]);
		print_message(philo, "has taken a fork\n");
	// }
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat);
	print_message(philo, "is eating\n");
	philo->times_up = philo->sc->now + philo->sc->t_to_die;
	ft_usleep(philo->sc->t_to_eat, philo->sc);
	philo->meal++;
	pthread_mutex_unlock(&philo->eat);

}

void	give_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->sc->forks[philo->rfork]);
	pthread_mutex_unlock(&philo->sc->forks[philo->lfork]);
}

void	sleep_then_think(t_philo *philo)
{
	print_message(philo, "is sleeping\n");
	ft_usleep(philo->sc->t_to_sleep, philo->sc);
	print_message(philo, "is thinking\n");
}
