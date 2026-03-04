#include<vector>
#include <utility>
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
            if(std::abs(A(i,h)) > 1e-10)
            {
                ifzero=false;
                for(int p=0;p<A.cols;p++)
                    std::swap(A(h,p),A(i,p));
                break;
            }
        }
        if(ifzero)
        continue;
        for(j=h+1;j<A.rows;j++)
        {
            for(k=A.cols-1;k>=h;k--)
            {
                A(j,k)-=A(h,k)*A(j,h)/A(h,h);
            }
        }
    }
    return A;
}