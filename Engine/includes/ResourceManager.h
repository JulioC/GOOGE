#ifndef RESOURCEMANAGER_H
#define	RESOURCEMANAGER_H

#include <map>
#include <string>

#include "defs.h"
#include "Object.h"

template<typename T>
class ResourceManager: public Object {
protected:
    struct Resource {
        unsigned int refCount;
        T* resource;
    };
    
public:
    ResourceManager():
    _resources() {;
    }
    
    virtual ~ResourceManager() {
        while(!_resources.empty()) {
            Resource* res = _resources.begin()->second;
            delete res->resource;
            delete res;
            _resources.erase(_resources.begin());
        }
    }    
    
    T* get(const char* identifier) {
        if(_resources[identifier] == NULL) {
            
            T* obj = load(identifier);

            Resource* res = new Resource();
            res->resource = obj;
            res->refCount = 0;

            _resources[identifier] = res;
        }

        _resources[identifier]->refCount++;

        return _resources[identifier]->resource;
    }   
    
    void release(T* resource) {
        std::string identifier = identify(resource);

        _resources[identifier]->refCount--;
        if(_resources[identifier]->refCount == 0) {
            delete _resources[identifier]->resource;
            delete _resources[identifier];
            _resources.erase(identifier);
        }
    }
    
protected:
    virtual T* load(const char* identifier) = 0;
    virtual std::string identify(T* obj) = 0;
    
private:
    ResourceManager(const ResourceManager&);
    const ResourceManager& operator=(const ResourceManager&);
            
    std::map<std::string, Resource*> _resources;
};

#endif	/* RESOURCEMANAGER_H */

