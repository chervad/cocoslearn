#include "PauseScene.h"
#include "SimpleAudioEngine.h"
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

bool PauseMenu::init()
{
    if (!Layer::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	auto resumeItem = MenuItemImage::create("PauseScreen/Resume_Button.png"
										  , "PauseScreen/Resume_Button(Click).png"
										  , CC_CALLBACK_1(PauseMenu::Resume, this));

	auto retryItem = MenuItemImage::create("PauseScreen/Retry_Button.png"
										 , "PauseScreen/Retry_Button(Click).png"
										 , CC_CALLBACK_1(PauseMenu::Retry, this)); 

	auto mainMenuItem = MenuItemImage::create("PauseScreen/Menu_Button.png"
											, "PauseScreen/Menu_Button(Click).png"
											, CC_CALLBACK_1(PauseMenu::GoToMainMenuScene, this));
	auto menu = Menu::create(resumeItem, retryItem, mainMenuItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(menu);

    return true;
}

void PauseMenu::Resume(Ref *pSender) {
	Director::getInstance()->popScene();
}

void PauseMenu::GoToMainMenuScene(Ref *pSender) {
	auto scene = MainMenu::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

void PauseMenu::Retry(Ref *pSender) {
	auto scene = GameScreen::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}
