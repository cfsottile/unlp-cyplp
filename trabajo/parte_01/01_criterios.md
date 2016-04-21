# Punto 1

> Realice una comparación respecto de los criterios de evaluación de los lenguajes de programación asignados. Mencione al menos dos criterios

### Criterios de evaluación

* Simplicidad y legibilidad
* Claridad en los bindings
* Confiabilidad
* Soporte
* Abstracción
* Ortogonalidad
* Eficiencia

___

##### Simplicidad y legibilidad
Los lenguajes de programación deberían:
Poder producir programas fáciles de escribir y de leer.
Resultar fáciles a la hora de aprenderlo o enseñarlo
Ejemplo de cuestiones que atentan contra esto:
Muchas componentes elementales
Conocer subconjuntos de componentes
El mismo concepto semántico – distinta sintaxis
Distintos conceptos semánticos - la misma notación sintáctica
Abuso de operadores sobrecargados

##### Claridad en los bindings
Los elementos de los lenguajes de programación pueden ligarse a sus atributos o propiedades en diferentes momentos:
Definición del lenguaje
Implementación del lenguaje
En escritura del programa
Compilación
Cargado del programa
En ejecución
La ligadura en cualquier caso debe ser clara

##### Confiabilidad
La confiabilidad está relacionada con la seguridad:
* Chequeo de tipos: Cuanto antes se encuentren errores menos costoso resulta realizar los arreglos que se requieran.
* Manejo de excepciones: La habilidad para interceptar errores en tiempo de ejecución, tomar medidas correctivas y continuar.

##### Soporte
* Debería ser accesible para cualquiera que quiera usarlo o instalarlo. Lo ideal sería que su compilador o intérprete sea de dominio público.
* Debería poder ser implementado en diferentes plataformas.
* Deberían existir diferentes medios para poder familiarizarse con el lenguaje: tutoriales, cursos textos, etc.

##### Abstracción
Capacidad de definir y usar estructuras u operaciones complicadas de manera que sea posible ignorar muchos de los detalles. Abstracción de procesos y de datos.

##### Ortogonalidad
Significa que un conjunto pequeño de constructores primitivos, puede ser combinado en número relativamente pequeño a la hora de construir estructuras de control y datos. Cada combinación es legal y con sentido. El usuario comprende mejor si tiene un pequeño número de primitivas y un conjunto consistente de reglas de combinación.

Pascal NO es ortogonales, Rubi SI. En Pascal los proc y las funciones pueden ser pasadas por parámetro pero solo pueden pasar parámetros por valor, las funciones SOLO pueden devolver datos elementales, no punteros, ni arreglos, etc.

##### Eficiencia
* Tiempo y Espacio
* Esfuerzo humano
* Optimizable
