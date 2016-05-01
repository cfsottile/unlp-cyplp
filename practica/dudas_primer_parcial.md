# Dudas

## Práctica 4

### Análisis de identificadores

##### *r-value*

¿Ponemos como *r-value* el valor al momento de la definición, o el valor al momento de la primer asignación? En las siguientes dudas se ven algunos ejemplos.

###### Respuesta

* Si la definición incluye inicialización, dicho valor.
* Si el lenguaje inicializa por defecto en un valor, dicho valor.
* Si no, basura.

Inicializaciones

* C inicializa variables globales y `static` en 0
* ADA inicializa punteros en `nil`
* Pascal no inicializa nada

##### *Tiempo de vida* - `a` vs `*a`

Cuál es el tiempo de vida de una variable en los casos en que **no** se utiliza espacio adicional en la memoria dinámica, sino que se asignan celdas originalmente asignadas *para* otro puntero. 

###### Respuesta

Quedaron en charlarlo y avisar por el moodle. A priori, sería desde que se asigna algo al puntero hasta que se libera el mismo puntero. O sea, desde que hay un `p = ...` hasta que hay un `free(p)`.

Ejemplo:

```c
1.  | int *p, *q;
2.  | 
3.  | int main () {
4.  |     p = malloc(sizeof(int));
5.  |     *p = 8;
6.  |     // some stuff 1
7.  |     q = p;
8.  |     // some stuff 2
9.  |     free(p);
10. |     // some stuff 3
11. |     return 0;
12. | }
```

id  | l-value    | r-value    | scope | extent
--- | ---        | ---        | ---   | ---
p   | automática | **0**      | 1-12  | 1-12
\*p | dinámica   | basura     | 1-12  | 4-8
q   | automática | **0**      | 1-12  | 1-12
\*q | dinámica   | **8**      | 1-12  | **7-12>**

##### *Tiempo de vida* - `*a` y `&`

Cuál es el tiempo de vida en los casos en que un puntero apunta a una dirección de memoria que **no** es dinámica. 

###### Respuesta

Igual que en la duda anterior, quedaron en charlarlo y avisar por el moodle. A priori, sería también como en la duda anterior: desde que se asigna algo al puntero hasta que se libera el mismo puntero. O sea, desde que hay un `p = ...` hasta que hay un `free(p)`.

Ejemplo:

```c
1.  | int a, *p, *q;
2.  | 
3.  | int main () {
4.  |     a = 5;
5.  |     // some stuff 1
6.  |     p = &a;
7.  |     // some stuff 2
8.  |     q = p;
9.  |     // some stuff 3
10. |     p = malloc(sizeof(int));
11. |     // some stuff 4
12. |     free(p);
13. |     return 0;
14. | }
```

id  | l-value    | r-value    | scope | extent
--- | ---        | ---        | ---   | ---
a   | automática | **0**      | 1-14  | 1-14
p   | automática | **0**      | 1-14  | 1-14
\*p | dinámica   | **5**      | 1-14  | **6-12**
q   | automática | **0**      | 1-14  | 1-14
\*q | dinámica   | 8          | 1-14  | **8-14>**