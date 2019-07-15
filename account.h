#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char name[MAX_CHAR];
  int taux;
  int time;
} t_account;

typedef struct{
  int id_account;
  int id_client;
  int solde;
  int time;
  t_account type;
} Account;

void add_account(Account *account_list, int nb_compte);
void del_account(Account *account_list, int nb_compte);
void show_account(Account *account_list, int nb_compte);
