#include "fillit.h"

void swap_letters(void *set, int j, int k)
{
    char letter = ((char*)set)[j];
    ((char *)set)[j] = ((char *)set)[k];
    ((char *)set)[k] = letter;
}

void swap_integers(void *set, int j, int k)
{
    int integer = ((int *)set)[j];
    ((int *)set)[j] = ((int *)set)[k];
    ((int *)set)[k] = integer;
}

void swap_strings_wow(void *set, int j, int k)
{
    char *thing = (((char **)set)[j]);
    (((char **)set)[j]) = (((char **)set)[k]);
    (((char **)set)[k]) = thing;
}

int	get_int_array_new(int **array, int size)
{
	int k;

	*array = malloc(sizeof(int) * size);
	k = 0;
	if (*array)
	{
		while (k < size)
		{
			(*array)[k] = 0;
			k = k + 1;
		}
		return (1);
	}
	return (0);
}

int permute_new(void *set, int size, void (*swap)(void *, int, int), int reset)
{
    static int *stack_state;
    static int j;


    if (reset == 1)
    {
        stack_state = NULL;
        j = 0;
        return (-1);
    }
	if (!stack_state)
		return (get_int_array_new(&stack_state, size));
    while (j < size)
    {
        if (stack_state[j] < j)
        {
            if (j % 2 == 0)
            {
                swap(set, 0, j);
                stack_state[j] = stack_state[j] + 1;
                j = 0;
                return (1);
            }
            else
            {
                swap(set, stack_state[j], j);
                stack_state[j] = stack_state[j] + 1;
                j = 0;
                return (1);
            }
        }
        stack_state[j] = 0;
        j = j + 1;   
    }
    j = 0;
    stack_state = NULL;
    return (0);
}

void how_about_that(char *set, int size)
{
    int j = 0;
    char *new_set;
    while (j < size)
    {
        
        if (size > 2)
        {
            printf("%c", set[j]);
            new_set = ft_strjoin(ft_strsub(set, 0, j), ft_strsub(set, j + 1, ft_strlen(set) - j));
            //printf("new set: %s\n", new_set);
            how_about_that(new_set, size - 1);
        }
        printf("%s\n", set);
        swap_letters(set, 0, 1);
        j = j + 1;
    }
    //printf("\n");
}

void how_about_this(char *set, int size) //this is promising;
{
    int j = 0;
    while (j < size)
    {
        if (size > 2)
        {
            printf("%c", set[j]);
            how_about_this(ft_strjoin(ft_strsub(set, 0, j), ft_strsub(set, j + 1, ft_strlen(set) - j)), size - 1);
        }
        if (size == 2)
        {
            printf("%s\n", set);
            swap_letters(set, 0, 1);
        }
        j = j + 1;
    }
}

void maybe_this(char *set, int size, char **permutation, int depth, char *original)
{
    static int j;
    static char *new_set;
    char *store;
    while (j < size)
    {
        
        if (size > 2)
        {
            (*permutation)[depth] = set[j];
            new_set = ft_strjoin(ft_strsub(set, 0, j), ft_strsub(set, j + 1, ft_strlen(set) - j));
            maybe_this(new_set, size - 1, permutation, depth + 1, original);
        }
        store = ft_strdup(*permutation);
        (*permutation)[depth] = set[0];
        (*permutation)[depth + 1] = set[1];
        printf("current state: depth = %d; j = %d; permutation = %s;\n", depth, j, *permutation);
        swap_letters(set, 0, 1);
        j = j + 1;
        *permutation = ft_strdup(store);
    }
    //printf("current state: depth = %d; j = %d; permutation = %s;\n", depth, j, *permutation);
    new_set = NULL;

}