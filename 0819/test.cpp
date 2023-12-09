#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#define MAX 8
using namespace std;




// 프로그래머스 level 2 피로도 ( 완전 탐색 , DFS , recursive ) 일부 case 만 통과 
// my code 

// bool compare(vector<int> a , vector<int>  b)
// {
//    if( a[0] > b[0] )
//    {
//        return true;
//    }
//     else
//     {
//         return false;
//     }
// }
//
// int complete(int n , vector<int> a)
// {
//     if( n >= a[0]) return n -= a[1];
//     else return 5001;
// }
//
// vector<bool> visited(8, false); // 전역 변수로 초기화
//
// int cnt = 0;
// int recursiveDFS(int a , const vector<vector<int>>& v , int n )
// {
//     if(complete(a,v[n]) != 5001)
//     {
//         a = complete(a,v[n]);
//         visited[n] = true;
//         cnt++;
//         for(int i = 0;i<v.size();i++)
//         {
//             if( visited[i] == false && complete(a , v[i]) != 5001)
//             {
//                 recursiveDFS(a , v , i);
//             }
//         }
//     }
//     return cnt;
// }
//
// int solution(int k, vector<vector<int>> dungeons) {
//     int answer = -1;
//
//     sort(dungeons.begin(),dungeons.end(),compare);
//     for(auto n :dungeons) cout << n[0] << " , " << n[1] << endl;
//
//     int stamina = k;
//     int temp = 0;
//
//     for(int i = 0 ; i < dungeons.size() ;i++)
//     {
//         temp = recursiveDFS(stamina , dungeons , i);
//         if( temp >= answer) answer = temp;
// 
//            fill(visited.begin(), visited.end(), false); // 방문 여부 배열 초기화
//         stamina = k;
//
//         cnt = 0;
//     }
//
//     // 일부 testcase 만 통과 
//
//     return answer;
//}



//answer code 
//{
// int answer = 0;
// bool visited[MAX] = {0};

// void dfs(int cnt, int k, vector<vector<int>> &dungeons) {
//     if (cnt > answer) answer = cnt;
//   
//     for (int i=0; i<dungeons.size(); i++) {
//         if (!visited[i] && dungeons[i][0] <= k) {
//             visited[i] = true;
//             dfs(cnt + 1, k - dungeons[i][1], dungeons);
//             visited[i] = false;
//         }
//     }
// }
//
// int solution(int k, vector<vector<int>> dungeons) {
//     dfs(0, k, dungeons);
//    
//     return answer;
// }
//}



// programmers lv2 brute force 모의고사 , solve 
//https://school.programmers.co.kr/learn/courses/30/lessons/42840

    // vector<int> solution(vector<int> answers) {
    // vector<int> answer;
    // int a = 0 ,b =0,c=0;
    // long long cnt1 = 0 ,cnt2 = 0 , cnt3 = 0;
    // vector<int> first = { 1,2,3,4,5};
    // vector<int> second = {2,1,2,3,2,4,2,5};
    // vector<int> third = {3,3,1,1,2,2,4,4,5,5};
    
    // for(int i = 0 ; i< answers.size() ; i++)
    // {
        

    //     if (a != 0 && i % first.size() == 0) a = 0;
    //     if (b != 0 && i % second.size() == 0) b = 0;
    //     if (c != 0 && i % third.size() == 0) c = 0;
        
        
        
    //     if(answers[i] == first[a]) cnt1++;
        
            
   
            
        
    //     if(answers[i] == second[b]) cnt2++;
        
    //     if(answers[i] == third[c]) cnt3++;
        
        
        

    //     a++;
    //     b++;
    //     c++;
        
    // }
    
    
    
    // int temp =max(max(cnt1,cnt2),cnt3);
    
    // if( temp == cnt1 ) answer.push_back(1);
    // if( temp == cnt2 ) answer.push_back(2);
    // if( temp == cnt3 ) answer.push_back(3);
   
    
    
    
    // return answer;
    // }





//long long K;
// 1 <= N <= 10 , 1 <= K <= 100,00,000
//둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다.
// (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)



// 에라토스테네스의 제  구현 ,
bool Eratos ( int n , int a )
{
    // n 이 1보다 작거나 같으면 종료 
    if(  n<= 1 ) return false;

    // 2 부터 n-1 까지 저장할수있는 배열할당 
    // 배열 참조번호와 소수가 일치하도록 배열 크기는 n + 1 로 할당 
    // index 0 , 1 은 사용 x 
    bool* PrimaryArray = new bool[n+1];


    // 배열 초기화 , 처음엔 모든 숫자를 소수로 보고 true 값주기 
    for(int i = 2 ; i <= n ; i++) PrimaryArray[i] = true;

    for(int i = 2 ; i * i <= n ; i++)
    {
        if(PrimaryArray[i]) // bool 형식이니깐 만약 true 값에 도달했다면 
        {
            // if 3 이 true 면 9 부터 check 시작 
            for(int j = i * i;  j <= n ; j += i )
            {
                PrimaryArray[i] = false;
            }
        }
    }

    return PrimaryArray[a] ? PrimaryArray[a] : false;


}


