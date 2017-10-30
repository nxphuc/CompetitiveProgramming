import java.util.Scanner;

public class Main {
	public static String lowerBound(int[] a, int left, int right, int x) {
		int mid = 0;
		int result = -1;
		
		while (right >= left) {
			mid = left + (right - left)/2;
			
			// mid có thể là 1 đáp án
			if (a[mid] < x){
				result = mid;
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		
		if (result == -1)
			return "X";
		return a[result] + "";
	}
	
	public static String upperBound(int[] a, int left, int right, int x) {
		int mid = 0;
		int result = -1;
		
		while (right >= left) {
			mid = left + (right - left)/2;
			
			// mid có thể là 1 đáp án
			if (a[mid] > x){
				result = mid;
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		
		if (result == -1)
			return "X";
		return a[result] + "";
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int[] a = new int[n];
		
		for (int i=0;i<n;i++) {
			a[i] = in.nextInt();
		}
		
		int q = in.nextInt();
		for (int i=0;i<q;i++) {
			int x = in.nextInt();
			System.out.println(lowerBound(a, 0, a.length-1, x) + " " + upperBound(a, 0, a.length-1, x));
		}
		
		in.close();
	}
}