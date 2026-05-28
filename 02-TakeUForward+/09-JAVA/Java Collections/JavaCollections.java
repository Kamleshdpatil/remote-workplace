import java.util.*;
// import java.util.Collection;
// import java.util.List;

class Data {
    public Integer num;
    public String name;

    Data(int _num, String _name) {
        this.num = _num;
        this.name = _name;
    }
}

public class JavaCollections {
    public static void main(String[] args) {
        ArrayList<Integer> aList = new ArrayList<>();
        aList.add(10);
        aList.add(40);
        aList.add(70);
        aList.add(980);
        aList.add(780);
        aList.add(657);
        aList.add(30);

        // System.out.println(aList);
        // System.out.println(aList.size());

        // //System.out.println(aList.remove(2));

        // aList.add(2, 777);
        // System.out.println(aList);
        // System.out.println(aList.size());

        // System.out.println("Iterator:---");

        // Iterator<Integer> iterator = aList.iterator();

        // while (iterator.hasNext()) {
        // Integer num = iterator.next();
        // System.out.println(num);
        // }

        System.out.println(aList);

        Collections.sort(aList);

        System.out.println(aList);

        // Collections.sort(aList, new Comparator<Integer>() {
        //     @Override
        //     public int compare(Integer num1, Integer num2) {
        //         if (num1 < num2) {
        //             return 1;
        //         } else if (num1 > num2) {
        //             return -1;
        //         }
        //         return 0;
        //     }
        // });

        Collections.sort(aList, (num1, num2)-> num2-num1);

        System.out.println(aList);
    }
}
