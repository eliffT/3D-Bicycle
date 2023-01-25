#include <GL/glut.h>
#include <math.h>
GLint a1 = 0, a2 = 0;
float derece = 0;
float xgotur = 0, ygotur = 0, zgotur = 0;
#define DUZELT 0.0174532925



void goturil(void)
{

	xgotur -= 0.01;

}

void goturger(void)
{

	xgotur += 0.01;

}


void special(int key, int, int)
{
	switch (key) {
	case GLUT_KEY_UP: (a1 += 5) %= 360; goturil(); break;
	case GLUT_KEY_DOWN: (a1 -= 5) %= 360; goturger(); break;
	case GLUT_KEY_LEFT: (a2 += 5) %= 360; break;
	case GLUT_KEY_RIGHT: (a2 -= 5) %= 360; break;
	default: return;
	}
	glutPostRedisplay();
}



void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glTranslatef(xgotur, ygotur, zgotur);


	//ArkaTeker
	glPushMatrix();
	glTranslatef(1.0, -2.0, 0.0);
	glLineWidth(0.5);
	glColor3f(1.0, 0.0, 0.5);
	glRotatef((GLfloat)a1, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)a2, 0.0, 1.0, 0.0);
	glutWireTorus(0.2, 1.0, 7, 20);
	glPopMatrix();

	//Gövde
	glTranslatef(0.0, 0.0, 0.0);
	glLineWidth(2.5);
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, -2.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(-0.5, -2.0, 0.0);

	glVertex3f(1.0, -2.0, 0.0);
	glVertex3f(-0.5, -2.0, 0.0);
	glVertex3f(-2.0, 0.0, 0.0);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(-3.0, -2.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 0.5, 0.5);
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(-2.3, 0.5, 0.0);
	//glVertex3f(-2.0, 0.5, 0.0);
	glVertex3f(-2.5, 0.0, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(-0.5, -2.0, 0.0);
	glVertex3f(-0.5, -2.2, 0.0);
	glEnd();
	glRectf(-0.5, -2.2, -0.8, -2.6);
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRectf(0.0, 0.5, 1.0, 0.7);
	glRotatef((GLfloat)a2, 0.0, 1.0, 0.0);
	glPopMatrix();



	//ÖnTeker

	glPushMatrix();
	glTranslatef(-3.0, -2.0, 0.0);
	glLineWidth(0.5);
	glColor3f(1.0, 0.0, 0.5);
	glRotatef((GLfloat)a1, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)a2, 0.0, 1.0, 0.0);
	glutWireTorus(0.2, 1.0, 7, 20);
	glPopMatrix();
	glutSwapBuffers();



}
void reshape(GLint w, GLint h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, GLfloat(w) / GLfloat(h), 1.0, 20.0);

}

void init() {
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1, 2, 8, 0, 0, 0, 0, 1, 0);

}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("app");
	glutDisplayFunc(display);

	glutReshapeFunc(reshape);
	glutSpecialFunc(special);
	init();
	glutMainLoop();
}

