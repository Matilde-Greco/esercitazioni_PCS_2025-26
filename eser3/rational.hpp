#include <concepts>
#include <iostream>
#pragma once
#include <numeric>
using namespace std;
template<typename T> requires std::integral<T>
class rational{
    T num_; 
    T den_;

    // semplificazione
    void semplificazione(){
        if (den_==0) return; //se trovi inf o nan non andare avanti e lascia stare con la semplificazione

        //fai il MCD
        T comune= std::gcd(num_,den_);

        num_=num_/comune;
        den_=den_/comune;

        if (den_<0){
            num_=-num_;
            den_=-den_;
        }
    }

    public:
    //costruttore di default
        rational()
            :num_(T{0}), den_(T{1})
        {}
    //costruttore con parametri (il mio)
        rational(const T& pnum,const T& pden)
            :num_(pnum), den_(pden)
        {//mettere trattazione 0
            //int inf=10^10;
            //string NaN;
            if (den_==0 && num_!=0){
                // Assegniamo al numeratore il massimo valore possibile per il tipo T
                // num_ = std::numeric_limits<T>::max();
                //valore sentinella per inf
                num_=1;
                den_=0;
            } else if (den_==0 && num_==0){
                //valore sentinella per NaN
                num_=0;
                den_=0;
            }
            semplificazione();
        }
    
    // dammi i valori di num e den
    T num() const {return num_;}
    T den() const {return den_;}

    //ora devo fare l'impplementazione di somma prodotto etc
    //modifica i num e den che avevo già
    rational& operator+=(const rational& other){
        //trattazione inf e NaN
        if ((den_==0 && num_==1)|| (other.num_==1 && other.den_ == 0)){
            num_=1;
            den_=0; // caso infinito + infinito
        }
        else if ((den_==0 && num_==0)|| (other.den_ == 0 && other.num_ == 0)){
            num_=0;
            den_=0; //caso nan+ nan
        }
        else if ((den_==0 && num_==1) && (other.num_==1 && other.den_ == 0)){
            num_=0;
            den_=0;
            //caso inf-inf=NaN
        }
        else { //caso semplice o normale
            num_=(num_*other.den_)+(other.num_*den_);
            den_=(den_*other.den_);
        }
        // T n_=(num_*other.den_)+(other.num_*den_);
        // T d_=(den_*other.den_);
        // *this=rational(n_,d_);
        semplificazione();
        return *this;
    }

    //sempre somma ma senza modificare i miei num e den iniziali(con nuova variabile)
    rational operator+(const rational& other) const {
        rational ret= *this;
        ret += other;
        return ret;
    }

    //differenza
    rational& operator-=(const rational& other){
        //trattazione inf e NaN
        if ((den_==0 && num_==1)|| (other.num_==1 && other.den_ == 0)){
            num_=1;
            den_=0; //inf-inf=inf
        }
        else if ((den_==0 && num_==0)|| (other.den_ == 0 && other.num_ == 0)){
            num_=0;
            den_=0; //nan- nan=nan
        }
        else { //caso semplice o normale
            num_=(num_*other.den_)-(other.num_*den_);
            den_=(den_*other.den_);
        }
        semplificazione();
        return *this;
    }

    //sempre differenza ma senza modificare i miei num e den iniziali(con nuova variabile)
    rational operator-(const rational& other) const {
        rational ret= *this;
        ret -= other;
        return ret;
    }

    //moltiplicazione
    rational& operator*=(const rational& other){
        //trattazione inf e NaN
        if ((den_==0 && num_==1) || (other.num_==1 && other.den_ == 0)){
            num_=1;
            den_=0; //infinito per infinito=inf
        }
        else if ((den_==0 && num_==0) || (other.den_ == 0 && other.num_ == 0)){
            num_=0;
            den_=0; // caso nan*nan=nan
        }
        else if ((den_==0 && num_==1)&&(other.num_!=1 && other.num_!=0 && other.den_ != 0)){
            num_=1;
            den_=0;
            //caso inf*numero=inf
        }
        else { //caso semplice o normale
            num_=(num_*other.num_);
            den_=(den_*other.den_);
        }
        semplificazione();
        return *this;
    }

    //sempre moltiplicazione ma senza modificare i miei num e den iniziali(con nuova variabile)
    rational operator*(const rational& other) const {
        rational ret= *this;
        ret *= other;
        return ret;
    }

    //divisione
    rational& operator/=(const rational& other){
        //trattazione inf e NaN, un po' diversa
        if ((den_==0 && num_==1)&& (other.num_==1 && other.den_ == 0)){
            num_=0;
            den_=0;
            //sarebbe inf/inf che è forma indeterminata (NaN).
        }
        else if ((den_==0 && num_==0)&& (other.den_ == 0 && other.num_ == 0)){
            num_=0;
            den_=0;
            //caso 0/0 forma indeterminata(NaN)
        }
        else if ((den_==0 && num_==1)&&(other.num_!=1 && other.num_!=0 && other.den_ != 0)) {
            num_=1;
            den_=0;
            // caso inf/num=inf
        }
        else if ((num_!=1 && num_!=0 && den_ != 0)&&(other.den_==0 && other.num_==0)){
            num_=1;
            den_=0;
            //caso num/zero=inf
        }
        else { //caso semplice o normale
            num_=(num_*other.den_);
            den_=(den_*other.num_);
        }
        semplificazione();
        return *this;
    }

    //sempre divisione ma senza modificare i miei num e den iniziali(con nuova variabile)
    rational operator/(const rational& other) const {
        rational ret= *this;
        ret /= other;
        return ret;
    }
};

// definizione operatore <<
template<typename T>
std::ostream&
operator<<(std::ostream& os, const rational<T>& r)
{
    os << r.num() << "/" << r.den();
    return os;
}