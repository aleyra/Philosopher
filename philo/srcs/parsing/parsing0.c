/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:25:03 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/16 14:28:07 by lucille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	assign_int(int *to_be_assign, char *str)
{
	*to_be_assign = ft_atoi(str);
	if (*to_be_assign <= 0)
		return (NOT_POS);
	return (NO_ERROR);
}

int	ft_parsing(int ac, char *av[], t_suitcase *sc)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (can_atoi(av[i]) == 1)
			return (NOT_AN_INT);
		if (i == 1 && assign_int(&sc->nb_philo, av[i]) != NO_ERROR)
			return (NOT_POS);
		else if (i == 2 && assign_int(&sc->t_to_die, av[i]) != NO_ERROR)
			return (NOT_POS);
		else if (i == 3 && assign_int(&sc->t_to_eat, av[i]) != NO_ERROR)
			return (NOT_POS);
		else if (i == 4 && assign_int(&sc->t_to_sleep, av[i]) != NO_ERROR)
			return (NOT_POS);
		else if (i == 5 && assign_int(&sc->nb_meal, av[i]) != NO_ERROR)
			return (NOT_POS);
		i++;
	}
	return (NO_ERROR);
}
