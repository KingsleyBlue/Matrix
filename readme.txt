不要使用using namespace std
定义一个矩阵，如Matrix A(m,n)，即m行n列的矩阵A
直接使用std::cin、std::cout即可
可对矩阵进行加、减、数乘和矩阵乘法
行列式：mat::det()
转置：mat::trans()
LU分解：mat::LUdecomp();返回auto=std::make_pair(L,U)