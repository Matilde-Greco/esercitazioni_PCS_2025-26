// penso che qui io debba scrivere questione tempi e grafici

//PER FARLO COMPILARE: g++ -std=c++20 measure_sorts.cpp timecounter.cpp -o tempi
//altrimenti non vede la funzione timecounter che sta nel cpp
// ./tempi <- per farlo partire


#include "sorts.hpp"
#include "randfiller.h"
#include "timecounter.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    timecounter timer;
    randfiller rf;

    for (int i=4; i<=8192; i*=2){
        vector<int> numeri(i);
        rf.fill(numeri,1,100000 );

        vector<int> v_bubble = numeri;
        vector<int> v_sele = numeri;
        vector<int> v_inse = numeri;
        vector<int> v_sort = numeri;

        //tempo bubblesort
        timer.tic();
        bubble_sort(v_bubble);
        double fine_bubble=timer.toc();

        //tempo selectionsort
        timer.tic();
        selection_sort(v_sele);
        double fine_sele=timer.toc();

        //tempo insertionsort
        timer.tic();
        insertion_sort(v_inse);
        double fine_inse=timer.toc();

        //tempo sort
        timer.tic();
        sort(v_sort.begin(),v_sort.end()); //sort è speciale, funzione vecchia scuola, vuole che gli dica come iniziare e come finire
        double fine_sort=timer.toc();


        //STAMPO I RISULTATI OTTENUTI
        cout<<"Per vettore di "<< i << " elementi \n";
        cout<< "il bubblesort ci ha impiegato " <<fine_bubble<< '\n';
        cout<< "il selectionsort ci ha impiegato " <<fine_sele<< '\n';
        cout<< "l'insertionsort ci ha impiegato " <<fine_inse<< '\n';
        cout<< "il sort ci ha impiegato " <<fine_sort<< '\n';
        cout <<'\n';
    }
}

//mancano i grafici ma non so ancora dove mettere mano anche perchè non ho capito cosa vuole che facciamo
//voglio fare un grafico di come variano questi 3 algoritmi al variare della dimensione e del tempo
//quanto ci mettono per varie dimensioni ordinate (4,8,16, etc)

//esempio di risultato:
// Per vettore di 4 elementi
// il bubblesort ci ha impiegato 1e-06
// il selectionsort ci ha impiegato 6e-07
// l'insertionsort ci ha impiegato 4e-07
// il sort ci ha impiegato 1.5e-06

// Per vettore di 8 elementi
// il bubblesort ci ha impiegato 1.9e-06
// il selectionsort ci ha impiegato 1.5e-06
// l'insertionsort ci ha impiegato 9e-07
// il sort ci ha impiegato 2.3e-06

// Per vettore di 16 elementi
// il bubblesort ci ha impiegato 6.501e-06
// il selectionsort ci ha impiegato 4.9e-06
// l'insertionsort ci ha impiegato 2e-06
// il sort ci ha impiegato 4.101e-06

// Per vettore di 32 elementi
// il bubblesort ci ha impiegato 2.1302e-05
// il selectionsort ci ha impiegato 1.6101e-05
// l'insertionsort ci ha impiegato 9.901e-06
// il sort ci ha impiegato 1.1901e-05

// Per vettore di 64 elementi
// il bubblesort ci ha impiegato 0.000107411
// il selectionsort ci ha impiegato 4.5605e-05
// l'insertionsort ci ha impiegato 1.8502e-05
// il sort ci ha impiegato 2.2002e-05

// Per vettore di 128 elementi
// il bubblesort ci ha impiegato 0.000504252
// il selectionsort ci ha impiegato 0.000230224
// l'insertionsort ci ha impiegato 0.000150716
// il sort ci ha impiegato 4.5504e-05

// Per vettore di 256 elementi
// il bubblesort ci ha impiegato 0.00142395
// il selectionsort ci ha impiegato 0.00078068
// l'insertionsort ci ha impiegato 0.000295131
// il sort ci ha impiegato 0.000119012

// Per vettore di 512 elementi
// il bubblesort ci ha impiegato 0.0057632
// il selectionsort ci ha impiegato 0.00171848
// l'insertionsort ci ha impiegato 0.000786481
// il sort ci ha impiegato 0.000152516

// Per vettore di 1024 elementi
// il bubblesort ci ha impiegato 0.0106294
// il selectionsort ci ha impiegato 0.00336445
// l'insertionsort ci ha impiegato 0.00168197
// il sort ci ha impiegato 0.000213722

// Per vettore di 2048 elementi
// il bubblesort ci ha impiegato 0.031825
// il selectionsort ci ha impiegato 0.0138048
// l'insertionsort ci ha impiegato 0.00660608
// il sort ci ha impiegato 0.000468948

// Per vettore di 4096 elementi
// il bubblesort ci ha impiegato 0.124249
// il selectionsort ci ha impiegato 0.0536594
// l'insertionsort ci ha impiegato 0.0265696
// il sort ci ha impiegato 0.00102161

// Per vettore di 8192 elementi
// il bubblesort ci ha impiegato 0.481558
// il selectionsort ci ha impiegato 0.210325
// l'insertionsort ci ha impiegato 0.108256
// il sort ci ha impiegato 0.00216312
