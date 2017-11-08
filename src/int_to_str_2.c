/*
** int_to_str_two.c for int_to_str in /home/dommer_c/rendu/int_to_str
** 
** Made by dommer_c
** Login   <dommer_c@epitech.net>
** 
** Started on  Sat Feb 13 17:51:21 2016 dommer_c
** Last update Sat Feb 13 17:53:12 2016 dommer_c
*/

#include "../inc/int_to_str.h"

int     search_diz(int tmp, int diz)
{
  while (tmp > 0)
    {
      tmp = tmp / 10;
      diz++;
    }
  return (diz);
}

int     search_div(int  diz, int div)
{
  int	n;

  n = 1;
  while (diz > 1)
    {
      div = 10 * n;
      diz--;
      n = n * 10;
    }
  return (div);
}

char	*nbr_eq_zero(int nb, char *nbr)
{
  if (nb == 0)
    {
      nbr = mem_nbr(1);
      nbr[0] = '0';
      nbr[1] = 0;
      return (nbr);
    }
  return (NULL);
}

char	*diz_eq_one(int nb, char *nbr, int diz)
{
  if (diz == 1)
    {
      nbr = mem_nbr(1);
      nbr[0] = (char)(nb + '0');
      nbr[1] = 0;
      return (nbr);
    }
  return (NULL);
}
