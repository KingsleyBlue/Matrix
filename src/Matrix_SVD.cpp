#include"Matrix/Matrix_core.hpp"

void bidiagonal_qr(Matrix& B,Matrix& U,Matrix& V)
{
    namespace G=mat::Givens;
    int n = B.getrow();

    const long double eps = 1e-12;

    for(int iter=0;iter<1000;iter++)
    {
        bool done = true;

        for(int i=0;i<n-1;i++)
        {
            if(fabsl(B(i,i+1)) > eps)
                done = false;
        }

        if(done) break;

        for(int i=0;i<n-1;i++)
        {
            long double c,s;

            /* 右旋转 */

            G::givens(B(i,i),B(i,i+1),c,s);

            G::right_givens(B,i,c,s);
            G::update_V(V,i,c,s);

            /* 左旋转 */

            G::givens(B(i,i),B(i+1,i),c,s);

            G::left_givens(B,i,c,s);
            G::update_U(U,i,c,s);
        }
    }

    /* 奇异值取绝对值 */

    for(int i=0;i<n;i++)
        B(i,i) = fabsl(B(i,i));
}

std::vector<Matrix> mat::SVD(const Matrix& A)
{
    std::vector<Matrix> svd;
    svd.reserve(3);
    svd.push_back(Identity(A.getrow()));
    svd.push_back(Matrix(A));
    svd.push_back(Identity(A.getcol()));
    int rows=A.getrow();
    int cols=A.getcol();
    if(A.getcol()>=A.getrow())
    {
        for(int i=0;i<std::min(A.getcol(),A.getrow());i++)
        {
            Matrix H1=mat::HT(svd[1],i,i,"col");
            svd[0]=svd[0]*H1;
            svd[1]=H1*svd[1];
            Matrix H2=mat::HT(svd[1],i,i+1,"row");
            svd[2]=H2*svd[2];
            svd[1]=svd[1]*H2;
        }
    }
    else
    {
        for(int i=0;i<std::min(A.getcol(),A.getrow());i++)
        {
            Matrix H2=mat::HT(svd[1],i,i,"row");
            svd[2]=H2*svd[2];
            svd[1]=svd[1]*H2;
            Matrix H1=mat::HT(svd[1],i+1,i,"col");
            svd[0]=svd[0]*H1;
            svd[1]=H1*svd[1];
        }
    }

    return svd;
}