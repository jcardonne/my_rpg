/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** create_object
*/

#include "object.h"

object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)())
{
    object_t *object = malloc(sizeof(object_t));
    object->id = id;
    object->data = data;
    object->handler = handler;
    object->draw = draw;
    return object;
}
