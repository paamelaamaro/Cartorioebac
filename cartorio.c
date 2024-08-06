#include <stdio.h> //biblioteca de comunica��o com o usuario 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string

int registro()//fun��o responsavel por cadastrar os usuarios no sistema
{
  //inicio cria��o de vari�veis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //final cria��o de vari�veis/string
  
  printf("Digite o nome do CPF cadastrado: ");//coletando informa��es do usu�rio
  scanf("%s", cpf);//%s refere a string
  
  strcpy(arquivo, cpf);//Responsavel por copiar os valores do string
  
  FILE *file;//cria o arquivo
  file= fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever(write)
  fprintf(file, cpf);//salva o valor da variavel
  fclose(file);//fecha o arquivo
  
  file=fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o nome a ser cadastrado: ");//coletando o nome do usu�rio 
  scanf("%s", nome); //%s refere-se a string
 
  file=fopen(arquivo, "a"); //cria o arquivo
  fprintf(file, nome);//salva o nome da variavel
  fclose(file);//fecha o arquivo
  
    file=fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��es do usuario
  scanf("%s", sobrenome);//%s refere-se ao string
  
  file=fopen(arquivo,"a");//cria o arquivo
  fprintf(file, sobrenome);//salva a variavel
  fclose(file);//fecha o arquivo
  
    file=fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o cargo a ser cadastrado: ");//coletando informa��es do usu�rio
  scanf("%s", cargo);//%s refere-se ao string
  
  file=fopen(arquivo, "a");
  fprintf(file, cargo);
  fclose(file);
  
  system("pause");
  
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
  char cpf[40];
  char conteudo[200];
  
  printf("Digite o cpf a ser consultado: ");
  scanf("%s",cpf);
  
  FILE*file;
  file=fopen(cpf, "r");
  
  if(file == NULL)
  {
  	printf("N�o foi possivel abir o arquivo, n�o localizado!\n");
  }
  
  while(fgets(conteudo, 200, file)!= NULL )
{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  system("pause");
  
  
}
int deletar()
{
     char cpf[40];
     
     printf("Digite o CPF do usu�rio a ser deletado: ");
     scanf("%s", cpf);
     
     remove(cpf);
     
     FILE*file;
     file = fopen(cpf, "r");
     
     if(file == NULL)
     {
     	printf("Usu�rio nao se encontra no sistema!.\n");
     	system("pause");
	 }
     
     
     
     
}

int main()
    {
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	 
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a op��o desejada no menu:\n\n");
        printf("\t1-Registrar Nomes\n");
        printf("\t2-Consultar Nomes\n");
        printf("\t3-Deletar Nomes\n\n");
        printf("Op��o: ");//fim do menu
    
        scanf("%d",&opcao); //armazenando a escolha do usu�rio
    
    	system("cls");//responsavel por limpar a tela 
	
	switch(opcao)//inicio da sele��o do menu
	    {
		
	    case 1://chamada de fun��es 
	    registro();
 	    break;
 	    
 	    case 2:
	    consulta();
     	break;
     	
     	case 3:
     	deletar();
		break;
				
		default:
		printf("Essa op��o n�o est� dispon�vel!\n");
     	 system("pause");	
     	 break;
		}	
    
  	}  
 }
