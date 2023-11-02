#ifndef JOBEXPLORER_FRONTENDDEV_H
#define JOBEXPLORER_FRONTENDDEV_H

#endif //JOBEXPLORER_FRONTENDDEV_H


class FrontendDevJob : virtual public WebDevJob {
protected:
    int uiUxExperience;
public:
    FrontendDevJob();
    FrontendDevJob(const string &mainLanguage, int salary, int yearsOfExperience, bool remote, bool available,
                   int noOfAdditionalTechnologies, const vector<string> &additionalTechnologies, int uiUxExperience);
    FrontendDevJob(const FrontendDevJob &dev);
    FrontendDevJob& operator=(const FrontendDevJob& dev);

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    friend istream& operator >>(istream& in, FrontendDevJob& dev);
    friend ostream& operator <<(ostream& out, const FrontendDevJob& dev);

    int getUiUxExperience() const;
    void setUiUxExperience(int uiUxExperience);

};

FrontendDevJob::FrontendDevJob() : WebDevJob(), uiUxExperience(0) {}

FrontendDevJob::FrontendDevJob(const string &mainLanguage, int salary, int yearsOfExperience, bool remote,
                               bool available, int noOfAdditionalTechnologies,
                               const vector<string> &additionalTechnologies, int uiUxExperience)
        : WebDevJob(mainLanguage, salary, yearsOfExperience, remote, available, noOfAdditionalTechnologies,
                    additionalTechnologies), uiUxExperience(uiUxExperience) {}

FrontendDevJob::FrontendDevJob(const FrontendDevJob &dev) : WebDevJob(dev), uiUxExperience(dev.uiUxExperience) {}

FrontendDevJob &FrontendDevJob::operator=(const FrontendDevJob &dev) {
    if(this != &dev) {
        WebDevJob::operator=(dev);
        this->uiUxExperience = dev.uiUxExperience;
    }
    return *this;
}

istream &FrontendDevJob::read(istream &in) {
    WebDevJob::read(in);
    cout << "UI UX Experience : ";
    in >> this->uiUxExperience;
    return in;
}

ostream &FrontendDevJob::write(ostream &out) const {
    WebDevJob::write(out);
    out << "UI UX Experience : " << this->uiUxExperience << '\n';
    return out;
}

istream &operator>>(istream &in, FrontendDevJob &dev) {
    return dev.read(in);
}

ostream &operator<<(ostream &out, const FrontendDevJob &dev) {
    return dev.write(out);
}

int FrontendDevJob::getUiUxExperience() const {
    return uiUxExperience;
}

void FrontendDevJob::setUiUxExperience(int uiUxExperience) {
    FrontendDevJob::uiUxExperience = uiUxExperience;
}
