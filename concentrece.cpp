#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int menu1(int opcion);
void mostrador(int cartas_restan, int igual,int cont);
int escan1(int car1,int cont1,int cartas[],int a);
int escan2(int car2,int cont1,int cartas[],int a);
void eliminar(int car1,int car2,int cont1,int cartas[],int a);
void opin(int car1,int car2,int cont1,int cartas[],int a);
int sum(int cont1,int igual);
int comprobar(int bande,int cont1);
void felicitaciones(int correc,int incorrec);

int main(){
    
    int cartas[16]={15,23,54,67,84,45,96,32,15,23,54,67,84,45,96,32};
	int cartas_restan=16;
	int igual=0;
	int cont1=0;
    int correc=0;
    int incorrec=0;
    int car1;
    int car2;
    int opcion;
    bool bande=false;
    
    do{
    	opcion=menu1(opcion);
    	if(opcion==1){
    		do{
    			system("cls");
    			mostrador(cartas_restan,igual,cont1);
    			car1=escan1(car1,cont1,cartas,16);
                car2=escan2(car2,cont1,cartas,16);
				igual=0;
    			opin(car1,car2,cont1,cartas,16);
    			if(car1<16-cont1 && car2<16-cont1){
    			    if(car1==car2){
		            }else{
    	                if(cartas[car1]==cartas[car2]){
						    igual=2;
						    eliminar(car1,car2,cont1,cartas,16);
			    		    correc++;
		    		    }else{
			    		    incorrec++;
			    	    }
    	    	    }	
				}
    			cont1=sum(cont1,igual);
    			bande=comprobar(bande,cont1);
			}while(bande!=true);	
	    }
	    system("cls");
	    felicitaciones(correc,incorrec);
	    system("cls");
    }while(opcion!=2);
    return 0;
}

int menu1(int opcion){
	printf("\n\n\n\n                        ________________________________\n");
	printf("                       |================================|\n");
	printf("                       |              MENU              |\n");
	printf("                       |================================|\n");
	printf("                       |                                |\n");
    printf("                       |      1. Juego de memoria.      |\n");
    printf("                       |                                |\n");
    printf("                       |      2. Salir                  |\n");
    printf("                       |________________________________|\n\n");
    printf("                          Escoja una opcion [1/2]: ");
    scanf("%d",&opcion);
    return opcion;
}



int escan1(int car1,int cont1,int cartas[],int a){
	int r=16-cont1;
    printf("\n\n           Digite el numero de la carta que quiere voltear [1-%d]: ",r);
    scanf("%d",&car1);
    car1=car1-1;
    return car1;
}
int escan2(int car2,int cont1,int cartas[],int a){
	int r=16-cont1;
	printf("\n         Digite el numero que cree que es igual, al anterior [1-%d]: ",r);
    scanf("%d",&car2);
    car2=car2-1;
    return car2;
}

void mostrador(int cartas_restan,int igual,int cont1){
	printf("\n\n\n                    ====================================\n");	
	printf("                    |        JUEGO DE CONCENTRESE      |\n");	
	printf("                    ====================================\n\n");	
    for(int cont=0;cont<16-cont1;cont++){
    	if(cont<9){
      	    if(cont==3 || cont==7 || cont==11 || cont==15){
          	    printf("           | %d |",cont+1);
          	    printf("\n");
		    }else{
			    printf("           | %d |",cont+1);
		    }
	    }else{
	    	if(cont==3 || cont==7 || cont==11 || cont==15){
          	    printf("           | %d|",cont+1);
          	    printf("\n");
		    }else{
			    printf("           | %d|",cont+1);
		    }
		}
    }
    printf("\n");
}

int sum(int cont1,int igual){
	if(igual==2){
      	cont1=cont1+igual;	
	}
	return cont1;
}

void eliminar(int car1,int car2,int cont1,int cartas[],int a){
	for(int cont=0;cont<16-cont1;cont++){
		if(cont>=car1){
			cartas[cont]=cartas[cont+1];
		}
	}
	for(int cont=0;cont<16-cont1;cont++){
		if(cont+1>=car2){
			cartas[cont]=cartas[cont+1];
		}
	}
	for(int cont=0;cont<16-cont1;cont++){
		if(cont==16-cont-1 && cont==16-cont){
			cartas[cont]=0;
		}
	}
}

void opin(int car1,int car2,int cont1,int cartas[],int a){
	if(car1<16-cont1 && car2<16-cont1){
    	if(car1==car2){
    		printf("\n\n            =======================================================");
	        printf("\n                  Vuelva a intentarlo, con numeros diferentes \n");
	        printf("            =======================================================");
            sleep(2);
		}else{
    	    if(cartas[car1]==cartas[car2]){
			    printf("\n\n            ======================================================");
			    printf("\n                     Muy bien encontro la pareja del: %d \n",cartas[car1]);
			    printf("            ======================================================");
			    sleep(2);
		    }else{
		   	    printf("\n\n            =======================================================");
	     	    printf("\n                  se equivoco de pareja, vuelva a intentarlo \n");
		   	    printf("            =======================================================");
				sleep(2);
		    }
		}	
	}else{
		printf("\n\n         =============================================================");
		printf("\n            Alguno de los numeros no es valido, vuelva a intentarlo \n");
		printf("         =============================================================");
		sleep(2);
	}
}

int comprobar(int bande,int cont1){
	if(cont1==16){
		bande=true;
	}
	return bande;
}

void felicitaciones(int correc,int incorrec){
	printf("\n\n\n\n\n\n                   __________________________________________\n");
	printf("                  |                                          |\n");
	printf("                  |>========================================<|\n");
	printf("                  |>             FELICITACIONES             <|\n");
	printf("                  |>         HAS COMPLETADO EL JUEGO        <|\n");
	printf("                  |>           errores cometidos: %d         <|\n",incorrec);
	printf("                  |>========================================<|\n");
    printf("                  |__________________________________________|\n");
    sleep(6);
}
