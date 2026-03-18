#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int main(){
    static const int N=10;
    double arr[N]={11.1, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};

    //MINIMO
    double minimo=arr[0];
    for (int i=1; i<N; i++){
        if (minimo>=arr[i]){
            minimo=arr[i];
        }
        else{
            minimo=minimo;
        }
    }
    cout<<"il minimo è "<< minimo<< "\n";

    //MASSIMO
    double massimo=arr[0];
    for (int i=1; i<N; i++){
        if (massimo<=arr[i]){
            massimo=arr[i];
        }
        else{
            massimo=massimo;
        }
    }
    cout<<"il massimo è "<< massimo<< "\n";


    //MEDIA
    double somma=0.0;
    for (int i=0; i<N; i++){
        somma =somma + arr[i];
    }
    double media=somma/N;
    cout<<"la media è "<< media << "\n";

    //DEVIAZIONE STANDARD
    //nuovo array con gli scarti al quadrato
    double arr2[N];
    for (int i=0; i<N; i++){
        arr2[i]=(arr[i]-media)*(arr[i]-media);
    }

    //media array scarti al quadrato
    double somma2=0.0;
    for (int i=0; i<N; i++){
        somma2 =somma2 + arr2[i];
    }
    double media2=somma2/N;
    cout<<"la media è "<< media2 << "\n";

    //deviazione standard
    double dev=sqrt(media2);
    cout<<"la deviazione standard è "<< dev << "\n";

    return 0;

}