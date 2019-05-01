#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX_CHAR 15

typedef struct{
	int id_client;
	char[MAX_CHAR] lastname;
	char[MAX_CHAR] firstname;
	char[MAX_CHAR] profession;
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
Client add_client(int id_client, char* lastname, char* firstname, char* profession, int tel){
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
