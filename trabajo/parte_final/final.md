## a\.

Las dudas que nos quedaron con respecto al lenguaje son:

### Sintáxis

__1__\. Siendo un lenguaje tan alejado de C en la mayoría de los aspectos, __¿por qué se elige una sintáxis C-like?__

### Ligadura entre una variable y su tipo

__2__\. En el trabajo elaboramos la siguiente conclusión sobre el momento en que se ligan las variables con su tipo.

> Considerando que **1)** las variables no se definen, directamente se inicializan, **2)** el tipo se liga en la inicialización, y **3)** para asignar espacio de memoria debemos conocer el tamaño requerido, el cual está dado por el tipo; podemos deducir que el *l-valor* se liga en la sentencia de inicialización, lo que hace a las variables **dinámicas** según el *binding time* del *l-valor*.

Por otro lado, dado que Python presenta el mismo tipo de variables [1], y que Gobstones está implementado sobre dicho lenguaje, podemos suponer que estábamos en lo cierto.

__¿Es nuestro planteo correcto?__

[1] Stack Overflow - *Memory allocation types by moment of lvalue binding in Python*. [link](http://stackoverflow.com/questions/29733309/memory-allocation-types-by-moment-of-lvalue-binding-in-python)

### Pasaje de parámetros

__3__\. El pasaje de parámetros en Gobstones es **por valor constante**, ya que se realiza una copia del valor contenido en el parámetro real hacia el parámetro formal, y *no se puede* modificar al parámetro real desde la unidad invocada. __¿Esto fue una decisión deliberada relacionada con la ausencia de efectos laterales en la programación funcional y la naturaleza intrínseca operacional, abstracta y de alto nivel de este paradigma, que se condice con el abordaje que ustedes plantean?__> Punto B - Citar características importantes diferentes entre el lenguaje seleccionado y el resto de los lenguajes que les haya tocado analizar.

## b\.

### Soporte

Gobstones consta de un soporte aceptable y es accesible para cualquiera que desee utilizarlo.

**Facilidad de acceso al compilador o intérprete**

Tanto en Gobtones como en C, el intérprete/compilador es accesible.

El intérprete de Gobstones está bajo la licencia GNU General Public License (GPL) en su página oficial.

El compilador de C tiene una amplia variedad de implementaciones. La más conocida es GCC, que es de dominio público y con licencia GPL.

**Multiplataforma**

Ambos lenguajes tienen un soporte multiplataforma, es decir, corren en distintos sistemas operativos. Los más utilizados son Windows, OS X y Linux.

### Ortogonalidad

Gobstones es un lenguaje mucho más ortogonal que C. Principalmente por el enfoque con el cual fue diseñado.

Ninguno es completamente ortogonal. Nos encontramos con que algunas combinaciones no están permitidas en Gobstones, y en C,  parámetros restringidos, funciones que solo retornan “structs” pero no "arrays", no tiene representación para el tipo de dato String y Boolean (aunque se pueden implementar).

### Simplicidad y legibilidad

En este punto, quién saca ventaja es Gobstone. Al ser un lenguaje de programación ideado para enseñar a programar a personas que no tienen conocimientos previos, nos encontramos que tiene como fortaleza la simplicidad y legibilidad. Esta simplicidad está dada por distintas razones: la exclución de algunos conceptos, por ejemplo, los punteros y las excepciones. La sintaxis se ve facilitada a la hora del aprendizaje ya que no da espacio a cometer muchos errores.

Ocurre que C es un lenguaje poco legible pero con una sintaxis muy completa que permite una escritura de código muy compacta. Un punto muy relevante es que se puede expresar el mismo concepto semántico pero con distintas sintaxis. También es debilmente tipado, es decir, que no están prohibidas las violaciones de los tipos de datos. También se ve afectada la complejidad de la curva de aprendizaje debido a que se trata de un lenguaje de nivel medio con muchas características que nos permiten trabajar a bajo nivel.

### Confiabilidad

**Chequeo de tipos**

En C, el chequeo de tipos se hace en compilación y no tiene una conversión automática de tipos de datos incompatibles. Gobstone permite el chequeo de tipo pero es opcional y puede no estar disponible en todas las versiones de la herramienta. Cuando ocurre un error de tipo, falla el programa en ejecución.

**Excepciones**

Ninguno maneja excepciones de forma nativa. Pero C, al ser un lenguaje muy robusto, se pueden importar librerías para el manejo de excepciones o también el mismo programador podria implementarlas.


### Variables

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
|Valores de inicialización|**-**|_static, extern_: 0, _auto_: _initializer_/indefinido, restantes:_const initializer_/0|


* \* _Llamamos modificación de tipo a la posibilidad de modificar el atributo tipo de una variable luego de ser asignado por primera vez._
* \** _Llamamos conversión de tipo a la posibilidad de modificar el atributo tipo al cual evalúa una variable o expresión._

### Parámetros

El pasaje de parametros en Gobstones es de **ligadura posicional**. En el caso de este lenguaje sucede lo mismo que en C. La ligadura de los parametros es posicional.

Modo IN:

* C: Pasajes por valor y por valor constante
* Gobstones: Pasaje por valor. También se pueden pasar funciones como parámetros.

Modo OUT:

* C y Gobstones: Por resultado de funciones -> El resultado de una función puede devolverse con el uso del **return**

Modo I/O:

* C: No tiene pasaje de parametros por referencia pero en C se simula a través del *uso de punteros*.
* Gobstones: No cuenta con la posibilidad de pasar parametros por referencia, por valor/resultado o por nombre

## c\.

Gobstones es un lenguaje de programación que tiene como objetivo principal enseñar a programar a personas que no tienen conocimientos previos al respecto. Esto es asi, ya que nos encontramos ante un lenguaje cerrado y conciso, con una gramática bien definida por su simplicidad y claridad en las instrucciones.

Pero también es importante remarcar que se deja de lado conceptos complementarios más avanzados como entrada/salida, estructura de datos y excepciones, debido a que se considera que son conceptos que no aportan a la comprensión de la programación básica porque resuelven problemas avanzados que no son para un primer curso, y requieren como base muchos conceptos previos.

Entre algunas de las características, que ayudan a que sea un lenguaje para principiantes, se pueden mencionar:

* Es muy ortogonal
* Legible
* Facil de aprender ya que la sintaxis no da espacio a cometer muchos errores.
* Es un lenguaje muy acotado para el desarrollo.
* Es accesible para cualquiera que desee utilizarlo.

Por todo lo mencionado, Gobstones resulta fácil de entender y aprender, lo que va en concordancia con su objetivo educacional.

## d\.

Preguntas realizadas al docente Pablo E. Martínez López, creador del lenguaje.

### Dudas extraídas del punto a y en relación al punto b

##### Sintaxis (y simplicidad y legibilidad)

*Pregunta:*

Siendo un lenguaje tan alejado de C en la mayoría de los aspectos, __¿por qué se elige una sintáxis C-like?__

*Respuesta:*

> La idea es familiarizar al estudiante con una sintaxis textual C-like o Java-like para que la transición posterior sea sencilla. De ahí el hecho de usar llaves para los bloques, y paréntesis y comas para los parámetros y argumentos.
Además, posee 3 formas de comentarios diferentes: C-like, Haskell-like y Python-like. La idea es que puedan usar cualquiera para sentirse luego familiarizados en el lenguaje que vayan...
>
> La otra decisión de diseño es que todos los conceptos estén representados por una palabra clave (excepto la asignación). Así tenés "procedure", "function", "repeat", "while", "if", "switch", "foreach" y en XGobstones, "type", "record", "field", etc. En esto sí se diferencia de otros lenguajes.

##### Variables

*Pregunta:*

En el trabajo elaboramos la siguiente conclusión sobre el momento en que se ligan las variables con su tipo.

Considerando que **1)** las variables no se definen, directamente se inicializan, **2)** el tipo se liga en la inicialización, y **3)** para asignar espacio de memoria debemos conocer el tamaño requerido, el cual está dado por el tipo; podemos deducir que el *l-valor* se liga en la sentencia de inicialización, lo que hace a las variables **dinámicas** según el *binding time* del *l-valor*.

