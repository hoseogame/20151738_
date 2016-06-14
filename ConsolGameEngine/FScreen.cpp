#include <iostream>

#include "FScreen.h"

FScreen::FScreen()
{
	
}

FScreen::~FScreen()
{

}

void FScreen::InitScreen()
{
	ScreenPrint(0, 0, "����������������������������������������������");
	ScreenPrint(0, 1, "��                                          ��");
	ScreenPrint(0, 2, "��             �ব������                   ��");
	ScreenPrint(0, 3, "��                                          ��");
	ScreenPrint(0, 4, "��                        ///.   ��~~~      ��");
	ScreenPrint(0, 5, "��                       (^.^)              ��");
	ScreenPrint(0, 6, "��                      ���� ����           ��");
	ScreenPrint(0, 7, "��                         ����             ��");
	ScreenPrint(0, 8, "��                     ��  ����             ��");
	ScreenPrint(0, 9, "��                                          ��");
	ScreenPrint(0, 10, "��                                          ��");
	ScreenPrint(0, 11, "��       �� ���� ����  Go! Go!              ��");
	ScreenPrint(0, 12, "��                                          ��");
	ScreenPrint(0, 13, "��                                          ��");
	ScreenPrint(0, 14, "��       j :���� l : ������ k :��           ��");
	ScreenPrint(0, 15, "��                                          ��");
	ScreenPrint(0, 16, "��                                          ��");
	ScreenPrint(0, 17, "��                                          ��");
	ScreenPrint(0, 18, "��        ���ܦ�  space Ű�� �����ּ���     ��");
	ScreenPrint(0, 19, "��                                          ��");
	ScreenPrint(0, 20, "��                                          ��");
	ScreenPrint(0, 21, "��                                          ��");
	ScreenPrint(0, 22, "����������������������������������������������");
}

void FScreen::ReadyScreen(int stage)
{
	char string[100];

	ScreenPrint(0, 0, "����������������������������������������������");
	ScreenPrint(0, 1, "�����������������������᦭");
	ScreenPrint(0, 2, "�����������������������᦭");
	ScreenPrint(0, 3, "�����������������������᦭");
	ScreenPrint(0, 4, "�����������������������᦭");
	ScreenPrint(0, 5, "�����������������������᦭");
	ScreenPrint(0, 6, "�����������������������᦭");
	ScreenPrint(0, 7, "�����������������������᦭");
	ScreenPrint(0, 8, "�����������������������᦭");
	ScreenPrint(0, 9, "�����������������������᦭");
	ScreenPrint(0, 10, "��������                    ������᦭");
	sprintf_s(string, "��������     %d   ��������   ������᦭", stage + 1);
	ScreenPrint(0, 11, string);
	ScreenPrint(0, 12, "��������                    ������᦭");
	ScreenPrint(0, 13, "�����������������������᦭");
	ScreenPrint(0, 14, "�����������������������᦭");
	ScreenPrint(0, 15, "�����������������������᦭");
	ScreenPrint(0, 16, "�����������������������᦭");
	ScreenPrint(0, 17, "�����������������������᦭");
	ScreenPrint(0, 18, "�����������������������᦭");
	ScreenPrint(0, 19, "�����������������������᦭");
	ScreenPrint(0, 20, "�����������������������᦭");
	ScreenPrint(0, 21, "�����������������������᦭");
	ScreenPrint(0, 22, "�����������������������᦭");
	ScreenPrint(0, 23, "����������������������������������������������");
}

void FScreen::RunningScreen(int g_nStage, int LimitTime, int g_GameStartTime, int nGoalBall, int g_nBallCount)
{
	char string[100];

	ScreenPrint(0, 0, "����������������������������������������������");
	ScreenPrint(0, 1, "��                                          ��");
	ScreenPrint(0, 2, "��                                          ��");
	ScreenPrint(0, 3, "��                                          ��");
	sprintf_s(string, "��                                          ����������: %d", g_nStage + 1);
	ScreenPrint(0, 4, string);
	ScreenPrint(0, 5, "��                                          ��");
	sprintf_s(string, "�������������������������������������������������� �ð�: %d", LimitTime / 1000);
	ScreenPrint(0, 6, string);
	ScreenPrint(0, 7, "��                                          ��");
	sprintf_s(string, "��                                          ������ �ð�: %d", (clock() - g_GameStartTime) / 1000);
	ScreenPrint(0, 8, string);
	ScreenPrint(0, 9, "��                                          ��");
	sprintf_s(string, "��                                          ����ǥ ����: %d ", nGoalBall);
	ScreenPrint(0, 10, string);
	ScreenPrint(0, 11, "��                                          ��");
	sprintf_s(string, "��                                          ������ �� ����: %d ", g_nBallCount);
	ScreenPrint(0, 12, string);
	ScreenPrint(0, 13, "��                                          ��");
	sprintf_s(string, "��                                          ��");
	ScreenPrint(0, 14, string);
	ScreenPrint(0, 15, "��                                          ��");
	sprintf_s(string, "��                                          ��");
	ScreenPrint(0, 16, string);
	ScreenPrint(0, 17, "��                                          ��");
	ScreenPrint(0, 18, "��                                          ��");
	ScreenPrint(0, 19, "��                                          ��");
	ScreenPrint(0, 20, "��                                          ��");
	ScreenPrint(0, 21, "��                                          ��");
	ScreenPrint(0, 22, "��                                          ��");
	ScreenPrint(0, 23, "����������������������������������������������");
}

