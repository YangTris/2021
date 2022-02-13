package DoAn;

import java.util.Arrays;
import java.util.Scanner;

public class list implements Ipeople {
    static Scanner sc = new Scanner(System.in);

    public list() {
    }

    private People nv[] = new Employee[0];
    private People kh[] = new Customer[0];
    private Product sp[] = new Product[0];
    private Order or[] = new payment[0];

    int k, quantity, choice;
    double total, temp;
    String s;

    public double getTemp() {
        return temp;
    }

    public void setTemp(double temp) {
        this.temp = temp;
    }

    public double getTotal() {
        return total;
    }

    public void setTotal(double total) {
        this.total = total;
    }

    void addNV() {
        nv = Arrays.copyOf(nv, nv.length + 1);
        System.out.println("1: Full Time, 2: Part Time");
        System.out.print("Choose type of employee: ");
        k = Integer.parseInt(sc.nextLine());
        while (k != 1 && k != 2) {
            System.out.println("Error! Please input again");
            System.out.println("1: Full Time, 2: Part Time");
            System.out.print("Choose type of employee: ");
            k = Integer.parseInt(sc.nextLine());
        }
        if (k == 1) {
            nv[nv.length - 1] = new Fulltime();
            nv[nv.length - 1].input();
            for (int i = 0; i < nv.length - 1; i++)
                if (nv[i].getId().equals(nv[i + 1].getId())) {
                    System.out.println("-----Duplicate id please input again-----");
                    nv[nv.length - 1].input();
                }
        } else {
            nv[nv.length - 1] = new PartTime();
            nv[nv.length - 1].input();
            for (int i = 0; i < nv.length - 1; i++)
                if (nv[i].getId().equals(nv[i + 1].getId())) {
                    System.out.println("-----Duplicate id please input again-----");
                    nv[nv.length - 1].input();
                }
        }
    }

    void delNV() {
        if (nv.length == 0) {
            System.out.println("Employee list is empty");
            return;
        }
        displayNV();
        System.out.print("Input employee id want to delete: ");
        s = sc.nextLine();
        for (int i = 0; i < nv.length; i++) {
            if (nv[i].getId().equals(s)) {
                if (nv.length == 1) {
                    nv = Arrays.copyOf(nv, nv.length - 1);
                    System.out.println("Employee was deleted!");
                    return;
                }
                nv[i] = nv[i + 1];
                nv = Arrays.copyOf(nv, nv.length - 1);
                System.out.println("Employee was deleted!");
                return;
            }
        }
        System.out.println("Employee not found!");
    }

    void displayNV() {
        if (nv.length == 0) {
            System.out.println("Employee list is empty!");
            return;
        }
        for (int i = 0; i < nv.length; i++) {
            System.out.println("Employee " + (i + 1) + ": ");
            nv[i].output();
        }
    }

    void searchNV() {
        if (nv.length == 0) {
            System.out.println("Employee list is empty!");
            return;
        }
        System.out.print("Input employee id want to search: ");
        s = sc.nextLine();
        for (int i = 0; i < nv.length; i++) {
            if (nv[i].getId().equals(s)) {
                nv[i].output();
                return;
            }
        }
        System.out.println("Employee not found!");
    }

    void changeNV() {
        if (nv.length == 0) {
            System.out.println("Employee list is empty!");
            return;
        }
        System.out.print("Input employee id want to change: ");
        s = sc.nextLine();
        for (int i = 0; i < nv.length; i++) {
            if (nv[i].getId().equals(s)) {
                System.out.println("1: Full Time, 2: Part Time");
                System.out.print("Choose type of employee: ");
                k = Integer.parseInt(sc.nextLine());
                while (k != 1 && k != 2) {
                    System.out.println("Error! Please input again");
                    System.out.println("1: Full Time, 2: Part Time");
                    System.out.print("Choose type of employee: ");
                    k = Integer.parseInt(sc.nextLine());
                }
                if (k == 1) {
                    nv[nv.length - 1] = new Fulltime();
                    nv[nv.length - 1].input();
                    for (int j = 0; i < nv.length - 1; j++)
                        if (nv[j].getId().equals(nv[j + 1].getId())) {
                            System.out.println("-----Duplicate id please input again-----");
                            nv[nv.length - 1].input();
                        }
                } else {
                    nv[nv.length - 1] = new PartTime();
                    nv[nv.length - 1].input();
                    for (int j = 0; i < nv.length - 1; j++)
                        if (nv[j].getId().equals(nv[j + 1].getId())) {
                            System.out.println("-----Duplicate id please input again-----");
                            nv[nv.length - 1].input();
                        }
                }
                return;
            }
        }
        System.out.println("Employee not found!");
    }