Por otro lado, dado que Python presenta el mismo tipo de variables, y que Gobstones está implementado sobre dicho lenguaje, podemos suponer que estábamos en lo cierto.

__¿Es nuestro planteo correcto?__

*Respuesta:*

> No del todo, aunque hay cosas ciertas. Primero que nada, la implementación de Gobstones hecha en Python no afecta en nada al lenguaje en sí. También tenemos implementaciones hechas en Haskell (la original), en Javascript (la que está por salir) y una experimental en Smalltalk. Y en todas el lenguaje debe comportarse igual.
>
> En Gobstones las variables NO REPRESENTAN espacio de memoria. De hecho, la manera correcta de implementarlo es utilizar un mapping entre nombres y valores. O sea, una variable es un nombre con el que se referencia un valor dado en cierto momento de la ejecución, y que puede alterarse mediante el comando de asignación. No hay memoria involucrada (aunque en las implementaciones, es usual utilizar memoria para esto, y puede que alguna implementación no sea correcta).
>
> Con respecto al tipo de las variables, la intención del lenguaje es que las variables denoten un valor de cierto tipo, determinado, efectivamente, al momento de su inicialización. Esto es determinado de manera dinámica, tal cual ustedes dicen. Pero les repito: no es por Python.
>
> La intención al enseñar Gobstones es no pensar en memoria, sino en nombres. Los parámetros, las variables y los índices son 3 formas de nombres. Lo que varía en ellos es:
>
> a.- su scope
>
> b.- su forma de inicialización
>
> c.- su forma de variación
>
> Los parámetros y las variables tienen scope al procedimiento que las define. Los índices, solo al bloque cuerpo de la repetición.
> 
> La inicialización de los parámetros es al momento de la invocación de un procedimiento, y no pueden modificarse nunca más.
> 
> La inicialización de los índices es al comenzar la repetición indexada, y varían en cada iteración.
> 
> La inicialización y variación de las variables es controlada por el programador mediante asignación; la primera asignación inicializa (y determina el tipo dinámicamente) y las siguientes modifican la ligadura.

