#include "iGraphics.h"
#include "time.h"
#include "HighScore.h"


int background, background1, background21, hplay, play, play1, easy, medium, hard, high_score, high_score_bg, about, author, control, control_detail, settings_mode, exits, level_select, game_mode, single_player, multi_player, difficulty, path,music_on,music_off;
int level, level_1, level_2, level_3, level_4, level_5, back;
int gameState = -1;

int finishline;
int menu;
int reload;

int winImage;
int loseImage;
bool musicON = true;

//int obs1, obs2, obs3, obs4, obs5, obs6, obs7, obs8, obs9, obs10;

//int obsCo1, obsCo2, obsCo3, obsCo4, obsCo5, obsCo6, obsCo7, obsCo8, obsCo9, obsCo10;

 //= {obs1, obs2, obs3, obs4, obs5, obs6, obs7, obs8, obs9, obs10};

bool p = true;
bool jumpBool = false;
bool jump = false;
bool duckBool = false;
bool runBool = true;

int check;

char strTimer[10];
char strGems[10];

int timerValueE = 40;
int timerValueM = 50;
int timerValueH = 60;

bool timerBool = true;
int gemsCount = 0;

int character[10];
int characterJump[10];
int characterJumpUp;

int characterCoX = 95;
int characterCoY = 120;
int characterIndex = 0;
int jumpLimit = 25;

int characterDx = 50;
int characterDy = 50;

int BGround[10];
int obs[30];
int jems[20];    // jems array to load jems images  


struct jemsStructure{     // jems Co-ordinate structure
	int x;
	int y;
	bool show = true;
}jemsCo[11];

struct jemsStructure1{     // jems Co-ordinate structure
	int x;
	int y;
	bool show = true;
}jemsCo1[16];

struct jemsStructure2{     // jems Co-ordinate structure
	int x;
	int y;
	bool show = true;
}jemsCo2[21];

struct BG
{
	int x;
	int y;
}bgCo[10];

struct obsCoStructure
{
	int x;
	int y;
}obsCo[20];

struct obsCoStructure1
{
	int x;
	int y;
}obsCo1[25];

struct obsCoStructure2
{
	int x;
	int y;
}obsCo2[30];


/*
void obstaclesSetToCordinate()
{
	

	
	iShowImage(obsCo[1].x, 345, 50, 50, obs1);
	iShowImage(obsCo[2].x, 345, 50, 50, obs1);
	iShowImage(obsCo[3].x, 345, 50, 50, obs1);
	iShowImage(obsCo[4].x, 345, 50, 50, obs1);
	iShowImage(obsCo[5].x, 345, 50, 50, obs1);
	iShowImage(obsCo[6].x, 345, 50, 50, obs1);
	iShowImage(obsCo[7].x, 345, 50, 50, obs1);
	iShowImage(obsCo[8].x, 345, 50, 50, obs1);
	iShowImage(obsCo[8].x, 345, 50, 50, obs1);
	iShowImage(obsCo[10].x, 345, 50, 50, obs1);
	
}*/
void pauseMethod()
{
	iPauseTimer(0);
	iPauseTimer(1);
	iPauseTimer(2);
	iPauseTimer(3);
	iPauseTimer(4);
}

void resumeMethod()
{
	iResumeTimer(0);
	iResumeTimer(1);
	iResumeTimer(2);
	iResumeTimer(3);
	iResumeTimer(4);
}



