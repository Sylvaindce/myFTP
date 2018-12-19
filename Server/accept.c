/*
** accept.c for accept in /home/decomb_s/Documents/TCPIP/Server
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@HP-EliteBook-decombs>
** 
** Started on  Wed Mar 11 15:24:55 2015 Sylvain DECOMBE
** Last update Sun Mar 29 18:31:55 2015 Sylvain DECOMBE
*/

#include "server.h"

int			create_proc(struct sockaddr_in sin, int fd, int cs, t_env *ev)
{
  char			*str;

  str = inet_ntoa(sin.sin_addr);
  wimip(str);
  if (close(fd) == -1)
    return (manage_err("Error close fd\n"));
  write(cs, "220\r\n", 5);
  write(cs, "230\r\n", 5);
  write(cs, "332\r\n", 5);
  do_server(cs, ev);
  return (0);
}

int			init_accept(int fd, t_env *ev)
{
  struct sockaddr_in	sin_client;
  socklen_t		c_len;
  int			cs;
  pid_t			pid;

  c_len = sizeof(sin_client);
  while (42)
    {
      if ((cs = (accept(fd, (struct sockaddr *)&sin_client, &c_len))) < 0)
	{
	  if (close(fd) == -1)
	    return (manage_err("Error close fd\n"));
	  return (manage_err("Error accept\n"));
	}
      pid = fork();
      if (pid < 0)
	return (manage_err("Error on fork\n"));
      if (pid == 0)
	create_proc(sin_client, fd, cs, ev);
      else
      	if (close(cs) == -1)
      	  return (manage_err("Error close cs\n"));
    }
  return (0);
}
