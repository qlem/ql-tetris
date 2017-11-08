
#include "../inc/tetris.h"

t_subm_color         *malloc_sub_menu(void)
{
    t_subm_color     *submenu;

    submenu = malloc(sizeof(t_subm_color));
    submenu->p_index = 0;
    submenu->nb_color = 7;
    submenu->tab_color[0].name = "color 1";
    submenu->tab_color[0].color = 1;
    submenu->tab_color[1].name = "color 2";
    submenu->tab_color[1].color = 2;
    submenu->tab_color[2].name = "color 3";
    submenu->tab_color[2].color = 3;
    submenu->tab_color[3].name = "color 4";
    submenu->tab_color[3].color = 4;
    submenu->tab_color[4].name = "color 5";
    submenu->tab_color[4].color = 5;
    submenu->tab_color[5].name = "color 6";
    submenu->tab_color[5].color = 6;
    submenu->tab_color[6].name = "color 7";
    submenu->tab_color[6].color = 7;
    return (submenu);
}

t_menu      *malloc_pause_menu(void)
{
    t_menu      *menu;

    menu = malloc(sizeof(t_menu));
    if (menu == NULL)
        return (NULL);
    menu->tab_elem[0].name = "Continue";
    menu->tab_elem[0].id = 0;
    menu->tab_elem[1].name = "Restart";
    menu->tab_elem[1].id = 1;
    menu->tab_elem[2].name = "Box color";
    menu->tab_elem[2].id = 2;
    menu->tab_elem[3].name = "Music";
    menu->tab_elem[3].id = 3;
    menu->tab_elem[4].name = "Quit";
    menu->tab_elem[4].id = 4;
    menu->nb_elem = 5;
    menu->p_index = 0;
    menu->subm_color = malloc_sub_menu();
    menu->opt_color = false;
    return (menu);
}