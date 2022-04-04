//Bibliotecas:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INPUTS (char) char >= '0' && char <= '9' || char>= 'A' && char <= 'z'

// Variável do tipo c_rle para compressão de texto
struct c_rle 
{
    char caracter;
    int count;
};

//Variáveis globais:
char Fun[2]; // Tipo da função aplicada pelo usuário
char Text[1000]; // Texto digitado pelo usuário
char Str_Encode[1000]; // Saida da codificação
char Str_Decode[1000]; // Saida da decodificação
struct c_rle Coded[1000];
int Psc_Coded, Serie;

//Blocos de função:
void Encode(void);
void Decode(void);
void C_Rle(char in_text[], struct c_rle out_text[]);
void D_Rle(void);

//Procedimento principal:
int main(void)
{
  //Variávei locais:
  int fun_encode, fun_decode;
     
do
{
    printf( "Escolha a funcao desejada 'C' para codificar ou 'D' para decodificar:\n");   
    gets(Fun);
    fun_encode = strcmp(Fun,"C"); // Comparação para codificar
    fun_decode = strcmp(Fun,"D"); // Comparação para decodificar

     if(fun_encode==0 || fun_decode==0)
    {
      printf( "Digite o texto:\n");
      gets(Text);
    }
    else    
    {
       printf ("Funcao invalida\n\n");
     
    }   
} while(fun_encode!=0 && fun_decode!=0); //Teste lógico para fim do laço de repetição
        
         if(fun_encode==0)
       {
           Encode();
           C_Rle(Str_Encode,Coded);
           printf("Codigo:\n");

           for(int Psc_Coded=0;Psc_Coded< Serie;Psc_Coded++)
           {
               if(Coded[Psc_Coded].count > 1 )
               {
                   printf("%d%c",Coded[Psc_Coded].count,Coded[Psc_Coded].caracter);
               }
               else
               {
                   printf("%c",Coded[Psc_Coded].caracter);
               }
           }
           printf("\n");
       }
       if(fun_decode==0)
       {
           Decode();           
       }
       
    
    return 0;
}

//Função para codificação:
void Encode(void)
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
} 

//Função para decodificação:
void Decode(void)
{
    printf ( "Decodificador: \n");
    puts(Text);
}

// Função para compressão
void C_Rle(char in_text[], struct c_rle out_text[])
{
    int psc_comp, psc_in_text=0, ctrl; // variáveis de controle da função
    int texto = strlen(in_text);
    for(psc_comp=0; psc_comp<1000; psc_comp++)
    {
        for(ctrl=psc_in_text ; ctrl < texto ; ctrl++)
        {
            if(in_text[ctrl] != in_text[ctrl+1])
            break;
        }

         out_text[psc_comp].count = ctrl-psc_in_text + 1;
         out_text[psc_comp].caracter = in_text[psc_in_text];       

        if( psc_in_text < texto )
        {
          psc_in_text = ctrl+1;
        }
        else
        {
            break;
        }
    }
    Psc_Coded=psc_comp;
    Serie=psc_comp;
}

// Função para descompressão
/*void D_Rle(void)
{
    printf ( "Decodificador: \n");
    puts(Text);
}*\