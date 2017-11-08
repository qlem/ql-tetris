/*
** int_to_str_one.c for int_to_str in /home/dommer_c/rendu/int_to_str
** 
** Made by dommer_c
** Login   <dommer_c@epitech.net>
** 
** Started on  Sat Feb 13 17:50:49 2016 dommer_c
** Last update Sat Feb 13 17:52:43 2016 dommer_c
*/

#include "../inc/int_to_str.h"

char	*mem_nbr(int n)
{
  char	*nbr;
  if ((nbr = malloc(sizeof(char) * n + 1)) == NULL)
    return (NULL);
  return (nbr);
}

char	*put_on_nbr(int nb, int diz, int div, char *nbr)
{
  int	i;
  int	tmp;

  i = 0;
  nbr = mem_nbr(diz);
  while (div > 0)
    {
      tmp = nb / div;
      tmp = tmp % 10;
      div = div / 10;
      nbr[i] = (char)(tmp + '0');
      i++;
    }
  nbr[i] = 0;
  return (nbr);
}

char	*int_to_str(int nb)
{
  int	tmp;
  int	diz;
  int	div;
  char	*nbr;

  tmp = nb;
  diz = 0;
  div = 0;
  nbr = NULL;
  if ((nbr = nbr_eq_zero(nb, nbr)) != NULL)
    return (nbr);
  diz = search_diz(tmp, diz);
  if ((nbr = diz_eq_one(nb, nbr, diz)) != NULL)
    return (nbr);
  div = search_div(diz, div);
  nbr = put_on_nbr(nb, diz, div, nbr);
  return (nbr);
}
