#include <math.h>
#include "input.h"
#include "map.h"

void update_player(Player *player, const Uint8 *state) {
    const double moveSpeed = 0.1;
    const double rotSpeed = 0.05;

    // Mouvement avant/arrière
    if (state[SDL_SCANCODE_W]) {
        double newX = player->posX + player->dirX * moveSpeed;
        double newY = player->posY + player->dirY * moveSpeed;
        if (worldMap[(int)newY][(int)newX] == 0) {
            player->posX = newX;
            player->posY = newY;
        }
    }
    if (state[SDL_SCANCODE_S]) {
        double newX = player->posX - player->dirX * moveSpeed;
        double newY = player->posY - player->dirY * moveSpeed;
        if (worldMap[(int)newY][(int)newX] == 0) {
            player->posX = newX;
            player->posY = newY;
        }
    }

    // Rotation gauche
    if (state[SDL_SCANCODE_A]) {
        double oldDirX = player->dirX;
        player->dirX = player->dirX * cos(rotSpeed) - player->dirY * sin(rotSpeed);
        player->dirY = oldDirX * sin(rotSpeed) + player->dirY * cos(rotSpeed);
        double oldPlaneX = player->planeX;
        player->planeX = player->planeX * cos(rotSpeed) - player->planeY * sin(rotSpeed);
        player->planeY = oldPlaneX * sin(rotSpeed) + player->planeY * cos(rotSpeed);
    }
    // Rotation droite
    if (state[SDL_SCANCODE_D]) {
        double oldDirX = player->dirX;
        player->dirX = player->dirX * cos(-rotSpeed) - player->dirY * sin(-rotSpeed);
        player->dirY = oldDirX * sin(-rotSpeed) + player->dirY * cos(-rotSpeed);
        double oldPlaneX = player->planeX;
        player->planeX = player->planeX * cos(-rotSpeed) - player->planeY * sin(-rotSpeed);
        player->planeY = oldPlaneX * sin(-rotSpeed) + player->planeY * cos(-rotSpeed);
    }
}