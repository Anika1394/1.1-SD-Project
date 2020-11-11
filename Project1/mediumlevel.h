	
	iSetColor(255, 255, 255);
	for (int i = 0; i < 10; i++)
	{
		iShowImage(bgCo[i].x, bgCo[i].y, 100, 600, BGround[i]);
	}

	iSetColor(255, 25, 255);
	iFilledRectangle(0, 110, 1000, 10);


	iSetColor(255, 255, 255);
	for (int i = 0; i < 25; i++)
	{
		iShowImage(obsCo1[i].x, obsCo1[i].y, 50, 50, obs[i]);
	}
	

	if (runBool == true)
	{
		iShowImage(characterCoX, characterCoY, characterDx, characterDy, character[characterIndex]);
	}

	if (jumpBool == true)
	{
		iShowImage(characterCoX, characterCoY, characterDx + 10, characterDy + 10, characterJump[characterIndex]);
	}
	if (duckBool == true)
	{
		iShowImage(characterCoX, characterCoY - 20, characterDx, characterDy, characterJump[1]);
	}

	if (jump == true)
	{
		iShowImage(characterCoX, characterCoY, characterDx + 10, characterDy + 10, characterJumpUp);
	}


	if ((characterCoX + 50 >= obsCo1[0].x && characterCoX + 50 <= obsCo1[0].x + 50 && characterCoY + 50 >= obsCo1[0].y && characterCoY + 50 <= obsCo1[0].y + 50) || (characterCoX + 50 >= obsCo1[1].x && characterCoX + 50 <= obsCo1[1].x + 50 && characterCoY + 50 >= obsCo1[1].y && characterCoY + 50 <= obsCo1[1].y + 50) || (characterCoX + 50 >= obsCo1[2].x && characterCoX + 50 <= obsCo1[2].x + 50 && characterCoY + 50 >= obsCo1[2].y && characterCoY + 50 <= obsCo1[2].y + 50) || (characterCoX + 50 >= obsCo1[3].x && characterCoX + 50 <= obsCo1[3].x + 50 && characterCoY + 50 >= obsCo1[3].y && characterCoY + 50 <= obsCo1[3].y + 50) || (characterCoX + 50 >= obsCo1[4].x && characterCoX + 50 <= obsCo1[4].x + 50 && characterCoY + 50 >= obsCo1[4].y && characterCoY + 50 <= obsCo1[4].y + 50))
	{
		characterCoX -= 20;

	}

	else if ((characterCoX + 50 >= obsCo1[5].x && characterCoX + 50 <= obsCo1[5].x + 50 && characterCoY + 50 >= obsCo1[5].y && characterCoY + 50 <= obsCo1[5].y + 50) || (characterCoX + 50 >= obsCo1[6].x && characterCoX + 50 <= obsCo1[6].x + 50 && characterCoY + 50 >= obsCo1[6].y && characterCoY + 50 <= obsCo1[6].y + 50) || (characterCoX + 50 >= obsCo1[7].x && characterCoX + 50 <= obsCo1[7].x + 50 && characterCoY + 50 >= obsCo1[7].y && characterCoY + 50 <= obsCo1[7].y + 50) || (characterCoX + 50 >= obsCo1[8].x && characterCoX + 50 <= obsCo1[8].x + 50 && characterCoY + 50 >= obsCo1[8].y && characterCoY + 50 <= obsCo1[8].y + 50) || (characterCoX + 50 >= obsCo1[9].x && characterCoX + 50 <= obsCo1[9].x + 50 && characterCoY + 50 >= obsCo1[9].y && characterCoY + 50 <= obsCo1[9].y + 50))
	{
		characterCoX -= 20;

	}

	else if ((characterCoX + 50 >= obsCo1[10].x && characterCoX + 50 <= obsCo1[10].x + 50 && characterCoY + 50 >= obsCo1[10].y && characterCoY + 50 <= obsCo1[10].y + 50) || (characterCoX + 50 >= obsCo1[11].x && characterCoX + 50 <= obsCo1[11].x + 50 && characterCoY + 50 >= obsCo1[11].y && characterCoY + 50 <= obsCo1[11].y + 50) || (characterCoX + 50 >= obsCo1[12].x && characterCoX + 50 <= obsCo1[12].x + 50 && characterCoY + 50 >= obsCo1[12].y && characterCoY + 50 <= obsCo1[12].y + 50) || (characterCoX + 50 >= obsCo1[13].x && characterCoX + 50 <= obsCo1[13].x + 50 && characterCoY + 50 >= obsCo1[13].y && characterCoY + 50 <= obsCo1[13].y + 50) || (characterCoX + 50 >= obsCo1[14].x && characterCoX + 50 <= obsCo1[14].x + 50 && characterCoY + 50 >= obsCo1[14].y && characterCoY + 50 <= obsCo1[14].y + 50))
	{
		characterCoX -= 20;

	}

	else if ((characterCoX + 50 >= obsCo1[15].x && characterCoX + 50 <= obsCo1[15].x + 50 && characterCoY + 50 >= obsCo1[15].y && characterCoY + 50 <= obsCo1[15].y + 50) || (characterCoX + 50 >= obsCo1[16].x && characterCoX + 50 <= obsCo1[16].x + 50 && characterCoY + 50 >= obsCo1[16].y && characterCoY + 50 <= obsCo1[16].y + 50) || (characterCoX + 50 >= obsCo1[17].x && characterCoX + 50 <= obsCo1[17].x + 50 && characterCoY + 50 >= obsCo1[17].y && characterCoY + 50 <= obsCo1[17].y + 50) || (characterCoX + 50 >= obsCo1[18].x && characterCoX + 50 <= obsCo1[18].x + 50 && characterCoY + 50 >= obsCo1[18].y && characterCoY + 50 <= obsCo1[18].y + 50) || (characterCoX + 50 >= obsCo1[19].x && characterCoX + 50 <= obsCo1[19].x + 50 && characterCoY + 50 >= obsCo1[19].y && characterCoY + 50 <= obsCo1[19].y + 50))
	{
		characterCoX -= 20;

	}

	else if ((characterCoX + 50 >= obsCo1[20].x && characterCoX + 50 <= obsCo1[20].x + 50 && characterCoY + 50 >= obsCo1[20].y && characterCoY + 50 <= obsCo1[20].y + 50) || (characterCoX + 50 >= obsCo1[21].x && characterCoX + 50 <= obsCo1[21].x + 50 && characterCoY + 50 >= obsCo1[21].y && characterCoY + 50 <= obsCo1[21].y + 50) || (characterCoX + 50 >= obsCo1[22].x && characterCoX + 50 <= obsCo1[22].x + 50 && characterCoY + 50 >= obsCo1[22].y && characterCoY + 50 <= obsCo1[22].y + 50) || (characterCoX + 50 >= obsCo1[23].x && characterCoX + 50 <= obsCo1[23].x + 50 && characterCoY + 50 >= obsCo1[23].y && characterCoY + 50 <= obsCo1[23].y + 50) || (characterCoX + 50 >= obsCo1[24].x && characterCoX + 50 <= obsCo1[24].x + 50 && characterCoY + 50 >= obsCo1[24].y && characterCoY + 50 <= obsCo1[24].y + 50))
	{
		characterCoX -= 20;

	}

	// jems Co-ordinate colision check

	for (int j = 0; j < 15; j++)
	{
		if (characterCoX + 50 >= jemsCo1[j].x && characterCoX + 50 <= jemsCo1[j].x + 50 && characterCoY + 50 >= jemsCo1[j].y && characterCoY + 50 <= jemsCo1[j].y + 50)
		{
			jemsCo1[j].show = false;
			gemsCount += 1;
		}
	}

	// to show jems if not collided

	for (int j = 0; j < 15; j++)
	{
		if (jemsCo1[j].show == true)
		{
			iShowImage(jemsCo1[j].x, jemsCo1[j].y, 30, 30, jems[j]);
		}
	}

	iShowImage(jemsCo1[15].x, jemsCo1[15].y, 30, 30, finishline);

	iSetColor(55, 25, 62);
	iFilledRectangle(0, 0, 100, 600);

	iSetColor(12, 125, 45);
	sprintf_s(strTimer, "%d", timerValueM);
	iText(15, 500, "Time: ", GLUT_BITMAP_HELVETICA_18);
	iText(70, 500, strTimer, GLUT_BITMAP_HELVETICA_18);

	sprintf_s(strGems, "%d", gemsCount);
	iText(10, 420, "Score: ", GLUT_BITMAP_HELVETICA_18);
	iText(70, 420, strGems, GLUT_BITMAP_HELVETICA_18);




	if (timerValueM == 0 || characterCoX <= 0 || characterCoX >= 1000)
	{
		gameState = 10;
	}

	if (characterCoX + 50 >= jemsCo1[15].x && characterCoX + 50 <= jemsCo1[15].x + 50 && characterCoY + 50 >= jemsCo1[15].y && characterCoY + 50 <= jemsCo1[15].y + 50)
	{
		gameState = 11;
	}
