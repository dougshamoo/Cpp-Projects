// File PayrollType.cpp -- Payroll class function implementation file
#include "PayrollType.h"

double Payroll::getGrossPay() {
	// declare variables to hold the values of normal and overtime hours, values depend on whether there was more than 40 hours worked or not
	double normalHours = (hoursWorked <= 40.0) ? hoursWorked : 40.0;
	double overtimeHours = (hoursWorked <= 40.0) ? 0.0 : hoursWorked - 40.0;

	return (normalHours * payRate) + (overtimeHours * payRate * 1.5);
}