void FScreen::SuccessScreen()
{
	ScreenPrint(0, 0, "����������������������������������������������");
	ScreenPrint(0, 1, "��                                          ��");
	ScreenPrint(0, 2, "��                                          ��");
	ScreenPrint(0, 3, "��                                          ��");
	ScreenPrint(0, 4, "��                                          ��");
	ScreenPrint(0, 5, "��                                          ��");
	ScreenPrint(0, 6, "��                ////����                  ��");
	ScreenPrint(0, 7, "��               q ��  �� p                 ��");
	ScreenPrint(0, 8, "��               (��������)                 ��");
	ScreenPrint(0, 9, "��             �� �̼� ���� ��              ��");
	ScreenPrint(0, 10, "��                                          ��");
	ScreenPrint(0, 11, "��                                          ��");
	ScreenPrint(0, 12, "��                                          ��");
	ScreenPrint(0, 13, "��                                          ��");
	ScreenPrint(0, 14, "��                                          ��");
	ScreenPrint(0, 15, "��                                          ��");
	ScreenPrint(0, 16, "��                                          ��");
	ScreenPrint(0, 17, "��                                          ��");
	ScreenPrint(0, 18, "��                                          ��");
	ScreenPrint(0, 19, "��                                          ��");
	ScreenPrint(0, 20, "��                                          ��");
	ScreenPrint(0, 21, "��                                          ��");
	ScreenPrint(0, 22, "��                                          ��");
	ScreenPrint(0, 23, "����������������������������������������������");
}

void FScreen::FailureScreen()
{
	ScreenPrint(0, 0, "����������������������������������������������");
	ScreenPrint(0, 1, "��                                          ��");
	ScreenPrint(0, 2, "��                                          ��");
	ScreenPrint(0, 3, "��                                          ��");
	ScreenPrint(0, 4, "��                                          ��");
	ScreenPrint(0, 5, "��                                          ��");
	ScreenPrint(0, 6, "��                                          ��");
	ScreenPrint(0, 7, "��                                          ��");
	ScreenPrint(0, 8, "��                                          ��");
	ScreenPrint(0, 9, "��                                          ��");
	ScreenPrint(0, 10, "��                                          ��");
	ScreenPrint(0, 11, "��                    �̼� ���� !!!!        ��");
	ScreenPrint(0, 12, "��                                          ��");
	ScreenPrint(0, 13, "��                                          ��");
	ScreenPrint(0, 14, "��                 �ܦ�����                 ��");
	ScreenPrint(0, 15, "��                   ��  ��                 ��");
	ScreenPrint(0, 16, "��                  �����                ��");
	ScreenPrint(0, 17, "��                                          ��");
	ScreenPrint(0, 18, "��        �ٽ� �Ͻðڽ��ϱ�? (y/n)          ��");
	ScreenPrint(0, 19, "��                                          ��");
	ScreenPrint(0, 20, "��                                          ��");
	ScreenPrint(0, 21, "��                                          ��");
	ScreenPrint(0, 22, "����������������������������������������������");
}

void FScreen::ResultScreen(int stage)
{
	char string[100];
	ScreenPrint(0, 0, "����������������������������������������������");
	ScreenPrint(0, 1, "��                                          ��");
	ScreenPrint(0, 2, "��                                          ��");
	ScreenPrint(0, 3, "��             �ব������                   ��");
	ScreenPrint(0, 4, "��                                          ��");
	ScreenPrint(0, 5, "��                                          ��");
	ScreenPrint(0, 6, "��                                          ��");
	ScreenPrint(0, 7, "��                                          ��");
	sprintf_s(string, "��      ������ �������� :  %2d               ��", stage + 1);
	ScreenPrint(0, 8, string);
	ScreenPrint(0, 9, "��                                          ��");
	ScreenPrint(0, 10, "��                                          ��");
	ScreenPrint(0, 11, "��   ___�ƢƢ�___                           ��");
	ScreenPrint(0, 12, "��     (*^  ^*)                             ��");
	ScreenPrint(0, 13, "�� =====��==��=====                         ��");
	ScreenPrint(0, 14, "��                                          ��");
	ScreenPrint(0, 15, "��                                          ��");
	ScreenPrint(0, 16, "��                                          ��");
	ScreenPrint(0, 17, "��                                          ��");
	ScreenPrint(0, 18, "��                      ���ܦ�              ��");
	ScreenPrint(0, 19, "��                                          ��");
	ScreenPrint(0, 20, "��                                          ��");
	ScreenPrint(0, 21, "��                                          ��");
	ScreenPrint(0, 22, "����������������������������������������������");
}

void FScreen::Effect(int nX, int nY)
{
	ScreenPrint(nX, nY, "�� )) ���� (( ��");
	ScreenPrint(nX, nY + 1, "��(^^')/ ��(\"*')/");
	ScreenPrint(nX, nY + 2, "   ��       ��");
	ScreenPrint(nX, nY + 3, "  ����    ����");
}