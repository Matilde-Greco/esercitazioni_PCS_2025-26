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

        rf.fill(casuali,1,500);//riempilo con numeri tra 1 e 500

        //metti in ordine
        selection_sort(casuali);

        //vedi se funziona
        //is_sorted(casuali);
        if (!is_sorted(casuali)){
            cerr<<"il selection non ha fatto il suo lavoro \n";
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS; 
}
