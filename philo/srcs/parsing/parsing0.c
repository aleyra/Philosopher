/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:25:03 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/09 10:44:34 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parsing(int ac, char *av[], t_p *p)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		printf("%s\n", av[i]);
		i++;
	}
	(void)p;
	return (NO_ERROR);
}
