package DoAn;

import java.util.Scanner;

public abstract class Product {
    private String id;
    private String name;
    private double price;
    private int amount;
    static Scanner sc = new Scanner(System.in);

    public Product() {
    }

    public Product(String id, String name, double price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getAmount() {
        return amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }

    @Override
    public String toString() {
        return "Product [amount=" + amount + ", id=" + id + ", name=" + name + ", price=" + price + "]";
    }

    public void input() {
        System.out.print("Product id: ");
        id = sc.nextLine();
        while (id.length() < 2 || id.charAt(0) != 'F' && id.charAt(0) != 'D' && id.charAt(0) != 'T') {
            System.out.println("at least 2 character and 1st character must be start with 'F' or 'D' or 'T'");
            System.out.print("Product id: ");
            id = sc.nextLine();
        }
        System.out.print("Product name: ");
        name = sc.nextLine();
        System.out.print("Product price: ");
        price = Double.parseDouble(sc.nextLine());
        System.out.print("Product amount: ");
        amount = Integer.parseInt(sc.nextLine());
    }

    public void output() {
        System.out.println(toString());
    }
}