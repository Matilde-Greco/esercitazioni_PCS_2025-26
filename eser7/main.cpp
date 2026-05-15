#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"
#include "grafi_visita.hpp"

using namespace std;

int main(){
    unidirected_graph<unsigned int> g;

    g.add_edge(unidirected_edge<unsigned int>(1,2));
    g.add_edge(unidirected_edge<unsigned int>(1,3));
    g.add_edge(unidirected_edge<unsigned int>(1,4));
    g.add_edge(unidirected_edge<unsigned int>(1,6));
    g.add_edge(unidirected_edge<unsigned int>(9,8));
    g.add_edge(unidirected_edge<unsigned int>(7,6));
    g.add_edge(unidirected_edge<unsigned int>(4,6));
    g.add_edge(unidirected_edge<unsigned int>(4,7));
    g.add_edge(unidirected_edge<unsigned int>(5,7));
    g.add_edge(unidirected_edge<unsigned int>(3,6));
    g.add_edge(unidirected_edge<unsigned int>(4,2));
    g.add_edge(unidirected_edge<unsigned int>(6,8));
    g.add_edge(unidirected_edge<unsigned int>(2,5));
    g.add_edge(unidirected_edge<unsigned int>(2,7));
    g.add_edge(unidirected_edge<unsigned int>(7,9));
    salva_dot(g, "originale.dot");

    //testo contenitore politica lifo
    lifo<int> l;
    l.put(10);
    int x=l.get();
    bool y=l.empty();
    cout<<"per la lifo prendi: "<<x<<", è vuota? "<<y<<'\n';

    //testo contenitore politica fifo
    fifo<int> f;
    f.put(10);
    int z=f.get();
    bool h=f.empty();
    cout<<"per la fifo prendi: "<<z<<", è vuota? "<<h<<'\n';

    //verifico graph visit per la lifo
    lifo<unsigned int> s;
    auto dfsG = graph_visit(g, 1u, s);
    salva_dot(dfsG, "albero_dfs.dot");

    //verifico graph visit per la fifo
    fifo<unsigned int> q;
    auto bfsG = graph_visit(g, 1u, q);
    salva_dot(bfsG, "albero_bfs.dot");

    //verifico graph visit per la lifo
    auto dfsG_rec = recursive_dfs(g, 1u);
    salva_dot(dfsG_rec, "albero_dfs_rec.dot");

    //verifico dijkstra
    auto dijstra=dijkstra_senza_pesi(g,1u,10);
    salva_dot(dijstra, "albero_dijkstra.dot");

    return 0;

    //convertire in jpg: dot -Tjpg nomefile.dot -o nomefile.jpg
}