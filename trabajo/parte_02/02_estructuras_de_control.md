> Compare las sentencias de iteración y condicional para cada lenguaje mencionando las características y particularidades que considere más importantes.

## C

### Condicional

* La expresiones condicionales en C estan dadas por las estructuras de control `if-else` y `?:`.
	* _Ejemplo:_
	```C
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
	```
	* La expresión a evaluar puede ser tan compleja como se desee pero debe retornar un valor.
	* La expresión es ejecutada y se compara el valor retornado con 0 (siendo éste equivalente a `false`).
	* Si evalúa a `true`, el control se envía al bloque definido debajo del `if` el cual es obligatorio.
	* Si evalúa a `false`, el control se envía al bloque definido por `else` en caso de existir, sino se continúa la ejecución al final del bloque `if`.
	* Para el bloque `?:` denominado `if ternario`, debemos expandir la notación: `(condition)? <ifTrueStatements> : <ifFalseStatements>`.
	* Nuevamente la condición puede ser tan compleja como se desee, debe retornar un valor y es evaluado de la misma forma que el bloque `if-else`.
	* Tanto los bloques <ifTrueStatements> e <ifFalseStatements> son obligatorios.
	* Multiples operaciones pueden ser comprendidas dentro de <ifTrueStatements> e <ifFalseStatements> pero a travez del operador `,` ya que los bloques `{` `}` no estan permitidos.
		Se debe tener cuidado cuando se hace esto ya que:
		```C
		#include <stdio.h>
		int main()
		{
			int n = 3;
			(n > 1)? (printf("true\n"), printf("true again\n")) : printf("false\n"), printf("false again\n");
			return 0;
		}
		```
		_Retorna `'true', 'true again', 'false again'`._

		Pero:
		```C
		#include <stdio.h>
		int main()
		{
			int n = 3;
			(n > 1)? (printf("true\n"), printf("true again\n")) : (printf("false\n"), printf("false again\n"));
			return 0;
		}
		```
		_Retorna correctamente `'true', 'true again'`._

	*

* A su vez C proporciona una estructura de control condicional múltiple `switch-case`.
	* _Ejemplo:_
	```C
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
			case 50:
				c = 'L';
				break;
			case 100:
				c = 'C';
				break;
			case 500:
				c = 'D';
				break;
			case 1000:
				c = 'M';
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
	```
	* La expresión a evaluar puede ser tan compleja como se desee pero debe retornar un valor.
	* Las etiquetas `case` deben ir acompañadas de un literal(o una expresión literal) tipo entero que será el valor a comparar para esa etiqueta.
	* La etiqueta `default` es ocpional y no va acompañada de un literal. Sólo es ejecutada si ninguna de las etiquetas evaúa a true. (Puede ir en cualquier lugar del case aunque se acostumbra ponerlo al final.)
	* Todas las etiquetas `case` _deben_ evaluar a valores diferentes.
	* Todas las etiquetas son evaluadas _simultaneamente_ y en caso de que la comparación de sea `true`, se ejecuta el bloque especificado para esa etiqueta.
	* Luego de finalizar el bloque definido para una etiqueta, si éste no quebró la estructura de control (a travez de un `break`) se continúa ejecuntando el bloque de la próxima etiqueta definida. (`The C Programming Language` lo define como `fall through` y sucede porque las etiquetas son simplemente puntos definidos de código y no bloques independientes.)

### Iteración

* Las expresiones iterativas-precondicionales estan implementadas bajo la estructura de control `while`
	* _Ejemplo:_
	```C
	#include <stdio.h>
	const int limit = 100;
	int done(int index)
	{
		return (index > limit);
	}
	int main() {
		int i = 0;
		while(!done(i)){
			printf("%d\n", i);
			i++;
		}
	}
	```
	* La expresión a evaluar puede ser tan compleja como se desee.
	* La expresión es ejecutada y se compara el valor retornado con 0 (siendo éste equivalente a `false`).
	* Si la expresión evalúa `expr != 0` el bloque es ejecutado y la expresión se vuelve a evaluar.
	* Si la expresión evalúa a `false`, la ejecución continúa fuera del bloque `while`.

* C provee además, la expresión iterativa `for` que es(en este caso) una estructura iterativa-precondicional.
	* _Ejemplo:_
	```C
	#include <stdio.h>
	const int limit = 100;
	int main() {
		for(int i = 0; i < limit; i++){
			printf("%d\n", i);
		}
	}
	```
	* El `for` de C se define en 3 partes:
		* La primer sentencia es ejecutada al ingresar al bloque del `for`.
		* Luego se evalúa la segunda sentencia de forma tal que `expr != 0`.
		* Si la expresión evalúa a `false` la ejecución se continúa al final del bloque.
		* Si la expresión evalúa a `true` se ejecuta el bloque interno al `for`.
		* Luego de la ejecución del bloque, se ejecuta la tercera expresión.
		* Finalmente se vuelve a evaluar la segunda expresión y se genera el bucle.
	* Consideramos al `for` de C como iterativo-precondicional ya que antes de ejecutar el bloque por primera vez se chequea la condición del bloque.
	* Las expresiones del "header" del for pueden ser tan complejas como se deseen pero los bloques `{` `}` no están permitidos.
	* Cualquiera de las 3 expresiones es opcional.
	* En general su uso con el bloque `while` puede ser intercambiado, pero aporta legibilidad el uso específico de esta estructura de control.

