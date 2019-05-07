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

/*			ADD_CLIENT
 *
 *	Create a new client with a unique id, firstname, lastname,
 *	profession and telephone
 *	
 *	INPUT:
 *		- int id_client			:	Unique id
 *		- char* firstname		:	firstname of the client
 *		- char* lastname		:	lastname of the client
 *		- char* professopn		:	profession of the client
 *		- int tel				:	telephone of the client
 *	
 *	OUTPUT:
 *		- Client new			:	Typedef Client of the client
 */
Client add_client(int id_client, char const* lastname, char const* firstname, char const* profession, int tel){
	Client new;
	for(int i=0;i<MAX_CHAR;i++){
		new.lastname[i] = lastname[i];
		new.firstname[i] = firstname[i];
		new.profession[i] = profession[i];
	}
	new.id_client = id_client;
	new.tel = tel;

	return new;
}


/*			EDIT_CLIENT
 *
 *	Update the information of a client. wich field will be updated will
 * 	depend on the field value:
 *		- 1 				:	firstname
 *		- 2 				:	lastname
 *		- 3 				:	profession
 *		- 4 				:	telephone number
 *	
 *	INPUT:
 *		- Client* self		:	Client to be updated
 *		- int field			:	Field to be updated
 *		- char* char_val	:	Values if it's a string
 *		- int int_val		:	Values if it's an int
 *
 *	OUTPUT:
 *	    - Return the Client* self with modified fields by pointer.
 *		
 */
void edit_client(Client* self, int field, char const* char_val, int int_val){
	switch(field){
		case 1:
			for(int i=0; i<MAX_CHAR; i++){
				self->firstname[i] = char_val[i];
			}
			break;
		case 2:
			for(int i=0; i<MAX_CHAR; i++){
				self->lastname[i] = char_val[i];
			}
			break;
		case 3:
			for(int i=0; i<MAX_CHAR; i++){
				self->profession[i] = char_val[i];
			}
			break;
		case 4:
			self->tel = int_val;
			break;
		default:
			return;
	}
}


/*              DELETE_CLIENT
 *
 * Delete the client <=> put the id_client at -1
 *
 *  INPUT:
 *      - Client *self      : The Client to be deleted
 *
 */
void delete_client(Client* self){
    self->id_client = -1;
}

/*          SEARCH_CLIENT
 * Search the result for the string given in the name of list of client.
 * If the string end with XXX* it will show all the client that start with XXX.
 *
 * INPUT:
 *      - Client** list_client      : list of all the client
 *      - int t_tab                 : Size of the list of client
 *      - char *string              : String to look for in the nal
 *      - int t_string              : Size of the string given
 *
 * OUTPUT:
 *      - Show a list ( lastname + firstname + id_client) of the all the client that matches
 */
void search_client(Client** list_client, int t_tab, char* string, int t_string){
	if("*" == string[t_string]) {
        string[t_string - 1] = "\0";
        for (int i = 0; i < t_tab; i++) {
            if (strncmp(*string, list_client[i]->lastname, t_string - 1) == 0) {
                printf("%d: %s %s\n", list_client[i]->id_client, list_client[i]->lastname, list_client[i]->firstname);
            }
        }
    }else{
	    for(int i = 0; i< t_tab; i++){
	        if(strcmp(*string, list_client[i]->lastname) == 0){
	            printf("%d: %s %s\n",list_client[i]->id_client, list_client[i]->lastname, list_client[i]->firstname);
	        }
	    }
	}
}

/*          SHOW_CLIENT
 *
 *  Display the variable of the client on standard output
 *
 */
void show_client(Client* self){
    printf("Client N°%d\n", self->id_client);
    printf("Nom : %s\n", self->lastname);
    printf("Prenom : %s\n", self->firstname);
    printf("Profession : %s\n", self->profession);
    printf("Tel : %d\n", self->tel);
}

int main(){
    char nom[MAX_CHAR] = "Bouvet";
    char prenom[MAX_CHAR] = "Pacome";
    char profession[MAX_CHAR] = "Etudiant";
    int tel = 683602417;
    Client list_client[15];
    list_client[0] = add_client(1, nom, prenom, profession, tel);
    *nom = "Bysewski";
    *prenom = "Cedric";
    list_client[1] = add_client(2, nom, prenom, profession, tel);
    *nom = "Delagarde";
    *prenom = "Aurelien";
    list_client[2] = add_client(3, nom, prenom, profession, tel);


}