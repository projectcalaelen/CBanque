#include <stdio.h>
#include <stdlib.h>

void depot(Account *account_list, int nb_compte){
  int id = NULL, int depot = NULL;
  printf("Veuillez rentrer le compte à crediter:\n");
  scanf("%d", &id);
  printf("Veuillez rentrer le montant à crediter:\n");
  scanf("%d", &depot);
  for(int i = 0; i<nb_compte; i++){
    if(account_list[i]->id_account == id){
      account_list[i]->solde += depot + (depot*account_list[i]->type.taux/100);
      break;
    }
  }
  return;
}

void retrait(Account *account_list, int nb_compte){
  int id = NULL, int retrait = NULL;
  printf("Veuillez rentrer le compte à dediter:\n");
  scanf("%d", &id);
  printf("Veuillez rentrer le montant à dediter:\n");
  scanf("%d", &retrait);
  for(int i = 0; i<nb_compte; i++){
    if(account_list[i]->id_account == id){
      account_list[i]->solde -= retrait);
      break;
    }
  }
  return;
}

void virement(Account *account_list, int nb_compte){
  int id_out = NULL, id_in = NULL, total = 0, montant = NULL;
  printf("Veuillez rentrer le compte à dediter:\n");
  scanf("%d", &id_out);
  printf("Veuillez rentrer le compte à crediter:\n");
  scanf("%d", &id_in);
  printf("Veuillez rentrer le montant à virer:\n");
  scanf("%d", &montant);
  for(int i = 0; i< nb_compte; i++){
    if(account_list[i]->id_account == id_in){
      account_list[i]->solde += montant;
      total++;
    }else if(account_list[i]->id_account == id_out){
      account_list[i]->solde -= montant;
      total++;
    }
    if(total == 2){
      break;
    }
  }
  return;
}

