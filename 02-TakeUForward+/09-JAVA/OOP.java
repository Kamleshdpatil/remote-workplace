import java.util.*;

class Test {
    int age = 10;

    public static void TestFun() {
        System.out.println("Inside TestFun");

        Test test = new Test();

        System.out.print("Age is: ");
        System.out.println(test.age);

        System.out.println("Exit TestFun");
    }

    public void Fun() {
        System.out.println("Inside Fun");
        TestFun(); // Non Static to non static within class

        // System.out.print("Age is: ");
        // System.out.println(age);

        System.out.println("Exit Fun");
    }
}

class BankAccount {
    private double balance;

    public BankAccount(double _balance) {
        this.balance = _balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public double getBalance() {
        return balance;
    }

    public void printBalance() {
        System.out.println(balance);
    }
}

public class OOP {
    public static void main(String[] args) {
        /////////////////////////////////////////////////////////

        Scanner scanner = new Scanner(System.in);

        // Test test = new Test();
        // test.Fun(); // Static to non static

        // Test.TestFun(); // Static to static

        BankAccount account = new BankAccount(scanner.nextInt());

        // System.out.println(account.getBalance());
        // account.balance = 0.0;

        account.printBalance();
        
        account.setBalance(500);
        
        System.out.println(account.getBalance());

        /////////////////////////////////////////////////////////
        scanner.close();
    }
}
