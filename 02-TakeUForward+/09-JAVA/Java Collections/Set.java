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

public class Set {
    public static void main(String[] args) {
        // HashSet
        // Store Unique element in random order
        HashSet<Integer> hs = new HashSet<>(); // log(1)

        hs.add(14);
        hs.add(40);
        hs.add(24);

        // System.out.println(hs);

        // System.out.println(hs.remove(14));

        // System.out.println(hs);
        //

        // TreeSet
        // Store Unique element in sorted order
        TreeSet<Integer> ts = new TreeSet<>(); // log(N)

        ts.add(14);
        ts.add(40);
        ts.add(24);

        System.out.println(ts);

        //System.out.println(ts.remove(14));

        System.out.println(ts.floor(23));
        System.out.println(ts.ceiling(23));



    }
}
