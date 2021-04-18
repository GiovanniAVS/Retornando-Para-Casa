#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <time.h>
#include <chrono>
#include "planeta.h"
#include "ordenacao.h"

using namespace std;

int main( int argc, char *argv[ ] ){
    int i;
    time_t t_ini, t_fim;

    fstream dados(argv[1]);
    int nlinhas = stoi(argv[2]);

    Ordenacao ord;

    Planeta *array_de_planetas = new Planeta[nlinhas];

    if (dados.is_open()){
        for(i = 0; i < nlinhas; i++) {
            string s1, s2;
            dados >> s1;
            dados >> s2;
            array_de_planetas[i].set_nome(s1);
            array_de_planetas[i].set_dist(stoi(s2));
        }
    }
    else{
        cout << "Nao foi possivel abrir o arquivo de dados \n";
        exit(0);
    }
    dados.close();
    
    for(i = 0; i < 7; i++){
        cout<<array_de_planetas[i].get_nome()<<" "<<array_de_planetas[i].get_dist()<<endl;
    }

    t_ini = clock();
    //ord.Insertion_sort(array_de_planetas, nlinhas); //função para organizar
    //ord.Merge_sort(array_de_planetas, 0, nlinhas-1);
    //ord.Quick_sort(array_de_planetas, 0, nlinhas-1);
    //ord.Comb_sort(array_de_planetas, nlinhas);
    ord.Quick_sort_mod(array_de_planetas, 0, nlinhas-1);

    t_fim = clock();
    cout<<"\n";

    for(i = 0; i < 7; i++){
        cout<<"->"<<array_de_planetas[i].get_nome()<<" "<<array_de_planetas[i].get_dist()<<endl;
    }
   
    cout<<"\n Tempo gasto: "<<double(t_fim - t_ini) / CLOCKS_PER_SEC<<" segundos"<<endl;

    delete array_de_planetas;

return 0;
}