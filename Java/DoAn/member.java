package DoAn;

public class member extends Customer {
    private double discountPercent = 2;

    public member() {

    }

    public member(double discountPercent) {
        this.discountPercent = discountPercent;
    }

    public member(String address, double discountPercent) {
        super(address);
        this.discountPercent = discountPercent;
    }

    public member(String id, String phoneNumber, String name, String address, double discountPercent) {
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
        return super.toString() + " member [discountPercent=" + discountPercent + "%]";
    }

    @Override
    public void output() {
        System.out.println(toString());
    }
}
