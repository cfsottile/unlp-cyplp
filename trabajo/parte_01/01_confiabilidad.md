# Confiabilidad

> La confiabilidad está relacionada con la seguridad:
* Chequeo de tipos: Cuanto antes se encuentren errores menos costoso resulta realizar los arreglos que se requieran.
* Manejo de excepciones: La habilidad para interceptar errores en tiempo de ejecución, tomar medidas correctivas y continuar.

## C

**Chequeo de tipos**

El chequeo de tipos se hace tiempo tiempo de compilación.
Los Compiladores advierten de la mayoría de los errores de tipo, y no hay conversión automática de tipos de datos incompatibles. Sin embargo, C conserva la filosofía básica que los programadores saben lo que están haciendo.

**Manejo de excepciones**

A traves de la libreria `<signal.h>`, se pueden manejar las excepciones que surjan durante la ejecucion como una senial de interrupcion externa o un error en la ejecucion.

*Referencia: page 255, "The c programming language, Second edition" *

___

## Gobstone


**Chequeo de tipos**
Se permite invocar definiciones que esperan expresiones de un determinado tipo con expresiones de cualquier otro tipo, incluso cuando su uso es incorrecto. No obstante, si esto sucede el programa fallar al ser ejecutado.
Sin embargo, permite la verificacion para los tipos de datos, chequeando de alguna forma en que casos su uso es correcto. Sin embargo, esta caracterıstica es opcional, y puede no estar disponible en todas las versiones de la herramienta.

**Manejo de excepciones**

No tiene herramientas para el manejo de excepciones ya que este concepto no aporta a la comprension de la programacion basica, resuelven problemas avanzados que no son para un primer curso y requieren como base muchos de los conceptos impartidos.

___

##### Referencias

* Libro "The c programming language", Segunda edicion. Autor: Brian W. Kernighan y Dennis M. Ritchie.
* Documentacion de la página oficial de Gobstone: http://www.gobstones.org/?page_id=34 - SobreGobstones
