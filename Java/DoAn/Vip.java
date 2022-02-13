package DoAn;

public class Vip extends Customer {
    private double discountPercent = 5;

    public Vip() {

    }

    public Vip(double discountPercent) {
        this.discountPercent = discountPercent;
    }

    public Vip(String address, double discountPercent) {
        super(address);
        this.discountPercent = discountPercent;
    }

    public Vip(String id, String phoneNumber, String name, String address, double discountPercent) {
        super(id, phoneNumber, name, address);
        this.discountPercent = discountPercent;
    }

    public double getDiscount() {
        return discountPercent;
    }

    public void setDiscount(double discountPercent) {
        this.discountPercent = discountPercent;
    }

    @Override
    public String toString() {
        return super.toString() + " Vip [discountPercent=" + discountPercent + "%]";
    }

    @Override
    public void output() {
        System.out.println(toString());
    }
}
