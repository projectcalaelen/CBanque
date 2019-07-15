#include <stdio.h>
#include <stdlib.h>


void add_client(Client *client_list, int nb_client){
  printf("Veuillez rentrer un nom\n");
  scanf("%s", client_list[nb_client]->lastname);
  printf("Entrez un prenom\n");
  scanf("%s", client_list[nb_client]->firstname);
  printf("Rentrez une profession\n");
  scanf("%s", client_list[nb_client]->profession);
  printf("Rentrez un numero de telephone\n");
  scanf("%d", client_list[nb_client]->tel;
  client_list[nb_client]->id_client = nb_client;
  return;
}

void edit_client(CLient *client_list, int nb_client){
  printf("Veuillez rentrer l'id du compte\n");
  int id = -1;
  scanf("%d", &id);
  int out = 0;
  int choix = 10;
  while(out==0){
    printf("Veuillez choisir un champ a modifier\n");
    printf("1. Nom\n");
    printf("2. Prenom\n");
    printf("3. Profession\n");
    printf("4. Telephone\n");
    printf("0. retour\n");
    scanf("%d", &choix);
    switch(choix){
      case 1:
        printf("Veuillez rentrer un nom\n");
        scanf("%s", client_list[id]->lastname);
        break;
      case 2:
        printf("Veuillez rentrer un prenom\n");
        scanf("%s", client_list[id]->firstname);
        break;
      case 3:
        printf("Veuillez rentrer une profession\n");
        scanf("%s", client_list[id]->profession);
        break;
      case 4:
        printf("Veuillez rentre un numero de telephone\n");
        scanf("%s", client_list[id]->tel);
        break;
      case 0:
        out = 1;
        break;
      default:
        printf("Veuillez saisir une option valide\n");
        break;
    }
  }
  return;
}

void del_client(Client *client_list){
  printf("Veuillez saisir l'id du client\n");
  int id = 0;
  scanf("%d", &id);
  client_list[id]->id = -1;
}

void search_client(Client *client_list, int nb_client){
  printf("Veuillez rentrer votre recherche:");
  char search[15];
  scanf("%d", &search);
  for(int i = 0; i < nb_client; i++){
    
  }
}
