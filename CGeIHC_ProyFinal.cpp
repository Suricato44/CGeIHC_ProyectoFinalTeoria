/*
PROYECTO FINAL:
	Cuadriello Valdés Cynthia Citlalli  -- 422020266
	Cuadriello Valdés Diana Sinsuni     -- 422038870
	Gutiérrez Ávila Tristan Bernardo    -- 319111347
*/

// --------------------------------------
// ----------IMPORTAR MÓDULOS------------
// --------------------------------------


//para cargar imagen
#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <math.h>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader_light.h"
#include "Camera.h"
#include "Texture.h"
#include "Sphere.h"
#include"Model.h"
#include "Skybox.h"

//para iluminación
#include "CommonValues.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Material.h"
const float toRadians = 3.14159265f / 180.0f;

// --------------------------------------
// -----------DEFINIR VENTANA------------
// --------------------------------------

Window mainWindow;

// --------------------------------------
// ------------DEFINIR LISTAS------------
// --------------------------------------

std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;

// --------------------------------------
// -----------DEFINIR CÁMARAS------------
// --------------------------------------

Camera camera;
Camera camera2;
Camera camera3;
Camera cameraLibre;

// --------------------------------------
// -----------DEFINIR TEXTURAS-----------
// --------------------------------------

Texture plainTexture;
Texture pisoTexture;
Texture rejaTexture;
Texture caminoTexture;

// --------------------------------------
// -----------DEFINIR MODELOS------------
// --------------------------------------

//Rueda Fortuna
Model RuedaFortuna_M;
Model NeuvilletteCuerpo_Genshin_M;
Model NeuvilletteHombro_Genshin_M;
Model NeuvilletteBrazo_Genshin_M;
Model Furina_Genshin_M;

//Puesto Helados
Model PuestoHelado_M;
Model MariusCasual_M;
Model Sigwinne_Genshin_M;
Model MariusCasualBrazo_M;
Model BolaHelado_Suelta_M;
Model BolaHelado_Arriba_M;
Model BolaHelado_Derecha_M;
Model BolaHelado_Izquierda_M;

Model BolaHelado_Suelta_Naranja_M;
Model BolaHelado_Suelta_Morada_M;

//Banca Puesto de Helados
Model Wriothesley_Genshin_M;

//Puesto Dardos
Model PuestoDardos_M;
Model Globo1_M;
Model Globo2_M;
Model Globo3_M;
Model Dardo_M;
Model Firefly_StarRail_M;
Model LukeNormal_M;

//Carrusel
Model Carrusel_Base_M;
Model Carrusel_M;
Model Lyney_M;

//Baño Puesto Dardos
Model Bano_M;
Model MariusChino_M;

//Puesto Hot Dogs
Model PuestoHotDog_M;
Model Jean_Genshin_M;
Model VynNormal_M;

//Banca Puesto de Hot Dogs
Model Klee_Genshin_M;

//Banca Puesto Palomitas
Model Sunday_StarRail_M;

//Artem Protagonista
Model ArtemNormalCuerpo_M;
Model ArtemNormalBrazo_M;
Model ArtemNormalHoja_M;

//Puesto Palomitas
Model PuestoPalomitas_M;
Model Feixiao_StarRail_M;

//Puesto Lanzamiento Hacha
Model LanzamientoHacha_M;
Model Hacha_M;
Model Wanderer_Genshin_M;

//Puesto Dados
Model MesaDados_M;
Model MesaDados_Dados1_M;
Model MesaDados_Dados2_M;
Model MesaDados_DadosMesa_M;
Model Aventurine_StarRail_M;

//Puesto Boliche
Model Boliche_M;
Model Rendija_Boliche_M;
Model Bolo_M;
Model Bola_Boliche_M;
Model Ayato_Genshin_M;

//Puesto Golpear al Topo
Model GolpearTopo_M;
Model GolpearTopo_Topos1_M;
Model GolpearTopo_Topos2_M;
Model GolpearTopo_MazaHerta_M;
Model Yanqing_StarRail_M;

//Puesto Algodón Azúcar
Model MaquinaAlgodon_M;
Model Robin_StarRail_M;

//Puesto Carros Chocones
Model CarrosChocones_M;
Model ArtemCasual_Themis_M;
Model Carro_Azul_M;
Model Carro_Naranja_M;

//Jaula Bateo
Model PuestoBateo_M;
Model Bate_M;
Model PelotaBateo_M;
Model LukeCasual_Themis_M;

//Baño Boliche
Model Ratio_StarTail_M;

//Puesto de Tickets
Model PuestoTickets_M;
Model PomPom_M;

//Banca Boliche
Model Banca_Genshin_M;
Model VynChino_Themis_M;

//Puesto de Tacos
Model PuestoTacos_M;
Model Herta_StarTail_M;
Model Xiao_Genshin_M;

//Decoraciones
Model Lampara_Genshin_M;
Model Bote_StarRail_M;

//Plataforma Dodoco
Model Plataforma_Genshin_M;

//Mesa Comida Genshin
Model MesaComida;
Model LecheDango;

//Stand madera Tears of Themis
Model Stand_Dardos_M;
Model Stand_HotDog_M;
Model Stand_Taquilla_M;
Model Stand_Carrusel_M;
Model Stand_Carros_M;
Model Stand_Comida_M;
Model Stand_Dados_M;
Model Stand_Topos_M;

//Puesto Inazuma
Model Ixbalanque_M;
Model PuestoInazuma_M;

//Globos de Genshin
Model Globo_Enojado_M;
Model Globo_Feliz_M;
Model Globo_Verde_M;
Model Globo_Naranja_M;

//Gatos Star Rail
Model Gato_Basura_M;
Model Gato_Blade_M;
Model Gato_Clara_M;
Model Gato_DanHeng_M;
Model Gato_Kafka_M;
Model Gato_March_M;
Model Gato_Naranja_M;
Model Gato_RuanMei_M;
Model Gato_Herta_M;
Model Gato_Verde_M;

//Blade Star Rail
Model Blade_Cuerpo;
Model Blade_Cabeza;
Model Blade_HombroDer;
Model Blade_AntebrazoDer;
Model Blade_ManoDer;
Model Blade_HombroIzq;
Model Blade_AntebrazoIzq;
Model Blade_ManoIzq;
Model Blade_PiernaDer;
Model Blade_PantorrillaDer;
Model Blade_PieDer;
Model Blade_PiernaIzq;
Model Blade_PantorrillaIzq;
Model Blade_PieIzq;

Model BrazoDerecho;
Model BrazoDerecho_Sur;
Model BrazoDerecho_Derecha;
Model BrazoDerecho_Izquierda;

//Bote
Model Bote_Cuerpo;
Model Bote_HombroIzq;
Model Bote_AntebrazoIzq;
Model Bote_PiernaDer;
Model Bote_PantorrillaDer;
Model Bote_PiernaIzq;
Model Bote_PantorrillaIzq;

//Moneda Juegos
Model Tear_Themis;
Model Destino_Genshin;
Model Ticket_StarRail;

// --------------------------------------
// ------------DEFINIR SKYBOX------------
// --------------------------------------

Skybox skybox;

// --------------------------------------
// ----------DEFINIR MATERIALES----------
// --------------------------------------

Material Material_brillante;
Material Material_opaco;

Material Material_Avatar;
Material Material_Madera;
Material Material_Reja;
Material Material_Terciopelo;
Material Material_MaderaPulida;
Material Material_Plastico;

// -------------------------------------------------
// ----------DEFINIR CONSTANTES Y VARIABLES---------
// -------------------------------------------------

GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
static double limitFPS = 1.0 / 60.0;

//Para los skyboxes
int skyCount = 0; //Se crea una variable contadora para que lleve la cuenta de vueltas que lleva el while y se vayan cambiando

//Cámaras
int banderaCamaraMovimiento = 0; //Para manejar los cambios en la camara de vistas estáticas a la general dinámica
int banderaCamara = 0; //Indica si la camara se puede cambiar o no (en animación o no). 1 ocupado, 0 desocupado. INICIA EN 0
int camaraAnimacion = 0; //Indica qué stand se muestra

//Luces
int luzContador = 0;		//Rueda Fortuna
int luzContador2 = 0;		//Carrusel
float luzContador3 = 0.0f;	//Carritos Chocones
float luzContador4 = 0.0f;	//Carritos Chocones
int banderaLuz = 0;			//Carritos Chocones
float luzContador5 = 0.0f;	//Puesto Tickets
int banderaLuz1 = 0;		//Puesto Tickets
float luzContador6 = 0.0f;	//Lámpara
int banderaLuz2 = 0;		//Lámpara
int contadorTopos = 0;		//Animación Topos
int contadorBate = 0;		//Animación Bate

//Movimiento Blade Avatar
float angulovaria = 0.0f;
float angulovariaAux = 0.0f;
float angulovaria2 = 0.0f;
float angulovaria3 = 0.0f;

//Animación Entrega moneda
float brazoVariacion = 20.0f;
float brazoVariacion1 = 100.0f;
float timerBateo = 0.0;

//Animación Bateo
float movBateo = 0.0;
float movBateoPelota = 0.0;
float movBateoPelotaRegreso = 0.0;
float movBateoRegreso = 0.0;
float inicioBrazo = 0.0;

//Animación Dardos
float movDardoNuevo = 0.0;
float movDardoNuevoMovimiento = 0.0f;
float movDardoRegreso = 0.0f;
float moverDardoAbajo = 0.0f;
float movDardoNuevoArriba = 0.0f;
float movDardoNuevoMovimiento2 = 0.0f;
float movDardoRegreso2 = 0.0f;

//Animación Marius helados
int banderaMarius = 0;
float MariusBrazo = 0.0;
int MariusContador = 0;
int MariusContador2 = 0;
int helado1 = 0;
int helado2 = 0;
int helado3 = 0;

//Animación Carros Chocones
int banderaCarro1 = 0;
float CarroAzul = 0.0f;
int banderaCarro2 = 0;
float CarroNaranja = 0.0f;
float CarroAzul1 = 0.0f;
float CarroAzul2 = 0.0f;

//Movimiento Bote 
float Bangulovaria = 0.0f;
float BangulovariaAux = 0.0f;
float Bangulovaria2 = 0.0f;
float Bangulovaria3 = 0.0f;
float BanguloAvanza = 0.0f;
float BanguloMira = 0.0f;
float senoAnterior = 0.0f;
const float epsilon = 0.01f; // Umbral de cercanía a los extremos
bool yaCambio = false;

//Animacion Topos
float ToposY1 = 0.0f;
float ToposY2 = 0.0f;
float BrazoMartillo = 20.0f;

//Animacion Dados
float TiroDado = 0.0f;

//Movimiento Neuvillette (Otro Protagonista)
float NeuviHombro = 0.0f;
float NeuviBrazoY = 0.0f;
int banderaNeuvi = 0;
int banderaNeuvi2 = 0;

//Movimiento Artem (Otro Protagonista)
int banderaArtem = 0;
float ArtemBrazo = 0.0f;
float ArtemHoja = 0.0f;
float ArtemHoja2 = 0.0f;

//General, timing de comienzo de programa
int contadorInicioPrograma = 0;
int contadorInicioPrograma2 = 0;
int contadorInicioPrograma3 = 0;
int contadorInicioPrograma4 = 0;

// --------------------------------------
// -------------DEFINIR LUCES------------
// --------------------------------------

//Luz direccional
DirectionalLight mainLight;

//para declarar varias luces
PointLight pointLightsDia[MAX_POINT_LIGHTS];
SpotLight spotLightsDia[MAX_SPOT_LIGHTS];

PointLight pointLightsDia2[MAX_POINT_LIGHTS]; // Para las luces interactivas con teclado

PointLight pointLightsNoche[MAX_POINT_LIGHTS];
SpotLight spotLightsNoche[MAX_SPOT_LIGHTS];

//Luz Hacha
SpotLight spotLightsDiaHacha[MAX_SPOT_LIGHTS];
SpotLight spotLightsNocheHacha[MAX_SPOT_LIGHTS];

//Luz Boliche
SpotLight spotLightsDiaBoliche[MAX_SPOT_LIGHTS];
SpotLight spotLightsNocheBoliche[MAX_SPOT_LIGHTS];

//Luz Dados
SpotLight spotLightsDiaDados[MAX_SPOT_LIGHTS];
SpotLight spotLightsNocheDados[MAX_SPOT_LIGHTS];

//Luz Bateo
SpotLight spotLightsDiaBateo[MAX_SPOT_LIGHTS];
SpotLight spotLightsNocheBateo[MAX_SPOT_LIGHTS];

//Luz Dardos
SpotLight spotLightsDiaDardos[MAX_SPOT_LIGHTS];
SpotLight spotLightsNocheDardos[MAX_SPOT_LIGHTS];

//Luz Topos
SpotLight spotLightsDiaTopos[MAX_SPOT_LIGHTS];
SpotLight spotLightsNocheTopos[MAX_SPOT_LIGHTS];


// --------------------------------------
// -----------DEFINIR SHADERS------------
// --------------------------------------

//Vertex Shader
static const char* vShader = "shaders/shader_light.vert";

//Fragment Shader
static const char* fShader = "shaders/shader_light.frag";


// --------------------------------------
// -----------CÁLCULO NORMALES-----------
// --------------------------------------

//función de calculo de normales por promedio de vértices 
void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
	unsigned int vLength, unsigned int normalOffset)
{
	for (size_t i = 0; i < indiceCount; i += 3)
	{
		unsigned int in0 = indices[i] * vLength;
		unsigned int in1 = indices[i + 1] * vLength;
		unsigned int in2 = indices[i + 2] * vLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);

		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
		vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
		vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
	}

	for (size_t i = 0; i < verticeCount / vLength; i++)
	{
		unsigned int nOffset = i * vLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
	}
}


// --------------------------------------
// ----------ESTABLECER OBJETOS----------
// --------------------------------------

void CreateObjects()
{
	//Piso
	unsigned int floorIndices[] = {
		0, 2, 1,
		1, 2, 3
	};

	GLfloat floorVertices[] = {
		//	x      y      z			u	  v			nx	  ny    nz
		-10.0f, 0.0f, -10.0f,	0.0f, 10.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, -10.0f,	10.0f, 10.0f,		0.0f, -1.0f, 0.0f,
		-10.0f, 0.0f, 10.0f,	0.0f, 0.0f,			0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, 10.0f,		10.0f, 0.0f,		0.0f, -1.0f, 0.0f
	};

	//Reja
	unsigned int rejaIndices[] = {
	   0, 1, 2,
	   0, 2, 3,
	};

	GLfloat rejaVertices[] = {
		-12.0f, 0.0f, 0.0f,			0.0f, 0.0f,		0.0f, 0.0f, 0.0f, //inf izq
		12.0f, 0.0f, 0.0f,			1.0f, 0.0f,		0.0f, 0.0f, 0.0f, //inf der
		12.0f, 12.0f, 0.0f,			1.0f, 1.0f,		0.0f, 0.0f, 0.0f, //sup der
		-12.0f, 12.0f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f, //sup izq

	};

	//Camino vertical largo (Derecha)
	unsigned int caminoIndices[] = {
		0, 2, 1,
		1, 2, 3
	};

	GLfloat caminoVertices[] = {
		-10.0f, 0.06f, -100.0f,	0.0f, 10.0f,	0.0f, -1.0f, 0.0f,
		10.0f, 0.06f, -100.0f,	1.0f, 10.0f,	0.0f, -1.0f, 0.0f,
		-10.0f, 0.06f, 125.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.06f, 125.0f,	1.0f, 0.0f,		0.0f, -1.0f, 0.0f

	};

	//Camino vertical corto (Centro e Izquierda)
	unsigned int caminoIndices1[] = {
		0, 2, 1,
		1, 2, 3
	};

	GLfloat caminoVertices1[] = {
		-10.0f, 0.06f, -100.0f,	0.0f, 7.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.06f, -100.0f,	1.0f, 7.0f,		0.0f, -1.0f, 0.0f,
		-10.0f, 0.06f, 56.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.06f, 56.0f,	1.0f, 0.0f,		0.0f, -1.0f, 0.0f

	};

	//Camino horizontal (Frente y Detrás)
	unsigned int caminoIndices2[] = {
		0, 2, 1,
		1, 2, 3
	};

	GLfloat caminoVertices2[] = {
		-94.0f, 0.08f, -10.0f,	0.0f, 1.0f,		0.0f, -1.0f, 0.0f,
		90.0f, 0.08f, -10.0f,	10.0f, 1.0f,	0.0f, -1.0f, 0.0f,
		-94.0f, 0.08f, 10.0f,	0.0f, 0.015f,	0.0f, -1.0f, 0.0f,
		90.0f, 0.08f, 10.0f,	10.0f, 0.015f,	0.0f, -1.0f, 0.0f

	};

	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(floorVertices, floorIndices, 32, 6);
	meshList.push_back(obj1);

	Mesh* obj2 = new Mesh();
	obj2->CreateMesh(rejaVertices, rejaIndices, 32, 6);
	meshList.push_back(obj2);

	Mesh* obj3 = new Mesh();
	obj3->CreateMesh(caminoVertices, caminoIndices, 32, 6);
	meshList.push_back(obj3);

	Mesh* obj4 = new Mesh();
	obj4->CreateMesh(caminoVertices1, caminoIndices1, 32, 6);
	meshList.push_back(obj4);

	Mesh* obj5 = new Mesh();
	obj5->CreateMesh(caminoVertices2, caminoIndices2, 32, 6);
	meshList.push_back(obj5);

	calcAverageNormals(rejaIndices, 6, rejaVertices, 32, 8, 5);

}


// --------------------------------------
// ----------ESTABLECER SHADERS----------
// --------------------------------------

void CreateShaders()
{
	Shader *shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}


// -------------------------------------------
// --------------FUNCIÓN PRINCIPAL------------
// -------------------------------------------

