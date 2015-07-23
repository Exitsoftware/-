/*

VCPP, GPP���� ���

*/

#include <iostream>
using namespace std;

#define Nmax 10010

int N,M;
int A[Nmax];
int D[Nmax];

int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

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

		�˰����� ���� �κ�

		*/

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */ 

}