void valueInitilize()
{
	timerValueE = 30;
	timerValueM = 40;
	timerValueH = 50;
	gemsCount = 0;
	timerBool = true;

}
void iDraw()
{

	iClear();
	//iSetColor(255, 255, 255);

	
	iShowImage(0, 0, 1000, 600, background);

	// Main Menu
	if (gameState == -1){
		iSetColor(255, 255, 255);
		iShowImage(0, 0, 1000, 600, background);
		iShowImage(400, 263, 184, 63, play);
		iShowImage(400, 198, 180, 61, high_score);
		iShowImage(400, 127, 180, 70, control);
		iShowImage(400, 68, 180, 61, about);
		iShowImage(400, 5, 180, 61, exits);
		if (musicON == true)
		{
			iShowImage(850, 500, 50, 50, music_off);
		}
		else if (musicON == false)
		{
			iShowImage(850, 500, 50, 50, music_on);
		}
		
		//iShowImage(910, 500, 50, 50, music_off);
	}

	//After Play is Clicked 

	else if (gameState == 0){
		iSetColor(255, 255, 255);
		iShowImage(0, 0, 1000, 600, background1);
		iShowImage(280, 40, 450, 505, game_mode);
		iShowImage(330, 320, 345, 73, single_player);
		iShowImage(330, 210, 345, 73, multi_player);
		iShowImage(470, 30, 78, 79, back);
		
	}

	//After "Single_player" is Clicked -- Difficulty
	else if (gameState == 1){
		iSetColor(255, 255, 255);
		iShowImage(0, 0, 1000, 600, background1);
		iShowImage(285, 420, 440, 118, difficulty);
		iShowImage(400, 340, 217, 74, easy);
		iShowImage(400, 250, 217, 74, medium);
		iShowImage(400, 160, 217, 74, hard);
		iShowImage(470, 30, 78, 79, back);
	}

	// After Difficulty or Multiplayer is clicked --Level
	else if (gameState == 2){
		iSetColor(255, 255, 255);
		iShowImage(0, 0, 1000, 600, background1);
		iShowImage(165, 100, 647, 439, level);
		iShowImage(205, 240, 93, 98, level_1);
		iShowImage(325, 240, 93, 98, level_2);
		iShowImage(445, 240, 93, 98, level_3);
		iShowImage(565, 240, 93, 98, level_4);
		iShowImage(685, 240, 93, 98, level_5);
		iShowImage(465, 80, 78, 79, back);

	}

	// High Score
	else if (gameState == 3){
		iSetColor(255, 255, 255);
		iShowImage(0, 0, 1000, 600, background1);
		iShowImage(300, 50, 377, 500, high_score_bg);
		iShowImage(450, 25, 78, 79, back);
		highScoreShow();
	}
	// Settings
	else if (gameState == 4){
		iSetColor(255, 255, 255);
		iShowImage(0, 0, 1000, 600, background1);
		iShowImage(300, 50, 408, 519, control_detail);
		iShowImage(460, 10, 78, 79, back);
	}
	// About
	else if (gameState == 5){
		iSetColor(255, 255, 255);
		iShowImage(0, 0, 1000, 600, background1);
		iShowImage(50, 50, 400, 528, hplay);
		iShowImage(550, 50, 400, 528, author);
		iShowImage(460, 20, 78, 79, back);
	}
	else if (gameState == 7)
	{
		
		#include "easylevel.h"
	}

	else if (gameState == 8)
	{
		
		#include "mediumlevel.h"
	}

	else if (gameState == 9)
	{
		
		#include "hardlevel.h"  
	}

	else if (gameState == 6)
	{
		exit(0);
	}

	else if (gameState == 10)
	{
		pauseMethod();
		iSetColor(255, 255, 255);
		iShowImage(0, 0, 1000, 600, loseImage);
		isEnterName = true;
		showName();

		iSetColor(255, 255, 255);
		iShowImage(700, 100, 80, 80, menu);
		iShowImage(800, 100, 80, 80, reload);

	}
	else if (gameState == 11)
	{
		pauseMethod();
		iShowImage(0, 0, 1000, 600, winImage);
		isEnterName = true;
		showName();

		iSetColor(255, 255, 255);
		iShowImage(700, 100, 80, 80, menu);
		iShowImage(800, 100, 80, 80, reload);
	}

	

}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (gameState == -1){
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx >= 400 && mx <= 584 && my >= 263 && my <= 326){
				gameState = 1;
			}
			else if (mx >= 400 && mx <= 584 && my >= 198 && my <= 259){
				gameState = 3;
			}
			else if (mx >= 400 && mx <= 584 && my >= 133 && my <= 194){
				gameState = 4;
			}
			else if (mx >= 400 && mx <= 584 && my >= 68 && my <= 129){
				gameState = 5;
			}
			else if (mx >= 400 && mx <= 584 && my >= 5 && my <= 66){
				gameState = 6;
			}
		    if (mx >= 850 && mx <= 900 && my >= 500 && my <= 550)
			{
				if (musicON)
				{
					musicON = false;
					PlaySound(0, 0, 0);	
				}
				else
				
				{
					musicON = true;
					PlaySound("sound\\backgroundMusic.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				
			}
		}
	}
	/*
	else if (gameState == 0){
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx >= 330 && mx <= 675 && my >= 320 && my <= 393){
				gameState = 1;
			}
			else if (mx >= 330 && mx <= 675 && my >= 210 && my <= 283){
				gameState = 2;
			}
			else if (mx >= 470 && mx <= 548 && my >= 30 && my <= 109){
				gameState = -1;
			}
		}
	}
	*/
	else if (gameState == 1){
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx >= 400 && mx <= 617 && my >= 340 && my <= 414){
				gameState = 7;	
			}
			else if (mx >= 400 && mx <= 617 && my >= 250 && my <= 324){
				gameState = 8;
			}
			else if (mx >= 400 && mx <= 617 && my >= 160 && my <= 234){
				gameState = 9;
			}
		}
	}
	
	else if (gameState == 3){
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx >= 450 && mx <= 528 && my >= 25 && my <= 104){
				gameState = -1;
			}
		}
	}
	else if (gameState == 4){
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx >= 460 && mx <= 538 && my >= 25 && my <= 104){
				gameState = -1;
			}
		}
	}
	else if (gameState == 5){
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx >= 460 && mx <= 538 && my >= 20 && my <= 99){
				gameState = -1;
			}
		}
	}

	else if (gameState == 10)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx >= 700 && mx <= 780 && my >= 100 && my <= 180)
			{
				gameState = -1;
				characterCoX = 600;
				//resumeMethod();
				valueInitilize();
			}

			if (mx >= 800 && mx <= 880 && my >= 100 && my <= 180)
			{
				gameState = 1;
				characterCoX = 600;
				//resumeMethod();
				valueInitilize();
			}
		}
	}

	else if (gameState == 11)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx >= 700 && mx <= 780 && my >= 100 && my <= 180)
			{
				gameState = -1;
				valueInitilize();
				characterCoX = 600;
			}

			if (mx >= 800 && mx <= 880 && my >= 100 && my <= 180)
			{
				gameState = 1;
				resumeMethod();
				characterCoX = 600;
				valueInitilize();
			}
		}
	}
	
	
}

