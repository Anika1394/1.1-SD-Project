

	iSetColor(255, 255, 255);
	for (int i = 0; i < 10; i++)
	{
		iShowImage(bgCo[i].x, bgCo[i].y, 100, 600, BGround[i]);
	}

	iSetColor(255, 25, 255);
	iFilledRectangle(0, 110, 1000, 10);

	iSetColor(255, 255, 255);
	for (int i = 0; i < 20; i++)
	{
		iShowImage(obsCo[i].x, obsCo[i].y, 50, 50, obs[i]);
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


	if ((characterCoX + 50 >= obsCo[0].x && characterCoX + 50 <= obsCo[0].x + 50 && characterCoY + 50 >= obsCo[0].y && characterCoY + 50 <= obsCo[0].y + 50) || (characterCoX + 50 >= obsCo[1].x && characterCoX + 50 <= obsCo[1].x + 50 && characterCoY + 50 >= obsCo[1].y && characterCoY + 50 <= obsCo[1].y + 50) || (characterCoX + 50 >= obsCo[2].x && characterCoX + 50 <= obsCo[2].x + 50 && characterCoY + 50 >= obsCo[2].y && characterCoY + 50 <= obsCo[2].y + 50) || (characterCoX + 50 >= obsCo[3].x && characterCoX + 50 <= obsCo[3].x + 50 && characterCoY + 50 >= obsCo[3].y && characterCoY + 50 <= obsCo[3].y + 50) || (characterCoX + 50 >= obsCo[4].x && characterCoX + 50 <= obsCo[4].x + 50 && characterCoY + 50 >= obsCo[4].y && characterCoY + 50 <= obsCo[4].y + 50))
	{
		characterCoX -= 20;

	}

	else if ((characterCoX + 50 >= obsCo[5].x && characterCoX + 50 <= obsCo[5].x + 50 && characterCoY + 50 >= obsCo[5].y && characterCoY + 50 <= obsCo[5].y + 50) || (characterCoX + 50 >= obsCo[6].x && characterCoX + 50 <= obsCo[6].x + 50 && characterCoY + 50 >= obsCo[6].y && characterCoY + 50 <= obsCo[6].y + 50) || (characterCoX + 50 >= obsCo[7].x && characterCoX + 50 <= obsCo[7].x + 50 && characterCoY + 50 >= obsCo[7].y && characterCoY + 50 <= obsCo[7].y + 50) || (characterCoX + 50 >= obsCo[8].x && characterCoX + 50 <= obsCo[8].x + 50 && characterCoY + 50 >= obsCo[8].y && characterCoY + 50 <= obsCo[8].y + 50) || (characterCoX + 50 >= obsCo[9].x && characterCoX + 50 <= obsCo[9].x + 50 && characterCoY + 50 >= obsCo[9].y && characterCoY + 50 <= obsCo[9].y + 50))
	{
		characterCoX -= 20;

	}

	else if ((characterCoX + 50 >= obsCo[10].x && characterCoX + 50 <= obsCo[10].x + 50 && characterCoY + 50 >= obsCo[10].y && characterCoY + 50 <= obsCo[10].y + 50) || (characterCoX + 50 >= obsCo[11].x && characterCoX + 50 <= obsCo[11].x + 50 && characterCoY + 50 >= obsCo[11].y && characterCoY + 50 <= obsCo[11].y + 50) || (characterCoX + 50 >= obsCo[12].x && characterCoX + 50 <= obsCo[12].x + 50 && characterCoY + 50 >= obsCo[12].y && characterCoY + 50 <= obsCo[12].y + 50) || (characterCoX + 50 >= obsCo[13].x && characterCoX + 50 <= obsCo[13].x + 50 && characterCoY + 50 >= obsCo[13].y && characterCoY + 50 <= obsCo[13].y + 50) || (characterCoX + 50 >= obsCo[14].x && characterCoX + 50 <= obsCo[14].x + 50 && characterCoY + 50 >= obsCo[14].y && characterCoY + 50 <= obsCo[14].y + 50))
	{
		characterCoX -= 20;

	}

	else if ((characterCoX + 50 >= obsCo[15].x && characterCoX + 50 <= obsCo[15].x + 50 && characterCoY + 50 >= obsCo[15].y && characterCoY + 50 <= obsCo[15].y + 50) || (characterCoX + 50 >= obsCo[16].x && characterCoX + 50 <= obsCo[16].x + 50 && characterCoY + 50 >= obsCo[16].y && characterCoY + 50 <= obsCo[16].y + 50) || (characterCoX + 50 >= obsCo[17].x && characterCoX + 50 <= obsCo[17].x + 50 && characterCoY + 50 >= obsCo[17].y && characterCoY + 50 <= obsCo[17].y + 50) || (characterCoX + 50 >= obsCo[18].x && characterCoX + 50 <= obsCo[18].x + 50 && characterCoY + 50 >= obsCo[18].y && characterCoY + 50 <= obsCo[18].y + 50) || (characterCoX + 50 >= obsCo[19].x && characterCoX + 50 <= obsCo[19].x + 50 && characterCoY + 50 >= obsCo[19].y && characterCoY + 50 <= obsCo[19].y + 50))
	{
		characterCoX -= 20;

	}

	// jems Co-ordinate colision check

	for (int j = 0; j < 10; j++)
	{
		if (characterCoX + 50 >= jemsCo[j].x && characterCoX + 50 <= jemsCo[j].x + 50 && characterCoY + 50 >= jemsCo[j].y && characterCoY + 50 <= jemsCo[j].y + 50)
		{
			jemsCo[j].show = false;
			gemsCount += 1;
		}
	}

	// to show jems if not collided

	for (int j = 0; j < 10; j++)
	{
		if (jemsCo[j].show == true)
		{
			iShowImage(jemsCo[j].x, jemsCo[j].y, 30, 30, jems[j]);
		}
	}

	iShowImage(jemsCo[10].x, jemsCo[10].y, 30, 30, finishline);

	iSetColor(55, 25, 62);
	iFilledRectangle(0, 0, 100, 600);

	iSetColor(12, 125, 45);
	sprintf_s(strTimer, "%d", timerValueE);
	iText(15, 500, "Time: ", GLUT_BITMAP_HELVETICA_18);
	iText(70, 500, strTimer, GLUT_BITMAP_HELVETICA_18);

	sprintf_s(strGems, "%d", gemsCount);
	iText(15, 420, "Score: ", GLUT_BITMAP_HELVETICA_18);
	iText(70, 420, strGems, GLUT_BITMAP_HELVETICA_18);


	


	if (timerValueE == 0 || characterCoX <= 0 || characterCoX >= 1000)
	{
		gameState = 10;
	}

	if (characterCoX + 50 >= jemsCo[10].x && characterCoX + 50 <= jemsCo[10].x + 50 && characterCoY + 50 >= jemsCo[10].y && characterCoY + 50 <= jemsCo[10].y + 50)
	{
		gameState = 11;
	}
