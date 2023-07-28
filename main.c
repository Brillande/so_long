/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:02 by emedina-          #+#    #+#             */
/*   Updated: 2023/07/28 16:46:18 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

// ahora te toca hacer la una funcion que lea el archivo

/* void	read_map(int fd, char *map)
{
	char	*buff;
	int		leng;
	int		read_map;
	size_t	i;
	int		len;

	leng = ft_strlen(map);
	buff = malloc(leng * sizeof(char));
	if (!buff)
		return (NULL);
	read_map = 1;
	while (!ft_strchr(map, '\n') && read_map != 0)
	{
		read_map = read(fd, buff, 1);
		if (read_map == -1)
		{
			free(buff);
			free(map);
			return (NULL);
		}
		buff[read_map] = '\0';
		map = ft_strjoin(map, buff);
	}
	free(buff);
	return (map);
} */
/* size_t	ft_strlen(const char *s)
{
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
} */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*str;
	unsigned char		*dest;
	size_t				i;

	str = src;
	dest = dst;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2 + 1);
	return (str);
}
int	ft_strlen(const char *str)
{
	int len;
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*check_name(char *map_name)
{
	int	leng;
	int	i;

	leng = 0;
	i = 0;
	leng = ft_strlen(map_name);
	ft_printf("%s", "El nombre del archivo es: ");
	ft_printf("%s\n", &map_name[i]);
	return (map_name);
}

char	*check_extension(char *map_extension)
{
	int	leng;

	leng = 0;
	leng = ft_strlen(map_extension);
	if (map_extension[leng - 1] == 'r' && map_extension[leng - 2] == 'e'
		&& map_extension[leng - 3] == 'b' && map_extension[leng - 4] == '.')
	{
		write(1, "La extension es .ber\n", 21);
		check_name(map_extension);
		return (map_extension);
	}
	else
	{
		write(1, "Error\nLa extension no es .ber\n", 30);
		return (NULL);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *map_name_with_extension;
		char *maps_directory;
		char *full_path;
		int file;
		map_name_with_extension = check_extension(argv[1]);

		if (map_name_with_extension != NULL)
		{
			maps_directory = "maps/";
			full_path = (char *)ft_strjoin(maps_directory, map_name_with_extension);
			if (full_path == NULL)
			{
				perror("Error al asignar memoria\n");
				return (1);
			}
			file = open(full_path, O_RDONLY);
			if (file == -1)
			{
				perror("ERROR \n No se pudo abrir el archivo\n");
				return (1);
			}
			else
			{
				ft_printf("%s", "se abrio el archivo");
				
			}
			free(full_path);
		}
	}
	return (0);
}