void add_client(Client *client_list, int nb_client){
  char lastname[MAX_CHAR], firstname[MAX_CHAR], profession[MAX_CHAR];
  int tel;
  printf("Veuillez rentrer un nom\n");
  scanf("%s", &lastname);
  printf("Entrez un prenom\n");
  scanf("%s", &firstname);
  printf("Rentrez une profession\n");
  scanf("%s", &profession);
  printf("Rentrez un numero de telephone\n");
  scanf("%d", &tel);
  client_list[nb_client]->lastname = lastname;
  client_list[nb_client]->firstname = firstname;
  client_list[nb_client]->profession = profession;
  client_list[nb_client]->tel = tel;
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

void del_client(Client *client_list, int nb_client){
  printf("Veuillez saisir l'id du client\n");
  int id = 0;
  scanf("%d", &id);
  for(int i = O; i<nb_client; i++){
    if(client_list[i]->id_client == id){
      client_list[id]->id_client = -1;
    }
  }
  return;
}

void search_client(Client *client_list, int nb_client){
  printf("Veuillez rentrer votre recherche:");
  char search[15];
  scanf("%s", &search);
  t_string = strlen(search);
  for(int i = 0; i<t_string; i++){
    if("*" == search[i]){
      search[i] = "\0";
    }
  }
  for(int i = 0; i< nb_client; i++){
    if(strncmp(search, list_client[i]->lastname, t_string -1) == 0){
      printf("%d: %s %s\n", list_client[i]->id_client, list_client[i]->lastname, list_client[i]->firstname);
    }
  }
  return;
}

void show_client(Client *client_list, int nb_client){
  printf("Rentrer l'id du client que vous voulez afficher:\n");
  int id = NULL;
  scanf("%d", &id);
  for(int i = 0; i<nb_client; i++){
    if( id == list_client[i]->id){
      printf("ID: %d\n", list_client[i]->id);
      printf("Lastname: %s\n", list_client[i]->lastname);
      printf("Firstname: %s\n", list_client[i]->firstname);
      printf("profession: %s\n", list_client[i]->profession);
      printf("telephone: %s\n", list_client[i]->tel);
      break;
    }
  }
  return;
}
