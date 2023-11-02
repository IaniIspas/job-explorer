#ifndef JOBEXPLORER_APPLICANT_H
#define JOBEXPLORER_APPLICANT_H

#endif //JOBEXPLORER_APPLICANT_H

class Applicant {
private:
    static int indexId;
    const int Id;
    string firstName;
    string lastName;
    string email;
    string portfolio;
    int age;
    int yearsOfExperience;
public:
    Applicant();
    Applicant(const string &firstName, const string &lastName, const string &email,
              const string &portfolio, int age, int yearsOfExperience);
    Applicant(const Applicant& applicant);
    Applicant& operator=(const Applicant& applicant);

    friend istream& operator >>(istream& in, Applicant& applicant);
    friend  ostream& operator <<(ostream& out, const Applicant& applicant);

    static int getIndexId() {
        return indexId;
    }
    static void setIndexId(int indexId);

    const int getId() const;

    const string &getFirstName() const;
    void setFirstName(const string &firstName);

    const string &getLastName() const;
    void setLastName(const string &lastName);

    const string &getEmail() const;
    void setEmail(const string &email);

    const string &getPortfolio() const;
    void setPortfolio(const string &portfolio);

    int getAge() const;
    void setAge(int age);

    int getYearsOfExperience() const;
    void setYearsOfExperience(int yearsOfExperience);

    ~Applicant() {}
};

int Applicant::indexId = 0;

Applicant::Applicant() : Id(indexId++) {
    this->firstName = "N/A";
    this->lastName = "N/A";
    this->email = "N/A";
    this->portfolio = "N/A";
    this->age = 0;
    this->yearsOfExperience = 0;
}

Applicant::Applicant(const string &firstName, const string &lastName, const string &email, const string &portfolio,
                     int age, int yearsOfExperience) : Id(++indexId), firstName(firstName),
                                                       lastName(lastName), email(email),
                                                       portfolio(portfolio), age(age),
                                                       yearsOfExperience(yearsOfExperience) {}

Applicant::Applicant(const Applicant &applicant) : Id(applicant.Id) {
    this->firstName = applicant.firstName;
    this->lastName = applicant.lastName;
    this->email = applicant.email;
    this->portfolio = applicant.portfolio;
    this->age = applicant.age;
    this->yearsOfExperience = applicant.yearsOfExperience;
}

Applicant &Applicant::operator=(const Applicant &applicant) {
    if(this != &applicant) {
        this->firstName = applicant.firstName;
        this->lastName = applicant.lastName;
        this->email = applicant.email;
        this->portfolio = applicant.portfolio;
        this->age = applicant.age;
        this->yearsOfExperience = applicant.yearsOfExperience;
    }
    return *this;
}

istream &operator>>(istream &in, Applicant &applicant) {
    cout << "First name : "; in >> applicant.firstName;
    cout << "Last name : "; in >> applicant.lastName;
    cout << "Email : "; in >> applicant.email;
    cout << "Portfolio : "; in >> applicant.portfolio;
    cout << "Age : "; in >> applicant.age;
    cout << "Years of experience : "; in >> applicant.yearsOfExperience;
}

ostream &operator<<(ostream &out, const Applicant &applicant) {
    out << "Id : " << applicant.Id;
    out << "\nFirst name : " << applicant.firstName;
    out << "\nLast name : " << applicant.lastName;
    out << "\nEmail : " << applicant.email;
    out << "\nPortfolio : " << applicant.portfolio;
    out << "\nAge : " << applicant.age;
    out << "\nYears of experience : " << applicant.yearsOfExperience;
}

void Applicant::setIndexId(int indexId) {
    Applicant::indexId = indexId;
}

const string &Applicant::getFirstName() const {
    return firstName;
}

const int Applicant::getId() const {
    return Id;
}

void Applicant::setFirstName(const string &firstName) {
    Applicant::firstName = firstName;
}

const string &Applicant::getLastName() const {
    return lastName;
}

void Applicant::setLastName(const string &lastName) {
    Applicant::lastName = lastName;
}

void Applicant::setEmail(const string &email) {
    Applicant::email = email;
}

const string &Applicant::getEmail() const {
    return email;
}

const string &Applicant::getPortfolio() const {
    return portfolio;
}

void Applicant::setPortfolio(const string &portfolio) {
    Applicant::portfolio = portfolio;
}

int Applicant::getAge() const {
    return age;
}

void Applicant::setAge(int age) {
    Applicant::age = age;
}

int Applicant::getYearsOfExperience() const {
    return yearsOfExperience;
}

void Applicant::setYearsOfExperience(int yearsOfExperience) {
    Applicant::yearsOfExperience = yearsOfExperience;
}
