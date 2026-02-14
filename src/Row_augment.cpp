#include<Matrix/Matrix_core.hpp>

Matrix mat::row_aug(const Matrix& A,const Matrix& B)
{
    if(A.getcol()!=B.getcol())
    throw std::invalid_argument("size not match!");
    else
    {
        int t;
        int rows=A.getrow()+B.getrow();
        int cols=A.getcol();
        Matrix C(rows,cols);
        for(int j=0;j<cols;j++)
        {
            for(int i=0;i<rows;i++)
            {
                t=(i<A.getrow())? A(i,j):B(i-A.getrow(),j);
                C(i,j)=t;
            }
        }
        return C;
    }
}