import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    public static class TempArray {
        private int TempSize;
        private int Size;
        private List<int[]> Temp;
        private int[] Array;

        public TempArray(int TempSize, int Size) {
            this.TempSize = TempSize;
            this.Size = Size;
            Temp = new ArrayList<int[]>();
            if (TempSize < 1) {
                return;
            }

            this.Array = new int[Size];
            for (int i = 0; i < Size; i++) {
                Array[i] = i;
            }

            for (int i = 0; i <= Size - TempSize; i++) {
                int[] combo = new int[TempSize];
                combo[0] = Array[i];
                setNewItem(i + 1, combo, 1);
            }
        }

        private void setNewItem(int pos, int[] combo, int height) {
            if (height >= this.TempSize) {
                Temp.add(combo);
                return;
            }
            for (int p = pos; p <= Size - TempSize + height; p++) {
                int[] newCombo = combo.clone();
                newCombo[height] = Array[p];
                setNewItem(p + 1, newCombo, height + 1);
            }
        }

        public List<int[]> getSubArrays() {
            return Temp;
        }
    }

    private int[] notUsed(int size, int[] idx) {
        if (idx.length >= size)
            return new int[0];

        int[] a = new int[size];
        for (int i = 0; i < size; i++)
            a[i] = i;

        Set<Integer> used = new HashSet<Integer>();
        for (Integer u : idx)
            used.add(u);

        int cnt = 0;
        int[] other = new int[a.length - idx.length];

        for (int i = 0; i < a.length; i++)
            if (!used.contains(a[i]))
                other[cnt++] = a[i];

        return other;
    }

    private void thisForm(double[][] A, double[] B, double[][] thisForm, double[] currFormBudget, int[] idx) {
        for (int i = 0; i < idx.length; i++) {
            if (idx[i] < A.length) {
                thisForm[i] = Arrays.copyOf(A[idx[i]], A[i].length);
                currFormBudget[i] = B[idx[i]];
            }
            else if (idx[i] == A.length + A[0].length) {
                Arrays.fill(thisForm[i], 1);
                currFormBudget[i] = 1e9;
            }
            else
                thisForm[i][idx[i] - A.length] = -1;
        }
    }

    private int dolver(int n, int m, double A[][], double[] B, double[] P, double[] ans) {
        Double maxVal = Double.NaN;

        double[] solution = new double[m];

        List<int[]> subSets = new TempArray(m, n + m + 1).getSubArrays();
        for (int[] combo : subSets) {
            double[][] cur = new double[m][m];
            double[] curBudget = new double[m];
            thisForm(A, B, cur, curBudget, combo);
            double[] cand;

            try {
                cand = gauss(cur, curBudget);
            } catch (Exception e) {
                continue;
            }

            int[] notUsed = notUsed(n + m + 1, combo);
            cur = new double[notUsed.length][m];
            curBudget = new double[notUsed.length];
            thisForm(A, B, cur, curBudget, notUsed);

            if (check(cand, cur, curBudget)) {
                double max = max(cand, P);
                if (maxVal.isNaN() || max > maxVal) {
                    maxVal = max;
                    solution = Arrays.copyOf(cand, cand.length);
                }
            }

        }

        if (maxVal.isNaN()) {
            return -1;
        }
        if (maxVal > 1e9 - 10) {
            return 1;
        }

        for (int i = 0; i < m; i++) {
            ans[i] = solution[i];
        }

        return 0;
    }

    private double max(double[] solutionCandidate, double[] P) {
        double maxVal = 0;
        for (int i = 0; i < solutionCandidate.length; i++)
            maxVal += solutionCandidate[i] * P[i];

        return maxVal;
    }

    private boolean check(double[] sol, double[][] A, double[] B) {
        for (int i = 0; i < A.length; i++) {
            double fi = 0;
            double se = B[i];

            for (int j = 0; j < sol.length; j++)
                fi += sol[j] * A[i][j];

            if (fi > se)
                return false;
        }
        return true;
    }

    public static double[] gauss(double A[][], double[] b) {
        int size = A[0].length;
        for (int p = 0; p < size; p++) {
            int max = p;

            for (int i = p + 1; i < size; i++)
                if (Math.abs(A[i][p]) > Math.abs(A[max][p]))
                    max = i;

            if (Math.abs(A[max][p]) <= 1e-5) {
                throw new IllegalArgumentException();
            }
            double[] temp = A[p];
            A[p] = A[max];
            A[max] = temp;

            double t = b[p];
            b[p] = b[max];
            b[max] = t;

            for (int i = p + 1; i < size; i++) {
                double a = A[i][p] / A[p][p];
                b[i] -= a * b[p];
                for (int j = p; j < size; j++)
                    A[i][j] -= a * A[p][j];
            }
        }

        double[] solution = new double[size];
        for (int i = size - 1; i >= 0; i--) {
            double sum = 0.0;
            for (int j = i + 1; j < size; j++)
                sum += A[i][j] * solution[j];

            solution[i] = (b[i] - sum) / A[i][i];
        }

        return solution;
    }

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();

        double[][] A = new double[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                A[i][j] = nextInt();

        double[] B = new double[n];
        for (int i = 0; i < n; i++)
            B[i] = nextInt();

        double[] P = new double[m];
        for (int i = 0; i < m; i++)
            P[i] = nextInt();

        double[] ans = new double[m];

        int sol = dolver(n, m, A, B, P, ans);
        if (sol == -1) {
            out.printf("No solution\n");
        }
        else if (sol == 0) {
            out.printf("Bounded solution\n");
            for (int i = 0; i < m; i++) {
                out.printf("%.18f%c", ans[i], ' ');
            }
        }
        else{
            out.printf("Infinity\n");
        }
        return;
    }

    public static void main(String[] args) throws IOException {
        new Main();
    }

    Main() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    private BufferedReader br;
    private PrintWriter out;
    private StringTokenizer st;

    private String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                return null;
            }
        }
        return st.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
}