#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
	puts(argv[1]);
	FILE *arquivo, *saida;
	char Str[50];
	int i=1;
	strcpy(Str, argv[1]);
	char Linha[100];
	arquivo = fopen(Str, "rb");
	saida = fopen("saida.png", "wb");

	if (arquivo == NULL)
	{
		printf("Problemas na abertura do arquivo\n");
		return 1;
	}

	while (1)
	{
		// Lê uma linha (inclusive com o '\n')
		// o 'fgets' lê até 99 caracteres ou até o '\n'
		fgets(Linha, 100, arquivo); // Se foi possível ler	
		if(feof(arquivo))
			break;
/*		if(i>20000&&i<21000){
			memset(Linha, 255, sizeof(Linha));
		}*/
		//fprintf(saida, "%s", Linha);
		fwrite(Linha, sizeof(char), sizeof(Linha), saida);		
		i++;
	}
	fclose(arquivo);
	fclose(saida);
}
