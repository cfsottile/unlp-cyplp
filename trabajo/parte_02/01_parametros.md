> Realice una comparación respecto de la utilización de parámetros y los diferentes modos que implementa. Ejemplifique.

## C

El pasaje de parámetros en C se lleva a cabo mediante **ligadura posicional** y **por copia**. Para cada parámetro formal, se especifica una expresión cuyo valor será asignado a los parámetros formales, los cuales son variables locales a la función. Por ejemplo:

* si la expresión correspondiente al parámetro real es un literal `5`, se asigna al parámetro real el valor `5`;
* si la expresión es un identificador de una variable, se asigna el valor de la variable;
* si la expresión es una invocación a una función, se asigna el valor de retorno de la misma.

Es posible especificar que el *r-valor* del parámetro formal no pueda cambiarse, mediante el modificador `const`. Uno podría verse tentado a afirmar que esto incurre en la implementación del pasaje de parámetros *por copia constante*, pero no es el caso, ya que el lenguaje no asegura que el parámetro real no pueda modificarse (usando punteros uno podría modificar objetos de datos externos a la función).

Ejemplo:

```
void fun(int x, const int y) {
	x = 11; // `x` es un valor local a la función, sin
	        // relación alguna con el parámetro real `a`
	y = 21; // operación ilegal
}

int main() {
	int a = 10, b = 20;
	fun(a, b);
	printf("a: %d", a); // imprime "10"
	printf("b: %d", b); // imprime "20"
}
```

Si bien no se provee un mecanismo automático para el pasaje de parámetros por referencia, esto puede realizarse mediante punteros. *Es importante destacar, previo a la explicación, que el operador `&` aplicado sobre una variable obtiene un puntero hacia esa variable.*

1. Se declara al parámetro formal como de tipo puntero.
2. Se pasa como parámetro real un puntero a un objeto de datos.
3. La copia se hace desde el valor del parámetro real hacia el del parámetro formal, permitiendo que mediante el segundo se acceda al dato que es referenciado por el primero.

Ejemplo:

```
void fun(int *c) {
	// desreferencio el puntero `c`, lo que me da un objeto
	// de datos al que le incremento el valor en 1
	(*c)++;
}

int main() {
	int a;
	int *b;
	
	a = 5;
	b = malloc(sizeof(int));
	*b = 10;
	
	// pasaje de un puntero al objeto de datos `a`, obtenido mediante `&a`
	printf("%d", fun(&a)); // imprime "6"
	// pasaje del puntero b
	printf("%d", fun(b)); // imprime "11"
}
```

##### Referencias

* [Diapositivas de la cátedra - Clase sobre parámetros](https://catedras.info.unlp.edu.ar/mod/resource/view.php?id=16698)
* [The C Programming Language](http://www.amazon.com/Programming-Language-Brian-W-Kernighan/dp/0131103628) - Sección 1.8
* [The GNU C Reference Manual - Sección 5.4: Function Parameters](http://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Function-Parameters)