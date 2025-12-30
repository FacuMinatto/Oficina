#include <stdio.h>
#include <stdlib.h>

void imprimir(void);
int ingresar(void);

void activator (void);
void red (void);
void imp (void);
void disk (void);
void oracle (void);
void d_oracle (void);		
void pdf24 (void);

int main(void) {
	
	void (*p[7])(void) = { activator, red, imp, disk, d_oracle, oracle, pdf24 };
	
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
	
	system("color 97");
	
	printf("¿Qué herramienta necesitas?\n\n");
	
	printf("|1| Activador de Windows - Office\n");
	printf("|2| Reiniciar ajustes de red\n");
	printf("|3| Borrar cola de la impresora\n");
	printf("|4| Escanear el disco en busca de errores\n");
	printf("|5| Descargar Oracle\n");
	printf("|6| Modifica el idioma del oracle\n");
	printf("|7| Descargar PDF24\n");
	printf("|0| Salir\n\n");
}
	
int ingresar(void) {
	
	int var;
	
	do {
		printf("Ingrese un número: ");
		scanf("%d", &var);
		printf("\n");
		
		if (var == 0)
			exit(1);
		
	} while(var < 0 || var > 7);
	
	return var;
}

void esperar_enter(void) {
	
	printf("\nPresione ENTER para continuar...");

	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }

	getchar(); 
}

void activator (void){
	
	system("powershell -Command \"irm https://get.activated.win | iex\"");
	
	esperar_enter();
}

void red (void){
	
	system("cls");
	system("netsh winsock reset");
	system("netsh int ip reset");
	system("ipconfig /release");
	system("ipconfig /renew");
	system("ipconfig /flushdns");
	system("ipconfig /registerdns");
	
	esperar_enter();
}

void imp (void){
	
	system("cls");
	system("net stop spooler");
	
	printf("Buscar en system32 la carpeta spool - printers; Y borras todo.\n");
	
	esperar_enter();
	system("net start spooler");
}

void disk (void){
	
	system("cls");
	system("DISM /online /cleanup-image /checkhealth");
	system("DISM /online /cleanup-image /scanhealth");
	system("dism /online /Cleanup-Image /RestoreHealth");
	system("sfc /scannow");
	esperar_enter();
	
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
	
	esperar_enter();
}

void d_oracle (void){
	
	system("cls");
	
	int var;
	
	do {
	 
	printf("¿Qué versión quieres descargar?\n");
	printf("|1| Oracle 9\n");
	printf("|2| oracle 11\n");
	scanf("%d", &var);
	 
	} while (var < 1 && var > 2);
	
	
	if (var == 1){
		
		char *url2 = "https://download844.mediafire.com/9l6lj064xnvgP2agzEF_WE9b-R2aoIj3pSe0SvkgKovJm4iXdSFGzw6TbxSrtV5Hb1Mf23WWPcT21dIec0B9n2P-2wQm-uqXAgHKEP87aif0vRvP0SJm9ZKsoZKITeuSTyhMaa-HE_PWKJIq91Ln14o7EG-MnKt1mky6I9eHyEQ9G0Y/lqheiw04xqwcq2y/ORACLE+9.rar";
		char *nombre_archivo2 = "Oracle 9.rar";
		char comando2[1024];
		
		sprintf(comando2, "curl -L -o \"%s\" \"%s\"", nombre_archivo2, url2);
		
		printf("Iniciando descarga...\n");
		printf("Informacion: %% Descarga | Total | Recibido | Velocidad | Tiempo Restante\n\n");
		
		int resultado = system(comando2);
		
		printf("\n\n"); 
		
		if (resultado == 0) {
			printf("[EXITO] Archivo guardado como: %s\n", nombre_archivo2);
			printf("Se guardo el archivo al lado del ejecutable.\n");
		} else {
			printf("[ERROR] No se pudo descargar. Verifica tu internet o el enlace.\n");
		}
		
		esperar_enter();
	}
	
	
	else if (var == 2){
		
		char *url = "https://download937.mediafire.com/tbvmsvdysflgMXDrECyU3E8abjvo82sg04tVexPwistcnwJvpoJxovwJYD2kAq3-PFZuBeK3ZovCjufAORsEQDV--5elTzSRQBY9brAkTkXopkmw7jWbaOuQZXPbo7atTyIJEwhyPVATOATkEufeM1OcdMImG3CPjf_rqEtl9HEPhd4/wqmztfd0y89xz0g/ORACLE+11.rar";
		char *nombre_archivo = "Oracle 11.rar";
		char comando[1024];
		
		sprintf(comando, "curl -L -o \"%s\" \"%s\"", nombre_archivo, url);
		
		printf("Iniciando descarga...\n");
		printf("Informacion: %% Descarga | Total | Recibido | Velocidad | Tiempo Restante\n\n");
		
		int resultado = system(comando);
		
		printf("\n\n"); 
		
		if (resultado == 0) {
			printf("[EXITO] Archivo guardado como: %s\n", nombre_archivo);
			printf("Se guardo el archivo al lado del ejecutable.\n");
		} else {
			printf("[ERROR] No se pudo descargar. Verifica tu internet o el enlace.\n");
		}
		
		esperar_enter();
	}
}
	
void pdf24 (void){
	
	system("cls");
	
	char *url = "https://download1500.mediafire.com/leezzk4wyrognp6DMfzEQbry6sChvsLqRPEAQxdxU7iOgJsEbFV3r1itY9kzMY2JBrzQKyVc60Jw_-x3HaHvhz6r5RNjra3sgOYY_dwg6I0yo-kM9BcgQzQAPB2dMcSDVYJ-XNYOQ4LJ5uYzP0PBv44ozdaf6K1jpgFXFdcPEDCzsA/jlpbhxnevt2gce7/pdf24-creator-11.0.1.msi";
	char *nombre_archivo = "Pdf24 - 11.0.1.msi";
	char comando[1024];
	
	sprintf(comando, "curl -L -o \"%s\" \"%s\"", nombre_archivo, url);
	
	printf("Iniciando descarga...\n");
	printf("Informacion: %% Descarga | Total | Recibido | Velocidad | Tiempo Restante\n\n");
	
	int resultado = system(comando);
	
	printf("\n\n"); 
	
	if (resultado == 0) {
		printf("[EXITO] Archivo guardado como: %s\n", nombre_archivo);
		printf("Se guardo el archivo al lado del ejecutable.\n");
	} else {
		printf("[ERROR] No se pudo descargar. Verifica tu internet o el enlace.\n");
	}
}
