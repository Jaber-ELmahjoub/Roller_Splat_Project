

#ifndef __GAME_SCENE_2_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScreen2 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();



    // implement the "static create()" method manually
    CREATE_FUNC(GameScreen2);

    void GoToPauseScene(Ref* pSender);
    
    cocos2d::DrawNode* drawNode;

};

#endif // __GAME_SCENE_H__
