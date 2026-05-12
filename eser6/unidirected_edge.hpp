#pragma once
#include <concepts>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


template<typename T> 
class unidirected_edge {
    T nodo1_;
    T nodo2_;

    public:
    //costruttore user-defined
        unidirected_edge(const T& pnodo1, const T& pnodo2)
        {
            nodo1_=min(pnodo1,pnodo2); 
            nodo2_=max(pnodo1,pnodo2);
        }
        T nodo1() const {return nodo1_;}
        T nodo2() const {return nodo2_;}

    //implemenazione dei metodi, prima from e to
    T from() const{
        return nodo1_;
    }
    T to() const{
        return nodo2_;
    }

    bool operator<(const unidirected_edge& other) const{
        if (nodo1_<other.nodo1_){
            return true;
        } else if(nodo1_>other.nodo1_){
            return false;
        }
        else {
            // if (nodo2_<other.nodo2_){
            //     return true;
            // }
            
            return (nodo2_>other.nodo2_);
        }
    }

    bool operator==(const unidirected_edge& other) const {
        if ((nodo1_==other.nodo1_)&&(nodo2_==other.nodo2_)){
            return true;
        }else{
            return false;
        }
    }

};

// definizione operatore <<
template<typename T>
ostream& operator<<(std::ostream& os, const unidirected_edge<T>& a)
{
    os << "("<<a.nodo1() << ", " << a.nodo2()<<")";
    return os;
}