#include <stdio.h>
//Este programa responde qué letra corresponde en números romanos a un número
int main()
{
	int n = 0;
	char c = '-';
	printf("Ingrese el numero a evaluar\n");
	scanf("%d", &n);
	switch(n){
		case 1:
			c = 'I';
			break;
		case 5:
			c = 'V';
			break;
		case 10:
			c = 'X';
			break;
		default:
			c = '-';
			break;
	}
	if(c == '-') {
		printf("Hubo un error\n");
	} else {
		printf("El numero se escribe %c\n", c);
	}
	return 0;
}
