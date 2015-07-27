/*

VC, GCC에서 사용

*/

#include <stdio.h>

int count, people;
int arr[50000];

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		scanf("%d %d", &count, &people);
		int max;
		for(int i = 0; i < count; i++){

			scanf("%d", &arr[i]);

			if(i == 0){
				max = arr[i];
			}
			if(max < arr[i]){
				max = arr[i];
			}
		}

		int d1 = max;
		int d2 = 0;
		int d3 = (d1+d2)/2;
		int res;
		while(1){
			// printf("d1 %d d2 %d d3 %d\n", d1, d2, d3);
			res = 0;
			for(int i = 0; i < count; i++){
				res += arr[i]/d3;
			}
			if(res > people){

				d2 = d3;
				d3 = (d1+d2)/2;
			}
			else if(res < people){

				d1 = d3;
				d3 = (d1+d2)/2;
			}
			// if(res == people){
			// 	break;
			// }
			if(d1 == d3 || d3 == d2){
				break;
			}
			if(res == people){
				d3++;
				break;
			}
		}

		printf("%d\n", d3);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}