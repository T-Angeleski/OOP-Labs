#include<iostream>
#include<cstring>
using namespace std;

class Person{
    char ime[20], prezime[20];

    public:
        Person() {
            strcpy(ime, "not specified");
            strcpy(prezime, "not specified");
        }

        Person(char * _ime, char * _prezime) {
            strcpy(ime, _ime);
            strcpy(prezime, _prezime);
        }

        void print() {
            cout<<ime<<" "<<prezime<<endl;
        }
};

class Date{
    int year,month,day;

    public:
        Date() {
            year = 2002;
            month = 10;
            day = 14;
        }

        Date(int year, int month, int day){
            this->year = year;
            this->month = month;
            this->day = day;
        }

        Date(const Date & d) {
            year = d.year;
            month = d.month;
            day = d.day;
        }

        void print() {
            cout<<year<<"."<<month<<"."<<day<<endl;
        }
};

class Car{
    Person owner;
    Date dateOfPurchase;
    float price=0;

    public:
        Car() {
            price = 0;
        }

        Car(Person owner, Date dop, float price) {
            this->owner= owner;
            this->dateOfPurchase = dop;
            this->price = price;
        }

        float getPrice() {
            return price;
        }

        void print() {
            owner.print();
            dateOfPurchase.print();
            cout<<"Price: "<<price;
        }

    
};

Car cheaperThan(Car* cars, int numCars, float price) {
    for (int i = 0; i < numCars; i++)
        {
            if(cars[i].getPrice() < price) {
                cars[i].print();
            }
        }
}

int main() {
    //     Во оваа задача треба да се внесат и испечатат податоци за автомобили.

    // За еден автомобил (објект од класата Car) се чуваат следниве податоци:

    //     сопственик (објект од класата Person)
    //     датум на купување (објект од класата Date)
    //     цена (float price), предодредена вредност 0

    // За класата Car потребно е да се напише метод за печатење print() и метод за добивање на цената getPrice().

    // Класата Date содржи три цели броеви (int year, month, day) кои претставуваат датум. За неа треба да се напише метод за печатење print(), предодреден (default) конструктор, конструктор со параметри и конструктор за копирање.

    // Класата Person содржи име и презиме (низи од максимум 20 знаци, со предодредени вредности not specified), предодреден конструктор, конструктор со параметри и метод за печатење print().

    // Методот за печатење кај класата Person изгледа вака: [name] [lastName].

    // Методот за печатење кај класата Date изгледа вака: [year].[month].[day].

    // Методот за печатење кај класата Car изгледа вака:

    // owner.print()

    // date.print()

    // Price: [price]

    // Покрај тоа, потребно е да се напише метод cheaperThan(Car* cars, int numCars, float price) кој ќе ги испечати сите објекти Car од низата cars со големина numCars чија цена е помала од price.



	char name[20];
	char lastName[20];
	int year;
	int month;
	int day;
	float price;

	int testCase;
	cin >> testCase;

	if (testCase == 1) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);

		cin >> year;
		cin >> month;
		cin >> day;
		Date date(year, month, day);

		cin >> price;
		Car car(lik, date,  price);

		car.print();
	}
	else if (testCase == 2) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);

		cin >> year;
		cin >> month;
		cin >> day;
		Date date(Date(year, month, day));

		cin >> price;
		Car car(lik, date,  price);
		car.print();
	}
	else {
		int numCars;
		cin >> numCars;

		Car cars[10];
		for (int i = 0; i < numCars; i++) {
			cin >> name;
			cin >> lastName;
			Person lik(name, lastName);

			cin >> year;
			cin >> month;
			cin >> day;
			Date date(year, month, day);

			cin >> price;
			cars[i] = Car(lik, date,  price);
		}
        float priceLimit;
        cin >> priceLimit;
		cheaperThan(cars, numCars, priceLimit);
	}


	return 0;
}