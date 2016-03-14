#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

float z = 0;
float factor = 1.0f;
float speed = 5.0f;
float zMin = -5;
float zMax = 5;
int lastTime = 0;

void render() {
	int elapsedTime = glutGet(GLUT_ELAPSED_TIME);
	int gap = lastTime - elapsedTime;
	lastTime = elapsedTime;

	z += factor * speed * (float) gap / 1000;
	if (z < zMin) {
		z = zMin * 2 - z;
		factor *= -1;
	}

	if (z > zMax) {
		z = zMax * 2 - z;
		factor *= -1;
	}

	glClearColor(100.0f / 255, 149.0f / 255, 237.0f / 255, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glLineWidth(100.0f);
	gluPerspective(45.0, 1.0, 0.1, 1000);
	gluLookAt(0, 0, -10, 0, 0, 0, 0, 1, 0);

	glBegin(GL_TRIANGLES);
	{
		glColor3f(1.0f, 0, 0);

		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glVertex3f(0.5f, -0.5f, z);
	}
	glEnd();

	glFlush();
}

void timerCallback(int mills) {
	glutTimerFunc(mills, timerCallback, mills);
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
	glutInitWindowSize(640, 640);
	glutCreateWindow("OpenGL TEST");

	glutTimerFunc(16, timerCallback, 16);
	glutDisplayFunc(render);

	glutMainLoop();

	return 0;
}