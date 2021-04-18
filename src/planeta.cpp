#include <iostream>
#include "planeta.h"
#include <math.h>
#include <string.h> 
#include <stdio.h>

using namespace std;

Planeta::Planeta(){
    string s = "N/A";
    this->set_dist(0);
    this->set_nome(s);
}

Planeta::~Planeta(){
    
}
