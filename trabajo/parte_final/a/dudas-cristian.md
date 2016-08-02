> Determine los tipos de variable de acuerdo al momento de ligadura con el lvalor.

Considerando que **1)** las variables no se definen, directamente se inicializan, **2)** el tipo se liga en la inicialización, y **3)** para asignar espacio de memoria debemos conocer el tamaño requerido, el cual está dado por el tipo; podemos deducir que el *l-valor* se liga en la sentencia de inicialización, lo que hace a las variables **dinámicas** según el *binding time* del *l-valor*. Por otro lado, dado que Python presenta el mismo tipo de variables [1], y que Gobstones está implementado sobre dicho lenguaje, podemos suponer que estábamos en lo cierto. ¿Nuestra deducción es correcta?

**[1]** Stack Overflow - *Memory allocation types by moment of lvalue binding in Python*. [link](http://stackoverflow.com/questions/29733309/memory-allocation-types-by-moment-of-lvalue-binding-in-python)

> Ejemplifique la forma en que simularía una variable de tipo estática.

Tomando como definición de *variables de tipo estáticas* a aquellas que *están cargadas en memoria desde el inicio hasta el fin del programa*, y dado que suponemos que el lenguaje carga a las variables en el momento de su inicialización, lo más similar a una variable estática que podríamos obtener en un programa Gobstones sería una que se encuentre inicializada en la primer sentencia del programa. Este fue nuestro razonamiento al momento de entregar una de las partes del trabajo. Analizando más en profundidad el concepto de variable estática, nos encontramos con que *debe estar cargada en memoria desde antes de la ejecución*, lo que nos dejaría sin la posibilidad de implementar variables estáticas. **Meh, malísimo**.

> Tipos de pasaje de parámetros soportados

El pasaje de parámetros en Gobstones es **por valor constante**, ya que se realiza una copia del valor contenido en el parámetro real hacia el parámetro formal, y *no se puede* modificar al parámetro real desde la unidad invocada. ¿Esto fue una decisión deliberada relacionada con la naturaleza inmutable de los datos en la programación funcional  y la relación de este paradigma con el enfoque denotacional por sobre el operacional que ustedes han querido abordar?

> Otras dudas

* Sobre la introducción del **análisis denotacional** por sobre el **operacional** para la resolución de problemas mediante la programación
	* ¿En qué medida se logró llevarla a cabo?
	* ¿Realizaron análisis sobre los efectos que el cambio produjo sobre el alumnado?
	* Sabemos que en la UBA, en la carrera de Ciencias de la Computación, este es el enfoque que toma la materia troncal de *Algoritmos y Estructuras de Datos*. Hasta donde conocemos, en general, en las diferentes universidades de Sistemas e Informática del país nos encontramos con programas con un foco operacional sobre los algoritmos. ¿Por qué dirías que esto sucede?
	* ¿Ves factible que el enfoque denotacional, que según entendemos se ha llevado a cabo por largos años en algunas universidades extranjeras de gran prestigio, se pueda implementar en otras universidades argentinas? ¿Cuáles te parece que serían los beneficios y las contras de que algo así ocurriese?

## Descartado

A diferencia de C, en la documentación de Gobstones no se especifica en qué momento se liga el *l-valor* a las variables. Es por eso que decidimos conjeturar basándonos en la evidencia disponible. Planteamos algunas preposiciones: **1)** las variables no se deben definir, simplemente se inicializan; **2)** el tipo se liga en tiempo de ejecución (más concretamente al momento de ejecutar la sentencia de inicialización); **3)** para conocer el espacio necesario para almacenar una variable, es probable que requiramos conocer su tipo. Teniendo en cuenta la veracidad de lo anterior, podemos decir que el *l-valor* se liga en la sentencia de inicialización, lo que hace a las variables **dinámicas** según el *binding time* del *l-valor*.
