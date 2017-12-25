// #include <iostream>
// #include <string>
// #define FIN 65535
// using namespace std;
// void Floyd_Warshall(int ***, int ***, int);
// string reverse(string);
// int main() {
// 	int m, n;
// 	int x, y, v;
// 	cin >> n >> m;
// 	int ***D = new int**[n];
// 	int ***I = new int **[n];
// 	for (int i = 0; i < n; i++) {
// 		D[i] = new int*[n];
// 		I[i] = new int*[n];
// 		for (int j = 0; j < n; j++) {
// 			D[i][j] = new int[n];
// 			I[i][j] = new int[n];
// 			for (int m = 0; m < n; m++) {
// 				if (j == m) {
// 					D[i][j][m] = 0;
// 				}
// 				else {
// 					D[i][j][m] = FIN;
// 				}
// 				I[i][j][m] = FIN;
// 			}
// 		}
// 	}
// 	while (m--) {
// 		cin >> x >> y >> v;
// 		D[0][x][y] = v;
// 		I[0][x][y] = x;
// 	}
// 	Floyd_Warshall(D, I, n);
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			if (i != j) {
// 				if (D[n - 1][i][j] == FIN) {
// 					cout << i << " to " << j << " no path." << endl;
// 				}
// 				else {
// 					cout << i << " to " << j << ":" << endl;
// 					cout << "length:" << D[n - 1][i][j] << endl;
// 					string result = j + ">-";
// 					int t = j;
// 					while (I[n - 1][i][t] != i) {
// 						t = I[n - 1][i][t];
// 						result += t + ">-";
// 					}
// 					result += i;
// 					result = reverse(result);
// 					cout << "path: " << result << endl;
// 				}
// 			}
// 		}
// 	}
// 	return 0;
// }
// string reverse(string s) {
// 	string revStr = "";
// 	for (int i = s.size() - 1; i >= 0; i--) {
// 		revStr += s[i];
// 	}
// 	return revStr;
// }
// void Floyd_Warshall(int ***D, int ***I, int n) {
// 	for (int k = 1; k < n; k++) {
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++) {
// 				if (D[k - 1][i][j] < D[k - 1][i][k] + D[k - 1][k][j]) {
// 					D[k][i][j] = D[k - 1][i][j];
// 					I[k][i][j] = I[k - 1][i][j];
// 				}
// 				else {
// 					D[k][i][j] = D[k - 1][i][k] + D[k - 1][k][j];
// 					I[k][i][j] = I[k - 1][k][j];
// 				}
// 			}
// 		}
// 	}
// }



#include <iostream>
#include <string>
#define FIN 65535
using namespace std;
void Floyd_Warshall(int **, int **, int);
string reverse(string);
int main() {
	int m, n;
	int x, y, v;
	cin >> n >> m;
	int **D = new int*[n];
	int **I = new int*[n];
	for (int i = 0; i < n; i++) {
		D[i] = new int[n];
		I[i] = new int[n];
		for (int j = 0; j < n; j++) {

			if (j == i) {
				D[i][j] = 0;
			}
			else {
				D[i][j] = FIN;
			}
			I[i][j] = FIN;
		}
	}
	while (m--) {
		cin >> x >> y >> v;
		D[x][y] = v;
		I[x][y] = x;
	}
	Floyd_Warshall(D, I, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (D[i][j] == FIN) {
					cout << i << " to " << j << " no path." << endl;
				}
				else {
					cout << i << " to " << j << ":" << endl;
					cout << "length:" << D[i][j] << endl;
					// string result = "";
					// result +=  j + ">-";
					cout << "path:";
					cout << j << " <= ";
					int t = j;
					while (I[i][t] != i) {
						t = I[i][t];
						// result += t;
						// result += ">-";
						cout << t << " <= ";
					}
					// result += i;
					// result = reverse(result);
					// cout << "path: " << result << endl;
					cout << i << endl;
				}
			}
		}
	}
	return 0;
}
string reverse(string s) {
	string revStr = "";
	for (int i = s.size() - 1; i >= 0; i--) {
		revStr += s[i];
	}
	return revStr;
}
void Floyd_Warshall(int **D, int **I, int n) {
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// if (D[i][j] < D[i][k] + D[k][j]) {
				// 	D[i][j] = D[i][j];
				// 	I[i][j] = I[i][j];
				// }
				// else {
				// 	D[i][j] = D[i][k] + D[k][j];
				// 	I[i][j] = I[k][j];
				// }
				if (D[i][j] == FIN && (D[i][k] == FIN || D[k][j] == FIN)) {
					continue;
				}
				if (D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[i][k] + D[k][j];
					I[i][j] = I[k][j];
				}
			}
		}
	}
}
