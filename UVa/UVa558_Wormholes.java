import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;
import java.util.Scanner;

class Triad {
    private int source;
    private int target;
    private int weight;
    public Triad(int source, int target, int weight) {
        this.source = source;
        this.target = target;
        this.weight = weight;
    }
    public int getSource() {
        return this.source;
    } 
    public int getTarget() {
        return this.target;
    }
    public int getWeight() {
        return this.weight;
    }   
}

class FastReader {
    BufferedReader br;
    StringTokenizer st;

    public FastReader()
    {
        br = new BufferedReader(new
                InputStreamReader(System.in));
    }

    String next()
    {
        while (st == null || !st.hasMoreElements())
        {
            try
            {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt()
    {
        return Integer.parseInt(next());
    }

    long nextLong()
    {
        return Long.parseLong(next());
    }

    double nextDouble()
    {
        return Double.parseDouble(next());
    }

    String nextLine()
    {
        String str = "";
        try
        {
            str = br.readLine();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        return str;
    }
}

public class Main {    
    public static boolean BellmanFord(int source, ArrayList<Triad> graph, int[] dist) {
        int u, v, w;
        dist[source] = 0;
        for (int j=1; j<=dist.length-1; j++) { // For every node, examine all the edges again
            for (int l=0; l<graph.size(); l++) {
                u = graph.get(l).getSource();
                v = graph.get(l).getTarget();
                w = graph.get(l).getWeight();
                // Dist from source to node u + cost on edge u-v < Dist from source to node v (currently)
                if (dist[u] != Integer.MAX_VALUE && (dist[u] + w < dist[v])) {
                    dist[v] = dist[u] + w;
                    // path[v] = u; // save the path
                }
            }
        }
        // Test if there is a negative cycle
        for (int i=0; i<graph.size(); i++) {
            u = graph.get(i).getSource();
            v = graph.get(i).getTarget();
            w = graph.get(i).getWeight();
            if (dist[u] != Integer.MAX_VALUE && (dist[u] + w < dist[v])) {
                return false;
            } 
        }
        return true;
    }
    
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            t--;
            int n = sc.nextInt();
            int m = sc.nextInt();
            
            ArrayList<Triad> graph = new ArrayList<Triad>();
            int[] dist = new int[n];
            Arrays.fill(dist, Integer.MAX_VALUE);
            
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                int w = sc.nextInt();
                graph.add(new Triad(u, v, w));
            }
            if (BellmanFord(0, graph, dist) == false) {
                System.out.println("possible");
            }
            else {
                System.out.println("not possible");
            }
        }
    }
}