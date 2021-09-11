#include <random>
#include <iostream>

using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distribution(600, 800);

	int height = distribution(gen);
	double velocity = -1.62;
	double fuel = 100;
	double time = 0;

	double a;
	double A;
	
	double input;

	while(height > 0 && fuel > 0) {
		cout << "Time in seconds: " << time << endl
			<< "Fuel in %: " << fuel << endl
			<< "Height in meters: " << height << endl
			<< "Velocity in m/s: " << velocity << endl
			<< "Enter seconds of fire: ";
		cin >> input; cout << endl;
		time = time + (10 + input);
		fuel = fuel - (input * 10);

		// Engine off
		if (input == 0) {
			a = -1.62;
			velocity = velocity + a;
			height = height + velocity*10.0;
		}
		//Engine on
		else {
			A = 3.66;
			a = A - 1, 62;
			velocity = velocity + (a * input);
			height = height + velocity * input + a * (input * input) / 2.0;
		}

		// Landed on surface
		if (height <= 0) {
			if (velocity > -5) {
				cout << "---------------------------" << endl;
				cout << "Time in seconds: " << time << endl
					<< "Fuel in %: " << fuel << endl
					<< "Height in meters: " << height << endl
					<< "Velocity in m/s: " << velocity << endl;

				cout << "---NEWS:---" << endl << "Eagle has landed!" << endl;
			}
			else {
				cout << "---------------------------" << endl;
				cout << "Time in seconds: " << time << endl
					<< "Fuel in %: " << fuel << endl
					<< "Height in meters: " << height << endl
					<< "Velocity in m/s: " << velocity << endl;
				cout << "---NEWS:---" << endl << "You crashed!" << endl;
			}
		}
	}
}
