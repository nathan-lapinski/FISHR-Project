#include <iostream>
#include <sstream>
#include <unistd.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int input;
	cout << "*******************************************" << endl;
	cout << "*Welcome to the FISHR program, designed by*" << endl;
	cout << "*the Keller Lab Group at the University of*" << endl;
	cout << "*Colorado, Boulder. For questions or error*" << endl;
	cout << "*reporting, email lapinski@colorado.edu   *" << endl;
	cout << "*******************************************" << endl;
	cout << "To start the standard version of FISHR, type 1." << endl;
	cout << "To start the reduced RAM version of FISHR(which will not perform SH consolidations) type 2." << endl;
	std::string  line;
	while(std::getline(std::cin, line))
	{
		std::stringstream linestream(line);
		if(!(linestream >> input))
		{
			//input was NaN
			cout << "Error! Input was not a number. Try again." << endl;
			continue;
		}
		if((input != 1) && (input != 2))
		{
			//out of range
			cout << "Error! Input was not 1 or 2. Try again." << endl;
			continue;
		}
		char errorTest;
		if(linestream >> errorTest)
		{
			//extra junk in input
			cout << "Input contained more than just a number, try again." << endl;
			continue;
		}

		//otherwise, we are good
		break;
	}

	if(input == 1){
		//start FISHR as normal. Find a way to accept args
		cout << endl;
                cout << "Welcome to the general version of FISHR. This version will consolidate SH based on the " << endl;
                cout << "gap argument you provide. Simply paste or type your input below, just as you would " << endl;
                cout << "if you were running FISHR from the command line. Be sure to include the file name as the " << endl;
                cout << "very first argument." << endl;
		vector<string> vs;
		vector<string>::iterator vsi;
		string buffer;
		getline(cin,buffer);
		istringstream s2(buffer);
		string temp;
		while(s2 >> temp){
			vs.push_back(temp);
		}
		vsi = vs.begin();
	        vector<char *> argvv(vs.size() + 1);
		for(size_t i = 0; i != vs.size(); ++i){
			argvv[i] = &vs[i][0];
		}
		
		execvp("/work/KellerLab/opt/bin/ErrorFinder23.5",argvv.data());
	} else if(input == 2){
		cout << endl;
		cout << "Welcome to the reduced RAM version of FISHR. This version is recommended for those " << endl;
		cout << "working with large data sets. Simply paste or type your input below, just as you would " << endl;
		cout << "if you were running FISHR from the command line. Be sure to include the file name as the " << endl;
		cout << "very first argument." << endl;
		vector<string> vs;
                vector<string>::iterator vsi;
                string buffer;
                getline(cin,buffer);
                istringstream s2(buffer);
                string temp;
                while(s2 >> temp){
                        vs.push_back(temp);
                }
                vsi = vs.begin();
                vector<char *> argvv(vs.size() + 1);
                for(size_t i = 0; i != vs.size(); ++i){
                        argvv[i] = &vs[i][0];
                }
		execvp("/work/KellerLab/opt/bin/fishr_low_ram6.0",argvv.data());
	} else {
		//something went wrong.
		cout << "Some part of input was corrupted. Please try running the program again. Exiting..." << endl;
		return -1;	
	}
	
}
