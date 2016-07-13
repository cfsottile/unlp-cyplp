# Conceptos y Paradigmas de Lenguajes de Programación

## Primer Trabajo Integrador

### Grupo 51

* 12222/0 - Sottile, Cristian Fabián
* 12469/2 - Eusebi, Cirano
* 12667/7 - Aparicio, Natalia Elizabeth

### Referencias

##### Punto *a*

* [Diapositivas de la cátedra - Clase sobre parámetros](https://catedras.info.unlp.edu.ar/mod/resource/view.php?id=16698)
* [The C Programming Language](http://www.amazon.com/Programming-Language-Brian-W-Kernighan/dp/0131103628) - Sección 1.8
* [The GNU C Reference Manual - Sección 5.4: Function Parameters](http://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Function-Parameters)
* Libro *Bases conceptuales de la programación*. [link-descarga](http://www.gobstones.org/bibliografia/Libros/BasesConceptualesProg.pdf)

##### Punto *b*

* _`The C Programming Language` de Brian W. Kernighan & Dennis M. Ritchie, segunda edición_.
* _`Las bases conceptuales de la Programación` de Pablo E. Martínez López, versión digital revisión 10 de febrero de 2014_.

##### Punto *c*

* Sitio oficial de Gobstones. [link](http://www.gobstones.org/)
* Sección Bibliografía, sitio oficial de Gobstones. [link](http://www.gobstones.org/?page_id=34)
* Libro: "The c programming language, Second edition" pag. 255
* Ejemplo del TRY CATCH en C [link](http://www.di.unipi.it/~nids/docs/longjump_try_trow_catch.html)

.

.

.

.


# a. Parámetros

## C

El pasaje de parámetros en C se lleva a cabo mediante **ligadura posicional** y **por copia**. Para cada parámetro formal, se especifica una expresión cuyo valor será asignado a los parámetros formales, los cuales son variables locales a la función. Por ejemplo:

* si la expresión correspondiente al parámetro real es un literal `5`, se asigna al parámetro real el valor `5`;
* si la expresión es un identificador de una variable, se asigna el valor de la variable;
* si la expresión es una invocación a una función, se asigna el valor de retorno de la misma.

Es posible especificar que el *r-valor* del parámetro formal no pueda cambiarse, mediante el modificador `const`. Uno podría verse tentado a afirmar que esto incurre en la implementación del pasaje de parámetros *por copia constante*, pero no es el caso, ya que el lenguaje no asegura que el parámetro real no pueda modificarse (usando punteros uno podría modificar objetos de datos externos a la función).

Ejemplo: [01_ejemplos/value.c](01_ejemplos/value.c)

Si bien no se provee un mecanismo automático para el pasaje de parámetros por referencia, esto puede realizarse mediante punteros. *Es importante destacar, previo a la explicación, que el operador `&` aplicado sobre una variable obtiene un puntero hacia esa variable.*

1. Se declara al parámetro formal como de tipo puntero.
2. Se pasa como parámetro real un puntero a un objeto de datos.
3. La copia se hace desde el valor del parámetro real hacia el del parámetro formal, permitiendo que mediante el segundo se acceda al dato que es referenciado por el primero.

Ejemplo: [01\_ejemplos/kind\_of\_reference.c](01_ejemplos/kind_of_reference.c)

## Gobstones

En la documentación del lenguaje se presenta a los parámetros como un mecanismo para poder definir valores que se usan en la rutina desde fuera de la misma. La ligadura se lleva a cabo de forma **posicional**. No se especifica si la copia se realiza por valor o por referencia, pero, dado que:

* los identificadores correspondientes a parámetros no pueden usarse como l-valor en una asignación, y que
* no existe el concepto de variable *no local* ni *global*,

podemos decir que el pasaje de parámetros se realiza **por copia constante**, ya que estamos ante un contexto en el que los parámetros reales no pueden ser modificados desde la rutina llamada.

Ejemplo: [01\_ejemplos/gobstones\_params.gbs](01_ejemplos/gobstones_params.gbs)

# b. Estructuras de control

## C

### Condicional

* La expresiones condicionales en C estan dadas por las estructuras de control `if-else` y `?:`.
	* _Ejemplo:_ [02_ejemplos/if.c](02_ejemplos/if.c)
	* La expresión a evaluar puede ser tan compleja como se desee pero debe retornar un valor.
	* La expresión es ejecutada y se compara el valor retornado con 0 (siendo éste equivalente a `false`).
	* Si evalúa a `true`, el control se envía al bloque definido debajo del `if` el cual es obligatorio.
	* Si evalúa a `false`, el control se envía al bloque definido por `else` en caso de existir, sino se continúa la ejecución al final del bloque `if`.
	* Para el bloque `?:` denominado `if ternario`, debemos expandir la notación: `(condition)? <ifTrueStatements> : <ifFalseStatements>`.
	* Nuevamente la condición puede ser tan compleja como se desee, debe retornar un valor y es evaluado de la misma forma que el bloque `if-else`.
	* Tanto los bloques <ifTrueStatements> e <ifFalseStatements> son obligatorios.
	* Multiples operaciones pueden ser comprendidas dentro de <ifTrueStatements> e <ifFalseStatements> pero a travez del operador `,` ya que los bloques `{` `}` no estan permitidos.

* A su vez C proporciona una estructura de control condicional múltiple `switch-case`.
	* _Ejemplo:_ [02_ejemplos/switch.c](02_ejemplos/switch.c)
	* La expresión a evaluar puede ser tan compleja como se desee pero debe retornar un valor.
	* Las etiquetas `case` deben ir acompañadas de un literal(o una expresión literal) tipo entero que será el valor a comparar para esa etiqueta.
	* La etiqueta `default` es ocpional y no va acompañada de un literal. Sólo es ejecutada si ninguna de las etiquetas evaúa a true. (Puede ir en cualquier lugar del case aunque se acostumbra ponerlo al final.)
	* Todas las etiquetas `case` _deben_ evaluar a valores diferentes.
	* Todas las etiquetas son evaluadas _simultaneamente_ y en caso de que la comparación de sea `true`, se ejecuta el bloque especificado para esa etiqueta.
	* Luego de finalizar el bloque definido para una etiqueta, si éste no quebró la estructura de control (a travez de un `break`) se continúa ejecuntando el bloque de la próxima etiqueta definida. (`The C Programming Language` lo define como `fall through` y sucede porque las etiquetas son simplemente puntos definidos de código y no bloques independientes.)

### Iteración

* Las expresiones iterativas-precondicionales estan implementadas bajo la estructura de control `while`
	* _Ejemplo:_ [02_ejemplos/while.c](02_ejemplos/while.c)
	* La expresión a evaluar puede ser tan compleja como se desee.
	* La expresión es ejecutada y se compara el valor retornado con 0 (siendo éste equivalente a `false`).
	* Si la expresión evalúa `expr != 0` el bloque es ejecutado y la expresión se vuelve a evaluar.
	* Si la expresión evalúa a `false`, la ejecución continúa fuera del bloque `while`.

* C provee además, la expresión iterativa `for` que es(en este caso) una estructura iterativa-precondicional.
	* _Ejemplo:_ [02_ejemplos/for.c](02_ejemplos/for.c)
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
	* _Ejemplo:_ [02\_ejemplos/do\_while.c](02_ejemplos/do_while.c)
	* La expresión a evaluar puede ser tan compleja como se desee.
	* El bloque es ejecutado una primera vez.
	* La expresión es evaluada y se compara el valor retornado con 0 (siendo éste equivalente a `false`).
	* Si la expresión evalúa `expr != 0` el bloque es ejecutado nuevamente y la expresión se vuelve a evaluar.
	* Si la expresión evalúa a `false`, la ejecución continúa fuera del bloque `do-while`.

## Gobstones

### Condicional

* La expresiones condicionales en Gobstones estan dadas por las estructuras de control `if-else`.
	* _Ejemplo:_ [02_ejemplos/if.gbs](02_ejemplos/if.gbs)
	* La expresión a evaluar puede ser tan compleja como se desee pero debe retornar un valor booleano.
	* La expresión es ejecutada y se compara el valor retornado con `true`.
	* Si evalúa a `true`, el control se envía al bloque definido debajo del `if` el cual es obligatorio.
	* Si evalúa a `false`, el control se envía al bloque definido por `else` en caso de existir, sino se continúa la ejecución al final del bloque `if`.

* A su vez, Gobstones provee de una expresión _condicional indexada_ a travez de la estructura de control `switch->`
	* _Ejemplo:_ [02_ejemplos/switch.gbs](02_ejemplos/switch.gbs)
	* La expresión a evaluar puede ser tan compleja como se desee pero debe retornar un valor.
	* Las etiquetas estan nombradas por un literal del mismo tipo que el retornado por la expresión evaluada.
	* La etiqueta `_` es obligatoria y debe colocarse al final del switch. No va acompañada de un literal y sólo es ejecutada si ninguna de las etiquetas evaúa a true. (Puede ir en cualquier lugar del case aunque se acostumbra ponerlo al final.)
	* Las etiquetas son evaluadas _secuencialmente_ y en caso de que la comparación de sea `true`, se ejecuta el bloque especificado para esa etiqueta y luego salta al final del switch.

### Iteratción

* Las expresiones iterativas-precondicionales estan implementadas bajo la estructura de control `while`
	* _Ejemplo:_ [02_ejemplos/while.gbs](02_ejemplos/while.gbs)
	* La expresión a evaluar puede ser tan compleja como se desee.
	* La expresión es ejecutada y se compara el valor retornado con `True`.
	* Si la expresión evalúa `True` el bloque es ejecutado y la expresión se vuelve a evaluar.
	* Si la expresión evalúa a `False`, la ejecución continúa fuera del bloque `while`.

* Gobstones provee de una función iterativa-indexada a travez de la estructura `foreach`.
	* _Ejemplo:_ [02_ejemplos/foreach.gbs](02_ejemplos/foreach.gbs)
	* Se define un identificador y un rango de valores.
	* El identificador toma todos los valores del rango hasta finalizar la iteración.
	* El bloque se ejecuta para cada valor del rango.

# c. Excepciones

## Gobstones

Gobstones no maneja las excepciones. Los creadores consideraron que es un concepto que no aporta a la comprensión de la programación básica porque resuelven problemas avanzados que no son para un primer curso y que requieren como base, muchos de los conceptos previos.

Una forma en la que podria implementarse sería utilizando una variable global para indicar si hubo un error en una operacion/función y en base a ello, definir una acción.

Resulta díficil (engorroso o tedioso) tener que verificar una variable despues de cada operación o función. Sería complicado de mantener un codigo en estas condiciones. Resulta poco viable.

De ser asi, seria un manejo por **reasunción**. Ya que al ser una manejo por condición, sigue siendo procedural la ejecución del lenguaje.

## C

En C, no se manejan las excepciones de forma nativa.
Si es posible una simulacion de manejo de excepciones o a traves de la libreria `<signal.h>`, se pueden manejar las excepciones que surjan durante la ejecucion.

A continuación, unos ejemplos de como simular un TRY CATCH en `C`.

La forma en que procede luego de la interrupción es de **terminacion de bloque**, es decir, que cuando finaliza el manejo de la excepción, termina la ejecucion del bloque en que se lanzo la excepción.

* Try Catch con solo un tipo de error [03\_ejemplos/try\_catch\_simple.c](03_ejemplos/try_catch_simple.c)

* Try Catch con varios posibles valores [03\_ejemplos/try\_catch\_varios.c](03_ejemplos/try_catch_varios.c)

# d. Conclusiones

Gobstones es un lenguaje cerrado y conciso, con una gramática bien definida. Por su simplicidad y claridad en las instrucciones, sumado a que deja de lado ciertos conceptos complementarios como entrada/salida, estructuras de datos o excepciones, resulta fácil de entender y aprender, lo que va en concordancia con su objetivo educaciona.

C, por otro lado, es un lenguaje que los tres conocemos porque fue el que elegimos en el seminario en segundo año. Lo consideramos un lenguaje robusto, de propósito general, una buena representación del hardware subyacente y, a nuestro criterio, algo que es muy importante conocer. 

Mientras usamos los lenguajes, no solemos tener en cuenta la forma en que se manipulan las variables por detrás; a veces uno se forma una idea aproximada de ello y a veces simplemente las usamos sin detenernos a pensar o investigar cómo es manejado. Lo que se aprendió en el trabajo se complementó con lo dado en la materia. Resultó interesante, en la práctica, conocer los diferentes tipos de variables existentes en los lenguajes de programación, así como luego, en el trabajo, ver cómo lo maneja un lenguaje como C en el mundo real.

Al conocer C, ya estábamos familiarizados con su gestión de los parámetros. Siendo curiosos por la programación funcional, fue llamativo que en el libro de Gobstones, que es un recurso de introducción a la programación, se posterga el concepto de *estado* en las variables. Esto indica un abordaje distinto al que conocemos como convencional, y a su vez se condice con algunos métodos de enseñanza de programación antiguos de universidades de gran prestigio como MIT y Berkeley, donde se priorizada el enfoque denotacional por sobre el operacional. Fue grato atar estos cabos.

Notamos la dicotomía en cuanto a la libertad (desde el punto de vista de las posibilidades ofrecidas al momento de producir código) entre Gobstones y C. Mientras que el primero nos lleva hacia un estilo concreto de diseño de software, que es justamente lo que intenta enseñar, el segundo es más abierto y permite afrontar los problemas desde diferentes perspectivas.