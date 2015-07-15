// DivSales.h file -- Class specification file for DivSales class.

#ifndef DIVSALES_H
#define DIVSALES_H

class DivSales {
    private:
	    static double totalSales;  // Total corporate sales across all divisions for entire year
		double quarters[4];        // Array of quarterly sales for this division

    public:
		DivSales() {
			quarters[0] = quarters[1] = quarters[2] = quarters[3] = 0;
		}

		void setQuarterSales(double q1, double q2, double q3, double q4) {
			quarters[0] = q1; quarters[1] = q2; quarters[2] = q3; quarters[3] = q4;
			totalSales += (q1 + q2 + q3 + q4);
		}

		double getQuarter(int index) {
			return quarters[index];
		}			

		double getTotalSales() {
			return totalSales;
		}
};
#endif