#ifndef JOBEXPLORER_MYEXCEPTION_H
#define JOBEXPLORER_MYEXCEPTION_H

#endif //JOBEXPLORER_MYEXCEPTION_H

class CustomException : public exception {
private:
    string msg;
public:

    CustomException(string msg) {
        this->msg = msg;
    }

    CustomException() {
        this->msg = "Unknown exception";
    }

    const char* what() const noexcept override {
        return msg.c_str();
    }
};