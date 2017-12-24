#include <iostream>
using namespace std;
int partition(int *A,int p,int r);
void quickSort(int *A,int p,int r);
void quickSort2(int *A,int p,int r);
int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    quickSort2(a,0,n-1);
    for(int i = 0;i < n;i++) {
        cout << a[i] << endl;
    }
    return 0;
}
void quickSort(int *A,int p,int r) {
    if(p < r) {
        int q = partition(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
}
int partition(int *A,int p,int r) {
    int x = A[r];
    int i = p - 1;
    for(int j = p;j < r;j++) {
        if(A[j] <= x) {
            i++;
            int tem = A[i];
            A[i] = A[j];
            A[j] = tem;
        }
    }
    int tem = A[r];
    A[r] = A[i+1];
    A[i+1] = tem;
    return i+1;
}
void quickSort2(int *A,int p,int r) {
    if(p >= r) return;
    int x = A[r];
    int i = p;
    int j = r - 1;
    while(i <= j) {
        while(i < r && A[i] <= x) i++;
        while(j >= p && A[j] > x) j--;
        if(i < j) {
            int tem = A[i];
            A[i] = A[j];
            A[j] = tem;
        }
    }
    A[r] = A[i];
    A[i] = x;

    quickSort2(A,p,i-1);
    quickSort2(A,i+1,r);
}