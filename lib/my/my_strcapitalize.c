/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    int min_check = 0;
    int symbol_check = 0;
    int l_bf_chck = 0;
    int u_bf_chck = 0;
    char temp;

    for (int i = 0; str[i] != '\0'; i++) {
        temp = str[i - 1];
        min_check = str[i] >= 97 && str[i] <= 122;
        l_bf_chck = temp >= 97 && temp <= 122;
        u_bf_chck = temp >= 65 && temp <= 90;
        symbol_check = (temp < 48 || temp > 57) && (!u_bf_chck && !l_bf_chck);

        if (min_check && (i == 0 || (temp == ' ' || symbol_check)))
            str[i] = str[i] - 32;
        else if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
    }
    return str;
}
