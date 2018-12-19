/*
** server.c for server in /home/decomb_s/Documents/TCPIP/Server
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@epitech.net>
** 
** Started on  Tue Mar 10 14:22:07 2015 Sylvain DECOMBE
** Last update Sun Mar 22 19:25:58 2015 Sylvain DECOMBE
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

#include "server.h"

int			init_listen(int fd, t_env *ev)
{
  if ((listen(fd, 42)) == -1)
    {
      if (close(fd) == -1)
	return (manage_err("Error close fd\n"));
      return (manage_err("Error listen\n"));
    }
  if (init_accept(fd, ev) == -1)
    return (-1);
  return (0);
}

int			init_bind(int fd, struct sockaddr_in sin, t_env *ev)
{
  if (bind(fd, (const struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
      if (close (fd) == -1)
	return (manage_err("Error close fd\n"));
      return (manage_err("Error init bind\n"));
    }
  if (init_listen(fd, ev) == -1)
    return (-1);
  return (0);
}

int			init_socket(int port, t_env *ev)
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  char			ipaddr[INET_ADDRSTRLEN];
  int			fd;

  pe = getprotobyname("TCP");
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) < 0)
    return (manage_err("Error init socket\n"));
  bzero((char*)&sin, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  inet_ntop(AF_INET, &sin.sin_addr, ipaddr, INET_ADDRSTRLEN);
  printf("%s\n", ipaddr);
  if (init_bind(fd, sin, ev) == -1)
    return (-1);
  return (0);
}

int			main(int argc, char **argv, char **env)
{
  t_env			*ev;

  ev = xmalloc(sizeof(t_env));
  if (argc != 2)
    return (manage_err("Error, usage ./myftp port\n"));
  if (*env == NULL)
    return (manage_err("Error, environment is NULL\n"));
  else
    {
      if (check_env(env, ev) == -1)
        write(2, "Path not found, check the environment.\n", 39);
      if (init_socket(atoi(argv[1]), ev) == -1)
	return (-1);
    }
  return (0);
}
