#include <stdio.h>
#include <cstdlib>
#include "StationLine.h"

int main()
{
	StationLine keihinTohokuLine;
	keihinTohokuLine.Initialize();

	keihinTohokuLine.PushBack({ "Ofuna" });
	keihinTohokuLine.PushBack({ "Hongodai" });
	keihinTohokuLine.PushBack({ "Konandai" });
	keihinTohokuLine.PushBack({ "Yokodai" });
	keihinTohokuLine.PushBack({ "Shin-Sugita" });
	keihinTohokuLine.PushBack({ "Isogo" });
	keihinTohokuLine.PushBack({ "Negishi" });
	keihinTohokuLine.PushBack({ "Yamate" });
	keihinTohokuLine.PushBack({ "Ishikawacho" });
	keihinTohokuLine.PushBack({ "Kannai" });
	keihinTohokuLine.PushBack({ "Sakuragicho" });
	keihinTohokuLine.PushBack({ "Yokohama" });
	keihinTohokuLine.PushBack({ "Higashi-Kanagawa" });
	keihinTohokuLine.PushBack({ "Shin-Koyasu" });
	keihinTohokuLine.PushBack({ "Turumi" });
	keihinTohokuLine.PushBack({ "Kawasaki" });
	keihinTohokuLine.PushBack({ "Kamata" });
	keihinTohokuLine.PushBack({ "Omori" });
	keihinTohokuLine.PushBack({ "Oimachi" });
	keihinTohokuLine.PushBack({ "Shinagawa" });
	keihinTohokuLine.PushBack({ "Tamachi" });
	keihinTohokuLine.PushBack({ "Hamamatsucho" });
	keihinTohokuLine.PushBack({ "Yurakucho" });
	keihinTohokuLine.PushBack({ "Tokyo" });
	keihinTohokuLine.PushBack({ "Kanda" });
	keihinTohokuLine.PushBack({ "Akihabara" });
	keihinTohokuLine.PushBack({ "Okachimachi" });
	keihinTohokuLine.PushBack({ "Ueno" });
	keihinTohokuLine.PushBack({ "Uguisudani" });
	keihinTohokuLine.PushBack({ "Nippori" });
	keihinTohokuLine.PushBack({ "Nishi-Nippori" });
	keihinTohokuLine.PushBack({ "Tabata" });
	keihinTohokuLine.PushBack({ "Kami-Nakazato" });
	keihinTohokuLine.PushBack({ "Oji" });
	keihinTohokuLine.PushBack({ "Higashi-Jujo" });
	keihinTohokuLine.PushBack({ "Akabane" });
	keihinTohokuLine.PushBack({ "Kawaguchi" });
	keihinTohokuLine.PushBack({ "Warabi" });
	keihinTohokuLine.PushBack({ "Minami-Urawa" });
	keihinTohokuLine.PushBack({ "Urawa" });
	keihinTohokuLine.PushBack({ "Kita-Urawa" });
	keihinTohokuLine.PushBack({ "Yono" });
	keihinTohokuLine.PushBack({ "Saitama-Shintoshin" });
	keihinTohokuLine.PushBack({ "Omiya" });

	keihinTohokuLine.DrawUp();
	keihinTohokuLine.DrawDown();

	keihinTohokuLine.Insert({ "TakanawaGateway" }, 20);

	keihinTohokuLine.DrawUp();
	keihinTohokuLine.DrawDown();

	system("PAUSE");
	return 0;
}