##### Parámetros

*Pregunta:*

El pasaje de parámetros en Gobstones es **por valor constante**, ya que se realiza una copia del valor contenido en el parámetro real hacia el parámetro formal, y *no se puede* modificar al parámetro real desde la unidad invocada. __¿Esto fue una decisión deliberada relacionada con la ausencia de efectos laterales en la programación funcional y la naturaleza intrínseca operacional, abstracta y de alto nivel de este paradigma, que se condice con el abordaje que ustedes plantean?__

*Respuesta:*

> Totalmente. La decisión es que exista una única forma de pasaje de parámetros simple, para poder transmitir la idea básica de que un parámetro es un dato (más en general, una porción de código cerrado) que falta en el procedimiento. Nuevamente, no existe la idea de memoria asociada con un parámetro.
> 
> La implementación más simple es por copia de valor, ya que la eficiencia no nos preocupa en un curso inicial. Sin embargo, de importar la eficiencia (y en XGobstones, donde se manejan listas y registros esto puede importar), podría implementarse con una referencia ya que el lenguaje no permite cambios a los parámetros... O sea, no tenés una manera observacional en el lenguaje de saber si es una referencia o una copia.

##### Soporte

Facilidad de acceso al intérprete, soporte multiplataforma y recursos para el aprendizaje del lenguaje.

> Este es el punto más flojo: falta comunidad... Y falta que la comunidad que existe tenga una visión unificada de qué es lo que importa y qué no.

