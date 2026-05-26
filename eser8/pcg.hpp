#pragma once
#include <iostream>
#include "Eigen/Eigen"
#include <optional>


std::optional<Eigen::VectorXd> pcg(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, Eigen::VectorXd& x0, const double& tol){
    if (A.rows()!=A.cols()){
        std::cout<<"errore: la matrice A non è quadrata! dimensioni: "<<A.rows()<<"x"<<A.cols()<<std::endl;
        return std::nullopt;
    }//check quadrata
    
    
    if (!A.isApprox(A.transpose(),1e-12)){
        std::cout<< "errore: la matrice A non è simmetrica!"<<std::endl;
        return std::nullopt;//optional vuoto
    } //check simmetrico

    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> solver(A);
    if (solver.eigenvalues().minCoeff()<=0){
        std::cout<<"la matrice non è definita positiva!"<<std::endl;
        return std::nullopt;
    } //check definita positiva

    Eigen::VectorXd r0=b-(A*x0);
    Eigen::VectorXd p0=r0;
    double res_norm_0=r0.norm();
    int k=0;
    while (k<A.rows()&&r0.norm()>tol*res_norm_0){
        const double alpha_k=((p0.transpose()*r0)/(p0.transpose()*A*p0)).value();
        
        x0=x0+(alpha_k*p0);
        r0=b-(A*x0);
        const double beta_k= ((p0.transpose()*A*r0)/(p0.transpose()*A*p0)).value();
        p0=r0-(beta_k*p0);
        k++;
        
    }
    return x0;
}