#include<Matrix/Matrix_core.hpp>
using namespace mat;

int main()
{
    Matrix A(3,3);
    long double value=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            A.set(i,j,value++);
        }
    }
    A.set(2,2,10);

    //LU Decompose
    auto lu=mat::LUdecomp(A);
    std::cout<<"L is:"<<std::endl<<std::get<0>(lu)<<std::endl;
    std::cout<<"U is:"<<std::endl<<std::get<1>(lu)<<std::endl;

    std::cout<<std::endl;

    //QR Decompose
    auto qr=mat::QRdecomp(A);
    std::cout<<"Q is:"<<std::endl<<std::get<0>(qr)<<std::endl;
    std::cout<<"R is:"<<std::endl<<std::get<1>(qr)<<std::endl;

    system("pause");
    return 0;
}