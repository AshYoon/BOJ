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

// 3���� ���߹迭�� ���� 
// �ϳ��� map , �ٸ��ϳ��� �� ��庰�� dist�� ������ dist ���߹迭 , ���ϳ��� visited �ߴ������ߴ����� �����ϴ� visited ���߹迭 
// queue �� ���ۺκ��� �־ pop �ѵڿ� 
// �ش� pop ���� ���� �¿츦 �м��ؼ� , �����¿쿡 �����ִ� true ���� ��� Ȥ�� ������ �ִٸ� 
// queue �� push ���ְ� 
// �ٽ� queue �� pop �ؼ� �ٽ� �����¿� �м��ϰ� 
//



// �� �� �� �� 
int dx[4] = { 0 ,  0 , 1 , -1 };
int dy[4] = { 1 , -1 , 0 ,  0 };



// ť�� pair �� ���� 
queue <pair<int, int>> Q;

int solution(vector<vector<int> > maps)
{
    // ���� �����������ϴ°�� �ٷ� -1 return 
    if (maps[maps.size() - 2][maps[0].size() - 1] == 0 && maps[maps.size() - 1][maps[0].size() - 2] == 0) return -1;
    int answer = 0;




    int n = maps.size();
    // �ʱ�ȭ 
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false)); // �湮�� ��� check �迭 
    vector<vector<int>> distmap(maps.size(), vector<int>(maps[0].size(), 0)); // �Ÿ������� �׷��� 


    Print(maps);
    Print(distmap);
    Print(visited);
    distmap[0][0] = 1;
    visited[0][0] = true;
    Q.push({ 0 , 0 });

    while (!Q.empty()) // Q �� Empty �� Not  �϶��� while���� true 
    {
        pair <int, int> current = Q.front(); //������ġ�� Q.front() , �ڷ����� pair , auto �� �ᵵ ���ҵ� 
        Q.pop(); // Q . pop����  ���� front �� ���� ����

        for (int i = 0; i < 4; i++) //���� ��ġ �������� �����¿�� �˻� ���� 
        {
            // x�� 0 , y �� 0 �� 0 ,1 �̴ϱ� ������ġ 0,0���� + 0 ,1 �� �ؼ� �ش���ġ�� �Ÿ� 1 ��ŭ ����� ����Ű�Ե� 
            int nowX = dx[i] + current.first; 
            int nowY = dy[i] + current.second;

            if (nowX < 0 || nowY < 0 || nowX >= maps[0].size() || nowY >= maps.size())
                continue; // ���� nowX , nowY�� 0���� �۴ٸ� �ش簪�� �� ������� ����ũ�� ���� ���� skip ,or nowX,nowY�� �ش� �� �迭ũ�� �Ͱ��ų� �� ũ�ٸ� �� ������ ����Ե� skip 
            if (maps[nowX][nowY] == 0 || distmap[nowX][nowY] >= 1)
                continue; // maps �� �ش� �迭�� 0�̸� ���̶�¶��̹Ƿ� skip , or distmap�� nowX,nowY�� 1 �̻��ΰ�� �ش� ���� �̹� �湮�������ִٴ� ���̹Ƿ� skip

            Q.push({ nowX , nowY });  // �� �� ���ǿ��� skip�� �ȵǾ��ٸ� Queue �� �ش���ǥ�� �湮�� ������ ��ǥ�� push ���ְ� 
            distmap[nowX][nowY] = distmap[current.first][current.second] + 1; // �ش� ��ǥ , �� ���� ���ǿ� ����� Ž�� ��ǥ�� ���� ��ǥ���� + 1 �� ���־� �ش� ��ǥ������ �Ÿ��� ��Ÿ���� ���� �����


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
        else if (numbers.find(s) == string::npos) //��ã������� 
        {
            if (s == '6' || s == '9') // ã�� ���ڰ� 6 or 9 �ΰ�� 
            {
                if (s == '6')
                {
                    if (numbers.find('9') != string::npos) // 9�� �ִٸ�
                    {
                        numbers.erase(numbers.find('9'),1); // 9�� �ε����� ���� 
                    }
                    else
                    {
                        numbercnt++;

                    }
                }
                else if (s == '9')
                {
                    if (numbers.find('6') != string::npos) // 6�� �ִٸ�
                    {
                        numbers.erase(numbers.find('6'),1); // 6�� �ε����� ���� 
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

  //  //�������� , if ���� ==  date �� 
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