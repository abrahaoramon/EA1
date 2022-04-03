//Bibliotecas:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INPUTS (char) char >= '0' && char <= '9' || char>= 'A' && char <= 'z'

//Variáveis globais:
char Fun[2]; // Tipo da função aplicada pelo usuário
char Text[1000]; // Texto digitado pelo usuário
char Str_Encode[1000]; // Saida da codificação
char Str_Decode[1000]; // Saida da decodificação

//Blocos de função:
void Encoder(void);
void Decoder(void);
void C_Rle(void);
void D_Rle(void);

//Procedimento principal:
int main(void)
{
  //Variávei locais:
  int fun_encoder, fun_decoder;
     
do
{
    printf( "Escolha a funcao desejada 'C' para codificar ou 'D' para decodificar:\n");   
    gets(Fun);
    fun_encoder = strcmp(Fun,"C"); // Comparação para codificar
    fun_decoder = strcmp(Fun,"D"); // Comparação para decodificar

     if(fun_encoder==0 || fun_decoder==0)
    {
      printf( "Digite o texto:\n");
      scanf("%s",&Text);
    }
    else    
    {
       printf ("Funcao invalida\n\n");
     
    }   
} while(fun_encoder!=0 && fun_decoder!=0); //Teste lógico para fim do laço de repetição
        
         if(fun_encoder==0)
       {
           Encoder();           
       }
       if(fun_decoder==0)
       {
           Decoder();           
       }
       
    
    system("pause");
    return 0;
}

//Função para codificação:
void Encoder(void)
{
    //Variáveis locais:
    long psc_text= 0, psc_encoder = 0; // verificadores de posição
    char x; //caracter obtido no texto

    while (Text[psc_text] !='\0')
    {
        x = Text[psc_text];
        // Condições para codificação
        if (x != 'Z' && x >= 'A' && x <= 'Z')
        {
            Str_Encode[psc_encoder]=x;            
        }
         else if (x == 'Z')
        {
            Str_Encode[psc_encoder]='Z';
            Str_Encode[psc_encoder + 1]='Z';
            psc_encoder++;
        }
        else if (x == '0')
        {
            Str_Encode[psc_encoder]='Z';
            Str_Encode[psc_encoder + 1]='A';
           psc_encoder++;  
        }
        else if (x == '1')
        {
            Str_Encode[psc_encoder]='Z';
            Str_Encode[psc_encoder + 1]='B';
            psc_encoder++;
        }
         else if (x == '2')
        {
            Str_Encode[psc_encoder]='Z';
            Str_Encode[psc_encoder + 1]='C';
            psc_encoder++;
        }
         else if (x == '3')
        {
            Str_Encode[psc_encoder]='Z';
            Str_Encode[psc_encoder + 1]='D';
            psc_encoder++;
        }
         else if (x == '4')
        {
            Str_Encode[psc_encoder]='Z';
            Str_Encode[psc_encoder + 1]='E';
            psc_encoder++;
        }
         else if (x == '5')
        {
            Str_Encode[psc_encoder]='Z';
            Str_Encode[psc_encoder + 1]='F';
            psc_encoder++;
        }
         else if (x == '6')
        {
            Str_Encode[psc_encoder]='Z';
            Str_Encode[psc_encoder + 1]='G';
            psc_encoder++;
        }
         else if (x == '7')
        {
            Str_Encode[psc_encoder]='Z';
            Str_Encode[psc_encoder + 1]='H';
            psc_encoder++;
        }
         else if (x == '8')
        {
            Str_Encode[psc_encoder]='Z';
            Str_Encode[psc_encoder + 1]='I';
            psc_encoder++;
        }
             else if (x == '9')
        {
            Str_Encode[psc_encoder]='Z';
            Str_Encode[psc_encoder + 1]='J';
            psc_encoder++;
        }    
        psc_text++;
        psc_encoder++;       
    }

    printf ("Codificacao:\n");
    puts(Str_Encode);
} 

//Função para decodificação:
void Decoder(void)
{
    printf ( "Decodificador: \n");
    puts(Text);
}

// Função para compressão
void C_Rle(void)
{
    printf ( "Decodificador: \n");
    puts(Text);
}
// Função para descompressão
void D_Rle(void)
{
    printf ( "Decodificador: \n");
    puts(Text);
}