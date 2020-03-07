#include <iostream>
using namespace std;

class Car {
	int price;
public:
	char* color;
	int wheel;
	//default constructor
	Car() {
		cout << "constructor called" << endl;
		price = 10;
		color = new char[10];
	}
	// //parameterized constructor
	// Car(char* col, int w = 4) {
	// 	cout << "parameterized constructor called" << endl;
	// 	wheel = w;
	// 	color = col;
	// 	price = 10;
	// }

	// constructor with initialization list
	Car(char* col, int w = 4): wheel(w) {
		cout << "initialization constructor called" << endl;
		//color = col;
		color = new char[strlen(col)];
		strcpy(color, col);
		price = 10;
	}
	//Deep copy
	//copy constructor
	Car(Car& X): wheel(X.wheel) {
		cout << "my ccopy constructor" << endl;
		setPrice(X.price);
		color = new char[strlen(X.color)];
		strcpy(color, X.color);
	}
	//assignment operator overrided
	void operator =(Car& X) {
		cout << "my assignment operator" << endl;
		setPrice(X.price);
		color = new char[strlen(X.color)];
		strcpy(color, X.color);
	}
	//+ operator overrided
	void operator +(Car& X) {
		cout << "my + operator" << endl;
		price += X.price;
	}

	// getter
	int getPrice() {
		return price;
	}
	//setter
	void setPrice(int p) {
		if (p >= 10) {
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

// void operator << (ostream& o, Car X){
// 	o << X.color << endl;
// 	o << X.wheel << endl;
// 	o << X.getPrice() << endl;
// 	o << "---------------" << endl;
// }
ostream& operator << (ostream& o, Car X) {
	o << X.color << endl;
	o << X.wheel << endl;
	o << X.getPrice() << endl;
	o << "---------------" << endl;
	return o;
}
istream& operator >> (istream& o, Car& X) {
	char arr[10];

	o >> arr;

	strcpy(X.color, arr);
	o >> X.wheel;
	int p;
	o >> p;
	X.setPrice(p);
	return o;
}

int main(int argc, char const *argv[])
{

//	char color[10] = "Blue";
	// Car D(color);
	// D.print();
	// Car E(D);
	// E.print();
	// E.color[1] = 'M';
	// D.print();
	//E.print();
	// Car F = D;
	// F.print();
	// // F+D;
	// // cout<<F.getPrice()<<endl;
	// // cout<<D.getPrice()<<endl;
	// //cout<<F;

	// cout<<F<<endl; //cascading
	// cout<<F<<D<<endl;
	Car G;
	Car H;
	cin >> G >> H;
	cout << G << H << endl;




	return 0;
}