int main()
{
	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	CreateObjects();
	CreateShaders();

	// ----------------------------------
	// --------------CÁMARAS-------------
	// ----------------------------------

	//1 Posición inicial; 2 No relevante; 3 Rotación hacia la izquierda o derecha en grados (+ o -)
	//4 Rotación hacia arriba o abajo en grados (+ o -); 5 y 6 Velocidades para la camara

	//Camara Blade Avatar (F)
	camera = Camera(glm::vec3(83.0f, 11.5f, 140.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 0.3f, 0.5f);

	//Camara aerea (G)
	camera2 = Camera(glm::vec3(0.0f, 270.0f, -10.0f), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f, -90.0f, 0.3f, 0.5f);

	//Camara stands (H,J,K,L,M,N)
	camera3 = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, 0.0f, 0.3f, 0.5f);

	//Cámara libre (Q)
	cameraLibre = Camera(glm::vec3(83.0f, 11.5f, 140.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 0.3f, 0.5f);
	
	// --------------------------------------
	// -----------CARGAR TEXTURAS------------
	// --------------------------------------

	plainTexture = Texture("Textures/plain.png");
	plainTexture.LoadTextureA();
	pisoTexture = Texture("Textures/Pasto.png");
	pisoTexture.LoadTextureA();
	rejaTexture = Texture("Textures/Reja.png");
	rejaTexture.LoadTextureA();
	caminoTexture = Texture("Textures/Camino.png");
	caminoTexture.LoadTextureA();

	// --------------------------------------
	// ------------CARGAR MODELOS------------
	// --------------------------------------

	//Rueda Fortuna
	RuedaFortuna_M = Model();
	RuedaFortuna_M.LoadModel("Models/RuedaFortuna/RuedaFortuna.obj");
	NeuvilletteCuerpo_Genshin_M = Model();
	NeuvilletteCuerpo_Genshin_M.LoadModel("Models/Neuvillette_Genshin/NeuvilletteCuerpo_Genshin.obj");
	NeuvilletteHombro_Genshin_M = Model();
	NeuvilletteHombro_Genshin_M.LoadModel("Models/Neuvillette_Genshin/NeuvilletteHombro_Genshin.obj");
	NeuvilletteBrazo_Genshin_M = Model();
	NeuvilletteBrazo_Genshin_M.LoadModel("Models/Neuvillette_Genshin/NeuvilletteBrazo_Genshin.obj");
	Furina_Genshin_M = Model();
	Furina_Genshin_M.LoadModel("Models/Furina_Genshin/Furina_Genshin.obj");

	//Puesto Helados
	PuestoHelado_M = Model();
	PuestoHelado_M.LoadModel("Models/PuestoHelado/puestoHelado.obj");
	MariusCasual_M = Model();
	MariusCasual_M.LoadModel("Models/MariusCasual_Themis/mariusCasual.obj");
	Sigwinne_Genshin_M = Model();
	Sigwinne_Genshin_M.LoadModel("Models/Sigwinne_Genshin/Sigwinne.obj");
	MariusCasualBrazo_M = Model();
	MariusCasualBrazo_M.LoadModel("Models/MariusCasual_Themis/mariusCasual_Brazo.obj");
	BolaHelado_Suelta_M = Model();
	BolaHelado_Suelta_M.LoadModel("Models/MariusCasual_Themis/BolaSuelta.obj");
	BolaHelado_Arriba_M = Model();
	BolaHelado_Arriba_M.LoadModel("Models/MariusCasual_Themis/BolaArriba.obj");
	BolaHelado_Derecha_M = Model();
	BolaHelado_Derecha_M.LoadModel("Models/MariusCasual_Themis/BolaDerecha.obj");
	BolaHelado_Izquierda_M = Model();
	BolaHelado_Izquierda_M.LoadModel("Models/MariusCasual_Themis/BolaIzquierda.obj");

	BolaHelado_Suelta_Naranja_M = Model();
	BolaHelado_Suelta_Naranja_M.LoadModel("Models/MariusCasual_Themis/BolaSueltaNaranja.obj");
	BolaHelado_Suelta_Morada_M = Model();
	BolaHelado_Suelta_Morada_M.LoadModel("Models/MariusCasual_Themis/BolaSueltaMorada.obj");

	//Banca Puesto de Helados
	Wriothesley_Genshin_M = Model();
	Wriothesley_Genshin_M.LoadModel("Models/Wriothesley_Genshin/Wriothesley_Genshin.obj");

	//Puesto de Dardos
	PuestoDardos_M = Model();
	PuestoDardos_M.LoadModel("Models/PuestoDardos/puestoDardos.obj");
	Globo1_M = Model();
	Globo1_M.LoadModel("Models/PuestoDardos/globo1.obj");
	Globo2_M = Model();
	Globo2_M.LoadModel("Models/PuestoDardos/globo2.obj");
	Globo3_M = Model();
	Globo3_M.LoadModel("Models/PuestoDardos/globo3.obj");
	Dardo_M = Model();
	Dardo_M.LoadModel("Models/PuestoDardos/dardo.obj");
	Firefly_StarRail_M = Model();
	Firefly_StarRail_M.LoadModel("Models/Firefly_StarRail/Firefly_StarRail.obj");
	LukeNormal_M = Model();
	LukeNormal_M.LoadModel("Models/LukeNormal-Themis/lukeNormal.obj");

	//Carrusel
	Carrusel_Base_M = Model();
	Carrusel_Base_M.LoadModel("Models/Carrusel/Base.obj");
	Carrusel_M = Model();
	Carrusel_M.LoadModel("Models/Carrusel/Carrusel.obj");
	Lyney_M = Model();
	Lyney_M.LoadModel("Models/Lyney_Genshin/Lyney_Genshin.obj");

	//Baño Puesto Dardos
	Bano_M = Model();
	Bano_M.LoadModel("Models/PuestoBano/puestoBano.obj");
	MariusChino_M = Model();
	MariusChino_M.LoadModel("Models/MariusChino_Themis/mariusChino.obj");

	//Puesto Hot Dogs
	PuestoHotDog_M = Model();
	PuestoHotDog_M.LoadModel("Models/PuestoHotDog/puestoHotDog.obj");
	Jean_Genshin_M = Model();
	Jean_Genshin_M.LoadModel("Models/Jean_Genshin/Jean.obj");
	VynNormal_M = Model();
	VynNormal_M.LoadModel("Models/VynNormal_Themis/vynNormal.obj");

	//Banca Puesto Hot Dogs
	Klee_Genshin_M = Model();
	Klee_Genshin_M.LoadModel("Models/Klee_Genshin/Klee_Genshin.obj");

	//Banca Puesto Palomitas
	Sunday_StarRail_M = Model();
	Sunday_StarRail_M.LoadModel("Models/Sunday_StarRail/Sunday.obj");

	//Artem Normal
	ArtemNormalCuerpo_M = Model();
	ArtemNormalCuerpo_M.LoadModel("Models/ArtemNormal_Themis/artemNormal_Cuerpo.obj");
	ArtemNormalBrazo_M = Model();
	ArtemNormalBrazo_M.LoadModel("Models/ArtemNormal_Themis/artemNormal_Brazo.obj");
	ArtemNormalHoja_M = Model();
	ArtemNormalHoja_M.LoadModel("Models/ArtemNormal_Themis/artemNormal_hoja.obj");

	//Puesto Palomitas
	PuestoPalomitas_M = Model();
	PuestoPalomitas_M.LoadModel("Models/PuestoPalomitas/PuestoPalomitas.obj");
	Feixiao_StarRail_M = Model();
	Feixiao_StarRail_M.LoadModel("Models/Feixiao_StarRail/Feixiao_StarRail.obj");

	//Lanzamiento de Hacha
	LanzamientoHacha_M = Model();
	LanzamientoHacha_M.LoadModel("Models/LanzamientoHacha/LanzamientoHacha.obj");
	Hacha_M = Model();
	Hacha_M.LoadModel("Models/LanzamientoHacha/Hacha.obj");
	Wanderer_Genshin_M = Model();
	Wanderer_Genshin_M.LoadModel("Models/Wanderer_Genshin/Wanderer_Genshin.obj");

	//Puesto Dados
	MesaDados_M = Model();
	MesaDados_M.LoadModel("Models/MesaDados/MesaDados.obj");
	MesaDados_Dados1_M = Model();
	MesaDados_Dados1_M.LoadModel("Models/MesaDados/Dados1.obj");
	MesaDados_Dados2_M = Model();
	MesaDados_Dados2_M.LoadModel("Models/MesaDados/Dados2.obj");
	MesaDados_DadosMesa_M = Model();
	MesaDados_DadosMesa_M.LoadModel("Models/MesaDados/DadosEnMesa.obj");
	Aventurine_StarRail_M = Model();
	Aventurine_StarRail_M.LoadModel("Models/Aventurine_StarRail/Aventurine_StarRail.obj");

	//Puesto Boliche
	Boliche_M = Model();
	Boliche_M.LoadModel("Models/Boliche/Boliche.obj");
	Rendija_Boliche_M = Model();
	Rendija_Boliche_M.LoadModel("Models/Boliche/RendijaBoliche.obj");
	Bolo_M = Model();
	Bolo_M.LoadModel("Models/Boliche/Bolo.obj");
	Bola_Boliche_M = Model();
	Bola_Boliche_M.LoadModel("Models/Boliche/Bola.obj");
	Ayato_Genshin_M = Model();
	Ayato_Genshin_M.LoadModel("Models/Ayato_Genshin/Ayato_Genshin.obj");

	//Puesto Golpear al Topo
	GolpearTopo_M = Model();
	GolpearTopo_M.LoadModel("Models/GolpearAlTopo/GolpearAlTopo.obj");
	GolpearTopo_Topos1_M = Model();
	GolpearTopo_Topos1_M.LoadModel("Models/GolpearAlTopo/GolpearAlTopo_Topos1.obj");
	GolpearTopo_Topos2_M = Model();
	GolpearTopo_Topos2_M.LoadModel("Models/GolpearAlTopo/GolpearAlTopo_Topos2.obj");
	GolpearTopo_MazaHerta_M = Model();
	GolpearTopo_MazaHerta_M.LoadModel("Models/GolpearAlTopo/MazaHertaTopos.obj");
	Yanqing_StarRail_M = Model();
	Yanqing_StarRail_M.LoadModel("Models/Yanqing_StarRail/Yanqing_StarRail.obj");

	//Puesto Algodón Azúcar
	MaquinaAlgodon_M = Model();
	MaquinaAlgodon_M.LoadModel("Models/MaquinaAlgodon/MaquinaAlgodon.obj");
	Robin_StarRail_M = Model();
	Robin_StarRail_M.LoadModel("Models/Robin_StarRail/Robin_StarRail.obj");

	//Puesto Carros Chocones
	CarrosChocones_M = Model();
	CarrosChocones_M.LoadModel("Models/PuestoCarrosChocones/puestoCarrosChocones.obj");
	ArtemCasual_Themis_M = Model();
	ArtemCasual_Themis_M.LoadModel("Models/ArtemCasual_Themis/artemCasual.obj");
	Carro_Azul_M = Model();
	Carro_Azul_M.LoadModel("Models/PuestoCarrosChocones/CarroAzul.obj");
	Carro_Naranja_M = Model();
	Carro_Naranja_M.LoadModel("Models/PuestoCarrosChocones/CarroNaranja.obj");

	//Jaula Bateo
	PuestoBateo_M = Model();
	PuestoBateo_M.LoadModel("Models/PuestoBateo/puestoBateo.obj");
	Bate_M = Model();
	Bate_M.LoadModel("Models/PuestoBateo/bate.obj");
	PelotaBateo_M = Model();
	PelotaBateo_M.LoadModel("Models/PuestoBateo/batePelota.obj");
	LukeCasual_Themis_M = Model();
	LukeCasual_Themis_M.LoadModel("Models/LukeCasual_Themis/LukeCasual.obj");

	//Baño Boliche
	Ratio_StarTail_M = Model();
	Ratio_StarTail_M.LoadModel("Models/Ratio_StarRail/Ratio_StarRail.obj");
	
	//Puesto de Tickets
	PuestoTickets_M = Model();
	PuestoTickets_M.LoadModel("Models/PuestoTickets/PuestoTickets.obj");
	PomPom_M = Model();
	PomPom_M.LoadModel("Models/PomPom_StarRail/PomPom_StarRail.obj");

	//Banca Boliche
	Banca_Genshin_M = Model();
	Banca_Genshin_M.LoadModel("Models/BancaTexturizada/BancaTexturizada.obj");
	VynChino_Themis_M = Model();
	VynChino_Themis_M.LoadModel("Models/VynChino_Genshin/vynChino.obj");

	//Puesto Tacos
	PuestoTacos_M = Model();
	PuestoTacos_M.LoadModel("Models/PuestoTacos/puestoTacos.obj");
	Herta_StarTail_M = Model();
	Herta_StarTail_M.LoadModel("Models/Herta_StarRail/herta.obj");
	Xiao_Genshin_M = Model();
	Xiao_Genshin_M.LoadModel("Models/Xiao_Genshin/xiao2.obj");

	//Decoraciones
	Lampara_Genshin_M = Model();
	Lampara_Genshin_M.LoadModel("Models/LamparaGenshin/LamparaGenshin.obj");
	Bote_StarRail_M = Model();
	Bote_StarRail_M.LoadModel("Models/Bote/Bote.obj");

	//Plataforma Dodoco
	Plataforma_Genshin_M = Model();
	Plataforma_Genshin_M.LoadModel("Models/MesaComida/Plataforma.obj");

	//Mesa con comida Genshin
	MesaComida = Model();
	MesaComida.LoadModel("Models/MesaComida/MesaComidas1.obj");
	LecheDango = Model();
	LecheDango.LoadModel("Models/MesaComida/lechedango.obj");

	//Stands de madera de Tears of Themis
	Stand_Dardos_M = Model();
	Stand_Dardos_M.LoadModel("Models/StandMadera/standMadera_ArtemDardos.obj");
	Stand_HotDog_M = Model();
	Stand_HotDog_M.LoadModel("Models/StandMadera/standMadera_ArtemHotDog.obj");
	Stand_Taquilla_M = Model();
	Stand_Taquilla_M.LoadModel("Models/StandMadera/standMadera_CarnivalThemis.obj");
	Stand_Carrusel_M = Model();
	Stand_Carrusel_M.LoadModel("Models/StandMadera/standMadera_Carrucel.obj");
	Stand_Carros_M = Model();
	Stand_Carros_M.LoadModel("Models/StandMadera/standMadera_VynCarrosChocones.obj");
	Stand_Comida_M = Model();
	Stand_Comida_M.LoadModel("Models/StandMadera/standMadera_LukeComida.obj");
	Stand_Dados_M = Model();
	Stand_Dados_M.LoadModel("Models/StandMadera/standMadera_MariusCasino.obj");
	Stand_Topos_M = Model();
	Stand_Topos_M.LoadModel("Models/StandMadera/standMadera_VynTopos.obj");

	//Puesto Inazuma
	PuestoInazuma_M = Model();
	PuestoInazuma_M.LoadModel("Models/PuestoInazuma/puestoInazumaPulpo.obj");
	Ixbalanque_M = Model();
	Ixbalanque_M.LoadModel("Models/Ixbalanque_Genshin/Ixbalanque_Genshin.obj");
	
	//Globos Genshin
	Globo_Enojado_M = Model();
	Globo_Enojado_M.LoadModel("Models/Globo/globoEnojado.obj");
	Globo_Feliz_M = Model();
	Globo_Feliz_M.LoadModel("Models/Globo/globoFeliz.obj");
	Globo_Verde_M = Model();
	Globo_Verde_M.LoadModel("Models/Globo/globoVerde.obj");
	Globo_Naranja_M = Model();
	Globo_Naranja_M.LoadModel("Models/Globo/globoNaranja.obj");

	//Gatos Star Rail
	Gato_Basura_M = Model();
	Gato_Basura_M.LoadModel("Models/Gato_StarRail/Gato_StarRail_Basura.obj");
	Gato_Blade_M = Model();
	Gato_Blade_M.LoadModel("Models/Gato_StarRail/Gato_StarRail_Blade.obj");
	Gato_Clara_M = Model();
	Gato_Clara_M.LoadModel("Models/Gato_StarRail/Gato_StarRail_Clara.obj");
	Gato_DanHeng_M = Model();
	Gato_DanHeng_M.LoadModel("Models/Gato_StarRail/Gato_StarRail_DanHeng.obj");
	Gato_Kafka_M = Model();
	Gato_Kafka_M.LoadModel("Models/Gato_StarRail/Gato_StarRail_Kafka.obj");
	Gato_March_M = Model();
	Gato_March_M.LoadModel("Models/Gato_StarRail/Gato_StarRail_March.obj");
	Gato_Naranja_M = Model();
	Gato_Naranja_M.LoadModel("Models/Gato_StarRail/Gato_StarRail_Naranja.obj");
	Gato_RuanMei_M = Model();
	Gato_RuanMei_M.LoadModel("Models/Gato_StarRail/Gato_StarRail_RuanMei.obj");
	Gato_Herta_M = Model();
	Gato_Herta_M.LoadModel("Models/Gato_StarRail/Gato_StarRail_Herta.obj");
	Gato_Verde_M = Model();
	Gato_Verde_M.LoadModel("Models/Gato_StarRail/Gato_StarRail_Verde.obj");

	//Blade Star Rail
	Blade_Cuerpo = Model();
	Blade_Cuerpo.LoadModel("Models/Blade_StarRail/BladeCuerpo_StarRail.obj");

	Blade_Cabeza = Model();
	Blade_Cabeza.LoadModel("Models/Blade_StarRail/Blade_Cabeza.obj");

	Blade_HombroDer = Model();
	Blade_HombroDer.LoadModel("Models/Blade_StarRail/Blade_HombroDer.obj");
	Blade_AntebrazoDer = Model();
	Blade_AntebrazoDer.LoadModel("Models/Blade_StarRail/Blade_AntebrazoDer.obj");
	Blade_ManoDer = Model();
	Blade_ManoDer.LoadModel("Models/Blade_StarRail/Blade_ManoDer.obj");

	Blade_HombroIzq = Model();
	Blade_HombroIzq.LoadModel("Models/Blade_StarRail/Blade_HombroIzq.obj");
	Blade_AntebrazoIzq = Model();
	Blade_AntebrazoIzq.LoadModel("Models/Blade_StarRail/Blade_AntebrazoIzq.obj");
	Blade_ManoIzq = Model();
	Blade_ManoIzq.LoadModel("Models/Blade_StarRail/Blade_ManoIzq.obj");

	Blade_PiernaDer = Model();
	Blade_PiernaDer.LoadModel("Models/Blade_StarRail/Blade_PiernaDer.obj");
	Blade_PantorrillaDer = Model();
	Blade_PantorrillaDer.LoadModel("Models/Blade_StarRail/Blade_PantorrillaDer.obj");
	Blade_PieDer = Model();
	Blade_PieDer.LoadModel("Models/Blade_StarRail/Blade_PieDer.obj");

	Blade_PiernaIzq = Model();
	Blade_PiernaIzq.LoadModel("Models/Blade_StarRail/Blade_PiernaIzq.obj");
	Blade_PantorrillaIzq = Model();
	Blade_PantorrillaIzq.LoadModel("Models/Blade_StarRail/Blade_PantorrillaIzq.obj");
	Blade_PieIzq = Model();
	Blade_PieIzq.LoadModel("Models/Blade_StarRail/Blade_PieIzq.obj");

	BrazoDerecho = Model();
	BrazoDerecho.LoadModel("Models/Blade_StarRail/BrazoDerecho.obj");
	BrazoDerecho_Sur = Model();
	BrazoDerecho_Sur.LoadModel("Models/Blade_StarRail/BrazoDerecho_Sur.obj");
	BrazoDerecho_Derecha = Model();
	BrazoDerecho_Derecha.LoadModel("Models/Blade_StarRail/BrazoDerecho_Derecha.obj");
	BrazoDerecho_Izquierda = Model();
	BrazoDerecho_Izquierda.LoadModel("Models/Blade_StarRail/BrazoDerecho_Izquierda.obj");

	//Bote Caminante
	Bote_Cuerpo = Model();
	Bote_Cuerpo.LoadModel("Models/Bote2/Bote_Cuerpo.obj");

	Bote_HombroIzq = Model();
	Bote_HombroIzq.LoadModel("Models/Bote2/Bote_HombroIzq.obj");
	Bote_AntebrazoIzq = Model();
	Bote_AntebrazoIzq.LoadModel("Models/Bote2/Bote_AntebrazoIzq.obj");

	Bote_PiernaDer = Model();
	Bote_PiernaDer.LoadModel("Models/Bote2/Bote_PiernaDer.obj");
	Bote_PantorrillaDer = Model();
	Bote_PantorrillaDer.LoadModel("Models/Bote2/Bote_PantorrillaDer.obj");

	Bote_PiernaIzq = Model();
	Bote_PiernaIzq.LoadModel("Models/Bote2/Bote_PiernaIzq.obj");
	Bote_PantorrillaIzq = Model();
	Bote_PantorrillaIzq.LoadModel("Models/Bote2/Bote_PantorrillaIzq.obj");

	//Monedas Juegos
	Tear_Themis = Model();
	Tear_Themis.LoadModel("Models/TearMoneda_Themis/tears.obj");
	Destino_Genshin = Model();
	Destino_Genshin.LoadModel("Models/DestinoEntrelazado_Genshin/DestinoEntrelazado_Genshin.obj");
	Ticket_StarRail = Model();
	Ticket_StarRail.LoadModel("Models/Ticket/Ticket.obj");

	// --------------------------------------
	// -----------SKYBOX TEXTURAS------------
	// --------------------------------------

	std::vector<std::string> skyboxFaces; //Se crea un vector con las texturas que componen al skybox de día
	//Todo esto para que dentro del while se vayan cambiando con los skybox ya existentes creados aquí
	skyboxFaces.push_back("Textures/Skybox/Nubes_Derecha.tga");
	skyboxFaces.push_back("Textures/Skybox/Nubes_Izq.tga");
	skyboxFaces.push_back("Textures/Skybox/Nubes_Abajo.tga");
	skyboxFaces.push_back("Textures/Skybox/Nubes_Arriba.tga");
	skyboxFaces.push_back("Textures/Skybox/Nubes_Detras.tga");
	skyboxFaces.push_back("Textures/Skybox/Nubes_Enfrente.tga");

	std::vector<std::string> skyboxFacesAtard; //Se crea un vector con las texturas que componen al skybox de atardecer
	skyboxFacesAtard.push_back("Textures/Skybox/Atardecer_Derecha.tga");
	skyboxFacesAtard.push_back("Textures/Skybox/Atardecer_Izq.tga");
	skyboxFacesAtard.push_back("Textures/Skybox/Atardecer_Abajo.tga");
	skyboxFacesAtard.push_back("Textures/Skybox/Atardecer_Arriba.tga");
	skyboxFacesAtard.push_back("Textures/Skybox/Atardecer_Detras.tga");
	skyboxFacesAtard.push_back("Textures/Skybox/Atardecer_Enfrente.tga");

	std::vector<std::string> skyboxFacesNoche; //Se crea un vector con las texturas que componen al skybox de noche
	skyboxFacesNoche.push_back("Textures/Skybox/Night_Derecha.tga");
	skyboxFacesNoche.push_back("Textures/Skybox/Night_Izq.tga");
	skyboxFacesNoche.push_back("Textures/Skybox/Night_Abajo.tga ");
	skyboxFacesNoche.push_back("Textures/Skybox/Night_Arriba.tga");
	skyboxFacesNoche.push_back("Textures/Skybox/Night_Detras.tga");
	skyboxFacesNoche.push_back("Textures/Skybox/Night_Enfrente.tga");
	
	// --------------------------------------
	// -----------CREAR MATERIALES-----------
	// --------------------------------------

	Material_brillante = Material(4.0f, 256);
	Material_opaco = Material(0.3f, 4);

	Material_Avatar = Material(0.1f, 10);
	Material_Madera = Material(0.4f, 10);
	Material_Reja = Material(0.8f, 50);
	Material_Terciopelo = Material(0.1f, 5);
	Material_MaderaPulida = Material(0.7f, 50);
	Material_Plastico = Material(0.8f, 30);

	// --------------------------------------
	// -----------ESTABLECER LUCES-----------
	// --------------------------------------

	//Luz direccional, sólo 1 y siempre debe de existir
	mainLight = DirectionalLight(0.9843f, 0.9843f, 0.8980f,	//RGB
		0.45f, 0.6f,				//Intensidad
		0.0f, 0.0f, 1.0f);			//Dirección

	//Contador de luces
	unsigned int pointLightDiaCount = 0;
	unsigned int spotLightDiaCount = 0;

	unsigned int pointLightNocheCount = 0;
	unsigned int spotLightNocheCount = 0;
	
	// --------------------------------------
	// ---------------LUCES DÍA--------------
	// --------------------------------------

	// ---POINT LIGHTS---

	//Luz Rueda Fortuna
	pointLightsDia[0] = PointLight(0.9843f, 0.0862f, 0.8705f, //RGB
		1.0f, 1.5f,
		0.0f, 67.0f, 0.0f, //Posición de la luz
		0.05f, 0.1f, 0.0f);
	pointLightDiaCount++;

	//Luz Hot Dogs
	pointLightsDia[1] = PointLight(0.9607f, 0.4352f, 0.3137f, //RGB
		0.7f, 0.6f,
		82.0f, 9.6f, -119.5f, //Posición de la luz
		0.0f, 0.0f, 0.05f);
	pointLightDiaCount++;

	//Luz Puesto Inazuma
	pointLightsDia[2] = PointLight(0.7294f, 0.4352f, 1.0f, //RGB
		0.4f, 0.1f,
		-60.0f, 8.0f, 19.5f, //Posición de la luz
		0.0f, 0.1f, 0.0f);
	pointLightDiaCount++;

	// ---SPOT LIGHTS---

	//Luz Carrusel
	spotLightsDia[0] = SpotLight(1.0f, 0.0f, 0.0f, //RGB
		1.0f, 2.0f,
		43.0f, 25.0f, -65.0f, //Posición (de dónde sale la luz)
		0.0f, -1.0f, 0.0f, //Dirección (hacia dónde apunta)
		0.0f, 0.1f, 0.0f,
		60.0f);
	spotLightDiaCount++;

	//Luz Carros Chocones
	spotLightsDia[1] = SpotLight(0.6156f, 0.5803f, 0.9921f, //RGB
		1.0f, 1.0f,
		0.0f, 25.0f, -145.0f, //Posición (de dónde sale la luz)
		0.0f, -1.0f, 0.0f, //Dirección (hacia dónde apunta)
		0.0f, 0.05f, 0.0f,
		25.0f);
	spotLightDiaCount++;

	//Luz Puesto de Tickets
	spotLightsDia[2] = SpotLight(0.9607f, 0.1294f, 0.0784f, //RGB
		1.0f, 1.0f,
		73.0f, 10.0f, -114.0f, //Posición (de dónde sale la luz)
		0.0f, -1.0f, 0.0f, //Dirección (hacia dónde apunta)
		0.0f, 0.04f, 0.0f,
		20.0f);
	spotLightDiaCount++;

	// --------------------------------------
	// -------------LUCES NOCHE--------------
	// --------------------------------------

	// ---POINT LIGHTS---

	pointLightsNoche[0] = pointLightsDia[0];	//Rueda Fortuna
	pointLightNocheCount++;

	//Luz Lámpara Izquierda
	pointLightsNoche[1] = PointLight(0.9607f, 0.4352f, 0.3137f, //RGB
		0.5f, 0.5f,
		-108.0f, 17.0f, -107.0f, //Posición de la luz
		0.0f, 0.1f, 0.0f);
	pointLightNocheCount++;

	//Luz Lámpara Centro
	pointLightsNoche[2] = PointLight(0.9607f, 0.4352f, 0.3137f, //RGB
		0.4f, 0.5f,
		-33.0f, 17.0f, 77.0f, //Posición de la luz
		0.0f, 0.1f, 0.0f);
	pointLightNocheCount++;

    pointLightsNoche[3] = pointLightsDia[2];	//Puesto Inazuma
	pointLightNocheCount++;


	// ---SPOT LIGHTS---

	//Luz Tacos
	spotLightsNoche[0] = SpotLight(0.9607f, 0.4352f, 0.3137f, //RGB
		0.5f, 0.5f,
		-118.0f, 12.0f, 8.5f, //Posición (de dónde sale la luz)
		0.0f, -1.0f, 0.0f, //Dirección (hacia dónde apunta)
		0.0f, 0.04f, 0.0f,
		60.0f);
	spotLightNocheCount++;

	spotLightsNoche[1] = spotLightsDia[0];		//Carrusel
	spotLightNocheCount++;

	spotLightsNoche[2] = spotLightsDia[2];		//Puesto de Tickets
	spotLightNocheCount++;

	// --------------------------------------
	// -------------LUCES HACHA--------------
	// --------------------------------------

	// ---SPOT LIGHTS---

					//Dia///

	spotLightsDiaHacha[0] = spotLightsDia[0]; // Carrusel

	spotLightsDiaHacha[1] = spotLightsDia[2]; // Puesto de Tickets

	//Luz Hacha
	spotLightsDiaHacha[2] = SpotLight(1.0f, 1.0f, 1.0f, //RGB
		0.3f, 0.4f,
		-125.0f, 12.5f, -78.0f, //Posición (de dónde sale la luz)
		0.0f, -1.0f, 0.0f, //Dirección (hacia dónde apunta)
		0.0f, 0.04f, 0.0f,
		20.0f);
	
					//Noche///
	
	spotLightsNocheHacha[0] = spotLightsNoche[0]; //Tacos

	spotLightsNocheHacha[1] = spotLightsDia[0];  //Carrusel

	spotLightsNocheHacha[2] = spotLightsDiaHacha[2];  //Hacha

	// ----------------------------------------
	// -------------LUCES BOLICHE--------------
	// ----------------------------------------

	// ---SPOT LIGHTS---

					//Dia///

	spotLightsDiaBoliche[0] = spotLightsDia[0]; // Carrusel

	spotLightsDiaBoliche[1] = spotLightsDia[2]; // Puesto de Tickets

	//Luz Boliche
	spotLightsDiaBoliche[2] = SpotLight(1.0f, 1.0f, 1.0f, //RGB
		0.3f, 0.4f,
		-54.0f, 15.0f, 110.0f, //Posición (de dónde sale la luz)
		0.0f, -1.0f, 0.0f, //Dirección (hacia dónde apunta)
		0.0f, 0.04f, 0.0f,
		20.0f);

					//Noche///

	spotLightsNocheBoliche[0] = spotLightsNoche[0]; //Tacos

	spotLightsNocheBoliche[1] = spotLightsDia[0];  //Carrusel

	spotLightsNocheBoliche[2] = spotLightsDiaBoliche[2];  //Boliche

	// --------------------------------------
	// -------------LUCES DADOS--------------
	// --------------------------------------

	// ---SPOT LIGHTS---

					//Dia///

	spotLightsDiaDados[0] = spotLightsDia[0]; // Carrusel

	spotLightsDiaDados[1] = spotLightsDia[2]; // Puesto de Tickets

	//Luz Dados
	spotLightsDiaDados[2] = SpotLight(1.0f, 1.0f, 1.0f, //RGB
		0.4f, 0.3f,
		-110.0f, 13.0f, -35.0f, //Posición (de dónde sale la luz)
		0.0f, -1.0f, 0.0f, //Dirección (hacia dónde apunta)
		0.0f, 0.05f, 0.0f,
		30.0f);

					//Noche///

	spotLightsNocheDados[0] = spotLightsNoche[0]; //Tacos

	spotLightsNocheDados[1] = spotLightsDia[0];  //Carrusel

	spotLightsNocheDados[2] = spotLightsDiaDados[2];  //Dados

	// --------------------------------------
	// -------------LUCES BATEO--------------
	// --------------------------------------

	// ---SPOT LIGHTS---

					//Dia///

	spotLightsDiaBateo[0] = spotLightsDia[0]; // Carrusel

	spotLightsDiaBateo[1] = spotLightsDia[2]; // Puesto de Tickets

	//Luz Bateo
	spotLightsDiaBateo[2] = SpotLight(1.0f, 1.0f, 1.0f, //RGB
		0.4f, 0.3f,
		-6.0f, 13.0f, 112.0f, //Posición (de dónde sale la luz)
		0.0f, -1.0f, 0.0f, //Dirección (hacia dónde apunta)
		0.0f, 0.04f, 0.0f,
		30.0f);

					//Noche///

	spotLightsNocheBateo[0] = spotLightsNoche[0]; //Tacos

	spotLightsNocheBateo[1] = spotLightsDia[0];  //Carrusel

	spotLightsNocheBateo[2] = spotLightsDiaBateo[2];  //Bateo

	// ---------------------------------------
	// -------------LUCES DARDOS--------------
	// ---------------------------------------

	// ---SPOT LIGHTS---

					//Dia///

	spotLightsDiaDardos[0] = spotLightsDia[0]; // Carrusel

	spotLightsDiaDardos[1] = spotLightsDia[2]; // Puesto de Tickets

	//Luz Dardos
	spotLightsDiaDardos[2] = SpotLight(1.0f, 1.0f, 1.0f, //RGB
		0.3f, 0.4f,
		112.0f, 16.0f, -25.0f, //Posición (de dónde sale la luz)
		0.0f, -1.0f, 0.0f, //Dirección (hacia dónde apunta)
		0.0f, 0.04f, 0.0f,
		20.0f);

					//Noche///

	spotLightsNocheDardos[0] = spotLightsNoche[0]; //Tacos

	spotLightsNocheDardos[1] = spotLightsDia[0];  //Carrusel

	spotLightsNocheDardos[2] = spotLightsDiaDardos[2];  //Dardos

	// ---------------------------------------
	// --------------LUCES TOPOS--------------
	// ---------------------------------------

	// ---SPOT LIGHTS---

					//Dia///

	spotLightsDiaTopos[0] = spotLightsDia[0]; // Carrusel

	spotLightsDiaTopos[1] = spotLightsDia[2]; // Puesto de Tickets

	//Luz Topo
	spotLightsDiaTopos[2] = SpotLight(1.0f, 1.0f, 1.0f, //RGB
		0.3f, 0.4f,
		61.0f, 13.0f, 69.0f, //Posición (de dónde sale la luz)
		0.0f, -1.0f, 0.0f, //Dirección (hacia dónde apunta)
		0.0f, 0.065f, 0.0f,
		15.0f);

	//Noche///

	spotLightsNocheTopos[0] = spotLightsDia[2]; //Puesto de Tickets

	spotLightsNocheTopos[1] = spotLightsDia[0];  //Carrusel

	spotLightsNocheTopos[2] = spotLightsDiaTopos[2];  //Topo
	
	// ----------------------------------------
	// -----------LUCES DÍA TECLADO------------
	// ----------------------------------------

	//Agregar el segundo arreglo de día (interacción con teclado Puesto Inazuma y Hot Dogs)
	pointLightsDia2[0] = pointLightsDia[0];
	pointLightsDia2[1] = pointLightsDia[2];
	pointLightsDia2[2] = pointLightsDia[1];


	// ---------------------------------------
	// -------VAR. UNIFORM Y PROYECCIÓN-------
	// ---------------------------------------

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0,
		uniformSpecularIntensity = 0, uniformShininess = 0;
	GLuint uniformColor = 0;

	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 1000.0f);

	glm::vec3 bladePosition = glm::vec3(83.0f, 6.463f, 130.0f);

	// --------------------------------------
	// ------------WHILE PRINCIPAL-----------
	// --------------------------------------

	////Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;

		// --------------------------------------
		// ----------------SKYBOX----------------
		// --------------------------------------

		if (skyCount == 0) { //Amanecer
			skybox = Skybox(skyboxFaces);  //Skybox de dia

			//Recibe Color nuevo RGC, dirección nueva, ambientIntensity, diffuseIntensity
			mainLight.SetLight(glm::vec3(0.9843f, 0.9843f, 0.8980f), glm::vec3(0.0f, 0.0f, 1.0f), 0.5f, 0.6f);
		}
		else if (skyCount == 1000) {//Medio día

			//Recibe Color nuevo RGC, dirección nueva, ambientIntensity, diffuseIntensity
			mainLight.SetLight(glm::vec3(1.0f, 0.9647f, 0.9333f), glm::vec3(0.0f, -1.0f, 0.0f), 0.43f, 0.37f);
		}

		else if (skyCount == 2000) {//Atardecer
			skybox = Skybox(skyboxFacesAtard);  //Skybox de atardecer

			//Recibe Color nuevo RGC, dirección nueva, ambientIntensity, diffuseIntensity
			mainLight.SetLight(glm::vec3(0.9450f, 0.6274f, 0.4745f), glm::vec3(0.0f, 0.0f, -1.0f), 0.45f, 0.6f);
		}
		else if (skyCount == 3000) { //Noche
			skybox = Skybox(skyboxFacesNoche);  //Skybox de noche

			//Recibe Color nuevo RGC, dirección nueva, ambientIntensity, diffuseIntensity
			mainLight.SetLight(glm::vec3(0.9176f, 0.9411f, 0.9686f), glm::vec3(0.0f, 0.0f, 1.0f), 0.5f, 0.4f);
		}
		else if (skyCount == 6000) { //Termina la noche
			skyCount = -1; //Se le resta uno porque abajo se suma 1 y al sumarse 1 ya no queda en e para el reinicio
		}

		skyCount += 1; //La variable contadora aumenta en uno con cada ciclo del while que es lo que lleva la cuenta del tiempo

		// --------------------------------------
		// ---------------CÁMARAS----------------
		// --------------------------------------

		if (banderaCamara == 0) {

			if (mainWindow.getarticulacion1() == 1.0) { //Vista Blade
				banderaCamaraMovimiento = 0;
			}
			else if (mainWindow.getarticulacion2() == 1.0) { //Vista aerea
				camera3 = camera2;
				banderaCamaraMovimiento = 1;
			}
			else if (mainWindow.getarticulacion3() == 1.0) { //Stand hacha
				camera3 = Camera(glm::vec3(-106.0f, 8.0f, -78.0f), glm::vec3(0.0f, 1.0f, 0.0f), 180.0f, 0.0f, 0.3f, 0.5f);
				banderaCamaraMovimiento = 1;
				camaraAnimacion = 1;
			}
			else if (mainWindow.getarticulacion4() == 1.0) { //Stand boliche
				camera3 = Camera(glm::vec3(-52.0f, 11.0f, 62.0f), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f, -15.0f, 0.3f, 0.5f);
				banderaCamaraMovimiento = 1;
				camaraAnimacion = 2;
			}
			else if (mainWindow.getarticulacion5() == 1.0) { //Stand dados
				camera3 = Camera(glm::vec3(-102.0f, 9.0f, -35.0f), glm::vec3(0.0f, 1.0f, 0.0f), 180.0f, -30.0f, 0.3f, 0.5f);
				banderaCamaraMovimiento = 1;
				camaraAnimacion = 3;
			}
			else if (mainWindow.getarticulacion6() == 1.0) { //Stand bateo
				camera3 = Camera(glm::vec3(-03.0f, 9.0f, 93.0f), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f, 0.0f, 0.3f, 0.5f);
				banderaCamaraMovimiento = 1;
				camaraAnimacion = 4;
			}
			else if (mainWindow.getarticulacion7() == 1.0) { //Stand dardos
				camera3 = Camera(glm::vec3(91.5f, 8.5f, -26.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, -5.0f, 0.3f, 0.5f);
				banderaCamaraMovimiento = 1;
				camaraAnimacion = 5;
			}
			else if (mainWindow.getarticulacion8() == 1.0) { //Stand topo
				camera3 = Camera(glm::vec3(61.0f, 9.0f, 62.5f), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f, -30.0f, 0.3f, 0.5f);
				banderaCamaraMovimiento = 1;
				camaraAnimacion = 6;
			}
			else if (mainWindow.getarticulacion11() == 1.0) { //Camara Libre (EXTRA)
				banderaCamaraMovimiento = 2;
			}
		}

		//Para  clear Window según se ocupe o no que se pueda mover la cámara
		if (banderaCamaraMovimiento == 0) {
			//CAMARA 1 (VISTA BLADE CON MOVIMIENTO)
			glfwPollEvents();
			//camera.keyControl(mainWindow.getsKeys(), deltaTime);
			camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

			// Clear the window
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			skybox.DrawSkybox(camera.calculateViewMatrix(), projection);
			shaderList[0].UseShader();
			uniformModel = shaderList[0].GetModelLocation();
			uniformProjection = shaderList[0].GetProjectionLocation();
			uniformView = shaderList[0].GetViewLocation();
			uniformEyePosition = shaderList[0].GetEyePositionLocation();
			uniformColor = shaderList[0].getColorLocation();

			//información en el shader de intensidad especular y brillo
			uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
			uniformShininess = shaderList[0].GetShininessLocation();

			glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
			glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
			glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);
		}
		else if (banderaCamaraMovimiento == 2) {
			//CAMARA LIBRE (VISTA EXTRA CON MOVIMIENTO )
			glfwPollEvents();
			cameraLibre.keyControl(mainWindow.getsKeys(), deltaTime);
			cameraLibre.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

			// Clear the window
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			skybox.DrawSkybox(cameraLibre.calculateViewMatrix(), projection);
			shaderList[0].UseShader();
			uniformModel = shaderList[0].GetModelLocation();
			uniformProjection = shaderList[0].GetProjectionLocation();
			uniformView = shaderList[0].GetViewLocation();
			uniformEyePosition = shaderList[0].GetEyePositionLocation();
			uniformColor = shaderList[0].getColorLocation();

			//información en el shader de intensidad especular y brillo
			uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
			uniformShininess = shaderList[0].GetShininessLocation();

			glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
			glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(cameraLibre.calculateViewMatrix()));
			glUniform3f(uniformEyePosition, cameraLibre.getCameraPosition().x, cameraLibre.getCameraPosition().y, cameraLibre.getCameraPosition().z);
		}
		else {
			//CAMARA 2 Y 3 (VISTA AEREA Y CADA STAND. SIN MOVIMIENTO)
			glfwPollEvents();

			// Clear the window
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			skybox.DrawSkybox(camera3.calculateViewMatrix(), projection);
			shaderList[0].UseShader();
			uniformModel = shaderList[0].GetModelLocation();
			uniformProjection = shaderList[0].GetProjectionLocation();
			uniformView = shaderList[0].GetViewLocation();
			uniformEyePosition = shaderList[0].GetEyePositionLocation();
			uniformColor = shaderList[0].getColorLocation();

			//información en el shader de intensidad especular y brillo
			uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
			uniformShininess = shaderList[0].GetShininessLocation();

			glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
			glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera3.calculateViewMatrix()));
			glUniform3f(uniformEyePosition, camera3.getCameraPosition().x, camera3.getCameraPosition().y, camera3.getCameraPosition().z);
		}


		// --------------------------------------
		// ----------------LUCES-----------------
		// --------------------------------------

		//Rueda Fortuna
		if (luzContador == 0) {
			//Color, posición, constante, lineal, exponencial (Rosa)
			pointLightsDia[0].SetLight(glm::vec3(0.9843f, 0.0862f, 0.8705f), glm::vec3(0.0f, 67.0f, 0.0f));
		}
		else if (luzContador == 150) {
			//Color, posición, constante, lineal, exponencial (Azul)
			pointLightsDia[0].SetLight(glm::vec3(0.1529f, 0.8862f, 1.0f), glm::vec3(0.0f, 67.0f, 0.0f));
		}
		else if (luzContador == 300) {
			//Color, posición, constante, lineal, exponencial (Morado)
			pointLightsDia[0].SetLight(glm::vec3(0.7333f, 0.2156f, 0.9764f), glm::vec3(0.0f, 67.0f, 0.0f));
		}
		else if (luzContador == 450) {
			//Color, posición, constante, lineal, exponencial (Amarillo)
			pointLightsDia[0].SetLight(glm::vec3(0.9764f, 0.9725f, 0.2156f), glm::vec3(0.0f, 67.0f, 0.0f));
		}
		else if (luzContador == 600) {
			luzContador = -1;
		}
		luzContador += 1;


		//Carrusel
		if (luzContador2 == 0) {
			//Color nuevo (Rojo)
			spotLightsDia[0].SetColor(glm::vec3(1.0f, 0.0f, 0.0f));
		}
		else if (luzContador2 == 50) {
			//Color nuevo (Amarillo)
			spotLightsDia[0].SetColor(glm::vec3(0.9921f, 0.9921f, 0.5333f));
		}
		else if (luzContador2 == 100) {
			luzContador2 = -1;
		}
		luzContador2 += 1;


		//Carritos chocones
		if (banderaLuz == 0 && luzContador3 < 20.0f) {
			//Recibe nueva posición
			spotLightsDia[1].SetPos(glm::vec3(0.0f + luzContador3, 25.0f, -145.0f - luzContador3));
			luzContador3 += 0.1;
			luzContador4 += 0.1;
		}
		else if (banderaLuz == 0 && luzContador4 >= -20.0f) {
			//Recibe nueva posición
			spotLightsDia[1].SetPos(glm::vec3(0.0f + luzContador4, 25.0f, -145.0f - luzContador3));
			luzContador4 -= 0.1;
		}
		else if (banderaLuz == 1 && luzContador3 <= 0.0f) {
			banderaLuz = 0;
		}
		else {
			//Recibe nueva posición
			spotLightsDia[1].SetPos(glm::vec3(0.0f + luzContador4, 25.0f, -145.0f - luzContador3));
			luzContador3 -= 0.1;
			luzContador4 += 0.1;
			banderaLuz = 1;
		}


		//Puesto de Tickets
		if (banderaLuz1 == 0 && luzContador5 < 10.0f) {
			//Recibe nueva posición
			spotLightsDia[2].SetPos(glm::vec3(73.0f + luzContador5, 20.0f, 114.0f));
			luzContador5 += 0.1;
		}
		else if (luzContador5 > -10.0f) {
			//Recibe nueva posición
			spotLightsDia[2].SetPos(glm::vec3(73.0f + luzContador5, 20.0f, 114.0f));
			luzContador5 -= 0.1;
			banderaLuz1 = 1;
		}
		else {
			banderaLuz1 = 0;
		}


		//Lámpara (Parpadea)
		if (banderaLuz2 == 0 && luzContador6 < 0.5f) {
			//Recibe nueva posición
			pointLightsNoche[1].SetIntensity(0.5f - luzContador6, 0.5f - luzContador6);
			luzContador6 += 0.09;
		}
		else if (luzContador6 > -0.5f) {
			//Recibe nueva posición
			pointLightsNoche[1].SetIntensity(0.5f - luzContador6, 0.5f - luzContador6);
			luzContador6 -= 0.09;
			banderaLuz2 = 1;
		}
		else {
			banderaLuz2 = 0;
		}

		//Luz Topos Animación
		if (camaraAnimacion == 6) {
			if (contadorTopos < 50) {
				spotLightsDiaTopos[2].SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
				spotLightsNocheTopos[2] = spotLightsDiaTopos[2];  //Topo
				contadorTopos++;
			}
			else if (contadorTopos < 100) {
				spotLightsDiaTopos[2].SetColor(glm::vec3(0.4784f, 0.4078f, 1.0f));
				spotLightsNocheTopos[2] = spotLightsDiaTopos[2];  //Topo
				contadorTopos++;
			}
			else contadorTopos = 0;
		}

		//Luz Topos Animación
		if (camaraAnimacion == 4) {
			if (contadorBate < 50) {
				spotLightsDiaBateo[2].SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
				spotLightsNocheBateo[2] = spotLightsDiaBateo[2];  //Bate
				contadorBate++;
			}
			else if (contadorBate < 100) {
				spotLightsDiaBateo[2].SetColor(glm::vec3(0.4784f, 0.4078f, 1.0f));
				spotLightsNocheBateo[2] = spotLightsDiaBateo[2];  //Bate
				contadorBate++;
			}
			else contadorBate = 0;
		}

		

		//Actualizar el segundo arreglo de día (para encender y apagar Inazuma y Hot Dogs)
		pointLightsDia2[0] = pointLightsDia[0];
		pointLightsDia2[1] = pointLightsDia[2];
		pointLightsDia2[2] = pointLightsDia[1];

		//Actualizar los arreglos de noche
		pointLightsNoche[0] = pointLightsDia[0];	//Rueda Fortuna
		pointLightsNoche[3] = pointLightsDia[2];	//Puesto Inazuma

		spotLightsNoche[1] = spotLightsDia[0];		//Carrusel
		spotLightsNoche[2] = spotLightsDia[2];		//Puesto de Tickets

		//Actualizar los arreglos de Hacha
		spotLightsDiaHacha[0] = spotLightsDia[0];	// Carrusel
		spotLightsDiaHacha[1] = spotLightsDia[2];	// Puesto de Tickets
		spotLightsNocheHacha[1] = spotLightsDia[0];  //Carrusel Noche

		//Actualizar los arreglos de Boliche
		spotLightsDiaBoliche[0] = spotLightsDia[0]; // Carrusel
		spotLightsDiaBoliche[1] = spotLightsDia[2]; // Puesto de Tickets
		spotLightsNocheBoliche[1] = spotLightsDia[0];  //Carrusel Noche

		//Actualizar los arreglos de Dados
		spotLightsDiaDados[0] = spotLightsDia[0]; // Carrusel
		spotLightsDiaDados[1] = spotLightsDia[2]; // Puesto de Tickets
		spotLightsNocheDados[1] = spotLightsDia[0];  //Carrusel Noche

		//Actualizar los arreglos de Bateo
		spotLightsDiaBateo[0] = spotLightsDia[0]; // Carrusel
		spotLightsDiaBateo[1] = spotLightsDia[2]; // Puesto de Tickets
		spotLightsNocheBateo[1] = spotLightsDia[0];  //Carrusel Noche

		//Actualizar los arreglos de Dardos
		spotLightsDiaDardos[0] = spotLightsDia[0]; // Carrusel
		spotLightsDiaDardos[1] = spotLightsDia[2]; // Puesto de Tickets
		spotLightsNocheDardos[1] = spotLightsDia[0];  //Carrusel Noche

		//Actualizar los arreglos de Topos
		spotLightsDiaTopos[0] = spotLightsDia[0]; // Carrusel
		spotLightsDiaTopos[1] = spotLightsDia[2]; // Puesto de Tickets
		spotLightsNocheTopos[0] = spotLightsDia[2]; //Puesto de Tickets Noche
		spotLightsNocheTopos[1] = spotLightsDia[0];  //Carrusel Noche


		//Información al shader de fuentes de iluminación
		shaderList[0].SetDirectionalLight(&mainLight);

		if (skyCount < 3000) { //Es de día
			//POINT LIGHTS
			if ( mainWindow.getarticulacion9() % 2 == 0 && mainWindow.getarticulacion10() % 2 == 0) { //Luz inazuma apagada (tecla O) y Luz Hot Dogs apagada (tecla P)
				shaderList[0].SetPointLights(pointLightsDia, pointLightDiaCount - 2);
			}
			else if (mainWindow.getarticulacion9() % 2 != 0 && mainWindow.getarticulacion10() % 2 == 0) { //Luz inazuma encendida (tecla O) y Luz Hot Dogs apagada (tecla P)
				shaderList[0].SetPointLights(pointLightsDia2, pointLightDiaCount - 1);
			}
			else if (mainWindow.getarticulacion9() % 2 == 0 && mainWindow.getarticulacion10() % 2 != 0) { //Luz inazuma apagada (tecla O) y Luz Hot Dogs encendida (tecla P)
				shaderList[0].SetPointLights(pointLightsDia, pointLightDiaCount - 1);
			}
			else if(mainWindow.getarticulacion9() % 2 != 0 && mainWindow.getarticulacion10() % 2 != 0) { //Luz inazuma encendida (tecla O) y Luz Hot Dogs encendida (tecla P)
				shaderList[0].SetPointLights(pointLightsDia, pointLightDiaCount);
			}

			//SPOT LIGHTS
			if (camaraAnimacion == 1) { // Luz Puesto Lanzamiento de Hacha
				shaderList[0].SetSpotLights(spotLightsDiaHacha, spotLightDiaCount);
			}
			else if (camaraAnimacion == 2) { // Luz Puesto Boliche
				shaderList[0].SetSpotLights(spotLightsDiaBoliche, spotLightDiaCount);
			} 
			else if (camaraAnimacion == 3) { // Luz Puesto Dados
				shaderList[0].SetSpotLights(spotLightsDiaDados, spotLightDiaCount);
			}
			else if (camaraAnimacion == 4) { // Luz Puesto Bateo
				shaderList[0].SetSpotLights(spotLightsDiaBateo, spotLightDiaCount);
			}
			else if (camaraAnimacion == 5) { // Luz Puesto Dardos
				shaderList[0].SetSpotLights(spotLightsDiaDardos, spotLightDiaCount);
			}
			else if (camaraAnimacion == 6) { // Luz Puesto Topos
				shaderList[0].SetSpotLights(spotLightsDiaTopos, spotLightDiaCount);
			}
			else { //Cámaras normales
				shaderList[0].SetSpotLights(spotLightsDia, spotLightDiaCount);
			}

		}
		else {	//Es de noche
			//POINT LIGHTS
			if (mainWindow.getarticulacion9() % 2 == 0) { //Luz inazuma apagada (tecla O)
				shaderList[0].SetPointLights(pointLightsNoche, pointLightNocheCount - 1);
			}
			else if (mainWindow.getarticulacion9() % 2 != 0) {
				shaderList[0].SetPointLights(pointLightsNoche, pointLightNocheCount); //Luz inazuma encendida (tecla O)
			}

			//SPOT LIGHTS
			if (camaraAnimacion == 1) { // Luz Puesto Lanzamiento de Hacha
				shaderList[0].SetSpotLights(spotLightsNocheHacha, spotLightNocheCount);
			}
			else if (camaraAnimacion == 2) { // Luz Puesto Boliche
				shaderList[0].SetSpotLights(spotLightsNocheBoliche, spotLightNocheCount);
			} 
			else if (camaraAnimacion == 3) { // Luz Puesto Dados
				shaderList[0].SetSpotLights(spotLightsNocheDados, spotLightNocheCount);
			}
			else if (camaraAnimacion == 4) { // Luz Puesto Bateo
				shaderList[0].SetSpotLights(spotLightsNocheBateo, spotLightNocheCount);
			}
			else if (camaraAnimacion == 5) { // Luz Puesto Dardos
				shaderList[0].SetSpotLights(spotLightsNocheDardos, spotLightNocheCount);
			}
			else if (camaraAnimacion == 6) { // Luz Puesto Topos
				shaderList[0].SetSpotLights(spotLightsNocheTopos, spotLightNocheCount);
			}
			else { //Cámaras normales
				shaderList[0].SetSpotLights(spotLightsNoche, spotLightNocheCount);
			}
		}

		// --------------------------------------
		// ---------INICIALIZAR VECTORES---------
		// --------------------------------------

		glm::mat4 model(1.0);
		glm::mat4 modelaux(1.0);
		glm::mat4 modelaux2(1.0);
		glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);

		// --------------------------------------
		// ----------ANIMACIONES STANDS----------
		// --------------------------------------

		if (camaraAnimacion == 1) { //Stand hacha 3
			banderaCamara = 1; //Para que la camara no se pueda mover hasta que se acabe la animación. Al final debe volver a 0.

			if (timerBateo < 670.0) { //Timpo que va a durar la animación general del stand

				//INICIO ANIMACIÓN DE LA MONEDA

				if (brazoVariacion <= 100.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-107.2f, 7.1f, -78.6f));
					model = glm::rotate(model, -brazoVariacion * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Izquierda.RenderModel();

					brazoVariacion += 0.5f * deltaTime;
				}
				if (timerBateo > 50.0 && timerBateo < 180.0 && brazoVariacion >= 100 && brazoVariacion1 == 100.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-107.2f, 7.1f, -78.6f));
					model = glm::rotate(model, -brazoVariacion * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Izquierda.RenderModel();

					if (timerBateo > 100.0 && timerBateo < 170.0) {
						//Moneda del juego
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-108.85f, 7.6f, -78.6f));//(x -1.65, y +0.5, z misma)
						model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Destino_Genshin.RenderModel();
					}
				}
				if (brazoVariacion1 >= 20.0 && brazoVariacion >= 100 && timerBateo > 180.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-107.2f, 7.1f, -78.6f));
					model = glm::rotate(model, -brazoVariacion1 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Izquierda.RenderModel();

					brazoVariacion1 -= 0.5f * deltaTime;
				}
				//FIN ANIMACIÓN DE LA MONEDA

				///AQUI VA LA ANIMACIÓN DE CADA STAND
				if (brazoVariacion1 <= 20.0 && brazoVariacion >= 100 && timerBateo > 250.0) {
					if (inicioBrazo < 100.0) { //Sube el brazo con el hacha
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-107.2f, 7.1f, -78.6f));
						model = glm::rotate(model, -inicioBrazo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Derecha.RenderModel();

						//Hacha
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-109.0f, 4.0f + (inicioBrazo * 0.03), -78.5f));
						model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Hacha_M.RenderModel();

						inicioBrazo += 0.5f * deltaTime;
					}
					if (movBateo < 30.0 && inicioBrazo >= 100.0) { //Hace el hacha hacia atrás para lanzar
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-107.2f, 7.1f, -78.6f));
						model = glm::rotate(model, -inicioBrazo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						//model = glm::rotate(model, -movBateo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Derecha.RenderModel();

						//Hacha
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-109.0f, 4.0f + (inicioBrazo * 0.03), -78.5f));
						model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, movBateo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Hacha_M.RenderModel();

						movBateo += 0.5f * deltaTime;
					}
					if (movBateoPelotaRegreso < 10.0 && movBateo >= 30.0 && inicioBrazo >= 100.0) { //Esperar
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-107.2f, 7.1f, -78.6f));
						model = glm::rotate(model, -inicioBrazo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						//model = glm::rotate(model, -movBateo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Derecha.RenderModel();

						//Hacha
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-109.0f, 4.0f + (inicioBrazo * 0.03), -78.5f));
						model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, movBateo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Hacha_M.RenderModel();

						movBateoPelotaRegreso += 0.25f * deltaTime;
					}
					if (movBateoPelota < 45.0 && movBateoPelotaRegreso >= 10.0 && movBateo >= 30.0 && inicioBrazo >= 100.0) { //Hace el hacha hacia delante
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-107.2f, 7.1f, -78.6f));
						model = glm::rotate(model, -inicioBrazo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						//model = glm::rotate(model, -movBateo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Derecha.RenderModel();

						//Hacha
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-109.0f, 4.0f + (inicioBrazo * 0.03), -78.5f));
						model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, (movBateo - movBateoPelota) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Hacha_M.RenderModel();

						movBateoPelota += 0.7f * deltaTime;
					}
					if (movBateoRegreso < 14.5 && movBateoPelota >= 45.0 && movBateoPelotaRegreso >= 10.0 && movBateo >= 30.0 &&
						inicioBrazo >= 100.0) { //Avanza el hacha y la gira
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-107.2f, 7.1f, -78.6f));
						model = glm::rotate(model, -inicioBrazo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Derecha.RenderModel();

						//Hacha
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-109.0f - movBateoRegreso, 4.0f + (inicioBrazo * 0.03), -78.5f));
						model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, ((movBateo - movBateoPelota) - movBateoRegreso * 50) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Hacha_M.RenderModel();

						movBateoRegreso += 0.05f * deltaTime;
					}
					if (movDardoNuevo < 100.0 && movBateoRegreso >= 14.5 && movBateoPelota >= 45.0 && movBateoPelotaRegreso >= 10.0 && movBateo >= 30.0 &&
						inicioBrazo >= 100.0) { //Avanza el hacha y la gira
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-107.2f, 7.1f, -78.6f));
						model = glm::rotate(model, (-inicioBrazo + movDardoNuevo) * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Derecha.RenderModel();

						//Hacha
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-109.0f - movBateoRegreso, 4.0f + (inicioBrazo * 0.03), -78.5f));
						model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, ((movBateo - movBateoPelota) - movBateoRegreso * 50) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Hacha_M.RenderModel();

						movDardoNuevo += 0.5f * deltaTime;
					}
				}

				////

				timerBateo += 0.5f * deltaTime;
			}
			else {
				//VARIABLES FUNCIONALIDAD CÁMARA Y ANIMACIÓN MONEDA (NO MOVER)
				banderaCamaraMovimiento = 0;//para que la camara regrese a la camara de blade de manera automatica
				banderaCamara = 0;//para que ya se puedan usar las teclas de camaras
				camaraAnimacion = 0;//
				brazoVariacion = 20.0;
				brazoVariacion1 = 100.0;
				timerBateo = 0.0;

				//VARIABLES ANIMACIÓN DEL STAND
				inicioBrazo = 0.0;
				movBateo = 0.0;
				movBateoPelota = 0.0;
				movBateoPelotaRegreso = 0.0;
				movBateoRegreso = 0.0;
				movDardoNuevo = 0.0;
				//
			}
		}
		else if (camaraAnimacion == 2) { //Stand boliche
			banderaCamara = 1; //Para que la camara no se pueda mover hasta que se acabe la animación. Al final debe volver a 0.

			if (timerBateo < 1650.0) { //Timpo que va a durar la animación general del stand

				//INICIO ANIMACIÓN DE LA MONEDA

				if (brazoVariacion <= 100.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-54.0f, 8.5f, 64.2f));
					model = glm::rotate(model, -brazoVariacion * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Sur.RenderModel();

					//Rendija Boliche
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-60.0f, 0.0f, 93.0f));
					model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					Rendija_Boliche_M.RenderModel();

					brazoVariacion += 0.5f * deltaTime;
				}
				if (timerBateo > 50.0 && timerBateo < 180.0 && brazoVariacion >= 100 && brazoVariacion1 == 100.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-54.0f, 8.5f, 64.2f));
					model = glm::rotate(model, -brazoVariacion * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Sur.RenderModel();

					//Rendija Boliche
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-60.0f, 0.0f, 93.0f));
					model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					Rendija_Boliche_M.RenderModel();

					if (timerBateo > 100.0 && timerBateo < 170.0) {
						//Moneda del juego
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 9.0f, 65.85f));//(x misma, y +0.5, z +1.65)
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Destino_Genshin.RenderModel();
					}
				}
				if (brazoVariacion1 >= 20.0 && brazoVariacion >= 100 && timerBateo > 180.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-54.0f, 8.5f, 64.2f));
					model = glm::rotate(model, -brazoVariacion1 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Sur.RenderModel();

					//Rendija Boliche
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-60.0f, 0.0f, 93.0f));
					model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					Rendija_Boliche_M.RenderModel();

					brazoVariacion1 -= 0.5f * deltaTime;
				}
				//FIN ANIMACIÓN DE LA MONEDA

				///AQUI VA LA ANIMACIÓN DE CADA STAND

				if (brazoVariacion1 <= 20.0 && brazoVariacion >= 100 && timerBateo > 250.0) {
					if (inicioBrazo < 100.0) { //Sube el brazo y la pelota a la posición incial. Se levanta la rejilla de los bolos.
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 8.5f, 64.2f));
						model = glm::rotate(model, -inicioBrazo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Sur.RenderModel();

						//Rendija Boliche
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-60.0f, 0.0f + (inicioBrazo * 0.04), 93.0f));
						model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Rendija_Boliche_M.RenderModel();

						// Bolo Boliche 1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 111.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 2
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-52.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 3
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 4
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 5
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-51.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 6
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-55.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						//Bola Boliche
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 6.3f + (inicioBrazo * 0.03), 66.0f));
						model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bola_Boliche_M.RenderModel();

						inicioBrazo += 0.5f * deltaTime;
					}
					if (movBateo < 15.0 && inicioBrazo >= 100.0) { //Deja caer la pelota
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 8.5f, 64.2f));
						model = glm::rotate(model, -inicioBrazo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Sur.RenderModel();

						// Bolo Boliche 1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 111.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 2
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-52.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 3
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 4
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 5
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-51.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 6
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-55.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						//Bola Boliche
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 6.3f + (inicioBrazo * 0.03) - (movBateo * 0.5), 66.0f + movBateo));
						model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, -(movBateo * 100) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bola_Boliche_M.RenderModel();

						movBateo += 0.05f * deltaTime;
					}
					if (movBateoPelota < 25.0 && movBateo >= 15.0 && inicioBrazo >= 100.0) { //La pelota se mueve en la profundidad 
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 8.5f, 64.2f));
						model = glm::rotate(model, -inicioBrazo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Sur.RenderModel();

						// Bolo Boliche 1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 111.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 2
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-52.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 3
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 4
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 5
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-51.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 6
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-55.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						//Bola Boliche
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 6.3f + (inicioBrazo * 0.03) - (movBateo * 0.5), 66.0f + movBateo + (movBateoPelota * 1.2)));
						model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, -(movBateoPelota * 100) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bola_Boliche_M.RenderModel();

						movBateoPelota += 0.05f * deltaTime;
					}
					if (movBateoPelotaRegreso < 65.0 && movBateoPelota >= 25.0 && movBateo >= 15.0 && inicioBrazo >= 100.0) { //Se caen los pinos y vaja el brazo
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 8.5f, 64.2f));
						model = glm::rotate(model, -(inicioBrazo - movBateoPelotaRegreso) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Sur.RenderModel();

						// Bolo Boliche 1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 111.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 2
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-52.5f, 1.5f, 112.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 3
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.5f, 1.5f, 112.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 4
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 113.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 5
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-51.5f, 1.5f, 113.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 6
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-55.5f, 1.5f, 113.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						movBateoPelotaRegreso += 0.5f * deltaTime;
					}
					if (movBateoRegreso < 100.0 && movBateoPelotaRegreso >= 65.0 && movBateoPelota >= 25.0 && movBateo >= 15.0 &&
						inicioBrazo >= 100.0) { //Se baja la rejilla
						//Rendija Boliche
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-60.0f, 0.0f + ((inicioBrazo - movBateoRegreso) * 0.04), 93.0f));
						model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Rendija_Boliche_M.RenderModel();

						// Bolo Boliche 1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 111.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 2
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-52.5f, 1.5f, 112.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 3
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.5f, 1.5f, 112.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 4
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 113.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 5
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-51.5f, 1.5f, 113.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 6
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-55.5f, 1.5f, 113.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						movBateoRegreso += 0.5f * deltaTime;
					}
					///descarrilar
					if (movDardoNuevoArriba < 5.0 && movBateoRegreso >= 100.0 && movBateoPelotaRegreso >= 65.0 && movBateoPelota >= 25.0 && movBateo >= 15.0 &&
						inicioBrazo >= 100.0) { //Esperar
						//Rendija Boliche
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-60.0f, 0.0f + ((inicioBrazo - movBateoRegreso) * 0.04), 93.0f));
						model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Rendija_Boliche_M.RenderModel();

						// Bolo Boliche 1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 111.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 2
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-52.5f, 1.5f, 112.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 3
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.5f, 1.5f, 112.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 4
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 113.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 5
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-51.5f, 1.5f, 113.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 6
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-55.5f, 1.5f, 113.0f));
						model = glm::rotate(model, movBateoPelotaRegreso * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						movDardoNuevoArriba += 0.03f * deltaTime;
					}
					if (movDardoNuevo < 100.0 && movBateoRegreso >= 100.0 && movBateoPelotaRegreso >= 65.0 && movBateoPelota >= 25.0 && movBateo >= 15.0 &&
						inicioBrazo >= 100.0 && movDardoNuevoArriba >= 5.0) { //Sube el brazo y la pelota a la posición incial. Se levanta la rejilla de los bolos.
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 8.5f, 64.2f));
						model = glm::rotate(model, -movDardoNuevo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Sur.RenderModel();

						//Rendija Boliche
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-60.0f, 0.0f + (movDardoNuevo * 0.04), 93.0f));
						model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Rendija_Boliche_M.RenderModel();

						// Bolo Boliche 1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 111.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 2
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-52.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 3
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 4
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 5
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-51.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 6
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-55.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						//Bola Boliche
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 6.3f + (movDardoNuevo * 0.03), 66.0f));
						model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bola_Boliche_M.RenderModel();

						movDardoNuevo += 0.5f * deltaTime;
					}
					if (movDardoNuevo >= 100.0 && movBateoRegreso >= 100.0 && movBateoPelotaRegreso >= 65.0 && movBateoPelota >= 25.0
						&& movBateo >= 15.0 && inicioBrazo >= 100.0 && movDardoNuevoMovimiento < 15.0 && movDardoNuevoArriba >= 5.0) { //Deja caer la pelota
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 8.5f, 64.2f));
						model = glm::rotate(model, -movDardoNuevo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Sur.RenderModel();

						// Bolo Boliche 1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 111.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 2
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-52.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 3
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 4
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 5
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-51.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 6
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-55.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						//Bola Boliche
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f - movDardoNuevoMovimiento * 0.26, 6.3f + (movDardoNuevo * 0.03) - (movDardoNuevoMovimiento * 0.5), 66.0f + movDardoNuevoMovimiento));
						model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, -(movDardoNuevoMovimiento * 100) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bola_Boliche_M.RenderModel();

						movDardoNuevoMovimiento += 0.05f * deltaTime;
					}
					if (movDardoNuevo >= 100.0 && movBateoRegreso >= 100.0 && movBateoPelotaRegreso >= 65.0 && movBateoPelota >= 25.0
						&& movBateo >= 15.0 && inicioBrazo >= 100.0 && movDardoNuevoMovimiento >= 15.0 && movDardoRegreso < 25.0
						&& movDardoNuevoArriba >= 5.0) { //La pelota se mueve en la profundidad 
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 8.5f, 64.2f));
						model = glm::rotate(model, -movDardoNuevo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Sur.RenderModel();

						// Bolo Boliche 1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 111.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 2
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-52.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 3
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 4
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 5
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-51.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 6
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-55.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						//Bola Boliche
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f - movDardoNuevoMovimiento * 0.26, 6.3f + (movDardoNuevo * 0.03) - (movDardoNuevoMovimiento * 0.5), 66.0f + movDardoNuevoMovimiento + (movDardoRegreso * 1.2)));
						model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, -(movDardoRegreso * 100) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bola_Boliche_M.RenderModel();

						movDardoRegreso += 0.05f * deltaTime;
					}
					if (movDardoNuevo >= 100.0 && movBateoRegreso >= 100.0 && movBateoPelotaRegreso >= 65.0 && movBateoPelota >= 25.0
						&& movBateo >= 15.0 && inicioBrazo >= 100.0 && movDardoNuevoMovimiento >= 15.0 && movDardoRegreso >= 25.0
						&& moverDardoAbajo < 100.0 && movDardoNuevoArriba >= 5.0) { //Se baja la rejilla y se regresa el brazo
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.0f, 8.5f, 64.2f));
						model = glm::rotate(model, -(movDardoNuevo - moverDardoAbajo) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Sur.RenderModel();

						//Rendija Boliche
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-60.0f, 0.0f + ((movDardoNuevo - moverDardoAbajo) * 0.04), 93.0f));
						model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Rendija_Boliche_M.RenderModel();

						// Bolo Boliche 1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 111.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 2
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-52.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 3
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-54.5f, 1.5f, 112.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 4
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-53.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 5
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-51.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						// Bolo Boliche 6
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-55.5f, 1.5f, 113.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bolo_M.RenderModel();

						moverDardoAbajo += 0.5f * deltaTime;
					}
					if (movDardoNuevo >= 100.0 && movBateoRegreso >= 100.0 && movBateoPelotaRegreso >= 65.0 && movBateoPelota >= 25.0
						&& movBateo >= 15.0 && inicioBrazo >= 100.0 && movDardoNuevoMovimiento >= 15.0 && movDardoRegreso >= 25.0
						&& moverDardoAbajo >= 100.0 && movDardoNuevoArriba >= 5.0 && movDardoNuevoMovimiento2 < 7.0) { //Espera
						//Rendija Boliche
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-60.0f, 0.0f + ((movDardoNuevo - moverDardoAbajo) * 0.04), 93.0f));
						model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Rendija_Boliche_M.RenderModel();

						movDardoNuevoMovimiento2 += 0.05f * deltaTime;
					}
				}

				////

				timerBateo += 0.5f * deltaTime;
			}
			else {
				//VARIABLES FUNCIONALIDAD CÁMARA Y ANIMACIÓN MONEDA (NO MOVER)
				banderaCamaraMovimiento = 0;//para que la camara regrese a la camara de blade de manera automatica
				banderaCamara = 0;//para que ya se puedan usar las teclas de camaras
				camaraAnimacion = 0;//
				brazoVariacion = 20.0;
				brazoVariacion1 = 100.0;
				timerBateo = 0.0;

				//VARIABLES ANIMACIÓN DEL STAND
				inicioBrazo = 0.0;
				movBateo = 0.0;
				movBateoPelota = 0.0;
				movBateoPelotaRegreso = 0.0;
				movBateoRegreso = 0.0;
				movDardoNuevo = 0.0;
				movDardoNuevoMovimiento = 0.0f;
				movDardoRegreso = 0.0f;
				moverDardoAbajo = 0.0f;
				movDardoNuevoArriba = 0.0f;
				movDardoNuevoMovimiento2 = 0.0f;
				//
			}
		}
		else if (camaraAnimacion == 3) { //Stand dados
			banderaCamara = 1; //Para que la camara no se pueda mover hasta que se acabe la animación. Al final debe volver a 0.

			if (timerBateo < 500.0) { //Timpo que va a durar la animación general del stand

				//INICIO ANIMACIÓN DE LA MONEDA

				if (brazoVariacion <= 100.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-103.0f, 7.0f, -36.6f));
					model = glm::rotate(model, -brazoVariacion * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Izquierda.RenderModel();

					brazoVariacion += 0.5f * deltaTime;
				}
				if (timerBateo > 50.0 && timerBateo < 180.0 && brazoVariacion >= 100 && brazoVariacion1 == 100.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-103.0f, 7.0f, -36.6f));
					model = glm::rotate(model, -brazoVariacion * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Izquierda.RenderModel();

					if (timerBateo > 100.0 && timerBateo < 170.0) {
						//Moneda del juego
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-104.65f, 7.5f, -36.6f));//(x -1.65, y +0.5, z misma)
						model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Ticket_StarRail.RenderModel();
					}
				}
				if (brazoVariacion1 >= 20.0 && brazoVariacion >= 100 && timerBateo > 180.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-103.0f, 7.0f, -36.6f));
					model = glm::rotate(model, -brazoVariacion1 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Izquierda.RenderModel();

					brazoVariacion1 -= 0.5f * deltaTime;
				}
				//FIN ANIMACIÓN DE LA MONEDA

				///AQUI VA LA ANIMACIÓN DE CADA STAND

				if (timerBateo > 260.0 && timerBateo < 380) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-103.0f, 7.0f, -36.6f));
					model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));//mueve arriba (-) o abajo (+)
					model = glm::rotate(model, BrazoMartillo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Izquierda.RenderModel();

					model = glm::translate(model, glm::vec3(-0.1f, -1.8f, -0.2f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					MesaDados_Dados1_M.RenderModel();

					model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.2f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					MesaDados_Dados2_M.RenderModel();

					if (timerBateo > 260.0 && timerBateo < 320) {
						BrazoMartillo -= 1.5f * deltaTime;


					}
					else {
						BrazoMartillo += 0.6f * deltaTime;
					}

				}

				if (timerBateo > 380 && timerBateo < 470) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-103.0f, 7.0f, -36.6f));
					model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));//mueve arriba (-) o abajo (+)
					model = glm::rotate(model, BrazoMartillo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Izquierda.RenderModel();

					model = glm::translate(model, glm::vec3(-0.1f - TiroDado * 0.8, -2.0f + TiroDado * 1.2, -0.2f));
					model = glm::rotate(model, TiroDado * 70 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					MesaDados_Dados1_M.RenderModel();

					model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.2f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					MesaDados_Dados2_M.RenderModel();

					TiroDado -= 0.02f * deltaTime;


				}
				if (timerBateo > 470 && timerBateo < 500) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-103.0f, 7.0f, -36.6f));
					model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));//mueve arriba (-) o abajo (+)
					model = glm::rotate(model, BrazoMartillo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Izquierda.RenderModel();

					model = glm::translate(model, glm::vec3(-0.1f - TiroDado * 0.8, -2.0f + TiroDado * 1.2, -0.2f));
					model = glm::rotate(model, TiroDado * 70 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					MesaDados_Dados1_M.RenderModel();

					model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.2f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					MesaDados_Dados2_M.RenderModel();
				}
				////

				timerBateo += 0.5f * deltaTime;
			}
			else {
				//VARIABLES FUNCIONALIDAD CÁMARA Y ANIMACIÓN MONEDA (NO MOVER)
				banderaCamaraMovimiento = 0;//para que la camara regrese a la camara de blade de manera automatica
				banderaCamara = 0;//para que ya se puedan usar las teclas de camaras
				camaraAnimacion = 0;//
				brazoVariacion = 20.0;
				brazoVariacion1 = 100.0;
				timerBateo = 0.0;
				BrazoMartillo = 20.0f;
				TiroDado = 0.0f;
			}
		}
		else if (camaraAnimacion == 4) { //Stand bateo
			banderaCamara = 1; //Para que la camara no se pueda mover hasta que se acabe la animación. Al final debe volver a 0.

			if (timerBateo < 670.0) { //Timpo que va a durar la animación general del stand		

				//INICIO ANIMACIÓN DE LA MONEDA

				//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//rota el brazo
				//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));//mueve hacia derecha o izquierda
				//model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba o abajo

				if (brazoVariacion <= 100.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-3.6f, 8.0f, 94.2f));
					model = glm::rotate(model, -brazoVariacion * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Sur.RenderModel();

					brazoVariacion += 0.5f * deltaTime;
				}
				if (timerBateo > 50.0 && timerBateo < 180.0 && brazoVariacion >= 100 && brazoVariacion1 == 100.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-3.6f, 8.0f, 94.2f));
					model = glm::rotate(model, -brazoVariacion * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Sur.RenderModel();

					if (timerBateo > 100.0 && timerBateo < 170.0) {
						//Moneda del juego
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.6f, 8.5f, 95.85f));//(x misma, y +0.5, z +1.65)
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Tear_Themis.RenderModel();
					}
				}
				if (brazoVariacion1 >= 20.0 && brazoVariacion >= 100 && timerBateo > 180.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(-3.6f, 8.0f, 94.2f));
					model = glm::rotate(model, -brazoVariacion1 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Sur.RenderModel();

					brazoVariacion1 -= 0.5f * deltaTime;
				}
				//FIN ANIMACIÓN DE LA MONEDA

				///AQUI VA LA ANIMACIÓN DE CADA STAND

				if (brazoVariacion1 <= 20.0 && brazoVariacion >= 100 && timerBateo > 250.0) {

					if (inicioBrazo < 100.0) {
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.6f, 8.0f, 94.2f));
						model = glm::rotate(model, -inicioBrazo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						//model = glm::rotate(model, movBateo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho.RenderModel();

						//Bate
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.5f, 0.0f + inicioBrazo * 0.082, 96.0f));
						model = glm::rotate(model, 30 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));//+30 grados
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bate_M.RenderModel();

						inicioBrazo += 0.5f * deltaTime;
					}

					if (movBateo < 0.8 && inicioBrazo >= 100.0) {
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.6f - movBateo, 8.0f, 94.2f));
						model = glm::rotate(model, -100 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						//model = glm::rotate(model, movBateo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho.RenderModel();

						//Bate
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.5f - movBateo, 8.2f, 96.0f));
						model = glm::rotate(model, 30 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));//+30 grados
						model = glm::rotate(model, (movBateo * 50) * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bate_M.RenderModel();

						movBateo += 0.005f * deltaTime;
					}
					if (movBateo >= 0.8 && movBateoPelota < 16.0) {
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.6f - movBateo, 8.0f, 94.2f));
						model = glm::rotate(model, -100 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						//model = glm::rotate(model, movBateo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho.RenderModel();

						//Bate
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.5f - movBateo, 8.2f, 96.0f));
						model = glm::rotate(model, 30 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));//+30 grados
						model = glm::rotate(model, (movBateo * 50) * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bate_M.RenderModel();

						//Pelota de Baseball
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.5f - (movBateoPelota * 0.5), 7.0f + (movBateoPelota * 0.4), 115.0f - movBateoPelota));
						model = glm::rotate(model, (movBateoPelota * 30) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						PelotaBateo_M.RenderModel();

						movBateoPelota += 0.1f * deltaTime;
					}
					if (movBateo >= 0.8 && movBateoPelota >= 16.0 && movBateoPelotaRegreso < 16.0) {
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.6f - movBateo, 8.0f, 94.2f));
						model = glm::rotate(model, -100 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						//model = glm::rotate(model, movBateo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho.RenderModel();

						//Bate
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.5f - movBateo, 8.2f, 96.0f));
						model = glm::rotate(model, 30 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));//+30 grados
						model = glm::rotate(model, (movBateo * 50) * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bate_M.RenderModel();

						//Pelota de Baseball
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.5f - (movBateoPelota * 0.5) + (movBateoPelotaRegreso * 0.5), 7.0f +
							(movBateoPelota * 0.4) - (movBateoPelotaRegreso * 0.4), 115.0f - movBateoPelota + movBateoPelotaRegreso));
						model = glm::rotate(model, -(movBateoPelotaRegreso * 30) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						PelotaBateo_M.RenderModel();

						movBateoPelotaRegreso += 0.1f * deltaTime;
					}
					if (movBateo >= 0.8 && movBateoPelota >= 16.0 && movBateoPelotaRegreso >= 16.0 && movBateoRegreso < 0.8) {
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.6f - movBateo + movBateoRegreso, 8.0f, 94.2f));
						model = glm::rotate(model, -100 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						//model = glm::rotate(model, movBateo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho.RenderModel();

						//Bate
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(-3.5f - movBateo + movBateoRegreso, 8.2f, 96.0f));
						model = glm::rotate(model, 30 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));//+30 grados
						model = glm::rotate(model, ((movBateo * 50) - (movBateoRegreso * 50)) * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Bate_M.RenderModel();

						movBateoRegreso += 0.005f * deltaTime;
					}
				}


				////

				timerBateo += 0.5f * deltaTime;
			}
			else {
				//VARIABLES FUNCIONALIDAD CÁMARA Y ANIMACIÓN MONEDA (NO MOVER)
				banderaCamaraMovimiento = 0;//para que la camara regrese a la camara de blade de manera automatica
				banderaCamara = 0;//para que ya se puedan usar las teclas de camaras
				camaraAnimacion = 0;//
				brazoVariacion = 20.0;
				brazoVariacion1 = 100.0;
				timerBateo = 0.0;

				//VARIABLES ANIMACIÓN DEL STAND
				movBateo = 0.0;
				movBateoPelota = 0.0;
				movBateoPelotaRegreso = 0.0;
				movBateoRegreso = 0.0;
				inicioBrazo = 0.0;
				//
			}
		}
		else if (camaraAnimacion == 5) { //Stand dardos
			banderaCamara = 1; //Para que la camara no se pueda mover hasta que se acabe la animación. Al final debe volver a 0.

			if (timerBateo < 980.0) { //Timpo que va a durar la animación general del stand

				//INICIO ANIMACIÓN DE LA MONEDA

				if (brazoVariacion <= 100.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
					model = glm::rotate(model, brazoVariacion * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Derecha.RenderModel();

					//Globo1
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
					model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					Globo1_M.RenderModel();

					//Globo2
					Globo2_M.RenderModel();

					//Globo3
					Globo3_M.RenderModel();

					brazoVariacion += 0.5f * deltaTime;
				}
				if (timerBateo > 50.0 && timerBateo < 180.0 && brazoVariacion >= 100 && brazoVariacion1 == 100.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
					model = glm::rotate(model, brazoVariacion * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Derecha.RenderModel();

					//Globo1
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
					model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					Globo1_M.RenderModel();

					//Globo2
					Globo2_M.RenderModel();

					//Globo3
					Globo3_M.RenderModel();

					if (timerBateo > 100.0 && timerBateo < 170.0) {
						//Moneda del juego
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(93.95f, 8.2f, -25.0f));//(x +1.65, y +0.5, z misma)
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Tear_Themis.RenderModel();
					}
				}
				if (brazoVariacion1 >= 20.0 && brazoVariacion >= 100 && timerBateo > 180.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
					model = glm::rotate(model, brazoVariacion1 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Derecha.RenderModel();

					//Globo1
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
					model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					Globo1_M.RenderModel();

					//Globo2
					Globo2_M.RenderModel();

					//Globo3
					Globo3_M.RenderModel();

					brazoVariacion1 -= 0.5f * deltaTime;
				}
				//FIN ANIMACIÓN DE LA MONEDA

				///AQUI VA LA ANIMACIÓN DE CADA STAND

				if (brazoVariacion1 <= 20.0 && brazoVariacion >= 100 && timerBateo > 250.0) {
					if (inicioBrazo < 100.0) {
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
						model = glm::rotate(model, inicioBrazo * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Izquierda.RenderModel();

						//Globo1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Globo1_M.RenderModel();

						//Globo2
						Globo2_M.RenderModel();

						//Globo3
						Globo3_M.RenderModel();

						inicioBrazo += 0.5f * deltaTime;
					}
					if (movBateo < 8.0 && inicioBrazo >= 100.0) { //Mueve brazo hacia arriba
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
						model = glm::rotate(model, 100 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, movBateo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Izquierda.RenderModel();

						//Globo1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Globo1_M.RenderModel();

						//Globo2
						Globo2_M.RenderModel();

						//Globo3
						Globo3_M.RenderModel();

						//Dardo
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(109.5f, 1.2f + movBateo * 0.05, -25.7f));//98
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Dardo_M.RenderModel();

						movBateo += 0.05f * deltaTime;
					}
					if (movBateo >= 8.0 && movBateoPelota < 8.0) { //Mueve dardo
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
						model = glm::rotate(model, 100 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, movBateo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Izquierda.RenderModel();

						//Globo1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Globo1_M.RenderModel();

						//Globo2
						Globo2_M.RenderModel();

						//Globo3
						Globo3_M.RenderModel();

						//Dardo
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(109.5f + movBateoPelota, 1.2f + movBateo * 0.05, -25.7f - (movBateoPelota * 0.2)));//98
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Dardo_M.RenderModel();

						movBateoPelota += 0.1f * deltaTime;
					}
					if (movBateo >= 8.0 && movBateoPelota >= 8.0 && movBateoPelotaRegreso < 8.0) { //Desaparece globo
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
						model = glm::rotate(model, 100 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, movBateo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Izquierda.RenderModel();

						//Globo1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Globo1_M.RenderModel();

						//Globo2
						//Globo2_M.RenderModel();

						//Globo3
						Globo3_M.RenderModel();

						movBateoPelotaRegreso += 0.1f * deltaTime;
					}
					if (movBateo >= 8.0 && movBateoPelota >= 8.0 && movBateoPelotaRegreso >= 8.0 && movBateoRegreso < 8.0) { //Mueve brazo hacia abajo
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
						model = glm::rotate(model, 100 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, (movBateo - movBateoRegreso) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Izquierda.RenderModel();

						//Globo1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Globo1_M.RenderModel();

						//Globo2
						//Globo2_M.RenderModel();

						//Globo3
						Globo3_M.RenderModel();

						movBateoRegreso += 0.05f * deltaTime;
					}
					if (movBateo >= 8.0 && movBateoPelota >= 8.0 && movBateoPelotaRegreso >= 8.0 && movBateoRegreso >= 8.0
						&& movDardoNuevo < 8.0) { //Mueve brazo hacia arriba
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
						model = glm::rotate(model, 100 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, movDardoNuevo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Izquierda.RenderModel();

						//Globo1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Globo1_M.RenderModel();

						//Globo2
						//Globo2_M.RenderModel();

						//Globo3
						Globo3_M.RenderModel();

						//Dardo
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(109.5f, 1.2f + movDardoNuevo * 0.05, -25.7f));//98
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Dardo_M.RenderModel();

						movDardoNuevo += 0.05f * deltaTime;
					}
					if (movBateo >= 8.0 && movBateoPelota >= 8.0 && movBateoPelotaRegreso >= 8.0 && movBateoRegreso >= 8.0
						&& movDardoNuevo >= 8.0 && movDardoNuevoMovimiento < 8.0) { //Mueve Dardo
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
						model = glm::rotate(model, 100 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, movDardoNuevo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Izquierda.RenderModel();

						//Globo1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Globo1_M.RenderModel();

						//Globo2
						//Globo2_M.RenderModel();

						//Globo3
						Globo3_M.RenderModel();

						//Dardo
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(109.5f + movDardoNuevoMovimiento, 1.2f + movDardoNuevo * 0.05, -25.7f - (movDardoNuevoMovimiento * 0.003)));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Dardo_M.RenderModel();

						movDardoNuevoMovimiento += 0.1f * deltaTime;
					}
					if (movBateo >= 8.0 && movBateoPelota >= 8.0 && movBateoPelotaRegreso >= 8.0 && movBateoRegreso >= 8.0
						&& movDardoNuevo >= 8.0 && movDardoNuevoMovimiento >= 8.0 && movDardoRegreso < 8.0) { //Desaparece globo
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
						model = glm::rotate(model, 100 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, movDardoNuevo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Izquierda.RenderModel();

						//Globo1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Globo3_M.RenderModel();

						//Globo2
						//Globo2_M.RenderModel();

						//Globo3
						//Globo1_M.RenderModel();

						movDardoRegreso += 0.1f * deltaTime;
					}
					if (movBateo >= 8.0 && movBateoPelota >= 8.0 && movBateoPelotaRegreso >= 8.0 && movBateoRegreso >= 8.0
						&& movDardoNuevo >= 8.0 && movDardoNuevoMovimiento >= 8.0 && movDardoRegreso >= 8.0
						&& moverDardoAbajo < 8.0) { //Mueve brazo hacia abajo
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
						model = glm::rotate(model, 100 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, (movDardoNuevo - moverDardoAbajo) * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Izquierda.RenderModel();

						//Globo1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Globo3_M.RenderModel();

						//Globo2
						//Globo2_M.RenderModel();

						//Globo3
						//Globo1_M.RenderModel();

						moverDardoAbajo += 0.05f * deltaTime;
					}
					if (movBateo >= 8.0 && movBateoPelota >= 8.0 && movBateoPelotaRegreso >= 8.0 && movBateoRegreso >= 8.0
						&& movDardoNuevo >= 8.0 && movDardoNuevoMovimiento >= 8.0 && movDardoRegreso >= 8.0
						&& moverDardoAbajo >= 8.0 && movDardoNuevoArriba < 8.0) { //Mueve brazo hacia arriba
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
						model = glm::rotate(model, 100 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, movDardoNuevoArriba * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Izquierda.RenderModel();

						//Globo1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Globo3_M.RenderModel();

						//Globo2
						//Globo2_M.RenderModel();

						//Globo3
						//Globo1_M.RenderModel();

						//Dardo
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(109.5f, 1.2f + movDardoNuevoArriba * 0.05, -25.7f));//98
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Dardo_M.RenderModel();

						movDardoNuevoArriba += 0.05f * deltaTime;
					}
					if (movBateo >= 8.0 && movBateoPelota >= 8.0 && movBateoPelotaRegreso >= 8.0 && movBateoRegreso >= 8.0
						&& movDardoNuevo >= 8.0 && movDardoNuevoMovimiento >= 8.0 && movDardoRegreso >= 8.0
						&& moverDardoAbajo >= 8.0 && movDardoNuevoArriba >= 8.0 && movDardoNuevoMovimiento2 < 8.0) { //Mueve Dardo
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
						model = glm::rotate(model, 100 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, movDardoNuevoArriba * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Izquierda.RenderModel();

						//Globo1
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Globo3_M.RenderModel();

						//Globo2
						//Globo2_M.RenderModel();

						//Globo3
						//Globo1_M.RenderModel();

						//Dardo
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(109.5f + movDardoNuevoMovimiento2, 1.2f + movDardoNuevoArriba * 0.05, -25.7f + (movDardoNuevoMovimiento2 * 0.2)));
						model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Dardo_M.RenderModel();

						movDardoNuevoMovimiento2 += 0.1f * deltaTime;
					}
					if (movBateo >= 8.0 && movBateoPelota >= 8.0 && movBateoPelotaRegreso >= 8.0 && movBateoRegreso >= 8.0
						&& movDardoNuevo >= 8.0 && movDardoNuevoMovimiento >= 8.0 && movDardoRegreso >= 8.0
						&& moverDardoAbajo >= 8.0 && movDardoNuevoArriba >= 8.0 && movDardoNuevoMovimiento2 >= 8.0
						&& movDardoRegreso2 < 8.0) { //Desaparece globo
						//Antebrazo derecho
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(92.3f, 7.7f, -25.0f));
						model = glm::rotate(model, 100 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));//mueve arriba (-) o abajo (+)
						model = glm::rotate(model, -70 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
						model = glm::rotate(model, movDardoNuevo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						BrazoDerecho_Izquierda.RenderModel();

						//Globo2
						//Globo2_M.RenderModel();

						//Globo3
						//Globo1_M.RenderModel();

						movDardoRegreso2 += 0.1f * deltaTime;
					}
				}

				////

				timerBateo += 0.5f * deltaTime;
			}
			else {
				//VARIABLES FUNCIONALIDAD CÁMARA Y ANIMACIÓN MONEDA (NO MOVER)
				banderaCamaraMovimiento = 0;//para que la camara regrese a la camara de blade de manera automatica
				banderaCamara = 0;//para que ya se puedan usar las teclas de camaras
				camaraAnimacion = 0;//
				brazoVariacion = 20.0;
				brazoVariacion1 = 100.0;
				timerBateo = 0.0;

				//VARIABLES ANIMACIÓN DEL STAND
				inicioBrazo = 0.0;
				movBateo = 0.0;
				movBateoPelota = 0.0;
				movBateoPelotaRegreso = 0.0;
				movBateoRegreso = 0.0;
				movDardoNuevo = 0.0;
				movDardoNuevoMovimiento = 0.0f;
				movDardoRegreso = 0.0f;
				moverDardoAbajo = 0.0f;
				movDardoNuevoArriba = 0.0f;
				movDardoNuevoMovimiento2 = 0.0f;
				movDardoRegreso2 = 0.0f;

				//
			}
		}
		else if (camaraAnimacion == 6) { //Stand topo
			banderaCamara = 1; //Para que la camara no se pueda mover hasta que se acabe la animación. Al final debe volver a 0.

			if (timerBateo < 500.0) { //Timpo que va a durar la animación general del stand

				//INICIO ANIMACIÓN DE LA MONEDA

				if (brazoVariacion <= 100.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(59.5f, 7.1f, 63.2f));
					model = glm::rotate(model, -brazoVariacion * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Sur.RenderModel();

					brazoVariacion += 0.5f * deltaTime;
				}
				if (timerBateo > 50.0 && timerBateo < 180.0 && brazoVariacion >= 100 && brazoVariacion1 == 100.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(59.5f, 7.1f, 63.2f));
					model = glm::rotate(model, -brazoVariacion * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Sur.RenderModel();

					if (timerBateo > 100.0 && timerBateo < 170.0) {
						//Moneda del juego
						model = glm::mat4(1.0);
						model = glm::translate(model, glm::vec3(59.5f, 7.6f, 64.85f));//(x misma, y +0.5, z +1.65)
						glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
						Ticket_StarRail.RenderModel();
					}
				}
				if (brazoVariacion1 >= 20.0 && brazoVariacion >= 100 && timerBateo > 180.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(59.5f, 7.1f, 63.2f));
					model = glm::rotate(model, -brazoVariacion1 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Sur.RenderModel();

					brazoVariacion1 -= 0.5f * deltaTime;
				}
				//FIN ANIMACIÓN DE LA MONEDA

				///AQUI VA LA ANIMACIÓN DE CADA STAND

				if (timerBateo > 260.0 && timerBateo < 380) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(59.5f, 7.1f, 63.2f));
					model = glm::rotate(model, 10 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
					model = glm::rotate(model, BrazoMartillo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Derecha.RenderModel();

					model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
					model = glm::translate(model, glm::vec3(0.0f, 0.0f, 1.8f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					GolpearTopo_MazaHerta_M.RenderModel();

					if (timerBateo > 260.0 && timerBateo < 320) {
						BrazoMartillo -= 1.5f * deltaTime;
					}
					else {
						BrazoMartillo += 1.5f * deltaTime;
						if (timerBateo > 360.0 && timerBateo <= 380) ToposY2 -= 0.02f * deltaTime;
					}

				}

				if (timerBateo > 380.0 && timerBateo <= 500.0) {
					//Antebrazo derecho
					model = glm::mat4(1.0);
					model = glm::translate(model, glm::vec3(59.5f, 7.1f, 63.2f));
					model = glm::rotate(model, 30 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
					model = glm::rotate(model, BrazoMartillo * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));//mueve arriba (-) o abajo (+)
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					BrazoDerecho_Derecha.RenderModel();

					model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
					model = glm::translate(model, glm::vec3(0.0f, 0.0f, 1.8f));
					glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
					GolpearTopo_MazaHerta_M.RenderModel();

					if (timerBateo > 380.0 && timerBateo < 440) {
						BrazoMartillo -= 1.5f * deltaTime;
					}
					else {
						if (timerBateo > 480.0 && timerBateo <= 500) ToposY1 -= 0.02f * deltaTime;
						BrazoMartillo += 1.5f * deltaTime;
					}

				}
				////

				timerBateo += 0.5f * deltaTime;
			}
			else {
				//VARIABLES FUNCIONALIDAD CÁMARA Y ANIMACIÓN MONEDA (NO MOVER)
				banderaCamaraMovimiento = 0;//para que la camara regrese a la camara de blade de manera automatica
				banderaCamara = 0;//para que ya se puedan usar las teclas de camaras
				camaraAnimacion = 0;//
				brazoVariacion = 20.0;
				brazoVariacion1 = 100.0;
				timerBateo = 0.0;
				ToposY1 = 0.0f;
				ToposY2 = 0.0f;
				BrazoMartillo = 20.0f;
				//VARIABLES ANIMACIÓN DEL STAND

				//
			}
		}


		// --------------------------------------
		// -----------------PISO-----------------
		// --------------------------------------

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(30.0f, 1.0f, 30.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));

		pisoTexture.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);

		meshList[0]->RenderMesh();

		// --------------------------------------
		// ------------RUEDA FORTUNA-------------
		// --------------------------------------

		//Rueda Fortuna
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		RuedaFortuna_M.RenderModel();
		
		if (contadorInicioPrograma == 1) {

			//Neuvillette (cuerpo) Genshin Impact
			model = glm::mat4(1.0);
			model = glm::translate(model, glm::vec3(13.0f, 0.0f, 20.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			NeuvilletteCuerpo_Genshin_M.RenderModel();

			//Neuvillette hombro
			if (banderaNeuvi == 0 && NeuviHombro > -24.0f) {
				NeuviHombro -= 0.1f * deltaTime;
			}
			else if (NeuviHombro < 0.0f) {
				NeuviHombro += 0.1f * deltaTime;
				banderaNeuvi = 1;
			}
			else banderaNeuvi = 0;

			model = glm::translate(model, glm::vec3(-0.82f, 7.47f, -0.13f));
			model = glm::rotate(model, NeuviHombro * toRadians, glm::vec3(1.0f, 0.0f, 0.0f)); //-24 * toRadians
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			NeuvilletteHombro_Genshin_M.RenderModel();

			//Neuvillette brazo Y
			if (banderaNeuvi2 == 0 && NeuviBrazoY < 24.0f) {
				NeuviBrazoY += 0.1f * deltaTime;
			}
			else if (NeuviBrazoY > 0.0f) {
				NeuviBrazoY -= 0.1f * deltaTime;
				banderaNeuvi2 = 1;
			}
			else banderaNeuvi2 = 0;

			model = glm::translate(model, glm::vec3(-0.32f, -0.93f, 0.136f));
			model = glm::rotate(model, NeuviBrazoY * toRadians, glm::vec3(0.0f, 1.0f, 0.0f)); //24 * toRadians
			model = glm::rotate(model, -5 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
			model = glm::rotate(model, -8 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			NeuvilletteBrazo_Genshin_M.RenderModel();
		}
		else contadorInicioPrograma++;

		//Furina Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(20.0f, 0.0f, 19.0f));
		model = glm::rotate(model, -20 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Furina_Genshin_M.RenderModel();

		//Gato 7 de Marzo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 4.0f, 10.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Gato_March_M.RenderModel();

		//Basura Honkai Star Rail
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-20.0f, 0.0f, 20.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bote_StarRail_M.RenderModel();

		//Globos derecha
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(30.0f, 0.0f, 21.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(32.0f, 0.0f, 22.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(34.0f, 0.0f, 21.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		//Globos izquierda
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-30.0f, 0.0f, 21.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-32.0f, 0.0f, 22.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-34.0f, 0.0f, 21.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		// --------------------------------------
		// -----------PUESTO HELADOS-------------
		// --------------------------------------

		//Puesto helado
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(65.0f, 0.0f, 25.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PuestoHelado_M.RenderModel();

		//Marius Casual Tears of Themis Cuerpo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(66.5f, 0.0f, 24.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		MariusCasual_M.RenderModel();


		if (contadorInicioPrograma2 == 1) {
			//Marius brazo
			if (banderaMarius == 0 && MariusBrazo < 40.0f) {
				MariusBrazo += 0.2 * deltaTime;
			}
			else if (MariusBrazo >= 0.0f) {
				MariusBrazo -= 0.2 * deltaTime;
				banderaMarius = 1;
				if (helado1 == 0 && MariusContador2 == 0) helado1 = 1;
				if (helado2 == 0 && MariusContador2 == 1) helado2 = 1;
				if (helado3 == 0 && MariusContador2 == 2) helado3 = 1;

			}
			else {
				banderaMarius = 0;
				MariusContador2++;
				if (MariusContador < 2) MariusContador += 1;
				else MariusContador = 0;
			}

			if (MariusContador2 == 3) {
				MariusContador2 = 0;
				helado1 = 0;
				helado2 = 0;
				helado3 = 0;
			}

			model = glm::translate(model, glm::vec3(-0.44f, 7.13f, 2.73f));
			model = glm::rotate(model, MariusBrazo * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			MariusCasualBrazo_M.RenderModel();

			//Para que la bola gire en el cucharón
			if (MariusBrazo <= 40.0f && banderaMarius == 0 && MariusContador == 0) {
				model = glm::translate(model, glm::vec3(1.7f, -1.6f, -0.45f));
				model = glm::rotate(model, -50 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
				model = glm::rotate(model, -180 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
				model = glm::rotate(model, -MariusBrazo * 25 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
				glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
				BolaHelado_Suelta_M.RenderModel();//azul
			}
			else if (MariusBrazo <= 40.0f && banderaMarius == 0 && MariusContador == 1) {
				model = glm::translate(model, glm::vec3(1.7f, -1.6f, -0.45f));
				model = glm::rotate(model, -50 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
				model = glm::rotate(model, -180 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
				model = glm::rotate(model, -MariusBrazo * 25 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
				glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
				BolaHelado_Suelta_Morada_M.RenderModel();//morada
			}
			else if (MariusBrazo <= 40.0f && banderaMarius == 0 && MariusContador == 2) {
				model = glm::translate(model, glm::vec3(1.7f, -1.6f, -0.45f));
				model = glm::rotate(model, -50 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
				model = glm::rotate(model, -180 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
				model = glm::rotate(model, -MariusBrazo * 25 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
				glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
				BolaHelado_Suelta_Naranja_M.RenderModel();//naranja
			}
			//Para aparecer las bolas en el cono
			if (helado1 == 1) {
				model = glm::mat4(1.0);
				model = glm::translate(model, glm::vec3(66.5f, 0.0f, 24.0f));
				glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
				BolaHelado_Izquierda_M.RenderModel();//primera bola
			}
			if (helado2 == 1) {
				model = glm::mat4(1.0);
				model = glm::translate(model, glm::vec3(66.5f, 0.0f, 24.0f));
				glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
				BolaHelado_Derecha_M.RenderModel();//segunda bola
			}
			if (helado3 == 1) {
				model = glm::mat4(1.0);
				model = glm::translate(model, glm::vec3(66.5f, 0.0f, 24.0f));
				glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
				BolaHelado_Arriba_M.RenderModel();//tercera bola
			}
		}
		else contadorInicioPrograma2++;

		//Sigwinne Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(74.0f, 0.0f, 25.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Sigwinne_Genshin_M.RenderModel();

		//Lámpara Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(54.0f, 0.0f, -1.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara_Genshin_M.RenderModel();

		// --------------------------------------
		// --------BANCA PUESTO HELADOS----------
		// --------------------------------------

		//Wriothesley Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(105.0f, 0.0f, 25.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Wriothesley_Genshin_M.RenderModel();
		
		//Basura Honkai Star Rail
		model = glm::translate(model, glm::vec3(12.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bote_StarRail_M.RenderModel();

		//Lámpara Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(105.0f, 0.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara_Genshin_M.RenderModel();

		//Globo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(105.0f, 0.0f, 15.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Enojado_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(104.0f, 0.0f, 17.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Feliz_M.RenderModel();

		// --------------------------------------
		// -----------PUESTO DE DARDOS-----------
		// --------------------------------------

		Material_Madera.UseMaterial(uniformSpecularIntensity, uniformShininess);

		//Puesto Dardos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(110.0f, 0.0f, -25.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PuestoDardos_M.RenderModel();

		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);

		if (camaraAnimacion != 5) {
			//Globo1
			Globo1_M.RenderModel();

			//Globo2
			Globo2_M.RenderModel();

			//Globo3
			Globo3_M.RenderModel();
		}

		//Gato Verde
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(98.0f, 5.66f, -17.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Gato_Verde_M.RenderModel();

		//Firefly Honkai Star Rail
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(100.0f, 0.0f, -15.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Firefly_StarRail_M.RenderModel();

		//Luke Normal Tears of Themis
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(100.0f, 0.0f, -38.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		LukeNormal_M.RenderModel();

		//Globos izquierda
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(102.0f, 0.0f, -43.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(100.0f, 0.0f, -45.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(102.0f, 0.0f, -47.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		//Globos derecha
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(102.0f, 0.0f, -6.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(100.0f, 0.0f, -4.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(102.0f, 0.0f, -2.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		// --------------------------------------
		// ---------------CARRUSEL---------------
		// --------------------------------------

		//Base no movible Carrusel
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.0f, 0.0f, -65.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Carrusel_Base_M.RenderModel();

		//Carrusel
		Carrusel_M.RenderModel();

		//Lyney Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(69.0f, 0.0f, -65.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lyney_M.RenderModel();

		//Basura Honkai Star Rail
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(40.0f, 0.0f, -33.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bote_StarRail_M.RenderModel();

		// --------------------------------------
		// -------------BAÑO DARDOS--------------
		// --------------------------------------
		
		//Baño
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(105.0f, 0.0f, -85.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bano_M.RenderModel();

		//Baño
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(105.0f, 0.0f, -78.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bano_M.RenderModel();

		//Gato Kafka
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(105.0f, 11.9f, -78.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Gato_Kafka_M.RenderModel();

		//Marius Chino Tears of Themis
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(105.0f, 0.0f, -70.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		MariusChino_M.RenderModel();

		//Basura Honkai Star Rail
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(104.0f, 0.0f, -98.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bote_StarRail_M.RenderModel();

		//Lámpara Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(108.0f, 0.0f, -110.0f));
		model = glm::rotate(model, 20 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara_Genshin_M.RenderModel();

		// --------------------------------------
		// -----------PUESTO HOT DOGS------------
		// --------------------------------------

		//Puesto Hot Dogs
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(85.0f, 0.0f, -123.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PuestoHotDog_M.RenderModel();

		//Vyn Normal Tears of Themis
		VynNormal_M.RenderModel();

		//Jean Genshin Impact
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 7.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Jean_Genshin_M.RenderModel();

		//Globo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(100.0f, 0.0f, -119.0f));
		model = glm::rotate(model, -15 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Enojado_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(101.0f, 0.0f, -117.0f));
		model = glm::rotate(model, -15 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Feliz_M.RenderModel();

		// --------------------------------------
		// --------BANCA PUESTO HOTDOGS----------
		// --------------------------------------

		//Klee Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(55.0f, 0.0f, -120.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Klee_Genshin_M.RenderModel();

		//Lámpara Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(43.0f, 0.0f, -127.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara_Genshin_M.RenderModel();

		//Globos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(40.0f, 0.0f, -125.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(42.0f, 0.0f, -123.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(44.0f, 0.0f, -125.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		// --------------------------------------
		// -------BANCA PUESTO PALOMITAS---------
		// --------------------------------------

		//Sunday Honkai Star Rail
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-62.0f, 0.0f, -120.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Sunday_StarRail_M.RenderModel();

		//Lámpara Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.0f, 0.0f, -127.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara_Genshin_M.RenderModel();

		//Lámpara Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-115.0f, 0.0f, -110.0f));
		model = glm::rotate(model, -200 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara_Genshin_M.RenderModel();

		//Basura Honkai Star Rail
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-77.0f, 0.0f, -120.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bote_StarRail_M.RenderModel();

		//Globos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-46.0f, 0.0f, -125.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-44.0f, 0.0f, -123.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-42.0f, 0.0f, -125.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		// --------------------------------------
		// ----------ARTEM PROTAGONISTA----------
		// --------------------------------------
		
		//Artem Normal (cuerpo) Tears of Themis
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-10.0f, 0.0f, -55.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		ArtemNormalCuerpo_M.RenderModel();

		if (contadorInicioPrograma3 == 1) {
			
			//Artem brazo
			if (banderaArtem == 0 && ArtemBrazo > -35.0f) {
				ArtemBrazo -= 0.2f * deltaTime;
			}
			else if (ArtemBrazo < 0.0f) {
				ArtemBrazo += 0.2f * deltaTime;
				banderaArtem = 1;
			}
			else banderaArtem = 0;
						
			model = glm::translate(model, glm::vec3(-0.65f, 7.613f, 0.27f));
			model = glm::rotate(model, ArtemBrazo * toRadians, glm::vec3(0.0f, 1.0f, 0.0f)); //-35
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			ArtemNormalBrazo_M.RenderModel();

			//Hoja Libro
			if (ArtemHoja > -60.0f && banderaArtem == 0) {
				model = glm::mat4(1.0); //hoja izquierda
				model = glm::translate(model, glm::vec3(-9.84f, 6.7f, -56.41f));
				model = glm::rotate(model, ArtemHoja * toRadians, glm::vec3(0.0f, 0.0f, 1.0f)); //-60
				glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
				ArtemNormalHoja_M.RenderModel();
				ArtemHoja -= 0.62f * deltaTime;
			}
			else if (ArtemHoja2 < 58.0f && banderaArtem == 0) {
				model = glm::mat4(1.0);
				model = glm::translate(model, glm::vec3(-9.8f, 6.7f, -56.41f));
				model = glm::rotate(model, (73 - ArtemHoja2) * toRadians, glm::vec3(0.0f, 0.0f, 1.0f)); //5
				model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
				glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
				ArtemNormalHoja_M.RenderModel();
				ArtemHoja2 += 0.73f * deltaTime;
			}
			else {
				ArtemHoja = 0.0f;
				ArtemHoja2 = 0.0f;
			}
		}
		else contadorInicioPrograma3++;

		//Globos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-8.0f, 0.0f, -50.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Feliz_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(8.0f, 0.0f, -50.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Feliz_M.RenderModel();

		// --------------------------------------
		// ----------PUESTO PALOMITAS------------
		// --------------------------------------

		//Puesto de Palomitas
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-92.0f, 0.0f, -117.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PuestoPalomitas_M.RenderModel();

		//Feixiao Honkai Star Rail
		Feixiao_StarRail_M.RenderModel();

		//Gato DanHeng
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-94.0f, 9.17f, -121.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Gato_DanHeng_M.RenderModel();

		//Globos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-106.0f, 0.0f, -117.0f));
		model = glm::rotate(model, 15 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-108.0f, 0.0f, -115.0f));
		model = glm::rotate(model, 15 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		// --------------------------------------
		// ----------PUESTO TIRO DADOS-----------
		// --------------------------------------

		Material_Terciopelo.UseMaterial(uniformSpecularIntensity, uniformShininess);

		//Puesto de Tiro de Dados
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-113.0f, 0.0f, -35.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		MesaDados_M.RenderModel();

		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);

		//Aventurine Honkai Star Rail
		Aventurine_StarRail_M.RenderModel();

		//Lámpara Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-120.0f, 0.0f, -20.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara_Genshin_M.RenderModel();

		//Globos Izquierda
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-104.0f, 0.0f, -57.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-103.0f, 0.0f, -55.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-104.0f, 0.0f, -53.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		//Globos Derecha
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-104.0f, 0.0f, -22.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-103.0f, 0.0f, -20.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-104.0f, 0.0f, -18.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		// --------------------------------------
		// -----------PUESTO BOLICHE-------------
		// --------------------------------------
		
		Material_MaderaPulida.UseMaterial(uniformSpecularIntensity, uniformShininess);

		//Puesto Boliche
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-60.0f, 0.0f, 93.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Boliche_M.RenderModel();

		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);

		if (camaraAnimacion != 2) {
			//Rendija Boliche
			Rendija_Boliche_M.RenderModel();
		}

		//Ayato Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, 0.0f, 83.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Ayato_Genshin_M.RenderModel();

		//Lámpara Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-33.0f, 0.0f, 84.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara_Genshin_M.RenderModel();

		//Globos Izquierda
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-41.0f, 0.0f, 89.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-39.0f, 0.0f, 87.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-37.0f, 0.0f, 89.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		//Globos Derecha
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-81.0f, 0.0f, 89.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-79.0f, 0.0f, 87.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-77.0f, 0.0f, 89.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		// --------------------------------------
		// -----------GOLPEAR AL TOPO------------
		// --------------------------------------

		Material_Plastico.UseMaterial(uniformSpecularIntensity, uniformShininess);

		//Puesto Golpear al Topo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(65.0f, 0.0f, 70.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		GolpearTopo_M.RenderModel();

		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);

		//Yanqing Honkai Star Rail
		model = glm::translate(model, glm::vec3(-3.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Yanqing_StarRail_M.RenderModel();

		//Topos Izquierda
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(65.0f, 0.0f + ToposY1, 70.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		GolpearTopo_Topos1_M.RenderModel();

		//Topos Derecha
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(65.0f, 0.0f + ToposY2, 70.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		GolpearTopo_Topos2_M.RenderModel();

		//Lámpara Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(49.5f, 0.0f, 80.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara_Genshin_M.RenderModel();

		// --------------------------------------
		// ----------ALGODÓN DE AZÚCAR-----------
		// --------------------------------------

		//Puesto de Algodón de Azúcar
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(30.0f, 0.0f, 70.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		MaquinaAlgodon_M.RenderModel();

		//Robin Honkai Star Rail
		model = glm::translate(model, glm::vec3(6.0f, 0.0f, 19.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Robin_StarRail_M.RenderModel();

		//Globos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(49.0f, 0.0f, 76.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(48.0f, 0.0f, 74.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(47.0f, 0.0f, 76.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		// --------------------------------------
		// -----------CARROS CHOCONES------------
		// --------------------------------------

		//Puesto de Carros Chocones
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 4.0f, -125.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CarrosChocones_M.RenderModel();

		//Artem Casual Tears of Themis
		ArtemCasual_Themis_M.RenderModel();

		//Carro Azul
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(12.0f, 5.0f, -150.0f));
		model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Carro_Azul_M.RenderModel();

		//Carro Naranja
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(18.0f, 5.0f, -170.0f));
		model = glm::rotate(model, -20 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Carro_Naranja_M.RenderModel();

		// --------------------------------------
		// ------------BAÑO BOLICHE--------------
		// --------------------------------------

		//Baño
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-100.0f, 0.0f, 93.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bano_M.RenderModel();

		//Baño
		model = glm::translate(model, glm::vec3(-7.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bano_M.RenderModel();

		//Gato Clara
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-100.0f, 11.9f, 93.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Gato_Clara_M.RenderModel();

		//Ratio Star Rail
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-110.0f, 0.0f, 90.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Ratio_StarTail_M.RenderModel();

		//Lámpara Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-120.0f, 0.0f, 80.0f));
		model = glm::rotate(model, -160 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara_Genshin_M.RenderModel();

		//Globos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-123.0f, 0.0f, 79.0f));
		model = glm::rotate(model, 75 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Verde_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-121.0f, 0.0f, 76.0f));
		model = glm::rotate(model, 75 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Naranja_M.RenderModel();

		// --------------------------------------
		// ---------PUESTO DE TICKETS------------
		// --------------------------------------

		//Puesto de Tickets
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(73.0f, 0.0f, 110.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PuestoTickets_M.RenderModel();

		//Pom Pom Star Rail
		PomPom_M.RenderModel();

		//Gato Blade
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(73.0f, 7.8f, 113.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Gato_Blade_M.RenderModel();

		//Lámpara Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(67.0f, 0.0f, 105.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara_Genshin_M.RenderModel();

		//Globo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(78.0f, 0.0f, 110.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Enojado_M.RenderModel();

		//Globo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(67.0f, 0.0f, 109.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Enojado_M.RenderModel();

		// --------------------------------------
		// -----------BANCA BOLICHE--------------
		// --------------------------------------
		
		//Banca Boliche
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-115.0f, 0.0f, 60.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Banca_Genshin_M.RenderModel();

		//Vyn Chino Tears of Themis
		model = glm::translate(model, glm::vec3(10.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		VynChino_Themis_M.RenderModel();

		//Gato Basura
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-114.6f, 2.66f, 62.5f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Gato_Basura_M.RenderModel();

		// --------------------------------------
		// ------------PUESTO TACOS--------------
		// --------------------------------------

		//Puesto Tacos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-115.0f, 0.0f, 8.5f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PuestoTacos_M.RenderModel();

		//Herta Honkai Star Rail
		Herta_StarTail_M.RenderModel();

		//Xiao Genshin Impact
		Xiao_Genshin_M.RenderModel();

		//Basura Honkai Star Rail
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-115.0f, 0.0f, 32.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bote_StarRail_M.RenderModel();

		// --------------------------------------
		// ------------PUESTO INAZUMA------------
		// --------------------------------------

		//Puesto de Comida de Inazuma
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-60.0f, 0.0f, 20.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PuestoInazuma_M.RenderModel();

		//Ixbalanque Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-63.0f, 0.0f, 8.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Ixbalanque_M.RenderModel();

		//Lámpara Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-55.0f, 0.0f, -13.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Lampara_Genshin_M.RenderModel();

		//Gato Naranja
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-58.5f, 0.0f, -14.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Gato_Naranja_M.RenderModel();

		//Globos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-60.0f, 0.0f, 10.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Enojado_M.RenderModel();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-59.0f, 0.0f, 8.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Globo_Feliz_M.RenderModel();

		// --------------------------------------
		// ------------DECORACIONES--------------
		// --------------------------------------

		//Gato RuanMei
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(4.0f, 0.0f, 84.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Gato_RuanMei_M.RenderModel();

		//Plataforma Dodoco
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-43.0f, 0.5f, -65.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Plataforma_Genshin_M.RenderModel();

		//Mesa de comida
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -45.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		MesaComida.RenderModel();

		//Leche de Dango
		LecheDango.RenderModel();

		//Stand de madera en los Dardos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(93.0f, 0.0f, -14.0f));
		model = glm::rotate(model, -80 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Stand_Dardos_M.RenderModel();

		//Stand de madera en los Hot Dogs
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(93.0f, 0.0f, -115.0f));
		model = glm::rotate(model, -15 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Stand_HotDog_M.RenderModel();
		
		//Stand de madera en la taquilla
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(67.0f, 0.0f, 113.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Stand_Taquilla_M.RenderModel();

		//Stand de madera en el carrusel
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(68.0f, 0.0f, -58.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Stand_Carrusel_M.RenderModel();

		//Stand de madera en el carros
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-24.0f, 0.0f, -118.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Stand_Carros_M.RenderModel();

		//Stand de madera en el de topos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(55.0f, 0.0f, 66.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Stand_Topos_M.RenderModel();

		//Stand de madera en dados
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-102.0f, 0.0f, -46.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Stand_Dados_M.RenderModel();

		//Stand de madera en puesto inazuma
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-66.0f, 0.0f, 28.0f));
		model = glm::rotate(model, -105 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Stand_Comida_M.RenderModel();

		//Gato Herta
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-27.0f, 0.0f, -116.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Gato_Herta_M.RenderModel();
		
		// --------------------------------------
		// -------------PISO CAMINO--------------
		// --------------------------------------

		//Derecha
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(80.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

		caminoTexture.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[2]->RenderMesh();

		//Centro
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[3]->RenderMesh();

		//Izquierda
		model = glm::translate(model, glm::vec3(-84.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[3]->RenderMesh();

		//Frente
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -99.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[4]->RenderMesh();

		//Detrás
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 49.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[4]->RenderMesh();

		// --------------------------------------
		// ----------BLADE JERARQUICO------------
		// --------------------------------------

		Material_Avatar.UseMaterial(uniformSpecularIntensity, uniformShininess);

		// --------------------------------------
		// ----------BLADE JERARQUICO------------
		// --------------------------------------

		if (mainWindow.getAvanzaBlade() == 1) {

			angulovaria += 2.2f * deltaTime;
			angulovariaAux += 2.2f * deltaTime;
			if (sin(glm::radians(angulovariaAux)) > 0) {
				angulovaria2 = 0.0f;
			}
			else {
				angulovaria2 = angulovariaAux;
			}
			if (sin(glm::radians(angulovariaAux)) < 0) {
				angulovaria3 = 0.0f;
			}
			else {
				angulovaria3 = -angulovariaAux;
			}
			//std::cout << "angulovaria = " << sin(glm::radians(angulovaria2)) << std::endl;

		}

		if ((sin(glm::radians(angulovaria)) > 0.1 && mainWindow.getAvanzaBlade() == 0) || (sin(glm::radians(angulovaria)) < -0.1 && mainWindow.getAvanzaBlade() == 0)) {
			angulovaria += 3.0f * deltaTime;
			angulovariaAux += 3.0f * deltaTime;
			if (sin(glm::radians(angulovariaAux)) > 0) {
				angulovaria2 = 0.0f;
			}
			else {
				angulovaria2 = angulovariaAux;
			}
			if (sin(glm::radians(angulovariaAux)) < 0) {
				angulovaria3 = 0.0f;
			}
			else {
				angulovaria3 = -angulovariaAux;
			}
			//std::cout << "angulovaria = " << sin(glm::radians(angulovaria)) << std::endl;
		}

		// Variables persistentes (deberían estar fuera del loop si no lo están ya)

		float bladeSpeed = 0.3f;

		// En el render loop o función de actualización:

		// 1. Dirección de la cámara (sin componente Y para que no suba/baje el personaje)
		glm::vec3 cameraForward = glm::normalize(glm::vec3(camera.getCameraDirection().x, 0.0f, camera.getCameraDirection().z));
		glm::vec3 right = glm::normalize(glm::cross(cameraForward, glm::vec3(0.0f, 1.0f, 0.0f))); // vector a la derecha

		// 2. Rotación del personaje basada en la cámara
		float bladeAngle = atan2(cameraForward.x, cameraForward.z); // Yaw en radianes

		// 3. Movimiento si se presiona tecla
		if (mainWindow.getAvanzaBladeW() == 1) {
			bladePosition += cameraForward * bladeSpeed * deltaTime;
		}
		if (mainWindow.getAvanzaBladeA() == 1) {
			bladePosition -= right * bladeSpeed * deltaTime;
		}
		if (mainWindow.getAvanzaBladeS() == 1) {
			bladePosition -= cameraForward * bladeSpeed * deltaTime;
		}
		if (mainWindow.getAvanzaBladeD() == 1) {
			bladePosition += right * bladeSpeed * deltaTime;
		}

		// 4. Construcción de la matriz del personaje
		model = glm::mat4(1.0f);
		model = glm::translate(model, bladePosition);
		model = glm::rotate(model, bladeAngle, glm::vec3(0.0f, 1.0f, 0.0f)); // rotación en eje Y
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_Cuerpo.RenderModel();
		modelaux = model;

		// 5. Cámara que sigue al personaje desde atrás
		glm::vec3 cameraOffset = -cameraForward * 10.0f + glm::vec3(0.0f, 5.0f, 0.0f); // detrás y arriba
		glm::vec3 cameraPosition = bladePosition + cameraOffset;
		camera.setPosition(cameraPosition);

		glm::vec3 lookTarget = bladePosition + glm::vec3(0.0f, 2.0f, 0.0f); // mira al torso
		camera.setFront(glm::normalize(lookTarget - cameraPosition));

		//Cabeza 
		model = glm::translate(model, glm::vec3(0.0f, 1.552f, -0.207f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_Cabeza.RenderModel();

		//---Brazo derecho
		//Hombro Derecho
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.897f, 0.997f, -0.3f));
		model = glm::rotate(model, 42 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, 1.0f * sin(glm::radians(angulovaria)), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_HombroDer.RenderModel();

		//Antebrazo Derecho
		model = glm::translate(model, glm::vec3(-0.925f, -0.71f, 0.02f));
		model = glm::rotate(model, 0.5f * -sin(glm::radians(angulovaria2)), glm::vec3(0.0f, 0.0f, 1.0f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_AntebrazoDer.RenderModel();

		//Mano Derecha
		model = glm::translate(model, glm::vec3(-0.960f, -0.697f, 0.041f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_ManoDer.RenderModel();

		//---Brazo Izquierdo
		//Hombro Izquierdo
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.874f, 0.941f, -0.285f));
		model = glm::rotate(model, -42 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, 1.0f * -sin(glm::radians(angulovaria)), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_HombroIzq.RenderModel();

		//Antebrazo Izquierdo
		model = glm::translate(model, glm::vec3(0.939f, -0.616f, 0.005f));
		model = glm::rotate(model, 0.5f * sin(glm::radians(angulovaria3)), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_AntebrazoIzq.RenderModel();

		//Mano Izquierda
		model = glm::translate(model, glm::vec3(0.952f, -0.719f, 0.036f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_ManoIzq.RenderModel();

		//---Pierna Derecha
		//Pierna Derecha
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.424f, -1.452f, -0.12f));
		model = glm::rotate(model, 0.45f * -sin(glm::radians(angulovaria)), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_PiernaDer.RenderModel();

		model = glm::translate(model, glm::vec3(-0.062f, -1.991f, -0.106));
		model = glm::rotate(model, 0.5f * -sin(glm::radians(angulovaria3)), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_PantorrillaDer.RenderModel();

		model = glm::translate(model, glm::vec3(-0.047f, -2.442f, 0.031f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_PieDer.RenderModel();

		//---Pierna Izquierda
		//Pierna Izquierda
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.417f, -1.458f, -0.107f));
		model = glm::rotate(model, 0.45f * sin(glm::radians(angulovaria)), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_PiernaIzq.RenderModel();

		model = glm::translate(model, glm::vec3(0.061f, -1.974f, -0.119f));
		model = glm::rotate(model, 0.5f * -sin(glm::radians(angulovaria2)), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_PantorrillaIzq.RenderModel();

		model = glm::translate(model, glm::vec3(0.046f, -2.434f, -0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Blade_PieIzq.RenderModel();

		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);

		// --------------------------------------
		// -----------BOTE CAMINANTE-------------
		// --------------------------------------

		if (contadorInicioPrograma4 == 1) {

			Bangulovaria += 2.2f * deltaTime;
			BanguloAvanza += 0.2f * deltaTime;
			BangulovariaAux += 2.2f * deltaTime;
			if (sin(glm::radians(BangulovariaAux)) > 0) {
				Bangulovaria2 = 0.0f;
			}
			else {
				Bangulovaria2 = BangulovariaAux;
			}
			if (sin(glm::radians(BangulovariaAux)) < 0) {
				Bangulovaria3 = 0.0f;
			}
			else {
				Bangulovaria3 = -BangulovariaAux;
			}
			float senoActual = sin(glm::radians(BanguloAvanza));

			if (senoActual >= 1.0f - epsilon && !yaCambio) {
				BanguloMira = 180.0f;  // Mira hacia un lado
				yaCambio = true;
			}
			else if (senoActual <= -1.0f + epsilon && !yaCambio) {
				BanguloMira = 00.0f; // Mira al otro, je 
				yaCambio = true;
			}
			else if (senoActual < 1.0f - epsilon && senoActual > -1.0f + epsilon) {
				yaCambio = false;
			}
			senoAnterior = senoActual;
			//std::cout << "BanguloAvanza = " << sin(glm::radians(BanguloAvanza)) << std::endl;

			// 4. Construcción de la matriz del personaje
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(-80.0f, 4.033f, -35.0f + (25 * sin(glm::radians(BanguloAvanza)))));
			//model = glm::translate(model, glm::vec3(73.0f, 4.033f, 118.0f+(10*sin(glm::radians(BanguloAvanza)))));
			model = glm::rotate(model, BanguloMira * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			Bote_Cuerpo.RenderModel();
			modelaux = model;

			//---Brazo Izquierdo
			//Hombro Izquierdo
			model = modelaux;
			model = glm::translate(model, glm::vec3(1.091f, 0.662f, -0.107f));
			model = glm::rotate(model, 1.0f * -sin(glm::radians(Bangulovaria3)), glm::vec3(0.0f, 0.0f, 1.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			Bote_HombroIzq.RenderModel();
			//Antebrazo Izquierdo
			model = glm::translate(model, glm::vec3(0.982f, 0.039f, -0.076f));
			model = glm::rotate(model, 1.5f * sin(glm::radians(Bangulovaria3)), glm::vec3(0.0f, 0.0f, 1.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			Bote_AntebrazoIzq.RenderModel();

			//---Pierna Derecha
			//Pierna Derecha
			model = modelaux;
			model = glm::translate(model, glm::vec3(-0.438f, -1.512f, -0.014));
			model = glm::rotate(model, 0.45f * -sin(glm::radians(Bangulovaria)), glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			Bote_PiernaDer.RenderModel();

			model = glm::translate(model, glm::vec3(-0.033f, -1.002f, 0.1f));
			model = glm::rotate(model, 0.5f * -sin(glm::radians(Bangulovaria3)), glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			Bote_PantorrillaDer.RenderModel();

			//---Pierna Izquierda
			//Pierna Izquierda
			model = modelaux;
			model = glm::translate(model, glm::vec3(0.439f, -1.532f, -0.014f));
			model = glm::rotate(model, 0.45f * sin(glm::radians(Bangulovaria)), glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			Bote_PiernaIzq.RenderModel();

			model = glm::translate(model, glm::vec3(0.033f, -0.972f, 0.1f));
			model = glm::rotate(model, 0.5f * -sin(glm::radians(Bangulovaria2)), glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			Bote_PantorrillaIzq.RenderModel();
		}
		else contadorInicioPrograma4++;

		//-----------------¡¡TRANSPARENCIAS!!---------------------------------

		// --------------------------------------
		// ----------LANZAMIENTO HACHA-----------
		// --------------------------------------


		// --------------------------------------
		// -----------JAULA DE BATEO-------------
		// --------------------------------------

		//Wanderer Genshin Impact
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-105.0f, 0.0f, -90.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Wanderer_Genshin_M.RenderModel();

		//Luke Casual Tears of Themis
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 85.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		LukeCasual_Themis_M.RenderModel();

		//Basura Honkai Star Rail
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(16.0f, 0.0f, 80.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bote_StarRail_M.RenderModel();

		//--------------------------------------------------------------------

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		Material_Reja.UseMaterial(uniformSpecularIntensity, uniformShininess);

		//Puesto de Lanzamiento de Hacha
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-105.0f, 0.0f, -78.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		LanzamientoHacha_M.RenderModel();

		//Jaula Bateo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 85.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PuestoBateo_M.RenderModel();

		//------
		//REJAS-
		//------

		//Derecha
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(130.0f, 0.0f, 0.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

		rejaTexture.UseTexture();
		Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		//Detrás
		model = glm::translate(model, glm::vec3(11.45f, 0.0f, -11.45));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		//Izquierda
		model = glm::translate(model, glm::vec3(11.45f, 0.0f, -11.45));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		//Frente
		model = glm::translate(model, glm::vec3(11.45f, 0.0f, -11.45));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(45.8f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		//Derecha
		model = glm::translate(model, glm::vec3(11.45f, 0.0f, -11.45));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		model = glm::translate(model, glm::vec3(22.9f, 0.0f, 0.01f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[1]->RenderMesh();

		glDisable(GL_BLEND);


		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}
