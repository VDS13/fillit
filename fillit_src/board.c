#include "fillit.h"

int minimum_square_side(int number_of_items)
{
    int n = 1;
    if (number_of_items == 0)
        return (0);
    int number_of_cells = number_of_items * 4;
    while (1)
    {
        n = n + 1;
        if (n * n >= number_of_cells)
            return (n);
    }
    return (-1);
}

board *new_board(int side, char symbol)
{
    int j, k;
    board *board = malloc(sizeof(board));
    board->side = side;
    board->state = malloc(side * sizeof(char *));
    board->symbol = symbol;
    j = k = 0;
    while (j < side)
    {
        board->state[j] = malloc(side * sizeof(char));
        k = 0;
        while (k < side)
        {
            board->state[j][k] = '.';
            k = k + 1;
        }
        j = j + 1;
    }
    return (board);
}

void reset_board(board **board)
{
    int j;
    int k;

    j = 0;
    while (j < (*board)->side)
    {
        k = 0;
        while (k < (*board)->side)
        {
            (*board)->state[j][k] = '.';
            k = k + 1;
        }
        j = j + 1;
    }
}

void wipe_board(board **board)
{
    int j, k;

    j = k = 0;
    while (j < (*board)->side)
    {
        ft_strdel(&(*board)->state[j]);
        j = j + 1;
    }
    free(*board);
    *board = NULL;
}

board *wipe_and_resize(board **board, int new_size)
{
    
    struct board *new_item = new_board(new_size, (*board)->symbol);
    wipe_board(board);
    return (new_item);
}

point *new_point(int x, int y)
{
    point *point = malloc(sizeof(point));
    point->x = x;
    point->y = y;
    return (point);
}

point *closest_to_the_origin(board *board)
{
    int j, k, m;
    j = k = m = 0;
    while (m < board->side * 2)
    {
        (m > board->side - 1) ? (j = board->side - 1) : (j = m);
        (m > board->side - 1) ? (k = m % board->side - 1) : (k = 0);
        while (j >= 0)
        {
            if (board->state[j][k] == '.')
                return (new_point(j, k));
            j = j - 1;
            k = k + 1;
        }
        m = m + 1;
    }
    return (NULL);
}

point *closest_unchecked(board *board, struct board *checked_cells)
{
    int j, k, m;
    j = k = m = 0;
    while (m < board->side * 2)
    {
        if (m > board->side - 1)
        {
            j = board->side - 1;
            k = m % (board->side);
        }
        else 
        {
            j = m;
            k = 0;
        }
        while (j >= 0)
        {
            if (board->state[j][k] == '.' && checked_cells->state[j][k] == '.')
            {
                return (new_point(j, k));
            }
            j = j - 1;
            k = k + 1;
        }
        m = m + 1;
    }
    return (NULL);
}

board *copy_board(board *old_board)
{
    int j, k;
    struct board *board = new_board(old_board->side, old_board->symbol);
    j = k = 0;
    while (j < board->side)
    {
        k = 0;
        while (k < board->side)
        {
            board->state[j][k] = old_board->state[j][k];
            k = k + 1;
        }
        j = j + 1;
    }
    return (board);
}

void print_board(board *board)
{
    int j, k;
    if (!board)
        return ;
    j = k = 0;
    while (j < board->side)
    {
        k = 0;
        while (k < board->side)
        {
            write(1, &(board->state[j][k]), 1);
            k = k + 1;
        }
        j = j + 1;
        write(1, "\n", 1);
    }
}

board *string_to_board(int side, const char *string, char symbol) //what's the point of side? 
{
    int j, k, m;
    board *board = new_board(side, symbol);
    j = k = m = 0;
    while (j < side)
    {
        k = 0;
        while (k < side)
        {
            if (string[m] != '.')
                board->state[j][k] = symbol;
            k = k + 1;
            m = m + 1;
        }
        j = j + 1;
    }
    return (board);
}

int place_on_the_board(board **board, struct board *item, point *point, char c)
{
    int j, k;
    struct board *save = copy_board(*board);
    if (item->side != 4)
    {
        return (0);
    }
    j = k = 0;
    while (j < item->side)
    {
        k = 0;
        while (k < item->side)
        {
            if (item->state[j][k] != '.')
            {
                if (((*board)->side < (point->y + k + 1)) || ((*board)->side < (point->x + j + 1)))
                {
                    *board = save;
                    return (0);
                }
                if ((*board)->state[j + point->x][k + point->y] != '.')
                {
                    *board = save;
                    return (0);
                }
                (*board)->state[j + point->x][k + point->y] = c;
            }
            k = k + 1;
        }
        j = j + 1;
    }
    return (1);
}