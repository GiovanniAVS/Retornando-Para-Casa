#ifndef PLANETA_H_
#define PLANETA_H_
#include <iostream>
#include <math.h>

using namespace std;

class Planeta{
    private:
        string nome;
        int dist;
    public:
        Planeta();
        ~Planeta();
        void set_nome(string nome){ this->nome = nome; }
        void set_dist(int dist){ this->dist = dist; }
        string get_nome(){ return this->nome; }
        int get_dist(){ return this->dist; }

};


#endif /*PLANETA_H_*/