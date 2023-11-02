#ifndef JOBEXPLORER_INTERACTIVEMENU_H
#define JOBEXPLORER_INTERACTIVEMENU_H

#endif //JOBEXPLORER_INTERACTIVEMENU_H

class InteractiveMenu {
private:
    vector <Applicant*> applicants;
    Company <WebDevJob*> jobs;
    vector <string> applications;
    map <int, string> handleApplications;

    static InteractiveMenu* object;
    InteractiveMenu() {}
    InteractiveMenu(const InteractiveMenu& interactiveMenu) {
        object = interactiveMenu.object;
    }
    InteractiveMenu& operator=(const InteractiveMenu& interactiveMenu) {
        if(this != &interactiveMenu) {
            object = interactiveMenu.object;
        }
        return *this;
    }
public:
    static InteractiveMenu* getInstance() {
        if(!object)
            object = new InteractiveMenu();
        return object;
    }
    void applicantCrud();
    void jobCrud();
    void mainMenu();
};

InteractiveMenu *InteractiveMenu::object = 0;

void InteractiveMenu::applicantCrud() {
    int option = 1;
    while(option) {
        cout << "-- APPLICANT MENU --\n";
        cout << "0 - EXIT\n";
        cout << "1 - Create\n";
        cout << "2 - Read\n";
        cout << "3 - Update\n";
        cout << "4 - Delete\n";
        cout << "I want : "; cin >> option;
        switch(option) {
            case 0 : {
                option = 0;
                break;
            }
            case 1: {
                auto* applicant = new Applicant();
                cin >> *applicant;
                applicants.push_back(applicant);
                break;
            }
            case 2: {
                for(const auto& applicant : applicants)
                    cout << *applicant << '\n';
                break;
            }
            case 3: {
                cout << "Applicant ID : ";
                int id;
                bool found = false;
                cin >> id;
                for(const auto& applicant : applicants)
                    if((*applicant).getId() == id) {
                        found = true;
                        break;
                    }
                if(!found) {
                    cout << "The applicant was not found\n";
                    break;
                }
                cout << "What do you want to update about applicant ? \n";
                cout << "1 - First name\n";
                cout << "2 - Last name\n";
                cout << "3 - Email\n";
                cout << "4 - Portfolio\n";
                cout << "5 - Age\n";
                cout << "6 - Years of experience\n";
                int opt;
                cin >> opt;
                switch(opt) {
                    case 1: {
                        string firstName;
                        cout << "New First name : ";
                        cin >> firstName;
                        applicants[id]->setFirstName(firstName);
                        break;
                    }
                    case 2: {
                        string lastName;
                        cout << "New Last name : ";
                        cin >> lastName;
                        applicants[id]->setLastName(lastName);
                        break;
                    }
                    case 3: {
                        string email;
                        cout << "New email : ";
                        cin >> email;
                        applicants[id]->setEmail(email);
                        break;
                    }
                    case 4: {
                        string portfolio;
                        cout << "New Portfolio : ";
                        cin >> portfolio;
                        applicants[id]->setPortfolio(portfolio);
                        break;
                    }
                    case 5: {
                        int age;
                        cout << "New age : ";
                        cin >> age;
                        applicants[id]->setAge(age);
                        break;
                    }
                    case 6: {
                        int experience;
                        cout << "New years of experience : ";
                        cin >> experience;
                        applicants[id]->setYearsOfExperience(experience);
                        break;
                    }
                    default : {
                        cout << "You must introduce a number between 1 and 6\n";
                        break;
                    }
                }
                break;
            }
            case 4: {
                int id, index = 0;
                cout << "Applicant ID : ";
                cin >> id;
                bool found = false;
                for(const auto& applicant : applicants) {
                    if (applicant->getId() == id) {
                        applicants.erase(applicants.begin() + index);
                        found = true;
                        break;
                    }
                    ++index;
                }
                if(!found) {
                    cout << "The applicant was not found!\n";
                }
                break;
            }
            default: {
                cout << "You must introduce a number between 0 and 4!\n";
                break;
            }
        }
    }
}