### Dudas relacionadas con el punto c

Sobre la introducción del enfoque **denotacional** por sobre el **operacional** para la resolución de problemas mediante la programación en un curso inicial a la misma:

*Pregunta:*

**¿En qué medida se logró introducir este enfoque "diferente"?**

*Respuesta:*

> La resistencia más grande, curiosamente, viene de parte de los docentes y no de parte de los estudiantes. Los docentes con formación en programación funcional lo incorporan mucho más rápido, y lo transmiten. Los docentes con una formación clásica tienden a usar formas más operacionales, y trabajamos todo el tiempo para evitarlo.
> 
> Como todo lenguaje, Gobstones permite hacer las cosas de varias maneras, y no te impide hacerlas de una forma no adecuada. Implementamos algunos controles para tratar de mejorar esto, pero funcionan mejor como consejos que como características propias del lenguaje. El consejo más exitoso es que no se puede utilizar más de una forma de combinación de comandos en el mismo procedimiento (o sea, no se pueden anidar repeticiones, ni combinar una repetición con una alternativa), forzando de esta forma a definir un procedimiento cada vez que se requiere una forma nueva de combinación, lo que resulta en soluciones más abstractas.

*Pregunta:*

**¿Realizaron análisis sobre los efectos que el cambio produjo sobre el alumnado?**

*Respuesta:*

> Estamos haciendo un estudio formal sobre eso ahora mismo, en la forma de un doctorado. Informalmente, el efecto es que los estudiantes están mejor preparados para entender estructuras de datos complejas (funcionales en principio) y tipos abstractos de datos, y transfieren los conceptos de manera adecuada tanto a lenguajes con objetos (Smalltalk), como imperativos (C) como funcionales (Haskell), como híbridos (Java, Scala), que son los que usan en las materias que siguen.

*Pregunta:*

Sabemos que en la UBA, en la carrera de Ciencias de la Computación, es esta la orientación que toma la materia troncal de *Algoritmos y Estructuras de Datos*. Hasta donde conocemos, en general, en las diferentes universidades de Sistemas e Informática del país nos encontramos con programas con un foco  que podría decirse operacional sobre los algoritmos. **¿Por qué dirías que esto sucede?**

*Respuesta:*

> Porque seguimos enseñando de la forma en que aprendimos, y nos damos poco espacio para cuestionar la forma en que lo hicimos, y la validez de las suposiciones que usamos al aprender.
> 
> Por ejemplo, cuando yo estudié, se usaban los diagramas de flujo, porque al programar en assembler, entender qué iba a hacer tu programa era imposible sin un diagrama. La programación estructurada, si se usan bien los procedimientos, hace absolutamente innecesario tener un diagrama de flujo (y existe desde ANTES que yo estudiase), y sin embargo hay muchos lugares que aún (30 años después) lo siguen enseñando.
> 
> Por lo mismo, seguimos atados a enseñar usando memoria, usando efectos laterales modificando esa memoria. La mejora que se produjo es encapsular los efectos y limitarlos mediante objetos, pero no es suficiente, porque solo patea el problema para adelante. La siguiente mejora es aprender sin memoria (estilo funcional), pero es muy resistida sobre todo por los docentes más tradicionales. Para mí, lo que corresponde es desprenderse de la idea de memoria y pensar denotacional, aún en un lenguaje operacional, y por eso Gobstones es parte de esa búsqueda.
> 
> El estilo funcional ahora está de moda, pero lamentablemente pocos lo entienden denotacionalmente, y lo único que hacen es cambiar la forma de escribir sus efectos laterales, perdiendo la verdadera ventaja.

*Pregunta:*

**¿Ves factible que esta prioridad sobre la óptica abstracta denotacional, que según entendemos ha estado presente por largos años en algunas universidades extranjeras de gran prestigio, se pueda implementar en otras universidades argentinas? ¿Cuáles te parece que serían los beneficios y las contras de que algo así ocurriese?**

