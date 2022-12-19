#pragma once

// �C���^�[�t�F�[�X
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

// �^�C�g��
class TitleScene : public IScene
{
public:
	void Update() override;
	void Draw() override;
};

// �Q�[��
class GameScene : public IScene
{
public:
	void Update() override;
	void Draw() override;
};

// �Q�[���I�[�o�[
class GameOverScene : public IScene
{
public:
	void Update() override;
	void Draw() override;
};

// �N���A
class ClearScene : public IScene
{
public:
	void Update() override;
	void Draw() override;
};