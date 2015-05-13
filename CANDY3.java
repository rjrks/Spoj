


import java.util.Scanner;

 class CANDY3 {

	static Scanner in = new Scanner(System.in);

		
	public static void main(String[] args) {
	
		int tc;
		tc=in.nextInt();
		
		while(tc!=0){
		long  n;
		n=in.nextLong();
		
		long inp=0;
		
		for(int i=1;i<=n;i++){
			
			 inp+=in.nextLong();
			 inp%=n;
		}
		
		if(inp==0)System.out.println("YES");
		else System.out.println("NO");
		
	
		tc--;
	
		}
		
	}
	
	
}
