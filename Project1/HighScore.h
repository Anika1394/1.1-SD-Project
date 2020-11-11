char nhigh[100];

int numberArray[100];
int arrayIndex = 0, stringIndex = 0;
char st[100][100];
int numberIndex = 0;

int rank = 0;
char rankText[10];
bool isEnterName;
int len = 0;
char str[100];

void AppendHighScore(char name[], int n)
{
	FILE *fp = fopen("HighScore.txt", "a");

	if (fp != NULL)
	{
		fprintf(fp, "%s\n", name);
		fprintf(fp, "%d\n", n);
	}

	fclose(fp);
}

void readHighScore()
{
	FILE *fp = fopen("HighScore.txt", "r");
	char str[100];
	arrayIndex = 0, stringIndex = 0;

	if (fp != NULL)
	{
		while (fgets(str, 15, fp) != NULL)
		{
			strcpy(st[stringIndex++], str);
			fgets(str, 15, fp);
			numberArray[arrayIndex++] = atoi(str);
		}
	}

	fclose(fp);
}
void SortingHighScore()//Sorting the highScores and Call from showHighScore
{
	int temp;
	char t[100];

	for (int i = 0; i < arrayIndex - 1; i++)
	{
		for (int j = 0; j < arrayIndex - 1; j++)
		{
			if (numberArray[j] < numberArray[j + 1])
			{
				temp = numberArray[j];
				numberArray[j] = numberArray[j + 1];
				numberArray[j + 1] = temp;
				strcpy(t, st[j]);
				strcpy(st[j], st[j + 1]);
				strcpy(st[j + 1], t);
			}
		}
	}


}
void highScoreShow()//show the highScore call from doWork which is call from iDraw
{
	SortingHighScore();
	rank = 0;
	//iClear();
	//iShowBMP(0, 0, "highScore.bmp");
	for (int k = 0, y = 340; k < 6; k++, y -= 35)
	{
		char str[100];
		if (numberArray[k]>0)
		{
			rank++;
			sprintf(rankText, "%d", rank);
			sprintf(str, "%d", numberArray[k]);
			//itoa(numberArray[k], str, 10);
			iSetColor(0, 0, 255);

			iText(350, 400, "Rank", GLUT_BITMAP_HELVETICA_18);
			iText(350, y, rankText, GLUT_BITMAP_HELVETICA_18);

			iText(430, 400, "Score", GLUT_BITMAP_HELVETICA_18);
			iText(430, y, str, GLUT_BITMAP_HELVETICA_18);

			iText(530, 400, "Name", GLUT_BITMAP_HELVETICA_18);
			iText(530, y, st[k], GLUT_BITMAP_HELVETICA_18);
		}
	}
}


void showName()//when the game is over then Show Game Over page And Show Enter Your Name And When press the keyboard then Show the Letters in Screen And Called From DoWork which is call from IDraw
{
	srand(time(0));
	iSetColor(rand() % 256, rand() % 256, rand() % 256);
	iText(200, 100, "Enter Your Name & Press ENTER ", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iRectangle(250, 50, 250, 30);
	iSetColor(255, 0, 0);
	iText(255, 53, nhigh, GLUT_BITMAP_TIMES_ROMAN_24);
}
