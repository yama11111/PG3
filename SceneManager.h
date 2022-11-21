#pragma once

enum class Scene 
{
	Title,
	NewPlay,
	GamePlay,
	GameClear,
};

class SceneManager final
{
private:
	Scene current_ = Scene::Title;
	Scene next_ = Scene::NewPlay;
public:
	void Change(const Scene& scene);
	void DrawCurrent();
	void DrawNext();
public:
	static SceneManager* GetInstance();
private:
	SceneManager() = default;
	~SceneManager() = default;
	SceneManager(const SceneManager& obj) = delete;
	SceneManager& operator=(const SceneManager& obj) = delete;
};

