/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy
*/

#ifndef DESTROY_H_
#define DESTROY_H_

#include "game.h"
/**
 * @brief destroy all music loaded
 * @param game
 */
void destroy_music(game_t *game);
/**
 * @brief destroy all objects
 * @param game
 */
void destroy_objects(game_t *game);
/**
 * @brief destroy all buttons
 * @param game
 */
void destroy_button(game_t *game);
/**
 * @destroy all textures
 * @param game
 */
void destroy_texture(game_t *game);
/**
 * @brief destroy all dialogs
 * @param game
 */
void destroy_dia(game_t *game);
/**
 * @brief destroy buttons for fights
 * @param fight
 */
void free_fight(rectangle_t *fight);

#endif /* !DESTROY_H_ */
