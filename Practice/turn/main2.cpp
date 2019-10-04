#include <iostream>
using namespace std;
int N, M, T;
int imap[300][300];
int imap2[300][300];
int strmap[100][100];
int* whole[90001];
int ans[300][300];
int mv[2][4] = {
	0, 1, 0, -1,
	1, 0, -1 ,0
};

void createImap(int y, int x, int N, int M, int c) {
	if (imap[y][x]) {
		return;
	}
	int i = y, j = x;
	for (; j < M + x; ++j) {
		whole[c] = &strmap[i][j];
		imap[i][j] = c++;
	}
	--j; ++i;
	for (; i < N + y; ++i) {
		whole[c] = &strmap[i][j];
		imap[i][j] = c++;
	}
	--i; --j;
	for (; j >= x; --j) {
		whole[c] = &strmap[i][j];
		imap[i][j] = c++;
	}
	++j; --i;
	for (; i > y; --i) {
		whole[c] = &strmap[i][j];
		imap[i][j] = c++;
	}
	createImap(y + 1, x + 1, N - 2, M-2, c);
}

void createImap2(int y, int x, int NN, int MM, int c, int d) {
	if (imap2[y][x]) {
		return;
	}
	int nn = 4 * (NN - 1);
	if (nn == 0) nn = 1;
	int s = (nn+ (d * (T % nn))) % nn;
	int i = y, j = x, w = 0;
	for (int k = 0; k < nn && w < 4; k++) {
		if (imap2[i][j] == 0) {
			imap2[i][j] = (k + s) % nn + c;
		}
		i += mv[0][w]; j += mv[1][w];
		if (i + mv[0][w] == NN + y ||
			j + mv[1][w] == MM + x ||
			i + mv[0][w] < y ||
			j + mv[1][w] < x) {
			w++;
		}
	}

	createImap2(y + 1, x + 1, NN - 2, MM-2 ,c + nn, d);
}

void createans() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ans[i][j] = *whole[imap2[i][j]];
		}
	}
}

int main() {
	cin >> N >> M >> T;
	 for(int i =0; i < N * M; ++i) {
	 	cin >> strmap[i/M][i%M];
	 }

	createImap(0, 0, N, M, 0);
	createImap2(0, 0, N, M, 0, 1);
	createans();

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}



	return 0;
}