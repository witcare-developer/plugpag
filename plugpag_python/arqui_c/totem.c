#include "libPPPagSeguro/PPPagSeguro.h"

#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

stPPPSTransactionResult transactionResult;

void pResult (stPPPSTransactionResult transactionResult)
{
	printf ("Resultado da transacao\nmessage [%s]\ntransactionCode [%s]\ndate [%s]\ntime [%s]\nhostNsu [%s]\ncardBrand [%s]\nbin [%s]\nholder [%s]\nuser reference [%s]\nrawBuffer [%s]\nterminalSerialNumber [%s]",
			transactionResult.message,
			transactionResult.transactionCode,
			transactionResult.date,
			transactionResult.time,
			transactionResult.hostNsu,
			transactionResult.cardBrand,
			transactionResult.bin,
			transactionResult.holder,
			transactionResult.userReference,
			transactionResult.rawBuffer,
			transactionResult.terminalSerialNumber
			);
}

int main (int argc, char* argv [])
{
/*
	printf("%d\n", argc);
	printf("-----------------------------\n");
	printf("%s\n",argv[0]);//nome aplicação
	printf("%s\n",argv[1]);//porta
	printf("%s\n",argv[2]);//Tipo de pagamento (Crédito=1, Débito=2, Voucher=3)
	printf("%s\n",argv[3]);//Tipo de prestação (A vista=1, A prazo=2)
	printf("%s\n",argv[4]);//Quantidade de prestação qundo a prazo
	printf("%s\n",argv[5]);//Valor da transação
	printf("%s\n",argv[6]);//Código do estabelecimento relativo a transação
*/
	totem_pag(argv[1], atoi(argv[2]),atoi(argv[3]), atoi(argv[4]), argv[5], argv[6]);
}

void totem_pag(char* porta, int metodoPag,int tipo_prestacao, int qtd_prestacao, char* valor, char* codigo_vendedor )
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

	
	// Porta COM0 está com a Moderninha Pro pareada no Bluetooth
	memcpy (comPort, porta, strlen(porta));

	// Define métode de pagamento
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
	
	// Quantidade de parcelas
	if(metodoPag == PPPAGSEGURO_CREDIT){

		if( tipo_prestacao == 1 ){
			installmentType = PPPAGSEGURO_A_VISTA;
			installment = 1;
		}else if( tipo_prestacao == 2 ){
			installmentType = PPPAGSEGURO_PARC_VENDEDOR;
			installment = qtd_prestacao;
		}

	}
	
	

	// R$ 30,00 Reais
	memcpy (amount, valor, strlen(valor));

	// Meu código de venda é...
	memcpy (userReference, codigo_vendedor, strlen(codigo_vendedor));

	InitBTConnection (comPort);

	// Setar o nome e versão da aplicação
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

	pResult(transactionResult);
}