#include <iostream>

// a program to guess the user's number

int main() {
	int low = 1;
	int high = 100;
	
	while (std::cin && low < high) {
		//std::cout << low << " " << high << "\n";
		int mid = low + (high-low) / 2 + 1;
		std::cout << "Is the number you are thinking of less than " << mid << "? ";

		char ans;
		if (std::cin >> ans) {
			switch (ans) {
			case 'y': case 'Y':
				high = mid - 1;
				break;
			case 'n': case 'N':
				low = mid;	
				break;
			default:
				std::cerr << "Invalid answer: " << ans << "\n";
			}
		}
	}

	if (std::cin) {
		std::cout << "Your number is : " << low << "\n";
	}

	return 0;
}

