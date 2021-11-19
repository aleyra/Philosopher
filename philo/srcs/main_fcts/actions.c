/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:06:47 by lucille           #+#    #+#             */
/*   Updated: 2021/11/19 15:50:07 by lucille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->sc->forks[philo->rfork]);
	what_message(philo, FORK_TAKEN);
	pthread_mutex_lock(&philo->sc->forks[philo->lfork]);
	what_message(philo, FORK_TAKEN);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->iseating = 1;
	philo->last_meal = ft_gettime(philo->sc);
	philo->times_up = philo->last_meal + philo->sc->t_to_die;
	what_message(philo, IS_EATING);
	usleep(philo->sc->t_to_eat * 1000);
	philo->meal++;
	philo->iseating = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->a_table);
}

void	give_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->sc->forks[philo->rfork]);
	pthread_mutex_unlock(&philo->sc->forks[philo->lfork]);
}

void	sleep_then_think(t_philo *philo)
{
	what_message(philo, IS_SLEEPING);
	usleep(philo->sc->t_to_sleep * 1000);
	what_message(philo, IS_THINKING);
}
