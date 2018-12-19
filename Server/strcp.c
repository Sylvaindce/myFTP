/*
** my_strcmp.c for myftp in /home/decomb_s/Documents/TCPIP
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@epitech.net>
** 
** Started on  Tue Mar 10 11:38:30 2015 Sylvain DECOMBE
** Last update Sun Mar 22 19:28:24 2015 Sylvain DECOMBE
*/

#include "server.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	res;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0'))
    i = i + 1;
  res = s1[i] - s2[i];
  return (res);
}

int             my_strncmp(char *str, char *str2, int nb)
{
  int   i;
  int   a;

  i = 0;
  a = 0;
  nb = nb - 1;
  while (i <= nb)
    {
      if (str[i] == str2[i])
        a++;
      else
        return (-1);
      i++;
    }
  if (a - 1 == nb)
    return (0);
  else
    return (-1);
}
