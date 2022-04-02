#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char fun[2]; // Tipo da função aplicada pelo usuário
char text[1000]; // Texto digitado pelo usuário
char strencode[1000]; // Saida da codificação
char strdecode[1000]; // saida da decodificação

//Função para codificação:
void encoder(void)
{
    printf ( "Codificador:\n");
    puts(text);
return 0;
}

//Função para decodiciação:
void decoder(void)
{
    printf ( "Decodificador: \n");
    puts(text);
return 0;
}

//Procedimento principal:
int main(void)
{
  int funencode, fundecode;
    
    printf( "Escolha a funcao desejada 'C' para codificar ou 'D' para decodificar:\n");   
    gets(fun);

    printf( "Digite o texto:\n");
    gets(text);

    funencode = strcmp(fun,"C");
    fundecode = strcmp(fun,"D");
    
    if(funencode!=0 && fundecode!=0)
    {
       printf ("Funcao invalida\n");
    }
    else
    {
       if(funencode==0)
       {
           encoder();
       }
       if(fundecode==0)
       {
           decoder();
       }
    }
      
    return 0;
}