#include "GameScene3.h"
#include "GameOver.h"
#include "PauseScene.h"


USING_NS_CC;

Scene* GameOver::createScene()
{
    auto scene = Scene::create();
    auto layer = GameOver::create();
    scene->addChild(layer);
    return scene;
}


// on "init" you need to initialize your instance
bool GameOver::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto pauseItem =
        MenuItemImage::create("setting.png",
            "setting.png",
            CC_CALLBACK_1(GameOver::GoToPauseScene, this));
    
    auto menu = Menu::create(pauseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    auto back = Sprite::create("background.jpg");
    back->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ));
    this->addChild(back, -1);

    auto cong = Sprite::create("cong.png");
    cong->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 60));
    this->addChild(cong, 1);
    

   
    return true;
}
void GameOver::GoToPauseScene(cocos2d::Ref* pSender)
{
    auto scene = PauseMenu::createScene();
    Director::getInstance()->pushScene(scene);
}