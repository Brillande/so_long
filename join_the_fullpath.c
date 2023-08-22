char *join_the_fullpath(char *map_name)
{
	char	*map_name_with_extension;
	char	*maps_directory;
	char	*full_path;

	map_name_with_extension = check_extension(map_name);

	if (map_name_with_extension != NULL)
	{
		maps_directory = "maps/";
		full_path = (char *)ft_strjoin(maps_directory,
		map_name_with_extension);
		if (full_path == NULL)
		{
			perror("Error al asignar memoria\n");
			return (1);
		}
	}
	return(full_path);
}