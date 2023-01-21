#ifndef _CALC_H
#define _CALC_H
#include <stdlib.h>
#include <stdio.h>
/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
        char *op;
        int (*f)(int a, int b);
} op_t;
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
int (*get_op_func(char *s))(int, int);
#endif



3-get_op_func.c 

#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_op_func - Entry function
 * @s: operator
 * Return: function
 */

int (*get_op_func(char *s))(int, int)
{
        op_t ops[] = {
                {"+", op_add},
                {"-", op_sub},
                {"*", op_mul},
                {"/", op_div},
                {"%", op_mod},
                {NULL, NULL}
        };
        int i;

        i = 0;

        while (i < 5)
        {
                if (*ops[i].op == *s && s[1] == 0)
                {
                        return (ops[i].f);
                }
                i++;
        }
        printf("Error\n");
        exit(99);

}
