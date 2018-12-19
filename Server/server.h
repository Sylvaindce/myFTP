/*
** server.h for server in /home/decomb_s/Documents/TCPIP
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@HP-EliteBook-decombs>
** 
** Started on  Tue Mar 10 11:21:40 2015 Sylvain DECOMBE
** Last update Sun Mar 22 19:40:37 2015 Sylvain DECOMBE
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_env
{
  char		*home;
  char		*pwd;
  char		**envi;
}		t_env;

/* accept.c */
int             create_proc(struct sockaddr_in s, int fd, int cs, t_env *ev);
int             init_accept(int fd, t_env *ev);

/* action.c */
void		do_list(int cs);
void		do_pwd(int cs, t_env *ev);
void		do_cwd(int cs, t_env *ev, char *msg);
void		do_quit(int cs);
void            do_server(int cs, t_env *ev);

/* action2.c */
void		do_else(int cs);
void		read_err(int cs);

/* man_cd.c */
char		**cmdtocmd(char *cmd);

/* open.c */
void            cmd_cd(char *buff, int cs, t_env *ev);
void            my_cd(char *buff, t_env *ev, int cs);
void		puthome(char *home, int cs, t_env *ev);

/* man_env.c */
int             check_env(char **env, t_env *ev);
void            affpath(char **path);

/* man_ls.c */
int		my_ls(int fd);

/* strcp.c */
int		my_strcmp(char *s1, char *s2);
int             my_strncmp(char *str, char *str2, int nb);

/* man_put.c */
int		my_put(char *buff, int cs, char *msg);

/* server.c */
int             init_socket(int port, t_env *ev);
int             init_bind(int fd, struct sockaddr_in sin, t_env *ev);
int             init_listen(int fd, t_env *ev);

/* man_err.c */
void            wimip(char *str);
char            *clear_buff(char *str);
int             manage_err(char *str);

/* man_file.c */
int		my_get(char *buff, int cs);
char		*change_name(char *name);

/* man_pwd.c */
void		my_pwd(int fd, t_env *ev);

/* xmalloc.c */
void            *xmalloc(int size);

#endif /* !SERVER_H_ */
