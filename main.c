#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "account.h"

void menu_nouvel_account(Client* client_list, int* t_client, Account* account_list, int* t_account){
  
}

void menu_account(Client* client_list, int* t_client, Account* account_list, int* t_account){
  printf("##########  Account  ##########\n");
  int out = 0;
  int reponse;
  while(out == 0){
    printf("Veuillez choisir une option:\n");
    printf("\t1) Ajouter un compte\n");
    printf("\t2) Consultation de compte\n");
    printf("\t3) Fermeture d'un compte\n");
    printf("\t0) Retour menu précédent\n");
    scanf("%d", &reponse);
    switch(reponse){
      case 1:
        menu_nouvel_account(client_list, t_client, account_list, t_account);
        break;
      case 2:
        menu_consultation_account(client_list, t_client, account_list, t_account);
        break;
      case 3:
        menu_del_account(client_list, t_client, account_list, t_account);
        break;
      case 0:
        menu();
        break;
      default:
        printf("Veuillez rentrer une valeur vide\n");
    }
  }
}


void menu_client(Client * client_list, int* t_client, Account* account_list, int* t_account){
  printf("##########  Client  ##########\n");
  int out = 0;
  int reponse;
  while(out == 0){
    printf("Veuillez choisir une option:\n");
    printf("\t1) Ajouter un client\n");
    printf("\t2) Modifier un client\n");
    printf("\t3) Supprimer un client\n");
    printf("\t4) Rechercher un client\n");
    printf("\t0) Retour menu précédent\n");
    scanf("%d", &reponse);
    switch(reponse){
      case 1:
        menu_nouveau_client();
        break;
      case 2:
        menu_modif_client();
        break;
      case 3:
        menu_del_client();
        break;
      case 4:
        menu_search_client();
        break;
      case 0:
        menu();
        break;
      default:
        printf("Veuillez rentrer une valeur valide\n");
        break;
    }
  }
}


void menu(Client* client_list, int* t_client, Account* account_list, int* t_account){
  int out=0;
  int reponse;
  printf("Bienvenue à CBanque\n");
  while(out == 0){
    printf("Veuillez choisir une option:\n");
    printf("\t1) Client\n");
    printf("\t2) Account\n");
    printf("\t0) Sortir\n");
    scanf("%d", &reponse);
    switch(reponse){
      case 1:
        menu_client(client_list, t_client, account_list, t_account);
        break;
      case 2:
        menu_acount(client_list, t_client, account_list, t_account);
        break;
      case 3512:
        menu_admin(client_list, t_client, account_list, t_account);
        break;
      case 0:
        printf("Merci d'avoir utilisé notre logiciel, bonne journée\n");
        out = 1;
        break;
      default:
        printf("Erreur de saisie, veuillez rentrer un nombre valide\n");
    }
  }
}

int main(){
  Client* client_list = (Client*) malloc(sizeof(Client) * 20);
  Account* account_list = (Account*) malloc(sizeof(Account) * 20);
  t_client = 20;
  t_account = 20;
  menu(client_list,&t_client, account_list,&t_account);
}

