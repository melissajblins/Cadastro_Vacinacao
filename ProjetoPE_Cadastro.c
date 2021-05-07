#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 200 //Quantidade de linhas dos vetores e matrizes

char nome[TAMANHO][TAMANHO]; // Matriz para armazenar 200 nomes
char email[TAMANHO][50]; // Matriz para armazenar 200 e-mails
double cpf[TAMANHO]; // Vetor para armazanar 200 CPFs
double telefone[TAMANHO]; // Vetor utilizado para armazenar 200 telefones
int idade[TAMANHO]; // Vetor utilizado para armazenar 200 valores de idade
char comorbidade[TAMANHO][50]; // Matriz para armazenar possiveis comorbidades do usuario
int vacina_numero[TAMANHO]; // Vetor para armazenar a vacina em numero
char vacina_nome[TAMANHO][50]; // Vetor para armazenar o nome da vacina
int vacina_segunda_dose[TAMANHO]; // Vetor para armazenar a segunda dose da vacina
int ID[TAMANHO];  //Vetor para armazenar 200 IDs
int data_primeira[TAMANHO]; //variável para armazenar o mês da primeira dose
int data_segunda[TAMANHO]; //variável para armazenar o mês da segunda dose
int opcao; // Variavel utilizada para armazenar as opcoes do usuario
int edicao_opcao; // Variavel utilizada para editar o cadastro
int edicao; // Variavel utilizada para editar um dado
int grupo[TAMANHO]; //Variavel para armazenar o grupo pertencido


void cadastro(); // Prototipo da funcao cadastro
void pesquisa(); // Prototipo da funcao pesquisa
void lista(); // Prototipo da funcao lista
void mesvacina(int idade[], int vacina_numero[], int grupo_vacina[], int linha); // Prototipo da funcao mesvacina
void filas(); //Prototipo da funcao filas

struct fila {
    int quantidade;
    int inicio;
    int fim;
    int numeros[TAMANHO];
};

typedef struct fila Fila;

Fila* cria_Fila(){
    Fila *fi = NULL;

    fi = (Fila *) malloc(sizeof(Fila));

    if (fi != NULL){
        fi->inicio = 0;
        fi->quantidade = 0;
        fi->fim = 0;
    }

    return fi;
}

int insere_Fila (Fila *fi, int numero_inserir){
    if (fi == NULL){
        return 0;
    }
    else {
        if (fi->quantidade == TAMANHO){
            return 0;
        }
        else{
            fi->numeros[fi->fim] = numero_inserir;
            fi->fim = fi->fim + 1;
            fi->quantidade++;
            return 1;

        }
    }
}

int remove_Fila (Fila *fi){
    if (fi == NULL || fi->quantidade == 0){
        return 0;
    }
    else {
        fi->inicio = fi->inicio+1;
        fi->quantidade--;

        return 1;
    }

}

int imprimindo_Fila (Fila *fi){
    int ID_impresso = fi->inicio;
    if (fi == NULL){
        return 0;
    }
    else {
        for (int linha = 0; linha < fi->quantidade; linha++){
            printf("Paciente %d - ID: %d\n", linha+1,  fi->numeros[ID_impresso]);
            ID_impresso++;
        }
    ID_impresso = fi->inicio;
    }
}

Fila *ponteirooficial;
Fila *ponteirodemonstracao;

