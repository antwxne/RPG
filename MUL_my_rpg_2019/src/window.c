/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** window
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "game.h"

static void handle_window_event(sfEvent event, sfRenderWindow *window)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
}

static void display_window(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

int show_window(game_t *game)
{
    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        handle_window_event(game->event, game->window);
        display_window(game->window);
    }
    sfRenderWindow_destroy(game->window);
    return (0);
}
