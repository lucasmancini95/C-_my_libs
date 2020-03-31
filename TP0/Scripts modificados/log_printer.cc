// cmdline - procesamiento de opciones en la l�nea de comando.
//
#include <string>
#include <cstdlib>
#include <iostream>
#include "log_msg.h"

using namespace std;



void log_msg_printer(fstream *log,char* msg)
{
    *log<< msg << endl;
}

void log_msg_printer(fstream *log,char* msg, int failed_operation)
{
    *log<< msg << failed_operation << endl;
}
