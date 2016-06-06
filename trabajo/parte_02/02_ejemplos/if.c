#include <stdio.h>
//Este programa evalúa si 2 números son mayores a 10
int main()
{
	printf("Ingrese el numero a evaluar\n");
	int n = 0;
	scanf("%d", &n);
	if(n > 10){
		printf("True!\n");
	} else {
		printf("False!\n");
	}
	printf("Ingrese otro numero\n");
	scanf("%d", &n);
	printf((n>10)?"True!\n" : "False!\n");
	return 0;
}
