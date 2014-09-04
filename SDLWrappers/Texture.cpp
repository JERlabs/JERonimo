#include "Texture.h"

namespace jer
{
    Texture& Texture::operator= (const Texture &other)
    {
        if(&other != this && *this != other)
        {
            if(*this || src != nullptr)
            {
                Texture cop(other);
                tex.swap(cop.tex);
                src.swap(cop.src);
            }
            
            ren = other.ren;
            
            if(other.isLoaded())
                Loadable::load();
            else
                Loadable::unload();
        }
        
        return *this;
    }
    
    const bool Texture::operator== (const Texture &other) const
    {
        if(isLoaded() && other.isLoaded())
            return tex == other.tex;
        else if(!isLoaded() && !other.isLoaded())
            return *src == *(other.src);
        else
            return false;
    }
    
    const Dimensions<int> Texture::getDim() const
    {
        Dimensions<int> ret;
        if(isLoaded())
            SDL_QueryTexture(tex.get(), NULL, NULL, ret.x().getPtr(), ret.y().getPtr());
        else if(src->isLoaded())
            ret = src->getDim();
        return ret;
    }
    
    const SUCCESS Texture::load()
    {
        if(isLoaded()) return 1;
        if(src == nullptr || ren == NULL) return FAILED;
        bool cleanSrc;
        switch(src->load())
        {
        case SUCCEEDED:
            cleanSrc = true;
            break;
        case 1:
            cleanSrc = false;
            break;
        default:
            return FAILED;
        }
        if(ren->load() < SUCCEEDED) return FAILED;
        
        tex.reset(SDL_CreateTextureFromSurface(*ren, *src), SDL_TEXTURE_DELETER);
        if(tex == nullptr) return FAILED;
        
        if(cleanSrc) src->unload();
        
        Loadable::load();
        return SUCCEEDED;
    }
    
    const SUCCESS Texture::unload()
    {
        if(isLoaded())
            tex.reset();
        Loadable::unload();
        return SUCCEEDED;
    }
    
    const SUCCESS Texture::blit(const Rectangle<int> &src, const Rectangle<int> &dest) const
    {
        if(ren != NULL && tex != nullptr)
        {
            if(ren->isLoaded() && isLoaded())
            {
                SDL_Rect srcRect(src), dstRect(dest);
                dstRect.x += getOffset().x();
                dstRect.y += getOffset().y();
                return SDL_RenderCopy(*ren, tex.get(), &srcRect, &dstRect);
            }
        }
        return FAILED;            
    }
    
    const SUCCESS Texture::blit(const Rectangle<int> &dest) const
    {
        if(ren != NULL && tex != nullptr)
        {
            if(ren->isLoaded() && isLoaded())
            {
                SDL_Rect dstRect(dest);
                dstRect.x += getOffset().x();
                dstRect.y += getOffset().y();
                return SDL_RenderCopy(*ren, tex.get(), NULL, &dstRect);
            }
        }
        return FAILED;            
    }
}