* A su vez, provee del bloque `do-while` para iteraciones postcondicionales.
	* _Ejemplo:_
	```C
	#include <stdio.h>
	const int limit = 100;
	int done(int index)
	{
		return (index > limit);
	}
	int main() {
		int i = 0;
		do {
			printf("%d\n", i);
			i++;
		} while(!done(i));
	}
	```
	* La expresión a evaluar puede ser tan compleja como se desee.
	* El bloque es ejecutado una primera vez.
	* La expresión es evaluada y se compara el valor retornado con 0 (siendo éste equivalente a `false`).
	* Si la expresión evalúa `expr != 0` el bloque es ejecutado nuevamente y la expresión se vuelve a evaluar.
	* Si la expresión evalúa a `false`, la ejecución continúa fuera del bloque `do-while`.


## Gobstones

### Condicional

* La expresiones condicionales en Gobstones estan dadas por las estructuras de control `if-else`.
	* _Ejemplo:_
	```
	program
	{
		if (hayBolitas(Rojo)) -- Verdadero si hay flor en la celda actual
		{
			Poner(Negro) -- Solo agrega fertilizante
		}
		else
		{
			Poner(Rojo) -- Pone una flor, pues no hay ninguna
		}
	}
	```
	* La expresión a evaluar puede ser tan compleja como se desee pero debe retornar un valor booleano.
	* La expresión es ejecutada y se compara el valor retornado con `true`.
	* Si evalúa a `true`, el control se envía al bloque definido debajo del `if` el cual es obligatorio.
	* Si evalúa a `false`, el control se envía al bloque definido por `else` en caso de existir, sino se continúa la ejecución al final del bloque `if`.

* A su vez, Gobstones provee de una expresión _condicional indexada_ a travez de la estructura de control `switch->`
	* _Ejemplo:_
	```
	program
	{
		{
			switch (dir) to
			Norte -> { PonerN(1, Verde) }
			Sur -> { PonerN(2, Verde) }
			Este -> { PonerN(3, Verde) }
			_ -> { PonerN(4, Verde) }
		}
	}
	```
	* La expresión a evaluar puede ser tan compleja como se desee pero debe retornar un valor.
	* Las etiquetas estan nombradas por un literal del mismo tipo que el retornado por la expresión evaluada.
	* La etiqueta `_` es obligatoria y debe colocarse al final del switch. No va acompañada de un literal y sólo es ejecutada si ninguna de las etiquetas evaúa a true. (Puede ir en cualquier lugar del case aunque se acostumbra ponerlo al final.)
	* Las etiquetas son evaluadas _secuencialmente_ y en caso de que la comparación de sea `true`, se ejecuta el bloque especificado para esa etiqueta y luego salta al final del switch.

### Iteratción

* Las expresiones iterativas-precondicionales estan implementadas bajo la estructura de control `while`
	* _Ejemplo:_
	```
	program
	{
		dir := Norte;
		while(dir == Norte)
		{
			Poner(Verde)
		}
	}
	```
	* La expresión a evaluar puede ser tan compleja como se desee.
	* La expresión es ejecutada y se compara el valor retornado con `True`.
	* Si la expresión evalúa `True` el bloque es ejecutado y la expresión se vuelve a evaluar.
	* Si la expresión evalúa a `False`, la ejecución continúa fuera del bloque `while`.

* Gobstones provee de una función iterativa-indexada a travez de la estructura `foreach`.
	* _Ejemplo:_
	```
	program
	{
		foreach i in [2,4..10]
		{
			Poner(Verde)
			Mover(Este)
		}
	}
	```
	* Se define un identificador y un rango de valores.
	* El identificador toma todos los valores del rango hasta finalizar la iteración.
	* El bloque se ejecuta para cada valor del rango.

## Comparación

### Condicional

|Estructura|Característica|C|Gobstones|
|:----:|:----:|:----:|
|Condicional Simple|---|Si|Si|
||Condición compleja|Si|Si|
||Valor a comparar|expr != 0|expr = True|
||Bloques permitidos|Si|Si|
||Bloque afirmativo|Obligatorio|Obligatorio|
||Bloque negativo|Opcional|Opcional|
|Condicional Ternaria|---|Si|No|
||Condición compleja|Si|N/A|
||Valor a comparar|expr != 0|N/A|
||Bloques permitidos|No|N/A|
||Bloque afirmativo|Opcional|N/A|
||Bloque negativo|Obligatorio|N/A|
|Condicional Multiple||Si|Si|
||Condición compleja|Si|Si|
||Valor a comparar|(expr == literal) != 0|(expr = literal) = True|
||Orden de comparación|_Simultáneo*_|Secuencial|
||Manejo de colisiones en etiquetas|Error de compilación|Se ejecuta el primero en el orden|
||Al aceptar una etiqueta|Se ejecuta su bloque asociado y se sigue con los subsiguientes (**Fall through**)|Se ejecuta su bloque asociado y se sigue al final del bloque|
||Etiqueta default|Opcional|Obligatoria|
||Orden de la etiqueta default|Indiferente|Última|
||Aceptación de la etiqueta default|Sólo cuando ninguna otra etiqueta es válida|Sólo cuando ninguna otra etiqueta es válida|


### Iteración
|Estructura|Característica|C|Gobstones|
|:----:|:----:|:----:|
|Iteración precondicional||Si|Si|
||Condición compleja|Si|Si|
||Valor a comparar|expr != 0|expr = True|
||Cantidad de ejecuciones|0..N|0..N|
|Iteración postcondicional||Si|No|
||Condición compleja|Si|N/A|
||Valor a comparar|expr != 0|N/A|
||Cantidad de ejecuciones|1..N|N/A|
|Iteración indexada||No|Si|
||Condición compleja|N/A|Rango de valores|
||Cantidad de ejecuciones|N/A|Tamaño del rango|
