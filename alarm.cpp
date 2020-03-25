#include<iostream>
// for defining list this must be called
#include<list>
// for using sleep
#include<unistd.h>

int main() {

    // user defined variables
    int user_defined_time;
    int user_defined_break_time;

    // time controllers
    // pre-defined variables
    int time_controller = 0;

	// NOTE: THERE IS SOMETHING WRONG WITH THIS VARIABLE
	// WHEN I USE DIFFERENT VARIABLE LIKE THIS TO GRAP NEXT STEP WORK TIME
	// IT WORKS LIKE INFINITY LOOP NEVER RESPECTS BREAK TIME
	//
	// WHEN I DON'T USE SECOND VARIABLE USE ONLY user_defined_time VARIABLE
	// IT'S DOUBLING user_defined_time VARIABLE EVERY STEP
    int _user_defined_time;

    // completed work time collector
    // must be a list
    std::list<int> work_time_collector;
	// int work_time_collector;

    // get needed varibles from user

    // user_defined_time as integer
    std::cout << "time value as a integer: ";
    std::cin >> user_defined_time;

    // user defined break time as a integer
    std::cout << "break time value as a integer: ";
    std::cin >> user_defined_break_time;


    while (true) {
		// wait for a second to increase time_controller
        usleep(1*1000000);
        time_controller++;
        std::cout << time_controller << " seconds passed" << std::endl;

		// if user defined_time equals to time_controller at the moment
        if (user_defined_time == time_controller) {
            std::cout << "Your break time has begun" << std::endl;
            std::cout << "break time will be " << user_defined_break_time << "seconds" << std::endl;

			// give information to user 
			std::cout << "break time ticking.." << std::endl;

			// wait during the break time
			usleep(user_defined_break_time*1000000);

			for (int break_time_controller = 0; break_time_controller < user_defined_break_time; break_time_controller = break_time_controller + 1) {
				std::cout << break_time_controller << " seconds passed at break time" << std::endl;
        		usleep(1*1000000);
				if (break_time_controller == user_defined_break_time) {
					break;
				}
	    	}

            // collect a finished work time 
            // add "1" as a 
            work_time_collector.push_back(1);
			// work_time_collector++;

            // break time has done
            std::cout << "Your break time has done" << std::endl;
            std::cout << "your schedule will begin in 2.5 seconds" << std::endl;

            // wait for 2.5 second to let user prepare itself
            usleep(2.5*1000000);

            // next_user_defined_time = time_controller + user_defined_time;
			// resetting time_controller
			time_controller = 0;
            user_defined_time = user_defined_time + time_controller;
			std::cout << "new work time: " << user_defined_time << std::endl;

            // print size of the work_time_collected list
            // with this give information about the finished work times 
            std::cout << "new work time started.. collected worktimes: " << work_time_collector.size() << std::endl;
            continue;

        }
    }
	return EXIT_SUCCESS;
}
