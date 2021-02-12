#include <stdlib.h>
#include <math.h>
#include <glut.h>

float angle = 0.0;
float lx = 0.0f, lz = -1.0f;
float x = 0.0f, z = 5.0f;
float deltaAngle = 0.0f;
float deltaMove = 0;

void changeSize(int w, int h) 
{
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void Light()
{
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	GLfloat amb[] = { 0.0, 1.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	GLfloat pos[] = { -1.0, -1.0, -1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);

	GLfloat dif[] = { 1.0, 0.5, 0.1, 1.0 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, dif);
	GLfloat pos1[] = { 1.0, 0.0, 0.0, 0.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);

	GLfloat spec[] = { 0.0, 0.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
	GLfloat pos2[] = { 1.0, 1.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, pos2);

}

void drawSnowMan() 
{
	// тело снеговика
	glTranslatef(2.0f, 0.5f, 0.8f);
	glutSolidSphere(0.75f, 20, 20);
	// голова снеговика
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f, 20, 20);
	// глаза снеговика
	glPushMatrix();
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f, 10, 10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 10, 10);
	glPopMatrix();
}

void drawCube() 
{
	// Перед
	glBegin(GL_POLYGON);
	glVertex3f(3.5, -1.5, 1.5);
	glVertex3f(3.5, -0.5, 1.5);
	glVertex3f(2.5, -0.5, 1.5);
	glVertex3f(2.5, -1.5, 1.5);
	glEnd();

	// Правая сторона
	glBegin(GL_POLYGON);
	glVertex3f(3.5, -1.5, 0.5);
	glVertex3f(3.5, -0.5, 0.5);
	glVertex3f(3.5, -0.5, 1.5);
	glVertex3f(3.5, -1.5, 1.5);
	glEnd();

	// Левая сторона
	glBegin(GL_POLYGON);
	glVertex3f(2.5, -1.5, 1.5);
	glVertex3f(2.5, -0.5, 1.5);
	glVertex3f(2.5, -0.5, 0.5);
	glVertex3f(2.5, -1.5, 0.5);
	glEnd();

	// Верх
	glBegin(GL_POLYGON);
	glVertex3f(3.5, -0.5, 1.5);
	glVertex3f(3.5, -0.5, 0.5);
	glVertex3f(2.5, -0.5, 0.5);
	glVertex3f(2.5, -0.5, 1.5);
	glEnd();

	// Низ
	glBegin(GL_POLYGON);
	glVertex3f(3.5, -1.5, 0.5);
	glVertex3f(3.5, -1.5, 1.5);
	glVertex3f(2.5, -1.5, 1.5);
	glVertex3f(2.5, -1.5, 0.5);
	glEnd();
}


void computePos(float deltaMove)
{
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle)
{
	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

void renderScene(void) 
{
	if (deltaMove)
		computePos(deltaMove);
	if (deltaAngle)
		computeDir(deltaAngle);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt
	(x, 1.0f, z,
		x + lx, 1.0f, z + lz,
		0.0f, 1.0f, 0.0f);

	glutSolidTeapot(0.5);
	drawSnowMan();
	drawCube();
	Light();
	glutSwapBuffers();
}


void pressKey(int key, int xx, int yy) 
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		deltaAngle = -0.01f;
		break;
	case GLUT_KEY_RIGHT:
		deltaAngle = 0.01f;
		break;

	case GLUT_KEY_UP:
		deltaMove = 0.5f;
		break;
	case GLUT_KEY_DOWN:
		deltaMove = -0.5f;
		break;
	}
}

void releaseKey(int key, int x, int y) {

	switch (key) 
	{
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT:
		deltaAngle = 0.0f;
		break;

	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN:
		deltaMove = 0;
		break;
	}
}

void main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Источники света");
	
	glClearColor(0.0, 1.0, 1.0, 0.0);
	
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

	glutMainLoop();
}