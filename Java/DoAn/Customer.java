package DoAn;

public class Customer extends People {
    private String address;

    public Customer() {
    }

    public Customer(String address) {
        this.address = address;
    }

    public Customer(String id, String phoneNumber, String name, String address) {
        super(id, phoneNumber, name);
        this.address = address;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    @Override
    public void input() {
        super.input();
        System.out.print("Input Address: ");
        address = sc.nextLine();
    }

    @Override
    public String toString() {
        return super.toString() + " Customer [address=" + address + "]";
    }

    @Override
    public void output() {
        System.out.println(toString());
    }

}
