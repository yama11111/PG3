#pragma once

// インターフェース
class IScene
{
protected:
	int inputNum_ = 0;
	bool isDrawn_ = false;
	bool isInput_ = false;
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
	int GetInputNum() { return inputNum_; }
	bool GetIsInput() { return isInput_; }
};

// タイトル
class TitleScene : public IScene
{
public:
	void Update() override;
	void Draw() override;
};

// ゲーム
class GameScene : public IScene
{
public:
	void Update() override;
	void Draw() override;
};

// ゲームオーバー
class GameOverScene : public IScene
{
public:
	void Update() override;
	void Draw() override;
};

// クリア
class ClearScene : public IScene
{
public:
	void Update() override;
	void Draw() override;
};