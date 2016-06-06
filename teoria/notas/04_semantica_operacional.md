# Binding

Los programas constan de **entidades** que tienen **atributos** que deben ser establecidos para poder usar la entidad. La **ligadura** es la asociación entre la entidad y el atributo (el valor del mismo).

Del **binding** podemos especificar su *binding time* y su *estabilidad*.

El **binding time** es el momento en que se lleva a cabo la ligadura. Puede ser en la *definición del lenguaje*, en su *implementación*, durante la *compilación* o en *ejecución*.

La **estabilidad** determina si una ligadura puede modificarse. Las ligaduras *estáticas* no pueden modificarse, mientras que las *dinámicas* sí.

Clasificación de los *binding time* según su *estabilidad*:

* Estática
	* Definición del lenguaje
	* Implementación del lenguaje
	* Compilación
* Dinámica
	* Ejecución

# Entidades

## Variables

Los *atributos* de la entidad **variable** son:

* Nombre
* Alcance
* Tipo
* L-Value
* R-Value

### Nombre

Es la cadena de caracteres que, dentro del programa, sirve para referirse a la variable.

### Alcance - REVISAR, puede no ser correcto

Son las porciones del programa en los que el nombre de la variable es conocido y dicho nombre hace referencia a la variable.

El alcance puede ser *estático* o *dinámico*.

Es *estático* cuando el alcance está definido a partir de la estructura léxica del lenguaje. Por ejemplo, si hay una variable global `x` en el main y en una función no anidada se usa `x` sin declararla, se está haciendo referencia al `x` del main.

Es *dinámico* cuando el alcance está dado por la ejecución. Por ejemplo, si hay una variable `x` en el main y se usa a `x` sin declararla en una función no anidada, la variable a la que hace referencia `x` dependerá del RA de quien invocó a la función.

### Tipo

Valores posibles y operaciones asociadas. Pueden ser *predefinidos por el lenguaje*, *definidos por el usuario* o *TADs*.

La especificación del tipo puede ser estática o dinámica. Si es estática, puede ser:

* *Explícita*: `int x`
* *Implícita*: se deduce de algún lado, por ejemplo del nombre (Fortran).
* *Inferida*: se deduce de los tipos de los componentes.

### L-Value

Consiste en la dirección de memoria en la que se almacenará el valor. El *binding* puede producirse:

* En compilación