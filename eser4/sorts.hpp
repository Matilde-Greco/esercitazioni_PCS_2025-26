#include <concepts>
#include <iostream>
#include <algorithm>
#include <optional>
#include <vector>
#pragma once

using namespace std;

//implementazione algoritmi
template<typename T> 
//std::optional<T>
void bubble_sort(vector<T>& A)
{
    for (int i=0;i<=A.size()-1;i++){// ho messo 0 anche se da pseudo codice era 1
        for (int j=A.size()-1; j>i; j--){
            if (A[j]<A[j-1]){
                swap(A[j],A[j-1]);
            }
        }
    }
    return;
}

template<typename T> 
//std::optional<T>
void insertion_sort(vector<T>& A)
{
    for (int j=1;j<=A.size();j++){
        T chiave=A[j];
        int i=j-1;
        while (i>=0 && A[i]>chiave){ //aggiunto un = rispetto allo pseudocodice
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=chiave;
    }
    return;
}

template<typename T> 
//std::optional<T>
void selection_sort(vector<T>& A)
{
    for (int i=0;i<=A.size()-1;i++){//prima partiva da 1
        int min=i;
        for (int j=i+1; j<A.size();j++){ //tolto un = messo in precedenza
            if (A[j]<A[min]){
                min=j;
            }
        }
        swap(A[i],A[min]);
    }
    return;
}

//funzione is sorted per vedere se il vettore è ordinato
template<typename T>  
//std::optional<T>
bool is_sorted(vector<T>& A){
    if (A.size() < 2) return true;

    for (int i=0;i<A.size()-1;i++){
        if(A[i]>A[i+1]){
            return false;
        }
    }
    return true;  // se finisce tutto senza darmi mai false allora è ordinato
}



