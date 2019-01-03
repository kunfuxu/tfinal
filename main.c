#include "comboios.h"


int main(int argc, char *argv[]){
    srand(time(NULL));
    int cores[DIMCores][DIMrgb]={ {255,0,0,255},// vermelho
                                  {0,0,255,255},// azul
                                  {255,255,0,255},// AMARELO
                                  {0,255,255,255},//Cyan
                                  {153,0,153,255}, //Roxo
                                  {0,230,0,0}, // Verde
                                  {153,76,0,255}, //Castanho
                                  {0,0,0,255},//Preto
                                  {128,128,128,255},//Cinzento
                                  {255,255,255,255}/*Branco*/};
    int i=0;
    int jancoord[2];
    char opcao='0';
   // char buff[MAX];
    COMBOIO* todos[MAX];
    FERROVIA* todas[MAX];
    for (i=0;i<MAX;i++){
        todos[i]=NULL;
        todas[i]=NULL;
    }

	if(argc!=2){
		printf("Por favor insira o nome do ficheiro \n""Exemplo: ./comboios hahayes.txt\n");
		exit(0);
	}
	if(ler(argv,todos,todas,jancoord) == 0)
		exit(0);
    printf("PRESSIONE ENTER! \n");// ver nos LABS
	do{
		menu(&opcao);
        //getchar();
		fflush(stdin);
		switch(opcao)
		{
			case '1': // MOSTRA FERROVIA
				mostraLinha(todas);
				break;
			case '2': // ELIMINA FERROVIA
				//print instruçoes
                //scanf("%s", Indent);
                eliminaLinha(todas);
                //memset(Indent, 0, MAX);
				break;
			case '3': // MOSTRA COMBOIOS
				mostraComboio(todos);
				break;
			case '4': // ELIMINA COMBOIOS
                // Lista para depois eliminar por ID
                eliminaComboio(todos);
 				break;
			case '5':
				criarComboio(todos, todas);

				break;
			case '6':
				abreJanela(jancoord,todos,todas,cores);
				printf("Simular");
				break;
		}


	}while(opcao!='0');
	return 0;
}
