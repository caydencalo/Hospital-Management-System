#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <sstream>
#include <curl/curl.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ostringstream;
using std::stack;
using std::stringstream;
using std::time_t;
using std::tm;

void systemMenu();
int loginMenu();
void application();
