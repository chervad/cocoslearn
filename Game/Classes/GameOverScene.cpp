#include "GameOverScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* GameOverScreen::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOverScreen::create();
	scene->addChild(layer);
    return scene;
}

bool GameOverScreen::init()
{
    if (!Layer::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	auto menuTitle = MenuItemImage::create("GameOverScreen/Game_Over.png"
								, "GameOverScreen/Game_Over.png");

	auto retryItem = MenuItemImage::create("GameOverScreen/Retry_Button.png"
										 , "GameOverScreen/Retry_Button(Click).png"
										 , CC_CALLBACK_1(GameOverScreen::GoToGameScene, this));

	auto mainMenuItem = MenuItemImage::create("GameOverScreen/Menu_Button.png"
											, "GameOverScreen/Menu_Button(Click).png"
											, CC_CALLBACK_1(GameOverScreen::GoToMainMenuScene, this));

	auto menu = Menu::create(menuTitle, retryItem, mainMenuItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(menu);

    return true;
}

void GameOverScreen::GoToGameScene(Ref *pSender) {
	auto scene = GameScreen::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameOverScreen::GoToMainMenuScene(Ref *pSender) {
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}
