#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_all(Account *account_list, int nb_compte);
void show_type(Account *account_list, int nb_compte, int type_size, t_account *type_list);
void export_data(Account *account_list, int nb_compte, Client *list_client);
void import_data();
