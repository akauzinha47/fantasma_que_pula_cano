#ifndef STRUCTS
#define STRUCTS

#include <string.h>
#include <stdio.h>

typedef struct {
    int x;
    int y;

} Pipe;

typedef struct {
    char name[6];
    int score;

} Player;

Pipe construct_pipe()
{
    Pipe newpipe;
    newpipe.x = 0;
    newpipe.y = 0;

    return newpipe;
}

Player construct_player(char name[6])
{
    Player newplayer;

    strcpy(newplayer.name, name);
    newplayer.score = 0;

    return newplayer;
}

#endif // !STRCTS