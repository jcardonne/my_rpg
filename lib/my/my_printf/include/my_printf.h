/*
** EPITECH PROJECT, 2021
** my_printf.h
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <unistd.h>
    #include <stdlib.h>

    typedef struct printf_data_s {
        char *str;
        int prefix_len;
        int min_field_width;
        int precision;
        int is_nb;
        int active_flags[5];
    } printf_data_t;

    #define ABS(value) (value < 0 ? (value) * (-1) : (value))
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    #define MIN(a, b) ((a) < (b) ? (a) : (b))

    char get_sign_char(int is_neg, printf_data_t *data);
    char *my_strulong_base(unsigned long nbr, char *str, char const *base,
    int precision);
    char *my_strlong_base(long nbr, char *str, char const *base,
    int precision);
    char *my_struint_base(unsigned int nbr, char *str, char const *base,
    int precision);
    char *my_strint_base(int nbr, char *str, char const *base,
    int precision);
    char *my_addchar(char *src, char c);

#endif /* !MY_PRINTF_H_ */
