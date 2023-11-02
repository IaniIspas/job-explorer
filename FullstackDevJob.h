#ifndef JOBEXPLORER_FULLSTACKDEV_H
#define JOBEXPLORER_FULLSTACKDEV_H

#endif //JOBEXPLORER_FULLSTACKDEV_H

class FullstackDevJob : public BackendDevJob, public FrontendDevJob {
public:
    FullstackDevJob();
    FullstackDevJob(const string &mainLanguage, int salary, int yearsOfExperience, bool remote, bool available,
                    int noOfAdditionalTechnologies, const vector<string> &additionalTechnologies, int securitySkills, int uiUxExperience);
    FullstackDevJob(const FullstackDevJob &dev) : WebDevJob(dev), BackendDevJob(dev), FrontendDevJob(dev) {}
    FullstackDevJob& operator=(const FullstackDevJob& dev);

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    friend istream& operator >>(istream& in, FullstackDevJob& dev);
    friend ostream& operator <<(ostream& out, const FullstackDevJob& dev);
};

FullstackDevJob::FullstackDevJob() : WebDevJob(), BackendDevJob(), FrontendDevJob() {}

FullstackDevJob::FullstackDevJob(const string &mainLanguage, int salary, int yearsOfExperience, bool remote,
                                 bool available, int noOfAdditionalTechnologies,
                                 const vector<string> &additionalTechnologies, int securitySkills, int uiUxExperience)
        : WebDevJob(mainLanguage, salary, yearsOfExperience, remote, available, noOfAdditionalTechnologies, additionalTechnologies),
          BackendDevJob(mainLanguage, salary, yearsOfExperience, remote, available, noOfAdditionalTechnologies, additionalTechnologies, securitySkills),
          FrontendDevJob(mainLanguage, salary, yearsOfExperience, remote, available, noOfAdditionalTechnologies, additionalTechnologies, uiUxExperience) {}

FullstackDevJob &FullstackDevJob::operator=(const FullstackDevJob &dev) {
    if(this != &dev) {
        FrontendDevJob::operator=(dev);
        this->securitySkills = dev.securitySkills;
    }
    return *this;
}

istream &FullstackDevJob::read(istream &in) {
    FrontendDevJob::read(in);
    cout << "Security skills : ";
    in >> this->securitySkills;
    return in;
}

ostream &FullstackDevJob::write(ostream &out) const {
    FrontendDevJob::write(out);
    out << "Security skills : " << this->securitySkills << '\n';
    return out;
}

istream &operator>>(istream &in, FullstackDevJob &dev) {
    return dev.read(in);
}

ostream &operator<<(ostream &out, const FullstackDevJob &dev) {
    return dev.write(out);
}
