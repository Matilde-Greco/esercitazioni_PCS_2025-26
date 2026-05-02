// penso che qui io debba scrivere questione tempi e grafici

//PER FARLO COMPILARE: g++ -std=c++20 measure_sorts.cpp timecounter.cpp -o tempi
//altrimenti non vede la funzione timecounter che sta nel cpp
// ./tempi <- per farlo partire

// COMPILAZIONE:
// g++ -O3 -std=c++20 measure_sorts.cpp -o measure_sorts //RELEASE
// g++ -g -std=c++20 measure_sorts.cpp -o measure_sorts //DEBUG

#include "sorts.hpp"
#include "randfiller.h"
#include "timecounter.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    timecounter timer;
    randfiller rf;
    int m=100;

    string nomefile="tempi.txt";
    ofstream ofs(nomefile);
    if (ofs.is_open()){
        ofs<< "dim, tempo bubble, tempo insertion, tempo selection, tempo quick, tempo merge, tempi hybrid\n";
    }

    vector<double> tempi_bubble;
    vector<double> tempi_sele;
    vector<double> tempi_inse;
    vector<double> tempi_sort;
    vector<double> tempi_quick;
    vector<double> tempi_merge;
    vector<double> tempi_hybrid;

    for (int i=0; i<=100; i=i+10){
        
        //voglio creare un vettore con le dimensioni e poi per ogni dimensione creare 10 vettori diversi
        //troppo sbatti, alla fine faccio che direttamente per ogni dimensione mi faccio i 10 vettori
        //cout <<"vado a testare vettore di dimensione "<<i<<'\n';
        
        //RIFACCIO LA PARTE CON TEMPI GIUSTA
        //prima cosa da fare è un vettore di vettori, che abbia 100 righe e n colonne(nel mio caso 10perchè vado da 0 a 100 a salti di 10)
        vector<vector<int>> vettori(100, vector<int>(i));
        for (int j=0; j<100; j++){
            rf.fill(vettori[j],-100000,100000); //quello che faccio è iterare sulle righe e per ogni riga che sarebbe un vettore di 10 elementi lo riempio con numeri da -10000 a 100000
        }

        //inizializzo le mie "matrici" per ognuno dei vari algoritmi
        vector<vector<int>> v_bubble = vettori;
        vector<vector<int>> v_sele =vettori;
        vector<vector<int>> v_inse = vettori;
        vector<vector<int>> v_sort = vettori;
        vector<vector<int>> v_quick = vettori;
        vector<vector<int>> v_merge = vettori;
        vector<vector<int>> v_hybrid = vettori;

        //ora posso testare con i vari algoritmi
        timer.tic();
        for (int j = 0; j < m; j++) {
            quick_sort(v_quick[j], 0, v_quick[j].size() - 1);
        }
        double tempo_totale_quick = timer.toc();
        double media_quick = tempo_totale_quick / 100;//a tal punto calcolo già tutto il tempo totale quindi non ho più bisogno della funzione calcola media


        timer.tic();
        for (int j = 0; j < m; j++) {
            bubble_sort(v_bubble[j]);
        }
        double tempo_totale_bubble = timer.toc();
        double media_bubble = tempo_totale_bubble / 100;

        timer.tic();
        for (int j = 0; j < m; j++) {
            selection_sort(v_sele[j]);
        }
        double tempo_totale_sele = timer.toc();
        double media_sele = tempo_totale_sele / 100;

        timer.tic();
        for (int j = 0; j < m; j++) {
            insertion_sort(v_inse[j]);
        }
        double tempo_totale_inse = timer.toc();
        double media_inse = tempo_totale_inse / 100;

        timer.tic();
        for (int j = 0; j < m; j++) {
            merge_sort(v_merge[j], 0, v_merge[j].size() - 1);
        }
        double tempo_totale_merge = timer.toc();
        double media_merge = tempo_totale_merge / 100;

        timer.tic();
        for (int j = 0; j < m; j++) {
            sort(v_sort[j].begin(),v_sort[j].end());
        }
        double tempo_totale_sort = timer.toc();
        double media_sort = tempo_totale_sort / 100;


        //TESTO HYBRYD
        timer.tic();
        for (int j = 0; j < m; j++) {
            hybrid_quick_sort(v_hybrid[j], 0, v_hybrid[j].size() - 1);
        }
        double tempo_totale_hybrid = timer.toc();
        double media_hybrid = tempo_totale_hybrid / 100;
        
        //TROVARE DIMENSIONE
        //pensavo di fare un if che mi veda quando l'insertion smette di essere
        //più veloce del quicksort
        // if (media_quick<media_inse){
        //     cout<<"la dimensione è "<< i <<'\n';
        // }
        //AVEVO FATTO UNA PROVA MA ESSENDO TEMPI TROPPO VICINI ALLO ZERO NON VA PER VIA DI PROBLEMI DI ARCHITETTURA


        //VETTORI CON I VARITEMPI PER LE VARIE DIMENSIONI
        tempi_bubble.push_back(media_bubble);
        tempi_sele.push_back(media_sele);
        tempi_inse.push_back(media_inse);
        tempi_quick.push_back(media_quick);
        tempi_merge.push_back(media_merge);
        tempi_sort.push_back(media_sort);
        tempi_hybrid.push_back(media_hybrid);


        //STAMPARLI DECENTEMENTE PER TROVARE N
        // cout<<"stampa risultati tempi\n";
        // cout<< "stampo risultati bubblesort "<< tempi_bubble<<'\n';
        // cout<< "stampo risultati selectionsort "<< tempi_sele<<'\n';
        // cout<< "stampo risultati insertionsort "<< tempi_inse<<'\n';
        // cout<< "stampo risultati quicksort "<< tempi_quick<<'\n';
        // cout<< "stampo risultati mergesort "<< tempi_merge<<'\n';
        // cout<< "stampo risultati sort "<< tempi_sort<<'\n';
        //NON ANDAVA BENE PERCHè L'OPERATORE << NON PRENDE UN VETTORE



        //ALTRA IDEA ANCORA:
        //STAMPO PASSO PASSO NEL FOR:
        cout<<"--------------------------------------------------\n";
        cout<<"stampa risultati tempi per dimensione "<< i <<"\n";
        cout<< "stampo risultati bubblesort "<< media_bubble<<'\n';
        cout<< "stampo risultati selectionsort "<< media_sele<<'\n';
        cout<< "stampo risultati insertionsort "<< media_inse<<'\n';
        cout<< "stampo risultati quicksort "<< media_quick<<'\n';
        cout<< "stampo risultati mergesort "<< media_merge<<'\n';
        cout<< "stampo risultati sort "<< media_sort<<'\n';
        cout<< "stampo risultati hybryd "<< media_hybrid<<'\n';

    
        
        double quadratico=min({media_bubble,media_inse,media_sele});
        double log=min({media_merge,media_quick});
        if (log<quadratico){
            cout<<"n0= "<<i<<'\n';
        } else{
            cout<<"i quadratici sono più veloci dei log\n";
        }

        //SCRIVI SU FILE
        if (ofs.is_open()){
                ofs<<i<<". "<< media_bubble<<", "<<media_inse<<", "<<media_sele<<", "<<media_quick<<", "<<media_merge<<media_hybrid<<'\n';
            }
        }
    
    
    return 0;
}
//COMMENTO OUTPUT
        //dall'output si vede che a dimensione 50 il quick ha superato
        //l'insertion (3.38e-06 vs 3.47e-06), ma poi l'Insertion è tornato in vantaggio a 60, 70, 80 e 90.
        //A dimensione 100, il Quick ha vinto di nuovo e con un distacco più netto (7.82e-06 vs 1.60e-05)

        //il fatto che tutti sti valori oscillano significa che tra 50 e 90, i due algoritmi 
        //sono il competizione diretta: hanno performance simili e basta un piccolo ritardo della
        //macchina così che uno super l'altro;
        //la soglia è quindi intorno a 90-100


        //COSE ANCORA DA FARE:-insertion sort limitato, serve per il quicksort ibrido,
        //-quicksort ibrido, dove uso la soglia trovata,-relazione finale


        //MESSO IN STAND-BY PERCHE' DOVEVO METTERE A POSTO LA QUESTIONE DELLA GESTIONE DEI TEMPI CHE AVEVO FATTO MALE
        // //inizializzo vettori per tenere conto dei tempi dei vari algoritmi
        // vector<double> tempi_bubble(10);
        // vector<double> tempi_sele(10);
        // vector<double> tempi_inse(10);
        // vector<double> tempi_sort(10);
        // vector<double> tempi_quick(10);
        // vector<double> tempi_merge(10);

        // for (int j=0;j<100;j++){
        //     vector<int> casuali(i); //così faccio 10 vettori di dimensione i
            
        //     //riempio con numeri casuali
        //     rf.fill(casuali,-100000,100000);

        //     //copie per testare i vari vettori
        //     vector<int> v_bubble = casuali;
        //     vector<int> v_sele = casuali;
        //     vector<int> v_inse = casuali;
        //     vector<int> v_sort = casuali;
        //     vector<int> v_quick = casuali;
        //     vector<int> v_merge = casuali;

        //     //vado a testare tutti gli algoritmi
        //     //tempo bubblesort
        //     timer.tic();
        //     bubble_sort(v_bubble);
        //     double fine_bubble=timer.toc();
        //     tempi_bubble[j]=fine_bubble;

        //     //tempo selectionsort
        //     timer.tic();
        //     selection_sort(v_sele);
        //     double fine_sele=timer.toc();
        //     tempi_sele[j]=fine_sele;

        //     //tempo insertionsort
        //     timer.tic();
        //     insertion_sort(v_inse);
        //     double fine_inse=timer.toc();
        //     tempi_inse[j]=fine_inse;

        //     //tempo sort
        //     timer.tic();
        //     sort(v_sort.begin(),v_sort.end()); //sort è speciale, funzione vecchia scuola, vuole che gli dica come iniziare e come finire
        //     double fine_sort=timer.toc();
        //     tempi_sort[j]=fine_sort;

        //     //tempo quick
        //     timer.tic();
        //     quick_sort(v_quick,0,v_quick.size()-1); 
        //     double fine_quick=timer.toc();
        //     tempi_quick[j]=fine_quick;

        //     //tempo merge
        //     timer.tic();
        //     merge_sort(v_merge,0,v_merge.size()-1); 
        //     double fine_merge=timer.toc();
        //     tempi_merge[j]=fine_merge;

        //     //ora vorrei salvare per ognuno dei 10 vettori e per ognuno degli algoritmi i tempi per poi fare la media
        //     //fatto, ora dovrei avere vettori di tempi di dimensione 10
        //     //adesso vorrei fare la media di ognuno di questi vettori per poi staparmela magari

        //     //diciamo che ora io ho per ogni dimensione 6 vettori da 10 con i tempi uscita da questo for 
            
        // }
        // double media_bubble=calcola_media(tempi_bubble);
        // double media_sele=calcola_media(tempi_sele);
        // double media_inse=calcola_media(tempi_inse);
        // double media_sort=calcola_media(tempi_sort);
        // double media_quick=calcola_media(tempi_quick);
        // double media_merge=calcola_media(tempi_merge);

