//ciò che devo fare: 100 vettori di dimensioni randomiche con elementi randomini  a cui applico il bubblesort e poi vedo se funziona con is_sorted
//include vari
#include "sorts.hpp"
#include <iostream>
#include <concepts>
#include <random>
#include "randfiller.h"
#include <cstdlib>

using namespace std;

//definizione vettori
//per definire numeri random in c++ devo definire un seme 
// che mi generi numeri diversi ogni volta che avvio il programma

//il motore per generare le sequenze di bit casuali e la distribuzione per trasformare i bit in numeri utili
int main(){
    //int dim[100];
    //1. seme
    //random_device rd;
    //2. generatore
    //mt19937 gen(rd());
    randfiller rf; //creo un oggetto randfiller
    vector<int> dim(100); //vettore con le 100 dimensioni casuali
    rf.fill(dim,100,8000);//riempi il vettore con numeri da 100 a 8000
    //for (int i =0; i<100; i++){
        
        //3. range
        //uniform_int_distribution<> dis(100, 8000);
        //4.mi genera i numeri
        //dim[i]=dis(gen);
        //quello che ho fatto fin qui è un vettore che ha 100 elementi e 
        //ognuno è la dimensione dell'i-esimo vettore
        
        //potrei fare un for dove uso randfiller per generare vettori di quella dimensione
        
        //ho scoperto randfiller.h+
        //idea: visto che randfiller.h prende un vettore lungho un tot e ci mette dentro elementi
        //dove posso definire tra cosa prendere elementi

        //potrei fare che definisco il vettore di una certa 
        // lunghezza in maniera casuale e poi faccio si che me 
        // lo riempia con randfiller
        //problema: come definisco vettore di dimensione casuale?
        
    //}

    //provo a fare il for di cui parlavo prima
    for (int i=0; i<100;i++){
        
        vector<int> casuali(dim[i]); //così mi creo un vettore fatto da tanti elementi quanti il numero in posizione i-esima di dim

        rf.fill(casuali,1,500);//riempilo con numeri tra 1 e 500

        //metti in ordine
        bubble_sort(casuali);

        //vedi se funziona
        if (!is_sorted(casuali)){
            cerr<<"il bubble non ha fatto il suo lavoro \n";
            return EXIT_FAILURE;
        }
        
        //is_sorted(casuali);
        //cout<<"sono in ordine? "<< is_sorted(casuali)<<'\n'; //1=true, 0=false
    }
    return EXIT_SUCCESS; //prima messo dopo if ma così finiva troppo presto (penso vedesse solo il primo vettore)
}

