// -----DICCIONARIO-----
// que en la posicion 0 o despues de un salto de linea solo haya numeros
// quitar espacios que rodeen los " : "
// todo lo que esté ente salto de linea y " : " que sea un numero
// todo lo que esté entre " : " y salto de linea es imprimible (dan igual los espacios)
// existen las entradas basicas (diccionario original)

// -----ARGUMENTOS------
// puede haber solo 2 o 3 argumentos
// comprobar que el numero es valido
    // todo son numeros
    // numero >= 0 || numero <= 4294967295
// si hay solo 2 argumentos usamos el diccionario base por defecto

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

int check_numbers(char *arr)
{
    int i;

    while (arr[i])
        i++;
    i--;
    while (arr[i])
    {
        if (arr[i] == ':')
        {
            i--;
            while (i >= 0 || arr[i] != '\n')
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

int *get_original_dict()
{
    char *array;
    int *lon;
    int aux;
    int *numo;

    aux = 0;
    lon = &aux;
    array = get_file_content("numbers.dict");
    remove_spaces(array);
    get_longest_word(array, lon);
    numo = (int *)malloc(*lon * sizeof(int));
    fill_numbers(numo, array);
    return (numo);
}
int contains_basic(int *numn, int lonn, int aux) // aux = 0
{
    int *numo;
    int lono;
    int i;
    int j;

    i = 0;
    j = 0;
    lono = 32;
    numo = get_original_dict();
    while (i < lono)
    {
        aux = 0;
        j = 0;
        while (j < lonn)
        {
            if (numo[i] == numn[j])
                aux = 1;
        }
        if (aux == 0)
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
int is_valid(char *arr)
{
    if (check_spaces(arr) == 42 && check_numbers(arr) == 42 
        && check_imprimibol(arr) == 42)
        return (42);
    write(1, "Dict Error\n", 11);
    return (0);
}