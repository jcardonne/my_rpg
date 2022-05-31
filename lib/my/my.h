/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    void my_putchar(char c);
    char *my_strstr(char *str, char const *to_find);
    char *my_strdup(char const *src);
    int my_isneg(int nb);
    int my_strcmp(char const *s1, char const *s2);
    int my_put_nbr(int nb);
    int my_strncmp(char const *s1, char const *s2, int n);
    void my_swap(int *a, int *b);
    char *my_strupcase(char *str);
    int my_putstr(char const *str);
    void my_put_str_arr(char **arr);
    int my_compute_power_rec(int nb, int p);
    char *my_strlowcase(char *str);
    int my_strlen(char const *str);
    char *my_strcapitalize(char *str);
    int my_getnbr(char const *str);
    int my_str_isalpha(char const *str);
    void my_sort_int_array(int *tab, int size);
    int my_str_isnum(char const *str);
    int my_compute_power_rec(int nb, int power);
    int my_str_islower(char const *str);
    int my_compute_square_root(int nb);
    int my_str_isupper(char const *str);
    int my_is_prime(int nb);
    int my_str_isprintable(char const *str);
    int my_find_prime_sup(int nb);
    int my_showstr(char const *str);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strcat(char *dest, char const *src);
    char *my_revstr(char *str);
    char *my_strncat(char *dest, char const *src, int nb);
    int my_char_isprintable(char const str);
    int my_putnbr_base(int nbr, char const *base);
    char *my_to_lowercase(const char *str);
    int my_arr_size(char **arr);
    char **my_rev_str_list(char **input);
    void my_sort_str_array(char **array);
    int my_contain_str_arr(char **arr, char *to_find);
    int my_put_err(char const * str);
    void my_putstr_two(char const *one, char const *second);
    char *my_get_nbr_base(long nbr, char *base);
    int my_put_err_two(char const * str, char const *str_two);
    int my_nbrlen(int number);
    char *my_int_to_strnum(int nb);
    int my_str_is_nbr(char *str);
    char *re_malloc(char *str);
    int my_printf(const char *format, ...);
    int my_fprintf(int fd, const char *format, ...);
    int my_putstr_stream(int fd, char const *str);
    int power(int nb, int power);

#endif
