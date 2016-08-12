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
> Actualmente la iniciativa Program.AR apunta mucho en el sentido denotacional, algo que celebro profundamente. Si esta iniciativa tiene éxito, en una década, todos nuestros estudiantes nos van a exigir pensar denotacional... Veremos qué pasa.