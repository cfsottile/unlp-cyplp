> Para cada lenguaje, en el caso en que maneje excepciones, describa el método utilizado y compárelo con alguno de los modelos impartidos en la práctica.

>En caso de que no maneje excepciones analice y sugiera el modelo que debería utilizar el lenguaje. En todos los casos ejemplifique.

## Gobstones

Gobstones no maneja las excepciones. Los creadores consideraron que es un concepto que no aporta a la comprensión de la programación básica porque resuelven problemas avanzados que no son para un primer curso y que requieren como base, muchos de los conceptos previos.

En conclusión, como herramienta para introducirse al mundo de la programación, no es necesario el uso de excepciones.

// explicar que gosbtons manejaria de forma manial las excepciones mediante condiciones. Lo cual es engorroso.
Parte del resumen del lenguaje es que es bantante cerrado y conciso. Cumple con la funcion el lenguaje, como introductorio a la programacino


## C

En C, no se manejan las excepciones de forma nativa.
Si es posible una simulacion de manejo de excepciones o a traves de la libreria `<signal.h>`, se pueden manejar las excepciones que surjan durante la ejecucion.

A continuación, un ejemplo de como simular un TRY CATCH en `C`.
La forma en que procede luego de la interrupción es de **terminacion de bloque**, es decir, que cuando finaliza el manejo de la excepción, termina la ejecucion del bloque en que se lanzo la excepción.

```C
#include <stdio.h>
#include <setjmp.h>

#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW(err) longjmp(ex_buf__, err)

int main(int argc, char** argv)
{
    // se podria reemplaza el "CATCH } else {" y
    // utilizar un case para clasificar errores
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

## Referencias

* Sitio oficial de Gobstones. [link](http://www.gobstones.org/)

* Sección Bibliografía, sitio oficial de Gobstones. [link](http://www.gobstones.org/?page_id=34)

* Libro: "The c programming language, Second edition" pag. 255
