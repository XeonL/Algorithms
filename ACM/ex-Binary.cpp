//AC
/*
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
我们都知道二进制数的每一位可以是0或1。有一天小Hi突发奇想：如果允许使用数字2会发生什么事情？小Hi称其为扩展二进制数，例如(21)ii = 2 * 21 + 1 = 5, (112)ii = 1 * 22 + 1 * 21 + 2 = 8。

很快小Hi意识到在扩展二进制中，每个数的表示方法不是唯一的。例如8还可以有(1000)ii, (200)ii, (120)ii 三种表示方法。

对于一个给定的十进制数 N ，小Hi希望知道它的扩展二进制表示有几种方法？

输入
一个十进制整数 N。(0 ≤ N ≤ 1000000000)

输出
N的扩展二进制表示数目。
*/
# include <iostream>
using namespace std;
int calc(int);
int main() {
    int n;
    cin >> n;
    cout << calc(n) << endl;
    return 0;
}

int calc(int n) {
    if(n==0) return 1;
    if(n%2==0) return calc(n/2) + calc(n/2-1);
    return calc(n/2);
}