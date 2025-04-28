#include <iostream>
using namespace std;
class Point {
private:
    int xCord,yCord;
public:
    Point(int x=0,int y=0) : xCord(x), yCord(y) {}

    Point operator-() const {
        return Point(-xCord, -yCord);
    }
    Point operator+(const Point& other) const {
        return Point(xCord + other.xCord, yCord + other.yCord);
    }
    bool operator==(const Point& other) const {
        return xCord == other.xCord && yCord == other.yCord;
    }
    void readPoint() {
        cout<<"Enter x and y coordinates :: ";
        cin>>xCord>>yCord;
    }
    void showPoint() const {
        cout<<"("<<xCord<<", "<<yCord<<")";
    }
};
class PointStack {
private:
    Point stackArray[100];
    int topIndex;
public:
    PointStack() {
        topIndex = -1;
    }
    bool isEmpty() const {
        return topIndex == -1;
    }
    bool isFull() const {
        return topIndex == 99;
    }
    
    void push(Point p) {
        if (isFull()) {
            cout<<"Stack Overflow! Can't add more points."<<endl;
            return;
        }
        stackArray[++topIndex] = p;
    }
    
    Point pop() {
        if (isEmpty()) {
            cout<<"Stack Underflow! Nothing to undo."<<endl;
            return Point();
        }
        return stackArray[topIndex--];
    }
    
    Point peek() const {
        if (isEmpty()) {
            cout<<"Stack is empty."<<endl;
            return Point();
        }
        return stackArray[topIndex];
    }
};
int main() {
    PointStack operationStack;
    int userChoice;
    do {
       
        cout<<"\n====== Point Operations Menu ======\n";
        cout<<"1. Add two points\n";
        cout<<"2. Negate a point\n";
        cout<<"3. Compare two points\n";
        cout<<"4. Undo last operation\n";
        cout<<"5. Show current top point\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>userChoice;
        Point point1, point2, resultPoint;
        switch (userChoice) {
            case 1:
                
                cout<<"Enter first point :: "<<endl;
                point1.readPoint();
                cout<<"Enter second point :: "<<endl;
                point2.readPoint();
                resultPoint = point1 + point2;
                cout<<"Sum of points :: ";
                resultPoint.showPoint();
                cout<<endl;
                operationStack.push(resultPoint);
                break;
            case 2:
             
                cout<<"Enter a point to negate :: "<<endl;
                point1.readPoint();
                resultPoint = -point1;
                cout<<"Negated point :: ";
                resultPoint.showPoint();
                cout<<endl;
                operationStack.push(resultPoint);
                break;
            case 3:
                
                cout<<"Enter first point ::\n";
                point1.readPoint();
                cout<<"Enter second point ::\n";
                point2.readPoint();
                if (point1 == point2)
                    cout << "Points are equal.\n";
                else
                    cout << "Points are not equal.\n";
                break;
            case 4:
                
                operationStack.pop();
                cout << "Last operation undone.\n";
                break;
            case 5:
               
                cout << "Top point in stack: ";
                operationStack.peek().showPoint();
                cout << "\n";
                break;

            case 0:
                cout << "Exiting program. Thank you!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (userChoice != 0);
    return 0;
}