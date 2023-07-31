#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // fun��o responsavel por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de var�aveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de var�aveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // abrir o arquivo e o w significa escrever
	fprintf(file,cpf); // salvo o valor da var�avel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // a significa alterar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r"); // r significa ler
  	
	if(file == NULL)
	{
		printf("n�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
  	
	system ("pause");


}

int deletar()
{
	char cpf[40];
	
	printf("Escolha o usu�rio que sera deletado: \n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("o usu�rio n�o foi encontrado: \n");
		system("pause");
	}
	else
	{
		printf("Usu�rio Deletado com sucesso! \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //criamos a variavel op��o
	int laco=1;
	char senhadigitada[10]="a"; //variavel da senha que o usu�rio vai digitar
	int comparacao; //variavel para comparar a senha pr�-definida com a senha digitada
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //strcmp compara a string com a senha pr�-definida
	
	if(comparacao == 0) //==0 pq apos a strcmp se os valores vorem iguais vai retornar o n�mero 0, por isso (comparacao == 0)
	{
		system("cls");			
		for(laco=1;laco=1;)
		{
	
			system("cls");	
	
			setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nome\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do Programa\n\n");
			printf("Op��o: "); //fim do menu
	
			scanf("%d,", &opcao); //%d armazena varaivel do tipo inteiro e &opcao pra salvar na variavel opcao
	
			system("cls"); //system conversa com o sistema, cls limpar a tela apos a finaliza��o do programa
		
		
			switch(opcao) //in�cio da sele��o
			{
				case 1:
				registro(); //chamada de fun��o
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;
			
				default:
				printf("Essa op��o n�o esta d�sponivel!\n");
				system("pause");
				break;
				//fim da sele�ao	
			}
		
		}
	}
	
	else //caso erre a senha
		printf("Senha incorreta!\n");
}
