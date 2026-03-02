#include<Matrix/Matrix_core.hpp>
#include<cmath>
using Type=Vector::type;
Matrix mat::HT(const Matrix& A,const int& index,std::string method)
{
    if(method=="col")
    {
        int rows=A.getrow();
        int cols=A.getcol();
        long double modulus=0;
        Identity H(rows);
        Identity temp_H(rows-index);
        Vector x(rows-index);
        for(int i=index;i<rows;i++)
        {
            x[i-index]=A(i,index);
        }

        modulus=sqrt(mat::dot(x,x));
        if(x[0]>=0)
        {
            x[0]=x[0]+modulus;
        }
        else
        {
            x[0]=x[0]-modulus;
        }
        temp_H=temp_H-2*x*mat::trans(x)/mat::dot(x,x);

        if(index==0)
        return temp_H;
        else
        {
            for(int i=index;i<rows;i++)
            {
                for(int j=index;j<cols;j++)
                    H(i,j)=temp_H(i-index,j-index);
            }
        }
        return H;
    }
    else if(method=="row")
    {
        int rows=A.getrow();
        int cols=A.getcol();
        long double modulus=0;
        Identity H(cols);
        Identity temp_H(cols-index);
        Vector x(cols-index,Type::row);
        for(int i=index;i<cols;i++)
        {
            x[i-index]=A(index,i);
        }

        modulus=sqrt(mat::dot(x,x));
        if(x[0]>=0)
        {
            x[0]=x[0]+modulus;
        }
        else
        {
            x[0]=x[0]-modulus;
        }
        temp_H=temp_H-2*mat::trans(x)*(x)/mat::dot(x,x);

        if(index==0)
        return temp_H;
        else
        {
            for(int i=index;i<rows;i++)
            {
                for(int j=index;j<cols;j++)
                    H(i,j)=temp_H(i-index,j-index);
            }
        }
        return H;
    }
    else
    {
        throw std::invalid_argument("HT():incorrect parameter");
    }
    
}