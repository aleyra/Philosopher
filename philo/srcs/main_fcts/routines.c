/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:00:35 by lucille           #+#    #+#             */
/*   Updated: 2021/11/19 16:03:03 by lucille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*count_meal(void *void_sc)
{
	t_suitcase	*sc;
	int			i;

	sc = (t_suitcase *)void_sc;
	while (sc->nb_meal-- > 0)
	{
		i = 0;
		while (i < sc->nb_philo)
		{
			pthread_mutex_lock(&sc->philos[i].a_table);
			i++;
		}
	}
	what_message(&sc->philos[0], FINISHED_SUCCESS);
	pthread_mutex_unlock(&sc->isdead);
	return (NULL);
}

static void	*check_is_dead(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (philo->iseating == 0 && ft_gettime(philo->sc) > philo->times_up)
		{
			what_message(philo, IS_DIED);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&philo->sc->isdead);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
	return (NULL);
}

static void	*routine(void *void_philo)
{
	t_philo		*philo;
	pthread_t	new;
	int			thread_created;

	philo = (t_philo *)void_philo;
	philo->last_meal = ft_gettime(philo->sc);
	philo->times_up = philo->last_meal + philo->sc->t_to_die;
	thread_created = pthread_create(&new, NULL, &check_is_dead, void_philo);
	if (thread_created != 0)
		return (NULL);
	pthread_detach(new);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		give_forks(philo);
		sleep_then_think(philo);
	}
	return (NULL);
}

int	start_meeting(t_suitcase *sc)
{
	int			thread_created;
	pthread_t	new;
	int			i;

	sc->start = ft_gettime(sc);
	if (sc->nb_meal > 0)
	{
		thread_created = pthread_create(
				&new, NULL, &count_meal, (void *)sc);
		if (thread_created != 0)
			return (ERROR_PTHREAD_C);
		pthread_detach(new);
	}
	i = 0;
	while (i < sc->nb_philo)
	{
		thread_created = pthread_create(
				&new, NULL, &routine, (void *)&sc->philos[i]);
		if (thread_created != 0)
			return (ERROR_PTHREAD_C);
		pthread_detach(new);
		usleep(100);
		i++;
	}
	return (NO_ERROR);
}
