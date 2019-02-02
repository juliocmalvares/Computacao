#include <iostream>
#include <cstdlib>
#include <cuda.h>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

string NumberToString (int Number){
    stringstream ss;
    ss << Number;
    return ss.str();
}

struct no{
    short x,y,z;
    bool condicao;
    //string caminho;
};

typedef no TipoChave;

struct TipoItem{
    TipoChave chave;
};

struct TipoCelula{
    TipoItem item;
    TipoCelula* prox;
};

struct TipoLista{
    TipoCelula *primeiro, *ultimo;
};

__device__ void FLVazia(TipoLista *lista){
    lista->primeiro = new TipoCelula;
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = NULL;
}

__device__ int Vazia(TipoLista lista){return (lista.primeiro == lista.ultimo);}

__device__ void Insere(TipoLista *lista, int x, int y, int z, bool condicao){
    lista->ultimo->prox = new TipoCelula;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item.chave.x = x;
    lista->ultimo->item.chave.y = y;
    lista->ultimo->item.chave.z = z;
    lista->ultimo->item.chave.condicao = condicao;
    //lista->ultimo->item.chave.caminho = texto;
    lista->ultimo->prox = NULL;
    //printf("Insere: %d %d %d\n", x, y, z);
}

__device__ void Retira(TipoCelula *p, TipoLista *lista, TipoItem *item){
    if(Vazia (*lista) || (p == NULL) || (p->prox == NULL)) return;

    TipoCelula *q = p->prox;
    *item = q->item;
    //printf("Retira: %d %d %d\n", item->chave.x, item->chave.y, item->chave.z);
    p->prox = q->prox;
    if(p->prox == NULL)lista->ultimo = p;
    delete q;
}

