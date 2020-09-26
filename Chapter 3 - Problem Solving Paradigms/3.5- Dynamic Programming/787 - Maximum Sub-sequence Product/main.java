package com.company;
import java.math.BigInteger;
import java.util.*;

public class Main {
    private static final Scanner in = new Scanner(System.in);
    static long n;
    static ArrayList<Long> v = new ArrayList<>();

    public static void main(String[] args) {
        while (in.hasNextLong()) {
            n = in.nextLong();
            if (n == -999999L) {
                solve();
                v.clear();
                continue;
            }
            v.add(n);
        }
    }

    public static void solve() {
        BigInteger ans = new BigInteger("0");
        for (int j = 0; j < v.size(); j++) {
            BigInteger prod = new BigInteger("1");
            for (int i = j; i < v.size(); i++) {
                prod = prod.multiply(BigInteger.valueOf(v.get(i)));
                ans = prod.max(ans);
                if (prod.compareTo(BigInteger.valueOf(0)) == 0) {
                    prod = BigInteger.valueOf(1);
                }
            }
        }
        if (ans.compareTo(BigInteger.valueOf(0)) == 0) {
            if (v.size() == 1) {
                if (v.get(0) < 0) {
                    ans = BigInteger.valueOf(v.get(0));
                }
            }
        }
        System.out.println(ans);
    }
}

