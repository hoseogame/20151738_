#include <iostream>

#include "HScreen.h"

HScreen::HScreen()
{
	g_nScreenIndex = 0;
}

HScreen::~HScreen()
{

}

void HScreen::InitScreen()
{

	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                          ┃");
	ScreenPrint(0, 2, "┃                                          ┃");
	ScreenPrint(0, 3, "┃                                          ┃");
	ScreenPrint(0, 4, "┃                   하트 담기 게임         ┃");
	ScreenPrint(0, 5, "┃                                          ┃");
	ScreenPrint(0, 6, "┃     ┏●┓                               ┃");
	ScreenPrint(0, 7, "┃        ♡                                ┃");
	ScreenPrint(0, 8, "┃          ♡                              ┃");
	ScreenPrint(0, 9, "┃            ♡♡                          ┃");
	ScreenPrint(0, 10, "┃              ♡ ♡                       ┃");
	ScreenPrint(0, 11, "┃               ♡                         ┃");
	ScreenPrint(0, 12, "┃          ♡                              ┃");
	ScreenPrint(0, 13, "┃                         ♡               ┃");
	ScreenPrint(0, 14, "┃      ♡♡  ♡♡        ♡                ┃");
	ScreenPrint(0, 15, "┃       ♡♡♡♡♡♡♡  ♡    ♡           ┃");
	ScreenPrint(0, 16, "┃        ♡♡♡♡♡♡   ♡                 ┃");
	ScreenPrint(0, 17, "┃         ♡♡♡♡♡                       ┃");
	ScreenPrint(0, 18, "┃          ♡♡♡    space 를 눌러 주세요  ┃");
	ScreenPrint(0, 19, "┃            ♡                            ┃");
	ScreenPrint(0, 20, "┃          ┗○┛                          ┃");
	ScreenPrint(0, 21, "┃                                          ┃");
	ScreenPrint(0, 22, "┃                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}

void HScreen::ReadyScreen(int stage)
{
	char string[100];

	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 2, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 3, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 4, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 5, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 6, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 7, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 8, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 9, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 10, "┃♡♡♡♡♡                    ♡♡♡♡♡♡┃");
	sprintf(string,    "┃♡♡♡♡♡      %d  스테이지   ♡♡♡♡♡♡┃", stage + 1);
	ScreenPrint(0, 11, string);
	ScreenPrint(0, 12, "┃♡♡♡♡♡                    ♡♡♡♡♡♡┃");
	ScreenPrint(0, 13, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 14, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 15, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 16, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 17, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 18, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 19, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 20, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 21, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 22, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}

void HScreen::RunningScreen(int stage, int heart, int aim, int count, int score)
{
	char string[100];

	ScreenPrint(0, 1, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 2, "┃〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓┃");
	ScreenPrint(0, 3, "┃                                          ┃");
	sprintf(string,	  "┃                                          ┃전체 하트 개수 : %d ", heart);
	ScreenPrint(0, 4, string);
	ScreenPrint(0, 5, "┃                                          ┃");
	sprintf(string,   "┃                                          ┃목표 하트 개수 : %d ", aim);
	ScreenPrint(0, 6, string);
	ScreenPrint(0, 7, "┃                                          ┃");
	sprintf(string,   "┃                                          ┃담은 하트 개수 : %d ", count);
	ScreenPrint(0, 8, string);
	ScreenPrint(0, 9, "┃                                          ┃");
	sprintf(string,   "┃                                          ┃점수 : %d ", score);
	ScreenPrint(0, 10, string);
	ScreenPrint(0, 11, "┃                                          ┃");
	ScreenPrint(0, 12, "┃                                          ┃");
	ScreenPrint(0, 13, "┃                                          ┃");
	ScreenPrint(0, 14, "┃                                          ┃");
	ScreenPrint(0, 15, "┃                                          ┃");
	ScreenPrint(0, 16, "┃                                          ┃");
	ScreenPrint(0, 17, "┃                                          ┃");
	ScreenPrint(0, 18, "┃                                          ┃");
	ScreenPrint(0, 19, "┃                                          ┃");
	ScreenPrint(0, 20, "┃                                          ┃");
	ScreenPrint(0, 21, "┃                                          ┃");
	ScreenPrint(0, 22, "┃                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
void HScreen::SuccessScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 2, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 3, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 4, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 5, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 6, "┃♡♡♡♡♡                    ♡♡♡♡♡♡┃");
	ScreenPrint(0, 7, "┃♡♡♡♡♡          스테이지  ♡♡♡♡♡♡┃");
	ScreenPrint(0, 8, "┃♡♡♡♡♡                    ♡♡♡♡♡♡┃");
	ScreenPrint(0, 9, "┃♡♡♡♡♡    미션 성공 !!!   ♡♡♡♡♡♡┃");
	ScreenPrint(0, 10, "┃♡♡♡♡♡                    ♡♡♡♡♡♡┃");
	ScreenPrint(0, 11, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 12, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 13, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 14, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 15, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 16, "┃♡♡♡♡♡♡♡            ♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 17, "┃♡♡♡♡♡♡♡            ♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 18, "┃♡♡♡♡♡♡♡            ♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 19, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 20, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 21, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 22, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}

void HScreen::FailureScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 2, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 3, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 4, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 5, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 6, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 7, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 8, "┃♨♨♨♨♨                      ♨♨♨♨♨┃");
	ScreenPrint(0, 9, "┃♨♨♨♨♨           스테이지   ♨♨♨♨♨┃");
	ScreenPrint(0, 10, "┃♨♨♨♨♨                      ♨♨♨♨♨┃");
	ScreenPrint(0, 11, "┃♨♨♨♨♨    미션 실패 !!!!    ♨♨♨♨♨┃");
	ScreenPrint(0, 12, "┃♨♨♨♨♨                      ♨♨♨♨♨┃");
	ScreenPrint(0, 13, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 14, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 15, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 16, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 17, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 18, "┃♨♨♨♨                          ♨♨♨♨┃");
	ScreenPrint(0, 19, "┃♨♨♨♨ 계속 하시겠습니까? (y/n) ♨♨♨♨┃");
	ScreenPrint(0, 20, "┃♨♨♨♨                          ♨♨♨♨┃");
	ScreenPrint(0, 21, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 22, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}

void HScreen::ResultScreen(int score)
{
	char string[100];

	ScreenPrint(0, 1, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 2, "┃                                          ┃");
	ScreenPrint(0, 3, "┃                                          ┃");
	ScreenPrint(0, 4, "┃         ((((    결과 보기    ))))        ┃");
	ScreenPrint(0, 5, "┃                                          ┃");
	ScreenPrint(0, 6, "┃               ┏●┓                     ┃");
	ScreenPrint(0, 7, "┃                   ♡                     ┃");
	ScreenPrint(0, 8, "┃                                          ┃");
	ScreenPrint(0, 9, "┃                                ♡        ┃");
	ScreenPrint(0, 10, "┃                                          ┃");
	sprintf(string,	   "┃         총점 :  %d          ♡ ♡       ┃", score);
	ScreenPrint(0, 11, string);
	ScreenPrint(0, 12, "┃                               ♡         ┃");
	ScreenPrint(0, 13, "┃                               ♡         ┃");
	ScreenPrint(0, 14, "┃                              ♡          ┃");
	ScreenPrint(0, 15, "┃                 ♡♡  ♡♡        ♡     ┃");
	ScreenPrint(0, 16, "┃               ♡♡♡♡♡♡♡  ♡    ♡   ┃");
	ScreenPrint(0, 17, "┃                ♡♡♡♡♡♡   ♡         ┃");
	ScreenPrint(0, 18, "┃                 ♡♡♡♡♡               ┃");
	ScreenPrint(0, 19, "┃                   ♡♡♡                 ┃");
	ScreenPrint(0, 20, "┃                     ♡                   ┃");
	ScreenPrint(0, 21, "┃                    ┗○┛                ┃");
	ScreenPrint(0, 22, "┃                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}