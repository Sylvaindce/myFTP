/*
** man_cd.c for myftp in /home/decomb_s/Documents/TCPIP/Server
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@epitech.net>
** 
** Started on  Wed Mar 11 17:01:02 2015 Sylvain DECOMBE
** Last update Wed Mar 11 17:01:52 2015 Sylvain DECOMBE
*/

#include "server.h"

char		**cmdtocmd(char *cmd)
{
  char	**cmd2;
  int	x;
  int	y;
  int	i;

  y = 0;
  i = 0;
  cmd2 = xmalloc(sizeof(char *) * 4096);
  while (cmd[i] != '\0')
    {
      x = 0;
      cmd2[y] = xmalloc(sizeof(char) * 4096);
      while (cmd[i] != ' ' && cmd[i] != '\0' && cmd[i] != '\n')
	  cmd2[y][x++] = cmd[i++];
      cmd2[y++][x] = '\0';
      if (cmd[i] == '\n' || cmd[i] == ' ')
	i++;
    }
  cmd2[y] = NULL;
  return (cmd2);
}
