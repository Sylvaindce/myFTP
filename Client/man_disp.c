/*
** man_disp.c for myftp in /home/decomb_s/rendu/PSU_2014_myftp/Client
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@epitech.net>
** 
** Started on  Sun Mar 22 19:49:23 2015 Sylvain DECOMBE
** Last update Sat Mar 28 00:54:39 2015 Sylvain DECOMBE
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

void		my_co(char *ip)
{
  write(1, "Connected to ", 13);
  write(1, ip, strlen(ip));
  write(1, "\n", 1);
  write(1, "220 decomb_s FTP server (Linux OS) ready.\n", 42);
}

void		my_init(char *ip)
{
  write(1, "ANONYMOUS@", 10);
  write(1, ip, strlen(ip));
  write(1, ":~$ ", 4);
}

void		my_err(int sr)
{
  write(1, "READ error.\n", 12);
  close(sr);
  exit(-1);
}

int		man_cmd(char *buff, int sr)
{
  if (my_strncmp(buff, "ls", 2) == 0 || my_strncmp(buff, "LS", 2) == 0)
    write(sr, "LIST\n", 5);
  else if (my_strncmp(buff, "cd", 2) == 0 || my_strncmp(buff, "CD", 2) == 0)
    write(sr, cut_buff(buff), strlen(buff) + 1);
  else if (my_strncmp(buff, "quit", 4) == 0
	   || my_strncmp(buff, "QUIT", 4) == 0)
    {
      write(sr, "QUIT\n", 5);
      return (-1);
    }
  else if (my_strncmp(buff, "pwd", 3) == 0)
    write(sr, "PWD\n", 4);
  else
    write(sr, buff, strlen(buff));
  return (0);
}
