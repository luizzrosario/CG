#include <GL/freeglut.h>

/*
Trabalho de Computação Gráfica
Realizado pelos alunos: 
Gustavo Aragão Oliveira
Luiz Felipe do Rosário Alves Silva
*/

// Variáveis para armazenar as coordenadas do triângulo
float triangleX = 0.0f; // Coordenada x do triângulo
float triangleY = 0.0f; // Coordenada y do triângulo

// Função para desenhar o triângulo
void drawTriangle()
{
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cores
    glLoadIdentity(); // Carrega a matriz de identidade

    glTranslatef(triangleX, triangleY, 0.0f); // Aplica uma translação às coordenadas do triângulo
    
	glBegin(GL_TRIANGLES); // Inicia a definição do triângulo
    glColor3f(0.0f, 0.0f, 1.0f); // Define a cor azul
	glVertex2f(0.0f, 0.2f); // Define o primeiro vértice do triângulo
    glColor3f(1.0f, 0.0f, 0.0f); // Define a cor vermelha
    glVertex2f(-0.2f, -0.2f); // Define o segundo vértice do triângulo
    glColor3f(0.0f, 1.0f, 0.0f); // Define a cor verde
    glVertex2f(0.2f, -0.2f); // Define o terceiro vértice do triângulo
    
    glEnd(); // Finaliza a definição do triângulo
    glFlush(); // Envia os comandos para a GPU
}

// Função para lidar com o input do teclado
void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27: // Tecla ESC
            exit(0); // Encerra o programa
            break;
    }
}

// Função para lidar com o input das setas do teclado
void handleArrowKeys(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_UP: // Seta para cima
        	if(triangleY<0.8){ //verifica se está antes da borda
            triangleY += 0.1f; // Incrementa a coordenada y do triângulo
        	}
            break;
        case GLUT_KEY_DOWN: // Seta para baixo
        	if(triangleY>-0.8){ //verifica se está antes da borda
            	triangleY -= 0.1f; // Decrementa a coordenada y do triângulo
        	}
			break;
        case GLUT_KEY_LEFT: // Seta para a esquerda
            if(triangleX>-0.8){ //verifica se está antes da borda
            	triangleX -= 0.1f; // Decrementa a coordenada y do triângulo
        	}
            break;
        case GLUT_KEY_RIGHT: // Seta para a direita
        	if(triangleX<0.8){ //verifica se está antes da borda
            triangleX += 0.1f; // Incrementa a coordenada x do triângulo
        }
            break;
    }

    glutPostRedisplay(); // Marca a janela para redesenhar
}

// Função principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Configura o modo de exibição
    glutInitWindowSize(800, 600); // Configura o tamanho da janela
    glutCreateWindow("Triângulo Móvel"); // Cria a janela com o título especificado

    glutDisplayFunc(drawTriangle); // Define a função de desenho
    glutSpecialFunc(handleArrowKeys); // Define a função de tratamento das setas do teclado
    glutKeyboardFunc(handleKeypress); // Define a função de tratamento das teclas normais do teclado

    glutMainLoop(); // Inicia o loop principal do GLUT

    return 0;
}