    void addKH() {
        kh = Arrays.copyOf(kh, kh.length + 1);
        System.out.println("1: Member, 2: Vip");
        System.out.print("Choose type of customer: ");
        k = Integer.parseInt(sc.nextLine());
        while (k != 1 && k != 2) {
            System.out.println("Error! Please input again");
            System.out.println("1: Member, 2: Vip");
            System.out.print("Choose type of customer: ");
            k = Integer.parseInt(sc.nextLine());
        }
        if (k == 1) {
            kh[kh.length - 1] = new member();
            kh[kh.length - 1].input();
            for (int i = 0; i < kh.length - 1; i++)
                if (kh[i].getId().equals(kh[i + 1].getId())) {
                    System.out.println("-----Duplicate id please input again-----");
                    kh[kh.length - 1].input();
                }
        } else {
            kh[kh.length - 1] = new Vip();
            kh[kh.length - 1].input();
            for (int i = 0; i < kh.length - 1; i++)
                if (kh[i].getId().equals(kh[i + 1].getId())) {
                    System.out.println("-----Duplicate id please input again-----");
                    kh[kh.length - 1].input();
                }
        }
    }

    void delKH() {
        if (kh.length == 0) {
            System.out.println("Customer list is empty!");
            return;
        }
        displayKH();
        System.out.print("Input customer id want to delete: ");
        s = sc.nextLine();
        for (int i = 0; i < kh.length; i++) {
            if (kh[i].getId().equals(s)) {
                if (kh.length == 1) {
                    kh = Arrays.copyOf(kh, kh.length - 1);
                    System.out.println("Customer was deleted!");
                    return;
                }
                kh[i] = kh[i + 1];
                kh = Arrays.copyOf(kh, kh.length - 1);
                System.out.println("Customer was deleted!");
                return;
            }
        }
        System.out.println("Customer not found!");
    }

    void displayKH() {
        if (kh.length == 0) {
            System.out.println("Customer list is empty");
            return;
        }
        for (int i = 0; i < kh.length; i++) {
            System.out.println("Customer " + (i + 1) + ": ");
            kh[i].output();
            System.out.println("Total buy: " + kh[i].getTotalPrice);
        }
    }

    void searchKH() {
        if (kh.length == 0) {
            System.out.println("Customer list is empty");
            return;
        }
        System.out.print("Input customer id want to search: ");
        s = sc.nextLine();
        for (int i = 0; i < kh.length; i++) {
            if (kh[i].getId().equals(s)) {
                kh[i].output();
                return;
            }
        }
        System.out.println("Customer not found!");
    }

