#include <stdio.h>
#include <stdlib.h>

void imprimir(void);
int ingresar(void);

void activator (void);
void red (void);
void imp (void);
void disk (void);

int main(void) {
	
	void (*p[5])(void) = {activator, red, imp, disk};
	
	imprimir();
	int valor = ingresar();
	
	p[valor - 1]();
	
	return 0;
}

void imprimir(void){
	
	printf("¿Qué comando para CMD necesitas?\n\n");
	
	printf("|1| Activador de Windows - Office\n");
	printf("|2| Reiniciar ajustes de red\n");
	printf("|3| Borrar cola de la impresora\n");
	printf("|4| Escanear el disco en busca de errores\n");
	printf("|0| Salir\n\n");
}
	
int ingresar(void) {
	
	int var;
	
	do {
		printf("Ingrese un numero: ");
		scanf("%d", &var);
		
		if (var == 0)
			exit(1);
		
	} while(var < 0 || var > 4);
	
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
