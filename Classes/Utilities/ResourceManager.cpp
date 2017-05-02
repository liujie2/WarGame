#include "ResourceManager.h"

namespace DestoryColor
{
    static ResourceManager *s_sharedInstance = NULL;
    const std::string ResourceManager::Root = "Resources/";
    const std::string ResourceManager::Audio = "Audio";
    const std::string ResourceManager::Image = "Image";
    const std::string ResourceManager::Animation = "Animation";
    const std::string ResourceManager::Config = "Config";
    const std::string ResourceManager::Localization = "Localization";
    const std::string ResourceManager::Layout = "publish";
    const std::string ResourceManager::Font = "Font";
    const std::string ResourceManager::SFX = "SFX";
    const std::string ResourceManager::Items = "Items";

    ResourceManager::ResourceManager()
    {

    }
    
    ResourceManager::~ResourceManager()
    {

    }

    bool ResourceManager::init()
    {
        std::vector<std::string> paths;
        paths.push_back(Root);
        paths.push_back(getResourceRelativePath(Audio));
        paths.push_back(getResourceRelativePath(Image));
        paths.push_back(getResourceRelativePath(Animation));
        paths.push_back(getResourceRelativePath(Config));
        paths.push_back(getResourceRelativePath(Localization));
        paths.push_back(getResourceRelativePath(Layout));
        paths.push_back(getResourceRelativePath(Font));
        paths.push_back(getResourceRelativePath(SFX));
        paths.push_back(getResourceRelativePath(Items));

        cocos2d::FileUtils::getInstance()->setSearchPaths(paths);
        return true;
    }

    ResourceManager *ResourceManager::sharedInstance(void)
    {
        if (!s_sharedInstance)
        {
            s_sharedInstance = new ResourceManager;
        }
        return s_sharedInstance;
    }

    void ResourceManager::purgeInstance(void)
    {
        CC_SAFE_RELEASE_NULL(s_sharedInstance);
    }

    std::string ResourceManager::getResourceRelativePath(const std::string &path) const
    {
        return path;
    }
}
