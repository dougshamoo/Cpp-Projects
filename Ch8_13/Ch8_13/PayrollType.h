// File PayrollType.h -- Payroll class specification file
#ifndef PAYROLLTYPE_H
#define PAYROLLTYPE_H
class Payroll
{
	private:

		double payRate;      // holds an employee hourly pay rate
        double hoursWorked;  // an employee's hours worked

	public:

		Payroll() {
			payRate = 0;
			hoursWorked = 0;
		}

		// constructor checks for payR and hoursW to be positive
		// and sets payRate and hours worked; sets to zero if negative values are provided
		Payroll(double payR, double hoursW) {
			payRate = (payR > 0) ? payR : 0;
			hoursWorked = (hoursW > 0) ? hoursW : 0;
		}

		// mutator for payRate; checks for payR to be positive or sets to zero
		void setPayRate(double payR) {
			payRate = (payR > 0) ? payR : 0;
		}

		// mutator for hoursWorked; checks for positive hoursW or sets to zero
		void setHoursWorked(double hoursW) {
			hoursWorked = (hoursW > 0) ? hoursW : 0;
		}

		// accessor to return payRate
		double getPayRate() {
			return payRate;
		}

		// accessor to return hoursWorked
		double getHoursWorked() {
			return hoursWorked;
		}

		// computes and returns gross pay including OVERTIME as 1.5 * payRate * (hoursWorked - 40), if any.
		double getGrossPay(); // implemented in PayrollType.cpp implementation file.
};
#endif
