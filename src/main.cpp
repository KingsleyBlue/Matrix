#include"Matrix_core.hpp"
#include<tuple>
#include<cstdio>
#include<stdlib.h>


int main()
{
   Matrix A(2,2);
   Matrix B(2,1);
    std::cin>>A>>B;
    system("cls");
     auto qr=mat::QRdecomp(A);
            Matrix Q=std::get<0>(qr);
            Matrix R=std::get<1>(qr);
    //std::cout<<Q<<std::endl<<R;
    std::vector<Matrix> sol;
    sol=mat::solution(A,B);
    for(int i=0;i<sol.size();i++)
    {
        std::cout<<sol[i]<<std::endl;
    }
    //std::cout<<mat::reverse(A);
    system("pause");
    return 0;
}


