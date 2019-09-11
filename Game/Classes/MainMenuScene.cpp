#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
	auto scene = Scene::create();
	auto layer = MainMenu::create();
	scene->addChild(layer);
    return scene;
}

bool MainMenu::init()
{
    if (!Layer::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	auto menuTitle = MenuItemImage::create("MainMenuScreen/Game_Title.png"
										 , "MainMenuScreen/Game_Title.png");

	auto playItem = MenuItemImage::create("MainMenuScreen/Play_Button.png"
										, "MainMenuScreen/Play_Button(Click).png"
										, CC_CALLBACK_1(MainMenu::GoToGameScene, this));

	auto menu = Menu::create(menuTitle, playItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(menu);

    return true;
}

void MainMenu::GoToGameScene(Ref *pSender) {
	auto scene = GameScreen::createScene();

	Director::getInstance()->replaceScene(scene);
}
