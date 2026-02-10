#include<Matrix/Matrix_core.hpp>
using namespace mat;

int main()
{
    Matrix A(2,2);
    Matrix B(2,1);
    std::cin>>A>>B;
    system("cls");
    std::vector<Matrix> sol;
    sol=mat::solution(A,B);
    for(int i=0;i<sol.size();i++)
    {
        std::cout<<sol[i]<<std::endl;
    }
    system("pause");
    return 0;
}