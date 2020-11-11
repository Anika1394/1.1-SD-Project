#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

int ball_x, ball_y;
int dx, dy;

void ballChange(){
	ball_x += dx;
	ball_y += dy;

	if(ball_x > 400 || ball_x < 0)dx = -dx;
	if(ball_y > 400 || ball_y < 0)dy = -dy;
}

#endif // MYHEADER_H_INCLUDED