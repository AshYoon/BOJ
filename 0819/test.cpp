#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define MAX 8
using namespace std;




// 프로그래머스 level 2 피로도 ( 완전 탐색 , DFS , recursive ) 일부 case 만 통과 
// my code 
{
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
}


//answer code 
{
// int answer = 0;
// bool visited[MAX] = {0};

// void dfs(int cnt, int k, vector<vector<int>> &dungeons) {
//     if (cnt > answer) answer = cnt;
    
//     for (int i=0; i<dungeons.size(); i++) {
//         if (!visited[i] && dungeons[i][0] <= k) {
//             visited[i] = true;
//             dfs(cnt + 1, k - dungeons[i][1], dungeons);
//             visited[i] = false;
//         }
//     }
// }

// int solution(int k, vector<vector<int>> dungeons) {
//     dfs(0, k, dungeons);
    
//     return answer;
// }
}



// programmers lv2 brute force 모의고사 , solve 
//https://school.programmers.co.kr/learn/courses/30/lessons/42840
{
    vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a = 0 ,b =0,c=0;
    long long cnt1 = 0 ,cnt2 = 0 , cnt3 = 0;
    vector<int> first = { 1,2,3,4,5};
    vector<int> second = {2,1,2,3,2,4,2,5};
    vector<int> third = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i = 0 ; i< answers.size() ; i++)
    {
        

        if (a != 0 && i % first.size() == 0) a = 0;
        if (b != 0 && i % second.size() == 0) b = 0;
        if (c != 0 && i % third.size() == 0) c = 0;
        
        
        
        if(answers[i] == first[a]) cnt1++;
        
            
   
            
        
        if(answers[i] == second[b]) cnt2++;
        
        if(answers[i] == third[c]) cnt3++;
        
        
        

        a++;
        b++;
        c++;
        
    }
    
    
    
    int temp =max(max(cnt1,cnt2),cnt3);
    
    if( temp == cnt1 ) answer.push_back(1);
    if( temp == cnt2 ) answer.push_back(2);
    if( temp == cnt3 ) answer.push_back(3);
   
    
    
    
    return answer;
}
}



int N ;
long long K;
// 1 <= N <= 10 , 1 <= K <= 100,00,000
//둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다.
// (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)





int main()
{

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


        // 테스트 케이스 1
    vector<vector<int>> dungeons1 = {{80, 20}, {50, 40}, {30, 10}};
    int k1 = 80;
    int result1 = solution(k1, dungeons1);
    cout << "Test Case 1: " << result1 << endl;

    // 테스트 케이스 2
    vector<vector<int>> dungeons2 = {{100, 10}, {200, 20}, {300, 30}};
    int k2 = 500;
    int result2 = solution(k2, dungeons2);
    cout << "Test Case 2: " << result2 << endl;

    // 테스트 케이스 3
    vector<vector<int>> dungeons3 = {{50, 30}, {100, 50}, {150, 20}};
    int k3 = 200;
    int result3 = solution(k3, dungeons3);
    cout << "Test Case 3: " << result3 << endl;

    // 테스트 케이스 4
    vector<vector<int>> dungeons4 = {{10, 5}, {20, 5}, {30, 5}, {40, 5}, {50, 5}};
    int k4 = 100;
    int result4 = solution(k4, dungeons4);
    cout << "Test Case 4: " << result4 << endl;





    return 0;






}