#pragma once
#include<iostream>
#include<vector>
#include<cmath>

class Matrix;
namespace mat
{
    Matrix trans(const Matrix&);//求转置矩阵
    Matrix GaussianElimination(Matrix);//高斯消元法
    double det(const Matrix&);//求行列式
    std::pair<Matrix, Matrix> LUdecomp(const Matrix&);//LU分解
    int rank(Matrix);//求秩
    Matrix col_aug(const Matrix&,const Matrix&);//列增广矩阵
    Matrix row_aug(const Matrix&,const Matrix&);//行增广矩阵
    std::pair<Matrix, Matrix> QRdecomp(const Matrix&);//QR分解
    std::vector<Matrix> solution(const Matrix&,const Matrix&);
    long double dot(const Matrix&,const Matrix&);
    Matrix orthx(Matrix);
    Matrix reverse(const Matrix&);
    Matrix HT(const Matrix&,const int&);
}

//定义矩阵
 class Matrix
 {
    friend std::istream &operator>>(std::istream &is, Matrix &m);
    friend Matrix mat::GaussianElimination(Matrix A);
    friend int mat::rank(Matrix);

    private:
    int rows,cols;
    std::vector<std::vector<long double>>matrix;
    
    public:
    Matrix():rows(0),cols(0){}
    Matrix(int r,int c):rows(r), cols(c), matrix(r, std::vector<long double>(c, 0)){}

    Matrix(int size):rows(size), cols(size), matrix(size, std::vector<long double>(size, 0))
    {
        for(int i=0;i<rows;i++)
        {
            matrix[i][i]=1;
        }
    }

    Matrix(const Matrix& m):rows(m.rows),cols(m.cols),matrix(m.matrix){}
    int getrow() const{return rows;}//返回行数
    int getcol() const{return cols;}//返回列数
    long double getvalue(int row,int col) const
    {
        if(row>=rows||col>=cols)
            throw std::invalid_argument("out of range!");
        else
        return matrix[row][col];
    }
    std::vector<std::vector<long double>> getmat() const{return matrix;}
    void set(int row,int col,long double value){matrix[row][col]=value;}
    Matrix getrow(int row) const//返回某行
    {
        if(row>=rows)
        throw std::invalid_argument("out of range!");
        else
        {
            Matrix b(1,cols);
            for(int j=0;j<cols;j++)
            {
                b.set(0,j,matrix[row][j]);
            }
            return b;
        }
    }
    Matrix getcol(int col) const//返回某列
    {
        if(col>=cols)
        throw std::invalid_argument("out of range!");
        else
        {
            Matrix b(rows,1);
            for(int i=0;i<rows;i++)
            {
                b.set(i,0,matrix[i][col]);
            }
            return b;
        }
    }
    
    Matrix& operator=(const Matrix& other)//拷贝运算符重载
    {
        // 检查自赋值
        if (this == &other)
        {
            return *this;
        }

        // 检查矩阵规模是否相同
        else if (rows != other.rows || cols != other.cols)
        {
            throw std::invalid_argument("=():size not match!");
        }

        // 复制数据
        else
        {
            rows=other.rows;
            cols=other.cols;
            matrix = other.matrix;
            return *this;
        }
    }

    Matrix& operator=(Matrix&& other)//移动运算符重载
    {
        if(this==&other)
        {
            return *this;
        }
        else if(rows != other.rows || cols != other.cols)
        {
            throw std::invalid_argument("=():size not match!");
        }
        else
        {
            rows=other.rows;
            cols=other.cols;
            matrix = other.matrix;
            other.rows=0;
            other.cols=0;
            std::vector<std::vector<long double>>().swap(other.matrix);
            return *this;
        }
    }

 };


//重载运算符
std::istream &operator>>(std::istream &, Matrix &);

std::ostream & operator<<(std::ostream &, const Matrix &);

Matrix operator+(const Matrix&, const Matrix&);

Matrix operator-(const Matrix&,const Matrix&);

Matrix operator*(const long double&,const Matrix&);//矩阵数乘

Matrix operator*(const Matrix&,const long double&);//矩阵数乘

Matrix operator/(const Matrix&,const long double&);//矩阵数除

long double operator/(const Matrix&,const Matrix&);

Matrix operator*(const Matrix&,const Matrix&);//矩阵乘法

bool operator==(const Matrix&,const Matrix&);//判断矩阵是否相等