// BOJ 2178 미로찾기 ( bfs) 

// #define X first
// #define Y second
// int dx[4] = {0 , 0 , -1 , 1};
// int dy[4] = {1 , -1 , 0 , 0};
// int dist[102][102];
// string board[102];
//     cin >> N >> M;
//
//     for(int i = 0 ; i < N ; i++)
//         cin >> board[i];
//
//     for(int i = 0 ; i < N ;i++) fill(dist[i],dist[i]+M,-1); // -1로 배열 초기화 
//
//     for(int i = 0 ; i < N ; i++)
//     {
//         for(int j = 0 ; j < M ; j++)
//         {
//             cout << board[i][j] << " " ;
//         }
//         cout << '\n';
//     }
//     queue<pair<int,int>> q;
//     dist[0][0] = 0;
//     q.push({0,0});
//     while(!q.empty())
//     {
//         pair<int,int> cur = q.front(); q.pop();
//         for(int dir = 0 ; dir < 4 ; dir++)
//         {
//             int nx = cur.X + dx[dir];
//             int ny = cur.Y + dy[dir];
//             if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
//             if(dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
//             dist[nx][ny] = dist[cur.X][cur.Y] + 1;
//             q.push({nx,ny});
//             //cout << nx << " " << ny << " " << '\n';
//         }
//     }
//     cout << dist[N-1][M-1] + 1 << '\n';
 
//BOJ 7567 토마토 ( bfs ) 
//  {
//     int N , M;
// #define X first
// #define Y second
// int dx[4] = {-1 , 1 , 0,0 };
// int dy[4] = { 0 , 0 , 1, -1};
// int tomato[1002][1002];
// int dist[1002][1002];
// int main()
// {   
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >>  M >> N;
//     queue<pair<int,int>> Q;
//     for(int i = 0 ; i < N;i++)
//     {
//         for(int j = 0 ; j < M;j++)
//         {
//             cin >> tomato[i][j];
//
//             if(tomato[i][j] == 1) 
//             {
//                 Q.push({i,j});
//             }
//             else if(tomato[i][j] == 0)
//             {
//                 dist[i][j] = -1;
//             }
//         }
//     }
//     while(!Q.empty())
//     {
//         pair<int,int> cur = Q.front() ; Q.pop();
//         for(int dir = 0 ; dir < 4 ; dir++)
//         {
//             int nx = cur.X + dx[dir];
//             int ny = cur.Y + dy[dir];
//             if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
//             if( dist[nx][ny] >= 0 ) continue; // 0이거나 0보다 크면 이미 방문한 노드로 처리함 -> -1 로된 부분만 처리하니깐 
//             // 만약 빈공간이라면 0 으로 처리되어있으니 자연스럽게 넘어감 
//             //  if(tomato[nx][ny] == -1) continue;
//             dist[nx][ny] = dist[cur.X][cur.Y] + 1;
//            
//             Q.push({nx,ny});
//         }
//     }
//     int ans = 0;
//     for(int i = 0 ; i < N ; i++)
//     {
//         for(int j = 0 ; j < M ;j++)
//         {
//             if(dist[i][j] == -1) // 만약 -1 이있다면 우리가 초기화한 토마토값(-1) 이 남아있다는뜻이니 바로 -1 리턴 
//             {
//                 cout << -1 << '\n';
//                 return 0;
//             }
//             ans = max(dist[i][j], ans);  // -1 값이없다면 계속해서 최대값을 가져온다 
//         }
//         cout << '\n';
//     }
//     cout << ans ;   
//  }

