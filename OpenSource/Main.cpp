#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#pragma comment(lib, "Storm.lib")
#include <Storm.h>
#include <fstream>
#include <string>
#include <document.h>
#include <istreamwrapper.h>
#include <ostreamwrapper.h>
#include <prettywriter.h>

#include "Memory.h"

DWORD dwGame = (DWORD)LoadLibrary("Game.dll");
FARPROC procGameMain = GetProcAddress((HMODULE)dwGame, "GameMain");

HMODULE hStorm = LoadLibrary("Storm.dll");

rapidjson::Document doc;

const char* json = "War3.json";

LSTATUS CALLBACK BLZSRegQueryValueDword_Proxy(LPCSTR lpPath, LPCSTR lpValueName, LPDWORD lpcbData, LPBYTE lpData);

LSTATUS CALLBACK BLZSRegQueryValueString_Proxy(LPCSTR lpPath, LPCSTR lpValueName, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);

LSTATUS CALLBACK BLZSRegSetValueDword_Proxy(LPCSTR lpPath, LPCSTR lpValueName, DWORD dwType, DWORD dwData);

LSTATUS CALLBACK BLZSRegSetValueString_Proxy(LPCSTR lpPath, LPCSTR lpValueName, DWORD dwType, LPCSTR lpData);

//------------------------------------------------------------------------------------------------------------------------------------

BOOL CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hInstPrev, LPSTR lpCmdLine, int nCmdShow)
{
	if (!dwGame)
	{
		MessageBox(NULL, "Couldn't open Game.dll.", "Error", MB_ICONHAND);

		return FALSE;
	}

	if (!procGameMain)
	{
		MessageBox(NULL, "Game.dll is corrupt.", "Error", MB_ICONHAND);

		return FALSE;
	}

	std::ifstream file(json);
	if (!file)
	{
		std::ofstream file(json);
		file.close();
	}
	file.close();

	SFileOpenArchive("", NULL, NULL, NULL);
	
	call(dwGame + 0x5951, BLZSRegQueryValueString_Proxy);
	call(dwGame + 0x597F, BLZSRegQueryValueDword_Proxy);
	call(dwGame + 0x10F6, BLZSRegQueryValueDword_Proxy);
	call(dwGame + 0x5B8D, BLZSRegSetValueDword_Proxy);
	call(dwGame + 0x5B56, BLZSRegSetValueString_Proxy);

	stdcall<BOOL>(procGameMain, dwGame);
	FreeLibrary((HMODULE)dwGame);

	return FALSE;
}

//------------------------------------------------------------------------------------------------------------------------------------

LSTATUS CALLBACK BLZSRegQueryValueDword_Proxy(LPCSTR lpPath, LPCSTR lpValueName, LPDWORD lpcbData, LPBYTE lpData)
{
	std::ifstream file(json);

	rapidjson::IStreamWrapper isw(file);
	doc.ParseStream(isw);

	file.close();

	if (!doc.IsObject())
		doc.SetObject();

	const char* key = &lpPath[13];
	const char* war3 = "Warcraft III";

	if (!_strcmpi(lpPath, war3))
		key = war3;

	if (doc[key].HasMember(lpValueName))
	{
		if (doc[key][lpValueName].IsInt())
		{
			*(int*)lpData = doc[key][lpValueName].GetInt();

			return 1;
		}
	}
	else if (key == war3)
	{
		std::ofstream file(json);

		rapidjson::OStreamWrapper osw(file);
		rapidjson::PrettyWriter<rapidjson::OStreamWrapper> writer(osw);

		doc.AddMember(rapidjson::Value(key, strlen(key), doc.GetAllocator()), rapidjson::Value().SetObject(), doc.GetAllocator());
		doc[key].AddMember(rapidjson::Value(lpValueName, strlen(lpValueName), doc.GetAllocator()), rapidjson::Value(0), doc.GetAllocator());

		doc.Accept(writer);
		file.close();
	}

	return 0;
}

LSTATUS CALLBACK BLZSRegQueryValueString_Proxy(LPCSTR lpPath, LPCSTR lpValueName, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
	rapidjson::Document doc;

	std::ifstream file(json);

	rapidjson::IStreamWrapper isw(file);
	doc.ParseStream(isw);

	file.close();

	if (!doc.IsObject())
		doc.SetObject();

	const char* key = &lpPath[13];

	if (doc[key].HasMember(lpValueName))
		if (doc[key][lpValueName].IsString())
		{
			strcpy((char*)lpData, doc[key][lpValueName].GetString());

			return 1;
		}

	return 0;
}

LSTATUS CALLBACK BLZSRegSetValueDword_Proxy(LPCSTR lpPath, LPCSTR lpValueName, DWORD dwType, DWORD dwData)
{
	const char* key = &lpPath[13];

	if (!doc.HasMember(key))
		doc.AddMember(rapidjson::Value(key, strlen(key), doc.GetAllocator()), rapidjson::Value().SetObject(), doc.GetAllocator());
	
	if (!doc[key].HasMember(lpValueName))
		doc[key].AddMember(rapidjson::Value(lpValueName, strlen(lpValueName), doc.GetAllocator()), rapidjson::Value(0), doc.GetAllocator());
	
	std::ofstream file(json);

	rapidjson::OStreamWrapper osw(file);
	rapidjson::PrettyWriter<rapidjson::OStreamWrapper> writer(osw);

	doc[key][lpValueName].SetInt(dwData);

	doc.Accept(writer);
	file.close();

	return 1;
}

LSTATUS CALLBACK BLZSRegSetValueString_Proxy(LPCSTR lpPath, LPCSTR lpValueName, DWORD dwType, LPCSTR lpData)
{
	const char* key = &lpPath[13];

	if (!doc.HasMember(key))
		doc.AddMember(rapidjson::Value(key, strlen(key), doc.GetAllocator()), rapidjson::Value().SetObject(), doc.GetAllocator());

	if (!doc[key].HasMember(lpValueName))
		doc[key].AddMember(rapidjson::Value(lpValueName, strlen(lpValueName), doc.GetAllocator()), rapidjson::Value(lpData, strlen(lpData), doc.GetAllocator()), doc.GetAllocator());

	std::ofstream file(json);

	rapidjson::OStreamWrapper osw(file);
	rapidjson::PrettyWriter<rapidjson::OStreamWrapper> writer(osw);

	doc[key][lpValueName].SetString(lpData, strlen(lpData), doc.GetAllocator());

	doc.Accept(writer);
	file.close();

	return 1;
}