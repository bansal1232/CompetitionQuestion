import java.util.NavigableSet;
import java.util.Scanner;
import java.util.TreeSet;

class second {
    public static void main(String[] strings) {
        long mod = 1000000007, ans = 0;
        int num;
        Scanner scanner = new Scanner(System.in);
        NavigableSet<Integer> st = new TreeSet<>();
        int n = scanner.nextInt();
        for(int i=0; i<n; ++i){
            num = scanner.nextInt();
            st.add(num);
            Integer low = st.lower(num) , high = st.higher(num);
            long lw = (low == null) ? 0 : low;
            long hg = (high == null) ? 0 : high;
            ans =(ans + (lw * hg) % mod) % mod;

        }
        System.out.println(ans);
    }
}
