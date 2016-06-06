## ¿Qué es un *tipo abstracto de datos*?

Es un tipo definido por el usuario en el que se especifica:

* una estructura en la que almacenar datos, y
* un conjunto de operaciones relacionadas con el tipo abstracto en cuestión.

La definición de la estructura de datos, así como la implementación de las operaciones, se oculta en pos de la abstracción de la complejidad. Se deja visible la especificación de los encabezados de las operaciones: su nombre, los datos de entrada que esperar, y los datos de salida generados. Es decir, se deja visible su *sintáxis*, no así su *semántica*.

Toda esta definición debe poder llevarse a cabo en una misma unidad sintáctica (*encapsulamiento*), y debe garantizarse que no sean visibles al *usuario* la especificación del tipo usado como estructura para almacenar datos ni la implementación de las operaciones (*ocultamiento*).

##### Conclusiones personales

La idea detrás del TAD es, así como en la idea de tipo de dato original, clasificar a los datos (mediante la organización de los posibles conjuntos de valores, cuya representación interna se oculta al usuario para abstraerlo) y protegerlos de operaciones inválidas (mediante la definición de las operaciones válidas, mostrando sólo su forma de utilizarlas, y no lo que hacen por dentro).

1. Por un lado, se especifica de forma oculta cómo se almacenarán los datos que sean necesarios. Esto se hace mediante algún tipo de dato (presumiblemente alguno compuesto).
2. Por otro, se define públicamente el encabezado de las operaciones a llevar a cabo sobre el nuevo tipo abstracto. El encabezado consiste en el nombre, los datos entrada y los datos de salida.
3. Por último, de manera oculta se escribe la implementación de las operaciones.

Luego, el tipo se utiliza como un tipo de dato más, creándose variables y manipulándolas mediante las operaciones definidas.