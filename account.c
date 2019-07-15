#include "account.h"


void add_account(Account* account_list, int nb_compte, t_account *type_list, int type_size){
  int id_client=NULL;
  char name_account[15];
  printf("Veuillez rentrer les information suivante:\n");
  printf("id du client?\n");
  scanf("%d", &id_client);
  printf("type de compte?\n");
  scanf("%s", &name_account);
  account_list[nb_compte].id_account = nb_compte;
  account_list[nb_compte].id_client = id_client;
  account_list[nb_compte].solde = 0;
  for(int i = 0; i<type_size; i++){
    if(strcmp(name_account, type_list[i].name) == 0){
      account_list[nb_compte].type = type_list[i];
      break;
    }
  }
  return;
}

void del_account(Account* account_list, int nb_compte){
  int id = NULL;
  printf("Veuillez rentrer l'id du compte\n");
  scanf("%d", &id);
  for(int i = 0; i<nb_compte; i++){
    if(account_list[i].id_account == id){
      account_list[i].id_account = -1;
      break;
    }
  }
  return;
}

void show_account(Account* account_list, int nb_compte){
  printf("Veuillez rentrer l'id du client:\n");
  int id = NULL;
  scanf("%d", &id);
  for(int i = 0; i<nb_compte; i++){
    if(account_list[i].id_account == id){
      printf("ID: %d",account_list[i].id_account);
      printf("Solde: %d", account_list[i].solde);
      printf("taux: %d", account_list[i].type.taux);
      printf("Duree: %d", account_list[i].type.time);
    }
  }
  return;
}
