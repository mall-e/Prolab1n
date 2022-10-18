#include "prolab.h"

void	update_label()
{
	int	fd;
	int	i;
	char *row;
	char cwd[256];
	char cwd2[256];
	struct dirent *s_dir;
	struct dirent *sdir2;
	DIR *dir;
	DIR *dir2;
	unsigned char	uword[20];
	unsigned char	updatedw[20];
	int	ytm_control;
	int len;
	char	*doc;
	int j = 0;

	ytm_control = 0;
	len = 0;
	printf("Güncellenecek etiketi giriniz: \n");
	fflush(stdin);
	scanf("%[^\n]s", uword);
	printf("%s\n",(unsigned char *)uword); // ------------------------------------> :D
	printf("Güncellemek istediğiniz kelimeyi giriniz: \n");
	fflush(stdin);
	scanf("%[^\n]s", updatedw);
	printf("%s\n",(unsigned char *)updatedw); // ------------------------------------> :D
	// while (uword[j])
	// {
	// 	printf("%s",(unsigned char *)uword);
	// 	//write(1, &uword[j], 1);
	// 	j++;
	// }

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		(write(1, "Error\n", 6));
	//else
	//	printf("current working directory: %s\n", cwd);
	chdir(strcat(cwd, "/Üniversite/"));
	//printf("cwd      %s\n",cwd);
	dir = opendir(".");
	while ((s_dir = readdir(dir))!= NULL)
	{
		if (!strcmp(s_dir->d_name, ".") || !strcmp(s_dir->d_name, "..") || s_dir->d_type == 8)
			continue;
		//printf("içerdeki cwd : %s\n", cwd);
		chdir(strcat(cwd, "/"));
		dir2 = opendir(strcat(cwd, s_dir->d_name));
		//printf("degisen: %s\n", cwd);
		while ((sdir2 = readdir(dir2)) != NULL)
		{
			if (!strcmp(sdir2->d_name, ".") || !strcmp(sdir2->d_name, "..") || !find_txt(sdir2->d_name))
				continue;
			chdir(strcat(cwd, "/"));
			fd = open(sdir2->d_name, O_RDWR);
			//printf("Dosya: %s\n", sdir2->d_name);
			i = 1;
			while ((row = get_next_line(fd)) != NULL)
			{
				if (txtcmp(uword, sdir2->d_name))
				{
					ytm_control++;
				}
				if (uwordcmp(uword, row, sdir2->d_name, fd) == 2)
				{
					printf("Aha buldum \n%s isimli dosyada %d satırda aradığınız etiket bulunmakta\n", sdir2->d_name, i);
					close(fd);
					fd = open(sdir2->d_name, O_RDWR);
					row = get_next_line(fd);
					printf("row: %s\n", row);
					printf("file: \n%s doc : \n%s\n",sdir2->d_name, "zort");
					update_doc(ft_strjoin(row,readtxt(fd)),fd, uword, updatedw);
					//usleep(2000000);
				}
				else if (wordcmp(uword, row, sdir2->d_name) == 3)
				{
					//printf("%d\n", ist_control);
					//usleep(2000000);
				}
				// else
				// {
				// 	printf("Hmm... bu dosyada yok (%s)\n", sdir2->d_name);
				// 	//usleep(100000);
				// }
				//printf("Satir %d: \n%s\n", i,row);
				//printf("dname: %s word: %s mcmp(): %d strlenword: %lu strlendname: %lu\n", dlt_ext(sdir2->d_name), word, mcmp(dlt_ext(sdir2->d_name), word), strlen(word), strlen(dlt_ext(sdir2->d_name)));
				i++;
			}
			close(fd);

		}
		getcwd(cwd, sizeof(cwd));
		chdir(go_back(cwd));
		closedir(dir2);

	}
	closedir(dir);
	chdir(go_back(cwd));
}
