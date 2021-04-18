#include <iostream>
#include "planeta.h"
#include "ordenacao.h"
#include <math.h>
#include <string.h> 
#include <stdio.h>

using namespace std;

Ordenacao::Ordenacao(){
     
};

Ordenacao::~Ordenacao(){
     
};

void Ordenacao::Insertion_sort(Planeta *array, int nlinhas){
    int i, j;
    Planeta aux;


    for (i = 1; i < nlinhas; i++) { 
		j = i;

        while (j > 0 && array[j].get_dist() > array[j-1].get_dist()) {
            aux = array[j];
            array[j] = array[j-1];
            array[j-1] = aux;
			j -= 1;     
		}
	}  
}

void  Ordenacao::Merge_sort(Planeta *array, int ini, int fim){
    int meio;
    if(ini < fim){
        meio = (ini+fim)/2;
        Merge_sort(array, ini, meio);
        Merge_sort(array, meio+1, fim);
        merge(array, ini, meio, fim);
    }
}

void  Ordenacao::merge(Planeta *array, int ini, int meio, int fim){
    int posv1, posv2, tam, i, j, k;
    int fimv1 = 0, fimv2 = 0;
    tam = fim-ini+1;
    posv1 = ini;
    posv2 = meio+1;
    Planeta *vet3 = new Planeta[tam];
    if(vet3 != NULL){
        for(i=0; i<tam; i++){
            if(!fimv1 && !fimv2){
                if(array[posv1].get_dist() > array[posv2].get_dist()) //combinar ordenando
                    vet3[i] = array[posv1++]; 
                else
                    vet3[i] = array[posv2++]; 
            
                if(posv1 > meio) //checar se o vetor chegou ao fim
                    fimv1 = 1;
                if(posv2 > fim)
                    fimv2 = 1;
            }
            else{ //copiar o que sobrar
                if(!fimv1)
                   vet3[i] = array[posv1++];
                else
                    vet3[i] = array[posv2++]; 
            } 
        }
        k = ini;
        for(j=0; j<tam; j++){ //copia o vetor auxiliar para o original
            array[k]=vet3[j];
            k++;
        }

    }
    delete vet3;
}

void Ordenacao::Quick_sort(Planeta *array, int ini, int fim){
    int pivo;
    if(fim > ini){
        pivo = particao(array, ini, fim);
        Quick_sort(array, ini, pivo-1);
        Quick_sort(array, pivo+1, fim);
    }
}

int Ordenacao::particao(Planeta *array, int ini, int fim){
    int esq, dir, pivo;
    esq = ini;
    dir = fim;
    pivo = array[ini].get_dist();

    do{
        while (array[esq].get_dist() >= pivo)
            esq++;
        while (array[dir].get_dist() < pivo) 
            dir--;
        if (esq < dir){
            Planeta *aux = new Planeta();
            *aux = array[esq]; 
            array[esq] = array[dir]; 
            array[dir] = *aux;
            delete aux;
        }
    } while (esq < dir);

    array[ini] = array[dir];
    array[dir].set_dist(pivo); 

    

    return dir;

}

void Ordenacao::Comb_sort(Planeta *array, int tam){
    int gap = tam;
    bool troca = true;

    while (gap != 1 || troca == true){
        gap = get_gap(gap);
        troca = false; 
        for (int i = 0; i < tam - gap; i++){ //compara os elementos dado o gap
            if (array[i].get_dist() < array[i + gap].get_dist()){
                Planeta *aux = new Planeta();
                *aux = array[i];
                array[i] = array[i + gap];
                array[i + gap] = *aux;

                troca = true;
                delete aux;
            }
        }
    }
}

int Ordenacao::get_gap(int gap){
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    return gap;
}

void Ordenacao::particao_mod(Planeta *array, int esq, int dir, int& i, int& j){
    i = esq - 1, j = dir;
    int p = esq - 1, q = dir;
    int pivo = array[dir].get_dist();
 
    while (true) {
        while (array[++i].get_dist() > pivo)
            ;
        while (pivo > array[--j].get_dist())
            if (j == esq)
                break;
        if (i >= j)
            break;
        Planeta *aux = new Planeta(); //Menor para esquerda e maior para direita
        *aux = array[i]; 
        array[i] = array[j]; 
        array[j] = *aux;
        delete aux;
 
        if (array[i].get_dist() == pivo) { // Move todas os valores à esquerda do pivô para o início do vetor
            p++;
            Planeta *aux = new Planeta();
            *aux = array[i]; 
            array[i] = array[p]; 
            array[p] = *aux;
            delete aux;
        }
        if (array[j].get_dist() == pivo) { //Move todas os valores à direita do pivô para o fim do vetor
            q--;
            Planeta *aux = new Planeta();
            *aux = array[j]; 
            array[j] = array[q]; 
            array[q] = *aux;
            delete aux;
        }
    }
 
    Planeta *aux = new Planeta(); //Move valor do pivô para seu índice correto
    *aux = array[i]; 
    array[i] = array[dir]; 
    array[dir] = *aux;
    delete aux;

    j = i - 1;
    for (int k = esq; k < p; k++, j--){ // Mova todas as mesmas ocorrências à esquerda do início para o array adjacente
        Planeta *aux = new Planeta();
        *aux = array[j]; 
        array[j] = array[k]; 
        array[k] = *aux;
        delete aux;
    }
    i = i + 1;
    for (int k = dir - 1; k > q; k--, i++){ // Mova todas as mesmas ocorrências à direita do fim para o array adjacente
        Planeta *aux = new Planeta();
        *aux = array[i]; 
        array[i] = array[k]; 
        array[k] = *aux;
        delete aux;
    }
}
 
void Ordenacao::Quick_sort_mod(Planeta *array, int esq, int dir){
    if (dir <= esq)
        return;

    int i, j;
    particao_mod(array, esq, dir, i, j);
    Quick_sort_mod(array, esq, j);
    Quick_sort_mod(array, i, dir);
}
