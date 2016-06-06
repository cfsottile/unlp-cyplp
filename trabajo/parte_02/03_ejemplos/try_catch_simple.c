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
