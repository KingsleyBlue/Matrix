#include<Matrix/Matrix_core.hpp>
#include<cmath>
Matrix mat::HT(const Matrix& A,const int& index)
{
    int rows=A.getrow();
    int cols=A.getcol();
    long double modulus=0;
    Matrix H(rows);
    Matrix temp_H(rows-index);
    Matrix x(rows-index,1);
    for(int i=index;i<rows;i++)
    {
        x.set(i-index,0,A.getvalue(i,index));
    }

    
        //x=A.getcol(j);
    for(int i=0;i<rows-index;i++)
    {
        modulus+=x.getvalue(i,0)*x.getvalue(i,0);
    }
    modulus=sqrt(modulus);
    if((x.getvalue(0,0)/modulus)>0.5)
    {
        x.set(0,0,x.getvalue(0,0)+modulus);
        temp_H=temp_H-2*x*mat::trans(x)/mat::dot(x,x);
    }
        //Q.set(j,j,-modulus);
    else
    {
        x.set(0,0,x.getvalue(0,0)-modulus);
        temp_H=temp_H-2*x*mat::trans(x)/mat::dot(x,x);
    }
        //Q.set(j,j,modulus);
    if(index==0)
    return temp_H;
    else
    {
        for(int i=index;i<rows;i++)
        {
            for(int j=index;j<cols;j++)
            H.set(i,j,temp_H.getvalue(i-index,j-index));
        }
    }
    return H;
}