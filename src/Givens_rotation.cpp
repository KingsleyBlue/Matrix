#include"Matrix/Matrix_core.hpp"
namespace G=mat::Givens;

// 修改后的 Givens 计算（更加数值稳定）
void G::givens(long double a, long double b, long double& c, long double& s) {
    if (fabsl(b) < 1e-15) {
        c = 1.0; s = 0.0;
    } else if (fabsl(a) < 1e-15) {
        c = 0.0; s = (b > 0) ? 1.0 : -1.0;
    } else {
        long double r = sqrtl(a*a + b*b);
        c = a / r;
        s = b / r;
    }
}

// 修正后的右旋转更新 (对应 B = B * G)
void G::right_givens(Matrix& B, int i, long double c, long double s) {
    for(int k=0; k < B.getrow(); k++) {
        long double x = B(k, i);
        long double y = B(k, i+1);
        B(k, i)   =  c*x + s*y;
        B(k, i+1) = -s*x + c*y; // 注意这里的符号组合
    }
}

// 修正后的左旋转更新 (对应 B = G^T * B)
void G::left_givens(Matrix& B, int i, long double c, long double s) {
    for(int k=0; k < B.getcol(); k++) {
        long double x = B(i, k);
        double y = B(i+1, k);
        B(i, k)   = c*x + s*y;
        B(i+1, k) = -s*x + c*y;
    }
}

void G::update_V(Matrix& V, int i, long double c, long double s) {
    int n = V.getrow();
    for (int k = 0; k < n; k++) {
        long double x = V(k, i);
        long double y = V(k, i + 1);
        // 注意：V 的更新方向需与右作用于 B 的算子保持一致
        V(k, i)     = c * x + s * y;
        V(k, i + 1) = -s * x + c * y;
    }
}

void G::update_U(Matrix& U, int i, long double c, long double s) {
    int m = U.getrow();
    for (int k = 0; k < m; k++) {
        long double x = U(k, i);
        long double y = U(k, i + 1);
        // 注意：U 的更新对应左作用于 B 的算子的转置
        U(k, i)     = c * x + s * y;
        U(k, i + 1) = -s * x + c * y;
    }
}