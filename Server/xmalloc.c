/*
** xmalloc.c for myftp in /home/decomb_s/Documents/TCPIP
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@epitech.net>
** 
** Started on  Tue Mar 10 11:38:52 2015 Sylvain DECOMBE
** Last update Sun Mar 22 19:23:48 2015 Sylvain DECOMBE
*/

#include <stdlib.h>
#include "server.h"

void            *xmalloc(int size)
{
  void  *tmp;

  if ((tmp = malloc(size)) == NULL)
    {
      write(2, "Error Malloc failed\n", 20);
      exit(-1);
    }
  return (tmp);
}
