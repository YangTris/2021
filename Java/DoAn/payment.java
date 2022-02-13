package DoAn;

public class payment extends Order {
    double balance;

    public payment() {
    }

    public payment(double balance) {
        this.balance = balance;
    }

    public payment(int id, People customer, People employee, double balance) {
        super(id, customer, employee);
        this.balance = balance;
    }

    @Override
    public String toString() {
        return super.toString() + " payment [balance=" + balance + "]";
    }

    @Override
    public void output() {
        // TODO Auto-generated method stub
        System.out.println(toString());
    }

}
