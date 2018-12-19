/*
** action2.c for myftp in /home/decomb_s/rendu/PSU_2014_myftp/Server
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@epitech.net>
** 
** Started on  Sun Mar 22 19:14:43 2015 Sylvain DECOMBE
** Last update Sun Mar 29 18:39:36 2015 Sylvain DECOMBE
*/

#include "server.h"

void			do_else(int cs)
{
  write(cs, "xxx\n", 4);
  write(cs, "CMD not found\n", 14);
}

void			read_err(int cs)
{
  write(2, "READ error.\n", 12);
  close(cs);
  exit(-1);
}
