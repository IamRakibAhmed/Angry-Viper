#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#include <stdlib.h>
#define screenWidth 1000
#define screenHeight 680

int cX, cY, sX, sY;            //initial position of the snake
int fX, fY;                   //initial position of the food

int snakeMove = 0;            //for keyboard control for snake movement
int snakeSize = 0;           //increasing snake size

char score[100];            //String score value
int scoreInt = -1;           //integer score value
int showLevel = 0;          //level showing increase

int fSize = 15;             //snake food size

int levelTxtSizeX = 20, lSizeTxtX = 90, pauseTxtSizeX = 300, scoreTxtSizeX = 890, sSizeTxtX = 960;      //text size in X axis
int levelTxtSizeY = 15, pauseTxtSizeY = 15, scoreTxtSizeY = 15;      //text size in Y axis

int pauseTxtScreenX = 360, pauseTxtScreenY = 340;                 //gameplay pause txt position

int levelUp = 0, snakeSpeed = 0, pause = 0, gameOver = 0, sound = 1;
int newGameButton = 0, gameModeButton = 0, aboutButton = 0;
int easyModeButton = 0, mediumModeButton = 0, hardModeButton = 0;

void iDraw()
{
	iClear();
	iShowBMP(0, 0, "images\\HomeScreen.bmp");		//Main Menu

	if (newGameButton == 1)              //new game
	{

		if (levelUp >= 0 && levelUp <= 5)
		{
			showLevel = 1;
			snakeSpeed = 5;
			iShowBMP(0, 0, "images\\gameBack.bmp");
		}

		else if (levelUp >= 6 && levelUp <= 10)
		{
			showLevel = 2;
			snakeSpeed = 6;
			iShowBMP(0, 0, "images\\gameBack.bmp");
		}

		else if (levelUp >= 11 && levelUp <= 15)
		{
			showLevel = 3;
			snakeSpeed = 7;
			iShowBMP(0, 0, "images\\gameBack.bmp");
		}

		else if (levelUp >= 16 && levelUp <= 20)
		{
			showLevel = 4;
			snakeSpeed = 8;
			iShowBMP(0, 0, "images\\gameBack.bmp");
		}

		else if (levelUp >= 21)
		{
			showLevel = 5;
			snakeSpeed = 12;
			iShowBMP(0, 0, "images\\gameBack.bmp");
		}

		iSetColor(50, 205, 50);                 //snake color
		iFilledRectangle(cX, cY, sX, sY);    //snake initial position and length

		iSetColor(255, 255, 0);                //food color
		iFilledRectangle(fX, fY, fSize, fSize);     //snake food

		iSetColor(72, 61, 139);             //pattern color
		iFilledRectangle(0, 0, 1000, 50);  //pattern

		iSetColor(255, 69, 0);
		iText(pauseTxtSizeX, pauseTxtSizeY, "Prees SPACE Button to Pause the Game", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(levelTxtSizeX, levelTxtSizeY, "Level: ", GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(score, "%d", showLevel);	//Convert Int value to String
		iText(lSizeTxtX, scoreTxtSizeY, score, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(score, "%d", scoreInt);
		iText(scoreTxtSizeX, scoreTxtSizeY, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(sSizeTxtX, scoreTxtSizeY, score, GLUT_BITMAP_TIMES_ROMAN_24);

		if (pause == 1)
		{
			iSetColor(255, 69, 0);
			iText(pauseTxtScreenX, pauseTxtScreenY, "Prees SPACE For Continue", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(pauseTxtScreenX + 20, pauseTxtScreenY - 40, "Prees Q For Exit Game", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}

	if (gameModeButton == 1)                    //game mode selection
	{
		iShowBMP(0, 0, "images\\gameMode.bmp");
		iSetColor(75, 0, 130);
		iFilledRectangle(15, 10, 50, 20);
		iFilledRectangle(14, 11, 50, 20);
		iSetColor(224, 102, 255);
		iText(25, 13, "Exit", GLUT_BITMAP_HELVETICA_18);

		if (easyModeButton == 1 && gameModeButton == 1)             //easy mode
		{
			snakeSpeed = 5;
			iShowBMP(0, 0, "images\\gameBack.bmp");

			iSetColor(72, 61, 139);             //pattern color
			iFilledRectangle(0, 0, 1000, 50);  //pattern

			iSetColor(255, 69, 0);
			iText(pauseTxtSizeX, pauseTxtSizeY, "Prees SPACE Button to Pause the Game", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(levelTxtSizeX, levelTxtSizeY, "Easy Mode", GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(score, "%d", scoreInt);
			iText(scoreTxtSizeX, scoreTxtSizeY, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(sSizeTxtX, scoreTxtSizeY, score, GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(255, 0, 0);
			iFilledRectangle(cX, cY, sX, sY);
			iSetColor(255, 255, 0);                //food color
			iFilledRectangle(fX, fY, fSize, fSize);     //snake food

			if (pause == 1)
			{
				iSetColor(255, 69, 0);
				iText(pauseTxtScreenX, pauseTxtScreenY, "Prees SPACE For Continue", GLUT_BITMAP_TIMES_ROMAN_24);
				iText(pauseTxtScreenX + 20, pauseTxtScreenY - 40, "Prees Q For Exit Game", GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}

		if (mediumModeButton == 1 && gameModeButton == 1)                     //medium mode
		{
			snakeSpeed = 10;
			iShowBMP(0, 0, "images\\gameBack.bmp");

			iSetColor(72, 61, 139);             //pattern color
			iFilledRectangle(0, 0, 1000, 50);  //pattern

			iSetColor(255, 69, 0);
			iText(pauseTxtSizeX, pauseTxtSizeY, "Prees SPACE Button to Pause the Game", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(levelTxtSizeX, levelTxtSizeY, "Medium Mode", GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(score, "%d", scoreInt);
			iText(scoreTxtSizeX, scoreTxtSizeY, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(sSizeTxtX, scoreTxtSizeY, score, GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(255, 0, 0);                  //snake color
			iFilledRectangle(cX, cY, sX, sY);      //snake
			iSetColor(255, 255, 0);                //food color
			iFilledRectangle(fX, fY, fSize, fSize);     //snake food

			if (pause == 1)
			{
				iSetColor(255, 69, 0);
				iText(pauseTxtScreenX, pauseTxtScreenY, "Prees SPACE For Continue", GLUT_BITMAP_TIMES_ROMAN_24);
				iText(pauseTxtScreenX + 20, pauseTxtScreenY - 40, "Prees Q For Exit Game", GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}

		else if (hardModeButton == 1 && gameModeButton == 1)                  //hard mode
		{
			snakeSpeed = 15;
			iShowBMP(0, 0, "images\\gameBack.bmp");

			iSetColor(72, 61, 139);             //pattern color
			iFilledRectangle(0, 0, 1000, 50);  //pattern

			iSetColor(255, 69, 0);
			iText(pauseTxtSizeX, pauseTxtSizeY, "Prees SPACE Button to Pause the Game", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(levelTxtSizeX, levelTxtSizeY, "Hard Mode", GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(score, "%d", scoreInt);
			iText(scoreTxtSizeX, scoreTxtSizeY, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(sSizeTxtX, scoreTxtSizeY, score, GLUT_BITMAP_TIMES_ROMAN_24);

			iSetColor(255, 0, 0);                  //snake color
			iFilledRectangle(cX, cY, sX, sY);      //snake
			iSetColor(255, 255, 0);                //food color
			iFilledRectangle(fX, fY, fSize, fSize);     //snake food

			if (pause == 1)
			{
				iSetColor(255, 69, 0);
				iText(pauseTxtScreenX, pauseTxtScreenY, "Prees SPACE For Continue", GLUT_BITMAP_TIMES_ROMAN_24);
				iText(pauseTxtScreenX + 20, pauseTxtScreenY - 40, "Prees Q For Exit Game", GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
	}

	if (aboutButton == 1)                      //about
	{
		iShowBMP(0, 0, "images\\aboutDetails.bmp");
		iSetColor(75, 0, 130);
		iFilledRectangle(15, 10, 50, 20);
		iFilledRectangle(14, 11, 50, 20);
		iSetColor(224, 102, 255);
		iText(25, 13, "Exit", GLUT_BITMAP_HELVETICA_18);
	}

	if (gameOver == 1)                             //game over
	{
		iShowBMP(0, 0, "images\\gameOver.bmp");
		iSetColor(139, 95, 101);
		iFilledRectangle(15, 10, 50, 20);
		iFilledRectangle(14, 11, 50, 20);
		iSetColor(224, 102, 255);
		iText(25, 13, "Exit", GLUT_BITMAP_HELVETICA_18);
		iSetColor(255, 69, 0);
		iText(pauseTxtScreenX + 60, 106, "Your Score Is:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pauseTxtScreenX + 120, 80, score, GLUT_BITMAP_TIMES_ROMAN_24);
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


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("%d %d \n\n", mx, my);            //Button value will recieve by mouse click

		if ((mx >= 482 && mx <= 650) && (my >= 450 && my <= 495))      //strat new game button
		{
			newGameButton = 1;
		}

		else if ((mx >= 482 && mx <= 650) && (my >= 360 && my <= 410))  //game Mode button
		{
			gameModeButton = 1;
		}

		else if ((mx >= 482 && mx <= 650) && (my >= 260 && my <= 310))  //main menu exit button
		{
			exit(0);
		}

		else if ((mx >= 482 && mx <= 650) && (my >= 170 && my <= 220))  //about button
		{
			aboutButton = 1;
		}

		else if (gameModeButton == 1)
		{

			if ((mx >= 735 && mx <= 925) && (my >= 440 && my <= 490))        //easy mode button
			{
				easyModeButton = 1;
			}
			else if ((mx >= 740 && mx <= 925) && (my >= 340 && my <= 390))  //medium mode button
			{
				mediumModeButton = 1;
			}

			else if ((mx >= 740 && mx <= 925) && (my >= 240 && my <= 286))  //hard mode button
			{
				hardModeButton = 1;
			}
		}

		if ((mx >= 13 && mx <= 165) && (my >= 10 && my <= 31))     //Exit button
		{
			exit(0);
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 //mposx = mx;
 //mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/
}

void iKeyboard(unsigned char key)
{
	if (key == ' ' && pause == 0)
	{
		pause = 1;
	}
	else if (key == ' ' && pause == 1)
	{
		pause = 0;
	}
	else if (key == 'q')
	{
		exit(0);
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

	if(key == GLUT_KEY_RIGHT)
	{
		snakeMove = 1;
	}
	if (key == GLUT_KEY_LEFT)
	{
		snakeMove = 2;
	}
	if (key == GLUT_KEY_UP)
	{
		snakeMove = 3;
	}
	if (key == GLUT_KEY_DOWN)
	{
		snakeMove = 4;
	}
}

void snakemove()		//Snake Move Function
{
	if (pause == 1)			//Snake Puse And Resume Condition
	{
		return;
	}

	if (snakeMove == 1)
	{
		cX += snakeSpeed;
		sX = snakeSize;
		sY = 10;
		if (cX > 890)
		{
			gameOver = 1;
		}
	}

	if (snakeMove == 2)
	{
		cX -= snakeSpeed;
		sX = snakeSize;
		sY = 10;
		if (cX < 1)
		{
			gameOver = 1;
		}
	}
	if (snakeMove == 3)
	{
		cY += snakeSpeed;
		sX = 10;
		sY = snakeSize;
		if (cY > 570)
		{
			gameOver = 1;
		}
	}

	if (snakeMove == 4)
	{
		cY -= snakeSpeed;
		sX = 10;
		sY = snakeSize;
		if (cY < 50)
		{
			gameOver = 1;
		}

	}

	//random food generate and snake size increasing by collision
	if ((fX <= cX + sX || fX <= cX + sX - 8) && (fX >= cX || fX >= cX - 8) && (fY <= cY + sY || fY <= cY + sY - 8) && (fY >= cY || fY >= cY - 8))
	{
		levelUp += 1;

		if (snakeSize < 1000)
		{
			snakeSize += 8;
		}
		if (sound)
			PlaySound("eat", NULL, SND_ASYNC);

		scoreInt++;
		
		fX = (100 + (rand() % 750));
		fY = (100 + (rand() % 400));
	}
}


int main()
{
	cX = 50;
	cY = 103;
	sX = 100;
	sY = 10;

	fX = 100;
	fY = 100;

	snakeMove = 0;
	gameOver = 0;
	snakeSpeed = 0;
	levelUp = 0;
	gameModeButton = 0;
	pause = 0;
	snakeSize = sX;

	srand(time(NULL));			//Random Number Function

	iSetTimer(20, snakemove);

	iInitialize(screenWidth, screenHeight, "Hungry Viper");
	return 0;
}
