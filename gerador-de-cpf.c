#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cpfGerador();
void cpfImprimir(int *cpf);

int main() {
	
	srand(time(NULL));
	
	int *cpf;

	cpf = cpfGerador();
	cpfImprimir(cpf);

	free(cpf);
	cpf = NULL;
	
	return 0;

}

int cpfGerador() {

	int *cpf, i, valida = 0;
	
	cpf = malloc(sizeof(int) * 11);

	/* gera numero aleatorio de cpf*/
	for (i = 0; i < 9; i++) {
		*(cpf + i) = rand() % 10;
	}

	/* primeiro digito verificador */
	for (i = 0; i < 9; i++) {
		valida += *(cpf + i) * (10 - i);
	}

	*(cpf + 9) = (valida * 10) % 11;
	if (*(cpf + 9) == 10)
		*(cpf + 9) = 0;

	/* segundo digito verificador */
	valida = 0;
	for (i = 0; i < 10; i++) {
		valida += *(cpf + i) * (11 - i);
	}

	*(cpf + 10) = (valida * 10) % 11;
	if (*(cpf + 10) == 10)
		*(cpf + 10) = 0;


	return cpf;
}

void cpfImprimir(int *cpf) {
	int i;

	for (i = 0; i < 11; i++) {
		if (i == 3 || i == 6)
			printf(".");
		
		if(i == 9)
			printf("-");
		printf("%d", *(cpf + i));
	}
}
