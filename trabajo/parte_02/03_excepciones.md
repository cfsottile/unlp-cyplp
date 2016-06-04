> Para cada lenguaje, en el caso en que maneje excepciones, describa el método utilizado y compárelo con alguno de los modelos impartidos en la práctica.

>En caso de que no maneje excepciones analice y sugiera el modelo que debería utilizar el lenguaje. En todos los casos ejemplifique.

## Gobstones

Gobstones no maneja las excepciones. Los creadores consideraron que es un concepto que no aporta a la comprensión de la programación básica porque resuelven problemas avanzados que no son para un primer curso y que requieren como base, muchos de los conceptos previos.

Una forma en la que podria implementarse sería utilizando una variable global para indicar si hubo un error en una operacion/función y en base a ello, definir una acción.

Resulta díficil (engorroso o tedioso) tener que verificar una variable despues de cada operación o función. Sería complicado de mantener un codigo en estas condiciones. Resulta poco viable.

De ser asi, seria un manejo por **reasunción**. Ya que al ser una manejo por condición, sigue siendo procedural la ejecución del lenguaje.

Como herramienta para introducirse al mundo de la programación, cumple con su función. Es un lenguaje es bantante cerrado y conciso. Tiene bien definida su gramática también.

## C

En C, no se manejan las excepciones de forma nativa.
Si es posible una simulacion de manejo de excepciones o a traves de la libreria `<signal.h>`, se pueden manejar las excepciones que surjan durante la ejecucion.

A continuación, unos ejemplos de como simular un TRY CATCH en `C`.

La forma en que procede luego de la interrupción es de **terminacion de bloque**, es decir, que cuando finaliza el manejo de la excepción, termina la ejecucion del bloque en que se lanzo la excepción.

>Try Catch con solo un tipo de error

```C
#include <stdio.h>
#include <setjmp.h>

#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW(err) longjmp(ex_buf__, err)

int main(int argc, char** argv)
{
    typedef enum {
        myEx
    } ex;
   TRY
   {
      printf("In Try Statement\n");
      ex error = myEx;
      THROW(error);
      printf("I do not appear\n");
   }
   CATCH
   {
      printf("Got Exception!\n");
   }
   ETRY;
   //Como se veria si se reemplazara los define
   //Funciona igual
   {
    jmp_buf ex_buf__;
    if( !setjmp(ex_buf__) )
    {
        {
            printf("In Try Statement2\n");
            ex error = myEx;
            longjmp(ex_buf__, error);
            printf("I do not appear\n");
        }
    }
    else
    {
        {
        printf("Got Exception2!\n");
        }
    }
   }
   return 0;
}
```

>Try Catch con varios posibles valores

```C

#include <stdio.h>
#include <setjmp.h>

#define TRY do{ jmp_buf ex_buf__; switch( setjmp(ex_buf__) ){ case 0:
#define CATCH(x) break; case x:
#define ETRY } }while(0)
#define THROW(x) longjmp(ex_buf__, x)

#define FOO_EXCEPTION (1)
#define BAR_EXCEPTION (2)
#define BAZ_EXCEPTION (3)

int main(int argc, char** argv)
{
   TRY
   {
      printf("In Try Statement\n");
      THROW( BAR_EXCEPTION );
      printf("I do not appear\n");
   }
   CATCH( FOO_EXCEPTION )
   {
      printf("Got Foo!\n");
   }
   CATCH( BAR_EXCEPTION )
   {
      printf("Got Bar!\n");
   }
   CATCH( BAZ_EXCEPTION )
   {
      printf("Got Baz!\n");
   }
   ETRY;

   return 0;
}

```

## Referencias

* Sitio oficial de Gobstones. [link](http://www.gobstones.org/)

* Sección Bibliografía, sitio oficial de Gobstones. [link](http://www.gobstones.org/?page_id=34)

* Libro: "The c programming language, Second edition" pag. 255

* Ejemplo del TRY CATCH en C [link](http://www.di.unipi.it/~nids/docs/longjump_try_trow_catch.html)
