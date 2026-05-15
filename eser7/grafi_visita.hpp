#pragma once
#include <concepts>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <limits>
#include <fstream>
#include <string>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"

using namespace std;

//implementazione di fifo e lifo
template<typename T>
class lifo {
    stack<T> s;
    public:
        lifo() {};
        void put(const T& value){
            s.push(value);
        }
        T get(){
            T num=s.top();
            s.pop();
            return num;
        }

        bool empty() const{
            return s.empty();
        }
};

template<typename T>
class fifo {
    queue<T> q;
    public:
        fifo() {};
        void put(const T& value){
            q.push(value);
        }
        T get(){
            T num=q.front();
            q.pop();
            return num;
        }

        bool empty() const{
            return q.empty();
        }
};



//funzione generale graph_visit
template<typename Container>
unidirected_graph<unsigned int> graph_visit(const unidirected_graph<unsigned int>& g, int node, Container& C){
    unidirected_graph<unsigned int> albero;
    map<unsigned int,bool> reached;

    C.put(node); //metto primo nodo nel container
    reached[node]=true;// e lo segno come visitato

    
    while(!C.empty()){ //finchè c'è qualcosa nel contenitore continua a lavorare
        unsigned int u=C.get(); //estraggo il nodo dal contenitore e lo chiamo u
        
        for (auto& w:g.neighbours(u)){ //per ogni nodo estratto guardo tutti i suoi vicini
            if (!reached[w]){ //se non ci sono ancora stata in questo vicino
                reached[w]=true;//ora ci sono stata quindi lo metto a true
                albero.add_edge(unidirected_edge<unsigned int>(u,w));//aggiungi l'arco nell'albero che mi devi stampare
                C.put(w);//mettilo nel contenitore così che poi controllo i suoi vicini
            }
        }
    }
    return albero;
}


//DFS ricorsiva
template<typename T>
void dfs_rec_help(const unidirected_graph<T>& g, T node, map<T,bool>& reached, unidirected_graph<T>& albero){
    reached[node]=true;

    auto vicini=g.neighbours(node);
    // vector<T> copia_vicini(vicini.begin(),vicini.end());
    // reverse(copia_vicini.begin(),copia_vicini.end());
    
    vector<T> vicini_nuovi;
    for (T vicino:vicini){
        if (!reached[vicino]){
            reached[vicino]=true;
            albero.add_edge(unidirected_edge<unsigned int>(node,vicino));//se non è stato visitato metti l'arco che collego il node con il vicino all'interno dell'albero visite
            vicini_nuovi.push_back(vicino);
            
        }
    }
    for (int i=vicini_nuovi.size()-1;i>=0;i--){
        dfs_rec_help(g,vicini_nuovi[i],reached,albero);
    }
}

template<typename T>
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& g, T nodo_sorgente){
    unidirected_graph<T> albero;
    map<T,bool> reached;

    dfs_rec_help(g,nodo_sorgente,reached,albero);
    return albero;
}

//algoritmo di dijstra
template<typename T>
unidirected_graph<T> dijkstra_senza_pesi(unidirected_graph<T>& g, T nodo_sorgente, int m)//m è il numero totale di nodi, ricordarsi nel main di chimare all_nodes
{   unidirected_graph<T> albero;
    int infinito =numeric_limits<int>::max();

    vector<int> pred(m,-1); //array predecessore inizializzato tutto a -1
    vector<int> dist(m,infinito);//problema dell'infinito //array distanze inizializzate tutte a infinito

    pred[nodo_sorgente]=nodo_sorgente;//l'unico a non essere -1 è il primo che è predecessore di se stesso
    dist[nodo_sorgente]=0;//la prima distanza da se stesso è 0

    //priority queue
    priority_queue<pair<int,T>, vector<pair<int,T>>, greater<pair<int, T>>> prio_queue;//definisco una struttura di coppie distanza-nodo salvate in vettore, ordinato dal più piccolo al più grande
    prio_queue.push({0,nodo_sorgente});

    // for (int i=0;i<m;i++){
    //     prio_queue.push({dist[i], i});
    // }
    while (!prio_queue.empty()){
        T u=prio_queue.top().second;//prendi la prima coppia del vettore e di essa il secondo elemento che è il nodo con distanza minima
        int p=prio_queue.top().first;//prendi la distanza
        prio_queue.pop();//togli la coppia con distanza minima

        if (p>dist[u]) continue;

        for (T w: g.neighbours(u)){
            if (dist[w]> dist[u]+1){
                dist[w]=dist[u]+1;
                pred[w]=u;

                albero.add_edge(unidirected_edge<unsigned int>(u,w));
                prio_queue.push({dist[w],w});//aggiorna la priorità perchè ho trovato un buon percorso da percorrere
                //la coda si riordina automaticamente una volta aggiunta la coppia, distanza w e w
                //è per fare il decrease key che ha fatto il prof vicini
            }
        }
    }
    return albero;
}

//funziona per fare la stampa
template<typename T>
void salva_dot(unidirected_graph<T>& g, const string& nome_file){
    ofstream ofs(nome_file);
    if (!ofs.is_open()){
        cerr<<"impossibile aprire file!\n";
        return;
    }
    ofs<<"graph G {"<<endl;
    auto nodi=g.all_nodes();
    for (auto& u:nodi){
        for (auto& w:g.neighbours(u)){
            if (u<w){
                ofs<<" "<<u<<" -- "<<w<<";"<<endl;
            }
        }
    }
    ofs<<"}"<<endl;
    ofs.close();
}