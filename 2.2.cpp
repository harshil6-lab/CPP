#include<iostream>
#include<vector>
using namespace std;

class Stu {
	int roll;
	string name;
	float m1, m2, m3;

public:
	Stu() {
		roll = 0;
		name = "Test";
		m1 = m2 = m3 = 0;
	}

	Stu(int r, string n, float a, float b, float c) {
		roll = r;
		name = n;
		m1 = a;
		m2 = b;
		m3 = c;
	}

	float avg() const {
		return (m1 + m2 + m3) / 3;
	}

	void show() const {
		cout << "Roll: " << roll << "\n";
		cout << "Name: " << name << "\n";
		cout << "Marks: " << m1 << ", " << m2 << ", " << m3 << "\n";
		cout << "Average: " << avg() << "\n";
	}

	int getRoll() const {
		return roll;
	}
};

void addDefault(vector<Stu>& s) {
	s.push_back(Stu());
	cout << "Default student added at index [" << s.size() - 1 << "]\n";
}

void addCustom(vector<Stu>& s) {
	int r;
	string nm;
	float a, b, c;
	cout << "Enter Roll, Name, Marks of 3 Subjects: ";
	cin >> r >> nm >> a >> b >> c;
	s.push_back(Stu(r, nm, a, b, c));
	cout << "Custom student added at index [" << s.size() - 1 << "]\n";
}

void showOne(const vector<Stu>& s) {

	cout << "\nAvailable Students:\n";
	for (int i = 0; i < s.size(); ++i) {
		cout << "Index [" << i << "] => Roll: " << s[i].getRoll() << "\n";
	}

	int idx;
	cout << "\nEnter index number to view student details: ";
	cin >> idx;

	if (idx >= 0 && idx < s.size()) {
		cout << "\n--- Student Details at Index [" << idx << "] ---\n";
		s[idx].show();
	} else {
		cout << "Invalid index!\n";
	}
}

int main() {
	vector<Stu> s;
	int ch;

	do {
		cout << "\n1 => Add Student (Default)\n";
		cout << "2 => Add Student (Custom)\n";
		cout << "3 => Show One Student (by Index)\n";
		cout << "0 => Exit\n";
		cout << "Enter choice: ";
		cin >> ch;

		switch (ch) {
			case 1:
				addDefault(s);
				break;
			case 2:
				addCustom(s);
				break;
			case 3:
				showOne(s);
				break;
			case 0:
				cout << "Exiting...\n";
				break;
			default:
				cout << "Enter valid choice!\n";
		}

	} while (ch != 0);
    cout<<"\n24CE049_HARSHIL\n";
	return 0;
}
