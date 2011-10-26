#ifndef VIDEOMANAGER_H
#define	VIDEOMANAGER_H

#include "Object.h"
#include "SDL/SDL.h"

class VideoManager: public Object {
public:
    static VideoManager* instance();
    
    ~VideoManager();
    
    bool init(int width, int height, const char* title);
    void release();

    void update();

    bool initiated() const;
    
    Image* loadImage(const char *filename, bool reload=false) {
        // se imagem não carregada:
                // carrega imagem [Image] no vetor interno
        // incrementa contador
        // retorna contador
    }
    
    void releaseImage(Image **img) {
        // decrementa contador
        // se contador == 0, libera referencia interna e da memória
        // seta o valor do ponteiro img para null
    }
    
    
    
private:
    VideoManager();
    VideoManager(const VideoManager&);
    const VideoManager& operator=(const VideoManager&);

    static VideoManager* _instance;
    
    bool _SDLInitiated;
    bool _TTFInitiated;
    
    SDL_Surface* _screen;
    
};

#endif	/* VIDEOMANAGER_H */

