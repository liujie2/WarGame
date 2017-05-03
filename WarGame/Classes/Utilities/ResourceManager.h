#ifndef _RUSHGIRL_RESOURCEMANAGER_H_
#define _RUSHGIRL_RESOURCEMANAGER_H_

#include "cocos2d.h"
#include <string>

namespace DestoryColor
{
    class ResourceManager : public cocos2d::Ref
    {
    public:
        static const std::string Root;
        static const std::string Audio;
        static const std::string Image;
        static const std::string Animation;
        static const std::string Config;
        static const std::string Localization;
        static const std::string Layout;
        static const std::string Font;
        static const std::string SFX;
        static const std::string Items;

        virtual bool init(void);

        /** Gets the single instance of ResourceManager. */
        static ResourceManager *sharedInstance(void);

        /** Destroys the single instance of ResourceManager. */
        static void purgeInstance(void);

        std::string getResourceRelativePath(const std::string &path) const;
    private:
        /** ResourceManager constructor */
        ResourceManager();

        /** ResourceManager destructor */
        virtual ~ResourceManager();

    };
}

#endif