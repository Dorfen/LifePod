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

int filter_filter(const struct dirent *name)
{
    if (strcmp(name->d_name, ".") == 0 || strcmp(name->d_name, " ..") == 0)
        return (0);
    if (name->d_type == DT_REG)
        return (1);
    return (0);
}

event_t *add_event(const int n, const struct dirent *namelist)
{
    event_t *ret = alloc_event();
    struct stat statbuf;
    char *filename = NULL;
    char *buffer = NULL;
    FILE *file = NULL;

    asprintf(&filename, "./event_data/%s", namelist->d_name);
    file = fopen(filename, "r");
    if (file == NULL)
        return (NULL);
    stat(filename, &statbuf);
    fread(buffer, statbuf.st_size, 1, file);
    free(filename);
    fclose(file);
    return (ret);
}

event_t **load_all_event(void)
{
    event_t **ret = NULL;
    struct dirent **namelist = NULL;
    int n = scandir("./event_data/", &namelist, filter_filter, alphasort);

    if (n == -1)
        return (NULL);
    ret = malloc(sizeof(event_t *) * n);
    while (n--) {
        printf("%s\n", namelist[n]->d_name);
        ret[n] = add_event(n, namelist[n]);
        free(namelist[n]);
    }
    return (ret);
}
