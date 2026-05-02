#include "sorts.hpp"
#include <iostream>
#include <concepts>
#include <random>
#include "randfiller.h"

using namespace std;

int main() {
    randfiller rf; 
    vector<int> dim(100); 
    rf.fill(dim,100,8000);

    for (int i=0; i<100;i++){
        
        vector<int> casuali(dim[i]); //così mi creo un vettore fatto da tanti elementi quanti il numero in posizione i-esima di dim

        rf.fill(casuali,-500,500);//riempilo con numeri tra -500 e 500

        //metti in ordine
        quick_sort(casuali,0,casuali.size()-1);

        //vedi se funziona
        //is_sorted(casuali);
        if (!is_sorted(casuali.begin(),casuali.end())){
            cerr<<"il quicksort non ha fatto il suo lavoro \n";
            return EXIT_FAILURE;
        }
    }
    cout<<"il quicksort ha fatto il suo lavoro sui numeri\n";

    vector<string> stringa={"ciao", "mamma", "papa", "nonna", "nonno", "cugina", "zio", "parente", "nicole", "conni"};
    quick_sort(stringa,0,stringa.size()-1);

    if (!is_sorted(stringa)){
            cerr<<"il quicksort non ha fatto il suo lavoro sulle stringhe \n";
            return EXIT_FAILURE;
        }
    cout<<"il quicksort ha fatto il suo lavoro sulle stringhe\n";
    
    return EXIT_SUCCESS;
}
