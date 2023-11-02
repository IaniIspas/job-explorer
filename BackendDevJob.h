#ifndef JOBEXPLORER_BACKENDDEV_H
#define JOBEXPLORER_BACKENDDEV_H

#endif //JOBEXPLORER_BACKENDDEV_H

class BackendDevJob : virtual public WebDevJob {
protected:
    int securitySkills;
public:
    BackendDevJob();
    BackendDevJob(const string &mainLanguage, int salary, int yearsOfExperience, bool remote, bool available,
                  int noOfAdditionalTechnologies, const vector<string> &additionalTechnologies, int securitySkills);
    BackendDevJob(const BackendDevJob &dev) : WebDevJob(dev), securitySkills(dev.securitySkills) {}
    BackendDevJob& operator=(const BackendDevJob& dev);

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    friend istream& operator >>(istream& in, BackendDevJob& dev);
    friend ostream& operator <<(ostream& out, const BackendDevJob& dev);

    int getSecuritySkills() const;
    void setSecuritySkills(int securitySkills);

};

BackendDevJob::BackendDevJob() : WebDevJob(), securitySkills(0) {}

BackendDevJob::BackendDevJob(const string &mainLanguage, int salary, int yearsOfExperience, bool remote, bool available,
                             int noOfAdditionalTechnologies, const vector<string> &additionalTechnologies,
                             int securitySkills)
        : WebDevJob(mainLanguage, salary, yearsOfExperience, remote, available, noOfAdditionalTechnologies,
                    additionalTechnologies), securitySkills(securitySkills) {}

BackendDevJob &BackendDevJob::operator=(const BackendDevJob &dev) {
    if(this != &dev) {
        WebDevJob::operator=(dev);
        this->securitySkills = dev.securitySkills;
    }
    return *this;
}

istream &BackendDevJob::read(istream &in) {
    WebDevJob::read(in);
    cout << "Security skills : ";
    in >> this->securitySkills;
    return in;
}

ostream &BackendDevJob::write(ostream &out) const {
    WebDevJob::write(out);
    out << "Security skills : " << this->securitySkills << '\n';
    return out;
}

istream &operator>>(istream &in, BackendDevJob &dev) {
    return dev.read(in);
}

ostream &operator<<(ostream &out, const BackendDevJob &dev) {
    return dev.write(out);
}

int BackendDevJob::getSecuritySkills() const {
    return securitySkills;
}

void BackendDevJob::setSecuritySkills(int securitySkills) {
    this->securitySkills = securitySkills;
}
