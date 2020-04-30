/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_menu_pause
*/

#include "game.h"
#include "main.h"
#include "pause_menu.h"

static const sfColor transparent_grey = {255, 255, 255, 60};

static void change_action(game_t *game, int action)
{
    if (action == P_RESUME)
        game->view = MAP;
    if (action == P_QUIT)
        sfRenderWindow_close(game->window);
    if (action == P_MAIN_MENU)
        game->view = MENU_S;
    if (action == P_SAVE)
        manage_save(game);
}

static void overlay_button(button_display_t *ptr_button, game_t *game,
    int action)
{
    static bool clic = false;

    sfRectangleShape_setOutlineColor(ptr_button->shape, sfWhite);
    if (game->event.type == sfEvtMouseButtonPressed) {
        clic = true;
        sfRectangleShape_setFillColor(ptr_button->shape, transparent_grey);
    }
    if (game->event.type == sfEvtMouseButtonReleased && clic == true)
        change_action(game, action);
}

static void reset_overlay(button_display_t *ptr_button)
{
    sfRectangleShape_setOutlineColor(ptr_button->shape, sfTransparent);
    sfRectangleShape_setFillColor(ptr_button->shape, sfTransparent);
}

void manage_pause_menu(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    for (unsigned int i = P_RESUME; i <= P_QUIT; i++) {
        if (sfIntRect_contains(&game->buttons[i].rect,
            pos.x, pos.y))
            overlay_button(&game->buttons[i], game, i);
        else
            reset_overlay(&game->buttons[i]);
    }
}