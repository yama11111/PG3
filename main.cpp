#include <stdio.h>
#include <list>

void DrawStringList(std::list<const char*> list) 
{
	for (std::list<const char*>::iterator itr = list.begin(); itr != list.end(); ++itr)
	{
		printf("%s\n", *itr);
	}
}

int main()
{
	// �R���(1970�N)
	std::list<const char*> YamanoteLine = 
	{
		"Osaki","Shinagawa","Tamachi","Hamamatuchyo","Shinbashi",
		"Yurakuchyo","Tokyo","Kanda","Akihabara","Okaramachi",
		"Ueno","Uguisudani","Nippori","Tabashi","Komagome",
		"Tabata","Otuka","Ikebukuro","Mejiro","Takadanobaba",
		"Shin-Okubo","Shinjyuku","Yoyogi","Harajyuku","Shibuya"
		"Ebisu","Mejiro","Gotanda",
	};

	printf("----- YamanoteLine(1970) -----\n");
	DrawStringList(YamanoteLine);
	printf("------------------------------\n");

	// 1971�N �����闢�w �ǉ�
	auto itr = YamanoteLine.begin();
	for (size_t i = 0; i < 13; i++)
	{
		itr++;
	}
	itr = YamanoteLine.insert(itr, "Nishi-Nippori");

	printf("----- YamanoteLine(2019) -----\n");
	DrawStringList(YamanoteLine);
	printf("------------------------------\n");
	
	// 2020�N ���փQ�[�g�E�F�C �ǉ�
	auto itr2 = YamanoteLine.begin();
	for (size_t i = 0; i < 2; i++)
	{
		itr2++;
	}
	itr2 = YamanoteLine.insert(itr2, "TakanawaGateway");

	printf("----- YamanoteLine(2022) -----\n");
	DrawStringList(YamanoteLine);
	printf("------------------------------\n");

	return 0;
}