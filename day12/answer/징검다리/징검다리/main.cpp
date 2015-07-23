/*

VCPP, GPP���� ���

*/

#include <iostream>
using namespace std;

#define Nmax 10010

int N;
int A[Nmax];
int D[Nmax];

int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

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

		�˰����� ���� �κ�

		*/

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */ 

}