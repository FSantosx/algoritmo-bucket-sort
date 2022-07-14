#include <stdio.h>
#include <stdlib.h>

// definição das constantes do sistema
#define NUMBER_BUCKS 10
#define MAX 100
#define CAP 50
// -----------------------------------

// definição da Struct ---------------
typedef struct SBucket{
    int len;
    int *pbuck;
} bucket ;
// -----------------------------------

// definindo cabeçalho do projeto ----
void init_arr(int *arr);
void show_arr(int *arr);
void init_bucket(bucket *b);
void show_buckets(bucket *b);
int* sorted(int *arr, int len);
void bucket_sort(bucket *b, int vector[]);
// -----------------------------------

void clearBuff(){
    while ((getchar() != '\n') && (!EOF));
}

// funcao para iniciar ---------------
// o vetor com numero  ---------------
// aleatorio           ---------------
void init_arr(int *arr){
    char key;
    srand(time(0));
    for(int i=0;i<MAX;i++)
        arr[i] = rand() % CAP;
    clearBuff();
    printf("Array iniciado com sucesso");
    printf("\n");
    printf("pressione <enter> para continuar ...");
    key = getchar();
}
//------------------------------------

// funcao para exibir ----------------
// vetor com numero   ----------------
// aleatorio          ----------------
void show_arr(int *arr){
    system("cls||clear");
    char key;
    printf("Array --> \n");
    for(int i = 0; i<MAX; i++)
        printf("\tArray[%d] = %d\n", i+1, arr[i]);
    printf("\n\n");

    clearBuff();
    printf("Pressione <enter> para retornar...");
    key = getchar();
    system("cls||clear");
}
// -----------------------------------

// funcao para iniciar ---------------
// o bucket com topo   ---------------
// no 0                ---------------
void init_bucket(bucket *b){
    char key;
    // inicializando todos os bucket
    for(int i = 0; i < NUMBER_BUCKS; i++){
        b[i].len = 0;
        // b[i].pbuck = malloc(sizeof(int));
        b[i].pbuck = NULL;
    }
    clearBuff();
    printf("Buckets iniciados com sucesso");
    printf("\n");
    printf("pressione <enter> para continuar ...");
    key = getchar();
}
// -----------------------------------

// funcao para exibir ----------------
// os buckets         ----------------
// aleatorio          ----------------
void show_buckets(bucket *b){
    system("cls||clear");
    char key;
    printf("Buckets inicializados --> \n");
    for(int i = 0; i < NUMBER_BUCKS; i++)
        printf("\tBucket[%d].len = %d\n", i+1, b[i].len);
    clearBuff();
    printf("Pressione <enter> para retornar...");
    key = getchar();
}
// -----------------------------------

void bucket_sort(bucket *b, int *vector){
    char key;
    int i,j, res;
    for(i=0;i<MAX;i++){
        int *arrTemp;
        res = (int)(vector[i] / (CAP / NUMBER_BUCKS));
        if(b[res].len > 0){
            arrTemp = malloc(sizeof(int) * (b[res].len+1));
            for(int k = 0; k < b[res].len;k++){
                arrTemp[k] = b[res].pbuck[k];
            }
            arrTemp[b[res].len] = vector[i];
            b[res].pbuck = arrTemp;
            b[res].len++;
        } else {
            b[res].len = 1;
            b[res].pbuck = malloc(sizeof(int) * b[res].len);
            b[res].pbuck[0] = vector[i];
        }
    }
    // apresentação dos buckets préviamente ordenados
    for(i=0;i<NUMBER_BUCKS;i++){
        int *temp = sorted(b[i].pbuck, b[i].len);
        for(j=0;j<b[i].len;j++){
            printf("\t%d\n", temp[j]);
        }
        printf("\n");
    }
    clearBuff();
    printf("Pressione <enter> para continuar...");
    key = getchar();

    // retornando os valores ao array principal
    int v = 0;
    for(i=0;i<NUMBER_BUCKS;i++){
        int *temp = sorted(b[i].pbuck, b[i].len);
        for(j=0;j<b[i].len;j++){
            vector[v] = temp[j];
            v++;
        }
        printf("\n");
    }

    clearBuff();
    printf("Pressione <enter> para retornar...");
    key = getchar();
}

int* sorted(int *arr, int len){
    int temp;
    for(int i=0; i < len; i++){
        for(int j=i+1; j < len; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main(void) {
    bucket *b = malloc(sizeof(bucket) * NUMBER_BUCKS);
//    bucket *bpiorcaso = malloc(sizeof(bucket) * 1);
//    bucket *bcasomedio = malloc(sizeof(bucket) * 5);
//    bucket *bmelhorcaso = malloc(sizeof(bucket) * 10);
    int arr[MAX], op;
//    int arrTestes[10];
    do {
        system("cls||clear");
        printf("\n|----------------------------------------|\n");
        printf("|                    MENU                |\n");
        printf("|----------------------------------------|\n");
        printf("|                                        |\n");
        printf("| (1) Iniciar Array randomico            |\n");
        printf("| (2) Iniciar buckets                    |\n");
        printf("| (3) Apresentar array                   |\n");
        printf("| (4) Apresentar Buckets inicializados   |\n");
        printf("| (5) Bucket Sort                        |\n");
        printf("| (6) Criar array com valores teste      |\n");
        printf("| (0) Finalizar execucao                 |\n");
        printf("|                                        |\n");
        printf("|----------------------------------------|\n");
        printf("|                                        |\n");
        printf("|----------------------------------------|\n\n");
        scanf("%d", &op);
        system("cls||clear");
        switch(op){
        case 1:
            init_arr(arr);
            break;
        case 2:
            init_bucket(b);
            break;
        case 3:
            show_arr(arr);
            break;
        case 4:
            show_buckets(b);
            break;
        case 5:
            bucket_sort(b, arr);
            break;
        case 6:
            system("cls||clear");
            for (int i = 0; i < 10; i++){
                printf("Forneca o %o. valor: \n", i+1);
                scanf("%d", &arrTestes[i]);
            }
            system("cls||clear");
            break;
        default:
            break;
        }
    } while (op != 0);
    return 0;
}
