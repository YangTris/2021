package DoAn;

public class Food extends Product {
    private String size;

    public Food() {

    }

    public Food(String size) {
        this.size = size;
    }

    public Food(String id, String name, double price, String size) {
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
        System.out.print("Food size: ");
        size = sc.nextLine();
    }

    @Override
    public String toString() {
        return super.toString() + " Food [size=" + size + "]";
    }

    @Override
    public void output() {
        System.out.println(toString());
    }
}
