#include "unidirected_edge.hpp"
#include <iostream>

using namespace std;

int main(){
    unidirected_edge<unsigned int> a1(3,6);
    unidirected_edge<unsigned int> a2(2,4);
   
    cout<<"dell'arco 1 il nodo di partenza è "<<a1.from()<<'\n';
    cout<<"dell'arco 2 il nodo di arrivo è "<<a2.to()<<'\n';
    
    if (a1<a2){
        cout<<"è vero che arco 1 viene prima di arco 2? sì"<<'\n';
    }else{
        cout<<"è vero che arco 1 viene prima di arco 2? no"<<'\n';
    }
    
    if (a1==a2){
        cout<<"è vero che arco 1 e 2 sono uguali? sì"<<'\n';
    }else{
        cout<<"è vero che arco 1 e 2 sono uguali? no"<<'\n';
    }
    
}