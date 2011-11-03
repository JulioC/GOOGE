#ifndef INTRO_H
#define	INTRO_H

class Intro: public Scene {
public:
    Intro();
    virtual ~Intro();
    
private:
    Intro(const Intro&);
    const Intro& operator=(const Intro&);

};

#endif	/* INTRO_H */

