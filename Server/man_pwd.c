/*
** man_pwd.c for man_pwd in /home/decomb_s/Documents/TCPIP/Server
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@HP-EliteBook-decombs>
** 
** Started on  Thu Mar 12 13:06:52 2015 Sylvain DECOMBE
** Last update Thu Mar 19 11:17:10 2015 Sylvain DECOMBE
*/

#include "server.h"

void			my_pwd(int fd, t_env *ev)
{
  char			pwd[1024];
  int			i;
  int			l;

  l = strlen(ev->pwd) - 4;
  if (getcwd(pwd, sizeof(pwd)) != NULL)
    {
      i = strlen(pwd);
      if (i == l)
	write(fd, "/", 1);
      else
	while (l != i)
	  {
	    write(fd, &pwd[l], 1);
	    ++l;
	  }
    }
  else
    write(fd, "getcwd() error", 14);
  write(fd, "\n", 1);
}
