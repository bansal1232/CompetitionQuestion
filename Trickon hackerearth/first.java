import java.util.HashMap;
import java.util.Scanner;

class FIRSTone {
    public static void main(String[] strings){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int k = sc.nextInt();
        HashMap<Integer, Integer> map = new HashMap<>();
        int sum = 0;
        while (T-- > 0) {
            char ch = sc.next().charAt(0);
            int num = sc.nextInt();

            if (ch == 'i') {
                int count = map.containsKey(num) ? map.get(num) + 1 : 1;
                map.put(num, count);
                if (count == k)
                    sum += num;
            } else {
                int count = map.containsKey(num) ? map.get(num) - 1 : -1;
                if (count == -1)
                    continue;
                map.put(num, count);
                if (count == k - 1)
                    sum -= num;

            }
            System.out.println(sum);
        }

    }
}

