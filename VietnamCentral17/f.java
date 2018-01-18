package javacode;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        InputReader reader = new InputReader(System.in);
        List<BigInteger> f = new ArrayList<BigInteger>();
        f.add(BigInteger.ONE);
        f.add(BigInteger.ONE);
        int n = reader.nextInt();
        n -= 1;
        for (int i = 2; i <= n; i++) {
            f.add(f.get(i - 1).add(f.get(i-2)));
        }
        System.out.println(f.get(n).pow(n+1));
    }
}

/** Faster input **/
class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}