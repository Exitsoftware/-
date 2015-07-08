/*

VC, GCC에서 사용

*/

#include <stdio.h>

int len(int num){
	int count = 0;
	while(num != 0){
		num /= 10;
		count++;
	}
	return count;
}


int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		int input;

		scanf("%d",&input);
		// printf("%d\n", len(input));
		int temp_input = input;
		// int end_num = temp_input % 10;
		// int temp_num;
		// temp_input /= 10;



		int arr[100000];

		for(int i = 0; i < len(input); i++){
			arr[i] = temp_input%10;
			temp_input /= 10;
			
		}

		bool sw = false;
		int count = len(input)-1;
		for(int k = 0; k < len(input); k++){
			for(int i = 0; i < count; i++){

				if(arr[i] > arr[i+1]){
					int temp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = temp;
					sw = true;
					count = i;
					break;
				}
			}
		}

		// printf("count = %d\n", count);

		// for(int i = 0; i < len(input); i++){
		// 	printf("%d ", arr[i]);
		// }
		// printf("\n");


		// for(int i = 0; i < len(input); i++){
		// 	printf("%d", arr[i]);
		// }

		// printf("\n");



		if(sw){

			for (int i = len(input) - 1; i >= 0; i--)
			{
				printf("%d", arr[i]);
			}
			printf("\n");

		}
		else{
			printf("0\n");
		}
		// for(int i = len(input); i > 0; i--){
		// 	printf("%d", arr[i]);
		// }


		// while(1){
		// 	temp_num = temp_input % 10;
		// 	temp_input /= 10;	
		// 	if(end_num > temp_num){
		// 		int temp = end_num;
		// 		end_num = temp_num;
		// 		temp_num = temp;

		// 		break;	
		// 	}
		// 	else if(temp_input == 0){
		// 		printf("0\n");
		// 		break;
		// 	}

		// }





		/*

		알고리즘이 들어가는 부분

		*/

	}


	3333347998
	3333347989
	3333348997

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}