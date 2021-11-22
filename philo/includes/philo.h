/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:51:25 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/22 13:45:01 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "pthread.h"
# include "string.h"
# include "unistd.h"
# include "stdlib.h"
# include "sys/time.h"

typedef struct s_suitcase	t_suitcase;
typedef struct s_philo		t_philo;
typedef enum e_error		t_error;
typedef enum e_what			t_what;

struct s_philo
{
	int					who;
	int					iseating;
	long				times_up;
	long				last_meal;
	int					lfork;
	int					rfork;
	int					meal;
	t_suitcase			*sc;
	pthread_mutex_t		mutex;
};

struct s_suitcase
{
	int					nb_philo;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					nb_meal;
	long				start;
	long				now;
	struct timeval		tv;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		game_paused;
	pthread_mutex_t		write;
	int					isdead;
	int					gameover;
};

enum e_error
{
	NO_ERROR,
	WRONG_NB_ARG,
	ERROR_MALLOC,
	NOT_AN_INT,
	NOT_POS,
	ERROR_PTHREAD_C,
	FORBIDDEN,
};

enum e_what
{
	FORK_TAKEN,
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	IS_DIED,
	FINISHED_SUCCESS
};

//fct in display
void				error_message(int err);
void				print_philos(t_suitcase *p);
void				what_message(t_philo *philo, int what);
void				print(t_philo *philo, char *str);

//fct in mana_thread
void				take_forks(t_philo *philo);
void				eat(t_philo *philo);
void				give_forks(t_philo *philo);
void				sleep_then_think(t_philo *philo);
void				check_finished(t_suitcase *sc);
int					start_meeting(t_suitcase *sc);

//fct in parsing
int					ft_parsing(int ac, char *av[], t_suitcase *p);

//fct in tools
int					can_atoi(const char *str);
int					ft_atoi(const char *str);
void				free_destroy_all(t_suitcase *sc);
int					ft_exit(t_suitcase *sc, int err);
long				ft_gettime(t_suitcase *sc);
int					ft_isdigit(int c);
void				ft_putnbr_fd(int n, int fd);
int					ft_strlen(const char *str);
void				ft_usleep(int time, t_suitcase *sc);
#endif
