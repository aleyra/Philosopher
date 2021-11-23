/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:06:47 by lucille           #+#    #+#             */
/*   Updated: 2021/11/23 13:07:41 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	t_suitcase	*sc;

	sc = philo->sc;
	pthread_mutex_lock(&philo->sc->forks[philo->rfork]);
	pthread_mutex_lock(&philo->sc->forks[philo->lfork]);
	print_message(philo, "has taken forks\n");
}

void	eat(t_philo *philo)
{
	t_suitcase	*sc;

	pthread_mutex_lock(&philo->mutex);
	sc = philo->sc;
	philo->iseating = 1;
	print_message(philo, "is eating\n");
	philo->last_meal = sc->now;
	philo->times_up = philo->last_meal + philo->sc->t_to_die;
	ft_usleep(philo->sc->t_to_eat, sc);
	philo->meal++;
	philo->iseating = 0;
	pthread_mutex_unlock(&philo->mutex);

}

void	give_forks(t_philo *philo)
{
	t_suitcase	*sc;

	sc = philo->sc;
	pthread_mutex_unlock(&philo->sc->forks[philo->rfork]);
	pthread_mutex_unlock(&philo->sc->forks[philo->lfork]);
	print_message(philo, "has given forks\n");
}

void	sleep_then_think(t_philo *philo)
{
	t_suitcase	*sc;

	sc = philo->sc;
	print_message(philo, "is sleeping\n");
	ft_usleep(philo->sc->t_to_sleep, sc);
	print_message(philo, "is thinking\n");
}
