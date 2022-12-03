#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <vector>

// 学生情報構造体
struct StudentInfo
{
	const char* name_{}; // 名前
	int classNum_ = 0; // クラス番号
	int studentNum_ = 0; // 出席番号
	// クラス番号と出席番号が同じならtrue
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
	result += (name[5] - 48) * 10; // 10の位
	result += (name[6] - 48);	   //  1の位

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
	std::vector<StudentInfo> infos; // 学生情報コンテナ

	// 番号付け
	std::for_each(students.begin(), students.end(),
		[&infos](const char* name)
		{
			// クラス番号( A : 0, B : 1, C : 2, D : 3 )
			int classNum = ClassNumber(name);
			
			// 出席番号
			int studentNum = StudentNumber(name);

			infos.push_back({ name, classNum, studentNum });
		});

	// ソート用変数初期化
	std::vector<StudentInfo> sortInfos = infos; // ソート用コンテナ
	std::vector<StudentInfo>::iterator infoItr = infos.end() - 1; // ソート用イテレータ
	StudentInfo replaceInfo;  // 置き換え用イテレータ

	// ソート
	while (true)
	{
		// 最初に戻す
		replaceInfo = *infos.begin();

		std::for_each(sortInfos.begin(), sortInfos.end(),
			[&replaceInfo](const StudentInfo& info)
			{
				// 比較して大きい時のみ入れ替え
				if (replaceInfo.classNum_ > info.classNum_) { return; }
				if (replaceInfo.studentNum_ > info.studentNum_) { return; }
				replaceInfo = info;
			});

		// ソートが完了した学生は初期化
		std::replace(sortInfos.begin(), sortInfos.end(), replaceInfo, StudentInfo());
		
		// 置き替え
		std::replace(infos.begin(), infos.end(), *infoItr, replaceInfo);

		infoItr--;

		// イテレータが最初まで来たらループを抜ける
		if (infos.begin() >= infoItr) { break; }
	}

	// 表示
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
		"LE2D_07_カメタ_ダイチ", "LE2C_06_カトウ_オウミ", "LE2B_15_チバ_タカシ", "LE2B_02_アスマ_ショウタ", "LE2B_04_イズミダ_マサト", 
		"LE2C_01_アラケ_ユウト", "LE2A_16_フクヤマ_トモアキ", "LE2D_16_フジサキ_ユウキ", "LE2D_05_オノ_マサチカ", "LE2B_08_オザワ_リュウト", 
		"LE2A_05_オキヤマ_クニアキ", "LE2D_15_ノハラ_コウセイ", "LE2C_02_イトウ_ヨシキ", "LE2C_20_マツダ_マサツグ", "LE2A_06_カタグチ_リクト", 
		"LE2A_03_イイジマ_カオル", "LE2B_22_フジタ_ケンタロウ", "LE2C_21_ミス_ミカド", "LE2B_14_タナカ_マサキ", "LE2A_12_タカハシ_ツバキ",
		"LE2C_12_サキヒロ_ユウキ", "LE2C_18_ナカヤマ_シュウヤ", "LE2C_09_キラ_タイチ", "LE2B_10_カミサト_マサトシ", "LE2B_12_シミズ_ショウ",
		"LE2D_13_シュウ_チチョウ", "LE2D_14_ツカモト_リク", "LE2D_01_アベ_コウキ", "LE2B_23_ホソイ_タイセイ", "LE2C_25_ヨシダ_ツバサ",
		"LE2A_24_ワダ_カズマ", "LE2A_20_ムラカミ_ハルヤ", "LE2B_17_ナガハマ_コウキ", "LE2D_08_コウノ_ケンシロウ", "LE2C_23_モリタ_ツバサ",
		"LE2C_19_ニイダ_シュウト", "LE2C_08_カワツジ_ショウタ", "LE2B_09_カネコ_リョウタ", "LE2C_16_トミナガ_ユウキ", "LE2C_15_タケイ_ユウシン", 
		"LE2B_07_オオニシ_ヒロキ", "LE2A_08_スギタ_ジュンヤ", "LE2C_10_コバシ_ハヤト", "LE2A_17_マルイチ_ユウキ", "LE2C_17_ナカジマ_コウキ", 
		"LE2B_29_ヤマシタ_ツバサ", "LE2A_09_スズキ_リオン", "LE2B_26_ミヤタ_コウキ", "LE2A_15_ニッタ_シンジ", "LE2A_10_ソン_カイヨウ", 
		"LE2C_22_モトヤス_ヒロユキ", "LE2A_22_ヤマモト_ナナキ", "LE2B_18_ニシザワ_ユウガ", "LE2B_27_モミヤマ_ケイタ", "LE2C_07_カマタ_フウヤ", 
		"LE2D_11_サトウ_タクミ", "LE2B_28_モリ_アツシ", "LE2B_05_イマイ_タケシ", "LE2A_14_テラオ_カイコウ", "LE2B_24_ミヤウチ_ナオキ", 
		"LE2A_13_タムラ_フミヤ", "LE2A_02_アベ_リュウタ", "LE2C_13_シズク_カズキ", "LE2D_04_エンドウ_アキラ", "LE2D_02_イノウエ_カノン",
		"LE2A_01_アイカワ_ハルヒコ", "LE2D_12_シ_トクオン", "LE2B_13_タシロ_カズマ", "LE2B_11_サノ_ソラ", "LE2B_19_ハトウ_トシキ", 
		"LE2D_17_ミヤシタ_タケル", "LE2C_04_エチゴ_シュン", "LE2D_03_イワタ_カズヤ", "LE2D_06_オノダ_ショウマ", "LE2C_05_エン_ケンシュウ", 
		"LE2B_21_フクオカ_シオン", "LE2B_16_ナウディー_ナウィル", "LE2B_20_ヒグチ_ユウヤ", "LE2B_30_ワタナベ_ライキ", "LE2A_23_ワクイ_ダイキ", 
		"LE2C_14_タカハシ_コウタ", "LE2B_25_ミヤザキ_レオ", "LE2A_18_マルヤマ_ユウキ", "LE2B_01_アカイケ_カケル", "LE2A_04_イイダ_ユウキ", 
		"LE2D_10_ササガワ_ヒカル", "LE2B_03_イグチ_シュンペイ", "LE2A_21_ヤマナカ_ルイ", "LE2C_11_サオトメ_トア", "LE2A_07_サノ_ユウヤ",
		"LE2A_19_ミズガキ_カオル", "LE2C_03_イワタ_ユウシロウ", "LE2A_11_タカイ_リクシ", "LE2C_24_ヤスナガ_ヨウスケ", "LE2D_09_サクライ_ヒロト", 
		"LE2B_06_オオガミ_タカト"
	};

	// 並び替え
	SortStudents(students);

	//// 表示
	//std::for_each(students.begin(), students.end(),
	//	[](const char* name) 
	//	{
	//		printf("%s\n", name); 
	//	});

	system("PAUSE");
	return 0;
}