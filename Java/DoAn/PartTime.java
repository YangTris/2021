package DoAn;

public class PartTime extends Employee {
    private double hours;

    public PartTime() {
    }

    public PartTime(double hours) {
        this.hours = hours;
    }

    public PartTime(double salaryPerHour, double hours) {
        super(salaryPerHour);
        this.hours = hours;
    }

    public PartTime(String id, String phoneNumber, String address, double salaryPerHour, double hours) {
        super(id, phoneNumber, address, salaryPerHour);
        this.hours = hours;
    }

    public double getHours() {
        return hours;
    }

    public void setHours(double hours) {
        this.hours = hours;
    }

    @Override
    public void input() {
        super.input();
        System.out.print("Input hours: ");
        hours = Double.parseDouble(sc.nextLine());
    }

    @Override
    public String toString() {
        return super.toString() + " PartTime [hours=" + hours + "]";
    }

    @Override
    public void output() {
        System.out.println(toString());
        System.out.println("Total salary: " + salary());
    }

    @Override
    public double salary() {
        return hours * getSalaryPerHour();
    }
}
