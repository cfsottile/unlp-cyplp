## Ejercicio 1

Una excepción es una situación anómala que ocurre en la ejecución de un programa. Idealmente, las excepciones ocurren con poca frecuencia.

## Ejercicio 2

Para manejar excepciones, los lenguajes deben proveer:

* Una forma de definirlas
* Una forma de lanzarlas/alcanzarlas/invocarlas
* Una forma de manejarlas
* Un criterio de continuación

## Ejercicio 3

Se podría simular el manejo de excepciones mediante:

1. el chequeo manual de las condiciones que generarían la excepción, y
2. la invocación, también manual, de la rutina para manejar dicha excepción (esto sería el manejador).

## Ejercicio 4

**a**-**b**. Los modelos con respecto al criterio de continuación luego del manejo de la excepción son:

* Terminación: se corta la ejecución de la unidad que provocó la excepción y se entrega el control al manejador.
	* a nivel de bloque: el bloque en ejecución corta su ejecución. Ej.: Ada.
	* a nivel de sentencia: la sentencia en ejecución corta su ejecución. Ej.: CLU.
* Reasunción: luego de manejar la excepción, se continúa desde donde el manejador fue invocado. Ej.: PL1.

*DUDA: __terminación a nivel de sentencia__ vs __reasunción__. Si en ambas la ejecución continúa en la sentencia posterior a la invocación al manejador, ¿no sería lo mismo? O la diferencia radica en que en reasunción __siempre__ se invoca al manejador en la sentencia que lanza la excepción, permitiendo que se reanude la ejecución en la sentencia posterior, mientras que en terminación a nivel de sentencia __no se asegura__ que la invocación al manejo de la excepción se produzca en el mismo ámbito en el que la misma fue lanzada (por ejemplo, si se propaga estáticamente sobre las sentencias contenedoras, luego no volvería a ejecutar desde luego de la sentencia que provocó la excepción).*

**c**. ¿Inseguro desde qué perspectiva?

## Ejercicio 5

