#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // função responsavel por cadastrar os usuários no sistema
{
	//Início criação de varíaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de varíaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // abrir o arquivo e o w significa escrever
	fprintf(file,cpf); // salvo o valor da varíavel
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
		printf("não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
  	
	system ("pause");


}

int deletar()
{
	char cpf[40];
	
	printf("Escolha o usuário que sera deletado: \n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("o usuário não foi encontrado: \n");
		system("pause");
	}
	else
	{
		printf("Usuário Deletado com sucesso! \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //criamos a variavel opção
	int laco=1;
	char senhadigitada[10]="a"; //variavel da senha que o usuário vai digitar
	int comparacao; //variavel para comparar a senha pré-definida com a senha digitada
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //strcmp compara a string com a senha pré-definida
	
	if(comparacao == 0) //==0 pq apos a strcmp se os valores vorem iguais vai retornar o número 0, por isso (comparacao == 0)
	{
		system("cls");			
		for(laco=1;laco=1;)
		{
	
			system("cls");	
	
			setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem
	
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nome\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do Programa\n\n");
			printf("Opção: "); //fim do menu
	
			scanf("%d,", &opcao); //%d armazena varaivel do tipo inteiro e &opcao pra salvar na variavel opcao
	
			system("cls"); //system conversa com o sistema, cls limpar a tela apos a finalização do programa
		
		
			switch(opcao) //início da seleção
			{
				case 1:
				registro(); //chamada de função
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
				printf("Essa opção não esta dísponivel!\n");
				system("pause");
				break;
				//fim da seleçao	
			}
		
		}
	}
	
	else //caso erre a senha
		printf("Senha incorreta!\n");
}
