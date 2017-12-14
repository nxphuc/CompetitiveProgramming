#include <bits/stdc++.h>
using namespace std;

const int MAX = 110;
const int INF = 1e9;
const long double EPS = 1e-9;
const long double ONE = 1;

double dist[MAX][MAX];
double f[2][MAX];
int n, m, p;

struct Matrix {
	vector<vector<double>> x;
	int m, n;

	Matrix(int m = 0, int n = 0) : m(m), n(n) {
		x.resize(m);
		for (int i = 0; i < m; i++) {
			x[i].resize(n);
			for (int j = 0; j < n; j++) {
				x[i][j] = 0;
			}
		}
	}
	void print() {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << x[i][j] << ' ';
			}
			cout << endl;
		}
	}
};

Matrix operator*(const Matrix &a, const Matrix &b) {
	Matrix c(a.m, b.n);
	for (int i = 0; i < c.m; i++){
		for (int j = 0; j < c.n; j++) {
			for (int k = 0; k < a.n; k++) {
				c.x[i][j] += a.x[i][k] * b.x[k][j];
			}
		}
	}
	return c;
}

Matrix identity(int n) {
	Matrix res(n, n);
	for (int i = 0; i < n; i++) {
		res.x[i][i] = 1;
	}
	return res;
}

void floydWarshall() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

double sumDist(int u) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += dist[u][i];
	}
	return sum;
}

Matrix fastPow(Matrix mat, int exp) {
	if (exp == 1) {
		return mat;
	}
	Matrix tmp = fastPow(mat, exp >> 1);
	tmp = tmp*tmp;
	if (exp & 1) {
		tmp = tmp*mat;
	}
	return tmp;
}

int main() {
	freopen("C-large-practice.in", "rt", stdin);
	freopen("C-large-practice.ou", "wt", stdout);
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int t;

	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		cin >> n >> m >> p;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = i == j ? 0 : INF;
			}
		}
		for (int u, v, d, i = 0; i < m; i++) {
			cin >> u >> v >> d;
			u--, v--;
			dist[u][v] = dist[v][u] = d;
		}
		floydWarshall();

		Matrix mat(n+1, n+1);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (j == n) {
					mat.x[i][j] = i == n ? 1 : sumDist(i) / (n-1);
					continue;
				}
				if (i == j) {
					mat.x[i][j] = 0;
					continue;
				}
				mat.x[i][j] = i == n ? 0 : 1.0/(n-1);
			}
		}
		mat = fastPow(mat, p);
		Matrix f(n+1, 1);
		f.x[n][0] = 1;

		cout << "Case #" << cs << ": " << fixed << setprecision(6) << (mat*f).x[0][0] << "\n";
	}
	return 0;
}
