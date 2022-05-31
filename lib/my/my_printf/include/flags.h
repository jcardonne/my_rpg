/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** arg_type
*/

#ifndef FLAGS_H_
    #define FLAGS_H_

    #include "my_printf.h"

    #define F_POS_LEFT_JUSTIFY 0
    #define F_POS_ZERO_PADDED 1
    #define F_POS_SHOW_POSITIVE 2
    #define F_POS_BLANK_POSITIVE 3
    #define F_POS_PREFIX 4

    static const char FLAG_LIST[] = "-0+ #\0";

#endif /* !FLAGS_H_ */
