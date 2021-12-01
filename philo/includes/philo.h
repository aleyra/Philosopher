/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:51:25 by lburnet           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/30 16:30:42 by lburnet          ###   ########lyon.fr   */
=======
/*   Updated: 2021/11/30 20:11:30 by lucille          ###   ########.fr       */
>>>>>>> c7f22addb098499938fd6531071caaeaf67db52f
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

# define MY_INT_MIN -2147483648
# define MY_INT_MAX 2147483647
# define MY_LONG_MIN -9223372036854775808
# define MY_LONG_MAX 9223372036854775807

typedef struct s_suitcase	t_suitcase;
typedef struct s_philo		t_philo;
typedef enum e_error		t_error;

struct s_philo
{
	int					who;
	long				times_up;
	int					lfork;
	int					rfork;
	int					meal;
	t_suitcase			*sc;
	pthread_mutex_t		eat;
<<<<<<< HEAD
=======
	pthread_t			thread_id;
>>>>>>> c7f22addb098499938fd6531071caaeaf67db52f
};

struct s_suitcase
{
	int					nb_philo;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					nb_meal;
	long				start;
	int					ready;
	long				now;
	struct timeval		tv;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		game_paused;
	pthread_mutex_t		write;
	int					isdead;
	int					endgame;
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

//fct in display
void				error_message(int err);
void				print_philos(t_suitcase *p);
void				print_message(t_philo *philo, char *str);

//fct in mana_thread
void				take_forks(t_philo *philo);
void				eat(t_philo *philo);
void				give_forks(t_philo *philo);
void				sleep_then_think(t_philo *philo);
void				check_finished(t_suitcase *sc);
void				*routine(void *void_philo);

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
void				ft_putstr_fd(char *s, int fd);
int					ft_strlen(const char *str);
void				ft_usleep(int time, t_suitcase *sc);
#endif
