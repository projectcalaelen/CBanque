#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "client.h"
#include "account.h"
#include "operation.h"
#include "admin.h"

#define MAX_CHAR 15

void menu_admin(Account *account_list, int nb_compte, t_account *type_list, int type_size, Client *client_list);
void menu_operation(Account *account_list, int nb_compte);
void menu_client(Client *Client_list, int *nb_client, int *nb_max_client);
void menu_compte(Account *account_list, int *nb_compte, int *nb_max_compte, t_account *type_list, int type_size);
int main();
