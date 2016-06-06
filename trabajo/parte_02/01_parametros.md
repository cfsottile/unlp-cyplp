# a. Parámetros

## C

El pasaje de parámetros en C se lleva a cabo mediante **ligadura posicional** y **por copia**. Para cada parámetro formal, se especifica una expresión cuyo valor será asignado a los parámetros formales, los cuales son variables locales a la función. Por ejemplo:

* si la expresión correspondiente al parámetro real es un literal `5`, se asigna al parámetro real el valor `5`;
* si la expresión es un identificador de una variable, se asigna el valor de la variable;
* si la expresión es una invocación a una función, se asigna el valor de retorno de la misma.

Es posible especificar que el *r-valor* del parámetro formal no pueda cambiarse, mediante el modificador `const`. Uno podría verse tentado a afirmar que esto incurre en la implementación del pasaje de parámetros *por copia constante*, pero no es el caso, ya que el lenguaje no asegura que el parámetro real no pueda modificarse (usando punteros uno podría modificar objetos de datos externos a la función).

Ejemplo: [por valor](01_ejemplos/value.c)

Si bien no se provee un mecanismo automático para el pasaje de parámetros por referencia, esto puede realizarse mediante punteros. *Es importante destacar, previo a la explicación, que el operador `&` aplicado sobre una variable obtiene un puntero hacia esa variable.*

1. Se declara al parámetro formal como de tipo puntero.
2. Se pasa como parámetro real un puntero a un objeto de datos.
3. La copia se hace desde el valor del parámetro real hacia el del parámetro formal, permitiendo que mediante el segundo se acceda al dato que es referenciado por el primero.

Ejemplo: [simulando referencia](01_ejemplos/kind_of_reference.c)

## Gobstones

En la documentación del lenguaje se presenta a los parámetros como un mecanismo para poder definir valores que se usan en la rutina desde fuera de la misma. La ligadura se lleva a cabo de forma **posicional**. No se especifica si la copia se realiza por valor o por referencia, pero, dado que:

* los identificadores correspondientes a parámetros no pueden usarse como l-valor en una asignación, y que
* no existe el concepto de variable *no local* ni *global*,

podemos decir que el pasaje de parámetros se realiza **por copia constante**, ya que estamos ante un contexto en el que los parámetros reales no pueden ser modificados desde la rutina llamada.

Ejemplo: [parámetros en Gobstones](01_ejemplos/gobstones_params.gbs)

##### Referencias

* [Diapositivas de la cátedra - Clase sobre parámetros](https://catedras.info.unlp.edu.ar/mod/resource/view.php?id=16698)
* [The C Programming Language](http://www.amazon.com/Programming-Language-Brian-W-Kernighan/dp/0131103628) - Sección 1.8
* [The GNU C Reference Manual - Sección 5.4: Function Parameters](http://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Function-Parameters)
* Libro *Bases conceptuales de la programación*. [link-descarga](http://www.gobstones.org/bibliografia/Libros/BasesConceptualesProg.pdf)