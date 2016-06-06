# Tipos de datos

La cosa arranca con los **datos**. Los progamas reciben datos de entrada, y producen datos de salida. Para manipular estos datos, los lenguajes de programación proveen **tipos**, que son **una forma de clasificar a los diferentes datos, a partir de los valores que podrían tomar y de las operaciones que se les podrían aplicar**.

Por ejemplo, el tipo de dato *boolean* podría tomar los valores `true` o `false`, y se le podrían aplicar las operaciones `and`, `or` y `not`.

Los lenguajes proveen **tipos predefinidos** (llamados *built-in types*), y proveen mecanismos para construir tipos compuestos más complejos a partir de estos.

## Built-in types

El hecho de que los lenguajes contengan un conjunto de tipos predefinidos nos aporta algunas ventajas:

* **Abstracción sobre la representación interna de los datos**: el programador no quiere preocuparse por cómo está representado en el hardware el número que está utilizando; quiere preocuparse por utilizarlo. Esto aumenta la **legibilidad** de los programas y su **portabilidad** sobre diferentes arquitecturas.
* **Chequeo en traducción de errores**: se puede verificar durante la traducción que las combinaciones de variables y operaciones son legales.
* **Resolución en traducción de operadores sobrecargados**: ya que se conocen los tipos de las variables utilizadas, se puede conocer a qué operador sobrecargado se está haciendo referencia en una instrucción. Por ejemplo, si `+` se utiliza para referenciar a más de una operación, saber que, en `a + b`, `a` y `b` son enteros, nos dice qué `+` queremos utilizar.
* **Control de la precisión**

Dentro de los tipos de datos predefinidos, podemos encontrar:

* **primitivos o elementales**: su valor es atómico, no puede ser descompuesto. La mayoría (integer, float, character, boolean)
* **no primitivos/no elementales**: su valor se compone de otros valores. Por ejemplo, el tipo de dato String a menudo se compone de una colección de datos de tipo Character.

## Tipos de datos compuestos

Además de los tipos de datos predefinidos, los lenguajes proveen formas de *componer* objetos a partir de tipos de datos existentes. Por ejemplo, se podría componer un objeto a partir de dos variables de tipo String `nombre` y `apellido`, y este objeto representaría a una persona. Se puede ir más lejos y crear un *nuevo tipo de dato* compuesto por otros datos: en este caso, `Persona` estaría compuesto por dos variables, `nombre` y `apellido`.

Para llevar a cabo las acciones descriptas en el párrafo anterior, los lenguajes constan de **constructores**; estos permiten:

* generar nuevas variables representantes de objetos compuestos de otros objetos, e.g., records y arrays, y/o
* generar nuevos tipos de datos compuestos de otros datos, e.g., records y arrays definidos como tipo.

*Un detalle a tener en cuenta es que, para los tipos compuestos y definidos por el usuario, el lenguaje provee **constructores**, y **no** tipos. Esto provoca que array o record **no** sean tipos built-in, sino **constructores***.

### Producto cartesiano

Cada instancia de este tipo de dato es una tupla (a1, ..., an), perteneciendo cada elemento a un dominio A1, ..., An, pudiendo verse como el producto cartesiano A1 x A2 x ... x An. Un poco más en criollo: tenemos campos y cada campo pertenece a un cierto tipo de datos. Provee las operaciones de acceso a los campos indicando el nombre de los mismos, y, en algunos lenguajes, de asignación y comparación.

### Correspondencia finita

Se define una función cuyo dominio será un conjunto finito de valores. O sea, se toma un conjunto finito de valores y se mapea un valor a cada elemento. Por ejemplo, se toma el subconjunto de enteros `1..10` (dominio) y se asigna `"uno"`, `"dos"`, ..., `"diez"`. Hay dos formas de definir los valores asociados: por *intención* o por *extensión*. Por *intención*, se especifica una regla a aplicar: por ejemplo, `f(x) = 2*x`; por *extensión*, se especifican todos los elementos de forma literal. Según la estabilidad de la ligadura con el dominio, una correspondencia finita puede ser:

* Ligada en compilación: el subconjunto de valores para los objetos se determina durante la compilación, y no puede modificarse una vez establecido. I.e., arrays en C.
* Ligada en ejecución
	* Estáticamente: cuando se crea una nueva instancia, se debe especificar el subconjunto de valores que conformará al dominio, lo que da lugar al establecimiento del dominio, que no se puede alterar luego. I.e., arrays semidinámicos en Ada.
	* Dinámicamente: el subconjunto de valores del dominio puede ser modificado en ejecución. I.e., arrays asociativos?

