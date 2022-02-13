package DoAn;

import java.util.Scanner;

public abstract class Order {
    private int id;
    private People customer;
    private People employee;
    static Scanner sc = new Scanner(System.in);

    public Order() {

    }

    public Order(int id, People customer, People employee) {
        this.id = id;
        this.customer = customer;
        this.employee = employee;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public People getCustomer() {
        return customer;
    }

    public void setCustomer(People customer) {
        this.customer = customer;
    }

    public People getEmployee() {
        return employee;
    }

    public void setEmployee(People employee) {
        this.employee = employee;
    }

    @Override
    public String toString() {
        return "Order [customerId=" + customer.getId() + ", employeeId=" + employee.getId() + ", id=" + id + "]";
    }

    public void output() {
        System.out.println(toString());
    }
}
