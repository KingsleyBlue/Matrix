#include<Matrix/Matrix_core.hpp>

std::pair<Matrix, Matrix> mat::LUdecomp(const Matrix& A)
{
    if(abs(mat::det(A))>1e-5)
    {
        long double sum;
        int rows=A.getrow(),cols=A.getcol();
        Matrix L(rows,cols);
        Matrix U(rows);
        for(int j=0;j<cols;j++)
        {
            for(int i=0;i<rows;i++)
            {
                if(abs(A(i,i))<1e-5)
                {
                    throw std::string("pivot is near zero!");
                }
                
                L(i,0)=A(i,0);
                if(j>0)
                {
                    U(0,j)=A(0,j)/L(0,0);
                    if(j<=i)
                    {
                        sum=A(i,j);
                        for(int k=0;k<=j-1;k++)
                        {
                            sum-=L(i,k)*U(k,j);
                        }
                        L(i,j)=sum;
                    }
                    else if(i>0&&j>i)
                    {
                        sum=A(i,j);
                        for(int k=0;k<=i-1;k++)
                        {
                            sum-=L(i,k)*U(k,j);
                        }
                        U(i,j)=sum/L(i,i);
                    }
                
                }
            }
        }
        return std::make_pair(L,U);
    }
    else
    {
        throw std::string("near singular or not a square!");
    }

    
}