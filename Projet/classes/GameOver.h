

#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

#include "cocos2d.h"


class GameOver : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();



    // implement the "static create()" method manually
    CREATE_FUNC(GameOver);

    void GoToPauseScene(Ref* pSender);
    
    cocos2d::DrawNode* drawNode;

};

#endif // __GAME_SCENE_H__
