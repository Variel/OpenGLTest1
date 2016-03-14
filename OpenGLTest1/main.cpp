#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

void render() {
	glClearColor(100.0f / 255, 149.0f / 255, 237.0f / 255, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glLineWidth(100.0f);
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(1.0f, 0, 0);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.0f);
	}
	glEnd();

	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
	glutInitWindowSize(640, 640);
	glutCreateWindow("OpenGL TEST");

	glutDisplayFunc(render);

	glutMainLoop();

	return 0;
}