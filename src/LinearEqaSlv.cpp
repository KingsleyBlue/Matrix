#include<Matrix/Matrix_core.hpp>
#include<tuple>
std::vector<Matrix> mat::solution(const Matrix& A,const Matrix& B)
{
    int rows=B.getrow();
    int cols=B.getcol();

    try
    {
        std::vector<long double>temp_y(rows);
        std::vector<Matrix>result;
        result.reserve(cols);
        auto lu=mat::LUdecomp(A);
        Matrix L=std::get<0>(lu);
        Matrix U=std::get<1>(lu);
        double sum;
        for(int g=0;g<cols;g++)
        {
            result.push_back(Matrix(rows,1));
            for(int i=0;i<L.getrow();i++)
            {
                
                    temp_y[0]=B.getcol(g).getvalue(0,0)/L.getvalue(0,0);
                    if(i>0)
                    {
                        sum=B.getcol(g).getvalue(i,0);
                        for(int j=0;j<i;j++)
                        {
                            sum-=L.getvalue(i,j)*temp_y[j];
                        }
                        temp_y[i]=sum/L.getvalue(i,i);
                    }
                
            }
            for(int i=U.getrow()-1;i>=0;i--)
            {
                result[g].set(U.getrow()-1,0,temp_y[rows-1]);
                if(i<U.getrow()-1)
                {
                    result[g].set(i,0,temp_y[i]);
                    for(int j=U.getcol()-1;j>i;j--)
                    {
                        result[g].set(i,0,result[g].getvalue(i,0)-U.getvalue(i,j)*result[g].getvalue(j,0));
                    }
                }
            }
        }
       return result;
           
    }
    catch(const std::string& e)
    {
        if(e=="near singular or not a square!")
        throw std::invalid_argument(e);
        else
        {
            auto qr=mat::QRdecomp(A);
            Matrix Q=std::get<0>(qr);
            Matrix R=std::get<1>(qr);
            std::vector<Matrix>result;
            result.reserve(cols);
            Matrix Y=mat::trans(Q)*B;
            for(int g=0;g<cols;g++)
            {
                result.push_back(Matrix(rows,1));
                for(int i=R.getrow()-1;i>=0;i--)
                {
                    result[g].set(R.getrow()-1,0,Y.getvalue(rows-1,g)/R.getvalue(rows-1,rows-1));
                    if(i<R.getrow()-1)
                    {
                        result[g].set(i,0,Y.getvalue(i,g));
                        for(int j=R.getcol()-1;j>i;j--)
                        {
                            result[g].set(i,0,result[g].getvalue(i,0)-R.getvalue(i,j)*result[g].getvalue(j,0));
                        }
                        result[g].set(i,0,(result[g].getvalue(i,0))/R.getvalue(i,i));
                    }
                }
            }
            return result;
        }


    }
    
}