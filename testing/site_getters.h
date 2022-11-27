#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    /* Open a site of choice */
void open_site(struct site _sites[], int* index, char site_name[50]) {
    if (site_name != "" || _sites[*index].site_name != "") {

        if (strcmp(site_name, _sites[*index].site_name) == 0) {
            printf("Site title: %s\n-----------", _sites[*index].site_name_com_concat);
            for (size_t i = 0; i < strlen(_sites[*index].site_name_com_concat); i++) {
                printf("-");
            }

            printf("-\n%s\n", _sites[*index].site_content);
            _sites[*index].site_visits++;

            printf("\nSite visits: %i\nSite ID: %i\n", _sites[*index].site_visits,
            _sites[*index].site_id);
        }

        else {
            printf("Invalid site: %s.\n", site_name);
        }
    }

    else {
        printf("Cannot open an empty site.");
    }
}

    /* Prints all sites */
void get_all_sites(struct site _sites[]) {
    if (_sites[0].site_id == 0 || _sites[0].site_name == "") {
        printf("There are no sites to print out.\n");
    }

    else {
        for (size_t i = 0; _sites[i].site_id != 0; i++) {
            printf("%d: %s\n", i + 1, _sites[i].site_name_com_concat);
        }
    }
}