//         vector<int> numeri(i);
//         rf.fill(numeri,1,100000);

//         vector<int> v_bubble = numeri;
//         vector<int> v_sele = numeri;
//         vector<int> v_inse = numeri;
//         vector<int> v_sort = numeri;

//         //tempo bubblesort
//         timer.tic();
//         bubble_sort(v_bubble);
//         double fine_bubble=timer.toc();

//         //tempo selectionsort
//         timer.tic();
//         selection_sort(v_sele);
//         double fine_sele=timer.toc();

//         //tempo insertionsort
//         timer.tic();
//         insertion_sort(v_inse);
//         double fine_inse=timer.toc();

//         //tempo sort
//         timer.tic();
//         sort(v_sort.begin(),v_sort.end()); //sort è speciale, funzione vecchia scuola, vuole che gli dica come iniziare e come finire
//         double fine_sort=timer.toc();


//         //STAMPO I RISULTATI OTTENUTI
//         cout<<"Per vettore di "<< i << " elementi \n";
//         cout<< "il bubblesort ci ha impiegato " <<fine_bubble<< '\n';
//         cout<< "il selectionsort ci ha impiegato " <<fine_sele<< '\n';
//         cout<< "l'insertionsort ci ha impiegato " <<fine_inse<< '\n';
//         cout<< "il sort ci ha impiegato " <<fine_sort<< '\n';
//         cout <<'\n';



