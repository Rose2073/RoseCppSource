#include<cstdio> 
#include<algorithm>
struct Edge{
	int u,v,w;
} edges[201000];
int f[5111];
int cmp(Edge a, Edge b) {
	return a.w < b.w;
}
int find(int x) {
	return f[x] = (f[x] == x ? x : find(f[x]));
}
int main() {
	int n,buffer, k = 0;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) 
		for (int j = 1;j <= n;j++) {
			scanf("%d", &buffer);
			if (i < j) {
				edges[k].u = i;
				edges[k].v = j;
				edges[k].w = buffer;
				k++;
			}
		}
	for (int i = 1;i <= n;i++) {
		f[i] = i;
	}
	std::sort(edges, edges + k, cmp);
	int count = n;
	int i = 0;
	while (count > 1 && i < k) {
		int a = find(edges[i].u);
		int b = find(edges[i].v);
		if (a != b) {
			ans += edges[i].w;
			f[a] = b;
			count--;
		}
		i++;
	}
	printf("%lld", ans);
	return 0;
}
