/*

VCPP, GPP���� ���

*/

#include <iostream>
using namespace std;

#define Nmax 1000010

int N,A,B,C;
int D[Nmax][4];

int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for(int itr=0; itr<nCount; itr++)
	{
		cin >> A >> B >> C >> N;

		for(int i=0;i<=N;i++){
			for(int j=0;j<5;j++) D[i][j] = 0;
		}

		D[0][0] = 1;
		for(int i=1;i<=N;i++){
			D[i][1] = D[i-1][1] + D[i-1][0];
			if(i - A > -1) D[i][1] -= D[i-A][0];
			if(i - A > -1) D[i][2] = D[i-A][0] + D[i-1][2];
			if(i - B > -1) D[i][2] -= D[i-B][0];
			if(i - B > -1) D[i][3] = D[i-B][0] + D[i-1][3];
			if(i - C > -1) D[i][3] -= D[i-C][0];
			D[i][0] = D[i][2];
			for(int j=0;j<5;j++){
				D[i][j] %= 1000;
				if(D[i][j] < 0) D[i][j] += 1000;
			}
		}

		cout << "#testcase" << (itr+1) << endl;
		cout << (D[N][0] + D[N][1] + D[N][2] + D[N][3]) % 1000 << endl;
		/*

		�˰����� ���� �κ�

		*/

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */ 

}