int main(void){ // Funcao principal - Com a criacao do MENU PRINCIPAL

        // Foi apagada todas as funcoes do Main pois usaremos o Menu principal para direcionar o usuario com mais facilidade

        ponteirooficial = cria_Fila();
        ponteirodemonstracao = cria_Fila();

        system("color 8F");

        printf("\n==== PROGRAMA INICIADO ====\n\n");

        do{
        system("cls"); // Criada a funcao System que permite executar codigos do prompt de comando dentro do programa
        printf("\n---- MENU ----\n1 - Cadastrar\n2 - Listar todos\n3 - Pesquisar\n4 - Ordem de vacinação\n5 - Sair\n\n"); // Cabecario do Menu com todos os itens necessarios
        scanf("%d", &opcao);
        switch(opcao) { // Criada o switch para comparar a op��o que o usuario escolheu

        case 1:
            cadastro(); // Caso o usuario escolha a opcao 1, o mesmo sera direcionado para a funcao cadastro na linha 58
            break;

        case 2:         // Caso o usuario escolha a opcao 2, o mesmo sera direcionado para a funcao lista na linha 140
            lista();
            break;

        case 3:         // Caso o usuario escolha a opcao 3, o mesmo sera direcionado para a funcao pesquisa na linha 88
            pesquisa();
            break;

        case 4:
            filas();
            break;

        case 5:          // Caso o usuario escolha a opcao 4, o programa sera fechado.
            printf("\n==== PROGRAMA ENCERRADO ====\n");
            system("exit");
            break;

        default:
            printf("Opcao invalida! Pressione o enter."); // Mensagem para o usuario caso ele digite algum valor diferente do pedido no Menu

            getchar(); // Colocamos a funcao getchar para manter a tela aberta quando o usuario escolher uma outra opcao.
            getchar(); // Dependendo do sistema operacional, compilador e demais fatores, o programa pode funcionar com apenas um getchar, por motivos de precaucao colocamos dois.
            break;
        }
    }while(opcao!=5);

}

