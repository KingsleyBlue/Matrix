#include<Matrix/Matrix_core.hpp>
using namespace mat;
int main()
{
    // Generate a 3x3 zero matrix
    Matrix A(3,3);
    std::cout<<A<<std::endl<<std::endl;

    //Generate a 3x3 identity matrix
    Matrix I(3);
    std::cout<<I<<std::endl<<std::endl;

    //input a custom matrix
    int m,n;
    std::cin>>m>>n;
    Matrix B(m,n);
    std::cin>>B;

    return 0;
}