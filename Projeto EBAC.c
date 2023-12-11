#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string
int registro() //funcao responsavl por cadastrar os usuarios no sistema
{
	//inicio criacao de variaveis / string
	char arquivo[40];
    char cpf[40];
    char nome [40];
    char sobrenome[40];
    char cargo[40];
	//fibal da criacao de variavis / strings
	
	printf("Digite o CPF ser cadastrado:"); // coletando informacao do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strig
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
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
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//R ler }
	if(file == NULL)
	
	{
		printf("Não foi possivel abrir o arquivo, arquivo não localizado!.\n");
	}
    
    while(fgets(conteudo, 200, file));
    {
    	printf("\nEssas são as informações do usuario: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system("pause");
 }
    
int deletar()
{
	    char cpf[40];
	    
	    printf("Digitar o CPF do usuario a ser deletado: ");
	    scanf("%s", cpf);
	    
	    remove(cpf);
	    
	    FILE *file;
	    file = fopen(cpf,"r");
	    
	    if(file == NULL)
	    {
	    	printf("O usuario não se encontra no sistema!. \n");
	    	system ("pause");
		}
	
}
int main()
{
	int opcao=0; //Definir variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("Opção: "); //Final do menu
	
	scanf("%d", &opcao); //armazenando a ecolha do usuario
	
	system("cls"); // responsavel por limpar a tela
	
	switch(opcao) //inicio da funcao menu
	{
		case 1:
		registro(); //chamada das funcoes
		break;
		
		case 2: 
        consulta();
	    break;
	    
	    case 3:
	    deletar();
		break;
		
		default:
		printf("Essa opção não está disponível!");
		system("pause");
	    break;
	}// fim da selecao
}  
}
		
	
