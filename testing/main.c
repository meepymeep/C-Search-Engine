#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "site.h"
#include "site_creating.h"
#include "site_getters.h"

enum commands {
    Add = 1,
    Delete,
    Print_All,
    Open,
    Change_Name,
    Change_Option,
};

void list_of_cmds() {
    printf("*** Meeple Chrome Command List ***\n\n");

    printf("(1): Add a new site to the search engine\n");
    printf("(2): Delete a site of choice\n");
    printf("(3): Print all the sites\n");
    printf("(4): Open up a site\n");
    printf("(5): Change a sites name\n");
    printf("(6): Change search option\n\n");
}

int main(void) {

    struct site sites[1000];
    unsigned int index = 0;
    long int id = 1;

    unsigned int running = 1;

    unsigned int search_option; // 0 = command prompt, 1 = goes to google when searched

    option_selection:
    printf("Select search option: ");
    scanf("%i", &search_option);

    do {

        option_selection2:

        if (search_option == 0) {
            // Command prompt search engine //
            list_of_cmds();
            printf("Enter in a command: ");

            int command; scanf("%i", &command);

            char site_name[50];
            char site_name2[50];
            char site_content[197];
            
            switch(command) {
                case Add:
                    printf("Enter in a site name: ");
                    scanf("%s", site_name);

                    printf("Now enter in the site's content: ");
                    scanf("%s", site_content);

                    create_site(&index, &id, site_name, site_content, sites);
                    break;
                case Delete:
                    printf("Enter in the site name: ");
                    scanf("%s", site_name);

                    scanf("%i", &index);

                    delete_site(&index, site_name, sites);
                    break;
                case Print_All:
                    get_all_sites(sites);
                    break;
                case Open:
                    printf("Enter in the site name: ");
                    scanf("%s", site_name);

                    scanf("%i", &index);

                    open_site(sites, &index, site_name);
                    break;
                case Change_Name:
                    printf("Enter in old site name: ");
                    scanf("%s", site_name);
                    scanf("%i", &index);

                    printf("Enter in new one: ");
                    scanf("%s", site_name2);

                    set_site_name(&sites[index], site_name, site_name2);
                    break;
                case Change_Option:
                    goto option_selection;
                    break;
                case 999:
                    running = 0;
                    break;
            }
        }

        else if (search_option == 1) {
            printf("Work in progress\n");
            // This goes to google whenever you search something //
            break;
        }

        else {
            search_option = 0;
            goto option_selection2;
        }
    }

    while (running);
    return 0;
}