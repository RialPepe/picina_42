#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_atoi(char *str)
{
	int	aux;
	int	numf;

	numf = 0;
	aux = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			aux++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		numf = (numf * 10) + (*str - '0');
		str++;
	}
	if (aux % 2 != 0)
		numf = -numf;
	return (numf);
}

void move_positions(char *str, int pos)
{
    while (str[pos])
    {
        str[pos] = str[pos + 1];
        pos++;
    }
}
char *get_file_content(char  *filename)
{
    int fd;
    char character;  
    int character_count;
    int i;
    char *character_array;

    character_count = 0;
    i = 0;
    fd = open(filename, O_RDONLY);
    while (read(fd, &character, 1) > 0)
        character_count++;
    close(fd);
    fd = open(filename, O_RDONLY);
    character_array = (char *)malloc(character_count * sizeof(char));
    while (read(fd, &character, 1) > 0)
    {
        character_array[i] = character;
        i++;
    }
    close(fd);
    return (character_array);
}
void printArr(char *str)
{
    printf("%s", str);
}
void remove_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ':')
        {
            while (str[i + 1] == ' ')
            {
                move_positions(str, i + 1);
            }
            while (str[i - 1] == ' ')
            {
                move_positions(str, i - 1);
                i -= 1;
            }
        }
        i++;
    }
}

int get_longest_word(char *str,  int *row)
{
    int max;
    int i;
    int j;

    max = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == ':')
        {
            (*row)++;
            j = 0;
            while (str[i] != '\n')
            {
                j++;
                i++;
            }
            if (max < j)
                max = j;
        }
        i++;
    }
    return (max);
}

void fill_words(char **words, char *str)
{
    int i;
    int j;
    int r;

    i = 0;
    r = 0;
    while (str[i])
    {
        if (str[i] == ':')
        {
            j = 0;
            i++;
            while (str[i] != '\n')
            {
                words[r][j] = str[i];
                i++;
                j++;
            }
            words[r][j] = '\0';
            r++;
        }
        i++;
    }
}
void fill_numbers(int *nums, char *str)
{
    int i;
    int r;

    i = 0;
    r = 1;
    nums[0] = ft_atoi(str);
    while (str[i])
    {
        if (str[i] == '\n')
        {
            nums[r] = ft_atoi(str + i);
            r++;
        }
        i++;
    }
}


























// int main() {
//     int fd;              // Descriptor de archivo
//     char character;      // Carácter leído
//     int character_count = 0; // Contador de caracteres

//     // Abre el archivo en modo de lectura
//     fd = open("numbers.dict", O_RDONLY);

//     // Verifica si el archivo se abrió correctamente
//     if (fd == -1) {
//         perror("Error al abrir el archivo");
//         return 1;  // Termina el programa con error
//     }

//     // Cuenta los caracteres en el archivo
//     while (read(fd, &character, 1) > 0) {
//         character_count++;
//         printf("%c", character);
//     }

//     // Cierra el archivo
//     close(fd);

//     // Abre el archivo nuevamente
//     fd = open("numbers.dict", O_RDONLY);

//     // Crea un array dinámico para almacenar los caracteres
//     char *character_array = (char *)malloc(character_count * sizeof(char));

//     if (character_array == NULL) {
//         perror("Error al asignar memoria");
//         return 1; // Termina el programa con error
//     }

//     // Lee y almacena los caracteres en el array
//     for (int i = 0; i < character_count; i++) {
//         read(fd, &character, 1);
//         character_array[i] = character;
//     }

//     // Cierra el archivo nuevamente
//     close(fd);

//     // Ahora puedes usar el array character_array

//     // Liberar la memoria asignada para el array
//     free(character_array);

//     return 0; // Termina el programa exitosamente
// }
