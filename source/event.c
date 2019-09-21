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

event_t *parse_event(char const *buffer)
{
    event_t *ret = alloc_event();
    char **tab = parse_str(buffer, ":", false);

    if (tab == NULL || ret == NULL || my_tablen(tab) < 4)
        return NULL;
    ret->system = my_atoi(tab[0]);
    ret->dmg = my_atoi(tab[1]);
    ret->max_mult = my_atoi(tab[2]);
    ret->msg = my_strdup(tab[3]);
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

    asprintf(&filename, "./event_data/%s", namelist->d_name);
    file = fopen(filename, "r");
    if (file == NULL)
        return (NULL);
    stat(filename, &statbuf);
    buffer = malloc(sizeof(char) * (statbuf.st_size + 1));
    buffer[statbuf.st_size] = '\0';
    fread(buffer, statbuf.st_size, 1, file);
    ret = parse_event(buffer);
    free(filename);
    fclose(file);
    return (ret);
}

event_t **load_all_event(void)
{
    event_t **ret = NULL;
    int fail = 0;
    struct dirent **namelist = NULL;
    int n = scandir("./event_data/", &namelist, filter_filter, alphasort);

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
