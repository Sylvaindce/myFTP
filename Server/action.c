/*
** action.c for action in /home/decomb_s/Documents/TCPIP/Server
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@HP-EliteBook-decombs>
** 
** Started on  Wed Mar 11 15:26:22 2015 Sylvain DECOMBE
** Last update Sun Mar 29 18:39:53 2015 Sylvain DECOMBE
*/

#include "server.h"

void			do_list(int cs)
{
  write(cs, "200\r\n", 5);
  write(cs, "150\r\n", 5);
  my_ls(cs);
  write(cs, "226\r\n", 5);
}

void			do_pwd(int cs, t_env *ev)
{
  write(cs, "257\r\n", 5);
  my_pwd(cs, ev);
}

void			do_cwd(int cs, t_env *ev, char *msg)
{
  write(cs, "250\r\n", 5);
  my_cd(msg, ev, cs);
}

void			do_quit(int cs)
{
  write(cs, "221\r\n", 5);
  write(cs, "Quit\n", 5);
  write(cs, "226\r\n", 5);
}

void			do_server(int cs, t_env *ev)
{
  char			*msg;
  int			ret;

  (void)ev;
  while (my_strncmp(msg, "QUIT", 4) != 0)
    {
      msg = xmalloc(sizeof(char) * 4096);
      if ((ret = read(cs, msg, 4096)) <= 0)
	read_err(cs);
      msg[ret] = '\0';
      if (my_strncmp(msg, "LIST", 4) == 0)
	do_list(cs);
     else if (my_strncmp(msg, "PWD", 3) == 0)
       do_pwd(cs, ev);
     else if (my_strncmp(msg, "CWD", 3) == 0)
       do_cwd(cs, ev, msg);
     else if (my_strncmp(msg, "QUIT", 4) == 0)
       do_quit(cs);
     else
       do_else(cs);
      msg = clear_buff(msg);
      free(msg);
    }
}
