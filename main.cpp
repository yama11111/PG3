#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <vector>

// �w�����\����
struct StudentInfo
{
	const char* name_{}; // ���O
	int classNum_ = 0; // �N���X�ԍ�
	int studentNum_ = 0; // �o�Ȕԍ�
	// �N���X�ԍ��Əo�Ȕԍ��������Ȃ�true
	bool operator==(const StudentInfo& comp) 
	{
		bool classComp = classNum_ == comp.classNum_;
		bool studentComp = studentNum_ == comp.studentNum_;
		return classComp && studentComp;
	}
};

int StudentNumber(const char* name)
{
	int result = 0;
	result += (name[5] - 48) * 10; // 10�̈�
	result += (name[6] - 48);	   //  1�̈�

	return result;
}

int ClassNumber(const char* name) 
{
	if (name[3] == 'A') { return 0; }
	if (name[3] == 'B') { return 1; }
	if (name[3] == 'C') { return 2; }
	if (name[3] == 'D') { return 3; }
	return -1;
}

void SortStudents(std::vector<const char*>& students) 
{
	std::vector<StudentInfo> infos; // �w�����R���e�i

	// �ԍ��t��
	std::for_each(students.begin(), students.end(),
		[&infos](const char* name)
		{
			// �N���X�ԍ�( A : 0, B : 1, C : 2, D : 3 )
			int classNum = ClassNumber(name);
			
			// �o�Ȕԍ�
			int studentNum = StudentNumber(name);

			infos.push_back({ name, classNum, studentNum });
		});

	// �\�[�g�p�ϐ�������
	std::vector<StudentInfo> sortInfos = infos; // �\�[�g�p�R���e�i
	std::vector<StudentInfo>::iterator infoItr = infos.end() - 1; // �\�[�g�p�C�e���[�^
	StudentInfo replaceInfo;  // �u�������p�C�e���[�^

	// �\�[�g
	while (true)
	{
		// �ŏ��ɖ߂�
		replaceInfo = *infos.begin();

		std::for_each(sortInfos.begin(), sortInfos.end(),
			[&replaceInfo](const StudentInfo& info)
			{
				// ��r���đ傫�����̂ݓ���ւ�
				if (replaceInfo.classNum_ > info.classNum_) { return; }
				if (replaceInfo.studentNum_ > info.studentNum_) { return; }
				replaceInfo = info;
			});

		// �\�[�g�����������w���͏�����
		std::replace(sortInfos.begin(), sortInfos.end(), replaceInfo, StudentInfo());
		
		// �u���ւ�
		std::replace(infos.begin(), infos.end(), *infoItr, replaceInfo);

		infoItr--;

		// �C�e���[�^���ŏ��܂ŗ����烋�[�v�𔲂���
		if (infos.begin() >= infoItr) { break; }
	}

	// �\��
	std::for_each(infos.begin(), infos.end(),
		[](const StudentInfo& info)
		{
			printf("%s\n", info.name_);
		});
}

