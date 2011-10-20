#ifndef SCENE_H
#define	SCENE_H

#include "Object.h"

class VideoManager;
class InputManager;

class Scene: public Object {
public:
    Scene();
    Scene(VideoManager* video, InputManager* input);
    virtual ~Scene();
    
    virtual bool init();
    virtual void release();
    
    virtual void update() = 0;
    
    void videoManager(VideoManager* video);
    void inputManager(InputManager* input);
    
private:
    Scene(const Scene&);
    const Scene& operator=(const Scene&);
    
    VideoManager* _video;
    InputManager* _input;
};

#endif	/* SCENE_H */

