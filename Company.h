#ifndef JOBEXPLORER_COMPANY_H
#define JOBEXPLORER_COMPANY_H

#endif //JOBEXPLORER_COMPANY_H

template <class T>
class Company {
private:
    T* jobs;
    int size;
    int maxNoOfJobs;
public:
    Company();
    Company(T *jobs, int size, int maxNoOfJobs);
    Company(const Company& company);

    Company& operator=(const Company& company);

    template<typename U>
    friend ostream& operator<<(ostream& out, const Company<U>& company);

    void insert(T& job);
    void remove(int id);
    void getAvailableJobs();
    void getUnavailableJobs();
    T getJobById(int id);
};

template<class T>
Company<T>::Company() {
    this-> jobs = new T[30];
    this-> size = 0;
    this-> maxNoOfJobs = 30;
}

template<class T>
Company<T>::Company(T *jobs, int size,int maxNoOfJobs): jobs(jobs), size(size),maxNoOfJobs(maxNoOfJobs) {}

template<class T>
Company<T>::Company(const Company &company) {
    this->jobs = company.jobs;
    this->size = company.size;
    this->maxNoOfJobs = company.maxNoOfJobs;
}

template<class T>
Company<T> &Company<T>::operator=(const Company &company) {
    if(this != &company) {
        delete[] jobs;
        this->jobs = company.jobs;
        this->size = company.size;
        this->maxNoOfJobs = company.maxNoOfJobs;
    }
    return *this;
}

template<class T>
void Company<T>::getAvailableJobs() {
    for(int i = 0; i < this->size; i ++)
        if(this->jobs[i]->isAvailable())
            cout << i << " : \n" << *this->jobs[i] << '\n';
}

template<class T>
void Company<T>::getUnavailableJobs() {
    for(int i = 0; i < this->size; i ++)
        if(!this->jobs[i]->isAvailable())
            cout << i << " : \n" << *this->jobs[i] << '\n';
}

template<class T>
void Company<T>::insert(T &job) {
    if(this->size == maxNoOfJobs) {
        cout << "You can't apply to this company because it's full!";
    }
    else {
        this->jobs[this->size++] = job;
    }
}

template<class T>
void Company<T>::remove(int id) {
    if(id >= 0 && id <= this->maxNoOfJobs) {
        delete[] this->jobs[id];
        this->size --;
        for(int i = id; i < this->size; i ++)
            this->jobs[i] = this->jobs[i + 1];
    }
}

template<class T>
T Company<T>::getJobById(int id) {
    if(id >= 0 && id <= this->size)
        return this->jobs[id];
    else return nullptr;
}

template<typename U>
ostream &operator<<(ostream &out, const Company<U> &company) {
    for(int i = 0; i < company.size; i ++) {
        cout << i << " : " << *company.jobs[i] << '\n';
    }
}




