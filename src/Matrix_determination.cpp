#include<vector>
#include <utility>
#include<Matrix/Matrix_core.hpp>

double mat::det(const Matrix& m)
    {
        int row=m.getrow(),col=m.getcol();
        if(row!=col)
          throw std::invalid_argument("Not a square!");
        else
        {
            long double nonzero=-1,result=1;
            bool ifcolzero;
            int h,i,j,k;
            std::vector<long double>matrix(m.getmat());
            for(h=0;h<col;h++)//搜索非零元素
            {
                for(i=h;i<row;i++)
                {
                    ifcolzero=true;
                    if((matrix[i*col+h]!=0)&&(i!=nonzero))
                    {
                        for(int p=0;p<col;p++)
                            std::swap(matrix[h*col+p],matrix[i*col+p]);
                        ifcolzero=false;
                        break;
                    }
                }
                if(ifcolzero){return 0;}
                for(j=h+1;j<row;j++)
                {
                    for(k=col-1;k>=h;k--)
                    {
                        matrix[j*col+k]-=matrix[h*col+k]*matrix[j*col+h]/matrix[h*col+h];

                    }
                }
                result*=matrix[h*col+h];
            }
             return result;
        }
    }
