#include <bits/stdc++.h>

using namespace std;

long long GetMax(long long a, long long b) {
	return (a > b ? a : b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, r;
		cin >> n >> r;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		long long x = 0;
		long long ans = LLONG_MIN;
		for (int i = 0; i < n; i++) {
			// the current tension to 'x'
			x += b[i];
			// store the maximum tension possible in 'ans'
			ans = GetMax(ans, x);
			// check if 'i' is not the last element
			if (i != n - 1) {
				// if yes, then get the maximum between 0 and 'r' multiplied
				// to the difference of minutes between the next time 'a[i + 1]' and the
				// current time 'a[i]' subtracted from 'x'
				x = GetMax(0, x - (r * (a[i + 1] - a[i])));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
