#pragma once
#include "List.h"

class ListManager
{
private:
	// �@�\�񋓑�
	enum class Operation
	{
		Select,	 // �I��
		Display, // �\��
		Insert,  // �}��
		Edit,	 // �ҏW
		Delete,  // �폜
		End,	 // �I��
	};
	// �\���ݒ�񋓑�
	enum class DisplayDesc
	{
		Select, // �I��
		All, // �ꗗ�\��
		Specified, // �w��\��
	};
private:
	// ���X�g
	List list_;

	// ���͂��󂯎��p
	int inputNum_ = 0;

	// �@�\
	Operation ope_ = Operation::Select;
	// �\���ݒ�
	DisplayDesc disp_ = DisplayDesc::Select;

	// �I�������t���O (�\���p)
	bool isDispSelected_ = false;
	// ���͊����t���O (�\���p)
	bool isDispInputed_ = false;

	// �z��ԍ����͊����t���O (�}���p)
	bool isInsertItrInputed_ = false;
	// ���s�t���O (�}���p)
	bool isInsertFailed_ = false;
	// ���͊����t���O (�}���p)
	bool isInsertNumInputed_ = false;
	// �z��ԍ� (�}���p)
	int insertItr_ = -1;

	// �z��ԍ����͊����t���O (�ҏW�p)
	bool isEditItrInputed_ = false;
	// ���s�t���O (�ҏW�p)
	bool isEditFailed_ = false;
	// ���͊����t���O (�ҏW�p)
	bool isEditNumInputed_ = false;
	// �z��ԍ� (�ҏW�p)
	int editItr_ = -1;

	// �z��ԍ����͊����t���O (�폜�p)
	bool isDeleteItrInputed_ = false;
	// ���s�t���O (�폜�p)
	bool isDeleteFailed_ = false;
	// �z��ԍ� (�폜�p)
	int deleteItr_ = -1;
	// �폜�����v�f�̒l (�폜�p)
	int deleteNum_ = 0;

	// �`�抮���t���O
	bool isDrew_ = false;
public:
	// ������
	void Initialize();
	// �X�V
	void Update();
	// �`��
	void Draw();
	// �I����
	bool isEnd() { return ope_ == Operation::End; }
private:
	void UpdateSelect(); // �I���X�V
	void UpdateDisplay();// �\���X�V
	void UpdateInsert(); // �}���X�V
	void UpdateEdit();   // �ҏW�X�V
	void UpdateDelete(); // �폜�X�V
private:
	void DrawSelect(); // �I��`��
	void DrawDisplay();// �\���`��
	void DrawInsert(); // �}���`��
	void DrawEdit();   // �ҏW�`��
	void DrawDelete(); // �폜�`��
};

