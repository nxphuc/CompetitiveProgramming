struct point{ double x, y; };
inline point operator+(point a, point b) { a.x += b.x; a.y += b.y; return a; }
inline point operator-(point a, point b) { a.x -= b.x; a.y -= b.y; return a; }
inline point operator*(point a, point b) { point c; c.x = a.x * b.x - a.y * b.y; c.y = a.x * b.y + a.y * b.x; return c; }
inline point newpoint(double r, double t){ point c; c.x = r * cos(t); c.y = r * sin(t); return c; }

void fft(unsigned int n, double theta, point a[]) {
    unsigned int m, len, i, j;
    register point t,w;
    for (m = n; m > 1; m >>= 1) {
        len = m / 2;
        for(int d=0; d<len; ++d) {
            w = newpoint(1, theta * d);
            for (i = d; i < n; i += m) {
                j = i + len; t = a[i] - a[j];
                a[i] = a[i] + a[j]; a[j] = w * t;
            }
        }
        theta *= 2;
    }
    i = 0;
    for(j = 1; j < n; ++j){
        for (int k = n / 2; k > (i ^= k);
        k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
}

const int M = 65536; // M = 2^n const double PI = acos(-1); point pa[M], pb[M], pc[M];
void fast_mul(ll *arr1, ll *arr2, ll *ans, int MM){
    int Mx = MValue[MM];
    for(int i=0; i<Mx; ++i) {
        pa[i].x = 0; pb[i].x = 0;
        pa[i].y = 0; pb[i].y = 0;
    }
    for(int i=0; i<=min(MM,k); ++i)
        pa[i].x = arr1[i], pb[i].x = arr2[i];
    fft(Mx, 2.0*PI/Mx, pa); fft(Mx, 2.0*PI/Mx, pb);
    for(int i=0; i<Mx; ++i) pa[i] = pa[i]*pb[i];
    fft(Mx,-2.0*PI/Mx, pa);
    for(int i=0; i<Mx; ++i) pa[i].x /= Mx;
    for(int i=0; i<=min(MM,k); ++i) ans[i] = ll(pa[i].x+0.5);
}