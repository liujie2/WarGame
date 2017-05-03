//
//  touchpull.h
//  WarGame
//
//  Created by futurebike on 17/5/2.
//
//

#ifndef touchpull_h
#define touchpull_h
#include "cocos2d.h"

using namespace cocos2d;

namespace DestoryColor
{
    class TouchPull : public Layer{
    public:
        TouchPull();
        virtual ~TouchPull();
        
        void onEnter();
        
        CREATE_FUNC(TouchPull);
        
        virtual bool onTouchBegan(Touch * pTouches, Event * pEvent);
        virtual void onTouchEnded(Touch * pTouches, Event * pEvent);
    private:
        Sprite* m_pull;
    };
}

#endif /* touchpull_h */
