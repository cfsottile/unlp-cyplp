# Conceptos y Paradigmas de Lenguajes de Programación

## Primer Trabajo Integrador

### Grupo 51

* 12222/0 - Sottile, Cristian Fabián
* 12469/2 - Eusebi, Cirano
* 12667/7 - Aparicio, Natalia Elizabeth

### Referencias

##### Punto 1

* Soporte
	* StackOverflow, respuestas a la pregunta *Where do I find the current C or C++ standard documents?*. [link](http://stackoverflow.com/questions/81656/where-do-i-find-the-current-c-or-c-standard-documents)
	* Sitio del estándar ISO/IEC 9899 de C. [link](http://www.open-std.org/jtc1/sc22/wg14/www/standards.html)
	* *The GNU C Reference Manual*. [link](http://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html)
	* Sitio oficial de Gobstones. [link](http://www.gobstones.org/)
	* Instrucciones de instalación de Gobstones. [link](http://www.gobstones.org/?page_id=30)
	* Sección Bibliografía, sitio oficial de Gobstones. [link](http://www.gobstones.org/?page_id=34)
	* Repositorio oficial de Gobstones en Github. [link](https://github.com/gobstones/pygobstones)
* Confiabilidad
	* Libro *The c programming language*, por Brian W. Kernighan y Dennis M. Ritchie.
	* Documentación de la página oficial de Gobstones: http://www.gobstones.org/?page_id=34 - SobreGobstones


##### Punto 2

* Libro: "The c programming language, Segunda edición" Autor: Brian W. Kernighan y Dennis M. Ritchie.
* Documentación de la página oficial de Gobstones: http://www.gobstones.org/?page_id=34 - Gramática de Gobstones versión 3.0
* Libro: Programming languages 3ra ed. Autor: Pratt, Terrence W.


##### Punto 3

* _`The C Programming Language` de Brian W. Kernighan & Dennis M. Ritchie, segunda edición_.
* _`Las bases conceptuales de la Programación` de Pablo E. Martínez López, versión digital revisión 10 de febrero de 2014_.


##### Punto 4

* C
	* StackOverflow, respuesta a la pregunta *Difference between static memory allocation and dynamic memory allocation*. [link](http://stackoverflow.com/a/15793111/4969879)
	* TutorialsPoint *C Programming Tutorial*, sections:
		* *C - Variables*. [link](http://www.tutorialspoint.com/cprogramming/c_variables.htm)
		* *C - Storage Classes*. [link](http://www.tutorialspoint.com/cprogramming/c_storage_classes.htm)
	* *glibc*, sección *Memory allocation and C*. [link](http://www.gnu.org/software/libc/manual/html_node/Memory-Allocation-and-C.html#Memory-Allocation-and-C)
	* Slide de Introduction to Data Structures de la Universidad de Californa en Santa Cruz. [link](https://classes.soe.ucsc.edu/cmps012b/Spring97/Lecture05/tsld014.htm)
	* StackOverflow, respuesta al hilo *Memory allocation for global and local variables*. [link](http://stackoverflow.com/a/11977703/4969879)
* Gobstones
	* Artículo *El nombre verdadero de la programación*, por Pablo E. Martínez López, Bonelli y Sawady O'Connor. [link-descarga](http://www.gobstones.org/bibliografia/Articulos/ElNombreVerdaderoDeLaProgramacion.pdf)
	* *Slides* de la charla *Sobre Gobstones*, por Pablo E. Martínez López. [link-descarga](http://www.gobstones.org/bibliografia/Charlas/SobreGobstones.pdf)
	* Libro *Bases conceptuales de la programación*, por Pablo E. Martínez López. [link-descarga](http://www.gobstones.org/bibliografia/Libros/BasesConceptualesProg.pdf)
	* Documento *Sintaxis de Gobstones 3.0*, por Pablo E. Martínez López y Eduardo A. Bonelli. [link-descarga](http://www.gobstones.org/bibliografia/otros/Gobstones.v3.0x-Grammar.pdf)

.

.

.

.

.

.

# Punto 1

## Confiabilidad

> La confiabilidad está relacionada con la seguridad:
>
> * *Chequeo de tipos*: cuanto antes se encuentren errores, menos costoso resulta realizar los arreglos que se requieran.
> * *Manejo de excepciones*: habilidad para interceptar errores en tiempo de ejecución, tomar medidas correctivas y continuar.

### C

##### Chequeo de tipos

El chequeo de tipos se hace en tiempo de compilación. Los compiladores advierten de la mayoría de los errores de tipo, y no hay conversión automática de tipos de datos incompatibles. Sin embargo, C conserva la filosofía básica de que los programadores saben lo que están haciendo.

##### Manejo de excepciones

A través de la librería `<signal.h>`, se pueden manejar las excepciones que surjan durante la ejecución como una señal de interrupción externa o un error en la ejecución.

### Gobstones

##### Chequeo de tipos

Se permite invocar definiciones que esperan expresiones de un determinado tipo con expresiones de cualquier otro tipo, incluso cuando su uso es incorrecto. No obstante, si esto sucede el programa falla al ser ejecutado.
Sin embargo, permite la verificación para los tipos de datos, chequeando de alguna forma en que casos su uso es correcto. Sin embargo, esta característica es opcional, y puede no estar disponible en todas las versiones de la herramienta.

##### Manejo de excepciones

No tiene herramientas para el manejo de excepciones ya que este concepto no aporta a la comprensión de la programación básica, resuelven problemas avanzados que no son para un primer curso y requieren como base otros conceptos previos.## Soporte

###  Facilidad de acceso al compilador o intérprete

##### Gobstones

El software disponible para correr Gobstones es un IDE que incluye el intérprete. Está licenciado bajo la GNU General Public License (GPL), y tanto el software como su código fuente están disponibles para descargarse en el sitio oficial del lenguaje.

##### C

Hay muchas implementaciones de compiladores de C, algunos de ellos de dominio público, como *GCC (GNU Compiler Collection)* cuya licencia es GPL.

###  Soporte multiplataforma

##### Gobstones

Para correr el IDE de Gobstones se requiere tener instalado Python 2.7 y PyQt4. Dado que:

* la *audiencia* del lenguaje es el público general interesado en aprender a programar
* es altamente probable que este público general sea usuario de alguno de los tres sistemas operativos más ampliamente utilizados (Windows, OS X y Linux)
* para ejecutarse, el IDE de Gobstones requiere de los programas Python 2.7 y PyQt4
* Python 2.7 y PyQt4 están disponibles en los sistemas operativos antes descriptos

es correcto decir que cumple a la perfección con sus requerimientos de soporte multiplataforma.

##### C

Su *público* es muy amplio. Su naturaleza cercana al bajo nivel ha llevado a que se escriban compiladores para diversos dispositivos y plataformas. Es probable que, cualquiera sea la plataforma para la que se está escribiendo el código, C esté soportado.

### Recursos para el aprendizaje del lenguaje

##### Gobstones

Posee un libro llamado *Las Bases Conceptuales de la Programación* que provee una amplia introducción al lenguaje. Explica sus diferentes componentes y el porqué de las diferentes decisiones de diseño e implementación tomadas. También hay un documento expositor de la sintaxis, expresada en términos de una BNF con algunas adiciones. Hay otros dos documentos: uno de investigación y una presentación introductoria general. Dentro del IDE antes mencionado se pueden encontrar ejemplos de programas escritor en el lenguaje.

##### C

El lenguaje C está estandarizado. El actual es *ISO/IEC 9899:2011*, comúnmente llamado *C11*. Este estándar se puede comprar y podría usarse para aprender el lenguaje. Sin embargo, esta tarea podría resultar muy ardua para alguien que se está iniciando. El libro de mayor alcance sobre C, su estándar y sus buenas prácticas es *The C Programming Language*, escrito por Brian W. Kernighan y Dennis M. Ritchie (creador del lenguaje). Otro buen recurso es *The GNU C Reference Manual*, que cubre C89, C99 y las extensiones a C de GNU. También se puede encontrar una gran variedad de tutoriales y cursos online, algunos de ellos publicados y/o impartidos por las prestigiosas universidades del mundo.

# Punto 2

> Identifique las características principales de la sintaxis y realice la gramática en EBNF de una variable en ambos lenguajes asignados.

## Características de la sintaxis

### C

* Un bloque está comprendido por las sentencias encerradas entre `{` `}`.
* Los identificadores son separados por carácteres de espaciado.
* Las sentencias son separadas por `;`.
* La indentación o espaciado extra es irrelevante para la evaluación de sentencias.

  **Ejemplo:**

  ```C
  // La indentación no es tenida en cuenta por el programa.
  int main()
  {
  int a = 5;
      int b = 3;
            float c = a / b;int d;
      return 0;
  }
  ```

* Varias variables del mismo tipo pueden ser declaradas en la misma sentencia.

  **Ejemplo:**

  ```C
  int main()
  {
    int a, b, c;
    a = 2;
    b = 3;
    c = 4;
    return 0;
  }
  ```
* El operador de asignación es `=`.
* El operador de comparación es `==`.
* El operador de invocación es `()`.

  **Ejemplo:**

  ```C
  #include <stdio.h>
  void say_hi()
  {
    printf("Hello\n");
  }

  int main()
  {
    say_hi();
    return 0;
  }
  ```
* Para hacer comentarios se utiliza el simbolo `//` se utiliza para indicar comentarios de linea, y los simbolos `/*` y `*/` para encerrar comentarios de parrafo.

### Gobstones

* Gobstones basa mucha de su sintaxis en C, aunque con algunas variaciones, normalmente a esas sintaxis se las denomina _C like_.
* Un bloque está comprendido por las sentencias encerradas entre `{` `}`.
* Los identificadores son separados por carácteres de espaciado.
* Las sentencias son separadas por `;`.
* La indentación o espaciado extra es irrelevante para la evaluación de sentencias.

    **Ejemplo:**
    ```
    // La indentación no importa.
    program {
  	a:= 1;b:= 2;
  		c:=3;

    d:=4;
    }
    ```

    * El operador de asignación es `:=` _diferente a C_.
    * El operador de comparación es `==`.

    **Ejemplo:**
    ```
    // La indentación no importa.
    program {
      while (nroBolitas(Azul)==5){
        Poner(Azul)
      }
      return (5)
    }
    ```

    * El operador de invocación es `()`.

    **Ejemplo:**
    ```
    procedure DibujarCuadradoNegroDeLado3()
    {
      Mover(Norte); Poner(Negro); Mover(Norte); Poner(Negro)
      Mover(Este); Poner(Negro); Mover(Este); Poner(Negro)
      Mover(Sur); Poner(Negro); Mover(Sur); Poner(Negro)
      Mover(Oeste); Poner(Negro); Mover(Oeste); Poner(Negro)
    }
    program {
      DibujarCuadradoNegroDeLado3();
    }
    ```

En GOBSTONES coexisten 3 estilos de comentarios.
En el estilo C-like, el simbolo // se utiliza para indicar comentarios de linea, y los simbolos `/*` y `*/` para encerrar comentarios de parrafo.
En el estilo HASKELL-like, el simbolo -- indica comentarios de linea, y los simbolos `{-` y `-}` encierran comentarios de parrafo.
Finalmente, en el estilo PYTHON-like, el simbolo # indica comentarios de linea y el simbolo `’’’` indica el inicio y fin de los comentarios de parrafo

    **Ejemplo**
    ```
    {-
    Autor: Fidel
    Fecha: 08-08-08
    -}
    procedure DibujarLineaNegra2HaciaElNorte()
        {-
        PROPOSITO:
          Dibujar una linea negra de longitud 2
          hacia el norte de la celda actual.
        PRECONDICION:
          Debe haber al menos dos celdas al Norte de la actual.
          (O sea, el cabezal no puede encontrarse ni en la ultima
          ni en la ante ultima fila)
        -}
        {
        -- No se dibuja en la celda incial
        Mover(Norte); Poner(Negro)  -- Dibuja en la celda
                                    -- al Norte de la inicial
        Mover(Norte); Poner(Negro)  -- Dibuja en la celda dos
                                    -- lugares al Norte de la
                                    -- inicial
        -- Al terminar el cabezal se encuentra dos lugares
        -- al Norte de donde comenzo
    }
    program {
          DibujarLineaNegra2HaciaElNorte()
    }

    ```

## ENBF de una variable

### C
    G = (N, T, S, P)
    N = {<varname> <name> <letter> <digit> <reserved>}
    T = { 0..1, "a".."z", "A".."Z", " _ " }
    P = {
      <varname> ::= ( <name> / <reserved> );
      <name> ::= ( "_" | <letter>) { (<letter> | <digit> | "_" ) }*

      <letter> ::= "a"..z", "A".."Z"
      <digit> ::= 1, 2, 3, 4, 5, 6, 7, 8, 9, 0
      <reserved> ::= auto, double, int, struct, break, else,
        long, switch, case, enum, register, typedef, char, extern,
        return, union, const, float, short, unsigned, continue,
        for, signed, void, default, goto, sizeof, volatile,
        do, if, static, while
    }


### Gobstones

    G = (N, T, S, P)
    N = {<varname> <name> <letter> <digit> <reserved>}
    T = { 0..1, "a".."z", "A".."Z", "’", "-" }
    P = {
      <varname> ::= (<lowname> / <reserved>)
      <lowname> ::= <minus> { (<minus>|<mayus>|<car_esp>) }*

      <minus> ::= "a".."z"
      <mayus> ::= "A".."Z"
      <car_esp> ::= "’", "-"
      <digits> ::= <nonzerod> {<digit>}*
      <nonzero>::= 1,2,3,4,5,6,7,8,9
      <digit> ::= <nonzero>, 0

      <reserved> ::= if, then, else, not, True, FalseVerde, Rojo,
        Azul, NegroNorte, Sur, Este, Oesteswitch, to, while,
        repeat, Skip, foreach, ininteractive, program, procedure,
        function, returnMover, Poner, Sacar, IrAlBorde, VaciarTablerodiv,
        mod, siguiente, previo, opuestohayBolitas, nroBolitas,
        puedeMoverminBool, maxBoolminDir, maxDirminColor, maxColor

# Punto 3

> Enuncie las las diferencias existentes respecto de la asignación e inicialización por defecto de variables entre ambos lenguajes. Ejemplifique.

Se iniciará desarrollando las diferentes capacidades a la hora de delcarar variables y luego se sintetizará en un cuadro comparativo.

## C

* Cuenta con 4 tipos de variables: _char, int, float y double_.
	* _short y long_ se pueden aplicar solamente al tipo _int_ para modificar su tamaño, pudiendose acortar entonces _short int_ a simplemente _short_.
	* _signed y unsigned_ se pueden aplicar a los tipos _char e int_ para denotar si se debe utilizar un rango estrictamente positivo o no. Depende del compilador determinar si por defecto un _char o int_ son _signed o unsigned_.
* El atributo tipo de la variable se bindea cuando el código se compila y no puede ser modificado.
* Permite conversión implícita para los tipos primitivos:
	* char < short < int < long < long long
	* float < double < long double
	* long long < float

	_Estas conversiones denotarán un warning en compilación ya que puede perderse información en la conversión._

	* ( [unsigned]char | [unsigned]short ) > [unsigned]int

	_Esta conversión se la denomina Integer Promotion._

* Permite la conversión explícita de tipos a partir de la expresión: ```(<tipo>)<expresión>```. Errores producidos por conversiones explícitas son detectados en tiempo de compilación.

	**Ejemplo Conversión implícita:**

	```C
	/* Este código que puede parecer lógico en realidad es erróneo.
	 * Dado que la conversión implícita int > float se hace luego de la división,
	 * el cociente retornado proviene de la división entera entre a y b.
	 */
	#include <stdio.h>
	int main()
	{
		int a = 5;
		int b = 3;
		float c = a / b;
		printf("%d/%d = %f\n", a, b, c);
		return 0;
	}
	```

	**Ejemplo Conversión explícita:**

	```C
	/* Este código es correcto.
	 * Dado que la conversión explícita int > float de "a" se realiza antes de la división,
	 * C se encarga de hacer la conversión implícita de B, realizando la división en punto flotante.
	 * No se hace ninguna conversíon del cociente antes de asignarse a "c".
	 */
	#include <stdio.h>
	int main()
	{
		int a = 5;
		int b = 3;
		float c = (float)a / b;
		printf("%d/%d = %f\n", a, b, c);
		return 0;
	}
	```

* La inicialización por defecto en C es algo compleja, dependiendo de los modificadores de vida de las variables, éstas son inicializadas de manera distinta.
	* Variables _static_ y _external_ son inicializadas en 0 por defecto antes de comenzar el programa.
	* Variables _auto_ son inicializadas cada vez que se entra a la función o bloque que las contiene con un _initializer_\* que puede ser cualquier expresión. Aquellas variables _auto_ que no tengan un _initializer_ definido, son inicializadas con contenido **indefinido**(basura).
	* Todas las demás variables son inicializadas antes de la ejecución del programa con un _initializer_ sin embargo, la inicialización generada es _const_\**.
		* \* _Se denomina initializer a cualquier expresión:_ ```<tipo> <identificador> = <initializer>```
		* \*\* _Se denota con **const** a un método, variable o expresión cuando se prohibe la posibilidad de modificar los valores en uso._

		**Ejemplo Inicialización de variables:**

		```C
		#include <stdio.h>
		int main()
		{
			static double f;
			int a, i;
			for (i = 0; i < 2; i++) {
				auto int b;
				printf("a= %d and b= %d and f= %f\n", a, b ,f);
				f = 1;
				a = 2;
				b = 3;
			}
			return 0;
		}
		```

		**Ejemplo Inicialización const:**

		```C
		/* Este ejemplo tira un error de compilación,
		 * dado que C detecta que se está intentando asignar un valor sobre una variable marcada como const (arr&).
		 */
		#include <stdio.h>
		int main()
		{
			int arr[1] = {1};
			arr = {2};
			printf("%d\n", arr[0]);
			return 0;
		}
		```

---
## Gobstones
> Las variables en ```GOBSTONES``` son meramente nombres con los que se recuerdan ciertos valores. Esta idea tiene apenas una relacion vaga con la noción de _posicion de memoria_ con la que tradicionalmente se asocia la idea de variable en los lenguajes de programacion tradicionales. La noción de variables que manejamos en ```GOBSTONES``` tiene mucha mas relación con la idea que se tiene en matematicas, donde las variables son meramente valores que se desconocen en un momento dado.


* Cuenta con 4 tipos de variables: _Color, Número, Dirección y Booleano_.
* El atributo tipo de la variable se bindea en la primera asignación de la variable y nunca puede ser modificado.
* No cuenta con ningún tipo de conversión implícita o explícita de tipos. Errores pertinentes a asignaciones de tipos diferentes son detectados en tiempo de ejecución.
* El atributo valor de la variable se bindea en la primera asignación de la variable.
* No cuenta con ningún tipo de asignación de valores por defecto, ya que no cuenta con ninguna expresión que permita declarar una variable sin valor y el símbolo no es reconocido hasta que ocurre la asignación de valores.


---
## Comparación
|Propiedad|Gobstones|C|
|:---:|:---:|:---:|
|Variables Tipadas|**Sí**|**Sí**|
|Tipos de variable|_Color, Número, Dirección, Booleano_| _char, int, float, double_|
|Binding de Tipo|**Dinámico**|**Estático**|
|Momento de binding de Tipo|_Ejecución_|_Compilación_|
|Permite modificación de Tipo*|**No**|**No**|
|Permite conversión de Tipo**|_No_|_Conversión implícita y explícita_|
|Binding de Valor|**Dinámico**|**Dinámico**|
|Incialización por Defecto|_No_|_Sí_|
|Valores de inicialización|**N/A**|**_static, extern_: 0, _auto_: _initializer_/indefinido, restantes:_const initializer_/0**|



* \* _Llamamos modificación de tipo a la posibilidad de modificar el atributo tipo de una variable luego de ser asignado por primera vez._
* \** _Llamamos conversión de tipo a la posibilidad de modificar el atributo tipo al cual evalúa una variable o expresión._

# Punto 4

> Determine los tipos de variable de acuerdo al momento de ligadura con el lvalor con que cuenta cada lenguaje. Ejemplifique la forma en que simularía (en caso de no poseerla) una variable de tipo estática. En el caso en que cuente con este tipo de variables ejemplifique la diferencia con una variable global. Utilice el compilador de los lenguajes asignados que se encuentra en el sitio [tutorialspoint](http://www.tutorialspoint.com/codingground.htm).

## C

### Tipos de variables

Los tipos de variables de acuerdo al momento de la ligadura con el _l-valor_ son:

* Estáticas
* Automáticas
* Dinámicas

##### Variables *estáticas*

La memoria se asigna **cuando se lanza el programa** y se mantiene durante toda la ejecución. Así funcionan las variables globales y las definidas con el modificador `static`. Por defecto, el *r-value* se inicializa en 0.

```
int global_var;

int func() {
	static int static_var;
}

int main() {
	// ...
}
```

##### Variables *automáticas*

La asignación de la memoria se produce **al ingresar a la función o bloque**; cuando se sale, la misma se libera. Todas las variables definidas localmente funcionan así por defecto, y opcionalmente se puede explicitar el modificador `auto`.

```
int func() {
	int auto_var3;
	auto int auto_var4;
}

int main() {
	int auto_var1;
	auto int auto_var2;
	// ...
}
```

##### Variables *dinámicas*

Se asigna la memoria **de forma manual**, mediante las funciones `calloc()` o `malloc()`. Se libera mediante la función `free()`. Esta es la forma en que se manejan los *punteros*.

```
#include <stdlib.h>

int main() {
	// auto_var es una variable automática de tipo puntero a int
	int * auto_var;
	// malloc() genera una variable dinámica, cuyo
	// l-value se almacenará en el r-value de auto_var
	auto_var = malloc(sizeof(int)); 
	// ...
}
```

### Variables *estáticas* vs. *globales*

En el caso de C, las variables *globales* **son** *estáticas*. Se les asigna un espacio de memoria desde el momento en que se ejecuta el programa, y lo mantienen hasta que este termina. El código

```c
int global_var;

int main() {
	// ...
}
```

genera código *assembly* que contiene a la variable `global` en la sección de datos, cargándose la misma al lanzar el programa.

## Gobstones

### Tipos de variables

En Gobstones no se especifica formalmente el momento en que se liga el *l-value* a las variables. Sin embargo, dado que:

1. las variables no se deben definir, simplemente se inicializan,
2. el *tipo* se liga en tiempo de ejecución (más concretamente al momento de ejecutar la sentencia de inicialización), y
3. para conocer el espacio necesario para almacenar una variable, es probable que requeramos conocer su tipo,

se puede deducir que el *l-value*, así como el *tipo*, se liga en la sentencia de inicialización.

Ya que la asignación de la memoria y la ligadura del correspondiente *l-value* se provocan al ejecutarse la inicialización (que hace también las veces de definición), podemos decir que las variables son *dinámicas* según el *binding time* de su *l-value*.

### Simulación de una variable *estática*

Tomando como *variables de tipo estáticas* a aquellas que *están cargadas en memoria desde el inicio hasta el fin del programa*, y dado que suponemos que el lenguaje carga a las variables en el momento de su definición, lo más similar a una variable estática que podríamos obtener en un programa Gobstones sería una que se encuentre definida en la primer sentencia del programa.