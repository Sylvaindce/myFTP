/*
** man_env.c for myftp in /home/decomb_s/Documents/TCPIP
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@epitech.net>
** 
** Started on  Tue Mar 10 11:19:17 2015 Sylvain DECOMBE
** Last update Sun Mar 22 19:06:15 2015 Sylvain DECOMBE
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#include "server.h"

void		affpath(char **path)
{
  int	y;

  y = 0;
  while (path[y] != NULL)
    {
      write(1, path[y], strlen(path[y]));
      write(1, "\n", 1);
      y++;
    }
}

int             check_env(char **env, t_env *ev)
{
  int		y;
  int		ck;

  y = 0;
  ck = 0;
  ev->envi = xmalloc(sizeof(char*) * 4096);
  ev->pwd = xmalloc(sizeof(char) * 4096);
  while (env[y] != NULL)
    {
      ev->envi[y] = xmalloc(sizeof(char) * 4096);
      if (my_strncmp(env[y], "PWD=", 4) == 0)
	{
	  strcpy(ev->pwd, env[y]);
	  ++ck;
	}
      strcpy(ev->envi[y], env[y]);
      y++;
    }
  if (ck == 0)
    return (-1);
  return (0);
}
