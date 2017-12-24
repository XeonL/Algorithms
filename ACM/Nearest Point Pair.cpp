#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Point {
	double x,y;
};
struct Pair {
	int m,n;
};
struct PairArea {
	double len = -1;
	vector<Pair> pairs;
};
double length(Point &m,Point &n);
void NPP(Point *map,int i,int j,PairArea *area);
int partition(Point *map,int p,int r);
void quickSort(Point *map,int p,int r);
void exchange(Point &x,Point &y);

int main(int argc, char** argv) {
	PairArea area;
	
	int n;
	cin >> n;
	Point *map = new Point[n];
	for(int i=0;i<n;i++) {
		cin >> map[i].x;
		cin >> map[i].y;
	}
	
	quickSort(map,0,n-1); 
	// for(int i=0;i < n;i++) {
	// 	cout << map[i].x << endl;
	// }
	NPP(map,0,n-1,&area);
	cout << area.len << endl;
	for(int i=0;i < area.pairs.size();i++) {
		int m = area.pairs[i].m;
		int n = area.pairs[i].n;
		cout << map[m].x << "," << map[m].y << "\t";
		cout << map[n].x << "," << map[n].y << endl;
	}
	
	
	// double smallLength = 1000000;
	// int minI,minJ;
	// for(int i=0;i<n;i++) {
	// 	for(int j=i+1;j<n;j++) {
	// 		if(length(map[i],map[j])<=smallLength) {
	// 			smallLength = length(map[i],map[j]);
	// 			minI = i;
	// 			minJ = j;
	// 		}
	// 	}
	// }
	
	// cout << smallLength << endl;
	// cout << map[minI].x << "," << map[minI].y << " " << map[minJ].x << "," << map[minJ].y << endl;
	return 0;
}
void NPP(Point *map,int i,int j,PairArea *area) {
	// cout << i << " " << j <<" begin" << endl;
	if(i>=j) return;
	if(i == j-1) {
		double len = length(map[i],map[j]);
		if(area->len == -1||area->len > len) {
			area->len = len;
			area->pairs.clear();
			// cout << "clear" << endl;	
			// cout << "update length:" << len << endl;
		} 
		if(area->len == len) {
			Pair newPair;
			newPair.m = i;
			newPair.n = j;
			area->pairs.push_back(newPair);		
			// cout << "push " << map[i].x << "," << map[i].y;
			// cout << " " << map[j].x << "," << map[j].y << endl;
		}
		// cout << i << " " << j <<" end" << endl;
		return;
	}
	int mid = i+(j-i)/2;
	NPP(map,i,mid,area);
	NPP(map,mid+1,j,area);
	double nowLen = area->len;
	double minX = map[mid].x - nowLen;
	double maxX = map[mid].x + nowLen;
	int min = mid;
	int max = mid;
	while(min>i&&map[min-1].x >= minX) min--;
	while(max<j&&map[max+1].x <= maxX) max++;
	for(int i = min;i<=mid;i++) {
		for(int j = mid+1;j<=max;j++) {
			
			double len = length(map[i],map[j]);
			if(area->len == -1||area->len > len) {
				area->len = len;
				area->pairs.clear();
				// cout << "clear" << endl;
				// cout << "update length:" << len << endl;	
			} 
			if(area->len == len) {
				Pair newPair;
				newPair.m = i;
				newPair.n = j;
				area->pairs.push_back(newPair);		
				// cout << "push " << map[i].x << "," << map[i].y;
				// cout << " " << map[j].x << "," << map[j].y << endl;
			}
		}
	}
	// cout << i << " " << j <<" end" << endl;
}
double length(Point &m,Point &n) {
	double x = m.x-n.x;
	double y = m.y-n.y;
	return sqrt(x*x+y*y);
}
void quickSort(Point *map,int p,int r) {
	// if(i >= j) return;
	// int m = i+1,n = j;
	// double v = map[i].x;
	// while(m!=n) {
	// 	while(map[n].x >= v&&m<n) n--;
	// 	while(map[m].x < v&&m<n) m++;
	// 	if(m<n) {
	// 		exchange(map[m],map[n]);
	// 	}
	// }
	// if(map[m].x > v) exchange(map[i],map[m-1]);
	// else {
	// 	exchange(map[i],map[m]);	
	// }
    // exchange(map[i],map[m-1]);
	// quickSort(map,i,m-1);
	// quickSort(map,m+1,j);
    if(p < r) {
        int q = partition(map,p,r);
        quickSort(map,p,q-1);
        quickSort(map,q+1,r);
    }
}
int partition(Point *map,int p,int r) {
    int x = map[r].x;
    int i = p - 1;
    for(int j = p;j < r;j++) {
        if(map[j].x <= x) {
            i++;
            exchange(map[i],map[j]);
        }
    }
    exchange(map[r],map[i+1]);
    return i+1;
}
void exchange(Point &x,Point &y) {
	double temX = x.x;
	double temY = x.y;
	x.x = y.x;
	x.y = y.y;
	y.x = temX;
	y.y = temY;
	
}
