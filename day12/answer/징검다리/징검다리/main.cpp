/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;

#define Nmax 10010

int N;
int A[Nmax];
int D[Nmax];

int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for(int itr=0; itr<nCount; itr++)
	{
		cin >> N;
		for(int i=1;i<=N;i++){
			cin >> A[i];
			D[i] = 0;
		}

		A[N+1] = D[N+1] = 0;

		for(int i=1;i<=N+1;i++){
			D[i] = D[i-1];
			if(i > 1 && D[i] > D[i-2]) D[i] = D[i-2];
			if(i > 2 && D[i] > D[i-3]) D[i] = D[i-3];
			D[i] += A[i];
		}

		cout << "#testcase" << (itr+1) << endl;
		cout << D[N+1] << endl;

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}