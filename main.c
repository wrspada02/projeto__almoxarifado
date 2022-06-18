#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct item{
	int code;
	char name[50];
	int amount;
}item;

item itens[6] = {};

void toCreateItens(){
	FILE *fp;
	fp = fopen("itens.txt", "r");
	if(fp != NULL){
		printf("Arquivo aberto!");
	}
	
	fclose(fp);
}

void toPrintWarehouseItens(){
	printf("Seja bem-vindo ao sistema de almoxarifado, aqui estao nossos itens.\n");
	printf("Escolha um item para retirar ou incrementar\n");
	printf("101 - Lapis\n");
	printf("102 - Caneta\n");
	printf("103 - Borracha\n");
	printf("104 - Corretivo\n");
	printf("105 - Tesoura\n");
	printf("106 - Caderno\n");
}

void isIncrementOrDecrement(int answerTest){
	item object;
	
	if(answerTest == 1){
		printf("Qual a quantidade que deseja incrementar: \n");
		scanf("%d", &object.amount);
		printf("Qual o codigo do item: ");
		scanf("%d", &object.code);
		incrementItem(object);
	}else if(answerTest == 2){
		printf("Qual a quantidade que deseja decrementar: \n");
		scanf("%d", &object.amount);
		printf("Qual o codigo do item: ");
		scanf("%d", &object.code);
		decrementItem(object);
	}else{
		printf("Atividade invalida, tente novamente!\n");
	}
}

void incrementItem(item object){
	int i;
	
	for(i = 0; i < 5; i++){
		if(itens[i].code == object.code){
			itens[i].amount += object.amount;
		}
	}
}

void decrementItem(item object){
	int i;
	
	for(i = 0; i < 5; i++){
		if(itens[i].amount < 5){
			printf("O item de codigo %d e nome %s esta com quantidade baixa no estoque, solicitar compra!", itens[i].code, itens[i].name);
		}
		if(itens[i].code == object.code){
			if(itens[i].amount-object.amount < 0){
				printf("Nao e possivel decrementar o item em questao, estoque baixo.");
			}else{
				itens[i].amount -= object.amount;
			}
		}
	}
}

void main(){
	int wantItem, isIncrementOrDecrementValue;
	
	toCreateItens();
	toPrintWarehouseItens();

	do{
		printf("Deseja retirar ou adicionar algum item? Se sim, digite 1, se nao digite 0: ");
		scanf("%d", &wantItem);	
		if(wantItem == 1){
			printf("Para incrementar algum item digite 1, para retirar digite 2: ");
			scanf("%d", &isIncrementOrDecrementValue);
			isIncrementOrDecrement(isIncrementOrDecrementValue);
		}else if(wantItem == 0){
			exit(1);
		}else{
			while(wantItem != 1 || wantItem != 0){
				printf("Atividade invalida, digite novamente!");
				scanf("%d", &wantItem);
			}
		}
	}while(wantItem);
}
