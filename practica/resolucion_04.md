## Ejercicio 1

**a)**

## Ejercicio 3

##### Variable estática

Son cargadas en la memoria junto con el programa; su l-value se encuentra definido antes de que comiencen a ejecutarse las sentencias del programa.

##### Variable automática o semiestática

Viven dentro del registro de activación de la unidad que las define. Son cargadas en memoria junto con este, y son descartadas de la memoria también junto con este. Su l-value se define en el momento en que son cargadas.

Otra forma de expresarlo: son automáticamente cargadas en memoria cuando la ejecución del programa ingresa a su *scope*, y descargadas cuando el flujo sale de su *scope*.

##### Variable dinámica

Su l-value se determina en ejecución mediante la acción explícita del programador.

##### Variable semidinámica

???

## Ejercicio 4

**a)** *Variable local*: están definidas en el contexto de una unidad de programa, y su alcance se ve limitado a dicha unidad de programa. Por ejemplo, una variable `int a` definida dentro de una función, será local y su alcance estará reducido a esa función.

*Variable global*: son variables que pueden ser accesibles desde cualquier punto en el programa; es decir, su alcance se extiende a todo el programa. Por ejemplo, las variables definidas fuera de las funciones en C o las variables definidas con `$` en Ruby.

**b)** Sí: las variables `static` de C, cuyo binding para el l-value se realiza en compilación, lo que lleva a que vivan durante toda la ejecución del programa, más allá de cuál sea su alcance.

**c)** Una variable global *no necesariamente* será estática. En los lenguajes compilados esto tiende a ser así, pero en los interpretados no ya que las variables son creadas en el momento en que se alcanza la sentencia de su definición.

**d)** El l-value de las variables *estáticas* queda parcialmente determinado en la compilación. Una *constante* puede ser automática, con lo que su l-value se conocería recién en ejecución.

## Ejercicio 6

En ambos casos la variable `x` formaría parte del segmento de datos del programa y sería cargada antes de comenzar con la ejecución. El comportamiento sería el mismo.

