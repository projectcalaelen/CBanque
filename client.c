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
 *		
 */
void edit_client(Client* self, int field, char* char_val, int int_val){
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



void delete_client(int id){

}

void search_client(Client** tab, int t_tab, char* string, int t_string){
	
}

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
    Client client = add_client(1, nom, prenom, profession, tel);
    show_client(&client);
    char nom_bis[MAX_CHAR] = "Byszewski";
    edit_client(&client, 2, nom_bis, 0);
    printf("\n");
    show_client(&client);

}