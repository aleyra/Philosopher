/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:06:47 by lucille           #+#    #+#             */
/*   Updated: 2021/11/22 13:34:05 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	t_suitcase	*sc;

	sc = philo->sc;
	// pthread_mutex_lock(&sc->game_paused);
	pthread_mutex_lock(&philo->sc->forks[philo->rfork]);
	printf("%ld: philo nb %d has taken a fork\n",
		sc->now - sc->start, philo->who);
	pthread_mutex_lock(&philo->sc->forks[philo->lfork]);
	printf("%ld: philo nb %d has taken another fork\n",
		sc->now - sc->start, philo->who);
	// pthread_mutex_unlock(&sc->game_paused);
}

void	eat(t_philo *philo)
{
	t_suitcase	*sc;

	sc = philo->sc;
	// pthread_mutex_lock(&sc->game_paused);
	philo->iseating = 1;
	printf("%ld: philo nb %d is eating\n",
		sc->now - sc->start, philo->who);
	philo->last_meal = sc->now;
	philo->times_up = philo->last_meal + philo->sc->t_to_die;
	ft_usleep(philo->sc->t_to_eat, sc);
	philo->meal++;
	philo->iseating = 0;
	// pthread_mutex_unlock(&sc->game_paused);
}

void	give_forks(t_philo *philo)
{
	t_suitcase	*sc;

	sc = philo->sc;
	// pthread_mutex_lock(&sc->game_paused);
	pthread_mutex_unlock(&philo->sc->forks[philo->rfork]);
	pthread_mutex_unlock(&philo->sc->forks[philo->lfork]);
	printf("%ld: philo nb %d has given forks\n",
		sc->now - sc->start, philo->who);
	// pthread_mutex_unlock(&sc->game_paused);
}

void	sleep_then_think(t_philo *philo)
{
	t_suitcase	*sc;

	sc = philo->sc;
	// pthread_mutex_lock(&sc->game_paused);
	printf("%ld: philo nb %d is sleeping\n",
		sc->now - sc->start, philo->who);
	// pthread_mutex_unlock(&sc->game_paused);
	// pthread_mutex_lock(&sc->game_paused);
	ft_usleep(philo->sc->t_to_sleep, sc);
	printf("%ld: philo nb %d is thinking\n",
		sc->now - sc->start, philo->who);
	// pthread_mutex_unlock(&sc->game_paused);
}
