/*
** open.c for minishell in /home/decomb_s/rendu/PSU-2013-minishell1
** 
** Made by Sylvain Decombe
** Login   <decomb_s@epitech.net>
** 
** Started on  Tue Apr  8 16:55:21 2014 Sylvain Decombe
** Last update Sun Mar 22 19:20:48 2015 Sylvain DECOMBE
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "server.h"

void		my_cd(char *buff, t_env *ev, int cs)
{
  char		**cd2;

  cd2 = cmdtocmd(buff);
  if (cd2[1] == NULL)
    puthome(ev->pwd, cs, ev);
  else if (cd2[1] != NULL)
    cmd_cd(cd2[1], cs, ev);
  else
    write(cs, "Put a correct directory\n", 24);
}

void		puthome(char *home, int cs, t_env *ev)
{
  unsigned int	i;
  int	a;
  char	*stock;

  stock = xmalloc(sizeof(char) * strlen(home));
  a = 0;
  i = 4;
  while (i != strlen(home))
    {
      stock[a] = home[i];
      i++;
      a++;
    }
  cmd_cd(stock, cs, ev);
}

void		cmd_cd(char *buff, int cs, t_env *ev)
{
  int		droit;
  int		dest;
  char		pwd[1024];
  char		*fol;

  fol = xmalloc(sizeof(pwd) + sizeof(buff));
  strcat(fol, ev->pwd + 4);
  strcat(fol, "/");
  strcat(fol, buff);
  if (getcwd(pwd, sizeof(pwd)) == NULL)
    write(1, "error getcwd\n", 6);
  if ((strcmp(pwd, ev->pwd + 4) == 0) && (strncmp("..", buff, 2) == 0))
    write(cs, "Access Denied, you must be root.\n", 33);
  else if (strncmp(fol, ev->pwd + 4, (strlen(ev->pwd) - 4)) != 0)
    write(cs, "Access Denied, you must be root.\n", 33);
  else if ((droit = (R_OK || W_OK || X_OK)) != 0)
    {
      dest = access(buff, droit);
      if (dest == 0)
	chdir(buff);
      else
	write(cs, "cd : No such file or directory.\n", 29);
    }
}
