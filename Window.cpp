#include "Window.h"

Window::Window()
{
	width = 800;
	height = 600;
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
Window::Window(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;
	rotax = 0.0f;
	rotay = 0.0f;
	rotaz = 0.0f;
	articulacion1 = 0.0f;
	articulacion2 = 0.0f;
	articulacion3 = 0.0f;
	articulacion4 = 0.0f;
	articulacion5 = 0.0f;
	articulacion6 = 0.0f;
	articulacion7 = 0.0f;
	articulacion8 = 0.0f;
	articulacion9 = 1;
	articulacion10 = 1;
	articulacion11 = 0.0f;
	AvanzaBladeW = 0.0f;
	AvanzaBladeA = 0.0f;
	AvanzaBladeS = 0.0f;
	AvanzaBladeD = 0.0f;
	AvanzaBlade = 0.0f;
	MueveBlade = 0.0f;
	
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
int Window::Initialise()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	mainWindow = glfwCreateWindow(width, height, "Proyecto Final CGeIHC: 2025-2", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//MANEJAR TECLADO y MOUSE
	createCallbacks();


	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST); //HABILITAR BUFFER DE PROFUNDIDAD
	// Asignar valores de la ventana y coordenadas

	//Asignar Viewport
	glViewport(0, 0, bufferWidth, bufferHeight);
	//Callback para detectar que se está usando la ventana
	glfwSetWindowUserPointer(mainWindow, this);
}

void Window::createCallbacks()
{
	glfwSetKeyCallback(mainWindow, ManejaTeclado);
	glfwSetCursorPosCallback(mainWindow, ManejaMouse);
}

GLfloat Window::getXChange()
{
	GLfloat theChange = xChange;
	xChange = 0.0f;
	return theChange;
}

GLfloat Window::getYChange()
{
	GLfloat theChange = yChange;
	yChange = 0.0f;
	return theChange;
}

void Window::ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}


	if (key == GLFW_KEY_E)
	{
		theWindow->rotax += 10.0;
	}
	if (key == GLFW_KEY_R)
	{
		theWindow->rotay += 10.0; //rotar sobre el eje y 10 grados
	}
	if (key == GLFW_KEY_T)
	{
		theWindow->rotaz += 10.0;
	}

	//Avance Blade
	if (key == GLFW_KEY_W) {
		if (action == GLFW_PRESS) {
			theWindow->AvanzaBladeW = 1.0f;
			//theWindow->AvanzaBlade = 1.0f;


		}
		else if (action == GLFW_RELEASE) {
			theWindow->AvanzaBladeW = 0.0f;
			//theWindow->AvanzaBlade = 1.0f;

		}
	}
	if (key == GLFW_KEY_A) {
		if (action == GLFW_PRESS) {
			theWindow->AvanzaBladeA = 1.0f;
			//theWindow->AvanzaBlade = 1.0f;


		}
		else if (action == GLFW_RELEASE) {
			theWindow->AvanzaBladeA = 0.0f;
			//theWindow->AvanzaBlade = 1.0f;

		}
	}
	if (key == GLFW_KEY_S) {
		if (action == GLFW_PRESS) {
			theWindow->AvanzaBladeS = 1.0f;
			//theWindow->AvanzaBlade = 1.0f;


		}
		else if (action == GLFW_RELEASE) {
			theWindow->AvanzaBladeS = 0.0f;
			//theWindow->AvanzaBlade = 1.0f;

		}
	}
	if (key == GLFW_KEY_D) {
		if (action == GLFW_PRESS) {
			theWindow->AvanzaBladeD = 1.0f;
			//theWindow->AvanzaBlade = 1.0f;

		}
		else if (action == GLFW_RELEASE) {
			theWindow->AvanzaBladeD = 0.0f;
			//theWindow->AvanzaBlade = 1.0f;

		}
	}
	if (key == GLFW_KEY_W)
	{
		theWindow->MueveBlade -= 0.2;
	}

	//Movimiento brazos y piernas Avatar
	if (key == GLFW_KEY_W || key == GLFW_KEY_S || key == GLFW_KEY_D || key == GLFW_KEY_A) {
		if (action == GLFW_PRESS) {
			theWindow->AvanzaBlade = 1.0f;

		}
		else if (action == GLFW_RELEASE) {
			theWindow->AvanzaBlade = 0.0f;
		}
	}

	//Cámara Blade
	if (key == GLFW_KEY_F && action == GLFW_PRESS)
	{
		theWindow->articulacion1 = 1.0;
	}
	else theWindow->articulacion1 = 0.0;
	//Vista aérea
	if (key == GLFW_KEY_G && action == GLFW_PRESS)
	{
		theWindow->articulacion2 = 1.0;
	}
	else theWindow->articulacion2 = 0.0;
	//Stand Hacha
	if (key == GLFW_KEY_H && action == GLFW_PRESS)
	{
		theWindow->articulacion3 = 1.0;
	}
	else theWindow->articulacion3 = 0.0;
	//Stand boliche
	if (key == GLFW_KEY_J && action == GLFW_PRESS)
	{
		theWindow->articulacion4 = 1.0;
	}
	else theWindow->articulacion4 = 0.0;
	//Stand dados
	if (key == GLFW_KEY_K && action == GLFW_PRESS)
	{
		theWindow->articulacion5 = 1.0;
	}
	else theWindow->articulacion5 = 0.0;
	//Jaula bateo
	if (key == GLFW_KEY_L && action == GLFW_PRESS)
	{
		theWindow->articulacion6 = 1.0;
	}
	else theWindow->articulacion6 = 0.0;
	//Stand dardos
	if (key == GLFW_KEY_M && action == GLFW_PRESS)
	{
		theWindow->articulacion7 = 1.0;
	}
	else theWindow->articulacion7 = 0.0;
	//Golpear al topo
	if (key == GLFW_KEY_N && action == GLFW_PRESS)
	{
		theWindow->articulacion8 = 1.0;
	}
	else theWindow->articulacion8 = 0.0;
	//Cámara libre
	if (key == GLFW_KEY_Q && action == GLFW_PRESS)
	{
		theWindow->articulacion11 = 1.0;
	}
	else theWindow->articulacion11 = 0.0;

	//Luz Inazuma
	if (key == GLFW_KEY_O && action == GLFW_PRESS)
	{
		theWindow->articulacion9 += 1;
	}

	//Luz Hot Dogs
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
	{
		theWindow->articulacion10 += 1;
	}

	if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{
		const char* key_name = glfwGetKeyName(GLFW_KEY_D, 0);
		//printf("se presiono la tecla: %s\n",key_name);
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			theWindow->keys[key] = true;
			//printf("se presiono la tecla %d'\n", key);
		}
		else if (action == GLFW_RELEASE)
		{
			theWindow->keys[key] = false;
			//printf("se solto la tecla %d'\n", key);
		}
	}

}

void Window::ManejaMouse(GLFWwindow* window, double xPos, double yPos)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (theWindow->mouseFirstMoved)
	{
		theWindow->lastX = xPos;
		theWindow->lastY = yPos;
		theWindow->mouseFirstMoved = false;
	}

	theWindow->xChange = xPos - theWindow->lastX;
	theWindow->yChange = theWindow->lastY - yPos;

	theWindow->lastX = xPos;
	theWindow->lastY = yPos;
}


Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();

}