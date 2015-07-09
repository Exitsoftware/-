/*

JAVA에서 사용

-import 사용
-package 금지

*/

import java.util.Scanner;
class Que{
		char data[] = new char[10000];
		int front = 0;
		int rear = 0;

		// Queue(){

		// }
		void enqueue(char n){
			data[rear++] = n;
		}

		char dequeue(){
			front++;
			return data[front-1];
		}

		boolean empty(){
			return front == rear;
		}


	}


public class Test{

	
	public static void main(String[] args) {

		int nCount;		/* 문제의 테스트 케이스 */

		Scanner scan = new Scanner(System.in);

		nCount = scan.nextInt();		/* 테스트 케이스 입력 */

		for(int itr = 0 ; itr<nCount ;itr++) { 

			System.out.println("#testcase" + (itr+1));

			int num = scan.nextInt();

			Que q = new Que();
			boolean sw = true;

			for(int i = 0; i < num; i++){
				String s = scan.next();
				char temp = s.charAt(0);

				if(temp == '-'){
					if(!q.empty()){
						q.dequeue();
					}
					else{
						System.out.println("error!");
						sw = false;
						break;
					}
				}
				else{
					q.enqueue(temp);
				}
			}

			while(!q.empty() && sw){
				System.out.println(q.dequeue());
			}
			/*

			알고리즘이 들어가는 부분

			*/

		}
	}
}