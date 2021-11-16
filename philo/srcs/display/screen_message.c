/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:19:35 by lucille           #+#    #+#             */
/*   Updated: 2021/11/16 16:48:42 by lucille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	screen_message(t_philo *philo, int what)
{
	t_suitcase	*sc;

	sc = philo->sc;
	pthread_mutex_lock(&sc->game_paused);
	if (sc->gameover != 0)
	{
		printf("%llu: philo nb %d is ", ft_gettime(sc) - sc->start, philo->who);
		if (what == FORK_TAKEN)
			printf("has taken a fork\n");
		else if (what == IS_EATING)
			printf("is eating\n");
		else if (what == IS_SLEEPING)
			printf("is sleeping\n");
		else if (what == IS_THINKING)
			printf("is thinking\n");
		else if (what == FINISHED_SUCCESS)
			printf("ate all his meal(s)\n");
		else if (what == IS_DIED)
			printf("died\n");
		if (what == IS_DIED || what == FINISHED_SUCCESS)
			sc->gameover = 1;
	}
	pthread_mutex_unlock(&sc->game_paused);
}
