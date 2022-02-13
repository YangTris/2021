package DoAn;

public class Toy extends Product {
    private String material;

    public Toy() {

    }

    public Toy(String material) {
        this.material = material;
    }

    public Toy(String id, String name, double price, String material) {
        super(id, name, price);
        this.material = material;
    }

    public String getMaterial() {
        return material;
    }

    public void setMaterial(String material) {
        this.material = material;
    }

    @Override
    public String toString() {
        return super.toString() + " Toy [material=" + material + "]";
    }

    @Override
    public void input() {
        super.input();
        System.out.print("Toy materital: ");
        material = sc.nextLine();
    }

    @Override
    public void output() {
        System.out.println(toString());
    }
}
