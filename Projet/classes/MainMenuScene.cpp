#include "MainMenuScene.h"
#include "GameScene.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    auto scene = Scene::create();
    auto layer = MainMenu::create();
    scene->addChild(layer);
    return scene;
}


// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto menuTitle = MenuItemImage::create("piture.jpeg",
        "piture.jpeg");

    auto playItem = MenuItemImage::create("bouttona.png",
        "bouttona.png",
        CC_CALLBACK_1(MainMenu::GoToGameScene, this)); //fonction pour switcher au scene prochaine
    auto menu = Menu::create(menuTitle, playItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 2);
    this->addChild(menu);

    auto obs = Sprite::create("fff.jpeg");
    obs->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 20));
    this->addChild(obs, -1);

    int id = AudioEngine::play2d("song.mp3");

    return true;
}
void MainMenu::GoToGameScene(Ref* pSender)
{
    auto scene = GameScreen::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create
    (1.0, scene));
}