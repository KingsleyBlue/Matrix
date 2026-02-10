#include<Matrix/Matrix_core.hpp>
Matrix mat::trans(const Matrix& A)
    {
        int rows=A.getcol(),cols=A.getrow();
        Matrix AT(rows,cols);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                AT.set(i,j,A.getvalue(j,i));
            }
        }
        return AT;
    }