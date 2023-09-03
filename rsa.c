#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - The function factorizes a number
 * @buffer: pointer to the address of the number as a string
 *
 * Author: Thaoban Abdrasheed
 * Return: void
 */
void factorize(char *buffer)
{
    unsigned int num;
    unsigned int i;

    num = atoi(buffer);

    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            printf("%u = %u * %u\n", num, num / i, i);
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *fptr;
    size_t count = 0;
    ssize_t line;
    char *buffer = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((line = getline(&buffer, &count, fptr)) != -1)
    {
        // Remove newline character if present
        if (line > 0 && buffer[line - 1] == '\n')
            buffer[line - 1] = '\0';

        factorize(buffer);
    }

    // Clean up and close the file
    fclose(fptr);
    if (buffer)
        free(buffer);

    return 0;
}
