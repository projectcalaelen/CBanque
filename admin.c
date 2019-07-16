#include "admin.h"


void show_all(Account *account_list, int nb_compte){
	printf("Somme des montants de solde de tous les comptes: \n");
	int solde_total = 0;
	for (int i = 0; i < nb_compte; i++){
		if (account_list[i].id_account != -1){
			solde_total += account_list[i].solde;
		}
	}
	printf("Solde: %d\n", solde_total);
}

void show_type(Account *account_list, int nb_compte, int type_size, t_account *type_list){
	int montant[4] = 0;
	for(int i = 0; i< nb_compte; i++){
		if(account_list[i].id_account != -1){
			if(strcmp(account_list[i].type.name, type_list[0].name) == 0){
				montant[0] += account_list[i].solde;
			}else if(strcmp(account_list[i].type.name, type_list[1].name) == 0){
				montant[1] += account_list[i].solde;
			}else if(strcmp(account_list[i].type.name, type_list[2].name) == 0){
				montant[2] += account_list[i].solde;
			}else if(strcmp(account_list[i].type.name, type_list[3].name) == 0){
				montant[3] += account_list[i].solde;
      		}
    	}
  	}
	for(int i = 0; i < 4; i++){
		printf("Sommes des montants des %s: %d\n", type_list[i].name, montant[i]);
	}
}

void export_data(Account *account_list, int nb_compte, Client *list_client){
	//Compte + clients avec id != -1
	FILE *fpa;
	FILE *fpc;
	fpa = fopen("export_account.csv", "w+");
	fprintf(fpa, "Id client, Id compte, Solde, Taux, Durée");
	for (int i = 0; i < nb_compte; i++){
		if (account_list[i].id_account != -1){
			fprintf("\n");
			fprintf(fpa, account_list[i].id_client);
			fprintf(",");
			fprintf(fpa, account_list[i].id_account);
			fprintf(",");
			fprintf(fpa, account_list[i].solde);
			fprintf(",");
			fprintf(fpa, account_list[i].type.taux);
			fprintf(",");
			fprintf(fpa, account_list[i].type.time);
		}
	}
	fclose(fpa);
	fpc = fopen("export_client.csv", "w+");
	fprintf(fpc, "Id client, Nom, Prénom, Profession, Téléphone");
	for (int i = 0; i < nb_compte; i++){
		if (list_client[i].id_account != -1){
			fprintf("\n");
			fprintf(fpc, list_client[i].id_client);
			fprintf(",");
			fprintf(fpc, list_client[i].lastname);
			fprintf(",");
			fprintf(fpc, list_client[i].firstname);
			fprintf(",");
			fprintf(fpc, list_client[i].profession);
			fprintf(",");
			fprintf(fpc, list_client[i].tel);
		}
	}
	fclose(fpc);
}

void import_data(){

}
