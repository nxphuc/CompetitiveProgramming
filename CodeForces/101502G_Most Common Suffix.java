// Vo Anh Tuan
import java.util.*;
import java.io.*;

public class Main
{ 
    static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out), true);
    static Scanner in = new Scanner(System.in);
    static final int MAX = (int)1e5 + 10;
    
    static int max_suffix[] = new int[MAX];
    static String s;

    public static void main(String[] args) {
        int t, n, q, x;
	    String str;
        Node trie;
        t = in.nextInt();
        while (t-- > 0) {
                n = in.nextInt();
                q = in.nextInt();
                trie = new Node();
                for(int i = 0 ; i < MAX ; i++){
                    max_suffix[i] = 0;
                }
                s = in.nextLine();
                while (n-- > 0) {
                    s = in.nextLine();
                    str = new StringBuffer(s).reverse().toString();
                    trie.add(trie, str);
                }
                while (q-- > 0) {
                    x = in.nextInt();
                    out.printf("%d\n", max_suffix[x]);
                }
        }
    }
}

class Node {
    int cnt;
    Node[] child;
    public Node() {
        child = new Node[30];
        cnt = 0;
    }
    public void add(Node root, String s) {
        Node cur = root;
        int nxt;
        int len = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            char ch = s.charAt(i);
            len++;
            nxt = ch - 'a';
            if (cur.child[nxt] == null) {
                cur.child[nxt] = new Node();
            }
            cur = cur.child[nxt];
            cur.cnt++;
            max_suffix[len] = Math.max(max_suffix[len], cur.cnt);
        }
    }
};

class MyScanner {
    BufferedReader br;
    StringTokenizer st;

    public MyScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                    st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                    e.printStackTrace();
            }
        }
        return st.nextToken();
    }
    int nextInt() {
            return Integer.parseInt(next());
    }
    long nextLong() {
            return Long.parseLong(next());
    }
    double nextDouble() {
            return Double.parseDouble(next());
    }
    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}