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

static event_t *fill_event(char **value, char **msg, char **button)
{
    event_t *ret = alloc_event();

    if (value == NULL || msg == NULL || button == NULL)
        return NULL;
    for (int i = 0; i < 3; i++)
        if (my_str_isnum(value[i]) == 0)
            return NULL;
    ret->system = my_atoi(value[0]);
    ret->dmg = my_atoi(value[1]);
    ret->max_mult = my_atoi(value[2]);
    ret->tab = msg;
    ret->button = button;
    return ret;
}

event_t *parse_event(char const *buffer)
{
    char **tab = parse_str(buffer, "\n", false);
    char **value = NULL;
    char **msg = NULL;
    char **button = NULL;

    if (buffer == NULL || tab == NULL || my_tablen((char const * const*)tab) < 3)
        return NULL;
    value = parse_str(tab[0], ":", false);
    button = parse_str(tab[1], ":", false);
    msg  = my_tabdup((char const *const *)tab);
    if (value == NULL || value == NULL || button == NULL)
        return NULL;
    free_tab(tab);
    return fill_event(value, msg, button);
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
