// File Inventory.h -- Inventory class specification file
#ifndef INVENTORY_H
#define INVENTORY_H

// Inventory class declaration
class Inventory {
    private:
		
		int itemNumber,  // the item’s number
			quantity;    // the quantity of the item
		double cost;     // the wholesale per-unit cost of the item

    public:
		
		Inventory() {                  
			itemNumber = 0;
			quantity = 0;
			cost = 0.0;
		}

		Inventory(int id, int units, double unitCost) {
			itemNumber = id;
			quantity = units;
			cost = unitCost;
		}

		void setItemNumber(int id) {
			itemNumber = id;
		}

		void setQuantity(int units) {
			quantity = units;
		}

		void setCost(double unitCost) {
			cost = unitCost;
		}

		int getItemNumber() const {
			return itemNumber;
		}

		int getQuantity() const {
			return quantity;
		}

		double getCost() const {
			return cost;
		}

		double getTotalCost() const {
			return cost * quantity;
		}
};
#endif