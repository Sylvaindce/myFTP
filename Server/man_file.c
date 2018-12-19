/*
** man_file.c for man_file in /home/decomb_s/Documents/TCPIP/Server
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@HP-EliteBook-decombs>
** 
** Started on  Sun Mar 15 14:37:10 2015 Sylvain DECOMBE
** Last update Sun Mar 22 19:07:22 2015 Sylvain DECOMBE
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "server.h"

char		*change_name(char *name)
{
  char		*new;

  new = xmalloc(strlen(name) + 4);
  strcpy(new, name);
  strcat(new, "(1)");
  return (new);
}

int		my_get(char *buff, int cs)
{
  char		*str;
  int		fd;

  write(1, buff, strlen(buff));
  if ((fd = open(buff, O_RDWR | O_CREAT, O_EXCL, S_IRWXU)) == -1)
    {
      str = change_name(buff);
      write(cs, "file exist\n", 11);
      write(1, "\n", 1);
      write(1, str, strlen(str));
      my_get(str, cs);
    }
  else
    write(cs, "file doesnt exist\n", 18);
  return (0);
}
