> Punto B - Citar características importantes diferentes entre el lenguaje seleccionado y el resto de los lenguajes que les haya tocado analizar.

### Soporte

Gobstones consta de un soporte aceptable y es accesible para cualquiera que desee utilizarlo.

**Facilidad de acceso al compilador o intérprete**

Tanto en Gobtones como en C, el intérprete/compilador es accesible.

El intérprete de Gobstones está bajo la licencia GNU General Public License (GPL) en su página oficial.

El compilador de C tiene una amplia variedad de implementaciones. La más conocida es GCC, que es de dominio público y con licencia GPL.

**Multiplataforma**

Ambos lenguajes tienen un soporte multiplataforma, es decir, corren en distintos sistemas operativos. Los más utilizados son Windows, OS X y Linux.

### Ortogonalidad

Gobstones es un lenguaje mucho más ortogonal que C. Principalmente por el enfoque con el cual fue diseñado.

Ninguno es completamente ortogonal. Nos encontramos con que algunas combinaciones no están permitidas en Gobstones, y en C,  parámetros restringidos, funciones que solo retornan “structs” pero no "arrays", no tiene representación para el tipo de dato String y Boolean (aunque se pueden implementar).

### Simplicidad y legibilidad

En este punto, quién saca ventaja es Gobstone. Al ser un lenguaje de programación ideado para enseñar a programar a personas que no tienen conocimientos previos, nos encontramos que tiene como fortaleza la simplicidad y legibilidad. Esta simplicidad está dada por distintas razones: la exclución de algunos conceptos, por ejemplo, los punteros y las excepciones. La sintaxis se ve facilitada a la hora del aprendizaje ya que no da espacio a cometer muchos errores.

Ocurre que C es un lenguaje poco legible pero con una sintaxis muy completa que permite una escritura de código muy compacta. Un punto muy relevante es que se puede expresar el mismo concepto semántico pero con distintas sintaxis. También es debilmente tipado, es decir, que no están prohibidas las violaciones de los tipos de datos. También se ve afectada la complejidad de la curva de aprendizaje debido a que se trata de un lenguaje de nivel medio con muchas características que nos permiten trabajar a bajo nivel.

### Confiabilidad

**Chequeo de tipos**

En C, el chequeo de tipos se hace en compilación y no tiene una conversión automática de tipos de datos incompatibles. Gobstone permite el chequeo de tipo pero es opcional y puede no estar disponible en todas las versiones de la herramienta. Cuando ocurre un error de tipo, falla el programa en ejecución.

**Excepciones**

Ninguno maneja excepciones de forma nativa. Pero C, al ser un lenguaje muy robusto, se pueden importar librerías para el manejo de excepciones o también el mismo programador podria implementarlas.


### Variables

|Propiedad|Gobstones|C|
|:---:|:---:|:---:|
|Variables Tipadas|**Sí**|**Sí**|
|Tipos de variable|_Color, Número, Dirección, Booleano_| _char, int, float, double_|
|Binding de Tipo|**Dinámico**|**Estático**|
|Momento de binding de Tipo|_Ejecución_|_Compilación_|
|Permite modificación de Tipo*|**No**|**No**|
|Permite conversión de Tipo**|_No_|_Conversión implícita y explícita_|
|Binding de Valor|**Dinámico**|**Dinámico**|
|Incialización por Defecto|_No_|_Sí_|
|Valores de inicialización|**-**|_static, extern_: 0, _auto_: _initializer_/indefinido, restantes:_const initializer_/0|


* \* _Llamamos modificación de tipo a la posibilidad de modificar el atributo tipo de una variable luego de ser asignado por primera vez._
* \** _Llamamos conversión de tipo a la posibilidad de modificar el atributo tipo al cual evalúa una variable o expresión._

### Parámetros

El pasaje de parametros en Gobstones es de **ligadura posicional**. En el caso de este lenguaje sucede lo mismo que en C. La ligadura de los parametros es posicional.

Modo IN:
* C: Pasajes por valor y por valor constante
* Gobstones: Pasaje por valor. También se pueden pasar funciones como parámetros.

Modo OUT:
* C y Gobstones: Por resultado de funciones -> El resultado de una función puede devolverse con el uso del **return**

Modo I/O:
* C: No tiene pasaje de parametros por referencia pero en C se simula a través del *uso de punteros*.
* Gobstones: No cuenta con la posibilidad de pasar parametros por referencia, por valor/resultado o por nombre
