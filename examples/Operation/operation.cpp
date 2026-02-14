#include<Matrix/Matrix_core.hpp>
using namespace mat;

int main()
{
    Matrix A(3,3);
    Matrix B(3);

    //add
    std::cout<<A+B<<std::endl<<std::endl;

    //sub
    std::cout<<A-B<<std::endl<<std::endl;

    //mult
    std::cout<<2*B<<std::endl<<std::endl;
    std::cout<<A*B<<std::endl<<std::endl;

    //div
    std::cout<<B/2<<std::endl<<std::endl;

    //trans
    std::cout<<mat::trans(B)<<std::endl<<std::endl;

    //det
    std::cout<<mat::det(B)<<std::endl<<std::endl;

    //reverse
    std::cout<<mat::reverse(B)<<std::endl<<std::endl;

    //set value
    A(0,1)=3;

    //get value
    std::cout<<A(0,1)<<std::endl;
    //get matrix
    std::vector<std::vector<long double>> t(A.getmat());

    system("pause");
    return 0;
}