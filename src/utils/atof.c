/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** atof.c
*/

static void handle_before_dot(char arr, float *val, int *afterdot)
{
    if (arr == '.')
        *afterdot = *afterdot + 1;
    else
        *val = *val * 10.0 + (arr - '0');
}

float ratof(char *arr)
{
    float val = 0;
    int afterdot = 0;
    float scale = 1;
    int neg = 0;

    if (*arr == '-') {
        arr++;
        neg = 1;
    }
    while (*arr) {
        if (afterdot) {
            scale = scale / 10;
            val = val + (*arr - '0') * scale;
        } else
            handle_before_dot(*arr, &val, &afterdot);
        arr++;
    }
    val = (neg) ? -val : val;
    return val;
}
