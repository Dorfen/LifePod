/*
** PROJECT, 2019
** LifePod
** File description:
** source/event.c
*/

#include "lifepod.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

button_t *parse_button(char const * const buffer)
{
    button_t *ret = alloc_button();
    char **tab = parse_str(buffer, ":", false);
    short system = 0;

    if (ret == NULL || tab == NULL || buffer == NULL)
        return NULL;
    system = atoi(tab[1]);
    if (system <= 0 || system > 8)
        return ret;
    else
        ret->system = system;
    ret->msg = strdup(tab[0]);
    ret->dmg = atoi(tab[2]);
    ret->max_mult = atoi(tab[3]);
    free_tab(tab);
    return ret;
}

event_t *parse_event(char const *buffer)
{
    event_t *ret = alloc_event();
    unsigned int i = 0;
    char **tab = parse_str(buffer, "\n", false);

    if (buffer == NULL || tab == NULL || my_tablen(tab) < 3)
        return NULL;
    ret->nb_buttons = atoi(tab[0]);
    ret->button = malloc(sizeof(button_t *) * (ret->nb_buttons + 1));
    if (ret->button != NULL) {
        ret->button[ret->nb_buttons] = NULL;
        for (; i < ret->nb_buttons; i++)
            ret->button[i] = parse_button(tab[i + 1]);
    }
    ret->tab = my_tabdup(tab + i + 1);
    if (ret->tab == NULL || ret->button == NULL)
        return NULL;
    free_tab(tab);
    return ret;
}

static int filter_filter(const struct dirent *name)
{
    if (strcmp(name->d_name, ".") == 0 || strcmp(name->d_name, " ..") == 0)
        return (0);
    if (name->d_type == DT_REG)
        return (1);
    return (0);
}

event_t *read_event(const struct dirent *namelist)
{
    event_t *ret = NULL;
    struct stat statbuf;
    char *filename = NULL;
    char *buffer = NULL;
    FILE *file = NULL;

    asprintf(&filename, "%s%s", EVENT_DIR, namelist->d_name);
    file = fopen(filename, "r");
    if (file == NULL)
        return (NULL);
    stat(filename, &statbuf);
    buffer = malloc(sizeof(char) * (statbuf.st_size + 1));
    buffer[statbuf.st_size] = '\0';
    fread(buffer, statbuf.st_size, 1, file);
    ret = parse_event(buffer);
    free(filename);
    free(buffer);
    fclose(file);
    return (ret);
}

event_t **load_all_event(void)
{
    event_t **ret = NULL;
    int fail = 0;
    struct dirent **namelist = NULL;
    int n = scandir(EVENT_DIR, &namelist, filter_filter, alphasort);

    if (n == -1)
        return (NULL);
    ret = malloc(sizeof(event_t *) * (n + 1));
    ret[n] = NULL;
    for (int i = 0; i < n; i++) {
        ret[i - fail] = read_event(namelist[i]);
        if (ret[i - fail] == NULL)
            fail++;
        free(namelist[i]);
    }
    free(namelist);
    return (ret);
}
