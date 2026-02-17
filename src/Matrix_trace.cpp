#include<Matrix\Matrix_core.hpp>

long double mat::tr(const Matrix& A)
{
    if(A.getrow()!=A.getcol())
    {
        throw std::invalid_argument("tr(): Not a square!");
    }
    else
    {
        long double t=0;
        for(int i=0;i<A.getrow();i++)
        {
            t+=A(i,i);
        }
        return t;
    }
}