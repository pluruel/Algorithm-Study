#include <iostream>

using namespace std;
int N, M;
int map[8][8];

int q[65];
int viruses, hall;

int wx[4] = { 0, 1, 0, -1 };
int wy[4] = { -1, 0, 1, 0 };

bool val(int mapp[][8], int y, int x) {
	if (x > M - 1 || y > N - 1 || x < 0 || y < 0 || mapp[y][x]) {
		return false;
	}
	else {
		return true;
	}
}

int ans = 0;

int simulation(int w1, int w2, int w3) {
	int tmap[8][8];
	int top = viruses, rear = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			tmap[i][j] = map[i][j];
		}
	}


	tmap[w1 / M][w1 % M] = 1; tmap[w2 / M][w2 % M] = 1; tmap[w3 / M][w3 % M] = 1;

	while (top > rear) {
		int y = q[rear] / M; int x = q[rear++] % M;
		for (int i = 0; i < 4; ++i) {
			int ny = y + wy[i]; int nx = x + wx[i];
			if (val(tmap, ny, nx)) {
				tmap[ny][nx] = 2;
				q[top++] = ny * M + nx;
			}
		}
	}

	return hall - top - 3;

}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				q[viruses++] = i * M + j;
				hall++;
			}
			else if (!map[i][j]) {
				hall++;
			}
		}
	}

	int cases = N * M;
	for (int i = 0; i < cases - 2; ++i) {
		if (map[i / M][i % M]) continue;
		for (int j = i + 1; j < cases - 1; ++j) {
			if (map[j / M][j % M]) continue;
			for (int k = j + 1; k < cases; ++k) {
				if (map[k / M][k % M]) continue;
				ans = max(ans, simulation(i, j, k));
			}
		}
	}

	cout << ans << "\n";
	return 0;
}