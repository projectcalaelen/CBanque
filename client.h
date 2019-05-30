#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 15

#ifndef __Client__
#define __Client__

typedef struct{
  int id_client;
  char lastname[MAX_CHAR];
  char firstname[MAX_CHAR];
  char profession[MAX_CHAR];
  int tel;
} Client;

#endif

Client add_client(int id_client, char const* lastname, char constù firstname, char const* profession, int tel);
void edit_client(Client* self, int field, char const* char_val, int int_val);
void delete_client(Client* self);
void search_client(Client** list_client, int t_tab, char* string, int t_string);
