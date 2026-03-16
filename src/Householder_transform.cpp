#include<Matrix/Matrix_core.hpp>
#include<cmath>
#include <float.h>
using Type=Vector::type;
Matrix mat::HT(const Matrix& A,const int& row,const int& col,std::string method)
{
    if(method=="col")
    {
        int rows=A.getrow();
        int cols=A.getcol();
        long double modulus=0;
        Identity H(rows);
        if(row>=rows)
        {
            return H;
        }
        Identity temp_H(rows-row);
        Vector x(rows-row);
        for(int i=row;i<rows;i++)
        {
            x[i-row]=A(i,col);
        }

        modulus=sqrtl(mat::dot(x,x));
        if(modulus<1e-15)
            {
                return H;
            }
        if(x[0]>=0)
        {
            x[0]=x[0]+modulus;
        }
        else
        {
            x[0]=x[0]-modulus;
        }
        temp_H=temp_H-(2.0l/mat::dot(x,x))*(x*mat::trans(x));

        if(row==0)
        return temp_H;
        else
        {
            for(int i=row;i<rows;i++)
            {
                for(int j=row;j<rows;j++)
                    H(i,j)=temp_H(i-row,j-row);
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
        if(col>=cols)
        {
            return H;
        }
        Identity temp_H(cols-col);
        Vector x(cols-col,Type::row);
        for(int i=col;i<cols;i++)
        {
            x[i-col]=A(row,i);
        }
        modulus=sqrtl(mat::dot(x,x));
        if(modulus<1e-15)
        {
            return H;
        }
        if(x[0]>=0)
        {
            x[0]=x[0]+modulus;
        }
        else
        {
            x[0]=x[0]-modulus;
        }
        temp_H=temp_H-(2.0l/mat::dot(x,x))*(mat::trans(x)*(x));

        if(col==0)
        return temp_H;
        else
        {
            for(int i=col;i<cols;i++)
            {
                for(int j=col;j<cols;j++)
                    H(i,j)=temp_H(i-col,j-col);
            }
        }
        return H;
    }
    else
    {
        throw std::invalid_argument("HT():incorrect parameter");
    }
    
}

// Matrix mat::HT(const Matrix& A, const int& row, const int& col, std::string method)
// {
//     if(method == "col")
//     {
//         int rows = A.getrow();
//         Identity H(rows);
//         if(row >= rows - 1) return H; // 最后一行不需要消

//         Vector x(rows - row);
//         for(int i = row; i < rows; i++) x[i - row] = A(i, col);

//         long double norm_sq = mat::dot(x, x);
//         long double modulus = sqrtl(norm_sq);
//         if(modulus < 1e-18) return H; // 已经是 0，直接返回单位阵

//         // Householder 向量构建：保证数值稳定的符号选择
//         if(x[0] >= 0) x[0] += modulus;
//         else x[0] -= modulus;

//         long double new_dot = mat::dot(x, x);
//         if(new_dot < 1e-18) return H;

//         // 构建 temp_H 并嵌入大矩阵 H
//         Identity temp_H(rows - row);
//         Matrix House = temp_H - (2.0 / new_dot) * (x * mat::trans(x));

//         for(int i = row; i < rows; i++)
//             for(int j = row; j < rows; j++)
//                 H(i, j) = House(i - row, j - row);

//         return H;
//     }
//     else if(method == "row")
//     {
//         int cols = A.getcol();
//         Identity H(cols);
//         if(col >= cols - 1) return H; // 最后一列不需要消

//         // 注意：SVD 行变换目标是消去 A(row, col+1 ... end)
//         Vector x(cols - col);
//         for(int i = col; i < cols; i++) x[i - col] = A(row, i);

//         long double norm_sq = mat::dot(x, x);
//         long double modulus = sqrtl(norm_sq);
//         if(modulus < 1e-18) return H;

//         if(x[0] >= 0) x[0] += modulus;
//         else x[0] -= modulus;

//         long double new_dot = mat::dot(x, x);
//         if(new_dot < 1e-18) return H;

//         Identity temp_H(cols - col);
//         // 行变换是对右侧作用，结构保持一致
//         Matrix House = temp_H - (2.0 / new_dot) * (x * mat::trans(x));

//         for(int i = col; i < cols; i++)
//             for(int j = col; j < cols; j++)
//                 H(i, j) = House(i - col, j - col);

//         return H;
//     }
//     throw std::invalid_argument("HT(): incorrect parameter");
// }