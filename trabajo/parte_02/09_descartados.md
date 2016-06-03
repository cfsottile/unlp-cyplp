* Un *objeto* es una región manipulable de la memoria.

* Un *l-valor* es una referencia a un objeto. Una *expresión l-valor* es una expresión cuyo resultado es un *l-valor*. El identificador de una variable constituye una *expresión l-valor*.

* Los punteros son un tipo de dato que almacena valores enteros.

* El operador unario `*` se aplica sobre punteros y representa *indirección*: toma el valor entero del puntero, lo interpreta como una dirección de memoria, y retorna un *l-valor* que refiere al objeto correspondiente a dicha dirección. Por ejemplo: dado el puntero `char *p = 1000`, la expresión `*p` retornará un *l-valor* refiriendo al `char` almacenado en la dirección `1000`.

* El operador unario `&` se aplica sobre *expresiones l-valor* y retorna un puntero hacia el objeto que era referencia del *l-valor*. Por ejemplo: dada una variable `int a = 5`, que se encuentra almacenada en la dirección `1000` de memoria, `&a` arrojaría como resultado un puntero con valor `1000`.

Al invocar a una función, 