void InteractiveMenu::jobCrud() {
    int option = 1;
    while(option) {
        cout << "-- JOB MENU --\n";
        cout << "0 - EXIT\n";
        cout << "1 - Create\n";
        cout << "2 - Read\n";
        cout << "3 - Update\n";
        cout << "4 - Delete\n";
        cout << "I want : "; cin >> option;
        switch(option) {
            case 0:
                option = 0;
                break;
            case 1: {
                cout << "What job do you want to create ? [0 - Frontend | 1 - Backend | 2 - Fullstack] \n Command : ";
                int command;
                cin >> command;
                switch(command) {
                    case 0 : {
                        WebDevJob* job = new FrontendDevJob();
                        cin >> *job;
                        jobs.insert(job);
                        break;
                    }
                    case 1 : {
                        WebDevJob* job = new BackendDevJob();
                        cin >> *job;
                        jobs.insert(job);
                        break;
                    }
                    case 2 : {
                        WebDevJob* job = new FullstackDevJob();
                        cin >> *job;
                        jobs.insert(job);
                        break;
                    }
                    default : {
                        cout << "You must introduce a number between 0 and 2!\n";
                        break;
                    }
                }
            }
            case 2: {
                cout << jobs;
                break;
            }
            case 3: {
                cout << "Job ID : ";
                int id;
                cin >> id;
                WebDevJob* job = jobs.getJobById(id);

                if(job == nullptr) {
                    cout << "The job was not found\n";
                    break;
                }

                cout << "What do you want to update about job ? \n";
                cout << "1 - Main Language\n";
                cout << "2 - Salary\n";
                cout << "3 - Years of experience\n";
                cout << "4 - Remote working\n";
                cout << "5 - Job availability\n";
                cout << "6 - Additional technologies\n";

                if (FullstackDevJob* fullstack = dynamic_cast<FullstackDevJob*>(job)) {
                    cout << "7 - Security skills\n";
                    cout << "8 - UI UX Experience\n";
                }
                else if (FrontendDevJob* frontend = dynamic_cast<FrontendDevJob*>(job)) {
                    cout << "7 - UI UX Experience\n";
                }
                else {
                    cout << "7 - Security skills\n";
                }
                int opt;
                cin >> opt;
                if(opt <= 6) {
                    switch (opt) {
                        case 1: {
                            string mainLanguage;
                            cout << "New Main Language : ";
                            cin >> mainLanguage;
                            job->setMainLanguage(mainLanguage);
                            break;
                        }
                        case 2: {
                            string salary;
                            cout << "New Salary : ";
                            cin >> salary;
                            job->setMainLanguage(salary);
                            break;
                        }
                        case 3: {
                            int yearsOfExperience;
                            cout << "New Years of Experience : ";
                            cin >> yearsOfExperience;
                            job->setYearsOfExperience(yearsOfExperience);
                            break;
                        }
                        case 4: {
                            bool remote;
                            cout << "Remote ? [0 - no, 1 - yes]";
                            cin >> remote;
                            job->setRemote(remote);
                            break;
                        }
                        case 5: {
                            bool available;
                            cout << "Job Available ? [0 - no, 1 - yes]";
                            cin >> available;
                            job->setAvailable(available);
                            break;
                        }
                        case 6: {
                            int noOfAdditionalTechnologies;
                            vector<string> additionalTechnologies;
                            cout << "Number of additional technologies : ";
                            cin >> noOfAdditionalTechnologies;
                            string name;
                            for (int i = 1; i <= noOfAdditionalTechnologies; i++) {
                                cout << i << " : ";
                                cin >> name;
                                additionalTechnologies.push_back(name);
                            }
                            job->setNoOfAdditionalTechnologies(noOfAdditionalTechnologies);
                            job->setAdditionalTechnologies(additionalTechnologies);
                            break;
                        }
                    }
                }
                else {
                    if (FullstackDevJob* fullstack = dynamic_cast<FullstackDevJob*>(job)) {
                        if(opt == 7) {
                            cout << "New security skills :";
                            int securitySkills;
                            cin >> securitySkills;
                            auto* fullStack = dynamic_cast<FullstackDevJob*>(const_cast<WebDevJob*>(job));
                            fullStack->setSecuritySkills(securitySkills);
                        }
                        else {
                            cout << "New UI UX Experience :";
                            int uiUxExperience;
                            cin >> uiUxExperience;
                            auto* fullStack = dynamic_cast<FullstackDevJob*>(const_cast<WebDevJob*>(job));
                            fullStack->setUiUxExperience(uiUxExperience);
                        }
                    }
                    else if(FrontendDevJob* frontend = dynamic_cast<FrontendDevJob*>(job)) {
                        cout << "New UI UX Experience :";
                        int uiUxExperience;
                        cin >> uiUxExperience;
                        auto* frontEnd = dynamic_cast<FrontendDevJob*>(const_cast<WebDevJob*>(job));
                        frontEnd->setUiUxExperience(uiUxExperience);
                    }
                    else if(BackendDevJob* backend = dynamic_cast<BackendDevJob*>(job)) {
                        cout << "New Security Skills :";
                        int securitySkills;
                        cin >> securitySkills;
                        auto* backEnd = dynamic_cast<BackendDevJob*>(const_cast<WebDevJob*>(job));
                        backEnd->setSecuritySkills(securitySkills);
                    }
                    else throw CustomException("Job-ul nu exista!");
                }
                break;
            }
            case 4: {
                int id, index = 0;
                cout << "Job ID : ";
                cin >> id;
                if(jobs.getJobById(id) == nullptr) {
                    cout << "The applicant was not found!\n";
                }
                else jobs.remove(id);
                break;
            }
            default: {
                cout << "You must introduce a number between 0 and 4\n";
                break;
            }
        }
    }
}

