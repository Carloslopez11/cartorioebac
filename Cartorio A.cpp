#include <stdio.h> // biblioteca de comunicação com o usário
#include <stdlib.h> //  biblioteca de alocação de espaço em memória 
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // Função responsavel por cadastrar os usários no sistema
{
	//inicio criação de variáveis/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usario
	scanf("%s", cpf); // refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
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
	
	printf("Digite o sobrenome a ser cadastrado: ");
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
	setlocale(LC_ALL,  "portuguese"); // Definindo a linguagem
	 
    char cpf[40];
    char conteudo[200];

    printf("Digite o cpf a ser consultado: ");
    scanf("%s" ,cpf);

    FILE *file;
    file = fopen(cpf ,"r");

    if(file == NULL)
    {
	printf("Ñao foi possivel abrir o arquivo,  ñao localizado!.\n");
    }
    
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    system ("pause");
    
    
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usário a ser delatado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usario ñao se encuentra no sistema!.\n");
		system("pause");	
	}
}


int main()
    {
	int opcao=0; //Definindo as variáveis
    int laco=1;
   
    for(laco=1;laco=1;)
    {
	    
		system("cls"); //responsavel por limpar a tela
      
	    setlocale(LC_ALL,  "portuguese"); // Definindo a linguagem 

        printf("### Cartório da EBAC ###\n\n"); // inicio do menu 
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n\n"); 
	    printf("opção: ");// fim do menu
	 
        scanf("%d" , &opcao); // armazenando a escolha do usáurio
    
        system("cls");
        
     
	    switch(opcao) //inicio da seleção do menu
        {
    	    case 1:
    	    registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
		    deletar();
			break;
				
			default:
			printf("essa opcão não está disponivel!\n");
    	    system("pause");
			break;	
	    }
    
        } //fin da seleção
    
   
 }
