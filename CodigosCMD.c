#include <stdio.h>
#include <stdlib.h>

void imprimir(void);
int ingresar(void);

void activator (void);
void red (void);
void imp (void);
void disk (void);
void oracle (void);

int main(void) {
	
	void (*p[5])(void) = {activator, red, imp, disk, oracle};
	
	int valor; 
	
	do {
		system("cls"); 
		
		imprimir();
		valor = ingresar(); 
		
		if (valor > 0) {
			p[valor - 1]();
		}
		
	} while (valor != 0);
	
	printf("\nSaliendo del sistema...\n");
	return 0;
}

void imprimir(void){
	
	printf("¿Qué comando para CMD necesitas?\n\n");
	
	printf("|1| Activador de Windows - Office\n");
	printf("|2| Reiniciar ajustes de red\n");
	printf("|3| Borrar cola de la impresora\n");
	printf("|4| Escanear el disco en busca de errores\n");
	printf("|5| Modifica el idioma del oracle\n");
	printf("|0| Salir\n\n");
}
	
int ingresar(void) {
	
	int var;
	
	do {
		printf("Ingrese un numero: ");
		scanf("%d", &var);
		
		if (var == 0)
			exit(1);
		
	} while(var < 0 || var > 5);
	
	return var;
}

void esperar_enter(void) {
	
	printf("\nPresione ENTER para continuar al siguiente paso...");

	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }

	getchar(); 
}

void activator (void){
	
	system("powershell -Command \"irm https://get.activated.win | iex\"");
	
}

void red (void){
	
	system("netsh winsock reset");
	
	system("netsh int ip reset");
	
	system("ipconfig /release");
	
	system("ipconfig /renew");
	
	system("ipconfig /flushdns");
	
	system("ipconfig /registerdns");
}

void imp (void){
	
	system("net stop spooler");
	
	printf("\nBuscar en system32 la carpeta spool - printers; Y borras todo.\n");
	esperar_enter();
	
	system("net start spooler");
}

void disk (void){
	
	system("DISM /online /cleanup-image /checkhealth");
	system("DISM /online /cleanup-image /scanhealth");
	system("dism /online /Cleanup-Image /RestoreHealth");
	system("sfc /scannow");
	
}

void oracle (void){
	
	const char *comando = "reg add \"HKLM\\SOFTWARE\\WOW6432Node\\ORACLE\\KEY_OraClient11g_home1\" "
		"/v \"NLS_LANG\" "
		"/t REG_SZ "
		"/d \"AMERICAN_AMERICA.WE8MSWIN1252\" "
		"/f";
	
	int resultado = system(comando);
	
	if (resultado == 0) {
		printf("[EXITO] El registro fue modificado correctamente.\n");
	} else {
		printf("[ERROR] Fallo el comando. Posibles causas:\n");
		printf(" 1. No ejecutaste como ADMINISTRADOR (Error de Acceso).\n");
		printf(" 2. La ruta del registro no existe.\n");
	}
}