//BOJ 4179 불 ! ( BFS )
// {
// int N , M;
// #define X first
// #define Y second
// int dx[4] = {-1 , 1 , 0,0 };
// int dy[4] = { 0 , 0 , 1, -1};
// string board[1002];
// int dist[1002][1002];
// int firedist[1002][1002];
// int main()
// {   
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     // board에 넣으면서  J 와 F 의 위치를 찾고 
//     // bfs를 의 dir을 돌릴때 J와 F를 같이 돌려서 만약 만나면 impossible ? 
//     // 만약 J의 bfs를 돌릴때 탈출에 성공하게되면 바로 return ? 
//     // 해답 , fire bfs를 먼저 돌려서 해당 firedist 배열을 바탕으로 
//     // jihoon bfs를 돌려서 fire보다 값이 적은곳만 돌아다닐수있게 조건을 설정하고 만약 N 혹은 M 에 도달한다면 
//     // dist[cur.X][cur.Y] + 1 값을 해줘서 return 하면 탈출값이 나오고 만약 탈출을 못하고 bfs가 끝나게될경우 
//     // 해당 경우는 탈출이 불가능하니 "IMPOSSIBLE" 을 출력하면 된다 
//     pair<int, int> jihoon;
//     pair<int, int> fire;
//     cin >> N >> M;
//     for(int i = 0 ; i < N ;i++) fill(dist[i],dist[i]+M,-1); // -1로 배열 초기화 
//
//     for(int i = 0 ; i< N ; i++) fill(firedist[i],firedist[i]+M,-1);
//
//     for(int i = 0 ; i < N ;i++)
//         cin >> board[i];
//
//     queue<pair<int,int>> Q1;
//     queue<pair<int,int>> Q2;
//     for(int i = 0; i < N ;i++) // 불의 시작점이 여러개일경우 동시에 시작해야하니 해당 시작점을 미리 넣어줘야한다 
//     {
//         for(int j = 0 ; j < M ; j++)
//         {
//             if(board[i][j] == 'J') 
//             {
//                 jihoon = {i, j};
//                 Q2.push({i,j});
//             }
//             if(board[i][j] == 'F') 
//             {
//                 firedist[i][j] = 0;
//                 Q1.push({i,j});
//             }
//         }
//     }
//     //fire부터 
//     //firedist[fire.X][fire.Y] = 0;
//     //Q.push({fire.X,fire.Y});
//     while(!Q1.empty())
//     {
//         pair<int,int> cur = Q1.front();Q1.pop();
//         for(int dir = 0 ; dir < 4 ; dir++)
//         {
//             int nx = cur.X + dx[dir];
//             int ny = cur.Y + dy[dir];
//             if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
//             if(board[nx][ny] == '#' || firedist[nx][ny] >= 0 ) continue;
//
//             firedist[nx][ny] = firedist[cur.X][cur.Y] + 1;
//             Q1.push({nx,ny});
//         }
//     }
//     for(int i = 0 ; i < N ;i++)
//     {
//         for(int j = 0 ; j < M ;j++)
//         {
//             cout << firedist[i][j] << " ";
//         }
//         cout << '\n';
//     }
//     int ans = 0;
//     dist[jihoon.X][jihoon.Y] = 0;
//     //Q.push({jihoon.X , jihoon.Y});
//     while(!Q2.empty())
//     {
//         pair<int,int> cur = Q2.front() ; Q2.pop();
//         for(int dir = 0; dir < 4 ; dir++)
//         {
//             int nx = cur.X + dx[dir];
//             int ny = cur.Y + dy[dir];
//             if(nx < 0 || ny < 0 || nx >= N || ny >= M )
//             {
//                 cout << dist[cur.X][cur.Y] + 1 << '\n';
//                 return 0;
//                 ans = dist[cur.X][cur.Y] + 1;
//             }
//             if(board[nx][ny] == '#' || dist[nx][ny] >= 0) continue;
//             if(firedist[nx][ny] != -1 && firedist[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;
//             dist[nx][ny] = dist[cur.X][cur.Y] + 1;
//             Q2.push({nx,ny}); 
//         }
//     }
//     for(int i = 0 ; i < N ;i++)
//     {
//         for(int j = 0 ; j < M ;j++)
//         {
//             cout << dist[i][j] << " ";
//         }
//         cout << '\n';
//     }
//     ans == 0 ? cout << "IMPOSSIBLE" : cout << ans ;
//     //cout << "IMPOSSIBLE" << '\n';
//     return 0;
// }

// BOJ 1697 숨바꼭질 ( BFS 선형)
// {
//     int moves[3] = { -1 , 1  , 2};
//     int board[100002];
//     int n , m;
//         ios::sync_with_stdio(0);
//         cin.tie(0);
//         cin >> n >> m;
//         if(n == m) // 0 예외처리 
//         {
//             cout << "0" << '\n';
//             return 0;
//         }
//         fill(board, board + 100001 , -1);
//         queue<int> Q;
//         board[n] = 0 ;
//         Q.push(n);
//         while(!Q.empty())
//         {
//             int cur = Q.front(); Q.pop();
//             for(int i = 0 ; i < 3 ; i++)
//             {
//                 int np = cur + moves[i];
//                 if(i == 2 ) np = cur * moves[i];
//                 if( np < 0 || np >= 100002) continue;
//                 if(board[np] != -1 ) continue;
//                 if(np == m )
//                 {
//                     cout << board[cur] + 1 << '\n';
//                     return 0;
//                 }
//                 board[np] = board[cur] + 1;
//                 Q.push(np);
//             }
//         }
//         return 0;
// }


