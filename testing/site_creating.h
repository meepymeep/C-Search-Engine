#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _concat_site_name_com_(char site_name[50], struct site* _site) {
    char* old_site_name = malloc(10 * sizeof(char*));
    char com[6];
    char* https = malloc(10 * sizeof(char*));

    strcpy(https, "https://www.");
    strcpy(old_site_name, site_name);
    strcpy(com, ".com/");

    strcat(https, old_site_name);
    strcat(https, com);

    strcpy(_site -> site_name_com_concat, https);

    /* V without these two lines of code the code won't work */
    free(old_site_name);
    free(https);
}

void set_site_name(struct site* _site, char site_name[50], char site_name2[50]) {

    if (strcmp(_site -> site_name, site_name) == 0) {
        strcpy(_site -> site_name, site_name2);
        _concat_site_name_com_(_site -> site_name, _site);
    }

    else {
        printf("Cannot find site: %s\n", site_name);
    }
}

    /* Example of add_content: "Welcome to roblox! We hope you enjoy." */
void add_content(int* index, struct site _sites[], char content[50]);

void create_site(int* index, long int* id, char site_name[50], char content[197], struct site _sites[]) {
    if (_sites[*index].site_name == "" || _sites[*index].site_id == 0) {
        strcpy(_sites[*index].site_name, site_name);
        _concat_site_name_com_(_sites[*index].site_name, &_sites[*index]);

        _sites[*index].site_id = *id;
        *id = *id + 1;
        add_content(index, _sites, content);

        *index = *index + 1;
        printf("Added site successfully!\n");
    }

    else {
        // do nothing //
    }
}

void delete_site(int* index, char site_name[50], struct site sites[]) {
    if (site_name != "" || sites[*index].site_name != "") {
        if (strcmp(site_name, sites[*index].site_name) == 0) {
            strcpy(sites[*index].site_name, "");
            strcpy(sites[*index].site_name_com_concat, "");
            strcpy(sites[*index].site_content, "");

            sites[*index].site_id = 0;
            sites[*index].site_visits = 0;

            printf("Deleted site: %s\n", site_name);

            *index = *index - 1;
        }

        else {
            printf("Invalid site: %s\n", site_name);
        }
    }

    else {
        printf("Cannot delete a site with no name!\n");
    }
}

void add_content(int* index, struct site _sites[], char content[197]) {
    if (content != "") {
        strcpy(_sites[*index].site_content, content);
    }

    else {
        printf("Cannot add empty content to site!\n");
    }
}