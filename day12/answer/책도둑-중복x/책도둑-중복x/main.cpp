/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;

#define Nmax 110

int N,M;
int A[Nmax][2],Answer;
int D[10010];

int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for(int itr=0; itr<nCount; itr++)
	{
		cin >> N >> M;
		for(int i=0;i<N;i++) cin >> A[i][0] >> A[i][1];

		Answer = 0;
		for(int i=0;i<=M;i++) D[i] = 0;
		for(int i=0;i<N;i++){
			for(int j=M;j>=0;j--){
				if(D[j] == 0) continue;
				if(D[j + A[i][0]] < D[j] + A[i][1]) D[j + A[i][0]] = D[j] + A[i][1];
			}
			if(D[A[i][0]] < A[i][1]) D[A[i][0]] = A[i][1];
		}
		for(int i=0;i<=M;i++){
			if(D[i] > Answer) Answer = D[i];
		}
		cout << "#testcase" << (itr+1) << endl;
		cout << Answer << endl;

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}