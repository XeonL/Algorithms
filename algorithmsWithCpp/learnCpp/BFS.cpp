//WA SCORE:80/100
/*
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
小Hi正处在由 N × M 个房间组成的矩阵迷宫中。为了描述方便，我们把左上角的房间的坐标定为(0, 0),右下角房间的坐标定为(N-1, M-1)。每个房间可能是3种状态之一：开放的、关闭的、或者上锁的。

开放房间用'.'表示。小Hi可以从一个开放房间到达另一个相邻的(上下左右)开放房间。

关闭房间用'#'表示。小Hi永远不能进入一个关闭的房间。

上锁的房间用大写字母('A', 'B', 'C' ...)表示。小Hi在取得相应的钥匙前不能进入上锁的房间，而一旦取得钥匙就可以反复进入上锁的房间。每个房间的锁都是不同的，相应的钥匙在迷宫中的某一房间里，小Hi进入该房间就可以取得钥匙。

小Hi一开始处于一个开放房间，坐标(a, b)。迷宫的出口是一个开放或者上锁的房间，坐标(c, d)。假设小Hi每移动到一个相邻房间需要花费单位1的时间，那么小Hi到达出口最少需要花费多少时间？

输入
第一行包含7个整数: N , M , K , a , b , c , d . 其中N , M是矩阵的行列数；K 是上锁的房间数目，(a, b)是起始位置，(c, d)是出口位置。(1 ≤ N, M ≤ 100, 0 ≤ K ≤ 5, 0 ≤ a, c < N, 0 ≤ b, d < M)

以下 N 行每行包含 M 个字符，表示迷宫矩阵。

再以下 K 行每行两个整数 x, y，依次表示上锁房间A , B , C ....的钥匙所在房间坐标。(0 ≤ x < N, 0 ≤ y < M)

输出
输出到达出口的最短时间。如果小Hi永远到达不了出口，输出-1。
*/
# include <iostream>
# include <string>
# include <queue>
using namespace std;
typedef struct Pos {
    int x = 0;
    int y = 0;
//    bool keys[5] = {false,false,false,false,false};
    int keys = 0x0;
    int step = 0;
} Pos;
int main() {
    int n,m,keyNum,x,y;
    Pos start,end;
    int step = 0;
    cin >> n >> m >> keyNum >> start.x >> start.y >> end.x >> end.y;
    char Labyrinth[100][100] = {0};
    char keysPos[100][100] = {0};
    string str;
    // for(auto &row : Labyrinth) {
    //     for(auto &pos : row) {
    //         cin >> pos;
    //     }
    // }
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            cin >> Labyrinth[i][j];
        }
    }
    for(int i = 0;i < keyNum;i++) {
        cin >> x >> y;
        keysPos[x][y] = 'A' + i;
    }
    queue<Pos> que = {};
    que.push(start);
    // queue<int> q;
    // q.push(1);
    // cout << que.size() << q.size() << endl;
    // cout << que.empty() << q.empty() <<endl;
    Labyrinth[start.x][start.y] = '*';
    while(!que.empty()) {
        Pos now = que.front();
        que.pop();
        if(now.x==end.x&&now.y==end.y) {
            // cout << now.step;
            // return 0;
            if(step==0) {
                step = now.step;
            } else {
                step = step > now.step?now.step:step;
            }
        }
        Pos next[4];
        for(int i = 0;i <= 3;i++) {
            next[i].x = i%2!=0?now.x:now.x + i - 1;
            next[i].y = i%2!=0?now.y + 2 - i:now.y;
            next[i].keys = now.keys;
            next[i].step = now.step + 1;
            if(next[i].x>=n||next[i].x<0||next[i].y>=m||next[i].y<0) {
                continue;
            }
            char p = Labyrinth[next[i].x][next[i].y];
            if(p=='#'||p=='*'||(p!='#'&&p!='.'&&p!='*'&&!((now.keys-(0x1<<(p-'A')))>=0))) {
                continue;
            }
            
            if(keysPos[next[i].x][next[i].y]!=0){
                // next[i].keys[keysPos[next[i].x][next[i].y]-'A'] = true;
                next[i].keys += 0x1<<(keysPos[next[i].x][next[i].y]-'A');
                keysPos[next[i].x][next[i].y] = 0;
                for(auto &row : Labyrinth) {
                    for(auto &pos : row) {
                        if(pos=='*') {
                            pos = '.';
                        }
                    }
                }
            }
            Labyrinth[next[i].x][next[i].y] = '*';
            que.push(next[i]);
        }
    }
    cout << step?step:-1;
    // for(auto &row : Labyrinth) {
    //     for(auto &pos : row) {
    //        cout << pos;
    //     }
    //     cout << endl;
    // }
    // for(auto &row : keysPos) {
    //     for(auto &pos : row) {
    //        cout << pos;
    //     }
    //     cout << endl;
    // }


    return 0;
}
