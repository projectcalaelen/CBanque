#include <stdio.h>
#include <stdlib.h>

void show_all(int nb_compte){
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

void export_data(){
	//Compte + clients avec id != -1
	FILE *fp;
	fp = fopen("export.csv", "w+");
	fprintf(fp, account_list);
	fclose(fp);
}

void import_data(){

}
