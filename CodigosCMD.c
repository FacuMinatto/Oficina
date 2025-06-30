#include <stdio.h>

int var;

int main() {
    printf("    \n¿Qué comando para CMD necesitas?\n\n");
    printf("    |1| Activador de Windows - Office\n");
    printf("    |2| Reiniciar ajustes de red\n");
    printf("    |3| Borrar cola de la impresora\n");
    printf("    |4| Actualizar aplicaciones de terceros\n");
    printf("    |5| Escanear el disco en busca de errores\n\n");

    // Pedir opcion valida
    do {
        
        scanf("%d", &var);

        if (var < 1 || var > 5) 
            printf("Ingrese un numero valido.\n");

    } while (var < 1 || var > 5); // Acepta solo entre 1 y 5 inclusive

    switch (var) {
        case 1:
			printf("\n(En powershell)\n");
            printf("\nirm https://get.activated.win | iex \n");
            break;

        case 2:
			printf("\nnetsh winsock reset");
			printf("\nnetsh int ip reset");
			printf("\nipconfig /release");
			printf("\nipconfig /renew");
			printf("\nipconfig /flushdns");
			printf("\nipconfig /registerdns");
            break;

        case 3:
            printf("\nnet stop spooler\n");
			printf("\n(Busca la carpeta system32 - spool - printers).\n");
			printf("\n(Borra lo que haya dentro).\n");
			printf("\nnet start spooler\n");
            break;

        case 4:
            printf("\n(En powershell)\n");
			printf("\nwinget update");
			printf("\nWINGET UPDATE --ALL");
            break;

        case 5:
			printf("\nDISM /online /cleanup-image /checkhealth\n");
			printf("DISM /online /cleanup-image /scanhealth\n");
			printf("dism /online /Cleanup-Image /RestoreHealth\n");
			printf("sfc /scannow\n");
            break;
    }

	printf("\nPresiona Enter para salir...");
	getchar();  // Consumir el '\n' pendiente de scanf
	getchar(); 
	
    return 0;
}
