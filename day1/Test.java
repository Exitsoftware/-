/*

JAVA에서 사용

-import 사용
-package 금지

*/

import java.util.Scanner;

public class Test{

	public static void main(String[] args) {

		int nCount;		/* 문제의 테스트 케이스 */

		Scanner scan = new Scanner(System.in);

		nCount = scan.nextInt();		/* 테스트 케이스 입력 */

		for(int itr = 0 ; itr<nCount ;itr++) { 

 			System.out.println("#testcase" + (itr+1));


 			String input = scan.next();

 			
 			
 			char v = input.charAt(0);
 			int num = Integer.parseInt(input.substring(1, 2));
 			
 			String real_input = input.substring(2);
 			
 			int len = real_input.length();
 			char arr[] = new char[len];
 			
 			for(int i = 0; i < real_input.length(); i++){
 				arr[i] = real_input.charAt(i);
 			}
 			
 			if(v == 'L'){
 				for(int i = 0; i < num; i++){
 					char temp = arr[0];
 					for(int j = 0; j < len-1; j++){
 						arr[j] = arr[j+1];
 					}
 					arr[len-1] = temp;
 				}
 			}
 			else{
 				for(int i = 0; i < num; i++){
 					char temp = arr[len-1];
 					for(int j = len-1; j > 0; j--){
 						arr[j] = arr[j-1];
 					}
 					arr[0] = temp;
 				}
 			}
 			
 			for(int i = 0; i < len; i++){
 				System.out.print(arr[i]);
 			}
 			System.out.println();
			/*

			알고리즘이 들어가는 부분

			*/

		}
	}
}