import java.util.*;
// import java.util.Collection;
// import java.util.List;

import javax.print.attribute.HashAttributeSet;

class Data {
    public Integer num;
    public String name;

    Data(int _num, String _name) {
        this.num = _num;
        this.name = _name;
    }
}

// FIFO
public class MapInterface {
    public static void main(String[] args) {
        // Key value
        HashMap<Integer, String> mp = new HashMap<>();
        mp.put(1, "Raj");
        mp.put(3, "Kamlesh");
        mp.put(4, "Gouri");
        mp.put(2, "Shivu");

        // System.out.println(mp);
        // System.out.println(mp.get(2));
        // System.out.println(mp.size());
        // mp.remove(4);
        // System.out.println(mp.size());

        TreeMap<Integer, String> tmp = new TreeMap<>();
        tmp.put(1, "Raj");
        tmp.put(3, "Kamlesh");
        tmp.put(4, "Gouri");
        tmp.put(2, "Shivu");

        System.out.println(tmp);
        System.out.println(tmp.get(2));
        System.out.println(tmp.size());
        tmp.remove(4);
        System.out.println(tmp.size());

    }
}
