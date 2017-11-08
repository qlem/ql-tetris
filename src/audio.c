//
// Created by qlem on 02/11/17.
//

#include "../inc/tetris.h"

void        free_audio(t_tetris *tetris)
{
    int     i;

    i = -1;
    Mix_FreeMusic(tetris->audio->music);
    while (++i < NB_SAMPLES)
        Mix_FreeChunk(tetris->audio->sounds[i]);
    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();
}

int         load_sounds(t_tetris *tetris)
{
    tetris->audio->sounds[0] = Mix_LoadWAV("sounds/win.wav");
    if (tetris->audio->sounds[0] == NULL) {
        printf("Error loading win sound\n");
    }

    tetris->audio->sounds[1] = Mix_LoadWAV("sounds/lose.wav");
    if (tetris->audio->sounds[1] == NULL) {
        printf("Error loading lose sound\n");
    }

    tetris->audio->sounds[2] = Mix_LoadWAV("sounds/select.wav");
    if (tetris->audio->sounds[2] == NULL) {
        printf("Error loading select sound\n");
    }

    tetris->audio->sounds[3] = Mix_LoadWAV("sounds/start.wav");
    if (tetris->audio->sounds[3] == NULL) {
        printf("Error loading start sound\n");
    }

    tetris->audio->sounds[4] = Mix_LoadWAV("sounds/line.wav");
    if (tetris->audio->sounds[4] == NULL) {
        printf("Error loading remove line sound\n");
    }

    tetris->audio->music = Mix_LoadMUS("sounds/music.mp3");
    if (tetris->audio->music == NULL) {
        printf("Error loading music\n");
    }

    return (0);
}

int         init_audio(t_tetris *tetris)
{
    t_audio     *audio;

    audio = malloc(sizeof(t_audio));
    if (audio == NULL)
        return (1);
    tetris->audio = audio;
    tetris->audio->active_music = true;


    if (SDL_Init(SDL_INIT_AUDIO) != 0)
    {
        printf("Error SDL audio initialization\n");
        return (1);
    }

    Mix_Init(MIX_INIT_MP3);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Error Mix_OpenAudio\n");
        return (1);
    }

    load_sounds(tetris);

    Mix_AllocateChannels(8);
    Mix_Volume(-1 , MIX_MAX_VOLUME / 2);

    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);

    return (0);
}