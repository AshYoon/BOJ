#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

//#define A@B (A+B)*(A-B);


void Print(vector <vector<int>>& graph)
{
    for (auto v1 : graph)
    {
        for (auto v2 : v1)
        {
            cout << v2 << " ,";
        }
        cout << endl;
    }
}

void Print(vector <vector<bool>>& graph)
{
    for (auto v1 : graph)
    {
        for (auto v2 : v1)
        {
            cout << v2 << " ,";
        }
        cout << endl;
    }
}

// 3개의 이중배열이 있음 
// 하나는 map , 다른하나는 각 노드별로 dist를 저장한 dist 이중배열 , 또하나는 visited 했는지안했는지를 저장하는 visited 이중배열 
// queue 에 시작부분을 넣어서 pop 한뒤에 
// 해당 pop 값의 상하 좌우를 분석해서 , 상하좌우에 갈수있는 true 값의 노드 혹은 정점이 있다면 
// queue 에 push 해주고 
// 다시 queue 에 pop 해서 다시 상하좌우 분석하고 
//



// 상 하 좌 우 
int dx[4] = { 0 ,  0 , 1 , -1 };
int dy[4] = { 1 , -1 , 0 ,  0 };



// 큐를 pair 로 선언 
queue <pair<int, int>> Q;

int solution(vector<vector<int> > maps)
{
    // 만약 도달하지못하는경우 바로 -1 return 
    if (maps[maps.size() - 2][maps[0].size() - 1] == 0 && maps[maps.size() - 1][maps[0].size() - 2] == 0) return -1;
    int answer = 0;




    int n = maps.size();
    // 초기화 
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false)); // 방문한 노드 check 배열 
    vector<vector<int>> distmap(maps.size(), vector<int>(maps[0].size(), 0)); // 거리측정용 그래프 


    Print(maps);
    Print(distmap);
    Print(visited);
    distmap[0][0] = 1;
    visited[0][0] = true;
    Q.push({ 0 , 0 });

    while (!Q.empty()) // Q 가 Empty 가 Not  일때만 while문이 true 
    {
        pair <int, int> current = Q.front(); //현재위치는 Q.front() , 자료형은 pair , auto 를 써도 편할듯 
        Q.pop(); // Q . pop으로  기존 front 의 값을 삭제

        for (int i = 0; i < 4; i++) //현재 위치 기준으로 상하좌우로 검사 시작 
        {
            // x에 0 , y 의 0 은 0 ,1 이니깐 현재위치 0,0에서 + 0 ,1 을 해서 해당위치의 거리 1 만큼 상단을 가르키게됨 
            int nowX = dx[i] + current.first; 
            int nowY = dy[i] + current.second;

            if (nowX < 0 || nowY < 0 || nowX >= maps[0].size() || nowY >= maps.size())
                continue; // 만약 nowX , nowY가 0보다 작다면 해당값은 맵 사이즈보다 작은크기 가됨 따라서 skip ,or nowX,nowY가 해당 맵 배열크기 와같거나 더 크다면 맵 범위를 벗어난게됨 skip 
            if (maps[nowX][nowY] == 0 || distmap[nowX][nowY] >= 1)
                continue; // maps 의 해당 배열이 0이면 벽이라는뜻이므로 skip , or distmap에 nowX,nowY가 1 이상인경우 해당 노드는 이미 방문한적이있다는 뜻이므로 skip

            Q.push({ nowX , nowY });  // 위 의 조건에서 skip이 안되었다면 Queue 에 해당좌표는 방문이 가능한 좌표니 push 해주고 
            distmap[nowX][nowY] = distmap[current.first][current.second] + 1; // 해당 좌표 , 즉 위의 조건에 통과한 탐색 좌표는 현재 좌표값의 + 1 을 해주어 해당 좌표까지의 거리를 나타내는 맵을 만든다


        }

    }


    if (distmap[maps[0].size() - 1][maps.size() - 1] == 0)
    {
        return -1;
    }
    else
    {
        return distmap[maps[0].size() - 1][maps.size() - 1];
    }
}


struct person
{
    int date;
    int age;
    string name;
};

bool compare(person prev , person next)
{
    if (prev.age == next.age)
    {
        return prev.date < next.age ? true : false;
    }
    
    return prev.age < next.age;
}


vector<person> personSort(vector <person> data)
{

    std::sort(data.begin(), data.end() , compare);

    return data;
}

bool compare2(string prev, string next)
{
    int a, b;
    string temp = "";
    stringstream ss;
    ss.str(prev);
    while (ss >> temp)
    {
         a = stoi(temp);
        break;
    }
    ss.clear();
    temp.clear();
    ss.str(next);


    while (ss >> temp)
    {
         b = stoi(temp);
        break;
    }

    return a < b;


}


int codetest2(int a)
{
    string numbers = "0123456789";
    int numbercnt = 1;
    string temp = to_string(a);
    for (auto s : temp)
    {
       
        if (numbers.find(s) != string::npos)
        {
            numbers.erase(numbers.find(s),1);
        }
        else if (numbers.find(s) == string::npos) //못찾았을경우 
        {
            if (s == '6' || s == '9') // 찾는 숫자가 6 or 9 인경우 
            {
                if (s == '6')
                {
                    if (numbers.find('9') != string::npos) // 9가 있다면
                    {
                        numbers.erase(numbers.find('9'),1); // 9의 인덱스를 삭제 
                    }
                    else
                    {
                        numbercnt++;

                    }
                }
                else if (s == '9')
                {
                    if (numbers.find('6') != string::npos) // 6가 있다면
                    {
                        numbers.erase(numbers.find('6'),1); // 6의 인덱스를 삭제 
                    }
                    else
                    {
                        numbercnt++;

                    }
                }
            }
            else
            {
                numbercnt++;

            }
        }
    }

    return numbercnt;

}




int main()
{
  //  vector <vector<int>> maps = { {1, 0, 1, 1, 1} ,{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1 } };

  //  



  ////  cout << solution(maps) << endl;

  //  //오름차순 , if 나이 ==  date 비교 
  //  person a = { 20230505 , 28 , "kjy" };
  //  person c = { 20230630 , 29 , "jjg" };
  //  person d = { 20230630 , 31 , "ccd" };
  //  person b = { 20220404 , 33 , "ddc" };
  //  person h = { 20231223 , 36 , "abc" };
  //  person z = { 20220304 , 40 , "dda" };


  //  vector <person> database = { z ,h ,b ,d ,c,a };
  //  for (int i = 0; i < database.size(); i++)
  //  {
  //      cout << database[i].name << " ," << database[i].age << " ," << database[i].date << endl;
  //  }

  //  cout << " ------------------------------------------ " << endl;

  //  vector <person> sortperson = personSort(database);

  //  for (int i = 0; i < sortperson.size(); i++)
  //  {
  //      cout << sortperson[i].name << " ," << sortperson[i].age << " ," << sortperson[i].date << endl;
  //  }

  //  cout << " --------------------- " << endl;
  //  vector <string> test = { "21 Junkyu" , "21 Dohyun","20 Sunyoung" };
  //  sort(test.begin(), test.end(), compare2);
  //  for (auto v : test)
  //  {
  //      cout << v << endl;
  //  }


  //  cout << codetest2(9999) << endl; 


    string alphabets = "testcases";
    vector<pair<char, int>> answer;
    for (auto c : alphabets)
    {
        auto iter = find(alphabets.begin(), alphabets.end(), c);
        if(auto iter)
    }

   

}