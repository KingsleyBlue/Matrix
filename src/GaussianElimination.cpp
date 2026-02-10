#include<vector>
#include<algorithm>
#include<Matrix/Matrix_core.hpp>
Matrix mat::GaussianElimination(Matrix A)
{
    bool ifzero;
    int h,i,j,k;
    int m=std::min(A.cols,A.rows);
    for(h=0;h<m;h++)//搜索非零元素
    {
        for(i=h;i<A.rows;i++)
        {
            ifzero=true;
            if(A.matrix[i][h]!=0)
            {
                ifzero=false;
                swap(A.matrix[h],A.matrix[i]);
                break;
            }
        }
        if(ifzero)
        continue;
        for(j=h+1;j<A.rows;j++)
        {
            for(k=A.cols-1;k>=h;k--)
            {
                A.matrix[j][k]-=A.matrix[h][k]*A.matrix[j][h]/A.matrix[h][h];
            }
        }
    }
    return A;
}