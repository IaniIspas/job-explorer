#ifndef JOBEXPLORER_IOINTERFACE_H
#define JOBEXPLORER_IOINTERFACE_H

#endif //JOBEXPLORER_IOINTERFACE_H

class IOInterface {
public:
    virtual istream& read(istream& in) = 0;
    virtual ostream& write(ostream& out) const = 0;

};