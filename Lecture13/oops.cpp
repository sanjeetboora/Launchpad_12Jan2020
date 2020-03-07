#include <iostream>
using namespace std;
class Car {
	int price;
public:
	char* color;
	const int wheel;
	//default constructor
	// Car() {
	// 	cout << "constructor called" << endl;
	// 	price = 10;
	// }
	// //parameterized constructor
	// Car(char* col, int w = 4) {
	// 	cout << "parameterized constructor called" << endl;
	// 	wheel = w;
	// 	color = col;
	// 	price = 10;
	// }

	// constructor with initialization list
	Car(char* col, int w = 4): wheel(w), color(col) {
		cout << "initialization constructor called" << endl;
		//color = col;
		setPrice(X.price);
	}
	//shallow copy
	//copy constructor
	Car(Car& X): wheel(X.wheel) {
		cout<<"my ccopy constructor"<<endl;
		setPrice(X.price);
		color = X.color;
	}

	// getter
	int getPrice() {
		return price;
	}
	//setter
	void setPrice(int p) {
		if (p > 10) {
			price = p;
		}
	}

	void print() {
		cout << color << endl;
		cout << wheel << endl;
		cout << price << endl;
		cout << "---------------" << endl;
	}

};
int main(int argc, char const *argv[])
{
// 	Car A;
// 	cout<<sizeof(A)<<endl;
// 	cout<<sizeof(Car)<<endl;
//  char arr[10] = "Black";
// 	//A.color = arr;
// 	//A.price = 10;
// 	A.wheel =4;

// 	cout<<A.getPrice()<<endl;
	// char color[10] = "Blue";
	// Car B(color);
	// B.wheel = 6;
	// B.print();
	// Car C(color, 5);
	// C.print();
	// C.setPrice(5);
	// C.print();
	// C.setPrice(15);
	// C.print();

	char color[10] = "Blue";
	Car D(color);
	D.print();
	Car E(D);
	E.print();
	// Car F = D;
	// F.print();

	E.color[1] = 'M';
	D.print();
	E.print();




	return 0;
}










