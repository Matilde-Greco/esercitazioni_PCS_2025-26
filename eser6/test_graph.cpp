#include "unidirected_graph.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
    unidirected_graph<unsigned int> g; //grafo vuoto

    g.add_edge(unidirected_edge<unsigned int>(3,2));
    g.add_edge(unidirected_edge<unsigned int>(2,7));


    //stampa di tutti archi e tutti i nodi
    set<unsigned int> tutti_nodi=g.all_nodes();
    cout<<"Di seguito tutti i nodi del grafo: \n";
    for (auto& n:tutti_nodi){
        cout<<" "<< n<<'\n';
    }
    vector<unidirected_edge<unsigned int>> tutti_archi=g.all_edges();
    cout<<"Di seguito tutti gli archi del grafo: \n";
    for (auto& a:tutti_archi){
        cout<<" "<< a<<'\n';
    }

    set<unsigned int> vicini=g.neighbours(2);
    cout<<"Di seguito tutti i nodi vicini al nodo 2: \n";
    for (auto& v:vicini){
        cout<<" "<< v<<'\n';
    }

    int n_arco=g.edge_number(unidirected_edge<unsigned int>(3,2));
    unidirected_edge<unsigned int> arco_datonumero=g.edge_at(1);
    cout <<"Indice dell'arco (3,2): "<<n_arco<<'\n';
    cout <<"arco dato indice 1: "<<arco_datonumero<<'\n';


    //ultimo test su differenza tra grafi
    unidirected_graph<unsigned int> g2;
    g2.add_edge(unidirected_edge<unsigned int>(2,7));

    vector<unidirected_edge<unsigned int>> g3=g-g2;
    cout<<"Ecco gli archi presenti in g ma non in g2: \n";
    for (auto& a:g3){
        cout<<a<<'\n';
    }
    return 0;   
}