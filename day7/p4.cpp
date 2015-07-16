/*

VC, GCC에서 사용

*/


// 첫 줄은 보석의 가지 수 N(1≤N≤1,000)과 배낭의 용량 
// W(1≤W≤10,000)가 주어진다. 둘째 줄부터 N+1줄에는 각 보석의 무게 Wi(1≤Wi≤W)와 값어치 Pi가 주어진다. (단, 각각의 보석의 개수는 무제한으로 가정한다.)

#include <stdio.h>
#define INT_SWAP(a,b){int t = a; a = b; b = t;};
#define FLOAT_SWAP(a,b){float t = a; a = b; b = t;};

int n, w;
float average[1010];
int gem[1010][2];
float max_average = 0;
int max_index;

void print_average(){
	printf("print average : \n");
	for(int i = 0; i < n; i++){
		printf("%.2f ", average[i]);
	}
	printf("\n");
}

void print_gem(){
	printf("print gem : \n");
	printf("n : \n");
	for(int i = 0; i < n; i++){
		printf("%d ", gem[i][0]);
	}
	printf("\n");
	printf("price : \n");
	for(int i = 0; i < n; i++){
		printf("%d ", gem[i][1]);
	}
	printf("\n");
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		
		scanf("%d %d", &n, &w);

		int result = 0;

		for(int i = 0; i < n; i++){
			scanf("%d %d", &gem[i][0], &gem[i][1]);
			average[i] = gem[i][1] / gem[i][0];
			// if(max_average < average[i]){
			// 	max_average = average[i];
			// 	max_index = i;
			// }
		}
		
		// print_gem();
		// print_average();
		for(int i = 0; i < n-1; i++){
			for(int j = 0; j < n-1-i; j++){
				if(average[j] < average[j+1]){
					FLOAT_SWAP(average[j], average[j+1]);
					INT_SWAP(gem[j][0], gem[j+1][0]);
					INT_SWAP(gem[j][1], gem[j+1][1]);
				}
			}
		}

		// print_gem();
		// print_average();


		for(int i = 0; i < n; i++){
			if(w == 0){
				break;
			}

			if(w >= gem[i][0]){
				result += (w / gem[i][0]) * gem[i][1];
				w = w % gem[i][0];
			}
			// else{
			// 	result += w * gem[i][1];
			// 	w = 0;
			// }

		}

		printf("%d\n",result);
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}