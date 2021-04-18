#ifndef ORDENACAO_H_
#define ORDENACAO_H_
#include <iostream>
#include "planeta.h"
#include <math.h>

using namespace std;

class Ordenacao{
    private:

    public:
        Ordenacao();
        ~Ordenacao();
        void Insertion_sort(Planeta *array, int nlinhas);
        void Merge_sort(Planeta *array, int ini, int fim);
        void merge(Planeta *array, int ini, int meio, int fim);
        void Quick_sort(Planeta *array, int ini, int fim);
        int particao(Planeta *array, int ini, int fim);
        void Comb_sort(Planeta *array, int tam);
        int get_gap(int gap);
        void Quick_sort_mod(Planeta *array, int esq, int dir);
        void particao_mod(Planeta *array, int esq, int dir, int& i, int& j);
        
};


#endif /*ORDENACAO_H_*/