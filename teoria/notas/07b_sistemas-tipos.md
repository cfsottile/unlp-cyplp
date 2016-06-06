### Compatibilidad de tipos

Los sistemas de tipos pueden requerir que las operaciones que se llevan a cabo sobre parámetros especifiquen el tipo de estos. A su vez, pueden presentar cierta flexibilidad al momento de determinar si un parámetro de un tipo dado es válido para la función.

* *name compatibility*: sólo los datos del mismo tipo son aceptables.
* *structural compatilibity*: un tipo de dato es compatible con otro si:
	* es del mismo tipo (*name compatibility*), o
	* está compuesto por componentes que son del mismo tipo.

Por ejemplo:

```
typedef struct {
	float x, y;
} s1;

typedef struct {
	float x, y;
} s2;
```

Si el sistema de tipos adoptara la compatibilidad por nombre, `s1` y `s2` serían incompatibles. Si adoptara la compatibilidad estructural, serían compatibles.

Compatibilidad adoptada por lenguajes:

* C: compatibilidad estructural para todos los tipos menos para los `structs`, que presentan compatibilidad por nombre.
* Pascal: a priori, se dejó en manos de las implementaciones; luego, ISO Pascal definió una compatibilidad mayormente por nombre.
* Ada: compatibilidad por nombre. Sin embargo, mediante que el lenguaje introduce el concepto de *subtipo*, los subtipos de un mismo tipo son compatibles.
	* Cuando se genera una variable a partir de un constructor de tipos compuestos, se genera un tipo anónimo, y ese tipo anónimo es el que vale para la compatibilidad. Así, dos arrays declarados de igual forma como `array (INTEGER range 1..10) of INTEGER` no serán compatibles ya que sus tipos de datos asociados son diferentes.

### Conversión de tipos

Cuando una operación espera un objeto de tipo T1 y recibe uno de tipo T2, siendo T1 y T2 incompatibles, se podría intentar aplicar una *conversión* del tipo T2 a T1. Así, si tuviéramos por ejemplo 

```
func: T1 -> R1
x: T2
y: R2
```

y quisiéramos asignar a `y` el resultado de aplicar `func` a `x`, tendríamos dos problemones. El primero es que hay que transformar `x` a `T1`. Luego se llevaría a cabo la operación `func(x)` y esto nos daría como resultado un dato de tipo `R1`, según la especificación de `func`, lo que nos da el segundo problemón: hay que transformar el resultado de `R1` a `R2` para poder asignarlo a `y`.

```
t21: T2 -> T1
r12: R1 -> R2
```

Así, `y = func(x)` se transformaría en `y = r12(func(t21(x)))`.

Los lenguajes adoptan sistemas de conversión. Por ejemplo, C realiza las conversiones de forma automática y permite que se hagan conversiones de forma explícita, mientras que Ada admite conversiones explícitas y no las lleva a cabo de forma implícita.

La automatización de las conversiones puede ser útil para evitar explicitar conversiones triviales, pero puede quitar legibilidad, ya que deja de ser claro qué es lo que ocurre en cada caso, principalmente en las conversiones que se dan en operadores sobrecargados.

### Subtipos

En general, y viendo a los tipos como un conjunto de valores y operaciones, los **subtipos** son un subconjunto de los valores de un tipo junto con (por simplicidad) todas sus operaciones. Los lenguajes definen reglas de compatibilidad para los subtipos:

* en Pascal, los únicos subtipos que se pueden definir son subrangos de tipos discretos ordinales (integers, character, enumerations). Si se recibe un objeto de tipo T donde se espera uno de tipo R, hay compatibilidad "directa" si R y T son subtipos de otro tipo Q o si T es subtipo de R. Si T es supertipo de R, se deben realizar chequeos para verificar que el valor de T está contenido en el subconjunto de valores de R.
* en Ada, un subtipo de un array limita su dominio, el de un registro variante *elige* una de las variantes, y el de los tipos discretos orginales toma un subrango de valores contínuos. No se generan nuevos tipos (los subtipos de un tipo T son también de tipo T) sino que se indica al compilador que en runtime chequee que los valores recibidos se correspondan con los definidos por el subtipo.

### Tipos genéricos

Es útil poder definir tipos que manipulen un cierto dato sin especificar el tipo de este dato. Ke. Por ejemplo, el comportamiento de una estructura de datos pila será igual para todas las pilas, sin importar el tipo de dato que esté almacenando. Los tipos parametrizados genéricos permiten *postergar* el momento de especificación de un cierto tipo. Por ejemplo:

```
TAD stack
push: stack(T) x T -> stack(T)
pop: stack(T) -> T
```

El momento en que se define T depende del lenguaje. En Ada y en C++, los tipos genéricos son instanciados en tiempo de compilación, ligándose T con un tipo de dato conocido. Así, T queda estáticamente ligado a un tipo, y se pueden realizar los chequeos para asegurar la *type safety*. En otros lenguajes, se lleva a cabo de otra manera.

### Sistemas de tipos monomórficos y polimórficos

Monomorfismo y polimorfismo son términos que hacen alusión a la flexibilidad de un sistema de tipos para con los parámetros de las operaciones. El monomorfismo no tiene flexibilidad: los tipos de los parámetros reales deben ser los mismos que los de los parámetros formales. El polimorfismo es el que introduce la flexibilidad. Hay distintos tipos:

##### Polimorfismo **ad-hoc**

* **Sobrecarga**: el lenguaje usa un mismo nombre para referirse a un conjunto de funciones, y el contexto determina a cuál de todas ellas se está haciendo referencia en un cierto programa. Por ejemplo:

```
(1) +: float x float -> float
(2) +: integer x integer -> integer

int a, b;
float x, y;

a + b; => llama a (1)
x + y; => llama a (2)
```

* **Conversión**: transformaciones llevadas a cabo sobre los parámetros reales para que coincidan con los tipos de los parámetros formales. Por ejemplo:

```
+: float x float -> float

int a;
float x;

x + a; => se convierte `a` a float para que los tipos sean compatibles
```

##### Polimorfismo **universal**

* **Inclusión**: los parámetros actuales deben ser *subtipos* de los tipos de los parámetros formales.
* **Paramétrico**: las funciones operan de igual forma sobre diferentes tipos, los cuales son especificados como parámetros. Las rutinas genéricas de ML son un ejemplo, no así las de Ada, que son instanciadas en compilación y por lo tanto resultan en una suerte de polimorfismo ad-hoc.
* **Dinámico**: no se entiende, pero aparentemente no importa nada, y no se podría proveer un sistema de tipos fuerte (estimo que aquí por *fuerte* quiere decir *seguro*).