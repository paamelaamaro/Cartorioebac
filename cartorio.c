#include <stdio.h> //biblioteca de comunicação com o usuario 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string

int registro()//função responsavel por cadastrar os usuarios no sistema
{
  //inicio criação de variáveis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //final criação de variáveis/string
  
  printf("Digite o nome do CPF cadastrado: ");//coletando informações do usuário
  scanf("%s", cpf);//%s refere a string
  
  strcpy(arquivo, cpf);//Responsavel por copiar os valores do string
  
  FILE *file;//cria o arquivo
  file= fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever(write)
  fprintf(file, cpf);//salva o valor da variavel
  fclose(file);//fecha o arquivo
  
  file=fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o nome a ser cadastrado: ");//coletando o nome do usuário 
  scanf("%s", nome); //%s refere-se a string
 
  file=fopen(arquivo, "a"); //cria o arquivo
  fprintf(file, nome);//salva o nome da variavel
  fclose(file);//fecha o arquivo
  
    file=fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o sobrenome a ser cadastrado: ");//coletando informações do usuario
  scanf("%s", sobrenome);//%s refere-se ao string
  
  file=fopen(arquivo,"a");//cria o arquivo
  fprintf(file, sobrenome);//salva a variavel
  fclose(file);//fecha o arquivo
  
    file=fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o cargo a ser cadastrado: ");//coletando informações do usuário
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
  	printf("Não foi possivel abir o arquivo, não localizado!\n");
  }
  
  while(fgets(conteudo, 200, file)!= NULL )
{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  system("pause");
  
  
}
int deletar()
{
     char cpf[40];
     
     printf("Digite o CPF do usuário a ser deletado: ");
     scanf("%s", cpf);
     
     remove(cpf);
     
     FILE*file;
     file = fopen(cpf, "r");
     
     if(file == NULL)
     {
     	printf("Usuário nao se encontra no sistema!.\n");
     	system("pause");
	 }
     
     
     
     
}

int main()
    {
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	 
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada no menu:\n\n");
        printf("\t1-Registrar Nomes\n");
        printf("\t2-Consultar Nomes\n");
        printf("\t3-Deletar Nomes\n\n");
        printf("Opção: ");//fim do menu
    
        scanf("%d",&opcao); //armazenando a escolha do usuário
    
    	system("cls");//responsavel por limpar a tela 
	
	switch(opcao)//inicio da seleção do menu
	    {
		
	    case 1://chamada de funções 
	    registro();
 	    break;
 	    
 	    case 2:
	    consulta();
     	break;
     	
     	case 3:
     	deletar();
		break;
				
		default:
		printf("Essa opção não está disponível!\n");
     	 system("pause");	
     	 break;
		}	
    
  	}  
 }
