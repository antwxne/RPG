/*
** EPITECH PROJECT, 2020
** fight
** File description:
** init
*/
#include <stdlib.h>
#include <stdio.h>
#include "fight.h"
#include "game.h"

static const int nbr_enn = 3;

int init_ennemies(rectangle_t *rect)
{
    if ((rect->life_ennemie = malloc(sizeof(int) * nbr_enn)) == NULL)
        return 1;
    rect->def_ennemie = malloc(sizeof(int) * nbr_enn);
    for (int i = 0; i <= 2; i++)
        rect->life_ennemie[i] = 400;
    rect->def_ennemie[MERMS_DEF] = 50;
    rect->def_ennemie[SHEEP_DEF] = 40;
    rect->def_ennemie[PIGS_DEF] = 60;
    return 0;
}

int initia_fight(rectangle_t *rect)
{
    init_rectangle(rect);
    rect->etat = true;
    rect->god = true;
    rect->consequence = true;
    rect->life_clock = sfClock_create();
    rect->message = 0;
    rect->battle_status = 0;
    init_ennemies(rect);
    return 0;
}