__global__ void logicaPrograma(TipoLista *lista, int xDest, int yDest, int zDest, int pi, int *contador_caminhos, int x, int y, int z){
    FLVazia(lista);
    Insere(lista, 0,0,0,false);
    //TipoCelula *aux = lista->primeiro->prox;
    int i = 0;
   // int x = 0;
    //int y = 0;
    //int z = 0;
    int soma = 0;
    bool c = false;
    //string s = "(0,0,0)";
    int contador = 0;
   // printf("%s", "Entrei");
    while(i<pi)
    {
        x = lista->primeiro->prox->item.chave.x;
        y = lista->primeiro->prox->item.chave.y;
        z = lista->primeiro->prox->item.chave.z;
        c = lista->primeiro->prox->item.chave.condicao;
        //printf("Lista 0: %d %d %d\n", lista->primeiro->item.chave.x,lista->primeiro->item.chave.y,lista->primeiro->item.chave.z);
        printf("%d %d %d %d\n", x, y, z, soma);
        if(pi == (i+1) && i!=0){break;}

        if((x != xDest) && (y != yDest) && (z != zDest))
        {
            /*Insere(lista,x+1,y,z,c,(s + "->("+ NumberToString(x+1) + "," + NumberToString(y) + "," + NumberToString(z) + ")")); pi++;
            Insere(lista,x,y+1,z,c,(s + "->("+ NumberToString(x) + "," + NumberToString(y+1) + "," + NumberToString(z) + ")")); pi++;
            Insere(lista,x,y,z+1,c,(s + "->("+ NumberToString(x) + "," + NumberToString(y) + "," + NumberToString(z+1) + ")")); pi++;
            Insere(lista,x+1,y+1,z,true,(s + "->("+ NumberToString(x+1) + "," + NumberToString(y+1) + "," + NumberToString(z) + ")")); pi++;
            Insere(lista,x+1,y,z+1,true,(s + "->("+ NumberToString(x+1) + "," + NumberToString(y) + "," + NumberToString(z+1) + ")")); pi++;
            Insere(lista,x,y+1,z+1,true,(s + "->("+ NumberToString(x) + "," + NumberToString(y+1) + "," + NumberToString(z+1) + ")")); pi++;
            Insere(lista,x+1,y+1,z+1,true,(s + "->("+ NumberToString(x+1) + "," + NumberToString(y+1) + "," + NumberToString(z+1) + ")")); pi++;*/
            Insere(lista,x+1,y,z,c); pi++;
            Insere(lista,x,y+1,z,c); pi++;
            Insere(lista,x,y,z+1,c); pi++;
            Insere(lista,x+1,y+1,z,true); pi++;
            Insere(lista,x+1,y,z+1,true); pi++;
            Insere(lista,x,y+1,z+1,true); pi++;
            Insere(lista,x+1,y+1,z+1,true); pi++;
        }

        if((x == xDest) && (y != yDest) && (z != zDest))
        {
            /*Insere(lista,x,y+1,z,c,(s + "->("+ NumberToString(x) + "," + NumberToString(y+1) + "," + NumberToString(z) + ")")); pi++;
            Insere(lista,x,y,z+1,c,(s + "->("+ NumberToString(x) + "," + NumberToString(y) + "," + NumberToString(z+1) + ")")); pi++;
            Insere(lista,x,y+1,z+1,true,(s + "->("+ NumberToString(x) + "," + NumberToString(y+1) + "," + NumberToString(z+1) + ")")); pi++;*/
           // printf("Condicao 1: %d %d %d %d\n", x, y, z, soma);
            Insere(lista,x,y+1,z,c); pi++;
            Insere(lista,x,y,z+1,c); pi++;
            Insere(lista,x,y+1,z+1,true); pi++;
        }

        if((x != xDest) && (y == yDest) && (z != zDest))
        {
            /*Insere(lista,x+1,y,z,c,(s + "->("+ NumberToString(x+1) + "," + NumberToString(y) + "," + NumberToString(z) + ")")); pi++;
            Insere(lista,x,y,z+1,c,(s + "->("+ NumberToString(x) + "," + NumberToString(y) + "," + NumberToString(z+1) + ")")); pi++;
            Insere(lista,x+1,y,z+1,true,(s + "->("+ NumberToString(x+1) + "," + NumberToString(y) + "," + NumberToString(z+1) + ")")); pi++;*/
            //printf("Condicao 2: %d %d %d %d\n", x, y, z, soma);
            Insere(lista,x+1,y,z,c); pi++;
            Insere(lista,x,y,z+1,c); pi++;
            Insere(lista,x+1,y,z+1,true); pi++;
        }

        if((x != xDest) && (y != yDest) && (z == zDest))
        {
           /* Insere(lista,x+1,y,z,c,(s + "->("+ NumberToString(x+1) + "," + NumberToString(y) + "," + NumberToString(z) + ")")); pi++;
            Insere(lista,x,y+1,z,c,(s + "->("+ NumberToString(x) + "," + NumberToString(y+1) + "," + NumberToString(z) + ")")); pi++;
            Insere(lista,x+1,y+1,z,true,(s + "->("+ NumberToString(x+1) + "," + NumberToString(y+1) + "," + NumberToString(z) + ")")); pi++;*/
            //printf("Condicao 3: %d %d %d %d\n", x, y, z, soma);
            Insere(lista,x+1,y,z,c); pi++;
            Insere(lista,x,y+1,z,c); pi++;
            Insere(lista,x+1,y+1,z,true); pi++;
        }

        if((x == xDest) && (y == yDest) && (z != zDest))
        {
            //Insere(lista,x,y,z+1,c,(s + "->("+ NumberToString(x) + "," + NumberToString(y) + "," + NumberToString(z+1) + ")")); pi++;
            //printf("Condicao 4: %d %d %d %d\n", x, y, z, soma);
            Insere(lista,x,y,z+1,c); pi++;
        }

        if((x == xDest) && (y != yDest) && (z == zDest))
        {
            //Insere(lista,x,y+1,z,c,(s + "->("+ NumberToString(x) + "," + NumberToString(y+1) + "," + NumberToString(z) + ")")); pi++;
            //printf("Condicao 5: %d %d %d %d\n", x, y, z, soma);
            Insere(lista,x,y+1,z,c); pi++;
        }

        if((x != xDest) && (y == yDest) && (z == zDest)){
            //Insere(lista,x+1,y,z,c,(s + "->("+ NumberToString(x+1) + "," + NumberToString(y) + "," + NumberToString(z) + ")")); pi++;
            //printf("Condicao 6: %d %d %d %d\n", x, y, z, soma);
            Insere(lista,x+1,y,z,c); pi++;
        }
       // printf("%d %d %d %d\n", x, y, z, soma);
        if(c && (x == xDest) && (y == yDest) && (z == zDest)){
           // printf("%d %d %d %d\n", x, y, z, soma);
            contador++;
            //cout<<s<<endl<<endl;
        }

        Retira(lista->primeiro, lista, &lista->primeiro->item);
        //delete aux;
        //TipoCelula *aux = lista->primeiro->prox;
        //aux = aux->prox;

       // s = aux->item.chave.caminho;
        i++;
        soma += contador;
    }
    __syncthreads();
    *contador_caminhos = contador;

}

//Host é a CPU
//Device é a placa.

int main(){
    TipoLista *lista_device;

    int xDest_device = 1;
    int yDest_device = 2;
    int zDest_device = 3;
    int *contador_device = 0;
    int *contador_host = 0;
    int contador_final;

    //Alocação
    cudaMalloc(&lista_device, sizeof(TipoLista));
    cudaMalloc(&contador_device, sizeof(int));

    logicaPrograma<<<2,32>>>(lista_device, xDest_device, yDest_device, zDest_device, 1, contador_device, 0, 0, 0);
    cudaMemcpy(&contador_host, &contador_device, sizeof(int*), cudaMemcpyDeviceToHost);
    cudaFree(lista_device);
    cudaFree(contador_device);

    stringstream stream;
    stream << contador_host;
    stream >> std::hex >> contador_final;

    cout << "Caminhos:" << contador_final << endl;

    return 0;
}