    void addSP() {
        sp = Arrays.copyOf(sp, sp.length + 1);
        System.out.println("1: Food, 2: Drink, 3: Toy");
        System.out.print("Choose type of product: ");
        k = Integer.parseInt(sc.nextLine());
        while (k != 1 && k != 2 && k != 3) {
            System.out.println("Error! Please input again");
            System.out.println("1: Food, 2: Drink, 3: Toy");
            System.out.print("Choose type of product: ");
            k = Integer.parseInt(sc.nextLine());
        }
        if (k == 1) {
            sp[sp.length - 1] = new Food();
            sp[sp.length - 1].input();
            for (int i = 0; i < sp.length - 1; i++)
                if (sp[i].getId().equals(sp[i + 1].getId())) {
                    System.out.println("-----Duplicate id please input again-----");
                    sp[sp.length - 1].input();
                }
        } else if (k == 2) {
            sp[sp.length - 1] = new Drink();
            sp[sp.length - 1].input();
            for (int i = 0; i < sp.length - 1; i++)
                if (sp[i].getId().equals(sp[i + 1].getId())) {
                    System.out.println("-----Duplicate id please input again-----");
                    sp[sp.length - 1].input();
                }
        } else {
            sp[sp.length - 1] = new Toy();
            sp[sp.length - 1].input();
            for (int i = 0; i < sp.length - 1; i++)
                if (sp[i].getId().equals(sp[i + 1].getId())) {
                    System.out.println("-----Duplicate id please input again-----");
                    sp[sp.length - 1].input();
                }
        }
    }

    void delSP() {
        if (sp.length == 0) {
            System.out.println("Product list is empty!");
            return;
        }
        displaySP();
        System.out.print("Input product id want to delete: ");
        s = sc.nextLine();
        for (int i = 0; i < sp.length; i++) {
            if (sp[i].getId().equals(s)) {
                if (sp.length == 1) {
                    sp = Arrays.copyOf(sp, sp.length - 1);
                    System.out.println("Product was deleted!");
                    return;
                }
                sp[i] = sp[i + 1];
                sp = Arrays.copyOf(sp, sp.length - 1);
                System.out.println("Product was deleted!");
                return;
            }
        }
        System.out.println("Product not found!");
    }

    void displaySP() {
        if (sp.length == 0) {
            System.out.println("Product list is empty!");
            return;
        }
        for (int i = 0; i < sp.length; i++) {
            System.out.println("Product " + (i + 1) + ": ");
            sp[i].output();
        }
    }

    void searchSP() {
        if (sp.length == 0) {
            System.out.println("Product list is empty!");
            return;
        }
        System.out.print("Input product id want to search: ");
        s = sc.nextLine();
        for (int i = 0; i < sp.length; i++) {
            if (sp[i].getId().equals(s)) {
                sp[i].output();
                return;
            }
        }
        System.out.println("Product not found");
    }

    void changeSP() {
        if (sp.length == 0) {
            System.out.println("Product list is empty!");
            return;
        }
        System.out.print("Input product id want to change: ");
        s = sc.nextLine();
        for (int i = 0; i < sp.length; i++) {
            if (sp[i].getId().equals(s)) {
                System.out.println("1: Food, 2: Drink, 3: Toy");
                System.out.print("Choose type of product: ");
                k = Integer.parseInt(sc.nextLine());
                while (k != 1 && k != 2 && k != 3) {
                    System.out.println("Error! Please input again");
                    System.out.println("1: Food, 2: Drink, 3: Toy");
                    System.out.print("Choose type of product: ");
                    k = Integer.parseInt(sc.nextLine());
                }
                if (k == 1) {
                    sp[sp.length - 1] = new Food();
                    sp[sp.length - 1].input();
                    for (int j = 0; j < sp.length - 1; j++)
                        if (sp[j].getId().equals(sp[j + 1].getId())) {
                            System.out.println("-----Duplicate id please input again-----");
                            sp[sp.length - 1].input();
                        }
                } else if (k == 2) {
                    sp[sp.length - 1] = new Drink();
                    sp[sp.length - 1].input();
                    for (int j = 0; j < sp.length - 1; j++)
                        if (sp[j].getId().equals(sp[j + 1].getId())) {
                            System.out.println("-----Duplicate id please input again-----");
                            sp[sp.length - 1].input();
                        }
                } else {
                    sp[sp.length - 1] = new Toy();
                    sp[sp.length - 1].input();
                    for (int j = 0; j < sp.length - 1; j++)
                        if (sp[j].getId().equals(sp[j + 1].getId())) {
                            System.out.println("-----Duplicate id please input again-----");
                            sp[sp.length - 1].input();
                        }
                }
                return;
            }
        }
        System.out.println("Product not found!");
    }

