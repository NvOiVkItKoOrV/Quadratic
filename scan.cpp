#include <string.h>
#include <stdio.h>

void coeff_to_buf (char *buf, int size);

int main(void)
{
    char buf[50] = {0};
    coeff_to_buf(buf, 50);

    printf("Parsing the input string '%s'\n", buf);
    char *token = strtok(buf, " ");
    puts(token);

/*    while(token)
    {
        puts(token);
        token = strtok(NULL, " ");
    }

    printf("Contents of the input string now: '");
    for(size_t n = 0; n < sizeof input; ++n)
        input[n] ? putchar(input[n]) : fputs("\\0", stdout);
    puts("'");*/
}


void coeff_to_buf (char *buf, int size)
{

    int symb_count   = 0;
    int code_of_symb = 0;

    size -= 1;  // because of \0 at the end of buffer.

    while (symb_count < size && (code_of_symb = getchar()) != '\n')
    {
        buf[symb_count] = (char) code_of_symb;
        symb_count++;
    }

    buf[symb_count] = '\0';
}