// for jump

void jumpingMethod()
{
	
	if (jumpBool == true)
	{
		if (p == true)
		{
			characterCoY += 5;
			characterCoX += 5;
			if (characterCoY >= 225)
			{
				p = false;
			}
		}
		
		else 
		{
			characterCoY -= 5;
			characterCoX += 5;
			if (characterCoY <= 120)
			{
				jumpBool = false;
				runBool = true;
			}
			
		}
		
	}

}


void duckingMethod()
{
	if (gameState == 7)
	{
		if (duckBool == true)
		{
			characterCoX += 5;

			if (characterCoX >= check + 120)
			{

				check = 0;
				duckBool = false;
				runBool = true;
			}

		}
	}
	
}

void jumpUpMethod()
{
	if (jump == true)
	{
		if (p == true)
		{
			characterCoY += 5;
			
			if (characterCoY >= 225)
			{
				p = false;
			}
		}

		else
		{
			characterCoY -= 5;
			
			if (characterCoY <= 120)
			{
				
				jump = false;
				runBool = true;
			}

		}

	}

}




/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	//place your codes for other keys here
	if (key == 'a')
	{
		characterCoX -= 5;
	}
	else if (key == 'd')
	{
		characterCoX += 5;
	}
	else if (key == 'w')
	{
		p = true;
		jump = true;
		jumpBool = false;
		runBool = false;
		duckBool = false;
		
	}
	else if (key == 's')   //duck
	{
		check = characterCoX;
		jump = false;
		jumpBool = false;
		runBool = false;
		duckBool = true;
		
	}
	else if (key == ' ')  
	{
		p = true;
		jump = false;
		jumpBool = true;  //jump
		runBool = false;
		duckBool = false;
		

	}

	else if (key == 'r')
	{
		resumeMethod();

	}

	else if (key == 'p')
	{
		pauseMethod();
	}

	else if (key == 'm')
	{
		if (musicON)
		{
			musicON = false;
			PlaySound(0, 0, 0);
		}
		else

		{
			musicON = true;
			PlaySound("sound\\backgroundMusic.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}

	if (isEnterName)
	{
		if (key == '\r' && len > 0)
		{
			
			AppendHighScore(nhigh, gemsCount);
			readHighScore();
			for (int i = 0; i < len; i++)
			{
				str[i] = 0;
				strcpy(nhigh, str);
			}

			len = 0;
			isEnterName = false;
			gameState = -1;
			
		}
		else if (key == '\b')
		{
			if (len > 0)
			{
				str[--len] = '\0';
				strcpy(nhigh, str);
			}
		}
		else
		{
			if (len < 20)
			{
				str[len] = key;
				strcpy(nhigh, str);
				len++;
			}
		}

	}
	

}



/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)

{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	if (key == GLUT_KEY_HOME)
	{
		gameState = -1;
	}
		
}

// Set obstacles CoOrdinate	



//Changes obstaclesCoOrdinate
void obstaclesCoOrdinateChange()
{
	if (gameState == 7)
	{
		for (int i = 0; i < 20; i++)
		{
			obsCo[i].x -= 5;
		}
			
	}
	if (gameState == 8)
	{
		for (int i = 0; i < 25; i++)
		{
			obsCo1[i].x -= 5;
		}
	}

	if (gameState == 9)
	{
		for (int i = 0; i < 30; i++)
		{
			obsCo2[i].x -= 5;
		}
	}
}

void BGChange()
{
	if (gameState == 7 || gameState == 8 || gameState == 9)
	{
		for (int i = 0; i < 10; i++)
		{
			bgCo[i].x -= 5;

			if (bgCo[i].x <= 0)
			{
				bgCo[i].x = 995;
			}
		}
	}
}

void characterMovementIndex()
{
	if (gameState == 7 || gameState == 8 || gameState == 9)
	{
		characterIndex++;
		if (characterIndex > 9)
		{
			characterIndex = 0;
		}
	}
}

void jemsCoOrdinateChange()  // changing jems co-ordinate
{
	if (gameState == 7)
	{
		for (int i = 0; i <= 10; i++)
		{
			jemsCo[i].x -= 5;
		}
		
	}

	if (gameState == 8)
	{
		for (int i = 0; i <= 15; i++)
		{
			jemsCo1[i].x -= 5;
		}
		
	}

	if (gameState == 9)
	{
		for (int i = 0; i <= 20; i++)
		{
			jemsCo2[i].x -= 5;
		}
		
	}


}

void countDownTimer()
{
	if (gameState == 7)
	{
		if (timerBool == true)
		{
			timerValueE -= 1;

			if (timerValueE == 0)
			{
				timerBool = false;
				pauseMethod();
			}
		}
	}

	if (gameState == 8) 
	{
		if (timerBool == true)
		{
			timerValueM -= 1;

			if (timerValueM == 0)
			{
				timerBool = false;
				pauseMethod();
			}
		}
	}

	if (gameState == 9)
	{
		if (timerBool == true)
		{
			timerValueH -= 1;

			if (timerValueH == 0)
			{
				timerBool = false;
				pauseMethod();
			}
		}
	}
}

void BGCoOrdinateSet()
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		bgCo[i].x = sum;
		bgCo[i].y = 0;
		sum += 100;
	}
}

