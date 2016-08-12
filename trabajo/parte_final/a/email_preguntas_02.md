Hola Fidel, acá estamos con las respuestas. Te contestamos por partes también.

> Hola. Trato de responder a sus dudas... Si quieren, puedo después mirar el trabajo antes de que lo entreguen para darles mi opinión.

Más que bienvenido a leer el trabajo, ¡desde ya!

> > 1. Siendo un lenguaje tan alejado de C en la mayoría de los aspectos, ¿por qué se elige una sintáxis C-like?

> La idea es familiarizar al estudiante con una sintaxis textual C-like o Java-like para que la transición posterior sea sencilla. De ahí el hecho de usar llaves para los bloques, y paréntesis y comas para los parámetros y argumentos.
Además, posee 3 formas de comentarios diferentes: C-like, Haskell-like y Python-like. La idea es que puedan usar cualquiera para sentirse luego familiarizados en el lenguaje que vayan...

> La otra decisión de diseño es que todos los conceptos estén representados por una palabra clave (excepto la asignación). Así tenés "procedure", "function", "repeat", "while", "if", "switch", "foreach" y en XGobstones, "type", "record", "field", etc. En esto sí se diferencia de otros lenguajes.
…

Entendido. Me pasa que me pongo algo extremista cuando descubro teorías o tecnologías, y eso me lleva a demonizar alguans alternativas. Por ejemplo, al empezar a leer información sobre programación funcional, empecé a demonizar un poco a la programación imperativa. Quizá no tanto a demonizarla, sino mas bien a menospreciarla, como si fuera una etapa antigua de la programación que hoy ya no debería ser tomada como actual. Después con el tiempo me calmo y entiendo que todo convive con todo.

> > Ligadura entre una variable y su tipo

> Puesto que las variables son uno de los temas que menos interesan en este lenguaje, yo no empezaría por acá... :) Pero si lo eligieron, vamos allá.
…

En realidad el tema que más interesante nos resulta es lo que quedó a lo último. Lo ordenamos de la forma en que estaba ordenado en el trabajo; pura inercia.

> > 2. En el trabajo elaboramos la siguiente conclusión sobre el momento en que
> > se ligan las variables con su tipo.
> >
> > Considerando que 1) las variables no se definen, directamente se
> > inicializan, 2) el tipo se liga en la inicialización, y 3) para asignar
> > espacio de memoria debemos conocer el tamaño requerido, el cual está dado
> > por el tipo; podemos deducir que el l-valor se liga en la sentencia de
> > inicialización, lo que hace a las variables dinámicas según el binding time
> > del l-valor.
> >
> > Por otro lado, dado que Python presenta el mismo tipo de variables [1], y
> > que Gobstones está implementado sobre dicho lenguaje, podemos suponer que
> > estábamos en lo cierto.
> >
> > ¿Es nuestro planteo correcto?

> No del todo, aunque hay cosas ciertas. Primero que nada, la implementación de Gobstones hecha en Python no afecta en nada al lenguaje en sí. También tenemos implementaciones hechas en Haskell (la original), en Javascript (la que está por salir) y una experimental en Smalltalk. Y en todas el lenguaje debe comportarse igual.

Interesante que tengan diferentes implementaciones. ¿Está publicado el código fuente?

> En Gobstones las variables NO REPRESENTAN espacio de memoria. De hecho, la manera correcta de implementarlo es utilizar un mapping entre nombres y valores. O sea, una variables es un nombre con el que se referencia un valor dado en cierto momento de la ejecución, y que puede alterarse mediante el comando de asignación. No hay memoria involucrada (aunque en las implementaciones, es usual utilizar memoria para esto, y puede que alguna implementación no sea correcta).

> Con respecto al tipo de las variables, la intención del lenguaje es que las variables denoten un valor de cierto tipo, determinado, efectivamente, al momento de su inicialización. Esto es determinado de manera dinámica, tal cual ustedes dicen. Pero les repito: no es por Python.

> La intención al enseñar Gobstones es no pensar en memoria, sino en nombres. Los parámetros, las variables y los índices son 3 formas de nombres. Lo que varía en ellos es:
> a.- su scope
> b.- su forma de inicialización
> c.- su forma de variación

Bien, abstraen un poco más el concepto de variable y no se preocupan por la memoria.

> > 3.

> Totalmente. La decisión es que exista una única forma de pasaje de parámetros simple, para poder transmitir la idea básica de que un parámetro es un dato (más en general, una porción de código cerrado) que falta en el procedimiento. Nuevamente, no existe la idea de memoria asociada con un parámetro.

Claro. Supongo va de la mano con la supresión del concepto de memoria. ?????

> La implementación más simple es por copia de valor, ya que la eficiencia no nos preocupa en un curso inicial. Sin embargo, de importar la eficiencia (y en XGobstones, donde se manejan listas y registros esto puede importar), podría implementarse con una referencia ya que el lenguaje no permite cambios a los parámetros... O sea, no tenés una manera observacional en el lenguaje de saber si es una referencia o una copia. ;)

> > Otros temas
> >
> > Sobre la introducción del enfoque denotacional por sobre el operacional para
> > la resolución de problemas mediante la programación:
> > 
> > 4. ¿En qué medida se logró introducir este enfoque “diferente”?

> La resistencia más grande, curiosamente, viene de parte de los docentes y no de parte de los estudiantes. Los docentes con formación en programación funcional lo incorporan mucho más rápido, y lo transmiten. Los docentes con una formación clásica tienden a usar formas más operacionales, y trabajamos todo el tiempo para evitarlo.