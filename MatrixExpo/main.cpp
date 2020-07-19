#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long MOD2 = static_cast<long long>(MOD) * MOD;
const int MAX_K = 50;
/* https://www.hackerearth.com/practice/notes/matrix-exponentiation-1/ */
struct Matrix
{
    vector< vector<int> > mat;
    int n_rows, n_cols;

    Matrix() {}

    Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n)
    {
        vector< vector<int> > values(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const
    {
        int n = n_rows, m = other.n_cols;
        vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                long long tmp = 0;
                for(int k = 0; k < n_cols; k++) {
                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    while(tmp >= MOD2)
                        tmp -= MOD2;
                }
                result[i][j] = tmp % MOD;
            }
        return move(Matrix(move(result)));
    }

    inline bool is_square() const
    {
        return n_rows == n_cols;
    }
};

// M_powers[i] is M, raised to 2^i-th power
Matrix M_powers[55];

void precalc_powers(Matrix M)
{
    assert(M.is_square());
    M_powers[0] = M;

    for(int i = 1; i < 55; i++)
        M_powers[i] = M_powers[i - 1] * M_powers[i - 1];
}

Matrix fast_exponentiation_with_precalc(int power)
{
    Matrix result = Matrix::identity_matrix(M_powers[0].mat.size());
    int pointer = 0;
    while(power) {
        if(power & 1)
            result = result * M_powers[pointer];
        pointer++;
        power >>= 1;
    }
    return result;
}

Matrix fast_exponentiation(Matrix m, int power)
{
    assert(m.is_square());
    Matrix result = Matrix::identity_matrix(m.n_rows);

    while(power) {
        if(power & 1)
            result = result * m;
        m = m * m;
        power >>= 1;
    }

    return result;
}

int main()
{
    int t;
/*
    for precalculating power If you problem requires answering many queries
    of raising the same matrix M to some power, you can precalculate powers
    of two of M to get things done faster.

    Matrix M({
            {4, 0, 0},
            {2, 3, 0},
            {0, 1, 2} });
    precalc_powers(M);

    Matrix initial({ {0, 1, 2} });
    t = get_int();
    for(int i = 0; i < t; i++) {
        int n = get_int();
        cout << (initial * fast_exponentiation_with_precalc(n - 1)).mat[0][0] << "\n";
    }
*/
/*
    for recurrence solution
    Let’s take a look at more general problem than before. Sequence A satisfies two properties:

    Ai = c1 * Ai-1 + c2 * Ai-2 + … + ck * Ai-k for i ≥ k (c1, c2 …, ck are given integers);
    A0 = a0, A1 = a1, …, Ak-1 = ak-1 (a0, a1, …, ak-1 are given integers).
    We need to find AN modulo 1000000007, when N is up to 1018 and k up to 50.

    eg. fibonacci sequence
    int n=2,N=4;
    int cc[n+1];//stores coff c1,c2 and so on
    cc[1]=1;cc[2]=1;
    vector< vector<int> > vv(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j+1)vv[i][j]=1;
            else if(j==n-1){
                vv[i][j]=cc[n-i];
            }
        }
    }
    Matrix M(vv);
    vector< vector<int> >ii(1,vector<int> (n));//stores a0,a1,..an-1
    ii[0][0]=1;
    ii[0][1]=1;
    Matrix initial( ii );
    cout << (initial * fast_exponentiation(M,N-n+1)).mat[0][n-1] << "\n";
*/



/*Fast expo only code*/
/*
    Matrix M({
            {4, 0, 0},
            {2, 3, 0},
            {0, 1, 2} });
    M=fast_exponentiation(M,2);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<M.mat[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    return 0;
}
