#include <stdio.h> 


void imprimir ();

void imprimir2 (char mensaje[]);
int suma ();

int suma (){

int numero = 1 ;
int numero2 = 1 ;
int resultado = numero + numero2 ;

return resultado ;
}
void imprimir (){
    printf ("Hola Mundo\n");

}
void imprimir2 (char mensaje []){
    printf ("%s\n",mensaje);
}


int main (){

    int resultadoDeUnaSuma;
    resultadoDeUnaSuma = suma ();
    printf("%d\n", resultadoDeUnaSuma);
    imprimir ();
    imprimir2 ("Hola mundo");
    return 0;
    
}