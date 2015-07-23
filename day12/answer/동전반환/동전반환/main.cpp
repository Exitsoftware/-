/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;

#define Nmax 10010

int N,M;
int A[Nmax];
int D[Nmax];

int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for(int itr=0; itr<nCount; itr++)
	{
		cin >> N;
		for(int i=0;i<N;i++) cin >> A[i];
		cin >> M;
		for(int i=0;i<=M;i++) D[i] = 0;

		D[0] = 1;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(j + A[i] > M) break;
				D[j + A[i]] += D[j];
				D[j + A[i]] %= 1000000007;
			}
		}
		cout << "#testcase" << (itr+1) << endl;
		cout << D[M] << endl;

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}