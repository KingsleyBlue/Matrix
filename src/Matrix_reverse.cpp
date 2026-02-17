#include<Matrix/Matrix_core.hpp>

Matrix mat::reverse(const Matrix& A)
{
    int rows=A.getrow();
    int cols=A.getcol();
    if(rows!=cols)
    throw std::invalid_argument("not a square!");
    else
    {
        Identity I(rows);
        std::vector<Matrix>result;
        result=mat::solution(A,I);
        Matrix A_re(rows,cols);
        for(int j=0;j<cols;j++)
        {
            for(int i=0;i<rows;i++)
            {
                A_re(i,j)=result[j](i,0);
            }
        }
        return A_re;
    }
}