package DoAn;

public class Fulltime extends Employee {
    private int bonus = 10;

    public Fulltime() {
    }

    public Fulltime(int bonus) {
        this.bonus = bonus;
    }

    public Fulltime(double salaryPerHour, int bonus) {
        super(salaryPerHour);
        this.bonus = bonus;
    }

    public Fulltime(String id, String phoneNumber, String address, double salaryPerHour, int bonus) {
        super(id, phoneNumber, address, salaryPerHour);
        this.bonus = bonus;
    }
    
    public int getHours() {
        return bonus;
    }

    public void setHours(int bonus) {
        this.bonus = bonus;
    }

    @Override
    public String toString() {
        return super.toString() + " Fulltime [bonus=" + bonus + "]";
    }

    public void output() {
        System.out.println(toString());
        System.out.println("Total salary: " + salary());
    }

    @Override
    public double salary() {
        return 8 * getSalaryPerHour() + bonus;
    }
}
