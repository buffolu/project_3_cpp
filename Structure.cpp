//
// Created by igor on 14/06/2023.
//

#include "Structure.h"

void Structure::deposit(int amount) {
    if (amount > 0)
        hay += amount;
}

bool Structure::withdraw(int amount) {
    if (amount > 0 && amount <= hay) {
        hay -= amount;
	return true;	// successfully withdrawn
    }
    return false;	// failed to withdraw
}
