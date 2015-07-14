/*

VC, GCC에서 사용

*/

#include <stdio.h>

int arr[200000][2];


int get_gcd(int x, int y){
	int t = x;
	x = y;
	y = t % y;
	if(y == 0){
		return x;
	}
	return get_gcd(x,y);
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		long int num = 0;
		int w,h;
		scanf("%d %d", &w, &h);
		int x, y;
		int a, b;
		scanf("%d %d", &x, &y);
		scanf("%ld", &num);
		
		
		int temp_x = x, temp_y = y;
		int temp = 0;

		a = 1;
		b = 1;

		int count = 0;

		// int gcd = get_gcd(w,h);
		// int lcm = (w*h)/gcd;

		// if(num > 100000){
		// 	printf("1 1\n");
		// 	continue;
		// }

		// if((w % 2 == 0 && h % 2 == 0) || (w%h != 0)){
		// 	lcm += lcm;
		// }
		// printf("lcm =%d\n", lcm);
		for(int i = 0; i < num; i++){
			
			arr[i][0] = x;
			arr[i][1] = y;

			if(temp_x == x && temp_y == y && a == 1 && b== 1 && count != 0){
				temp = count;
				// printf("count = %d\n", count);
				break;
			}

			x += a;
			y += b;

			if(x == w || x == 0){
				a *= -1;
			}

			if(y == h || y == 0){
				b *= -1;
			}

			

			count++;

		}

		// if(temp != 0){
		// 	for(int i = 0; i < num % temp; i++){
		// 		x += a;
		// 		y += b;

		// 		if(x == w || x == 0){
		// 			a *= -1;
		// 		}

		// 		if(y == h || y == 0){
		// 			b *= -1;
		// 		}

		// 	}
		// }
		// printf("%d %d\n", x,y);

		if(temp == 0){
			printf("%d %d\n", x,y);
		}
		else{
			printf("%d %d\n", arr[num%temp][0],arr[num%temp][1]);
		}


	}



	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}