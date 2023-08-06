#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;


int MenOfPassion(int A[], int n)
{
	int sum = 0;
	int count = 0;
	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = i+1; j <= n - 1; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
				sum = sum + A[i] * A[j] * A[k];
				count++;
			}
		}
	}
	return count;
}

void print(vector<int> v)
{
	for (auto n : v)
	{
		cout << n << " ,";
	}
}

int main()
{
	//1018
	//체스판 다시 칠하기 
	//M N 개의 단위로 정사각형으로 나누어져있는  M * N 크기의 보드 
	// 어떤 사각형은검은색 or 흰색 , 8 x 8로 잘라서 제작 





	//19532
	////수학은 비대면 강의 
	////연립방정식풀기
	//// 숫자들은 -999 ~ 999 사이 
	//int a, b, c, d, e, f;
	//cin >> a >> b >> c >> d >> e >> f;
	//// ax + by = c 
	//// dx + ey = f


	//for (int x = -999; x <= 999; x++)
	//{
	//	for (int y = -999; y <= 999; y++)
	//	{

	//		if (a * x + b * y == c && d * x + e * y == f)
	//		{
	//			cout << x << " " << y;

	//			break;
	//		}
	//	}
	//}





	// 2231 

	// 분해합 , 자연수 N 의 분해합은 M , M 는  N + N 을 구성하는 각 자리수 의합 
	// ex ) 245 - > 245 + 2 + 4 + 5 = 256 , 256은 245의 분해합이며 245는 256 의 생성자 
	// 자연수 n 이 주어질때 이 N 의 가장 작은 생성자를 구하기 
	// 256 의 생성자를 구하려면 , ?	

	//int targetnumb;
	//cin >> targetnumb;
	//int N = 0;
	//string temp = to_string(targetnumb);
	//int generateNumb = 0;
	//int answer = 0; //answer의 초기값은  0 으로해서 생성자가없는 수면 0 을return 
	//int a;
	//int test = 0;
	//while (N != targetnumb)
	//{

	//	int a = targetnumb - N; // 원래 숫자에서 N 만큼 뺌 
	//	//cout << a << " , ";
	//	temp = to_string(a); // 각 자리수를더하기위한 to_string 
	//	for (int i = 0; i < temp.length(); i++) 
	//	{
	//		generateNumb += (int)temp[i] - 48; // 각 자리수를 generateNumb에 더해줌 
	//	}
	//	//cout << generateNumb;
	//	if (a + generateNumb == targetnumb) // 만약 a + 각 자리수 가 targetNumb와같다면 생성자숫자라는뜻 
	//	{
	//		answer = a; // 따라서 answer는 a 고 
	//	}
	//	//cout << " , " << N << endl;
	//	N++; // N을 증가시키면서 반복진행 
	//	generateNumb = 0;
	//	
	//}

	//cout << answer;







	//BaekJoon 2798번 문제
	// 블랙잭의 모든 경우의 수를 탐색하는 완전 탐색문제 
	// 카드의 합이 21 을넘지않는한도 내에서 가장 큰수를 만들어야함 
	// k 버전 블랙잭 ,각 카드는 양의정수가쓰여있다 딜러는 N 장의 카드를 숫자가 보이게 분다 
	//딜러가 숫자 M 을 외친다 , 제한된시간동안 N 장의 카드중 3장을 고른다 
	//플레이어가 고른카드는 M 을 넘지않으면서 가장 M에 가까운수를 만들어야함  , N 장의 카드들의 숫자들이 주어졌을때 
	// M을 넘지 않으면서 M 에 가장 가까운 수를 만드는 카드 3장 구하기 
	// 3 <= N <= 100 , 10 <= M <= 300,000 , 둘쨋줄에는 씌여져있는 카드의 숫자 이카드들의숫자는 100,000를 넘지않음 
	//


	//int NumberOfCard;
	//int targetNumber;
	//cin >>NumberOfCard >>targetNumber;
	//vector <int> Cards;
	//int temp;
	//for (int i = 0; i < NumberOfCard; i++)
	//{
	//	cin >> temp;
	//	Cards.push_back(temp);
	//}
	//vector <int> blackjack;
	//int sum = 0;

	//for (int i = 0; i < NumberOfCard ; i++)
	//{

	//	for (int j = i + 1; j < NumberOfCard ; j++)
	//	{

	//		for (int k = j + 1; k < NumberOfCard; k++)
	//		{
	//			sum = Cards[i] + Cards[j] + Cards[k];
	//			if(sum <= targetNumber)
	//			blackjack.push_back(sum);
	//		}

	//	}
	//}

	//sort(blackjack.begin(), blackjack.end());
	//cout << blackjack.back() << endl;

	





	// 알고리즘 시간복잡도 측정 
	//long long a;
	//int A[100] = { 1 };
	//cin >> a;
	//cout << (a -2 ) * ( a -1 ) * a/6  << endl; // 시그마 합 공식이 필요한 문제 
	//cout << 3 << endl;




	// BaekJoon 2720 

	// 거스름돈을 주는 프로그램작성 
	// 거스름돈 종류는 쿼터( 0.25 ) , 다임 ( 0.10 ) ,니켈 ( 0.05 ) ,페니 ( 0.01 ) 
	// 동전의 갯수는 최소로 , ex) 1.24 면 4 쿼터 2 다임 4 페니 
	// 첫쨋줄에 testcase 개수 숫자단위는 센트 , 즉 100 센트는 1 달러 즉 쿼터는 25
	// 각 케이스에 필요한 쿼터 , 다임 , 니켈  , 페니의 갯수를 공백으로 구분해서 출력 
	// C는 1 이상 500 이하 
	//int numberofcase;
	//int change;
	//vector <int> changes;
	//cin >> numberofcase;
	//for (int i = 0; i < numberofcase; i++)
	//{
	//	cin >> change;
	//	changes.push_back(change);
	//	
	//}
	//string temp = "";
	//int Q = 0, D = 0, N = 0, P = 0;
	//for (int i = 0; i < changes.size(); i++)
	//{

	//	change = changes[i];
	//	Q = change/25;
	//	change %= 25;
	//	D = change / 10;
	//	change %= 10;
	//	N = change / 5;
	//	change %= 5;
	//	P = change / 1;
	//	change %= 1;
	//	if (change != 0) cout << "error : chagne is not 0 ";
	//	else
	//	{
	//		temp.clear();
	//		temp += to_string(Q), temp += " ", temp += to_string(D), temp += " ", temp += to_string(N), temp += " ", temp += to_string(P);
	//		cout << temp << endl;
	//		Q = 0, D = 0, N = 0, P = 0; // 초기화 
	//	}
	//	
	//}






	// 백준 2563번 
	// 100 x 100 의 도화지안의 10x 10 색종이 붙이고 색종이를 붙인 넓이 구하기 
	// 각각 왼쪽 아래 모서리 의 좌표가 주어짐 

	//int BPaper[100][100] = { 0 };
	//int numberofpaper = 0;
	//int answer = 0;
	//int x, y;
	//vector <pair<int, int>> paper;
	//cin >> numberofpaper;
	//for (int i = 0; i < numberofpaper; i++)
	//{
	//	cin >> x >> y;
	//	paper.push_back(make_pair(x, y));
	//}

	//for (int i = 0; i < paper.size(); i++)
	//{
	//	x = paper[i].first;
	//	y = paper[i].second;
	//	for (int j = y; j < y+10  ; j++)
	//	{
	//		for (int k = x ; k < x + 10; k++)
	//		{
	//			if (BPaper[j][k] != 1)
	//			{
	//				BPaper[j][k] = 1;
	//				answer++;
	//			}
	//		}
	//	}
	//}

	//cout << answer;


















	// 너의 평점은 BaekJoon 25206
	//졸업하기위한 평점은 전공평점 3.3 이상만 통과 
	// 전공 평점은 ( 학점 x 과목평점 ) 의 합을 총합으로 나눈값 
	// 등급에 따른 과목평점은
	// A+ (4.5) , A0(4.0) , B+(3.5) , B0(3.0), C+(2.5), C0(2.0) , D+(1.5), D0(1.0), F(0.0)
	// Pass . Fail 과목의 경우 P 또는 F 로 표시되는데 P 인 과목은 계산에서 제외 F는 0으로 계산하는듯 
	// 과목명의 길이 는 1 이상 50이하 
	// 과목명은 알파벳 대소문자 또는 숫자 로만 , 띄어쓰기없이 , 입력으로주어지는 과목명은 서로다르다 

	// 20줄에 걸쳐 치훈이가 수강한 전공과목의 과목명 , 학점 , 과목평점이 공백으로 구분되어 주어짐 


	// ( 학점 x 과목평점 ) 들의 합을 학점의 총 합으로 나눈것 

	//string input1;
	//float input2;
	//string input3;

	//double  SumScore = 0;
	//float SumGrade = 0;
	//double temp = 0;
	//for (int i = 0; i < 20; i++)
	//{
	//	cin >> input1 >> input2 >> input3;

	//	SumScore += input2;


	//	if (input3 == "A+") SumGrade += 4.5 * input2;
	//	else if (input3 == "A0") SumGrade += 4.0 * input2;
	//	else if (input3 == "B+") SumGrade += 3.5 * input2;
	//	if (input3 == "B0") SumGrade += 3.0 * input2;
	//	else if (input3 == "C+") SumGrade += 2.5 * input2;
	//	else if (input3 == "C0") SumGrade += 2.0 * input2;
	//	if (input3 == "D+") SumGrade += 1.5 * input2;
	//	else if (input3 == "D0") SumGrade += 1.0 * input2;
	//	else if (input3 == "F") SumGrade += 0.0 * input2;
	//	else if (input3 == "P") SumScore -= input2;

	//	
	//}

	//float a = SumGrade / SumScore;
	//cout << a;












	////그룹 단어 체커 

	//// 그룹단어란 aabbcc 같이 연속된 문자가 나타나는것 , aabbccb 이건아님 
	//// abhdckwa 이것도 a 가 동떨어져서 나타나므로 x 
	//// 첫쨰 줄에 n이 주어지고 n 줄 만큼의 단어가 주어지고 이를 단어를 check 해야함 
	////  n 개의 단어를 check 해야하고 n 은 100이하 , 

	//vector<string> words;
	//int answer = 0;

	//string temp = "";
	//int numberofword = 0;
	//cin >> numberofword;
	//for (int i = 0; i < numberofword; i++)
	//{
	//	cin >> temp;
	//	words.push_back(temp);
	//}


	//vector<char> test;
	//bool groupword = true;
	//for (int i = 0; i < numberofword; i++)
	//{
	//	string temp = words.back();
	//	words.pop_back();
	//	for (auto c : temp)
	//	{
	//		
	//		auto it = find(test.begin(), test.end(), c);
	//		if (it != test.end()) // 해당단어가 중복단어일경우  
	//		{
	//			if (test.back() == c)//해당 단어가 연속되었다고 판단하고 c를 pushback 해줌 
	//			{
	//				test.push_back(c);
	//			}
	//			else
	//			{
	//				groupword = false;
	//				break; // 아니라면탈출 
	//			}
	//		}
	//		else if (it == test.end()) // 해당 단어가 중복단어가 아닌경우 
	//		{
	//			test.push_back(c);
	//		}
	//	}

	//	if (groupword) answer++;

	//	test.clear();
	//	groupword = true;
	//}

	//cout << answer;




}