*Respuesta:*

> Yo creo que pensar denotacional es el futuro. Todas las mejoras en los lenguajes de programación fueron parte de la búsqueda de mayor denotacionalidad (desde Assembler, FORTRAN y C, hasta Smalltalk, Haskell o Gobstones).
> 
> Es difícil transmitir bien esta idea, y debemos ser los informáticos formados los que llevemos el cambio adelante. El problema es que la visión operacional es más inmediata, más difundida y más vendible, y entonces competimos contra un monstruo de muchas cabezas. Pero no hay que ceder.
> 
> Actualmente la iniciativa Program.AR apunta mucho en el sentido denotacional, algo que celebro profundamente. Si esta iniciativa tiene éxito, en una década, todos nuestros estudiantes nos van a exigir pensar denotacional... Veremos qué pasa.> Conclusiones sobre opinión del trabajo de promoción.

## e\.

Acerca del trabajo de promoción y la materia en general, lo que más podemos resaltar es haber expandido nuestros conocimientos sobre nuevos lenguajes de programación. Ya sea acerca de las excepciones en _PL/1_, la alocación en heap de objetos en _Java_ o el approach más didáctico de **Gobstones**.

La comparación entre **C** y **Gobstones** tal vez fue muy radical. En un extremo, un lenguaje sumamente imperativo y verborrágico, reconocido por sus recovecos y _"gotchas"_, considerado padre de la programación moderna y de gran complejidad, mientras que en el otro, nos encontramos con un lenguaje diseñado para el aprendizaje, apuntando para lo funcional (y aún más en su nueva implementación **GobstonesX**), de alta legibilidad y simpleza, donde (conjunto a la documentación del lenguaje) se encuentra un curso teórico-práctico apuntado a jóvenes adolescentes.

Poco se pudo debatir (entre la _completitud_ y la _carencia_) de las características a comparar en el trabajo, sin embargo fue divertido el análisis realizado en busca de indicios en la implementación de **Gobstones**.

Finalmente, en la _"entrevista"_ con **Pablo E. Martínez López** confirmamos que la comparación entre **C** y **Gobstones** no es la más adecuada. Tienen motivaciones distintas, objetivos distintos, paradigmas distintos... el cotejo pierde sentido. Y aunque creo que es intrínseco del ser humano buscar las semejanzas, como informáticos deberíamos dejar atrás la confrontación entre lenguajes, _ya que cada uno está hecho a su medida, con objetivos y motivaciones propias._

Como conclusión: el trabajo fue interesante, las tecnologías y características a estudiar estaban a la altura del curso, pero el formato de comparación simplemente no era el adecuado. Si se quisiera realizar un balance entre tecnologías, se debería utilizar como contendiente a **Gobstones** otros lenguajes de aprendizaje, por ej. **Visual DaVinci** o **R-Info** (que son utilizados en la _UNLP_).

Por otro lado, así como expusimos en las conclusiones de la segunda parte del trabajo integrador, siendo curiosos por la programación funcional y su abordaje que dista del convencional operacional (al que más acostumbrados estamos), resultó muy interesante conocer no sólo al lenguaje Gobstones, que tiene estos conceptos como pilares, sino también a su iniciativa de afrontar a la programación desde el comienzo (i.e., desde un curso introductorio) con una perspectiva más abstracta.

En internet se pueden encontrar muchos debates sobre la programación funcional y la imperativa. El intercambio de ideas con el docente creador nos permitió leer de primera mano cómo se está intentando llevar a cabo este traspaso de lo operacional a lo denotacional en el país y en una universidad pública, cuáles son los elementos principales sobre los que se hace foco, y cuáles son las conclusiones que se van teniendo acerca de la implementación de la iniciativa. Nuevamente, teniendo en cuenta nuestra curiosidad (que eventualmente será afinidad, muy probablemente) por la programación funcional, esto último resultó enriquecedor y más que interesante.