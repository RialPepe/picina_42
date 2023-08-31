#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int ft_atoi(char *str);
void move_positions(char *str, int pos);
char *get_file_content();
void printArr(char *str);
void remove_spaces(char *str);
int get_longest_word(char *str,  int *row);
void fill_words(char **words, char *str);
void fill_numbers(int *nums, char *str); 


int find_num (int num, int *nums, int len)
{
    int i;
    
    i = 0;
    while (i < len)
    {    
        if (num == nums[i])
            return (i);
        i++;
    }
    return (-1);
}
void print_word (char **words, int *nums, int num, int l)
{
    int index;
    int len;

    len = 0;
    index = find_num(num, nums, l);
    while (words[index][len])
        len++;
    write(1, &*words[index], len);
}
int get_full_num(int *str, int pos)
{
    int fullnum;

    fullnum = 0;
    while (pos  < 4)
    {
        fullnum = fullnum*1000 + str[pos];
        pos++;
    }
    return (fullnum);
}
int *input_to_str(int num)
{
    int *str;
    int i;

    i = 3;
    str = (int *)malloc(4 * sizeof(int));
    while (i >= 0)
    {
        str[i] = num % 1000;
        num /=  1000;
        i--;
    }
    return (str);
}

int print_num (int *pos, int *str, int *nums, char **words)
{
    int full_num;

    if(find_num(get_full_num(str, pos[0]), nums, pos[1]) > 0)
    {
        full_num = get_full_num(str, pos[0]);
        if(full_num == 100 || full_num == 1000 
            || full_num == 1000000 || full_num == 1000000000)
        {
            print_word(words, nums, 1, pos[1]);
            write(1, " ", 1);
            print_word(words, nums, full_num, pos[1]);
            write(1, " ", 1);
        }
        else
            print_word(words, nums, full_num, pos[1]);
            return (42);
    }
    if(find_num(str[pos[0]], nums, pos[1]) > 0)
    {
        print_word(words, nums, str[pos[0]], pos[1]);
        write(1, " ", 1);
        return (0);
    }
    if (str[pos[0]] >= 100)
    {
        print_word(words, nums, str[pos[0]]/100, pos[1]);
        write(1, " ", 1);
        print_word(words, nums, 100, pos[1]);
        write(1, " ", 1);
        str[pos[0]] = str[pos[0]] % 100;
        return print_num(pos, str, nums, words);
    }
    if (str[pos[0]] >=  10)
    {
        print_word(words, nums, (str[pos[0]] / 10) * 10, pos[1]);
        write(1, " ", 1);
        str[pos[0]] = str[pos[0]] % 10;
        return print_num(pos, str, nums, words);
    }
    return (0);
}

void write_num (int *str, int *nums, char **words, int *pos)
{
    int i;
    int pot;
    int a;
    i = 0;
    a = 0;
    pot = 1000000000;
    while (a == 0)
    {
        if (str[i] > 0)
        {
            pos[0] = i;
            a = print_num(pos, str, nums, words);
            if (a == 42)
                break ;
            print_word(words, nums, pot, pos[1]);
            write(1, " ", 1);
        }
        pot /= 1000;
        i++;
    }
    write (1, "\n", 1);
}
int check_numbers(char *arr)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    i--;
    while (arr[i])
    {
        if (arr[i] == ':')
        {
            i--;
            while (i >= 0 && arr[i] != '\n')
            {
                if (arr[i] < '0' || arr[i] > '9')
                    return (0);
                i--;
            }
        }
        i--;
    }
    return (42);
}
int check_spaces(char *arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        if (arr[i] == ' ')
            return (0);
        i++;
    }
    return (42);
}

int check_imprimibol(char *arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        if (arr[i] == ':')
        {
            i++;
            while (arr[i] != '\n' && arr[i])
            {
                if(arr[i] <= 31 || arr[i] == 127)
                    return (0);
                i++;
            }
        }
        i++;
    }
    return (42);
}
int main(int ac, char **av)
{
    char *array;
    int *nums;
    char **words;
    int *rows;
    int aux;
    aux = 0;
    rows = &aux;
    array = get_file_content("numbers.dict");
    remove_spaces(array);
    //printf("%d", check_imprimibol(array));
    int longest = get_longest_word(array, rows) + 5;
    nums = (int *)malloc((*rows) * sizeof(int));
    fill_numbers(nums, array);
    words = (char **)malloc(*rows * sizeof(char *));
    int i = 0;
    while (i < *rows && ac != 42)
    {
        words[i] = (char *)malloc(longest * sizeof(char));
        i++;
    }
    fill_words(words, array);
 
    int *input = input_to_str(ft_atoi(av[1]));
    int pos[2];
    pos[1] = *rows;
    write_num(input, nums, words, pos);


    free(words);
    free(nums);
    free(array);
    return 0;
}