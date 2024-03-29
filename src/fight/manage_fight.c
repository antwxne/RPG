/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_fight
*/

#include "main.h"
#include "game.h"
#include "fight.h"
#include "textures.h"

static void has_won(game_t *game, int name, int def, int atk)
{
    int won = fight(game, name, def, atk);

    if (won == 1) {
        sfMusic_stop(game->musics[FIGHT_MUSIC]);
        sfMusic_play(game->musics[GAME_MUSIC]);
        game->player.stat[LVL_PLAYER] += 1;
        game->player.stat[DEF_PLAYER] += 30;
        game->player.stat[ATK_PLAYER] += 36;
        game->view = MAP;
    }
    if (won == 2) {
        sfMusic_stop(game->musics[FIGHT_MUSIC]);
        sfMusic_play(game->musics[DEAD_MUSIC]);
        game->view = END_DIED;
    }
}

void manage_fight(game_t *game)
{
    if (game->view == FIGHT_1)
        has_won(game, EN_1, PIGS_DEF, 180);
    if (game->view == FIGHT_2)
        has_won(game, SHEEP, SHEEP_DEF, 190);
    if (game->view == FIGHT_3)
        has_won(game, MERMS, MERMS_DEF, 200);
}