//BOJ 11729 하노이 탑 이동순서 
void func ( int a , int b , int n)
{
    if( n == 1 ) // base condition 
    {
        cout << a << " " << b << '\n';
        return ;
    }
    func ( a , 6 -a -b , n-1); // 먼저 n -1 개를 a 와 b 가 아닌 기둥으로 옮기고 
    cout << a << " " << b << '\n'; // 그 다음 a 기둥의 제일 마지막 원판을 b 기둥으로 옮긴뒤 
    func( 6 -a - b , b , n-1); // a 와 b 가 아닌 기둥에 있는 n -1 개의 원판을 b 로 옮겨 준다 
}


int n , m;
#define X first
#define Y second

int dx[4] = {-1 , 1 , 0,0 };
int dy[4] = { 0 , 0 , 1, -1};

void recursion(int n)
{
    if( n > 0 )
    {
        cout << n << '\n';
        recursion( n -1 );
    }
    
}

int recursionPlus(int n)
{
    if(n==0) return 0;
    return n + recursionPlus(n -1 );
}

int main()
{   
        ios::sync_with_stdio(0);
        cin.tie(0);
        int k;
        cin >> k;
        
        func( 1 ,3 ,k);
        cout << (1 << k) -1 << '\n';
        return 0;






    
    
    





















    // vector<int> numbers;
    // cin >> N >> K;
    // int temp;
    // for(int i = 0 ; i < N ; i++)
    // {
    //     cin >> temp;
    //     numbers.push_back(temp);
    // }

    // sort(numbers.begin(), numbers.end());

    // for(auto n : numbers)
    // {
    //     cout << n << "  , " ;
    // }


    //     // 테스트 케이스 1
    // vector<vector<int>> dungeons1 = {{80, 20}, {50, 40}, {30, 10}};
    // int k1 = 80;
    // //int result1 = solution( dungeons1);
    // //cout << "Test Case 1: " << result1 << endl;

    // // 테스트 케이스 2
    // vector<vector<int>> dungeons2 = {{100, 10}, {200, 20}, {300, 30}};
    // int k2 = 500;
    // //int result2 = solution( dungeons2);
    // //cout << "Test Case 2: " << result2 << endl;

    // // 테스트 케이스 3
    // vector<vector<int>> dungeons3 = {{50, 30}, {100, 50}, {150, 20}};
    // int k3 = 200;
    // //int result3 = solution( dungeons3);
    // //cout << "Test Case 3: " << result3 << endl;

    // // 테스트 케이스 4
    // vector<vector<int>> dungeons4 = {{10, 5}, {20, 5}, {30, 5}, {40, 5}, {50, 5}};
    // int k4 = 100;
    // //int result4 = solution( dungeons4);
    // cout << "Test Case 4: "  << endl;


        
    //int M , N ;
    //cin >> N >> M;

    // BOJ 1978 소수찾기  에라토스테네스의 제 활용 
    // int answer = 0;
    // int check[1001] = { 0 };
    // // 0번째 1번째 index는 사용안함 , 소수와 배열 참조의 숫자를 같게하기위해서 
    // check[0] = check[1] = 1;
    // for(int i = 2 ; i <= sqrt(1000); i++)
    // {
    //     cout << " i : " << i << " check [i] " <<check[i] << endl;
    //     if(check[i] == 0)
    //     {   
    //         cout << i << endl;
    //         for(int j = i * i ; j <= 1000; j += i)
    //         {
    //             check[j] = 1;
    //         }
    //     }
    // }
    // for(int i = 0 ; i < numbers.size() ; i++)
    // {
    //     cout << "number : " << numbers[i] << " check is : " << check[numbers[i]] << endl;
    //     if(!check[numbers[i]])
    //     {
    //         answer++;
    //     }
    // }
    //cout << answer <<endl;




    // BOJ 1929 소수 구하기 에라토스테네스의 제 활용 
    //bool eratos[M+1];

    // for(int i = 0 ; i < M+1 ; i++) eratos[i] = true;
    
    // for(int i = 2; i < sqrt(M+1);i++)
    // {
    //     if(eratos[i])
    //     {
    //         for( int j = i*i; j <= M+1; j += i)
    //         {
    //             eratos[j]= false;
    //         }
    //     }
    // }
    // for(int i = N; i <= M ; i++)
    // {
    //     if(eratos[i]&& i != 1 && i != 0)
    //     cout << i << endl; 
    //     //answer.push_back(i);
    // }
    
    //int V = 3;
    //vector<vector<int>> cost = {{1,2,2},{1,3,1},{2,3,1}};

















    return 0;






}