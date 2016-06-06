# Sintaxis

La **sintaxis** es el conjunto de reglas que toma un alfabeto de caracteres y define las construcciones válidas de un lenguaje.

Hay dos tipos de reglas:

* **léxicas**: determinan las *words* válidas: nombres identificadores de entidades, operadores, números.
* **sintácticas**: determinan las construcciones válidas a partir de las *words*.

En cuanto al análisis sintáctico de, justamente, la sintaxis, encontramos tres conceptos que definiremos mediante un ejemplo.

Al analizar la sentencias *while* en C y Pascal

* C

```c
while (x != y) {
    ...
}
```

* Pascal

```pascal
while x <> y do
begin
    ...
end
```

vemos que la estructura general es la misma; si bien hay detalles léxicos como:

* el símbolo de *distinto* se escribe `!=` en C y `<>` en Pascal;
* el bloque se encierra en `{}` en C y en `begin-end` en Pascal;
* la guarda de la sentencia *while* va entre `()` en C, mientras que eso no ocurre en Pascal.

Estos detalles descriptos son elementos de la **sintaxis concreta**, mientras que la estructura general pertenece a la **sintaxis abstracta**.

Por otro lado, para aquellos casos en los que el bloque del *loop* contiene una sola sentencia, ambos lenguajes permiten la omisión de las *words* delimitadoras del mismo.

* C

```c
while (x != y) x++;
```

* Pascal

```pascal
while x <> y x := x + 1;
```

Desde el punto de vista **práctico/pragmático**, esto puede resultar propenso a errores si no se tiene el cuidado de agregar los delimitadores al momento de introducir una línea adicional en el bloque. Otros lenguajes adoptan un enfoque distinto y menos propenso a errores en la práctica:

* ADA

```ada
while x /= y do
    ...
end
```

* **Sintaxis abstracta**: se refiere a la estructura sintáctica. Por ejemplo, 