#ifndef TEXT_H
#define	TEXT_H

#include "defs.h"
#include "Surface.h"

class Text: public Surface {
public:
    Text(SDL_Surface* screen, SDL_Surface* surface);
    virtual ~Text();

private:
    Text(const Text&);
    const Text& operator=(const Text&);

};

#endif	/* TEXT_H */