void cadastro(){ // Funcao para cadastrar pessoas

    system("color 8F");

    static int linha; //Variavel que estaciona o valor de linha
    printf(" \n----------------------------------- \n"); // Inicio do cadastro
    do{
        printf("   CADASTRO DE VACINACAO COVID-19  \n"); // Cabecalho da Funcao cadastro
        printf("----------------------------------- \n"); // Inicio do cadastro
        printf("\nDigite o nome: "); // Mensagem para o usuario digitar o nome
        getchar();
        fflush(stdin);
        fgets(nome[linha], 200, stdin);
        printf("\nDigite o e-mail: "); // Mensagem para o usuario digitar o e-mail
        scanf("%s", &email[linha]);
        printf("\nDigite o CPF (somente numeros): ");  // Mensagem para o usuario digitar o CPF
        scanf("%lf", &cpf[linha]);
        printf("\nDigite o telefone (somente numeros): ");  // Mensagem para o usuario digitar o telefone
        scanf("%lf", &telefone[linha]);
        printf("\nDigite a idade (somente numeros): ");  // Mensagem para o usuario digitar a sua idade
        scanf("%d", &idade[linha]);
        printf("\nDigite a(s) comorbidade(s) (digitar '-' se nao tiver. Se tiver mais de uma, separa-las por ','): "); // Mensagem para o usuario digitar sua(s) comorbidades (caso tenha)
        getchar();
        fflush(stdin);
        fgets(comorbidade[linha], 200, stdin);
        do {
            printf("\nQual vacina o usuário tomará?\n"); // Mensagem para o usuario digitar a vacina
            printf("[1] - Coronavac \n[2] - AstraZeneca \n[3] - Pfizer \n[4] - Janssen\n\n"); // Menu da vacina
            scanf("%d", &vacina_numero[linha]);
            if (vacina_numero[linha] <= 0 || vacina_numero[linha] >= 5){
                printf("\nDigite uma opcao valida!");
            }
        } while (vacina_numero[linha] <= 0 || vacina_numero[linha] >= 5);
        do {
            printf("\nO usuario pertence a algum desses grupos?\n"); // Mensagem para o usuario digitar os grupos prioritarios
            printf("[1] - Profissional da saude\n[2] - Indigena ou quilombola\n[3] - Profissional da educacao \n[4] - Trabalhadores do transporte coletivo\n[5] - Nao se aplica\n\n"); // Menu da vacina
            scanf("%d", &grupo[linha]);
            if (grupo[linha] <= 0 || grupo[linha] >= 6){
                printf("\nDigite uma opcao valida!");
            }
        } while (grupo[linha] <= 0 || grupo[linha] >= 6);
        do {
            printf("\n----------------------------- \n");
            printf("Digite 1 para editar alguma informação ou outro valor para terminar o cadastro: "); // Inicio da edicao
            scanf("%d", &edicao_opcao);
            if (edicao_opcao == 1){ // Se o usuario escolher 1 comeca a edicao
                printf("\n======== EDITANDO CADASTRO ========\n"); // Cabecalho da edicao
                printf("\nQual dado você deseja editar?\n"); // Mensagem para o usuario digitar qual dado deseja editar
                printf("[1] - Nome \n[2] - E-mail \n[3] - CPF \n[4] - Telefone \n[5] - Idade \n[6] - Comorbidades \n[7] - Vacina\n[8] - Grupo\n\n"); // Menu para escolher o dado de edicao
                scanf("%d", &edicao);
                printf("\n------ Opção %d selecionada ------\n", edicao);
                switch (edicao){
                    case 1: // Editando nome
                        printf("\nDigite o nome: ");
                        getchar();
                        fflush(stdin);
                        fgets(nome[linha], 200, stdin);
                        printf("\nNome alterado!");
                        break;
                    case 2: // Editando e-mail
                        printf("\nDigite o e-mail: ");
                        scanf("%s", &email[linha]);
                        printf("\nE-mail alterado!");
                        break;
                    case 3: // Editando CPF
                        printf("\nDigite o CPF (somente numeros): ");
                        scanf("%lf", &cpf[linha]);
                        printf("\nCPF alterado!");
                        break;
                    case 4: // Editando telefone
                        printf("\nDigite o telefone (somente numeros): ");
                        scanf("%lf", &telefone[linha]);
                        printf("\nTelefone alterado!");
                        break;
                    case 5: // Editando idade
                        printf("\nDigite a idade (somente numeros): ");
                        scanf("%d", &idade[linha]);
                        printf("\nIdade alterada!");
                        break;
                    case 6: // Editando comorbidade
                        printf("\nDigite a(s) comorbidade(s) (digitar '-' se nao tiver. Se tiver mais de uma, separa-las por ','): ");
                        getchar();
                        fflush(stdin);
                        fgets(comorbidade[linha], 200, stdin);
                        printf("\nComorbidades alteradas!");
                        break;
                    case 7: // Editando vacina
                        do {
                            printf("\nQual vacina o usuário tomará?\n"); // Mensagem para o usuario digitar a vacina
                            printf("[1] - Coronavac \n[2] - AstraZeneca \n[3] - Pfizer \n[4] - Janssen\n\n"); // Menu da vacina
                            scanf("%d", &vacina_numero[linha]);
                            if (vacina_numero[linha] <= 0 || vacina_numero[linha] >= 5){
                                printf("\nDigite uma opcao valida!");
                            }
                        } while (vacina_numero[linha] <= 0 || vacina_numero[linha] >= 5);
                        printf("\nVacina alterada!");
                        break;
                    case 8: // Editando grupo
                        do {
                            printf("\nO usuario pertence a algum desses grupos?\n"); // Mensagem para o usuario digitar a vacina
                            printf("[1] - Profissional da saude\n[2] - Indigena ou quilombola\n[3] - Profissional da educacao \n[4] - Trabalhadores do transporte coletivo\n[5] - Nao se aplica\n\n"); // Menu da vacina
                            scanf("%d", &grupo[linha]);
                            if (grupo[linha] <= 0 || grupo[linha] >= 6){
                                printf("\nDigite uma opcao valida!");
                            }
                            } while (grupo[linha] <= 0 || grupo[linha] >= 6);
                            printf("\Grupo alterado!");
                            break;
                }
            }
        } while (edicao_opcao == 1);

        printf("\n----------------------------- \n");

        mesvacina(idade, vacina_numero, grupo, linha);

        printf("\n----------------------------- \n");

        if (vacina_numero[linha] == 1){
            strcpy (vacina_nome[linha],"Coronavac"); // Atribuindo nome a vacina 1
            vacina_segunda_dose[linha] = 28; // Calculando data da segunda dose
            printf("\nALERTA: Sua segunda dose de %s deverá ser aplicada em até %d dias após a primeira dose.\n", vacina_nome[linha], vacina_segunda_dose[linha]);
        } else if (vacina_numero[linha] == 2){
            strcpy (vacina_nome[linha],"Astrazeneca"); // Atribuindo nome a vacina 2
            vacina_segunda_dose[linha] = 90; // Calculando data da segunda dose
            printf("\nALERTA: Sua segunda dose de %s deverá ser aplicada em até %d dias após a primeira dose.\n", vacina_nome[linha], vacina_segunda_dose[linha]);
        } else if (vacina_numero[linha] == 3){
            strcpy (vacina_nome[linha],"Pfizer"); // Atribuindo nome a vacina 3
            vacina_segunda_dose[linha] = 21; // Calculando data da segunda dose
            printf("\nALERTA: Sua segunda dose de %s deverá ser aplicada em até %d dias após a primeira dose.\n", vacina_nome[linha], vacina_segunda_dose[linha]);
        } else {
            strcpy (vacina_nome[linha],"Janssen"); // Atribuindo nome a vacina 4
            vacina_segunda_dose[linha] = 0; // Janssen possui dose unica
            printf("\nALERTA: A vacina da %s possui dose única.\n", vacina_nome[linha]);
        }

        printf("\n----------------------------- \n");

        ID[linha] = rand() % 1000; //Guarda no ID um número aleatório
        printf("\nCadastro realizado com sucesso! Numero do comprovante: %d\n", ID[linha]); //Mensagem apresentando o ID
        insere_Fila(ponteirooficial, ID[linha]);
        insere_Fila(ponteirodemonstracao, ID[linha]);
        printf("\n----------------------------- \n");
        printf("\nDigite 1 para continuar cadastrando ou outro valor para sair: ");  // Mensagem para o usuario escolher a opcao
        scanf("%d", &opcao);
        linha++; // Acrescentar um ao valor da linha
        printf("\n----------------------------------- \n"); // Finalizacao do cadastro
    }while(opcao == 1); //Condicao de parada do cadastro

}
void pesquisa(){

    system("color 8F");

    int opcao, contador = 0;
    int idPesquisa;
    double cpfPesquisa;
    char emailPesquisa[50];
    int i;
    do{
        printf(" ----------------------------- \n");
        printf("     PESQUISAR CADASTRADOS      \n");
        printf(" ----------------------------- \n");
        printf("\nDigite o numero:\n1 - Pesquisa pelo CPF\n2 - Pesquisa pelo e-mail\n3 - Pesquisa pelo ID\n");
        scanf("%d", &opcao);
        printf("\n------ Opção %d selecionada ------\n", opcao);
        switch(opcao){
        case 1:
            printf("\nDigite o CPF: ");
            scanf("%lf", &cpfPesquisa);
            for(i = 0; i < TAMANHO; i++){
                if(cpf[i]==cpfPesquisa){
                    printf("\nID: %d\nNome: %s\nEmail: %s\nCPF: %.0lf\nTelefone: %.0lf\nIdade: %d\nComorbidade: %s\nVacina: %s\nSua segunda dose deverá ser tomada em até %d dias a partir da primeira dose\nMes da primeira dose: %d\nMes da segunda dose: %d",ID[i], nome[i], email[i], cpf[i], telefone[i], idade[i], comorbidade[i], vacina_nome[i], vacina_segunda_dose[i], data_primeira[i], data_segunda[i]);
                    contador++;
                }
            }
            if (contador == 0){
                printf("\nCPF nao encontrado!\n");
            }
            contador = 0;
            break;
        case 2:
            printf("\nDigite o e-mail: ");
            scanf("%s", &emailPesquisa);
            for(i = 0; i < TAMANHO; i++){
                if(strcmp(email[i], emailPesquisa)==0){
                    printf("\nID: %d\nNome: %s\nEmail: %s\nCPF: %.0lf\nTelefone: %.0lf\nIdade: %d\nComorbidade: %s\nVacina: %s\nSua segunda dose deverá ser tomada em até %d dias a partir da primeira dose\nMes da primeira dose: %d\nMes da segunda dose: %d",ID[i], nome[i], email[i], cpf[i], telefone[i], idade[i], comorbidade[i], vacina_nome[i], vacina_segunda_dose[i], data_primeira[i], data_segunda[i]);
                    contador++;
                }
            }
            if (contador == 0){
                printf("\nE-mail nao encontrado!\n");
            }
            contador = 0;
            break;
        case 3:
            printf("\nDigite o ID: ");
            scanf("%d", &idPesquisa);
            for(i = 0; i < TAMANHO; i++){
                if(ID[i]==idPesquisa){
                    printf("\nID: %d\nNome: %s\nEmail: %s\nCPF: %.0lf\nTelefone: %.0lf\nIdade: %d\nComorbidade: %s\nVacina: %s\nSua segunda dose deverá ser tomada em até %d dias a partir da primeira dose\nMes da primeira dose: %d\nMes da segunda dose: %d",ID[i], nome[i], email[i], cpf[i], telefone[i], idade[i], comorbidade[i], vacina_nome[i], vacina_segunda_dose[i], data_primeira[i], data_segunda[i]);
                    contador++;
                }
            }
            if (contador == 0){
                printf("\nID nao encontrado!\n");
            }
            contador = 0;
            break;
        default:
            printf("\nOpcao invalida!");
            break;
        }

        printf("\n----------------------------- \n");
        printf("\nDigite 1 para continuar pesquisando ou outro valor para sair: ");
        printf("\n");
        scanf("%d", &opcao);
    }while(opcao == 1);

}


