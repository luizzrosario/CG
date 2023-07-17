#include <GL/freeglut.h>

/*
Trabalho de Computa��o Gr�fica
Realizado pelos alunos: 
Gustavo Arag�o Oliveira
Luiz Felipe do Ros�rio Alves Silva
*/

// Vari�veis para armazenar as coordenadas do tri�ngulo
float triangleX = 0.0f; // Coordenada x do tri�ngulo
float triangleY = 0.0f; // Coordenada y do tri�ngulo

// Fun��o para desenhar o tri�ngulo
void drawTriangle()
{
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cores
    glLoadIdentity(); // Carrega a matriz de identidade

    glTranslatef(triangleX, triangleY, 0.0f); // Aplica uma transla��o �s coordenadas do tri�ngulo
    
	glBegin(GL_TRIANGLES); // Inicia a defini��o do tri�ngulo
    glColor3f(0.0f, 0.0f, 1.0f); // Define a cor azul
	glVertex2f(0.0f, 0.2f); // Define o primeiro v�rtice do tri�ngulo
    glColor3f(1.0f, 0.0f, 0.0f); // Define a cor vermelha
    glVertex2f(-0.2f, -0.2f); // Define o segundo v�rtice do tri�ngulo
    glColor3f(0.0f, 1.0f, 0.0f); // Define a cor verde
    glVertex2f(0.2f, -0.2f); // Define o terceiro v�rtice do tri�ngulo
    
    glEnd(); // Finaliza a defini��o do tri�ngulo
    glFlush(); // Envia os comandos para a GPU
}

// Fun��o para lidar com o input do teclado
void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27: // Tecla ESC
            exit(0); // Encerra o programa
            break;
    }
}

// Fun��o para lidar com o input das setas do teclado
void handleArrowKeys(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_UP: // Seta para cima
        	if(triangleY<0.8){ //verifica se est� antes da borda
            triangleY += 0.1f; // Incrementa a coordenada y do tri�ngulo
        	}
            break;
        case GLUT_KEY_DOWN: // Seta para baixo
        	if(triangleY>-0.8){ //verifica se est� antes da borda
            	triangleY -= 0.1f; // Decrementa a coordenada y do tri�ngulo
        	}
			break;
        case GLUT_KEY_LEFT: // Seta para a esquerda
            if(triangleX>-0.8){ //verifica se est� antes da borda
            	triangleX -= 0.1f; // Decrementa a coordenada y do tri�ngulo
        	}
            break;
        case GLUT_KEY_RIGHT: // Seta para a direita
        	if(triangleX<0.8){ //verifica se est� antes da borda
            triangleX += 0.1f; // Incrementa a coordenada x do tri�ngulo
        }
            break;
    }

    glutPostRedisplay(); // Marca a janela para redesenhar
}

// Fun��o principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Configura o modo de exibi��o
    glutInitWindowSize(800, 600); // Configura o tamanho da janela
    glutCreateWindow("Tri�ngulo M�vel"); // Cria a janela com o t�tulo especificado

    glutDisplayFunc(drawTriangle); // Define a fun��o de desenho
    glutSpecialFunc(handleArrowKeys); // Define a fun��o de tratamento das setas do teclado
    glutKeyboardFunc(handleKeypress); // Define a fun��o de tratamento das teclas normais do teclado

    glutMainLoop(); // Inicia o loop principal do GLUT

    return 0;
}
