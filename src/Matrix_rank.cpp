#include"Matrix_core.hpp"
#include<algorithm>

int mat::rank(Matrix A)
{

    int rows=A.getrow();
    int cols=A.getcol();
    Matrix B(rows,cols);
    B=mat::GaussianElimination(A);
    int rank_max=std::min(rows,cols);
    int rank=rank_max;
    bool ifzero;
    for(int i=0;i<rank_max;i++)
    {
        ifzero=true;
        for(int j=0;j<cols;j++)
        {
            if(B.getvalue(i,j)!=0)
            {
                ifzero=false;
                break;
            }
        }
        if(ifzero)
        rank--;
    }
    return rank;
}
