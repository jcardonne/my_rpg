/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** create
*/

#include "object.h"
#include "region.h"

teleporter_t *create_teleporter_data(region_t *dest_region, sfFloatRect area)
{
    teleporter_t *teleporter = malloc(sizeof(teleporter_t));
    teleporter->area = area;
    teleporter->dest_region = dest_region;
    return teleporter;
}
