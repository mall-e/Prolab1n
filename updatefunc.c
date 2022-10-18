#include "prolab.h"

// int	file_lenght(int fd, int *len, char *row)
// {
// 	char	*str;
// 	*len += strlen(row);
// 	while ((*len += read(fd, str, 1) != NULL))
// 	{
// 		printf("satır: %s uzunluğu : %lu\n", str, strlen(str));
// 	}
// 	return (*len);
// }

// char	*readtxt(char *row, int fd)
// {
// 	char	*doc;
// 	char	*nrow;
// 	char	*gnl;

// 	doc = calloc(1, 10000);
// 	nrow = calloc(1, 10000);
// 	if ((gnl = get_next_line(fd)) != NULL)
// 		nrow = strcat(row, gnl);
// 	else
// 	{
// 		doc = strcat(doc, row);
// 		return (doc);
// 	}
// 	doc = strcat(doc, nrow);

// 	printf("doc: \n%s\tlen: %lu\n", doc, strlen(doc));
// 	return (doc);
// }

char	*readtxt(int fd)
{
	char	*doc;
	char	*c;

	doc = calloc(1, 10000);
	while ((read(fd, c, 1) != 0))
	{
		doc = strcat(doc, c);
	}
	return doc;
}

int	uwordcmp(char *word, char *row, char *fname, int fd)
{
	int	i;
	int	j;
	int	tmp;
	int	count;

	i = 0;
	//printf("word: %s  row: %s\n", word, row);
	while (row[i])
	{
		j = 0;
		tmp = i;
		count = 0;
		while(word[j])
		{
			if (row[tmp] == word[j])
			{
				tmp++;
				j++;
				count++;
			}
			else
				break ;
		}
		//printf("word %s dlt_extfname : %s \n", word, dlt_ext(fname));
		//usleep(1000000);
		if (strlen(word) == count && (row[tmp] == ' ' || row[tmp] == ',' || row[tmp] == '.' || row[tmp] == '\n' || row[tmp] == '\0'))
			return (1);
		else if (strlen(word) == count
			&& (row[tmp] == ']' && row[tmp + 1] == ']'
			&&	row[tmp - count - 1] == '[' && row[tmp - count  - 2] == '['))
		{
			return (2);
		}
		else if (!strcmp(word, dlt_ext(fname)))
		{
			return (3);
		}

		i++;
	}
	return (0);
}

void	update_doc(char *doc ,int fd, char *label, char *upword)
{
	int	i;
	int	j;
	int	tmp;
	int	k;
	char	*ndoc;
	int tmp2;

	i = 0;
	j = 0;
	k = 0;
	tmp = 0;
	ndoc = malloc(strlen(doc) - strlen(label) + strlen(upword));
	while (doc[i]) // tiktokçu burak kozluca snap attı         kozluca      çağlayan
	{
		tmp = i;
		j = 0;
		while (doc[tmp] == label[j])
		{
			tmp++;
			j++;
		}
		//printf("tmp - i = %d strlenlabel = %d\n", tmp - i, strlen(label));
		if (tmp - i == strlen(label) && doc[tmp] == ']')
		{
			k = 0;
			tmp2 = tmp;
			while (k < strlen(upword))
			{
				ndoc[i] = upword[k];
				i++;
				k++;
			}
		}
		ndoc[i] = doc[tmp2];
		tmp2++;
		i++;
	}
	printf("doc: %s\n", doc);
	printf("yeni dosya: \n%s\n", ndoc);
}
