#include<Matrix/Matrix_core.hpp>

Matrix mat::orthx(Matrix A)
{
    int rows=A.getrow();
    int cols=A.getcol();
    if(rows>=cols)
    {
        std::vector<Vector>orth;
        orth.reserve(cols);
        for(int j=0;j<cols;j++)
        {
            orth.push_back(Vector(rows));
            orth[j]=A.getcol(j);
        }
        for(int j=1;j<cols;j++)
        {
            for(int i=j;i<cols;i++)
            {
                //orth[j]=orth[j]-((mat::trans(orth[i])*orth[j])/(mat::trans(orth[i])*orth[i]))*orth[i];
                orth[i]=orth[i]-mat::dot(orth[i],orth[j-1])*orth[j-1];
            }
            
        }
        
        for(int j=0;j<cols;j++)
        {
            for(int i=0;i<rows;i++)
            {
                A.set(i,j,orth[j].getvalue(i,0));
            }
        }
        return A;
    }
    else
    {
        std::vector<Matrix>orth;
        orth.reserve(rows);
        for(int i=0;i<rows;i++)
        {
            orth.push_back(Matrix(1,cols));
            orth[i]=A.getrow(i);
        }
        for(int i=1;i<rows;i++)
        {
            for(int j=0;j<i;j++)
            {
                orth[i]=orth[i]-((orth[j]*mat::trans(orth[i]))/(orth[j]*mat::trans(orth[j])))*orth[j];
            }
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                A.set(i,j,orth[i].getvalue(0,j));
            }
        }
        return A;
    }
}