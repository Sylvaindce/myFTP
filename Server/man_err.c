/*
** man_err.c for man_err in /home/decomb_s/Documents/TCPIP/Server
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@HP-EliteBook-decombs>
** 
** Started on  Wed Mar 11 13:43:09 2015 Sylvain DECOMBE
** Last update Sun Mar 22 19:26:58 2015 Sylvain DECOMBE
*/

#include "server.h"

void			wimip(char *str)
{
  write(1, "IP Address : ", 13);
  write(1, str, strlen(str));
  write(1, "\n", 1);
}

char                    *clear_buff(char *str)
{
  int                   i;

  i = 0;
  while (i < 4096)
    {
      str[i] = '\0';
      ++i;
    }
  return (str);
}

int                     manage_err(char *str)
{
  write(2, str, strlen(str));
  return (-1);
}
