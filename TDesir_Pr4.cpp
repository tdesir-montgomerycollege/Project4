#include <iostream>
#include <fstream>
#include <iomanip>
/*
 * Class: CMSC140 CRN
 * Instructor:
 * Project 4
 * Computer/Platform/Compiler: HP Compaq Elite 8000 / Windows 10 / MS Visual Studio
 * Description: Average Employee Absence Calculator
 * Due Date: 11/15/20
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Timothy Desir

*/
using namespace std;
ofstream output("employeeAbsences.txt");
int NumOfEmployees();
int TotDaysAbsent(int);
double AverageAbsent(int, int);

int main() {
	int totNumEmployees, totMissedDays;
	double totAverageMissedDays;
	output << "EMPLOYEE ABSENCE REPORT\n" << //Employee Absences Text File Header
		"\t  Employee ID   Days Absent" << endl;
	cout << "Average employee absence calculator (days/year)" << endl;
	totNumEmployees = NumOfEmployees(); // Getting number of employees
	totMissedDays = TotDaysAbsent(totNumEmployees); //Getting employee ID and days missed for each employee
	totAverageMissedDays = AverageAbsent(totNumEmployees, totMissedDays); //Calculates average absent days per employee
	if (totNumEmployees > 1) { // Run if there is more than one employee
		output << "\nThe " << totNumEmployees << " employees were absent a total of " << totMissedDays << " days.\n"
			"The average number of days absent is " << showpoint << fixed << setprecision(1) <<
			totAverageMissedDays << " days." << endl;
	}
	else if(totNumEmployees == 1){
		if (totMissedDays > 1 && totAverageMissedDays > 1) { // Run if there is only one employee
			output << "\nWith only " << totNumEmployees << " employee absent for a total of " << totMissedDays << " days,\n" <<
				"the average number of days absent is obviously " << static_cast<int>(totAverageMissedDays) << " days." << endl;
		}
		else if (totMissedDays == 1 && totAverageMissedDays == 1) { // Run if only one employee and one absence
			output << "\nWith only " << totNumEmployees << " employee absent for a total of " << totMissedDays << " day,\n" <<
				"the average number of days absent is obviously " << static_cast<int>(totAverageMissedDays) << " day." << endl;
		}
		else { // Input validation - If number of employees is less than 1 
			cout << "Invalid statement. Exiting...";
			return 0;
		}
	}
	else { // Input validation - If number of employees is less than 1
		cout << "Invalid statement. Exiting...";
		return 0;
	}
	output << "Programmer: Timothy Desir" << endl; // Programmer signature
	cout << "Programmer: Timothy Desir" << endl <<
			"Assignment: Common Project 4" << endl <<
			"Due Date: 11/15/20" << endl;
}

int NumOfEmployees() {
	int numEmployees;
	cout << "Enter number of employees:";
	cin >> numEmployees;
	while (numEmployees <= 0) { // Function loops if number of employee is less than 0
		cout << "\nInvalid entry. The number of employees must be greater than 0.\n" <<
				"Enter number of employees:";
		cin >> numEmployees;
	}
	return numEmployees;
}

int TotDaysAbsent(int numEmployees) {
	int employeeID, employeeMissedDays, totalMissedDays = 0;
	for (int n = 1; n <= numEmployees; n++) { // Function loops until total number of employees is reached
		cout << "Enter employee ID:";
		cin >> employeeID;
		while (employeeID < 0) { // Loops while employee ID is negative
			cout << "\nInvalid entry. The employee ID must be a nonnegative value.\n" <<
					"Enter employee ID:";
			cin >> employeeID;
		}
		cout << "Enter number of days this employee was absent:";
		cin >> employeeMissedDays;
		while (employeeMissedDays < 0) { // Loops while employee absences is less than 0
			cout << "\nInvalid entry. The number of missed days must be greater than 0.\n"
				"Enter number of days this employee was absent:";
			cin >> employeeMissedDays;
		}
		output << "\t\t " << right << setw(4) << employeeID << "\t\t" << right << setw(3) << employeeMissedDays << endl;
		totalMissedDays += employeeMissedDays; // Sum variable to get total number of employee absences
	}
	return totalMissedDays;
}

double AverageAbsent(int numEmployees, int totalDaysMissed) { // Calculates average employee absences (absences/employee)
	double averageDaysMissed = static_cast<double>(totalDaysMissed) / numEmployees;
	return averageDaysMissed;
}