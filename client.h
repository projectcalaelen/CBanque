#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_CHAR 15

typedef struct{
  int id_client;
  char lastname[MAX_CHAR];
  char firstname[MAX_CHAR];
  char profession[MAX_CHAR];
  int tel;
} Client;

void add_client(Client *client_list, int nb_client);
void edit_client(Client *client_list, int nb_client);
void del_client(Client * client_list, int nb_client);
void search_client(Client *client_list, int nb_client);
void show_client(Client *client_list, int nb_client);
