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
	//ü���� �ٽ� ĥ�ϱ� 
	//M N ���� ������ ���簢������ ���������ִ�  M * N ũ���� ���� 
	// � �簢���������� or ��� , 8 x 8�� �߶� ���� 





	//19532
	////������ ���� ���� 
	////����������Ǯ��
	//// ���ڵ��� -999 ~ 999 ���� 
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

	// ������ , �ڿ��� N �� �������� M , M ��  N + N �� �����ϴ� �� �ڸ��� ���� 
	// ex ) 245 - > 245 + 2 + 4 + 5 = 256 , 256�� 245�� �������̸� 245�� 256 �� ������ 
	// �ڿ��� n �� �־����� �� N �� ���� ���� �����ڸ� ���ϱ� 
	// 256 �� �����ڸ� ���Ϸ��� , ?	

	//int targetnumb;
	//cin >> targetnumb;
	//int N = 0;
	//string temp = to_string(targetnumb);
	//int generateNumb = 0;
	//int answer = 0; //answer�� �ʱⰪ��  0 �����ؼ� �����ڰ����� ���� 0 ��return 
	//int a;
	//int test = 0;
	//while (N != targetnumb)
	//{

	//	int a = targetnumb - N; // ���� ���ڿ��� N ��ŭ �� 
	//	//cout << a << " , ";
	//	temp = to_string(a); // �� �ڸ��������ϱ����� to_string 
	//	for (int i = 0; i < temp.length(); i++) 
	//	{
	//		generateNumb += (int)temp[i] - 48; // �� �ڸ����� generateNumb�� ������ 
	//	}
	//	//cout << generateNumb;
	//	if (a + generateNumb == targetnumb) // ���� a + �� �ڸ��� �� targetNumb�Ͱ��ٸ� �����ڼ��ڶ�¶� 
	//	{
	//		answer = a; // ���� answer�� a �� 
	//	}
	//	//cout << " , " << N << endl;
	//	N++; // N�� ������Ű�鼭 �ݺ����� 
	//	generateNumb = 0;
	//	
	//}

	//cout << answer;







	//BaekJoon 2798�� ����
	// ������ ��� ����� ���� Ž���ϴ� ���� Ž������ 
	// ī���� ���� 21 �������ʴ��ѵ� ������ ���� ū���� �������� 
	// k ���� ���� ,�� ī��� ���������������ִ� ������ N ���� ī�带 ���ڰ� ���̰� �д� 
	//������ ���� M �� ��ģ�� , ���ѵȽð����� N ���� ī���� 3���� ���� 
	//�÷��̾ ��ī��� M �� ���������鼭 ���� M�� �������� ��������  , N ���� ī����� ���ڵ��� �־������� 
	// M�� ���� �����鼭 M �� ���� ����� ���� ����� ī�� 3�� ���ϱ� 
	// 3 <= N <= 100 , 10 <= M <= 300,000 , ��¶�ٿ��� �������ִ� ī���� ���� ��ī����Ǽ��ڴ� 100,000�� �������� 
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

	





	// �˰��� �ð����⵵ ���� 
	//long long a;
	//int A[100] = { 1 };
	//cin >> a;
	//cout << (a -2 ) * ( a -1 ) * a/6  << endl; // �ñ׸� �� ������ �ʿ��� ���� 
	//cout << 3 << endl;




	// BaekJoon 2720 

	// �Ž������� �ִ� ���α׷��ۼ� 
	// �Ž����� ������ ����( 0.25 ) , ���� ( 0.10 ) ,���� ( 0.05 ) ,��� ( 0.01 ) 
	// ������ ������ �ּҷ� , ex) 1.24 �� 4 ���� 2 ���� 4 ��� 
	// ù¶�ٿ� testcase ���� ���ڴ����� ��Ʈ , �� 100 ��Ʈ�� 1 �޷� �� ���ʹ� 25
	// �� ���̽��� �ʿ��� ���� , ���� , ����  , ����� ������ �������� �����ؼ� ��� 
	// C�� 1 �̻� 500 ���� 
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
	//		Q = 0, D = 0, N = 0, P = 0; // �ʱ�ȭ 
	//	}
	//	
	//}






	// ���� 2563�� 
	// 100 x 100 �� ��ȭ������ 10x 10 ������ ���̰� �����̸� ���� ���� ���ϱ� 
	// ���� ���� �Ʒ� �𼭸� �� ��ǥ�� �־��� 

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


















	// ���� ������ BaekJoon 25206
	//�����ϱ����� ������ �������� 3.3 �̻� ��� 
	// ���� ������ ( ���� x �������� ) �� ���� �������� ������ 
	// ��޿� ���� ����������
	// A+ (4.5) , A0(4.0) , B+(3.5) , B0(3.0), C+(2.5), C0(2.0) , D+(1.5), D0(1.0), F(0.0)
	// Pass . Fail ������ ��� P �Ǵ� F �� ǥ�õǴµ� P �� ������ ��꿡�� ���� F�� 0���� ����ϴµ� 
	// ������� ���� �� 1 �̻� 50���� 
	// ������� ���ĺ� ��ҹ��� �Ǵ� ���� �θ� , ������� , �Է������־����� ������� ���δٸ��� 

	// 20�ٿ� ���� ġ���̰� ������ ���������� ����� , ���� , ���������� �������� ���еǾ� �־��� 


	// ( ���� x �������� ) ���� ���� ������ �� ������ ������ 

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












	////�׷� �ܾ� üĿ 

	//// �׷�ܾ�� aabbcc ���� ���ӵ� ���ڰ� ��Ÿ���°� , aabbccb �̰Ǿƴ� 
	//// abhdckwa �̰͵� a �� ���������� ��Ÿ���Ƿ� x 
	//// ù�� �ٿ� n�� �־����� n �� ��ŭ�� �ܾ �־����� �̸� �ܾ check �ؾ��� 
	////  n ���� �ܾ check �ؾ��ϰ� n �� 100���� , 

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
	//		if (it != test.end()) // �ش�ܾ �ߺ��ܾ��ϰ��  
	//		{
	//			if (test.back() == c)//�ش� �ܾ ���ӵǾ��ٰ� �Ǵ��ϰ� c�� pushback ���� 
	//			{
	//				test.push_back(c);
	//			}
	//			else
	//			{
	//				groupword = false;
	//				break; // �ƴ϶��Ż�� 
	//			}
	//		}
	//		else if (it == test.end()) // �ش� �ܾ �ߺ��ܾ �ƴѰ�� 
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