void lista(){
    int i,regs;
    FILE *arq_lista;
    FILE* verifica;


    verifica = fopen("Lista_cadastro.txt", "r");
    if(verifica==NULL){
        arq_lista = fopen("Lista_cadastro.txt","w"); //abrindo para manter a linha head
        fprintf(arq_lista,"ID; Nome; Email; CPF; Telefone; Idade; Comorbidade; Nome da vacina; Segunda dose (dias); Mes da primeira dose; Mes da segunda dose\n" );
        fclose(arq_lista);
    }



    if(arq_lista == NULL){
        printf("Erro na abertura do arquivo!\n");
        return 1;
    }



    else{
        arq_lista = fopen("Lista_cadastro.txt","a"); //abrindo para gravacao de novos cadastros
        for(i=0; i<TAMANHO; i++){
            if(cpf[i]>0){
                   fprintf(arq_lista,"%d;%s;%s;%.0lf;%.0lf;%d;%s;%s;%d;%d;%d\n",ID[i], nome[i], email[i], cpf[i], telefone[i], idade[i], comorbidade[i], vacina_nome[i], vacina_segunda_dose[i], data_primeira[i], data_segunda[i]);
                   regs = i+1;
                  }
            else{
                break;
            }
        }
        fclose(arq_lista);
        printf("%i registros salvos!\nPressione o enter.",regs);
    }

    getchar(); // Colocamos a funcao getchar para manter a tela aberta quando o usuario escolher uma outra opcao.
    getchar(); // Dependendo do sistema operacional, compilador e demais fatores, o programa pode funcionar com apenas um getchar, por motivos de precaucao colocamos dois.

}
void mesvacina(int idade[], int vacina_numero[], int grupo_vacina[], int linha) {

        system("color 8F");

        if (idade[linha] >= 80 || grupo_vacina[linha] == 1){
            printf ("\nA data da sua primeira dose sera em fevereiro!\n");
            data_primeira[linha] = 2;
        }
        else if ((80 > idade[linha] && idade[linha] >= 69)|| grupo_vacina[linha] == 2) {
            printf ("\nA data da sua primeira dose sera em marco!\n");
            data_primeira[linha] = 3;
        }
        else if ((69 > idade[linha] && idade[linha] >= 63)|| grupo_vacina[linha] == 3){
            printf ("\nA data da sua primeira dose sera em abril!\n");
            data_primeira[linha] = 4;
        }
        else if ((63 > idade[linha] && idade[linha] >= 60)|| grupo_vacina[linha] == 4){
            printf ("\nA data da sua primeira dose sera em maio!\n");
            data_primeira[linha] = 5;
        }
        else if (idade[linha] < 60){
            printf ("\nA data da sua primeira dose ainda nao foi marcada!\n");
            data_primeira[linha] = 0;
        }

        if (data_primeira[linha] == 0) {
            data_segunda[linha] = 0;
        }

        else {
            switch(vacina_numero[linha]){

                case 1:
                data_segunda[linha] = data_primeira[linha] + 1;
                if (data_segunda[linha] > 12) {
                    data_segunda[linha] == data_segunda[linha] - 12;
                }
                break;

                case 2:
                data_segunda[linha] = data_primeira[linha] + 3;
                if (data_segunda[linha] > 12) {
                    data_segunda[linha] == data_segunda[linha] - 12;
                }
                break;

                case 3:
                data_segunda[linha] = data_primeira[linha] + 1;
                if (data_segunda[linha] > 12) {
                    data_segunda[linha] == data_segunda[linha] - 12;
                }
                break;

                case 4:
                data_segunda[linha] = 13;
                break;
            }
        }

        switch(data_segunda[linha]){

            case 0:
            printf("\nVoce ainda nao tem data marcada para a primeira dose, portanto nao ha previsao para a sua segunda dose!\n");
            break;

            case 1:
            printf("\nSua segunda dose sera em janeiro!\n");
            break;

            case 2:
            printf("\nSua segunda dose sera em fevereiro!\n");
            break;

            case 3:
            printf("\nSua segunda dose sera em marco!\n");
            break;

            case 4:
            printf("\nSua segunda dose sera em abril!\n");
            break;

            case 5:
            printf("\nSua segunda dose sera em maio!\n");
            break;

            case 6:
            printf("\nSua segunda dose sera em junho!\n");
            break;

            case 7:
            printf("\nSua segunda dose sera em julho!\n");
            break;

            case 8:
            printf("\nSua segunda dose sera em agosto!\n");
            break;

            case 9:
            printf("\nSua segunda dose sera em setembro!\n");
            break;

            case 10:
            printf("\nSua segunda dose sera em outubro!\n");
            break;

            case 11:
            printf("\nSua segunda dose sera em novembro!\n");
            break;

            case 12:
            printf("\nSua segunda dose sera em dezembro!\n");
            break;

            case 13:
            printf("\nSua vacina e de aplicacao unica!\n");
            break;
        }
}

void filas (){

    system("color 8F");

    int chamada = 0, contador_ID = 0, autenticando_remocao;

    do{
        printf(" ----------------------------- \n");
        printf("     ORDEM DE VACINAÇÃO      \n");
        printf(" ----------------------------- \n");
        imprimindo_Fila(ponteirodemonstracao);
        printf("\nDigite 1 para chamar o paciente ou outro valor para sair: ");
        scanf("%d", &chamada);
        if (chamada == 1){
            autenticando_remocao = remove_Fila(ponteirodemonstracao);
            if (autenticando_remocao == 0){
                printf("\nNão é possível chamar outro paciente!\n\n");
                chamada = 0;
            } else {
                printf("\nO paciente com ID: %d foi chamado!\n\n", ID[contador_ID]);
            }
        }
        contador_ID++;
    } while (chamada == 1);
}
