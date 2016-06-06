## C

### Condicional

* La expresiones condicionales en C están dadas por las estructuras de control `if-else` y `?:`.
	* _Ejemplo:_ [if.c](02_ejemplos/if.c)
	* La expresión a evaluar puede ser tan compleja como se desee pero debe retornar un valor.
	* La expresión es ejecutada y se compara el valor retornado con 0 (siendo éste equivalente a `false`).
	* Si evalúa a `true`, el control se envía al bloque definido debajo del `if` el cual es obligatorio.
	* Si evalúa a `false`, el control se envía al bloque definido por `else` en caso de existir, sino se continúa la ejecución al final del bloque `if`.
	* Para el bloque `?:` denominado `if ternario`, debemos expandir la notación: `(condition)? <ifTrueStatements> : <ifFalseStatements>`.
	* Nuevamente la condición puede ser tan compleja como se desee, debe retornar un valor y es evaluado de la misma forma que el bloque `if-else`.
	* Tanto los bloques <ifTrueStatements> e <ifFalseStatements> son obligatorios.
	* Múltiples operaciones pueden ser comprendidas dentro de <ifTrueStatements> e <ifFalseStatements> pero a través del operador `,` ya que los bloques `{` `}` no están permitidos.

* A su vez C proporciona una estructura de control condicional múltiple `switch-case`.
	* _Ejemplo:_ [switch.c](02_ejemplos/switch.c)
	* La expresión a evaluar puede ser tan compleja como se desee pero debe retornar un valor.
	* Las etiquetas `case` deben ir acompañadas de un literal(o una expresión literal) tipo entero que será el valor a comparar para esa etiqueta.
	* La etiqueta `default` es opcional y no va acompañada de un literal. Sólo es ejecutada si ninguna de las etiquetas evalúa a true. (Puede ir en cualquier lugar del case aunque se acostumbra ponerlo al final.)
	* Todas las etiquetas `case` _deben_ evaluar a valores diferentes.
	* Todas las etiquetas son evaluadas _simultáneamente_ y en caso de que la comparación de sea `true`, se ejecuta el bloque especificado para esa etiqueta.
	* Luego de finalizar el bloque definido para una etiqueta, si éste no quebró la estructura de control (a través de un `break`) se continúa ejecutando el bloque de la próxima etiqueta definida. (`The C Programming Language` lo define como `fall through` y sucede porque las etiquetas son simplemente puntos definidos de código y no bloques independientes.)

### Iteración

* Las expresiones iterativas-precondicionales están implementadas bajo la estructura de control `while`
	* _Ejemplo:_ [while.c](02_ejemplos/while.c)
	* La expresión a evaluar puede ser tan compleja como se desee.
	* La expresión es ejecutada y se compara el valor retornado con 0 (siendo éste equivalente a `false`).
	* Si la expresión evalúa `expr != 0` el bloque es ejecutado y la expresión se vuelve a evaluar.
	* Si la expresión evalúa a `false`, la ejecución continúa fuera del bloque `while`.

* C provee además, la expresión iterativa `for` que es(en este caso) una estructura iterativa-precondicional.
	* _Ejemplo:_ [for.c](02_ejemplos/for.c)
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
	* _Ejemplo:_ [do_while.c](02_ejemplos/do_while.c)
	* La expresión a evaluar puede ser tan compleja como se desee.
	* El bloque es ejecutado una primera vez.
	* La expresión es evaluada y se compara el valor retornado con 0 (siendo éste equivalente a `false`).
	* Si la expresión evalúa `expr != 0` el bloque es ejecutado nuevamente y la expresión se vuelve a evaluar.
	* Si la expresión evalúa a `false`, la ejecución continúa fuera del bloque `do-while`.

## Gobstones

### Condicional

* La expresiones condicionales en Gobstones están dadas por las estructuras de control `if-else`.
	* _Ejemplo:_ [if.gbs](02_ejemplos/if.gbs)
	* La expresión a evaluar puede ser tan compleja como se desee pero debe retornar un valor booleano.
	* La expresión es ejecutada y se compara el valor retornado con `true`.
	* Si evalúa a `true`, el control se envía al bloque definido debajo del `if` el cual es obligatorio.
	* Si evalúa a `false`, el control se envía al bloque definido por `else` en caso de existir, sino se continúa la ejecución al final del bloque `if`.

* A su vez, Gobstones provee de una expresión _condicional indexada_ a través de la estructura de control `switch->`
	* _Ejemplo:_ [switch.gbs](02_ejemplos/switch.gbs)
	* La expresión a evaluar puede ser tan compleja como se desee pero debe retornar un valor.
	* Las etiquetas están nombradas por un literal del mismo tipo que el retornado por la expresión evaluada.
	* La etiqueta `_` es obligatoria y debe colocarse al final del switch. No va acompañada de un literal y sólo es ejecutada si ninguna de las etiquetas evalúa a true. (Puede ir en cualquier lugar del case aunque se acostumbra ponerlo al final.)
	* Las etiquetas son evaluadas _secuencialmente_ y en caso de que la comparación de sea `true`, se ejecuta el bloque especificado para esa etiqueta y luego salta al final del switch.

### Iteración

* Las expresiones iterativas-precondicionales están implementadas bajo la estructura de control `while`
	* _Ejemplo:_ [while.gbs](02_ejemplos/while.gbs)
	* La expresión a evaluar puede ser tan compleja como se desee.
	* La expresión es ejecutada y se compara el valor retornado con `True`.
	* Si la expresión evalúa `True` el bloque es ejecutado y la expresión se vuelve a evaluar.
	* Si la expresión evalúa a `False`, la ejecución continúa fuera del bloque `while`.

* Gobstones provee de una función iterativa-indexada a través de la estructura `foreach`.
	* _Ejemplo:_ [foreach.gbs](02_ejemplos/foreach.gbs)
	* Se define un identificador y un rango de valores.
	* El identificador toma todos los valores del rango hasta finalizar la iteración.
	* El bloque se ejecuta para cada valor del rango.