Estamos hablando de los **arrays**, claro. La operación básica provista es la de acceso al valor asociado a un elemento del dominio. A partir de allí, el elemento pasa a ser del tipo propio del elemento, por lo que admite las operaciones de este.

### Uniones y uniones discriminadas

En las **uniones**, se define un conjunto de campos, y, en un instante dado, el objeto contendrá el valor de uno de ellos. No se provee una forma de conocer cuál de los posibles campos está en uso actualmente. De allí surgen las **uniones discriminadas**, que contienen un campo adicional, usualmente un enumerativo, que indica dicha información. Pascal soporta uniones discriminadas, las cuales contienen un *tag field* que se asocia con el *data field*, resultando en que **no** se puede acceder a un *data field* que no es el asociado con el *tag field* actual. Como, en general, se utiliza el mismo espacio de datos para todos los *data fields*, si se cambia el *tag field* y no se inicializa el valor del *data field*, estaremos interpretando, desde el punto de vista del tipo de dato actual, la cadena de bits que se correspondía con el valor del *data field* anterior. Esto puede usarse a favor a propósito, o puede usarse mal sin querer, y causar problemas.

### Powerset

Dado un conjunto `c`, un dato de tipo `powerset(c)` puede tomar como valor cualquier subconjunto de `c`. Admite las operaciones de conjuntos.

### Sequencing

Files.. ???

### Recursion

Son tipos que pueden contener elementos de su mismo tipo. Por ejemplo, una `lista` puede estar compuesta por un dato `elemento` de tipo entero y otro `siguiente` de tipo `lista`. Los tipos recursivos también admiten que su valor sea nulo. De esta forma, tendríamos:

```
type list = {nil} U (integer x list)
```

También podríamos tener un árbol binario de enteros:

```
type bin_tree = {nil} U (integer x bin_tree x bin_tree)
```

Los lenguajes implementan este concepto mediante **punteros**, que son un tipo de dato cuyo valor representa una dirección en la memoria, o que puede ser simplemente `nil`. Así, un tipo de dato recursivo resulta en:

```
type list = {nil} U address
type list_element = (integer x list)
```

donde `address` deberá ser una dirección de memoria que contenga un dato de tipo `list_element`.

El asunto con los punteros es que pueden ser inseguros:

* **Tipado en los punteros**: en algunos lenguajes se especifica a qué tipo de dato apuntará un puntero. Si se lo quiere hacer apuntar a un dato de otro tipo, se produce un error. Esto impide que, por ejemplo, accedamos al contenido de una celda de memoria en la que se guardó la representación de un número y lo interpretemos como un caracter.
* **Aritmética de punteros**: los valores contenidos en los punteros son números que hacen referencia a una celda de memoria, y el lenguaje podría permitir que se trate a este valor como un número, dando lugar a que el programador lo modifique a gusto, lo que podría resultar en que acceda a posiciones de memoria indebidas.
* **Dangling pointers**: es peligroso que haya punteros apuntando a direcciones de memoria en las que ya no se encuentra la variable correspondiente. Por eso, los lenguajes deben tener en cuenta: los valores que se asignan a los punteros, el tiempo 
* **Punteros como uniones**: si se tuviera una unión con, por ejemplo, un puntero y un entero, al usarse el puntero, este podría tomar el valor del entero como dirección y apuntar a ese dato.

### Valores compuestos

Forma de expresar valores para un tipo de dato compuesto, sin necesidad de acceder a cada componente explícitamente. Por ejemplo:

```
struct compound {
	int x, y;
}
compound = {10, 20}; 
```

### Tipos definidos por el usuario y TADs

* **Datos compuestos** a partir de bult-in types
* Nombramiento de datos compuestos a partir de built-in types, formando así **tipos de datos definidos por el usuario**

Los dos mayores beneficios del uso de tipos son la *clasificación* y la *protección* de los datos. Mediante los tipos, el universo de los datos puede organizarse y así *clasificarse*, que es lo que se logra con el uso de **datos compuestos** y de **tipos de datos definidos por el usuario**. La parte de la *protección* viene dada por el control sobre las operaciones a llevar a cabo sobre los datos, la cual está presente intrínsecamente en los *built-in types*, y que se aplica sobre los *tipos compuestos* a través de los **tipos abstractos de datos**; estos últimos consisten en la definición de un tipo de dato compuesto, y de un conjunto de operaciones que se pueden realizar sobre él, todo ello encapsulado y oculto para el usuario (de las operaciones se encapsula la implementación, se muestra la interfaz).