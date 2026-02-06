#include"Matrix_core.hpp"
Matrix mat::col_aug(const Matrix& A,const Matrix& B)
{
    if(A.getrow()!=B.getrow())
    throw std::invalid_argument("size not match!");
    else
    {
        int t;
        int rows=A.getrow();
        int cols=A.getcol()+B.getcol();
        Matrix C(rows,cols);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                t=(j<A.getcol())? A.getvalue(i,j):B.getvalue(i,j-A.getcol());
                C.set(i,j,t);
            }
        }
        return C;
    }
}