void InteractiveMenu::mainMenu() {
    int optionMain = 1;
    while(optionMain) {
        cout << "-- MAIN MENU --\n";
        cout << "0 - EXIT\n";
        cout << "1. Owner Menu\n";
        cout << "2. Applicant Menu\n";
        cout << "Option : ";
        cin >> optionMain;
        if (optionMain == 1) {
            cout << "0. EXIT!\n";
            cout << "1. Applicant CRUD\n";
            cout << "2. Job CRUD\n";
            cout << "3. See job application\n";
            cout << "4. Accept [1] | Reject [0] job application\n";
            cout << "Option : ";
            int ownerOpt;
            cin >> ownerOpt;
            while (ownerOpt) {
                switch (ownerOpt) {
                    case 0 : {
                        cout << "Exiting the Owner Menu. Goodbye!\n";
                        ownerOpt = 0;
                        break;
                    }
                    case 1 : {
                        this->applicantCrud();
                        ownerOpt = 0;
                        break;
                    }
                    case 2 : {
                        this->jobCrud();
                        ownerOpt = 0;
                        break;
                    }
                    case 3 : {
                        if(applications.size() == 0) {
                            cout << "There is no application in this moment!\n";
                            ownerOpt = 0;
                            break;
                        }
                        for (int i = 0; i < applications.size(); i++)
                            cout << i << " : " << this->applications[i] << '\n';
                        ownerOpt = 0;
                        break;
                    }
                    case 4 : {
                        cout << "Introduce the id of the application you want to handle : ";
                        int applicationId;
                        cin >> applicationId;

                        WebDevJob* job = jobs.getJobById(int(this->applications[applicationId][0]) - '0');

                        if(job == nullptr) {
                            ownerOpt = 0;
                            break;
                        }

                        cout << "Accept [1] - Reject [0] ? ";
                        bool state;
                        cin >> state;
                        this->applications.erase(this->applications.begin() + applicationId);
                        if(state)
                            job->setAvailable(false);
                        ownerOpt = 0;
                        break;
                    }
                    default: {
                        cout << "You must introduce a number between 0 and 4\n";
                        break;
                    }
                }
            }
        } else if(optionMain == 2) {
            cout << "0. EXIT\n";
            cout << "1. Available jobs\n";
            cout << "2. Unavailable jobs\n";
            cout << "3. Apply for a job\n";
            cout << "Option : ";
            int applicantOpt;
            cin >> applicantOpt;
            while (applicantOpt) {
                switch (applicantOpt) {
                    case 0 : {
                        applicantOpt = 0;
                        break;
                    }
                    case 1 : {
                        this->jobs.getAvailableJobs();
                        applicantOpt = 0;
                        break;
                    }
                    case 2 : {
                        this->jobs.getUnavailableJobs();
                        applicantOpt = 0;
                        break;
                    }
                    case 3 : {
                        cout << "Applicant ID : ";
                        int applicantId;
                        cin >> applicantId;
                        bool found = false;
                        for (const auto &applicant: applicants)
                            if ((*applicant).getId() == applicantId) {
                                found = true;
                                break;
                            }
                        if (!found) {
                            cout << "The applicant you want to use does not exist!\n";
                            break;
                        }
                        cout << "Job ID you want to apply : ";
                        int index;
                        cin >> index;
                        WebDevJob *job = jobs.getJobById(index);
                        if (job != nullptr) {
                            cout << *job;
                            if (!(*job).isAvailable()) {
                                cout << "The job you want to apply is unavailable\n";
                                applicantOpt = 0;
                                break;
                            }
                            //job->setAvailable(false);
                            applications.push_back(
                                    to_string(index) + " [Job ID], " + to_string(index) + " [Applicant ID]");

                        } else {
                            cout << "The job you want to apply does not exist\n";
                        }
                        applicantOpt = 0;
                        break;
                    }
                }
            }
        }
        else {
            optionMain = 0;
        }
    }
}
