#include<Matrix/Matrix_core.hpp>
#include<cmath>

std::istream &operator>>(std::istream &is, Matrix &m)
{
    for(int i=0;i<m.getrow();i++)
        {
            for(int j=0;j<m.getcol();j++)
            {
                std::cin>>m.matrix[i][j];
            }
        }
    return is;
}

std::ostream & operator<<(std::ostream &os, const Matrix &m)
{
    for(int i=0;i<m.getrow();i++)
        {
            for(int j=0;j<m.getcol();j++)
            {
                if(abs(m(i,j))<1e-5)
                    os<<0<<' ';
                else
                    os<<m(i,j)<<' ';
            }
            os<<std::endl;
        }
    return os;
}

Matrix operator+(const Matrix& A, const Matrix& B)
{
     if (A.getrow() == B.getrow() && A.getcol() == B.getcol())
     {
         Matrix C(A.getrow(), B.getcol());
         for (int i = 0; i < C.getrow(); i++)
         {
             for (int j = 0; j < C.getcol(); j++)
             {
                C(i,j)=A(i,j)+B(i,j);
             }
         }
         return C;
     }
     else
     {
       throw std::invalid_argument("+():size not match!");
     }
}

Matrix operator-(const Matrix& A,const Matrix& B)
    {
        if(A.getrow()==B.getrow()&&A.getcol()==B.getcol())
        {
            Matrix C(A.getrow(),B.getcol());
            for(int i=0;i<C.getrow();i++)
            {
                for(int j=0;j<C.getcol();j++)
                {
                    C(i,j)=A(i,j)-B(i,j);
                }
            }
            return C;

        }
        else
        {
           throw std::invalid_argument("-():size not match!");
        }
    }

Matrix operator*(const long double& a,const Matrix& B)//矩阵数乘
    {
        Matrix C(B.getrow(),B.getcol());
            for(int i=0;i<C.getrow();i++)
            {
                for(int j=0;j<C.getcol();j++)
                {
                    C(i,j)=a*B(i,j);
                }
            }
            return C;
    }

Matrix operator*(const Matrix& A,const long double& b)//矩阵数乘
    {
        Matrix C(A.getrow(),A.getcol());
            for(int i=0;i<C.getrow();i++)
            {
                for(int j=0;j<C.getcol();j++)
                {
                    C(i,j)=b*A(i,j);
                }
            }
            return C;
    }

Matrix operator/(const Matrix& A,const long double& b)//矩阵数除
    {
        if(b==0)
          throw std::invalid_argument("/():the divisor is 0!");
        else{
        Matrix C(A.getrow(),A.getcol());
            for(int i=0;i<C.getrow();i++)
            {
                for(int j=0;j<C.getcol();j++)
                {
                    C(i,j)=A(i,j)/b;
                }
            }
            return C;
        }
    }


Matrix operator*(const Matrix& A,const Matrix& B)//矩阵乘法
    {
        if(A.getcol()==B.getrow())
        {
            Matrix C(A.getrow(),B.getcol());
            for(int i=0;i<C.getrow();i++)
            {
                for(int j=0;j<C.getcol();j++)
                {
                    for(int k=0;k<A.getcol();k++)
                    {
                        C(i,j)=C(i,j)+A(i,k)*B(k,j);
                    }
                }
            }
            return C;
        }
        else
        {
           throw std::invalid_argument("*():size not match!");
        }
    }



bool operator==(const Matrix& A,const Matrix& B)//判断矩阵是否相等
{
    if(A.getrow()==B.getrow()&&A.getcol()==B.getcol())
    {
        for(int i=0;i<B.getrow();i++)
        {
            for(int j=0;j<B.getcol();j++)
            {
                switch(A(i,j)==B(i,j))
                {
                    case 0:
                        return false;
                    case 1:
                        continue;    
                }
            }
        }
        return true;
    }
    else
    return false;
}