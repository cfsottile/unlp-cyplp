Hola Fidel. Somos alumnos de la Facultad de Informática de la UNLP. Te escribimos porque estamos cursando la materia _Conceptos y Paradigmas de Lenguajes de Programación_ y nos tocó analizar el lenguaje Gobstones que ustedes desarrollaron. Uno de los ejercicios del trabajo de promoción consiste en transmitirte dudas que nos hayan quedado, incluyendo luego tus respuestas.

El análisis que hicimos abarcó:

* Chequeo de tipos
* Soporte (facilidad de acceso al intérprete, soporte multiplataforma y recursos para el aprendizaje del lenguaje)
* Características principales del lenguaje y gramática en EBNF
* Asignación e inicialización por defecto de variables
* Tipos de variable de acuerdo al _binding time_ con el l-valor
* Pasaje de parámetros
* Sentencias condicionales y de iteración
* Manejo de excepciones

En líneas generales podemos decir que las dudas no son mayores. Creemos que comprendimos la mecánica y el objetivo del lenguaje. Provee un espacio para el aprendizaje y aplicación de un grupo de conceptos, abstrayéndose de aquellos con los que no se quiere _distraer_ al alumno, lo que le permite mantenerse simple y conciso, a la vez de no perder el foco sobre dichos conceptos. En lenguajes de propósito general, no diseñados para el ámbito educativo y por ende no acotados, esta desviación de la atención se puede dar muy fácilmente, a menudo en pos de lo operacional por sobre lo denotacional.

Por si es de tu interés, te dejamos un enlace al [directorio dentro del repositorio de GitHub](https://github.com/cfsottile/unlp-cyplp/tree/master/trabajo/parte_final/trabajos_originales) en el que se encuentran los trabajos que realizamos.

A continuación expresamos las dudas. Gracias de antemano.

Saludos

## Dudas

### Sintáxis

__1__\. Siendo un lenguaje tan alejado de C en la mayoría de los aspectos, __¿por qué se elige una sintáxis C-like?__

### Ligadura entre una variable y su tipo

__2__\. En el trabajo elaboramos la siguiente conclusión sobre el momento en que se ligan las variables con su tipo.

> Considerando que **1)** las variables no se definen, directamente se inicializan, **2)** el tipo se liga en la inicialización, y **3)** para asignar espacio de memoria debemos conocer el tamaño requerido, el cual está dado por el tipo; podemos deducir que el *l-valor* se liga en la sentencia de inicialización, lo que hace a las variables **dinámicas** según el *binding time* del *l-valor*.

Por otro lado, dado que Python presenta el mismo tipo de variables [1], y que Gobstones está implementado sobre dicho lenguaje, podemos suponer que estábamos en lo cierto.

__¿Es nuestro planteo correcto?__

[1] Stack Overflow - *Memory allocation types by moment of lvalue binding in Python*. [link](http://stackoverflow.com/questions/29733309/memory-allocation-types-by-moment-of-lvalue-binding-in-python)

### Pasaje de parámetros

__3__\. El pasaje de parámetros en Gobstones es **por valor constante**, ya que se realiza una copia del valor contenido en el parámetro real hacia el parámetro formal, y *no se puede* modificar al parámetro real desde la unidad invocada. __¿Esto fue una decisión deliberada relacionada con la ausencia de efectos laterales en la programación funcional y la naturaleza intrínseca operacional, abstracta y de alto nivel de este paradigma, que se condice con el abordaje que ustedes plantean?__

### Otros temas

Sobre la introducción del enfoque **denotacional** por sobre el **operacional** para la resolución de problemas mediante la programación:

__4__\. **¿En qué medida se logró introducir este enfoque "diferente"?**

__5__\. **¿Realizaron análisis sobre los efectos que el cambio produjo sobre el alumnado?**

__6__\. Sabemos que en la UBA, en la carrera de Ciencias de la Computación, es esta la orientación que toma la materia troncal de *Algoritmos y Estructuras de Datos*. Hasta donde conocemos, en general, en las diferentes universidades de Sistemas e Informática del país nos encontramos con programas con un foco  que podría decirse operacional sobre los algoritmos. **¿Por qué dirías que esto sucede?**

__7__\. **¿Ves factible que esta prioridad sobre la óptica abstracta denotacional, que según entendemos ha estado presente por largos años en algunas universidades extranjeras de gran prestigio, se pueda implementar en otras universidades argentinas? ¿Cuáles te parece que serían los beneficios y las contras de que algo así ocurriese?**