#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

#ifndef __T_ACCOUNT__
#define __T_ACCOUNT__

typedef struct{
	char[] name;
	int taux;
} t_account;

#endif

#ifndef __ACCOUNT__
#define __ACCOUNT__

typedef struct{
	int id_account;
	int id_client;
	int solde;
	int time;
  t_account type;
} Account;

#endif
