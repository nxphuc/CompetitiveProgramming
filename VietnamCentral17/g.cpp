#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI w; 
VI ml, mr; 
char s[109][109];

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

int main() {
	// freopen("test.in", "r", stdin); 
	int n, m; 
	scanf("%d %d", &n, &m); 
	for (int i = 0; i < n; i++) scanf("%s", s[i]);  
	w.resize(n);  
	for (int i = 0; i < n; i++) 
		w[i].resize(m, 0); 


	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (s[i][j] == '#') 
				w[i][j] = 1;  

	printf("%d", BipartiteMatching(w, ml, mr));  
}
