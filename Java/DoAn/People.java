package DoAn;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public abstract class People implements Ipeople {

    private String id;
    private String phoneNumber;
    private String name;
    public double getTotalPrice;
    public double getBalance;

    static Scanner sc = new Scanner(System.in);

    public People() {

    }

    public People(String id, String phoneNumber, String name) {
        this.id = id;
        this.phoneNumber = phoneNumber;
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    @Override
    public String toString() {
        return "People [id=" + id + ", name=" + name + ", phoneNumber=" + phoneNumber + "]";
    }

    public void input() {
        System.out.print("Person id: ");
        id = sc.nextLine();
        while (id.length() < 3 || (id.charAt(0) != 'N' && id.charAt(1) != 'H')
                || (id.charAt(0) != 'K' && id.charAt(1) != 'V')) {
            System.out.println("at least 3 character and 2 first character must be start with NV or KH");
            System.out.print("Person id: ");
            id = sc.nextLine();
        }
        System.out.print("Person name: ");
        name = sc.nextLine();
        System.out.print("Person phoneNumber: ");
        phoneNumber = sc.nextLine();
        Pattern pattern = Pattern.compile("^[0-9]{10}$");
        Matcher matcher = pattern.matcher(phoneNumber);
        while (!matcher.matches()) {
            System.out.println("matches 10-digit numbers only");
            System.out.print("Input phone number again: ");
            phoneNumber = sc.nextLine();
            matcher = pattern.matcher(phoneNumber);
        }
    }

    public abstract void output();

    @Override
    public double salary() {
        // TODO Auto-generated method stub
        return 0;
    }

    @Override
    public double discount() {
        // TODO Auto-generated method stub
        return 0;
    }

    @Override
    public double total() {
        // TODO Auto-generated method stub
        return 0;
    }
}
