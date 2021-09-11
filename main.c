#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void catalogo(){
	printf("\n----- Ingresa la clave de tu entidad federativa (LUGAR DONDE NACIO) -----\n");
    printf("AGUASCALIENTES [AS]\t\t");
    printf("BAJA CALIFORNIA [BC]\t\t");
    printf("BAJA CALIFORNIA SUR [BS]\n");
    printf("CAMPECHE [CC]\t\t");
    printf("COAHUILA [CL]\t\t");
    printf("COLIMA [C]M\n");
    printf("CHIAPAS [CS]\t\t");
    printf("CHIHUAHUA [CH]\t\t");
    printf("DISTRITO FEDERAL [DF]\n");
    printf("DURANGO [DG]\t\t");
    printf("GUANAJUATO [GT]\t\t");
    printf("GUERRERO [GR]\n");
    printf("HIDALGO [HG]\t\t");
    printf("JALISCO [JC]\t\t");
    printf("MEXICO [MC]\n");
    printf("MICHOACAN [MN]\t\t");
    printf("MORELOS [MS]\t\t");
    printf("NAYARIT [NT]\n");
    printf("NUEVO LEON [NL]\t\t");
    printf("OAXACA [OC]\t\t");
    printf("PUEBLA [PL]\n");
    printf("QUERETARO [QT]\t\t");
    printf("QUINTANA ROO [QR]\t\t");
    printf("SAN LUIS POTOSI [SP]\n");
    printf("SINALOA [SL]\t\t");
    printf("SONORA [SR]\t\t");
    printf("TABASCO [TC]\n");
    printf("TAMAULIPAS [TS]\t\t");
    printf("TLAXCALA [TC]\t\t");
    printf("VERACRUZ [VZ]\n");
    printf("YUCATAN [YN]\t\t");
    printf("ZACATECAS [ZS]\t\t");
    printf("NACIDO EN EL EXTRANJERO [NE]\n");
}


int main(int argc, char *argv[]) {
	
	char nombre[25];
	char apellido[25];
	char fecha[15];
	char lugar[10];
	char sexo[1];
	char curp[15];
	int formato;
	 
	/**
	 * Se declaran las variables que se le piden al usuario.
	 * Ademas se agrega curp donde iremos formando nuestro curp.
	 */
	
    printf("Introduzca su nombre: ");
    scanf("%[^\n]%*c",nombre);
    
    printf("Introduzca sus apellidos: ");
    scanf("%[^\n]%*c",apellido);
    
    do{
     printf("Introduzca sus fecha de nacimiento en el formato dd/mm/aaaa: ");
     scanf("%[^\n]%*c",fecha);	
    
     formato = strlen(fecha); //se extrae la longitud de la fecha para verificar que tiene el tamanio solicitado	
	}while(formato!=10);
    
    catalogo();
    printf("Ingresa el codigo: ");
    scanf("%[^\n]%*c",lugar);
    
    char claveLugar = lugar[0];
    char claveLugar1 = lugar[1];
    
    printf("Introduzca su sexo H (hombre) o M (mujer): ");
    scanf("%s",sexo);
    
    /**
	 * Se piden los datos al usuario y se guardan en sus respectivas variables.
	 */
	 
	 
    curp[0]=apellido[0]; 
    
    /**
	 * Se extrae la letra inicial del primer apellido y se guarda en la primera posicion del CURP
	 */
    
    if(apellido[1]=='a' ||apellido[1]=='e' ||apellido[1]=='i' ||apellido[1]=='o' ||apellido[1]=='u' || apellido[1]=='A' ||apellido[1]=='E' ||apellido[1]=='I' ||apellido[1]=='O' ||apellido[1]=='U'){	
    curp[1]=apellido[1];
	}
	else{
		curp[1]=apellido[2];
	}
	
	/**
	 * Se extrae la primera vocal interna del primer apellido y se guarda en la segunda posicion del CURP
	 */
	 
	 
	int largoApellido = strlen(apellido); //se extrae la longitud de apellido para poderlo recorrer
	int i;
	
	for(i = 0; i < largoApellido; i++) {
            
            if (apellido[i] == ' ') {
                curp[2]=apellido[i+1];
            }
	}
	 
	/**
	 * Se extrae la letra inicial del segundo apellido
	 * Se recorre la cadena apellido buscando un espacio para poder obtener el 
	 * primer caracter del segundo apellido y se guarda en la tercera posicion del CURP
	 */
	
	 
	curp[3]=nombre[0]; 
	
	/**
	 * Se extrae la primera letra del nombre y se guarda en la cuarta posicion del CURP
	 */
  
  
    curp[4]=fecha[8]; //penultimo digito del año
    curp[5]=fecha[9]; ////ultimo digito del año
	curp[6]=fecha[3]; //primer digito del mes
	curp[7]=fecha[4]; //segundo digito del mes
	curp[8]=fecha[0]; //primer digito del mes
	curp[9]=fecha[1]; //segundo digito del mes
    
    /**
     * Se sabe que el formato de fecha dd/mm/aaaa tiene 10 caracteres
	 * Se extrae el penultimo (8 caracter porque la cuenta es desde 0) y ultimo (9 caracter) digito del año de nacimiento
	 *
	 * Tomando la misma logica podemos obtener el mes de nacimiento y dia de nacimiento
	 */
	
	
	curp[10]= sexo[0];
	
	/**
	 * Se agrega el Sexo al curp
	 */
	
	
	curp[11]= claveLugar;
	curp[12]= claveLugar1;
	
	/**
	 * Se agrega la entidad federativa al curp
	 */
	
	
	int k;
	for(k = 1; k < largoApellido; k++) {
            
        if(apellido[k]!='a' &&apellido[k]!='e' &&apellido[k]!='i' &&apellido[k]!='o' &&apellido[k]!='u' && apellido[k]!='A' &&apellido[k]!='E' &&apellido[k]!='I' &&apellido[k]!='O' &&apellido[k]!='U'){	
         curp[13]=apellido[k];
         break;
	    }
	}
	 
	/**
	 * Se extrae la Primera consonante interna del primer apellido
	 */
	 
	 int incioSegundoApellido;
	for(i = 0; i < largoApellido; i++) {
        if (apellido[i] == ' ') {
            //AQUI INICIA EL SEGUNDO APELLIDO
			incioSegundoApellido=i+2;		
        }
	}
	for(i=incioSegundoApellido; i < largoApellido; i++){
		if(apellido[i]!='a' &&apellido[i]!='e' &&apellido[i]!='i' &&apellido[i]!='o' &&apellido[i]!='u' && apellido[i]!='A' &&apellido[i]!='E' &&apellido[i]!='I' &&apellido[i]!='O' &&apellido[i]!='U'){	
         curp[14]=apellido[i];
         break;
	    }
	}
	/**
	 * Se busca donde inicia el segundo apellido
	 * Posteriormente se hace la busqueda de una consonante interna
	 */
	
	
	int largoNombre = strlen(nombre);
	for(k = 1; k < largoNombre; k++) {
            
        if(nombre[k]!='a' &&nombre[k]!='e' &&nombre[k]!='i' &&nombre[k]!='o' &&nombre[k]!='u' && nombre[k]!='A' &&nombre[k]!='E' &&nombre[k]!='I' &&nombre[k]!='O' &&nombre[k]!='U'){	
         curp[15]=nombre[k];
         break;
	    }
	}
	
	/**
	 * Se busca la consonante interna del nombre
	 */
	
	 
	 
    printf("\nImprimiendo CURP: %s \n" ,curp);
    printf("\n");
	return 0;
}
