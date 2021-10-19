
import java.util.*;
import java.io.*;

public class hangglide {
    public static void main(String[] Args) throws Exception {
        FS sc = new FS(System.in);
        int n = sc.nextInt(); // events
        int m = sc.nextInt(); // pilots
        Event[] events = new Event[n<<1];
        for (int i = 0; i < n; i++) {
            int s = sc.nextInt();
            int e = sc.nextInt();
            int score = sc.nextInt();
            events[(i<<1)] = new Event(i, s, true, score);
            events[(i<<1)|1] = new Event(i, e, false, score);
        }
        Arrays.sort(events);
        double[] anss = new double[n];
        double[] score = new double[n];
        Pilot[] pilots = new Pilot[m];
        for (int i = 0; i < m; i++) {
            double ans = 0;

            for (int j = 0; j < n; j++)
                score[j] = sc.nextDouble();

            for (int j = 0; j < (n<<1); j++) {
                if (!events[j].isStart) {
                    if (anss[events[j].ind] > ans) 
                        ans = anss[events[j].ind];
                } else
                    anss[events[j].ind] = ans + score[events[j].ind] * events[j].score;
            }

            pilots[i] = new Pilot(i + 1, ans);
        }
        Arrays.sort(pilots);
        for (int i = 0; i < 3; i++) {
            Pilot p = pilots[i];
            System.out.printf("%d %.2f%n", p.ind, p.score);
        }
    }

    public static class Pilot implements Comparable<Pilot>{
        int ind;
        double score;
        Pilot(int ii, double ss) {
            ind = ii;
            score = ss;
        }
        public int compareTo(Pilot o) {
            return Double.compare(o.score, score);
        }
    }

    public static class Event implements Comparable<Event>{
        int ind;
        boolean isStart;
        int time;
        int score;
        Event(int ii, int tt, boolean st, int sc) {
            ind = ii;
            time = tt;
            isStart = st;
            score = sc;
        }
        public int compareTo(Event o) {
            if (time != o.time)
                return Double.compare(time, o.time);
            if (o.isStart != isStart)
                return isStart ? 1 : -1;
            return 0;
        }
        public String toString() {
            return (isStart ? "S" : "E") + " " +  ind + " " + score;
        }
    }

    public static class FS {
        BufferedReader br;
        StringTokenizer st;
        FS(InputStream in) throws Exception{
            br = new BufferedReader(new InputStreamReader(in));
            st = new StringTokenizer(br.readLine());
        }
        String next() throws Exception {
            if (st.hasMoreTokens())
                return st.nextToken();
            st = new StringTokenizer(br.readLine());
            return next();
        }
        int nextInt() throws Exception {
            return Integer.parseInt(next());
        }
        double nextDouble() throws Exception {
            return Double.parseDouble(next());
        }
    }
}