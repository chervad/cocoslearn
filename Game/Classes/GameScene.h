#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScreen : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(GameScreen);

	void GoToPauseScene(Ref *pSender);
	void GoToGameOverScene(Ref *pSender);
};

#endif // __GAME_SCENE_H__
