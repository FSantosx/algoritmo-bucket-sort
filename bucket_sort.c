#include <stdio.h>
#include <stdlib.h>

// definição das constantes do sistema
#define SIZE_BUCK 100
#define NUMBER_BUCKS 10
#define MAX 10
// -----------------------------------

// definição da Struct ---------------
typedef struct SBucket{
    int top;
    int buck[SIZE_BUCK];
} bucket ;
// -----------------------------------

// definindo cabeçalho do projeto ----
void init_arr(int *arr);
void show_arr(int *arr);
void init_bucket(bucket *b);
// void show_buckets(bucket *b);
void sorted(int v[], int top);
void bucket_sort(bucket *b, int vector[]);
void orderly_array(int *arr);
// -----------------------------------

// funcao para iniciar ---------------
// o vetor com numero  ---------------
// aleatorio           ---------------
void init_arr(int *arr){
    for(int i=0;i<MAX;i++)
        arr[i] = rand() % 50;
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
        b[i].top = 0;
    }
}
// -----------------------------------

// funcao para exibir ----------------
// os buckets         ----------------
// aleatorio          ----------------
void show_buckets(bucket *b){
    for(int i = 0; i < NUMBER_BUCKS; i++)
        printf("\tBucket[%d].top = %d\n", i+1, b[i].top);
}
// -----------------------------------

void bucket_sort(bucket *b, int vector[]){
    int i,j;
    init_bucket(b);
    for(i=0;i<MAX;i++){
        j=(NUMBER_BUCKS)-1;
        while(1){
            if(j<0)
                break;
            if(vector[i]>=j*10){
                b[j].buck[b[j].top]=vector[i];
                (b[j].top)++;
                break;
            }
            j--;
        }
    }

    // laço para ordenar os elementos
    for(i=0;i<NUMBER_BUCKS;i++)                
        sorted(b[i].buck, b[i].top);

    // devolvendo os elementos para o array original   
    i=0;
    for(j=0;j<NUMBER_BUCKS;j++){
        for(int k=0;k<b[j].top;k++){
            vector[i]=b[j].buck[k];
            i++;
        }
    }
}

void sorted(int v[], int top){
    int i,j,temp,flag;
    if(top) {
        for(j=0;j<top-1;j++){
            flag=0;
            for(i=0;i<top-1;i++){
                if(v[i+1]<v[i]){
                    temp=v[i];
                    v[i]=v[i+1];
                    v[i+1]=temp;
                    flag=1;
                }
            }
            if(!flag)
                break;
        }
    }    
}

void orderly_array(int *arr){
    printf("\n\tArray ordenado\n");
    for(int i=0;i<MAX;i++){
        printf("\tArr[%d] = %d\n", i+1, arr[i]);
    }
}

int main(void) {
    bucket b;
    int arr;
    init_arr(&arr);
    show_arr(&arr);
    bucket_sort(&b, &arr);
    orderly_array(&arr);
    return 0;
}