#include "AppDelegate.h"
#include "Scene/SceneManager.h"
#include "GameLogic/PhysicLogic/PhysicManager.h"
USING_NS_CC;

static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(1280,720);

AppDelegate::AppDelegate() {
    
}

AppDelegate::~AppDelegate()
{
    cocos2d::Director::getInstance()->end();
}
//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    
    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages,
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("Catherine", Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("Catherine");
#endif
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
        glview->setFrameSize(480, 854);
#endif
        
        director->setOpenGLView(glview);
    }
    
    // turn on display FPS
    director->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.f / 60.f);
    
    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::EXACT_FIT);
    
    register_all_packages();

    
    DestoryColor::SceneManager::CreateSingleton();
    DestoryColor::SceneManager::Singleton().EnterScene(DestoryColor::e_Scene_Home);
    
    DestoryColor::PhysicManager::CreateSingleton();
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCLOG("applicationDidEnterBackground");
    Director::getInstance()->stopAnimation();
    
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCLOG("applicationWillEnterForeground");
    Director::getInstance()->startAnimation();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
