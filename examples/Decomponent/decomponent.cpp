#include<Matrix/Matrix_core.hpp>
using namespace mat;

int main()
{
    Matrix A(3,3);
    double value=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            A(i,j)=value++;
        }
    }
    A(2,2)=10;

    //LU Decompose
    auto lu=mat::LUdecomp(A);
    std::cout<<"L is:"<<std::endl<<std::get<0>(lu)<<std::endl;
    std::cout<<"U is:"<<std::endl<<std::get<1>(lu)<<std::endl;

    std::cout<<std::endl;

    //QR Decompose
    auto qr=mat::QRdecomp(A);
    std::cout<<"Q is:"<<std::endl<<std::get<0>(qr)<<std::endl;
    std::cout<<"R is:"<<std::endl<<std::get<1>(qr)<<std::endl;

    //SVD Decompose
    std::vector<Matrix>svd=mat::SVD(A);
    std::cout<<"U is"<<std::endl<<svd[0]<<std::endl;
    std::cout<<"Sigma is"<<std::endl<<svd[1]<<std::endl;
    std::cout<<"V is"<<std::endl<<svd[2]<<std::endl;
    std::cout<<"sum is"<<std::endl<<svd[0]*svd[1]*svd[2]<<std::endl;
    system("pause");
    return 0;
}