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

void show_account(){

}

void export_data(Account *account_list, int nb_compte){
	//Compte + clients avec id != -1
	FILE *fp;
	fp = fopen("export.csv", "w+");
	fprintf(fp, "Id client, Id compte, Solde, Taux, Durée");
	for (int i = 0; i < nb_compte; i++){
		if (account_list[i].id_account != -1){
			fprintf("\n");
			fprintf(fp, account_list[i].id_client);
			fprintf(fp, account_list[i].id_account);
			fprintf(fp, account_list[i].solde);
			fprintf(fp, account_list[i].type.taux);
			fprintf(fp, account_list[i].type.time);
		}
	}
	fclose(fp);
}

void import_data(){

}
