/*
** man_ls.c for man_ls in /home/decomb_s/Documents/TCPIP/Server
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@HP-EliteBook-decombs>
** 
** Started on  Thu Mar 12 11:22:20 2015 Sylvain DECOMBE
** Last update Sun Mar 22 19:26:25 2015 Sylvain DECOMBE
*/

#include <dirent.h>
#include "server.h"

int			my_ls(int fd)
{
  struct dirent		**folder;
  int			i;
  int			a;

  a = 0;
  if ((i = scandir(".", &folder, 0, alphasort)) < 0)
    write(2, "Error scandir\n", 14);
  else
    {
      while (a != i)
	{
	  write(fd, folder[a]->d_name, strlen(folder[a]->d_name));
	  write(fd, "\n", 1);
	  free(folder[a]);
	  ++a;
	}
      free(folder);
    }
  return (1);
}

