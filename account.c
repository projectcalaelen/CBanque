#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include <string.h>

typedef struct{
	char[] name;
	int taux;
} t_account;

typedef struct{
	int id_account;
	int id_client;
	float solde;
	int time;
  t_account type;
} Account;

Account add_account(int id_account, int id_client, float solde, int time, t_account type){
  Account new;
  new.id_account = id_account;
  new.id_client = id_client;
  new.solde = solde;
  new.time = time;
  strcpy(new.type.name, type.name);
  new.type.taux = type.taux;
  return &Account;
}

void del_account(Account self){
  self.id_account = -1;
}

void show_account(Account** list, int t_list, int id_client){
  for(int i=0; i<t_list; i++){
    if(list[i].id_client == id_client){
      rpr_account(list[i]);
    }
  }
}

void transfer(Account** list, int t_list, int id_sender, int id_recipient, float credit){
  for(int i=0; i<t_list; i++){
    if(list[i].id_account == id_sender){
      list[i].solde -= credit;
    }else if(list[i].id_account == id_recipient){
      list[i].solde += credit;
    }
  }
}

/**
 *
 *  TO DO
 */
void histo(){

}

void add_credit(Account **list, int t_list, int id_account, float credit){
  for(int i=0; i<t_list; i++){
    if(list[i].id_account == id_account){
      list[i].solde += credit*(1+list[i].type.taux;
    }
  }
}

void sub_credit(Account **list, int t_list, int id_account, float debit){
  for(int i=0; i<t_list; i++){
    if(list[i].id_account == id_account){
      list[i].solde -= debit;
    }
  }
}

void rpr_account(Accout* self){
  printf("#### Account n° %d ####\n", self.id_account);
  printf("\tsolde : %f\n", self.solde);
  printf("\ttime : %d\n", self.time);
  printf("\ttype : %s\n", self.type.name);
}
