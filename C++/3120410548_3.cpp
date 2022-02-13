#include <iostream>
using namespace std;
struct Queue //Cấu trúc khởi tạo Queue
{
    int rear;
    int front = 0;
    int arr[100];
};

void initQueue(Queue &q) //khởi tạo Queue
{
    q.rear = -1; //gán phần tử đuôi có giá trị là -1 => mảng rỗng
}

void enQueue(Queue &q, int n) //Thêm giá trị vào cuối hàng đợi
{
    q.rear++;          //tăng phần tử đuôi lên 1 đơn vị
    q.arr[q.rear] = n; //gán phần tử đuôi có giá trị bằng phần tử truyền vào n
}

int deQueue(Queue &q) //lấy giá trị ở đầu hàng và xóa đi
{
    if (q.front <= q.rear)       //kiểm tra Queue có rỗng hay ko
        return q.arr[q.front++]; //trả về giá trị phần tử ở đầu;
    return -1;                   //trả về giá trị -1 nếu queue rỗng
}

bool isEmpty(Queue q) //kiểm tra Queue có rỗng hay không
{
    if (q.rear < q.front) //phần tử đuôi bé hơn phần tử đầu => mảng rỗng
        return true;
    else //mảng không rỗng
        return false;
}

int Front(Queue q) //lấy giá trị ở đầu hàng mà không xóa
{
    if (isEmpty(q)) //kiểm tra rỗng
        return -1;
    return q.arr[q.front]; //trả về phần tử đầu nếu không rỗng
}

int main()
{
    struct Queue q;
    initQueue(q);                  //khởi tạo Queue q
    enQueue(q, 1);                 //thêm giá trị vào queue q
    cout << "Front= " << Front(q); //lấy giá trị ở đầu mà không xóa
    cout << endl;
    enQueue(q, 3);
    enQueue(q, 2);
    enQueue(q, 5);
    while (isEmpty(q) == 0) //mảng không rỗng tiến hành dequeue
        cout << deQueue(q) << " ";
    enQueue(q, 4);
    cout << deQueue(q);
    return 0;
}
