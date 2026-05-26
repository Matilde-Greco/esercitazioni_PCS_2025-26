#include <iostream> 
#include "Eigen/Eigen"
#include "pcg.hpp"
#include <cstdlib>

using namespace std;
int main(int argc, char **argv){
    const double tol=1.0e-15;

    bool test1_ =false;
    bool test2_ =false;
    bool test3_ =false;


    cout<<"TEST 1\n";
    Eigen::MatrixXd A1(3,3);
    A1<<4.0, 1.0, 0.0,
        1.0, 5.0, 1.0,
        0.0, 1.0, 3.0;

    Eigen::VectorXd x_es1(3);
    x_es1<< 1.0, 1.0, 1.0;

    Eigen::VectorXd b1=A1*x_es1;
    Eigen::VectorXd x0_1=Eigen::VectorXd::Zero(3);
    auto ris1=pcg(A1, b1, x0_1, tol);

    if (ris1.has_value()){
        cout<<"soluzione calcolata: \n"<<ris1.value()<<'\n';
        cout<<"soluzione esatta: \n"<<x_es1<<'\n';
        test1_=true;
    }else{
        cout<<"calcolo fallito nei controlli iniziali\n";
        test1_=false;
    }

    cout<<"TEST 2\n";
    Eigen::MatrixXd A2(3,3);
    A2<<1.0, 2.0, 0.0,
        2.0, -5.0, 1.0,
        0.0, 1.0, 2.0;

    Eigen::VectorXd x_es2(3);
    x_es2<< 1.0, 1.0, 1.0;

    Eigen::VectorXd b2=A2*x_es2;
    Eigen::VectorXd x0_2=Eigen::VectorXd::Zero(3);
    auto ris2=pcg(A2, b2, x0_2, tol);

    if (ris2.has_value()){
        test2_=false;;
    }else{
        test2_=true;;
    }


    cout<<"TEST 3\n";
    Eigen::MatrixXd A3(3,3);
    A3<<4.0, 1.0, 10.0,
        1.0, 5.0, 1.0,
        0.0, 1.0, 3.0;

    Eigen::VectorXd x_es3(3);
    x_es3<< 1.0, 1.0, 1.0;

    Eigen::VectorXd b3=A3*x_es3;
    Eigen::VectorXd x0_3=Eigen::VectorXd::Zero(3);
    auto ris3=pcg(A3, b3, x0_3, tol);

    if (ris3.has_value()){
        test3_=false;
    }else{
        test3_=true;
    }

    if (test1_ && test2_ && test3_){
        return EXIT_SUCCESS;
    }else{
        return EXIT_FAILURE;
    }

}