    public void Buy() {
        if (sp.length < 1) {
            System.out.println("Product list is empty! Nothing to buy see you later.");
            return;
        }
        or = Arrays.copyOf(or, or.length + 1);
        do {
            displaySP();
            System.out.print("Choose product want to buy: ");
            k = Integer.parseInt(sc.nextLine());
            while (k > sp.length) {
                System.out.print("Error! Choose product want to but again:");
                k = Integer.parseInt(sc.nextLine());
            }
            System.out.print("Input quantity: ");
            quantity = Integer.parseInt(sc.nextLine());
            while (quantity > sp[k - 1].getAmount()) {
                System.out.println("Product only has " + sp[k - 1].getAmount() + " left");
                System.out.print("Please input quantity again: ");
                quantity = Integer.parseInt(sc.nextLine());
            }
            sp[k - 1].setAmount(sp[k - 1].getAmount() - quantity);
            total += quantity * sp[k - 1].getPrice();
            System.out.println("1: Continue buying, 2: Calc total");
            System.out.print("Choose method: ");
            choice = Integer.parseInt(sc.nextLine());
        } while (choice == 1);
        addKH();
        System.out.println("Total: " + discount());

        do {
            System.out.print("Account Balance: ");
            temp = Double.parseDouble(sc.nextLine());
        } while (temp < discount());
        if (discount() < 500)
            or[or.length - 1] = new payment(or.length, kh[kh.length - 1], nv[0], getTemp());
        else
            or[or.length - 1] = new payment(or.length, kh[kh.length - 1], nv[1], getTemp());
        kh[kh.length - 1].getTotalPrice = discount();
        kh[kh.length - 1].getBalance = (getTemp() - discount());
        System.out.println("Change: " + (getTemp() - discount()));
        total = 0;
    }

    void delOR() {
        if (or.length == 0) {
            System.out.println("Order list is empty");
            return;
        }
        displayOr();
        System.out.print("Choose Order want to delete: ");
        k = Integer.parseInt(sc.nextLine());
        while (k > nv.length || k < 0) {
            System.out.println("Order not found");
            System.out.println("Please input again: ");
            k = Integer.parseInt(sc.nextLine());
        }
        for (int i = k - 1; i < or.length - 1; i++)
            or[i] = or[i + 1];
        or = Arrays.copyOf(or, or.length - 1);
        System.out.println("Order was deleted!");
    }

    void displayOr() {
        if (or.length == 0) {
            System.out.println("Order list is empty");
            return;
        }
        for (int i = 0; i < or.length; i++) {
            System.out.println("Order " + (i + 1) + ": ");
            or[i].output();
            System.out.println("Total buy: " + kh[i].getTotalPrice);
            System.out.println("Change: " + kh[i].getBalance);
        }
    }

