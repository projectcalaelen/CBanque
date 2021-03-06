#include "main.h"


void menu_admin(Account *account_list, int nb_compte, t_account *type_list, int type_size, Client *client_list){
  printf("\n\nMenu admin\n");
  int out = 0;
  int choix = 10;
  while(out == 0){
    printf("Veullez faire un choix:\n");
    printf("1. Importer données\n");
    printf("2. Exporter données\n");
    printf("3. Afficher la somme des montants de tous les comptes\n");
    printf("4. Afficher la somme des montants par type de comptes\n");
    printf("0. Menu precedent\n");
    scanf("%d", &choix);
    switch(choix){
      case 1:
        import_data();
        break;
      case 2:
        export_data(account_list, nb_compte, client_list);
        break;
      case 3:
        show_all(account_list, nb_compte);
        break;
      case 4:
        show_type(account_list, nb_compte, type_size, type_list);
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
        depot(account_list, nb_compte);
        break;
      case 2:
        retrait(account_list, nb_compte);
        break;
      case 3:
        virement(account_list, nb_compte);
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
    printf("4. Editer un client\n");
    printf("0. Revenir au menu principal");
    scanf("%d", &choix);
    switch(choix){
      case 1:
        add_client(client_list, *nb_client);
        nb_client++;
        break;
      case 2:
        del_client(client_list, *nb_client);
        break;
      case 3:
        search_client(client_list, *nb_client);
        break;
      case 4:
        edit_client(client_list, *nb_client);
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


void menu_compte(Account *account_list, int *nb_compte, int* nb_max_compte, t_account *type_list, int type_size){
  int out = 0;
  int choix = 0;
  printf("Menu Compte\n");
  while(out == 0){
    printf("Veuillez choisir une option:\n");
    printf("1. Creer un compte\n");
    printf("2. Supprimer un compte\n");
    printf("3. Afficher compte d'un client\n");
    printf("0. Revenir au menu précedent\n");
    scanf("%d", &choix);
    switch(choix){
      case 1:
        add_account(account_list, *nb_compte, type_list, type_size);
        *nb_compte++;
        break;
      case 2:
        del_account(account_list, *nb_compte);
        break;
      case 3:
        show_account(account_list, *nb_compte);
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
  char chaine[MAX_CHAR];
  t_account type_list[4];
  int control = 0, i = 0, type_size = 4;
  FILE* file = fopen("config.ini","r");
  if(file == NULL){
    printf("Erreur Lecture fichier");
    return EXIT_FAILURE;
  }
  while(fgets(chaine, MAX_CHAR, file) != NULL){
    switch(control%3){
      case 0:
        strcpy(type_list[i].name, chaine);
        break;
      case 1:
        type_list[i].taux = atoi(chaine);
        break;
      case 2:
        type_list[i].time = atoi(chaine);
        i++;
        break;
    }
    control++;
  }
  fclose(file);
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
        menu_compte(account_list, &nb_compte, &nb_max_compte, type_list, type_size);
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
  free(client_list);
  free(account_list);
  printf("Merci d'avoir utilisez CBanque");
  return EXIT_SUCCESS;
}