int main()
{
	std::vector<const char*> students =
	{
		"LE2D_07_�J���^_�_�C�`", "LE2C_06_�J�g�E_�I�E�~", "LE2B_15_�`�o_�^�J�V", "LE2B_02_�A�X�}_�V���E�^", "LE2B_04_�C�Y�~�__�}�T�g", 
		"LE2C_01_�A���P_���E�g", "LE2A_16_�t�N���}_�g���A�L", "LE2D_16_�t�W�T�L_���E�L", "LE2D_05_�I�m_�}�T�`�J", "LE2B_08_�I�U��_�����E�g", 
		"LE2A_05_�I�L���}_�N�j�A�L", "LE2D_15_�m�n��_�R�E�Z�C", "LE2C_02_�C�g�E_���V�L", "LE2C_20_�}�c�__�}�T�c�O", "LE2A_06_�J�^�O�`_���N�g", 
		"LE2A_03_�C�C�W�}_�J�I��", "LE2B_22_�t�W�^_�P���^���E", "LE2C_21_�~�X_�~�J�h", "LE2B_14_�^�i�J_�}�T�L", "LE2A_12_�^�J�n�V_�c�o�L",
		"LE2C_12_�T�L�q��_���E�L", "LE2C_18_�i�J���}_�V���E��", "LE2C_09_�L��_�^�C�`", "LE2B_10_�J�~�T�g_�}�T�g�V", "LE2B_12_�V�~�Y_�V���E",
		"LE2D_13_�V���E_�`�`���E", "LE2D_14_�c�J���g_���N", "LE2D_01_�A�x_�R�E�L", "LE2B_23_�z�\�C_�^�C�Z�C", "LE2C_25_���V�__�c�o�T",
		"LE2A_24_���__�J�Y�}", "LE2A_20_�����J�~_�n����", "LE2B_17_�i�K�n�}_�R�E�L", "LE2D_08_�R�E�m_�P���V���E", "LE2C_23_�����^_�c�o�T",
		"LE2C_19_�j�C�__�V���E�g", "LE2C_08_�J���c�W_�V���E�^", "LE2B_09_�J�l�R_�����E�^", "LE2C_16_�g�~�i�K_���E�L", "LE2C_15_�^�P�C_���E�V��", 
		"LE2B_07_�I�I�j�V_�q���L", "LE2A_08_�X�M�^_�W������", "LE2C_10_�R�o�V_�n���g", "LE2A_17_�}���C�`_���E�L", "LE2C_17_�i�J�W�}_�R�E�L", 
		"LE2B_29_���}�V�^_�c�o�T", "LE2A_09_�X�Y�L_���I��", "LE2B_26_�~���^_�R�E�L", "LE2A_15_�j�b�^_�V���W", "LE2A_10_�\��_�J�C���E", 
		"LE2C_22_���g���X_�q�����L", "LE2A_22_���}���g_�i�i�L", "LE2B_18_�j�V�U��_���E�K", "LE2B_27_���~���}_�P�C�^", "LE2C_07_�J�}�^_�t�E��", 
		"LE2D_11_�T�g�E_�^�N�~", "LE2B_28_����_�A�c�V", "LE2B_05_�C�}�C_�^�P�V", "LE2A_14_�e���I_�J�C�R�E", "LE2B_24_�~���E�`_�i�I�L", 
		"LE2A_13_�^����_�t�~��", "LE2A_02_�A�x_�����E�^", "LE2C_13_�V�Y�N_�J�Y�L", "LE2D_04_�G���h�E_�A�L��", "LE2D_02_�C�m�E�G_�J�m��",
		"LE2A_01_�A�C�J��_�n���q�R", "LE2D_12_�V_�g�N�I��", "LE2B_13_�^�V��_�J�Y�}", "LE2B_11_�T�m_�\��", "LE2B_19_�n�g�E_�g�V�L", 
		"LE2D_17_�~���V�^_�^�P��", "LE2C_04_�G�`�S_�V����", "LE2D_03_�C���^_�J�Y��", "LE2D_06_�I�m�__�V���E�}", "LE2C_05_�G��_�P���V���E", 
		"LE2B_21_�t�N�I�J_�V�I��", "LE2B_16_�i�E�f�B�[_�i�E�B��", "LE2B_20_�q�O�`_���E��", "LE2B_30_���^�i�x_���C�L", "LE2A_23_���N�C_�_�C�L", 
		"LE2C_14_�^�J�n�V_�R�E�^", "LE2B_25_�~���U�L_���I", "LE2A_18_�}�����}_���E�L", "LE2B_01_�A�J�C�P_�J�P��", "LE2A_04_�C�C�__���E�L", 
		"LE2D_10_�T�T�K��_�q�J��", "LE2B_03_�C�O�`_�V�����y�C", "LE2A_21_���}�i�J_���C", "LE2C_11_�T�I�g��_�g�A", "LE2A_07_�T�m_���E��",
		"LE2A_19_�~�Y�K�L_�J�I��", "LE2C_03_�C���^_���E�V���E", "LE2A_11_�^�J�C_���N�V", "LE2C_24_���X�i�K_���E�X�P", "LE2D_09_�T�N���C_�q���g", 
		"LE2B_06_�I�I�K�~_�^�J�g"
	};

	// ���ёւ�
	SortStudents(students);

	//// �\��
	//std::for_each(students.begin(), students.end(),
	//	[](const char* name) 
	//	{
	//		printf("%s\n", name); 
	//	});

	system("PAUSE");
	return 0;
}