#include "App.hpp"
#include <wiringPi.h>

void Application::decodeParams(int argc, char* argv[]) {
}

int Application::run(int argc, char* argv[]) {

	cout << "Application starts" << endl;
	decodeParams(argc, argv);
	
	if(wiringPiSetup() < 0) {
		cout << "Error in initilisation of wiringPi" << endl;
		return -1;
	}
	
	pinMode(8, INPUT);
	
	int last_input_state = LOW;
	
	
	clock_t startClock, endClock;
	struct timespec pause = {0};
	
	string stop = registry.getValue(STOP);
	while(stop.empty() || stop != YES) {
		startClock = clock();
		
		int curr_input_state = digitalRead(8);
		
		if(curr_input_state != last_input_state) {
			last_input_state = curr_input_state;
			if(curr_input_state == HIGH) {
				cout << "Taster gedrückt" << endl;
			}
		}

		stop = registry.getValue(STOP);
		endClock = clock();
	
		pause.tv_nsec = CYCLE_TIME * 1000000L - (endClock - startClock) * 1000;
		nanosleep(&pause, (struct timespec *)NULL);
	}
	
	return 0;
}
