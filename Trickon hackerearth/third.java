import java.util.Scanner;

 class lastOne {
    public static void main(String[] strings) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        while (T-- > 0) {
            int vis[] = new int[26];
            for(int i=0; i<26; ++i)
                vis[i] = 0;
            int ans = -1;
            boolean flag = false;
            String a = scanner.next();
            String b = scanner.next();
            for(int i=0; i<a.length(); ++i){
               // System.out.println(b.charAt(i)-'a');
                vis[b.charAt(i)-'a'] += 1;
            }
            if(a.charAt(0) < b.charAt(0))
            {
                ans = 0;
                flag = true;
            }
            if(!flag){
                for(int i=0; i<a.length(); ++i){
                    if(a.charAt(i) > b.charAt(i)){
                        ans = 1;
                        break;
                    }
                    else{
                        int val = a.charAt(i) - 'a';
                        for(int j = val-1; j>=0; --j){
                            if(vis[j] >= 1){
                                flag = true;
                                ans = 1;
                                break;
                            }
                        }
                    }
                if(flag)
                    break;
                vis[b.charAt(i)-'a']--;
                }
            }
            System.out.println(ans);
        }
    }
}
