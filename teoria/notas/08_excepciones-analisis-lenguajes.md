## Ada

### Definición y Lanzamiento

Se declaran como variables `e: exception` y se levantan explícitamente mediante `raise e`. Así como las variables, tienen alcance. Cuando se lanza una excepción `e`, esta es aquella asociada al identificador `e` que tiene alcance en ese lugar del programa.

*DUDA1: si declaro una excepción en una unidad y no la manejo, cuando se propaga, ¿lo hace como anónima (por el asunto del alcance)?*

*DUDA2: el alcance de las excepciones (así como de las variables), ¿es estático o dinámico? ¿A dónde voy a buscar la excepción `e` que no está existe localmente?*

### Manejo

Se escribe una sección `Exceptions` al final de las unidades (que pueden ser un *bloque*, un *procedimiento*, un *paquete* o una *tarea*) y allí se incluyen los diferentes manejadores.

### Propagación

La unidad en la que se produce la excepción corta su ejecución; se intenta manejar con los manejadores definidos para la unidad, y si no se puede se relanza dinámicamente. Desde un manejador, se puede relanzar la excepción escribiendo `raise`.

### Criterio de continuación

*DUDA: luego de encontrar un manejador y manejarla, ¿la ejecución continúa desde quien invocó a la unidad contenedora del manejador?*

### Built-in exceptions

* `Constraint_Error`
* `Program_Error`
* `Storage_Error`
* `Numeric_Error`
* `Name_Error`
* `Tasking_Error`

## CLU

### Definición y Lanzamiento

Las excepciones sólo pueden lanzarse dentro de un procedimiento. Se definen junto al encabezado del método escribiendo `signals e1, e2`. Se lanzan mediante el comando `signal`.

### Manejo

Los manejadores se asocian a sentencias. Ejemplo:

```
<sentencia>; except 
	when e1: m1;
	when e2: m2;
	when others: mo;
end;
```

### Propagación

El procedimiento en el que se produjo la excepción corta su ejecución. Se busca al manejador en la *sentencia de invocación* al procedimiento; si no se encuentra allí, se busca al manejador ascendiendo de forma estática en la composición de sentencias. Si no se encuentra un manejador asociado dentro del procedimiento [invocador del procedimiento en el que se produjo la excepción], se levanta una excepción `failure` que termina el programa.

Sólo una vez, se puede *relanzar* una excepción mediante el comando `resignal`, lo que (*en duda*) genera un comportamiento similar a si el procedimiento contenedor del manejador fuera el que lanzó la excepción. 

### Criterio de continuación - *En duda*

Se continúa la ejecución desde la sentencia siguiente a aquella que tenía asociado el manejador que se invocó.

### Built-in exceptions

* `Failure`

## PL/1

### Definición, Lanzamiento y Manejo

Se define una excepción junto con su manejador asociado. Esto se almacena en una pila de manejadores que es global a las unidades. Cuando se lanza una excepción (esto se hace mediante `signal condition <exception>`), se toma de la pila el último manejador asociado para la excepción y este es quien la maneja. *DUDA: una vez que se maneja la excepción, ¿el manejador se desapila?*

### Propagación

No hay propagación. Ante el lanzamiento de la excepción, se intenta invocar a un manejador asociado en la pila; si no hay ninguno, (*en duda*) el programa corta su ejecución.

### Criterio de continuación

Una vez manejada la excepción, se continúa desde la instrucción siguiente a la que la lanzó.

### Built-in exceptions

NS/NC

## C++

### Definición, Lanzamiento

Se definen como una clase más. Se lanzan mediante la instrucción `throw <exception>`.

### Manejo

Se declaran bloques `try {} catch(<exception>) {}`. En `try` se escribe el código susceptible de generar una excepción; en `catch` se escribe el manejador de la excepción. 

### Propagación

Cuando se genera una excepción, se corta la ejecución del bloque `try` y se busca el manejador en sus correspondientes `catch`. Si no se encuentra, se propaga la excepción bajo las siguientes condiciones:

en el encabezado de las funciones se puede especificar un conjunto de excepciones que la misma puede levantar; si se alcanza una que no está incluida en la lista, se termina el programa (este comportamiento puede ser redefinido); si la lista es vacía, no se propaga ninguna excepción; si no hay lista, se propagan todas las excepciones.

### Criterio de continuación

Una vez ejecutado el bloque `catch` del manejador correspondiente, se continúa la ejecución desde las sentencias posteriores a dicho bloque.

### Built-in exceptions

Muchas.

## Java

Similar a C++, con algunas particularidades:

* Todas las excepciones que puede alcanzar una rutina deben listarse en su interfaz, o bien ser manejadas. Esto no vale para las excepciones de ejecución.
* Agrega un bloque `finally {}` que se ejecuta **sí o sí** (si no hay excepción lo hace luego del `try`, si hay excepción lo hace antes de propagar *DUDA: ¿y si no se propaga? Meh, a nadie le importa*).

## Python

Presenta un esquema de bloques `try` parecido al de C++ y Java: `try` incluye las sentencias que pueden generar un error, `except <exception>` contiene un manejador, `else` contiene sentencias a ejecutar en caso de que no se levanten excepciones, y `finally` contiene sentencias que se ejecutarán sí o sí.

En caso de que un bloque `try` no contenga un manejador para una excepción que lanza, se busca estáticamente si el mismo está contenido en otro bloque `try` y se propaga la excepción hacia este. Si no, se propaga la excepción dinámicamente; si no se encuentra un manejador, se corta la ejecución.

Las excepciones se lanzan con la instrucción `raise`.

## Ruby

### Definición

Las excepciones son clases. Se definen como cualquier clase; heredan de alguna excepción dentro de la jerarquía de `Exception`. Se lanzan mediante el método `raise`.

### Manejo

Se declaran bloques de una forma similar a Python: en `begin` se ponen las sentencias que podrían generar excepciones, en `rescue <exception>` se escribe el código para manejarla, en `ensure` el código que se debe ejecutar **sí o sí**, y en `else` el código a ejecutar si no hubo excepciones.

### Propagación