void jemsCoSet()   // setting jems co-ordinate
{
	
		jemsCo[0].x = 210;
		jemsCo[0].y = 255;

		jemsCo[1].x = 330;
		jemsCo[1].y = 245;

		jemsCo[2].x = 580;
		jemsCo[2].y = 199;

		jemsCo[3].x = 725;
		jemsCo[3].y = 334;

		jemsCo[4].x = 978;
		jemsCo[4].y = 234;

		jemsCo[5].x = 1520; 
		jemsCo[5].y = 195;

		jemsCo[6].x = 2170;
		jemsCo[6].y = 135;

		jemsCo[7].x = 2830;
		jemsCo[7].y = 225;

		jemsCo[8].x = 3500;
		jemsCo[8].y = 356;
		
		jemsCo[9].x = 4350;
		jemsCo[9].y = 235;

		jemsCo[10].x = 4500;
		jemsCo[10].y = 125;

	//for medium level

		jemsCo1[0].x = 210;
		jemsCo1[0].y = 225;

		jemsCo1[1].x = 330;
		jemsCo1[1].y = 245;

		jemsCo1[2].x = 580;
		jemsCo1[2].y = 199;

		jemsCo1[3].x = 725;
		jemsCo1[3].y = 334;

		jemsCo1[4].x = 978;
		jemsCo1[4].y = 234;

		jemsCo1[5].x = 1520;
		jemsCo1[5].y = 195;

		jemsCo1[6].x = 2170;
		jemsCo1[6].y = 135;

		jemsCo1[7].x = 2830;
		jemsCo1[7].y = 225;

		jemsCo1[8].x = 3500;
		jemsCo1[8].y = 356;

		jemsCo1[9].x = 4350;
		jemsCo1[9].y = 235;

		jemsCo1[10].x = 4510;
		jemsCo1[10].y = 195;

		jemsCo1[11].x = 4570;
		jemsCo1[11].y = 135;

		jemsCo1[12].x = 4830;
		jemsCo1[12].y = 225;

		jemsCo1[13].x = 5100;
		jemsCo1[13].y = 356;

		jemsCo1[14].x = 5350;
		jemsCo1[14].y = 235;

		jemsCo1[15].x = 5500;
		jemsCo1[15].y = 125;

		//for hard level

		jemsCo2[0].x = 210;
		jemsCo2[0].y = 255;

		jemsCo2[1].x = 330;
		jemsCo2[1].y = 245;

		jemsCo2[2].x = 580;
		jemsCo2[2].y = 199;

		jemsCo2[3].x = 725;
		jemsCo2[3].y = 334;

		jemsCo2[4].x = 978;
		jemsCo2[4].y = 234;

		jemsCo2[5].x = 1520;
		jemsCo2[5].y = 195;

		jemsCo2[6].x = 2170;
		jemsCo2[6].y = 135;

		jemsCo2[7].x = 2830;
		jemsCo2[7].y = 225;

		jemsCo2[8].x = 3500;
		jemsCo2[8].y = 356;

		jemsCo2[9].x = 4350;
		jemsCo2[9].y = 235;

		jemsCo2[10].x = 4510;
		jemsCo2[10].y = 125;

		jemsCo2[11].x = 4630;
		jemsCo2[11].y = 245;

		jemsCo2[12].x = 4780;
		jemsCo2[12].y = 199;

		jemsCo2[13].x = 4890;
		jemsCo2[13].y = 334;

		jemsCo2[14].x = 5100;
		jemsCo2[14].y = 234;

		jemsCo2[15].x = 5320;
		jemsCo2[15].y = 195;

		jemsCo2[16].x = 5470;
		jemsCo2[16].y = 135;

		jemsCo2[17].x = 5830;
		jemsCo2[17].y = 225;

		jemsCo2[18].x = 6400;
		jemsCo2[18].y = 356;

		jemsCo2[19].x = 6550;
		jemsCo2[19].y = 235;

		jemsCo2[20].x = 6800;
		jemsCo2[20].y = 125;

	
}

