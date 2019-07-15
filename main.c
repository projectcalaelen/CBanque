#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 15

typedef struct{
    int id_client;
    char lastname[MAX_CHAR];
    char firstname[MAX_CHAR];
    char profession[MAX_CHAR];
    int tel;
} Client;

typedef struct{
  char name[MAX_CHAR];
  int taux;
} t_account;

typedef struct{
  int id_account;
  int id_client;
  int solde;
  int time;
  t_account type;
} Account;


void menu_admin(){
  printf("\n\nMenu admin\n");
  int out = 0;
  int choix = 10;
  while(out == 0){
    printf("Veullez faire un choix:\n");
    printf("1. Importer données\n");
    printf("2. Exporter données\n");
    printf("0. Menu precedent\n");
    scanf("%d", &choix);
    switch(choix){
      case 1:
        import();
        break;
      case 2:
        export();
        break;
      case 0:
        return;
        break;
      default:
        printf("Veullez choisir une option valide\n");
        break;
    }
  }
}


void menu_operation(Account *account_list, int nb_compte){
  printf("\n\nMenu Operation\n");
  int out = 0;
  int choix = 10;
  while(out == 0){
    printf("Veullez faire un choix:\n");
    printf("1. Faire un depot\n");
    printf("2. Faire un retrait\n");
    printf("3. Faire un virement\n");
    printf("0. Menu precedent\n");
    scanf("%d", &choix);
    switch(choix){
      case 1:
        depot(account_list);
        break;
      case 2:
        retrait(account_list);
        break;
      case 3:
        virement(account_list);
        break;
      case 0:
        return;
        break;
      default:
        printf("Veuillez saisir une option valide\n");
        break;
    }
  }
}


void menu_client(Client *client_list, int *nb_client, int *nb_max_client){
  printf("\n\nMenu Client\n");
  int out = 0;
  int choix = 10;
  while(out == 0){
    printf("Veuillez faire un choix:\n");
    printf("1. Ajouter un nouveau client\n");
    printf("2. Supprimer un client\n");
    printf("3. Consulter un client\n");
    printf("0. Revenir au menu principal");
    scanf("%d", &choix);
    switch(choix){
      case 1:
        add_client(client_list, &nb_client);
        nb_client++;
        break;
      case 2:
        del_client(client_list, &nb_client);
        nb_client--;
        break;
      case 3:
        search_client(client_list, nb_client);
        break;
      case 0:
        return;
        break;
      default:
        printf("Veuillez rentrez une option valide\n");
    }
    if(*nb_client == *nb_max_client){
      *nb_max_client *= 2;
      extend_client(client_list, *nb_max_client);
    }
  }
}


void menu_compte(Account *account_list, int* nb_compte, int* nb_max_compte){
  int out = 0;
  int choix = 0;
  printf("Menu Compte\n");
  while(out == 0){
    printf("Veuillez choisir une option:\n");
    printf("1. Creer un compte\n");
    printf("2. Supprimer un compte\n");
    printf("3. Gerer un compte\n");
    printf("0. Revenir au menu précedent\n");
    scanf("%d", &choix);
    switch(choix){
      case 1:
        add_account(account_list, &nb_compte);
        *nb_compte++;
        break;
      case 2:
        del_account(account_list, &nb_compte);
        nb_compte--;
        break;
      case 3:
        manage_account(account_list, nb_compte);
        break;
      case 0:
        return;
        break;
      default:
        printf("Veullez rentrer une option valide\n");
        break;
    }
    if(*nb_compte == *nb_max_compte){
      *nb_max_compte *= 2;
      extend_account(account_list, *nb_max_compte);
    }
  }
}


int main(){
  Client *client_list = NULL;
  client_list = malloc(100 * sizeof(Client));
  Account *account_list = NULL;
  account_list = malloc(100 * sizeof(Account));
  if(client_list == NULL || account_list == NULL){
    printf("Erreur Allocation mémoire\n");
    return EXIT_FAILURE;
  }
  int nb_compte = 0;
  int nb_client = 0;
  int nb_max_client = 100;
  int nb_max_compte = 100;
  int out = 0;
  int choix = 10;
  printf("Bienvenue chez CBanque\nOutil de gestion de banque\n");
  while(out == 0){
    printf("Veuillez selectionner une option:\n");
    printf("1. Gestion Client\n");
    printf("2. Gestion Compte\n");
    printf("3. Gestion des opérations\n");
    printf("0. Quittez CBanque\n");
    scanf("%d", &choix);
    switch(choix){
      case 1:
        menu_client(client_list, &nb_client, &nb_max_client);
        break;
      case 2:
        menu_compte(account_list, &nb_compte, &nb_max_compte);
        break;
      case 3:
        menu_operation(account_list, nb_compte);
        break;
      case 0:
        out = 1;
        break;
      case 3212:
        menu_admin();
        break;
      default:
        printf("Veuillez rentrer un option valide\n");
        break;
    }
  }
  printf("Merci d'avoir utilisez CBanque");
  return EXIT_SUCCESS;
}
