#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "ControlInterfaces/Displayable.h"
#include "Declarations.h"
#include "Surface.h"

namespace jer
{
    using std::shared_ptr;
    
    class
    {
    public:
        void operator()(SDL_Texture * const ptr)
        {
            SDL_DestroyTexture(ptr);
        };
    } SDL_TEXTURE_DELETER;
    
    class Texture: public Loadable, public virtual Displayable
    {
    private:
        shared_ptr<Surface> src;
        shared_ptr<SDL_Texture> tex;
        HardRenderer *ren;
        
    public:
        virtual ~Texture() {};
        Texture(const shared_ptr<Surface> &s, HardRenderer * const r): src(s), tex(nullptr, SDL_TEXTURE_DELETER), ren(r) {};
        Texture(const shared_ptr<SDL_Texture>& t, HardRenderer * const r): src(nullptr), tex(t), ren(r) {if(tex != nullptr) FileLoadable::load();};
        Texture(SDL_Texture * const t, HardRenderer * const r): Texture(shared_ptr<SDL_Texture>(t, SDL_TEXTURE_DELETER), r) {};
        Texture(const Surface& s, HardRenderer * const r): Texture(std::make_shared(s), r) {};
        Texture(const Texture& other): Loadable(other), src(other.src), tex(other.tex), ren(other.ren) {};
        Texture& operator= (const Texture &other);
        
    public:
        const bool operator== (const Texture &other) const;
        const bool operator!= (const Surface &other) const {return !(*this == other);};
        operator const bool() const {return bool(tex);};
        
    public:
        //SDL_Texture * const copy() const 
        const shared_ptr<const Surface> &getSource() {return src;};
        const Renderer * const getRen() const {return ren;};
        Renderer * const getRen() {return ren;};
        const shared_ptr<SDL_Texture> &getTex() {return tex;};
        const shared_ptr<const SDL_Texture> &getTex() const {return tex;};
        operator const SDL_Texture * const () const {return getTex().get();};
        operator SDL_Texture * const () {return getTex().get();};
        
    public:
        virtual const SUCCESS load() override;
        virtual const SUCCESS unload() override;
        virtual const SUCCESS display() const override;
    };
}

#endif /*_TEXTURE_H_*/