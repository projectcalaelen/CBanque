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
