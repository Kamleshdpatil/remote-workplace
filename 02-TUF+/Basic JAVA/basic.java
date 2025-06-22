import java.util.Scanner;

class basic {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        // String name = "Kamlesh Dugade";

        // //System.out.println("Hello world!");
        // System.out.println(name.substring(0, 7));
        // int num = scan.nextInt();

        // System.out.println("Number: "+ num);

        // int x = 10;
        // double y = x; // Implicit
        // double y1 = 11.22;

        // int z = (int) y1; // Explicit

        // System.out.println(z);

        // int num = 10;
        // num += 15;

        // System.out.println(num);
        
        int[] Arr = new int[5];

        Arr[0] = 10;
        Arr[1] = 15;
        Arr[2] = 30;
        Arr[3] = 20;
        Arr[4] = 25;

        // for(int i = 0; i < Arr.length; i++)
        // {
        //     System.out.println(Arr[i]);
        // }
        
        for (int i : Arr) {
            System.out.println(Arr[i]);
            //System.out.println("K");
        }
        scan.close();
    }
}
