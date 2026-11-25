
class Data {
    public Integer num;
    public String name;
    protected InternalData internalData;

    Data(int _num, String _name, int _revenue) {
        this.num = _num;
        this.name = _name;
        this.internalData = new InternalData(_revenue);
    }
}

class InternalData {
    public Integer revenue;

    InternalData(Integer _revenue) {
        this.revenue = _revenue;
    }
}

public class basics {
    public static void main(String[] args) {
        Data data1 = new Data(7, "Kamlesh", 8000);
        Data data2 = new Data(9, "Gouri", 7500);

        System.out.println(data1.name);
        
        System.out.print("Revenue is: ");
        System.out.println(data1.internalData.revenue);
        System.out.println(data2.name);
        System.out.print("Revenue is: ");
        System.out.println(data2.internalData.revenue);

        
    }
}
