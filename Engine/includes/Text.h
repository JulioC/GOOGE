#ifndef TEXT_H
#define	TEXT_H

class Text {
public:
    Text();
    virtual ~Text();

private:
    Text(const Text&);
    const Text& operator=(const Text&);

};

#endif	/* TEXT_H */

