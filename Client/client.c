/*
** client.c for client in /home/decomb_s/Documents/TCPIP/Client
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@epitech.net>
** 
** Started on  Tue Mar 10 14:20:33 2015 Sylvain DECOMBE
** Last update Sun Mar 22 20:42:09 2015 Sylvain DECOMBE
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "client.h"

char			*cut_buff(char *buff)
{
  char			*stock;

  stock = xmalloc(sizeof(buff) + 1);
  if (strlen(buff) == 2)
    strcpy(stock, "CWD");
  else
    {
      strcpy(stock, "CWD");
      strcat(stock, buff + 2);
    }
  return (stock);
}

char			*man_buff(char *buff)
{
  int			i;
  int			len;
  char			*stock;

  i = 0;
  stock = xmalloc(sizeof(buff));
  len = strlen(buff) - 1;
  while (i < len)
    {
      stock[i] = buff[i];
      ++i;
    }
  stock[i] = 0;
  return (stock);
}

int			do_client(int sr, char *ip)
{
  char			*buff;
  char			*buff2;
  int			ret;
  int			flag;

  flag = 0;
  while (flag == 0)
    {
      my_init(ip);
      buff = xmalloc(sizeof(char) * 4096);
      buff2 = xmalloc(sizeof(char) * 4096);
      bzero(buff, 4096);
      bzero(buff2, 4096);
      if ((ret = read(0, buff, 4096)) <= 0)
	my_err(sr);
      buff[ret] = '\0';
      flag = man_cmd(buff, sr);
      sleep(1);
      read(sr, buff2, 4096);
      write(1, buff2, strlen(buff2));
      free(buff);
      free(buff2);
    }
  close(sr);
  return (-1);
}

int			man_con(int fd, int con, char **ar)
{
  struct sockaddr_in	sin;
  int			port;

  port = atoi(ar[2]);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(ar[1]);
  if ((con = connect(fd, (const struct sockaddr*)&sin, sizeof(sin))) == -1)
    {
      write(2, "Error connect\n", 14);
      if (close(fd) == -1)
	{
	  write(2, "Error close fd\n", 15);
	  return (-1);
	}
      return (-1);
    }
  my_co(ar[1]);
  if ((do_client(fd, ar[1])) == -1)
    return (-1);
  return (0);
}

int			main(int argc, char **argv)
{
  struct protoent	*pe;
  int			fd;
  int			con;

  con = 0;
  if (argc != 3)
    {
      write(2, "Error usage ./myftp ip port\n", 28);
      return (-1);
    }
  pe = getprotobyname("TCP");
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      write(2, "Error init socket.\n", 19);
      return (-1);
    }
  if (man_con(fd, con, argv) == -1)
    return (-1);
  return (0);
}
