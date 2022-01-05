#include "PauseScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* PauseMenu::createScene()
{
    auto scene = Scene::create();
    auto layer = PauseMenu::create();
    scene->addChild(layer);
    return scene;
}


// on "init" you need to initialize your instance
bool PauseMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto resumeItem =
        MenuItemImage::create("Resume.png",
            "Resume.png",
            CC_CALLBACK_1(PauseMenu::Resume, this));
    auto retryItem =
        MenuItemImage::create("Retry.png",
            "Retry.png",
            CC_CALLBACK_1(PauseMenu::Retry, this));
    auto mainMenuItem =
        MenuItemImage::create("MainMenu.png",
            "MainMenu.png",
            CC_CALLBACK_1(PauseMenu::GoToMainMenuScene, this));
    auto menu = Menu::create(resumeItem, retryItem, mainMenuItem,
        NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 16);
    this->addChild(menu);




    auto obs = Sprite::create("ddd.jpg");
    obs->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 20));
    this->addChild(obs, -1);

    return true;
}
void PauseMenu::Resume(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}

void PauseMenu::GoToMainMenuScene(cocos2d::Ref* pSender)
{
    auto scene = MainMenu::createScene();
    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}
void PauseMenu::Retry(cocos2d::Ref* pSender)
{
    auto scene = GameScreen::createScene();
    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}