//
//  ObstacleLayer.hpp
//  WarGame
//
//  Created by 刘姐 on 2017/5/10.
//
//

#ifndef __ObstacleLayer_H__
#define __ObstacleLayer_H__

#include "cocos2d.h"
#include "Utilities/FSM/FsmInclude.h"
USING_NS_CC;

namespace DestoryColor {
    class ObstacleLayer : public Layer
    {
    public:
        ObstacleLayer();
        ~ObstacleLayer();
        void onEnter();
        void update(float dt);
        float getSleepTime();
        bool getSwitchSide();
        CREATE_FUNC(ObstacleLayer);
    protected:
        DECLARE_FSM(ObstacleLayer);
        DECLARE_STATE(CreateUp);
        DECLARE_STATE(CreateDown);
        DECLARE_STATE(Sleep);
    };
}

#endif /* ObstacleLayer_hpp */
