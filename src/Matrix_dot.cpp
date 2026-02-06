#include"Matrix_core.hpp"

long double mat::dot(const Matrix& A,const Matrix& B)
{
    if(A.getcol()==1&&B.getcol()==1&&A.getrow()==B.getrow())
    {
        long double result=0;
        for(int i=0;i<A.getrow();i++)
        {
            result+=A.getvalue(i,0)*B.getvalue(i,0);
        }
        return result;
    }
    else
    throw std::invalid_argument("cannot dot!");
}
