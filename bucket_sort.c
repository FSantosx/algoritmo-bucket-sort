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

// funcao para iniciar ---------------
// o vetor com numero  ---------------
// aleatorio           ---------------
void init_arr(int *arr){
    for(int i=0;i<MAX;i++)
        arr[i] = rand() % CAP;
}
//------------------------------------

// funcao para exibir ----------------
// vetor com numero   ----------------
// aleatorio          ----------------
void show_arr(int *arr){
    printf("\tArray Original\n");
    for(int i = 0; i<MAX; i++)
        printf("\tArray[%d] = %d\n", i+1, arr[i]);
}
// -----------------------------------

// funcao para iniciar ---------------
// o bucket com topo   ---------------
// no 0                ---------------
void init_bucket(bucket *b){
    // inicializando todos os bucket
    for(int i = 0; i < NUMBER_BUCKS; i++){
        b[i].len = 0;
        // b[i].pbuck = malloc(sizeof(int));
        b[i].pbuck = NULL;
    }
}
// -----------------------------------

// funcao para exibir ----------------
// os buckets         ----------------
// aleatorio          ----------------
void show_buckets(bucket *b){
    for(int i = 0; i < NUMBER_BUCKS; i++)
        printf("\tBucket[%d].top = %d\n", i+1, b[i].len);
}
// -----------------------------------

void bucket_sort(bucket *b, int *vector){
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

    for(i=0;i<NUMBER_BUCKS;i++){
        int *temp = sorted(b[i].pbuck, b[i].len);
        for(j=0;j<b[i].len;j++){
            // printf("\t%d\n", b[i].pbuck[j]);
            printf("\t%d\n", temp[j]);
        }
        printf("\n");
    }
}

int* sorted(int *arr, int len){
    int temp;
    for(int i=0;i<len-2;i++){
        for(int j=len;j>i;j--){
            if(arr[i] < arr[j]){
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
    int arr[MAX];
    init_arr(arr);
    init_bucket(b);
    bucket_sort(b, arr);
    return 0;
}