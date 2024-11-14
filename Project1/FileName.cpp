#include<iostream>
using namespace std;

class Employee {
	string firstName;
	string lastName;
public:
	Employee() {
		firstName = "";
		lastName = "";
	}

	Employee(string firstname, string lastname) {
		SetFirstName(firstname);
		SetLastName(lastname);
	}

	string GetFirstName() const {
		return firstName;
	}

	void SetFirstName(string firstname) {
		if (firstname.length() > 2) {
			this->firstName = firstname;
		}
		else {
			cout << "Wrong First Name" << endl;
		}
	}

	string GetLastName() const {
		return lastName;
	}

	void SetLastName(string lastname) {
		if (lastname.length() > 2) {
			this->lastName = lastname;
		}
		else {
			cout << "Wrong Last Name" << endl;
		}
	}

	virtual double calculateSalary() = 0;
	virtual void display() {
		cout << "-----------------------------------------" << endl;
		cout << "Firstname: " << this->firstName << endl;
		cout << "Lastname: " << this->lastName << endl;
		cout << "Month Salary: " << this->calculateSalary() << endl;
	}
};

class Worker : public Employee {
	int hoursNumber;
	double hourlyRate;
public:
	Worker() : Employee() {
		hoursNumber = 0;
		hourlyRate = 0.0;
	}

	Worker(string firstname, string lastname, int hoursNumber, double hourlyRate) :Employee(firstname, lastname) {
		SetHoursNumber(hoursNumber);
		SetHourlyRate(hourlyRate);
	}

	int GetHoursNumber() const {
		return hoursNumber;
	}

	void SetHoursNumber(int hoursNumber) {
		if (hoursNumber > 10) {
			this->hoursNumber = hoursNumber;
		}
		else {
			cout << "Wrong Hours Number" << endl;
		}
	}

	double GetHourlyRate() const {
		return hourlyRate;
	}

	void SetHourlyRate(double hourlyRate) {
		if (hoursNumber > 2) {
			this->hourlyRate = hourlyRate;
		}
		else {
			cout << "Wrong Hourly Rate" << endl;
		}
	}

	double calculateSalary() override {
		if (hoursNumber > 40) {
			return 4 * (2 * hourlyRate * (hoursNumber - 40) + (40 * hourlyRate));
		}
		else {
			return 4 * (hoursNumber * hourlyRate);
		}
	}

    void display() override {
		Employee::display();
		cout << "Hours Number: " << this->hoursNumber << endl;
		cout << "Hourly Rate: " << this->hourlyRate << endl;
	}
};

class SalaryWorker : public Employee {
	double salary;
	int bonus;
public:
	SalaryWorker() : Employee() {
		salary = 0.0;
		bonus = 0;
	}

	SalaryWorker(string firstname, string lastname, double salary, int bonus) :Employee(firstname, lastname) {
		SetSalary(salary);
		SetBonus(bonus);
	}

	double GetSalary() const {
		return salary;
	}

	void SetSalary(double salary) {
		if (salary > 40) {
			this->salary = salary;
		}
		else {
			cout << "Wrong Salary" << endl;
		}
	}

	int GetBonus() const {
		return bonus;
	}

	void SetBonus(int bonus) {
		if (bonus > 5) {
			this->bonus = bonus;
		}
		else {
			cout << "Wrong Bonus" << endl;
		}
	}

	virtual double calculateBonus() = 0;

	double calculateSalary() override{
		return 4 * (salary + calculateBonus());
	}

	void display() override {
		Employee::display();
		cout << "Bonus: " << this->bonus << endl;
	}
};

class Salesman : public SalaryWorker {
	double planPercentage;
public:
	Salesman() : SalaryWorker() {
		planPercentage = 0.0;
	}

	Salesman(string firstname, string lastname, double salary, int bonus, double plan) : SalaryWorker(firstname, lastname, salary, bonus) {
		SetPlanPercentage(plan);
	}

	double GetPlanPercentage() const {
		return planPercentage;
	}

	void SetPlanPercentage(double plan) {
		if (plan > 10) {
			this->planPercentage = plan;
		}
		else {
			cout << "Wrong Plan Percentage" << endl;
		}
	}

	double calculateBonus() override {
		return (GetBonus() * planPercentage) / 100;
	}
	void display() override {
		SalaryWorker::display();
		cout << "Plan Percentage: " << planPercentage << "%" << endl;
	}
};

class Manager : public SalaryWorker {
	int clientCount;
public:
	Manager() : SalaryWorker() {
		clientCount = 0;
	}

	Manager(string firstname, string lastname, double salary, int bonus, int clientCount) : SalaryWorker(firstname, lastname, salary, bonus) {
		SetClientCount(clientCount);
	}

	int GetClientCount() const {
		return clientCount;
	}

	void SetClientCount(int clientCount) {
		if (clientCount > 100) {
			this->clientCount = clientCount;
		}
		else {
			cout << "Wrong Client Count" << endl;
		}
	}

	double calculateBonus() override {
		if (clientCount > 100) {
			return 2 * GetBonus();
		}
		else if (clientCount > 200) {
			return 3 * GetBonus();
		}
		else {
			return GetBonus();
		}
	}
	void display() override {
		SalaryWorker::display();
		cout << "Client Count: " << clientCount << endl;
	}
};

void main() {
	//Employee* employee1=new Worker("Narmin", "Alishova", 45, 2);
	//employee1->display();
	//cout << "Month Salary: " << employee1->calculateSalary();

	//Employee* employee2 = new Salesman("Nuray", "Adilzade", 60, 12, 20);
	//employee2->display();
	//cout << "Month Salary: " << employee2->calculateSalary();

	//Employee* employee3 = new Manager("Aysu", "Memmedova", 100, 30, 150);
	//employee3->display();
	//cout << "Month Salary: " << employee3->calculateSalary();

	Employee* employees[3];
	employees[0] = new Worker("Narmin", "Alishova", 45, 2);
	employees[1] = new Salesman("Nuray", "Adilzade", 60, 12, 20);
	employees[2] = new Manager("Aysu", "Memmedova", 100, 30, 150);

	for (auto employee : employees) {
		employee->display();
	}

}