void obstaclesCoOrdinateSet()
{

	obsCo[0].x = 400;		obsCo[0].y = 125;
	obsCo[1].x = 450;		obsCo[1].y = 125;
	obsCo[2].x = 750;		obsCo[2].y = 125;
	obsCo[3].x = 795;		obsCo[3].y = 145;
	obsCo[4].x = 1200;		obsCo[4].y = 145;
	obsCo[5].x = 1245;		obsCo[5].y = 120;
	obsCo[6].x = 1500;		obsCo[6].y = 125;
	obsCo[7].x = 1520;		obsCo[7].y = 175;
	obsCo[8].x = 1950;		obsCo[8].y = 125;
	obsCo[9].x = 1990;		obsCo[9].y = 125;
	obsCo[10].x = 2300;		obsCo[10].y = 195;
	obsCo[11].x = 2450;		obsCo[11].y = 125;
	obsCo[12].x = 2800;		obsCo[12].y = 125;
	obsCo[13].x = 2850;		obsCo[13].y = 135;
	obsCo[14].x = 2900;		obsCo[14].y = 125;
	obsCo[15].x = 3400;		obsCo[15].y = 145;
	obsCo[16].x = 3450;		obsCo[16].y = 125;
	obsCo[17].x = 3800;		obsCo[17].y = 125;
	obsCo[18].x = 3850;		obsCo[18].y = 125;
	obsCo[19].x = 4300;		obsCo[19].y = 195;
	


	obsCo1[0].x = 400;		obsCo1[0].y = 125;
	obsCo1[1].x = 450;		obsCo1[1].y = 225;
	obsCo1[2].x = 750;		obsCo1[2].y = 125;
	obsCo1[3].x = 795;		obsCo1[3].y = 145;
	obsCo1[4].x = 1200;		obsCo1[4].y = 145;
	obsCo1[5].x = 1245;		obsCo1[5].y = 120;
	obsCo1[6].x = 1500;		obsCo1[6].y = 125;
	obsCo1[7].x = 1520;		obsCo1[7].y = 175;
	obsCo1[8].x = 1950;		obsCo1[8].y = 225;
	obsCo1[9].x = 1990;		obsCo1[9].y = 325;
	obsCo1[10].x = 2300;	obsCo1[10].y = 195;
	obsCo1[11].x = 2450;	obsCo1[11].y = 125;
	obsCo1[12].x = 2800;	obsCo1[12].y = 125;
	obsCo1[13].x = 2850;	obsCo1[13].y = 135;
	obsCo1[14].x = 2900;	obsCo1[14].y = 125;
	obsCo1[15].x = 3400;	obsCo1[15].y = 145;
	obsCo1[16].x = 3450;	obsCo1[16].y = 125;
	obsCo1[17].x = 3800;	obsCo1[17].y = 125;
	obsCo1[18].x = 3850;	obsCo1[18].y = 125;
	obsCo1[19].x = 4300;	obsCo1[19].y = 195;
	obsCo1[20].x = 4430;	obsCo1[20].y = 125;
	obsCo1[21].x = 4550;	obsCo1[21].y = 125;
	obsCo1[22].x = 4750;	obsCo1[22].y = 125;
	obsCo1[23].x = 4995;	obsCo1[23].y = 145;
	obsCo1[24].x = 5200;	obsCo1[24].y = 145;


	obsCo2[0].x = 400;		obsCo2[0].y = 125;
	obsCo2[1].x = 450;		obsCo2[1].y = 125;
	obsCo2[2].x = 750;		obsCo2[2].y = 125;
	obsCo2[3].x = 795;		obsCo2[3].y = 145;
	obsCo2[4].x = 1200;		obsCo2[4].y = 145;
	obsCo2[5].x = 1245;		obsCo2[5].y = 120;
	obsCo2[6].x = 1500;		obsCo2[6].y = 125;
	obsCo2[7].x = 1520;		obsCo2[7].y = 175;
	obsCo2[8].x = 1950;		obsCo2[8].y = 125;
	obsCo2[9].x = 1990;		obsCo2[9].y = 125;
	obsCo2[10].x = 2300;	obsCo2[10].y = 195;
	obsCo2[11].x = 2450;	obsCo2[11].y = 125;
	obsCo2[12].x = 2800;	obsCo2[12].y = 125;
	obsCo2[13].x = 2850;	obsCo2[13].y = 135;
	obsCo2[14].x = 2900;	obsCo2[14].y = 125;
	obsCo2[15].x = 3400;	obsCo2[15].y = 145;
	obsCo2[16].x = 3450;	obsCo2[16].y = 125;
	obsCo2[17].x = 3800;	obsCo2[17].y = 125;
	obsCo2[18].x = 3850;	obsCo2[18].y = 125;
	obsCo2[19].x = 4300;	obsCo2[19].y = 195;
	obsCo2[20].x = 4430;	obsCo2[20].y = 125;
	obsCo2[21].x = 4750;	obsCo2[1].y = 125;
	obsCo2[22].x = 4990;	obsCo2[2].y = 125;
	obsCo2[23].x = 5295;	obsCo2[3].y = 145;
	obsCo2[24].x = 5410;	obsCo2[24].y = 145;
	obsCo2[25].x = 5645;	obsCo2[25].y = 120;
	obsCo2[26].x = 5800;	obsCo2[26].y = 125;
	obsCo2[27].x = 6120;	obsCo2[27].y = 175;
	obsCo2[28].x = 6350;	obsCo2[28].y = 125;
	obsCo2[29].x = 6590;	obsCo2[29].y = 125;


	

}


