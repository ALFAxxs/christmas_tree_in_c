#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int My_Christmas_Tree(int p1)
{
    int a = 1;
    int joylasgtirish = 0;
    for (int i = 1; i <= p1; i++)
    {
        int yoqVaroq = i + 3;
        a -= joylasgtirish;
        for (int j = 1; j < yoqVaroq; j++)
        {
            a += 2;
        }
        if (yoqVaroq % 2 == 0)
        {
            joylasgtirish += 2;
        }
    }
    return a;
}
void printer(char c, int x)
{
    for (int i = 0; i < x; i++)
    {
        putchar(c);
    }
}

int print_block(int first_line_len, int lower_len, int block_index)
{
    int current_star_no = first_line_len;
    int lines = block_index + 3;
    for (int i = 0; i < lines; i++)
    {
        int space_no = lower_len / 2 - (current_star_no / 2);
        printer(' ', space_no);
        printer('*', current_star_no);
        putchar('\n');
        current_star_no += 2;
    }
    return current_star_no - 2;
}

void tree(int p1)
{
    int list = 1;
    int length = My_Christmas_Tree(p1);
    int joylasgtirish = 0;
    for (int i = 1; i <= p1; i++)
    {
        int yoq_qatorlar = i + 3;
        list -= joylasgtirish;
        list = print_block(list, length, i);
        if (yoq_qatorlar % 2 == 0)
        {
            joylasgtirish += 2;
        }
    }
}
void leg(int p1)
{
    int spaces = My_Christmas_Tree(p1) / 2;
    int hozirgi_joylashuvi = spaces - (p1 / 2);
    if (p1 % 2 == 0)
    {
        hozirgi_joylashuvi += 1;
    }
    for (int i = 1; i <= p1; i++)
    {
        printer(' ', hozirgi_joylashuvi);
        printer('|', p1);
        putchar('\n');
    }
}

void print_tree(int temp)
{
    tree(temp);
    leg(temp);
}

int main(int ac, char** av)
{
    int number = av[1][0] - '0';
    if (av[1][1] > 0)
    {
        number = number * 10 + av[1][1];
    }
    print_tree(number);
}