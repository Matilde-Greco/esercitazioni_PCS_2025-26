#pragma once
#include <concepts>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <vector>
#include "unidirected_edge.hpp"

using namespace std;

template<typename T> 
class unidirected_graph {
    //lista di adiacenza
    map<T, set<T>> lista_adiacenza;

    //lista di archi
    vector<unidirected_edge<T>> vettor_archi;

    public:
        //costruttore di default
        unidirected_graph() {};

        //costruttore di copia
        unidirected_graph(const unidirected_graph& other)
        {
            lista_adiacenza=other.lista_adiacenza;
            vettor_archi=other.vettor_archi;
        }

    //implementazione dei metodi
    //cerca i vicini, quindi gli passo un nodo e vado a vedere nel mio dizionario che vicini ha:
    set<T> neighbours(const T& nodo) const {
        auto indice_nodo=lista_adiacenza.find(nodo);
        if (indice_nodo==lista_adiacenza.end()){
            return set<T>();
        }
        return lista_adiacenza.at(nodo); // anche lista_adiacenza.at(nodo)
    }

    //aggiungi un arco al grafo
    void add_edge(const unidirected_edge<T>& arco){
        for (size_t i=0; i<vettor_archi.size();i++){
            if (vettor_archi[i]==arco){
                return;
            }
        }
        vettor_archi.push_back(arco);

        //bisogna modificare lalista di adiacenza quando ci metto un nuovo arco:
        lista_adiacenza[arco.from()].insert(arco.to());
        lista_adiacenza[arco.to()].insert(arco.from());
    }

    //restituire tutti gli archi
    vector<unidirected_edge<T>> all_edges() const{
        return vettor_archi;
    }

    //prendimi tutti i nodi
    set<T> all_nodes() const{
        set<T> tutti_nodi;
        for (const auto& riga:lista_adiacenza){
            T nome_nodo=riga.first;
            tutti_nodi.insert(nome_nodo);//subito fatto pushback ma lo posso usare solo su vector
        }
        return tutti_nodi;
    }

    //dare numero a un arco
    int edge_number(const unidirected_edge<T>& arco) const {
        for (size_t i=0; i<vettor_archi.size();i++){
            if (vettor_archi[i]==arco){
                return i;
            }
        }
        return -1;//non lo ha trovato e quindi non c'è
    }

    //fa il contrario di prima
    unidirected_edge<T> edge_at(const size_t i){
        if (i<0 || i>=vettor_archi.size()){
            return unidirected_edge<T>(-1,-1); //valore sentinella
        }else{
            return vettor_archi[i];
        }   
    }

    //calcolo differenza tra due grafi
    vector<unidirected_edge<T>> operator-(const unidirected_graph& other) const {
        vector<unidirected_edge<T>> differenza;

        auto archi_other=other.all_edges();
        for (size_t i=0;i<vettor_archi.size();i++){
            auto iteratore=(find(archi_other.begin(),archi_other.end(),vettor_archi[i]));

            if (iteratore==archi_other.end()){
                differenza.push_back(vettor_archi[i]);
            }
        }
        return differenza;
        
    }

};