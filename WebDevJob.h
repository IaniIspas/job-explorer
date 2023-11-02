#ifndef JOBEXPLORER_DEVELOPER_H
#define JOBEXPLORER_DEVELOPER_H

#endif //JOBEXPLORER_DEVELOPER_H


class WebDevJob : public IOInterface {
protected:
    string mainLanguage;
    int salary;
    int yearsOfExperience;
    bool remote;
    bool available;
    int noOfAdditionalTechnologies;
    vector <string> additionalTechnologies;
public:
    WebDevJob();
    WebDevJob(const string &mainLanguage, int salary, int yearsOfExperience, bool remote, bool available,
              int noOfAdditionalTechnologies, const vector<string> &additionalTechnologies);
    WebDevJob(const WebDevJob& dev);
    WebDevJob &operator=(const WebDevJob& dev);

    string getMainLanguage() const;
    void setMainLanguage(const string &mainLanguage);
    int getSalary() const;
    void setSalary(int salary);
    int getYearsOfExperience() const;
    void setYearsOfExperience(int yearsOfExperience);
    bool isRemote() const;
    void setRemote(bool remote);

    bool isAvailable() const;

    void setAvailable(bool available);

    int getNoOfAdditionalTechnologies() const;
    void setNoOfAdditionalTechnologies(int noOfAdditionalTechnologies);

    vector<string> getAdditionalTechnologies() const;
    void setAdditionalTechnologies(const vector<string> &additionalTechnologies);

    friend istream& operator >>(istream& in, WebDevJob& developer);
    friend ostream& operator <<(ostream& out, const WebDevJob& developer);

    virtual istream& read(istream& in);
    virtual ostream& write(ostream& out) const;

    virtual ~WebDevJob() {}
};

WebDevJob::WebDevJob(const string &mainLanguage, int salary, int yearsOfExperience, bool remote, bool available, int noOfAdditionalTechnologies,
                     const vector<string> &additionalTechnologies) : mainLanguage(mainLanguage), salary(salary),
                                                                     yearsOfExperience(yearsOfExperience), remote(remote), available(available),
                                                                     noOfAdditionalTechnologies(noOfAdditionalTechnologies), additionalTechnologies(additionalTechnologies) {}

WebDevJob::WebDevJob() : mainLanguage("N/A"), salary(0), yearsOfExperience(0), remote(false), available(false), noOfAdditionalTechnologies(0), additionalTechnologies({}) {}

string WebDevJob::getMainLanguage() const {
    return mainLanguage;
}

void WebDevJob::setMainLanguage(const string &mainLanguage) {
    this->mainLanguage = mainLanguage;
}

int WebDevJob::getSalary() const {
    return salary;
}

void WebDevJob::setSalary(int salary) {
    this->salary = salary;
}

int WebDevJob::getYearsOfExperience() const {
    return yearsOfExperience;
}

void WebDevJob::setYearsOfExperience(int yearsOfExperience) {
    this->yearsOfExperience = yearsOfExperience;
}

bool WebDevJob::isRemote() const {
    return remote;
}

void WebDevJob::setRemote(bool remote) {
    this->remote = remote;
}

vector<string> WebDevJob::getAdditionalTechnologies() const {
    return additionalTechnologies;
}

void WebDevJob::setAdditionalTechnologies(const vector<string> &additionalTechnologies) {
    this->additionalTechnologies = additionalTechnologies;
}

int WebDevJob::getNoOfAdditionalTechnologies() const {
    return noOfAdditionalTechnologies;
}

void WebDevJob::setNoOfAdditionalTechnologies(int noOfAdditionalTechnologies) {
    this->noOfAdditionalTechnologies = noOfAdditionalTechnologies;
}

bool WebDevJob::isAvailable() const {
    return available;
}

void WebDevJob::setAvailable(bool available) {
    this->available = available;
}


istream &WebDevJob::read(istream &in) {
    cout << "Main language : ";
    in >> this->mainLanguage;
    cout << "Salary : ";
    in >> this->salary;
    cout << "Years of experience : ";
    in >> this->yearsOfExperience;
    cout << "Remote ? [1 - yes, 0 - no]";
    in >> this->remote;
    cout << "Available ? [1 - yes, 0 - no]";
    in >> this->available;
    cout << "Number of additional technologies : ";
    in >> noOfAdditionalTechnologies;
    string name;
    for(int i = 1; i <= noOfAdditionalTechnologies; i ++) {
        cout << i << " : ";
        in >> name;
        this->additionalTechnologies.push_back(name);
    }
    return in;
}

ostream &WebDevJob::write(ostream &out) const {
    out << "Main language : " << this->mainLanguage << '\n';
    out << "Salary : " << this->salary << '\n';
    out << "Years of experience : " << this->yearsOfExperience << '\n';
    out << "This job is ";
    if(!this->remote)
        out << "not ";
    out << "remote\n";
    out << "This job is ";
    if(!this->available)
        out << "not ";
    out << "available\n";
    out << "Additional technologies : ";
    for(const auto& tech : additionalTechnologies)
        out << tech << ", ";
    out << '\n';
    return out;
}

istream &operator>>(istream &in, WebDevJob &developer) {
    return developer.read(in);
}

ostream &operator<<(ostream &out, const WebDevJob &developer) {
    return developer.write(out);
}

WebDevJob::WebDevJob(const WebDevJob &dev) {
    this->mainLanguage = dev.mainLanguage;
    this->salary = dev.salary;
    this->yearsOfExperience = dev.yearsOfExperience;
    this->remote = dev.remote;
    this->noOfAdditionalTechnologies = dev.noOfAdditionalTechnologies;
    this->additionalTechnologies = dev.additionalTechnologies;
}

WebDevJob &WebDevJob::operator=(const WebDevJob &dev) {
    if(this != &dev) {
        this->mainLanguage = dev.mainLanguage;
        this->salary = dev.salary;
        this->yearsOfExperience = dev.yearsOfExperience;
        this->remote = dev.remote;
        this->noOfAdditionalTechnologies = dev.noOfAdditionalTechnologies;
        this->additionalTechnologies = dev.additionalTechnologies;
    }
    return *this;
}