    void searchOR() {
        if (or.length == 0) {
            System.out.println("Order list is empty");
            return;
        }
        System.out.print("Input order id want to search: ");
        choice = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < or.length; i++) {
            if (i == choice - 1) {
                or[i].output();
                System.out.println("Total buy: " + kh[i].getTotalPrice);
                System.out.println("Change: " + kh[i].getBalance);
                return;
            }
        }
        System.out.println("Order not found");
    }

    void change() {
        changeMenu();
        System.out.print("Choose method: ");
        choice = Integer.parseInt(sc.nextLine());
        while (choice != 1 && choice != 2) {
            System.out.print("Error! Please input again: ");
            changeMenu();
            choice = Integer.parseInt(sc.nextLine());
        }
        if (choice == 1)
            changeNV();
        else
            changeSP();
    }

    void del() {
        delMenu();
        System.out.print("Choose method: ");
        choice = Integer.parseInt(sc.nextLine());
        while (choice < 0 && choice > 4) {
            System.out.print("Error! Input again: ");
            delMenu();
            choice = Integer.parseInt(sc.nextLine());
        }
        if (choice == 1)
            delNV();
        if (choice == 2)
            delKH();
        if (choice == 3)
            delSP();
        if (choice == 4)
            delOR();
    }

    void display() {
        displayMenu();
        System.out.print("Choose method: ");
        choice = Integer.parseInt(sc.nextLine());
        while (choice < 0 && choice > 4) {
            System.out.print("Error! Input again: ");
            displayMenu();
            choice = Integer.parseInt(sc.nextLine());
        }
        if (choice == 1)
            displayNV();
        if (choice == 2)
            displayKH();
        if (choice == 3)
            displaySP();
        if (choice == 4)
            displayOr();
    }

    void search() {
        searchMenu();
        System.out.print("Choose method: ");
        choice = Integer.parseInt(sc.nextLine());
        while (choice < 0 && choice > 4) {
            System.out.print("Error! Input again: ");
            searchMenu();
            choice = Integer.parseInt(sc.nextLine());
        }
        if (choice == 1)
            searchNV();
        if (choice == 2)
            searchKH();
        if (choice == 3)
            searchSP();
        if (choice == 4)
            searchOR();
    }

    private static void changeMenu() {
        System.out.println("1. Change information employee");
        System.out.println("2. Change information Product");
    }

    private static void searchMenu() {
        System.out.println("1. Search employee by id");
        System.out.println("2. Search customer by id");
        System.out.println("3. Search product by id");
        System.out.println("4. Search order by id");
    }

    private static void displayMenu() {
        System.out.println("1. Display employee list");
        System.out.println("2. Display customer list");
        System.out.println("3. Display product list");
        System.out.println("4. Display order list");

    }

    private static void delMenu() {
        System.out.println("1. Delete employee");
        System.out.println("2. Delete customer");
        System.out.println("3. Delete product");
        System.out.println("4. Delete Order");
    }

    private static void menu() {
        System.out.println("-------------------------------------");
        System.out.println("0. End program");
        System.out.println("1. Add employee");
        System.out.println("2. Add product");
        System.out.println("3. Purchase");
        System.out.println("4. Delete information");
        System.out.println("5. Display information");
        System.out.println("6. Search information");
        System.out.println("7. Change information");
        System.out.println("-------------------------------------");
    }

    void project() {
        menu();
        System.out.print("Input chose: ");
        k = Integer.parseInt(sc.nextLine());
        while (k != 0) {
            switch (k) {
                case 0:
                    break;
                case 1:
                    addNV();
                    menu();
                    System.out.print("Input chose: ");
                    k = Integer.parseInt(sc.nextLine());
                    break;
                case 2:
                    addSP();
                    menu();
                    System.out.print("Input chose: ");
                    k = Integer.parseInt(sc.nextLine());
                    break;
                case 3:
                    Buy();
                    menu();
                    System.out.print("Input chose: ");
                    k = Integer.parseInt(sc.nextLine());
                    break;
                case 4:
                    del();
                    menu();
                    System.out.print("Input chose: ");
                    k = Integer.parseInt(sc.nextLine());
                    break;
                case 5:
                    display();
                    menu();
                    System.out.print("Input chose: ");
                    k = Integer.parseInt(sc.nextLine());
                    break;
                case 6:
                    search();
                    menu();
                    System.out.print("Input chose: ");
                    k = Integer.parseInt(sc.nextLine());
                    break;
                case 7:
                    change();
                    menu();
                    System.out.print("Input chose: ");
                    k = Integer.parseInt(sc.nextLine());
                    break;
                default:
                    System.out.println("--------------Error!--------------");
                    System.out.println("Input again");
                    k = Integer.parseInt(sc.nextLine());
                    break;
            }
        }
        System.out.println("Thanks for using program!");
    }

    @Override
    public double salary() {
        return salary();
    }

    @Override
    public double discount() {
        // TODO Auto-generated method stub
        if (k == 1)
            return total * 0.98;
        else
            return total * 0.95;
    }

    @Override
    public double total() {
        // TODO Auto-generated method stub
        return getTotal();
    }
}