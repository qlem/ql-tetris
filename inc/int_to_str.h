/*
** int_to_str.h for int_to_str in /home/dommer_c/rendu/int_to_str
** 
** Made by dommer_c
** Login   <dommer_c@epitech.net>
** 
** Started on  Sat Feb 13 17:51:58 2016 dommer_c
** Last update Sat Feb 13 17:52:01 2016 dommer_c
*/

#ifndef INT_TO_STR_H_
#define INT_TO_STR_H_

#include <stdlib.h>

char	*mem_nbr(int n);
char	*put_on_nbr(int nb, int diz, int div, char *nbr);
char	*int_to_str(int nb);
int	    search_diz(int tmp, int diz);
int	    search_div(int  diz, int div);
char	*nbr_eq_zero(int nb, char *nbr);
char	*diz_eq_one(int nb, char *nbr, int diz);

#endif /* !INT_TO_STR_H_ */
