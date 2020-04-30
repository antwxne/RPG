/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_map
*/

#include "textures.h"
#include "game.h"

void inventory(object_t *object)
{
    sfVector2f position = {10, 850};
    object[0].position = position;
    sfSprite_setPosition(object[0].sprite, position);
}

static void display_sprite(sfRenderWindow *window, object_t *obj)
{
    for (unsigned int i = 0; i < number_objects; i++)
        if (obj[i].position.x > -100 && obj[i].position.x < window_size_x + 100
        && obj[i].position.y > -100 && obj[i].position.y < window_size_y + 100)
            sfRenderWindow_drawSprite(window, obj[i].sprite, NULL);
}

void display_map(sfRenderWindow *window, object_t **objects)
{
    display_sprite(window, objects[PLAYER]);
    display_sprite(window, objects[ENEMI]);
    display_sprite(window, objects[HOUSE]);
    inventory(objects[INVENTORY_]);
    display_sprite(window, objects[INVENTORY_]);
}