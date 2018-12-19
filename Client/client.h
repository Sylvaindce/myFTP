/*
** client.h for client in /home/decomb_s/Documents/TCPIP/Client
** 
** Made by Sylvain DECOMBE
** Login   <decomb_s@HP-EliteBook-decombs>
** 
** Started on  Tue Mar 10 12:51:43 2015 Sylvain DECOMBE
** Last update Sun Mar 22 20:13:43 2015 Sylvain DECOMBE
*/

#ifndef CLIENT_H_
# define CLIENT_H_

/* client.c */
char                    *cut_buff(char *buff);
char                    *man_buff(char *buff);
int                     man_con(int fd, int con, char **ar);
int		        do_client(int fd, char *ip);

/* man_disp.c */
void			my_co(char *ip);
void			my_init(char *ip);
void			my_err(int sr);
int			man_cmd(char *buff, int sr);

/* xmalloc.c */
void			*xmalloc(int size);

/* strcp.c */
int			my_strcmp(char *s1, char *s2);
int			my_strncmp(char *str, char *str2, int nb);

#endif /* !CLIENT_H_ */
