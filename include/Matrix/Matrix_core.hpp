#pragma once
#include<iostream>
#include<vector>
#include<cmath>

class Matrix;
class Vector;

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
    long double dot(const Vector&,const Vector&);
    Matrix orthx(Matrix);
    Matrix reverse(const Matrix&);
    Matrix HT(const Matrix&,const int&);
    long double tr(const Matrix&);
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
    //构造函数
    Matrix():rows(0),cols(0){}
    Matrix(int r,int c):rows(r), cols(c), matrix(r, std::vector<long double>(c, 0)){}

    Matrix(int size):rows(size), cols(size), matrix(size, std::vector<long double>(size, 0))
    {
        for(int i=0;i<rows;i++)
        {
            matrix[i][i]=1;
        }
    }

    Matrix(const Matrix& m):rows(m.rows),cols(m.cols),matrix(m.matrix){}//拷贝构造函数
    Matrix(Matrix&& m):rows(m.rows),cols(m.cols),matrix(std::move(m.matrix))//移动构造函数
    {
        m.rows=0;
        m.cols=0;
    }

    //父类成员函数
    int getrow() const{return rows;}//返回行数
    int getcol() const{return cols;}//返回列数
   
    std::vector<std::vector<long double>> getmat() const{return matrix;}
    Matrix getrow(int row) const//返回某行
    {
        if(row>=rows)
        throw std::invalid_argument("out of range!");
        else
        {
            Matrix b(1,cols);
            for(int j=0;j<cols;j++)
            {
                //b.set(0,j,matrix[row][j]);
                b(0,j)=matrix[row][j];
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
                //b.set(i,0,matrix[i][col]);
                b(i,0)=matrix[i][col];
            }
            return b;
        }
    }
    
    //父类运算符重载
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

    Matrix& operator=(Matrix&& other) noexcept//移动运算符重载
    {
        if(this==&other)
        {
            return *this;
        }
        else
        {
            matrix.clear();
            rows=other.rows;
            cols=other.cols;
            matrix = std::move(other.matrix);
            other.rows=0;
            other.cols=0;
            return *this;
        }
    }

    long double& operator()(int r, int c)//写
    {
        if(r>=rows||c>=cols)
            throw std::invalid_argument("out of range!");
        else
            return matrix[r][c];
    }

    const long double& operator()(int r, int c) const   //读
    {
        if(r>=rows||c>=cols)
            throw std::invalid_argument("out of range!");
        else
            return matrix[r][c];
    }

 };

 class Vector:public Matrix
 {
    public:
    //构造函数
    Vector():Matrix(){};
    Vector(int r):Matrix(r,1){}
    Vector(const Vector&)=default;
    Vector(Vector&&)=default;

    //子类运算符重载
    long double& operator[](int r)
    {
        return (*this)(r,0);
    }
    long double operator[](int r) const
    {
        return (*this)(r,0);
    }
    int size() const
    {
        return getrow();
    }
    
    Vector& operator=(const Vector& other)
    {
        Matrix::operator=(other);
        return *this;
    }
    Vector& operator=(Vector&& other)//移动运算符重载
    {
        Matrix::operator=(std::move(other));
        return *this;
    }
    Vector(const Matrix& m) : Matrix(m)//转换构造函数
    {
        if (m.getcol() != 1)
            throw std::invalid_argument("Not a column vector");
    }

    private:
    using Matrix::getcol;
    using Matrix::getrow;
    using Matrix::getmat;
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