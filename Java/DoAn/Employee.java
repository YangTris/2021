package DoAn;

public class Employee extends People {
    private double salaryPerHour = 20;

    public Employee() {

    }

    public Employee(double salaryPerHour) {
        this.salaryPerHour = salaryPerHour;
    }

    public Employee(String id, String phoneNumber, String address, double salaryPerHour) {
        super(id, phoneNumber, address);
        this.salaryPerHour = salaryPerHour;
    }

    public double getSalaryPerHour() {
        return salaryPerHour;
    }

    public void setSalaryPerHour(double salaryPerHour) {
        this.salaryPerHour = salaryPerHour;
    }

    public Employee(String id, String phoneNumber, String name) {
        super(id, phoneNumber, name);
    }

    @Override
    public String toString() {
        return super.toString() + " Employee [salaryPerHour=" + salaryPerHour + "]";
    }

    @Override
    public void output() {
        System.out.println(toString());
    }

}
