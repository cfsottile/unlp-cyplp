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

__3__\. El pasaje de parámetros en Gobstones es **por valor constante**, ya que se realiza una copia del valor contenido en el parámetro real hacia el parámetro formal, y *no se puede* modificar al parámetro real desde la unidad invocada. __¿Esto fue una decisión deliberada relacionada con la ausencia de efectos laterales en la programación funcional y la naturaleza intrínseca operacional, abstracta y de alto nivel de este paradigma, que se condice con el abordaje que ustedes plantean?__