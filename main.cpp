#include <iostream>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

bool times = false;

static void timer(int sec) {
	std::this_thread::sleep_for(std::chrono::seconds(sec));
	times = true;
	cout << "Times up!" << endl;
}

int main() {
	int target = rand() % 100 + 1;
	int time_limit = 20;
	int guess=0;

	std::thread t1(timer, time_limit);

	cout << "Guess the number between 1 to 100. You have " << time_limit << " seconds" << endl;

	while (!times) {
		cout << "Enter your guess: "<<endl;
		cin >> guess;

		if (guess == target) {
			cout << "Congratulations you have guessed the target" << endl;
			times = true;
		}
		else if (guess < target) {
			cout << "Too low" << endl;
		}
		else if (guess > target) {
			cout << "Too high" << endl;
		}
	}

	if (guess != target) {
		cout << "The target was " << target << endl;
		cout << "Better luck next time" << endl;
	}

	if (!times) {
		t1.join();
	}
	return 0;
}