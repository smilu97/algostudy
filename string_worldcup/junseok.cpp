/*컵이 세계 각지의 팀으로 열린다.

순위는 이긴 팀의 포인터의 수로 결정된다. 포인터는 일반적인 방법으로 결정이 된다.

경기에서 이긴다면 3 점의 포인터를 받는다.
경기에서 비긴다면 양팀은 1 점의 포인터를 받고
진다면 포인터가 없다.
팀의 수와 현재까지 치른 경기 수가 주어질 때 , 이 때까지의 경기에서 비긴 경기가 얼마나 될 지를 알아내는 것이다.
입력

첫 줄에 두 개의 정수 T 와 N 이 주어진다. T 는 팀의 수 이고 , N 은 경기 수 이다. ( 0 <= T <= 200 , 0 <= N <= 10000 )
다음 T 라인은 팀 이름 한 칸의 공백 현재 까지 이 팀이 얻은 포인터가 주어진다.

출력

비긴 경기 수를 출력한다.
입출력 예

입력

3 3
Brasil 3
Australia 3
Croacia 3

출력

0

입력

3 3
Brasil 5
Japao 1
Australia 1

출력

2
출처: South America 2006, Brazil Subregion*/

#include<iostream>

using namespace std;

int main(){
	int n,cnt;
	cin>>n>>cnt;

	char name[101];
	int p;	
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>name>>p;
		sum+=p;
	}
	
	cout<<3*n - sum<<endl;
	return 0;

}
 