#include"Matrix_core.hpp"

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
                t=(i<A.getrow())? A.getvalue(i,j):B.getvalue(i-A.getrow(),j);
                C.set(i,j,t);
            }
        }
        return C;
    }
}