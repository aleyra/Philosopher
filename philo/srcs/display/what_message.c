/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:19:35 by lucille           #+#    #+#             */
/*   Updated: 2021/11/22 13:41:20 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	in_else(t_philo *philo, int what, t_suitcase *sc)
{
	printf("%llu: philo nb %d is ",
		ft_gettime(sc) - sc->start, philo->who);
	if (what == FORK_TAKEN)
		printf("has taken a fork\n");
	else if (what == IS_EATING)
		printf("is eating\n");
	else if (what == IS_SLEEPING)
		printf("is sleeping\n");
	else if (what == IS_THINKING)
		printf("is thinking\n");
	else if (what == IS_DIED)
		printf("died\n");
}

void	what_message(t_philo *philo, int what)
{
	t_suitcase	*sc;

	sc = philo->sc;
	pthread_mutex_lock(&sc->game_paused);
	if (sc->gameover != 0)
	{
		if (what == FINISHED_SUCCESS)
			printf("All philosophers ate at least %d meal(s)\n",
				philo->sc->nb_meal);
		else
			in_else(philo, what, sc);
		if (what == IS_DIED || what == FINISHED_SUCCESS)
			sc->gameover = 1;
	}
	pthread_mutex_unlock(&sc->game_paused);
}

void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->sc->write);
	if (philo->sc->isdead == 1)
	{
		pthread_mutex_unlock(&philo->sc->write);
		return ;
	}
	ft_putnbr_fd(philo->sc->now - philo->sc->start, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->who, 1);
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&philo->sc->write);
}
	