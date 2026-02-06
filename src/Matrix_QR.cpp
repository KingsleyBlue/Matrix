#include"Matrix_core.hpp"
#include<algorithm>
#include<cmath>

std::pair<Matrix, Matrix> mat::QRdecomp(const Matrix& A)
{
    if(mat::rank(A)<std::min(A.getcol(),A.getrow()))
    throw std::invalid_argument("not full rank row or full rank column!");
    else
    {
        int rows=A.getrow();
        int cols=A.getcol();
        Matrix R=A;
        Matrix Q(rows);
        for(int i=0;i<std::min(rows,cols);i++)
        {
            Q=Q*mat::HT(R,i);
            R=mat::HT(R,i)*R;
            //std::cout<<Q<<std::endl<<R<<std::endl;
        }
        //std::cout<<Q<<std::endl<<R<<std::endl;
        return std::make_pair(Q,R);
        // long double modulus;
        // Matrix Q(rows,cols);
        // Q=mat::orthx(A);
        // if(rows>=cols)
        // {
        //     Matrix R(cols,cols);
        //     for(int j=0;j<cols;j++)
        //     {
        //         modulus=0;
        //         for(int i=0;i<rows;i++)
        //         {
        //             modulus+=Q.getvalue(i,j)*Q.getvalue(i,j);
        //         }
        //         for(int i=0;i<rows;i++)
        //         {
        //             Q.set(i,j,Q.getvalue(i,j)/std::sqrt(modulus));
        //         }
        //     }
        //     R=mat::trans(Q)*A;
        //     return std::make_pair(Q,R);
        // }
        // else
        // {
        //     modulus=0;
        //     Matrix L(rows,rows);
        //     for(int i=0;i<rows;i++)
        //     {
        //         for(int j=0;j<cols;j++)
        //         {
        //             modulus+=std::sqrt(A.getvalue(i,j));
        //         }
        //         for(int j=0;j<cols;j++)
        //         {
        //             Q.set(i,j,A.getvalue(i,j)/modulus);
        //         }
        //     }
        //     L=A*(mat::trans(Q));
        //     return std::make_pair(Q,L);
        // }
    }
}