#ifndef PROLAB_H
#define PROLAB_H

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "get_next_line/get_next_line.h"
#include <fcntl.h>

typedef struct prolab
{
	char *cwd;
}				prolab;


int		find_txt(char *fname);
int		mcmp(char *s1, char *s2);
void	find_word(prolab *pro);
void	definitions(prolab *pro);
void	update_label();
char	*dlt_ext(char *txtfile);
int		txtcmp(char *word, char *txt);
int		wordcmp(char *word, char *row, char *fname);
char	*go_back(char *s);
//int	file_lenght(int fd, int *len, char *row);
char	*readtxt(int fd);
int	ft_strstr(const unsigned char *s1, const unsigned char *s2);
int	uwordcmp(char *word, char *row, char *fname, int fd);
void	update_doc(char *doc ,int fd, char *label, char *upword);

#endif
