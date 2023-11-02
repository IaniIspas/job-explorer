#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;

#include "IOInterface.h"
#include "CustomException.h"
#include "WebDevJob.h"
#include "BackendDevJob.h"
#include "FrontendDevJob.h"
#include "FullstackDevJob.h"
#include "Applicant.h"
#include "Company.h"
#include "InteractiveMenu.h"

int main() {
    InteractiveMenu *myMenu = myMenu->getInstance();
    myMenu -> mainMenu();
    return 0;
}
