//erorr handling
int check_spaces(char *arr);
int check_numbers(char *arr);
int *get_original_dict();
int contains_basic(int *numn, int lonn, int aux);
int check_imprimibol(char *arr);

// churrazo
int ft_atoi(char *str);
void move_positions(char *str, int pos);
char *get_file_content();
void printArr(char *str);
void remove_spaces(char *str);
int get_longest_word(char *str,  int *row);
void fill_words(char **words, char *str);
void fill_numbers(int *nums, char *str); 

//printer
int find_num (int num, int *nums, int len);
void print_word (char **words, int *nums, int num, int l);
int get_full_num(int *str, int pos);
int *input_to_str(int num);
int print_num (int *pos, int *str, int *nums, char **words);
void write_num (int *str, int *nums, char **words, int *pos);
int check_numbers(char *arr);
int check_spaces(char *arr);
int check_imprimibol(char *arr);


//main.c
int ft_isnum(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (42);
}
void compile (int *rows, int inp, int *nums, char *words)
{
    int *input;
    int pos[2];

    input = input_to_str(ft_atoi(*inp));
    pos[1] = *rows;
    write_num(input, &nums, words, pos);
}
void argc2(char **argv)
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
    if (is_valid(array) == 0)
        return ;
    int longest = get_longest_word(array, rows) + 5;
    nums = (int *)malloc((*rows) * sizeof(int));
    fill_numbers(nums, array);
    words = (char **)malloc(*rows * sizeof(char *));
    int i = 0;
    while (i < *rows)
    {
        words[i] = (char *)malloc(longest * sizeof(char));
        i++;
    }
    fill_words(words, array);
    compile(rows, argv[1], nums, words);
}
int main(int argc, int **argv)
{
    if (argc == 2 && ft_isnum(argv[1]) == 42 && argv[1] <= 2147483647)
    {
        argc2(argv);
    }
    else if (argc == 3 && ft_isnum(argv[2]) == 42 && argv[2] <= 2147483647)
    {
        
    }
    else
        write (1, "error", 5);
    return (0);
}