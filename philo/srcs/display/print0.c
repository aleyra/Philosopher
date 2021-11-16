/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:11:08 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/16 14:28:19 by lucille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philos(t_suitcase *sc)
{
	printf("nb_philo = %d\n", sc->nb_philo);
	printf("t_to_die = %d\n", sc->t_to_die);
	printf("t_to_eat = %d\n", sc->t_to_eat);
	printf("t_to_sleep = %d\n", sc->t_to_sleep);
	printf("nb_meal = %d\n", sc->nb_meal);
}
