import javafx.util.Pair;

import java.util.*;
import java.lang.*;


class Main
{
    static class MyCompartors implements Comparator<Pair<String, Integer>> {

        @Override
        public int compare(Pair<String, Integer> o1, Pair<String, Integer> o2) {
            if(o1.getValue().equals(o2.getValue()) )
                return o1.getKey().compareTo(o2.getKey());

            return o1.getValue() - o2.getValue();
        }
    }

    static TreeSet<Pair<String, Integer>> listSet = new TreeSet<>((o1, o2) -> {
        if(o1.getValue().equals(o2.getValue()) )
            return o1.getKey().compareTo(o2.getKey());

        return o1.getValue() - o2.getValue();
    });

    static HashMap<String, Integer> map = new HashMap<>();

    static void addTop10Elements(String word, Integer count) {

        if(map.get(word) == null ) {
            if(listSet.size() < 30) {
                listSet.add(new Pair<>(word,count));
                map.put(word,count);
            }
            else {
                Pair<String, Integer> topElem = listSet.first();
                map.remove(topElem.getKey());
                listSet.remove(topElem);

                listSet.add(new Pair<>(word, count));
                map.put(word,count);
            }
        }
        else {
//            TreeSet<Pair<String, Integer>> currWord = listSet.contains();
//            map.remove(word); // deleting entry

            listSet.remove(new Pair<>(word, map.get(word)));
            listSet.add(new Pair<>(word,count));
            map.put(word, count);
        }
    }
    public static void main(String args[])
    {
        addTop10Elements("a",10);
        addTop10Elements("b", 25);
        addTop10Elements("a", 250);

        addTop10Elements("c", 40);
        addTop10Elements("d", 20);
        addTop10Elements("e", 45);

        System.out.println(listSet);
    }
}
