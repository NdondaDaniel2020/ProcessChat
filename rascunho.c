#include "libft/libft.h"
#include <stdio.h>

int main(void)
{
    char *line;

    line = get_next_line(0);
    while (line != NULL)
    {   
        printf("Linha lida: %s\n", line);
        free(line);
        line = get_next_line(0);
    }
    return (0);
}
