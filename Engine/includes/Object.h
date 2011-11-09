#ifndef OBJECT_H
#define	OBJECT_H

class Object {
public:
    Object();
    ~Object();
    
    unsigned int id() const;
    
private:
    Object(const Object&);
    const Object& operator=(const Object&);
    
    static unsigned int _nextid;
    
    unsigned int _id;

};

#endif	/* OBJECT_H */

