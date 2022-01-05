

#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    

    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);

    void GoToGameScene(Ref* pSender);
};

#endif // __MAINMENU_SCENE_H__