int main()
{
	readHighScore();
	iInitialize(1000, 600, "RUSH HOUR");
	
	obstaclesCoOrdinateSet();
	BGCoOrdinateSet();
	jemsCoSet();  // calling method of setting jems co-ordinate
	
	iSetTimer(40, BGChange);
	iSetTimer(40, obstaclesCoOrdinateChange);
	iSetTimer(40, jemsCoOrdinateChange);  //timer to change jems co-ordinate
	iSetTimer(100, characterMovementIndex);
	iSetTimer(1000, countDownTimer);

	iSetTimer(25, jumpingMethod);
	iSetTimer(25, duckingMethod);
	iSetTimer(25, jumpUpMethod);
	
	
	

	background = iLoadImage("image\\background00.png");
	background1 = iLoadImage("image\\background1.jpg");
	background21 = iLoadImage("image\\background21.jpg");
	play = iLoadImage("image\\play.png");
	game_mode = iLoadImage("image\\game-mode.png");
	high_score = iLoadImage("image\\high-score.png");
	control = iLoadImage("image\\control.png");
	about = iLoadImage("image\\about.png");
	hplay = iLoadImage("image\\hplay.png");
	author = iLoadImage("image\\author.png");
	exits = iLoadImage("image\\exit.png");
	level_select = iLoadImage("image\\level-select.png");
	single_player = iLoadImage("image\\singleplayer.png");
	multi_player = iLoadImage("image\\multiplayer.png");
	difficulty = iLoadImage("image\\difficulty.png");
	easy = iLoadImage("image\\easy.png");
	medium = iLoadImage("image\\medium.png");
	hard = iLoadImage("image\\hard.png");
	level = iLoadImage("image\\level\\level-select.png");
	level_1 = iLoadImage("image\\level\\level1.png");
	level_2 = iLoadImage("image\\level\\level2.png");
	level_3 = iLoadImage("image\\level\\level3.png");
	level_4 = iLoadImage("image\\level\\level4.png");
	level_5 = iLoadImage("image\\level\\level5.png");
	back = iLoadImage("image\\back-button.png");
	high_score_bg = iLoadImage("image\\high_score.png");
	settings_mode = iLoadImage("image\\settings-mode.png");
	music_on = iLoadImage("image\\music-on.png");
	music_off = iLoadImage("image\\music-off.png");
	winImage = iLoadImage("image\\winImage.png");
	loseImage = iLoadImage("image\\loseImage.png");
	control_detail = iLoadImage("image\\control-detail.png");
	// path = iLoadImage("image\\path.png");
	//loading obstacles images

	characterJumpUp = iLoadImage("image\\jump\\jump_001.png");

	obs[0] = iLoadImage("image\\obstacles\\aces.png");
	obs[1] = iLoadImage("image\\obstacles\\dice.png");
	obs[2] = iLoadImage("image\\obstacles\\dice-1.png");
	obs[3] = iLoadImage("image\\obstacles\\dice-2.png");
	obs[4] = iLoadImage("image\\obstacles\\dice-3.png");  
	obs[5] = iLoadImage("image\\obstacles\\dice-4.png");  
	obs[6] = iLoadImage("image\\obstacles\\dice-5.png");  		
	obs[7] = iLoadImage("image\\obstacles\\domino.png"); 
	obs[8] = iLoadImage("image\\obstacles\\domino-1.png");
	obs[9]  = iLoadImage("image\\obstacles\\domino-2.png");
	obs[10] = iLoadImage("image\\obstacles\\domino-3.png");
	obs[11] = iLoadImage("image\\obstacles\\poker-45.png");
	obs[12] = iLoadImage("image\\obstacles\\poker-46.png");
	obs[13] = iLoadImage("image\\obstacles\\poker-47.png");
	obs[14] = iLoadImage("image\\obstacles\\poker-48.png");
	obs[15] = iLoadImage("image\\obstacles\\poker-49.png");
	obs[16] = iLoadImage("image\\obstacles\\poker-50.png");
	obs[17] = iLoadImage("image\\obstacles\\poker-51.png");
	obs[18] = iLoadImage("image\\obstacles\\poker-52.png");
	obs[19] = iLoadImage("image\\obstacles\\poker-53.png");
	obs[20] = iLoadImage("image\\obstacles\\poker-54.png");
	obs[21] = iLoadImage("image\\obstacles\\dice.png");
	obs[22] = iLoadImage("image\\obstacles\\dice-1.png");
	obs[23] = iLoadImage("image\\obstacles\\dice-2.png");
	obs[24] = iLoadImage("image\\obstacles\\dice-3.png");
	obs[25] = iLoadImage("image\\obstacles\\dice-4.png");
	obs[26] = iLoadImage("image\\obstacles\\dice-5.png");
	obs[27] = iLoadImage("image\\obstacles\\domino.png");
	obs[28] = iLoadImage("image\\obstacles\\domino-1.png");
	obs[29] = iLoadImage("image\\obstacles\\domino-2.png");

	

	//loading character images
	character[0] = iLoadImage("image\\run\\run_000.png");
	character[1] = iLoadImage("image\\run\\run_004.png");
	character[2] = iLoadImage("image\\run\\run_008.png");
	character[3] = iLoadImage("image\\run\\run_012.png");
	character[4] = iLoadImage("image\\run\\run_016.png");
	character[5] = iLoadImage("image\\run\\run_020.png");
	character[6] = iLoadImage("image\\run\\run_024.png");
	character[7] = iLoadImage("image\\run\\run_028.png");
	character[8] = iLoadImage("image\\run\\run_032.png");
	character[9] = iLoadImage("image\\run\\run_036.png");
	
	//loading character jump images
	characterJump[0] = iLoadImage("image\\jump\\jump_000.png");
	characterJump[1] = iLoadImage("image\\jump\\jump_004.png");
	characterJump[2] = iLoadImage("image\\jump\\jump_006.png");
	characterJump[3] = iLoadImage("image\\jump\\jump_008.png");
	characterJump[4] = iLoadImage("image\\jump\\jump_011.png");
	characterJump[5] = iLoadImage("image\\jump\\jump_015.png");
	characterJump[6] = iLoadImage("image\\jump\\jump_019.png");
	characterJump[7] = iLoadImage("image\\jump\\jump_022.png");
	characterJump[8] = iLoadImage("image\\jump\\jump_025.png");
	characterJump[9] = iLoadImage("image\\jump\\jump_029.png");

	
	BGround[0] = iLoadImage("image\\renderedBackGround\\background_0.png");
	BGround[1] = iLoadImage("image\\renderedBackGround\\background_1.png");
	BGround[2] = iLoadImage("image\\renderedBackGround\\background_2.png");
	BGround[3] = iLoadImage("image\\renderedBackGround\\background_3.png");
	BGround[4] = iLoadImage("image\\renderedBackGround\\background_4.png");
	BGround[5] = iLoadImage("image\\renderedBackGround\\background_5.png");
	BGround[6] = iLoadImage("image\\renderedBackGround\\background_6.png");
	BGround[7] = iLoadImage("image\\renderedBackGround\\background_7.png");
	BGround[8] = iLoadImage("image\\renderedBackGround\\background_8.png");
	BGround[9] = iLoadImage("image\\renderedBackGround\\background_9.png");
	
	//loading jems images
	
	jems[0] = iLoadImage("image\\jems\\jems1.png");
	jems[1] = iLoadImage("image\\jems\\jems2.png");
	jems[2] = iLoadImage("image\\jems\\jems3.png");
	jems[3] = iLoadImage("image\\jems\\jems4.png");
	jems[4] = iLoadImage("image\\jems\\jems5.png");
	jems[5] = iLoadImage("image\\jems\\jems6.png");
	jems[6] = iLoadImage("image\\jems\\jems1.png");
	jems[7] = iLoadImage("image\\jems\\jems2.png");
	jems[8] = iLoadImage("image\\jems\\jems3.png");
	jems[9] = iLoadImage("image\\jems\\jems4.png");
	jems[10] = iLoadImage("image\\jems\\jems1.png");
	jems[11] = iLoadImage("image\\jems\\jems2.png");
	jems[12] = iLoadImage("image\\jems\\jems3.png");
	jems[13] = iLoadImage("image\\jems\\jems4.png");
	jems[14] = iLoadImage("image\\jems\\jems5.png");
	jems[15] = iLoadImage("image\\jems\\jems6.png");
	jems[16] = iLoadImage("image\\jems\\jems1.png");
	jems[17] = iLoadImage("image\\jems\\jems2.png");
	jems[18] = iLoadImage("image\\jems\\jems3.png");
	jems[19] = iLoadImage("image\\jems\\jems4.png");

	finishline = iLoadImage("image\\finishLineFlag.png");
	menu = iLoadImage("image\\menu.png");
	reload = iLoadImage("image\\reload.png");

	if (musicON)
	{
		PlaySound("sound\\backgroundMusic.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	
	iStart();

	return 0;
}
