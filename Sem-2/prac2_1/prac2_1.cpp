#include <iostream>
using namespace std;
class Rectangle {
private:
    int length, width;
public:
    void setDimensions(int l, int w) {
        length = l;
        width = w;    
    }
    int area() {
        return length * width;
    }
    int perimeter() {
        return 2 * (length + width);
    }
    void displayDetails() {
        cout<<"  - Area: "<<area()<<" square units"<<endl;
        cout<<"  - Perimeter: "<<perimeter()<<" units"<< endl;
    }
};
void inputRectangle(Rectangle &rect) {
    int l, w;
    cout<<"Enter the length and width of the rectangle: ";
    cin>>l>>w;
    rect.setDimensions(l, w);
}
int main() {
    Rectangle rect1, rect2;

    cout<<"Let's create some rectangles!"<<endl;
    
    cout<<"For the first rectangle:"<<endl;
    inputRectangle(rect1);
    
    cout<<"For the second rectangle:"<<endl;
    inputRectangle(rect2);

    cout<<endl<<"Here are the details of your rectangles:"<<endl;

    cout<<"First Rectangle:"<<endl;
    rect1.displayDetails();

    cout<<endl<<"Second Rectangle:"<<endl;
    rect2.displayDetails();

    cout<<endl<<"End Of Programme"<<endl;
    return 0;
}
