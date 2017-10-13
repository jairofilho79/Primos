#include<stdio.h>
#include<locale.h>

int opcaoA(int n,int vet[]){
	int i=3,j,k=0,tam=0,tam2=1,l=0;
	while(i<=n && k==0){		
		for(j=0;j<=tam;j++){
			
			if(n%vet[j]==0){				
				k=1;
				continue;
			}
			if(i%vet[j]==0){
				j=tam;											
			}
			else if(l==tam){
				vet[tam2] = i;
				tam2++;				
			}
			l++;				
		}
		i++;
		tam = tam2-1;
		l=0;			
	}		
		if(k){			
			printf("É composto.\n");
			return 0;
		}
		else{
			printf("É primo.\n");
		}			
	return 0;	
}

int opcaoB(int n,int vet[],int k){
	int i=3,j,tam=0,tam2=1,l=0;
	while(i<=n){		
		for(j=0;j<=tam;j++){
			if(i%vet[j]==0){
				j=tam;											
			}
			else if(l==tam){
				if(k==1){
					vet[tam2] = i*-1;
				}
				else{
					vet[tam2] = i;					
				}
					tam2++;								
			}
			l++;				
		}
		i++;
		tam = tam2-1;
		l=0;			
	}
		
		if(k){
			for(j=tam2-1;j>=0;j--)
				printf("%i ",vet[j]);
		}	
		else{
			for(j=0;j<tam2;j++)
				printf("%i ",vet[j]);
		}
}

int main(){
	setlocale(LC_ALL,"portuguese");
	int n=0,k=0,op=0,vet[1000];
	
	do{
		printf("1 - VERIFICAR SE É PRIMO.\n2 - DIZER PRIMOS ATÉ O VALOR DIGITADO.\nDigite a opção desejada:.\n");
		scanf("%i",&op);
	} while(!((op==1)||(op==2)));
	
	printf("Digite um número inteiro.\n");
	scanf("%i",&n);
	
		if(n<0){
		n *=-1;
		k=1;		
	}
	if(k){
		vet[0] = -2;	
	}
	else
		vet[0] = 2;
		
	if(n == 0){
		printf("Número nulo.\n");
		return 0;		
	} else if(n == 1){
		printf("Número próprio.\n");
		return 0;
	} else if (n == 2){
		printf("É primo.\n");
		return 0;
	}
	if(op==1){
		opcaoA(n,vet);
	}
	else
		opcaoB(n,vet,k);	
	return 0;	
}
