#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
int getString(char* bufferString,int limite);
static int getFloat(float*pBuffer);
static int isFloat(char* pBuffer);
static int getInt(int*pBuffer);
static int isInt(char *pBuffer);
static int isLetras(char*pBuffer);

int utn_getEntero(int*pEdad,int reintentos,char* msg,char*msgError,int max,int min);

int utn_mostrarArray(int * pArray,int limite);

int utn_calcularNumeroMaximo(int *pArray,int limite,int *maximo);

int utn_initArray(int * pArray,int limite,int valor);


int utn_verificarNumeroEntero(int *pEntero,char* texto,char* textoError);

int utn_verificarNumeroFloat(float *pEntero,char* texto,char* textoError);

int utn_verificarNumeroChar(char *pChar,char* texto,char* textoError);

int utn_cargaNumeroAleatoriosEnArrays(int* pArray,int len,int min, int max);


int utn_promedioArray(int*pArray,int limite,float *promedio,int valorOmision);


int utn_ordenarArray(int *pArray,int limite,int flagMaxMin);
int utn_getFloat(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max);
int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);
int ordenarInsertion(int* pArray,int limite);
int utn_getCuit(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);
int isCuit(char* pBuffer);





#endif // UTN_H_INCLUDED
