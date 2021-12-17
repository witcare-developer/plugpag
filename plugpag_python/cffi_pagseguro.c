#include "libPPPagSeguro/PPPagSeguro.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

stPPPSTransactionResult transactionResult;

void totem(char* porta, int metodoPag,int tipo_prestacao, int qtd_prestacao, char* valor, char* codigo_vendedor )
{
	
    int ret;
	tyComPort comPort;
	enPPPSPaymentMethod paymentMethod;
	enPPPSInstallmentType installmentType;
	unsigned int installment;
	tyAmount amount;
	tyUserReference userReference;
	tyAppName appName;
       tyAppVersion appVersion;
	stPPPSTransactionResult transactionResult;

	memset ((void*) comPort, 0, sizeof (tyComPort));
	memset ((void*) amount, 0, sizeof (tyAmount));
	memset ((void*) userReference, 0, sizeof (tyUserReference));
	memset ((void*) appName, 0, sizeof (tyAppName));
	memset ((void*) appVersion, 0, sizeof (tyAppVersion));

	memcpy (comPort, porta, strlen(porta));

	switch(metodoPag){
		case 1:
		paymentMethod = PPPAGSEGURO_CREDIT;
		break;
		case 2:
		paymentMethod = PPPAGSEGURO_DEBIT;
		break;
		case 3:
		paymentMethod = PPPAGSEGURO_VOUCHER;
		break;
	}
	
	if(metodoPag == PPPAGSEGURO_CREDIT){

		if( tipo_prestacao == 1 ){
			installmentType = PPPAGSEGURO_A_VISTA;
			installment = 1;
		}else if( tipo_prestacao == 2 ){
			installmentType = PPPAGSEGURO_PARC_VENDEDOR;
			installment = qtd_prestacao;
		}

	}
	
	
	memcpy (amount, valor, strlen(valor));

	memcpy (userReference, codigo_vendedor, strlen(codigo_vendedor));

	InitBTConnection (comPort);

	memcpy (appName, "Totem de pagamentos", 19);
	memcpy (appVersion, "R001", 4);
	SetVersionName(appName, appVersion);

	ret = SimplePaymentTransaction (
		paymentMethod,
		installmentType,
		installment,
		&amount,
		&userReference,
		&transactionResult
	);
}