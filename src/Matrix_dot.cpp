#include<Matrix/Matrix_core.hpp>

long double mat::dot(const Vector& A,const Vector& B)
{
    if(A.size()==B.size())
    {
        long double result=0;
        for(int i=0;i<A.size();i++)
        {
            result+=A[i]*B[i];
        }
        return result;
    }
    else
    throw std::invalid_argument("cannot dot!");
}
