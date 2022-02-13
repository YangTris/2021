package DoAn;

public class Drink extends Product {
    private String size;

    public Drink() {

    }

    public Drink(String size) {
        this.size = size;
    }

    public Drink(String id, String name, double price, String size) {
        super(id, name, price);
        this.size = size;
    }

    public String getSize() {
        return size;
    }

    public void setSize(String size) {
        this.size = size;
    }

    @Override
    public void input() {
        super.input();
        System.out.print("Drink size: ");
        size = sc.nextLine();
    }

    @Override
    public String toString() {
        return super.toString() + " Drink [size=" + size + "]";
    }

    @Override
    public void output() {
        System.out.println(toString());
    }
}
