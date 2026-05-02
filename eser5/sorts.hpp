#include <concepts>
#include <iostream>
#include <algorithm>
#include <optional>
#include <vector>
#include<bits/stdc++.h>

#pragma once

using namespace std;

//implementazione algoritmi
template<typename T> 
//std::optional<T>
void bubble_sort(vector<T>& A)
{
    if (A.size() < 2) return; // Se il vettore è vuoto o ha 1 elemento, è già ordinato
    for (size_t i=0;i<A.size()-1;i++){// ho messo 0 anche se da pseudo codice era 1
        for (size_t j=A.size()-1; j>i; j--){
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
    if (A.size() < 2) return; // Se il vettore è vuoto o ha 1 elemento, è già ordinato

    for (size_t j=1;j<A.size();j++){
        T chiave=A[j];
        size_t i=j-1;
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
    if (A.size() < 2) return;

    for (size_t i=0;i<A.size()-1;i++){//prima partiva da 1
        size_t min=i;
        for (size_t j=i+1; j<A.size();j++){ //tolto un = messo in precedenza
            if (A[j]<A[min]){
                min=j;
            }
        }
        swap(A[i],A[min]);
    }
    return;
}

template<typename T>
// void merge(vector<T>& A, int p, int q, int r)
// {
//     double inf=1e10;

//     int n1=q-p+1;
//     int n2=r-q;

//     vector<T> L(n1+1);
//     vector<T> R(n2+1);

//     for (int i=0; i<n1;i++){
//         L[i]=A[p+i]; //L[i]=A[p+i-1]; quello che ho preso da pseudocodice ma 
//     }
//     for (int j=0; j<n2;j++){
//         R[j]=A[q+j+1];
//     }

//     L[n1+1]=inf;
//     R[n2+1]=inf;
//     int i=0; int j=0;

//     for (int k=p;k<=r;k++){
//         if (L[i]<=R[j]){
//             A[k]=L[i];
//             i=i+1;
//         }
//         else{
//             A[k]=R[j];
//             j=j+1;
//         }
//     }
//     return;
// } 
//ERA SBAGLIATA

// C++ program for the implementation of merge sort


// Merges two subarrays of vec.
// First subarray is vec[left..mid]
// Second subarray is vec[mid+1..right]
void merge(vector<T>& vec, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    vector<T> leftVec(n1), rightVec(n2);

    // Copy data to temporary vectors
    for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

    // Merge the temporary vectors back into vec[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftVec[], if any
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightVec[], if any
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

//ROBA IN PIù TROVATA SITO
// // The subarray to be sorted is in the index range [left..right]
// void mergeSort(vector<int>& vec, int left, int right) {
//     if (left < right) {
      
//         // Calculate the midpoint
//         int mid = left + (right - left) / 2;

//         // Sort first and second halves
//         mergeSort(vec, left, mid);
//         mergeSort(vec, mid + 1, right);

//         // Merge the sorted halves
//         merge(vec, left, mid, right);
//     }
// }


// int main() {
//     vector<int> vec = {12, 11, 13, 5, 6, 7};
//     int n = vec.size();

//     // Sorting vec using mergesort
//     mergeSort(vec, 0, n - 1);

//     for (auto i: vec)
//         cout << i << " ";
//     return 0;
// }


template<typename T>
void merge_sort(vector<T>& A, int p, int r)
{
    if (p<r){
        int q=(p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
    return;
}

template<typename T>
int partition(vector<T>& A, int p, int r)
{
    T x=A[r]; int i=p-1;
    for (int j=p; j<=r-1; j++){
        if (A[j]<=x){
            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

template<typename T>
void quick_sort(vector<T>& A, int p, int r)
{
    if(p<r){
        int q=partition(A,p,r);
        quick_sort(A,p,q-1);
        quick_sort(A,q+1,r);
    }
    return;
}

//ULTIMA PARTE SULL'HYBRID
template<typename T>
void insertion_sort_hybryd(vector<T>& A, int low, int n) 
  {

    for(int i=low+1;i<n+1;i++)
    {
      int val = A[i] ;
      int j = i ;
    while (j>low && A[j-1]>val)
      {
        A[j]= A[j-1] ;
      j-= 1;
    }
    A[j]= val ;
    } 
  }


template<typename T>
int partition_hybryd(vector<T>& A, int low, int high)
{
  int pivot = A[high] ;
  int i;
  int j;
  i = low;
  j = low;

  for ( i = low; i < high; i++)
     {
      if(A[i]<pivot)
      {
        int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
      j += 1;
      }
    }
  
    int temp = A[j];
    A[j] = A[high];
    A[high] = temp;

  return j; 
  }

//funzione is sorted per vedere se il vettore è ordinato
template<typename T>  
//std::optional<T>
bool is_sorted(vector<T>& A){
    if (A.size() < 2) return true;

    for (size_t i=0;i<A.size()-1;i++){
        if(A[i]>A[i+1]){
            return false;
        }
    }
    return true;  // se finisce tutto senza darmi mai false allora è ordinato
}

template<typename T> 
void hybrid_quick_sort(vector<T>& arr, int low, int high)
{
  while (low < high) 
    {

    // If the size of the array is less 
    // than threshold apply insertion sort 
    // and stop recursion 

    if (high-low + 1 < 10)
      {
        insertion_sort_hybryd(arr, low, high);
      break;
    }

    else 
      
        {
          int pivot = partition_hybryd(arr, low, high) ;

      // Optimised quicksort which works on 
      // the smaller arrays first 

      // If the left side of the pivot 
      // is less than right, sort left part 
      // and move to the right part of the array 

      if (pivot-low<high-pivot)
        {
          hybrid_quick_sort(arr, low, pivot - 1); 
        low = pivot + 1;
      }
      else
        {

        // If the right side of pivot is less 
        // than left, sort right side and 
        // move to the left side 
          
        hybrid_quick_sort(arr, pivot + 1, high);
        high = pivot-1;
        }

     }

   }
}

template<typename T>
double calcola_media(const vector<double>& tempi)
{
    double somma=0;
    for (int i=0; i<(int)tempi.size(); i++){
        somma=somma+tempi[i];
    }
    return somma/tempi.size();
}
