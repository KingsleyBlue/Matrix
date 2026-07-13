#include<Matrix/Matrix_core.hpp>
#include<cmath>

Matrix sin(Matrix& A) noexcept
{
    for(int i=0;i<A.getrow();i++)
        for(int j=0;j<A.getcol();j++)
            A(i,j)=sin(A(i,j));
    return A;
}

Matrix cos(Matrix& A) noexcept
{
    for(int i=0;i<A.getrow();i++)
        for(int j=0;j<A.getcol();j++)
            A(i,j)=cos(A(i,j));
    return A;
}

Matrix tan(Matrix& A)
{
    const long double pi=acos(-1.0);
    for(int i=0;i<A.getrow();i++)
        for(int j=0;j<A.getcol();j++)
            if(fmod(A(i,j),(pi/2))<fabs(1e-5))
                throw std::out_of_range("tan():near inf");
            else
                A(i,j)=sin(A(i,j));
    return A;
}