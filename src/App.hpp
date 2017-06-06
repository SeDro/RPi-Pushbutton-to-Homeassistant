#ifndef App_h
#define App_h
#include "Registry.hpp"
#include <thread>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <exception>

#define STOP "stop"
#define YES "yes"
#define CYCLE_TIME 100

using namespace std;

class Application {
	public:
		int run(int argc, char* argv[]);
	protected:
		Registry registry;
		void decodeParams(int argc, char* argv[]);
};

#endif
