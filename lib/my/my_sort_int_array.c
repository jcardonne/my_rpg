/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** Sort an array
*/

static void switch_array_member(int * array, int index_o, int index_s)
{
    int temp = 0;

    temp = array[index_o];
    array[index_o] = array[index_s];
    array[index_s] = temp;
}

void my_sort_int_array(int * array, int size)
{
    for (int a = 0; a < size - 1; a++) {
        for (int i = 0; i < size - 1; i++) {
            array[i] > array[i + 1] ? switch_array_member(array, i, i + 1) : i;
        }
    }
}
