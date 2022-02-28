#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;


/*
COMPARAR TRIPLETAS

//Comparacion de tripletas, comparando uno a uno
//gana un pt cada que su num en la tripleta es mayor, si son igual no se suma a nadie
*/
void compareTriplets1(int a[], int b[]){

    int resultado[]={0,0};
    for(int i=0;i<3;i++){
        //por cada iteracion 3 , en total 10 comparaciones en el peor caso 
        if(a[i]!=b[i]){
            if(a[i]>b[i])
                resultado[0]+= 1;
            else
                resultado[1]+= 1;
        }
    }
    cout << " resultado: "<< resultado[0] << " , "<< resultado[1] << endl;

}

/*
 Esta implementacion mejor en tiempo a la anterior ya que usa menos comparaciones y 
 evita muchos casos cuando no se cumple, es decir tiene un mejor en el mejor caso y en el peor
 caso es muy parecida.
*/

void compareTriplets2(int a[], int b[]){
    //se guarda la variable
    int resultado[]={0,0};
    int numero;
    //3 comparaciones y en el peor de los casos 11 operaciones
    if(a[0]!= b[0]){
        numero=(a[0]-b[0])/abs(a[0]-b[0]);
        resultado[0]+=numero+1;    //se le suma a dos puntos a 'a'             
        resultado[1]+=numero-1;    //se le suma 2 pts a 'b'
  }
    if(a[1]!=b[1]){
        numero=(a[1]-b[1])/abs(a[1]-b[1]);
        resultado[0]+=numero+1;        
        resultado[1]+=numero-1;
  }
    if(a[2]!=b[2]){
        numero=(a[2]-b[2])/abs(a[2]-b[2]);
        resultado[0]+=numero+1;
        resultado[1]+=numero-1;
  }
  resultado[0]=resultado[0]/2;      //divide entre 2 para obtener el resultado
  resultado[1]=abs(resultado[1]/2);

  cout << " resultado: "<< resultado[0] << " , "<< resultado[1] << endl;
}



string timeConversion1(string formatAP) {
	string format24h = formatAP.substr(2, 6); //:mm:ss
	int hrs = stoi(formatAP.substr(0,2)); //hh

	if(hrs==12){
		if(formatAP[8]=='A')
			hrs = 0; //Medianoche 00:mm:ss
	}else if(formatAP[8]=='P'){
		hrs += 12; //Horas de la tarde (13-23)
	}

	format24h = (hrs<10) ? "0"+to_string(hrs)+format24h : to_string(hrs)+format24h;

	return format24h;
}

/* Este es mejor al otro, ya que el anterior utiliza mas comparaciones 

*/
string timeConversion2(string formatAP) {
	string format24h = formatAP.substr(2, 6); //:mm:ss
	int hrs = stoi(formatAP.substr(0,2)); //hh
	int factor = ((hrs%12)/hrs); //Para PM: =0 si hrs=12 | =1 en otro caso
	
	if(formatAP[8]=='A')
        factor--; //Para AM: =-1 si hrs=12 | =0 en otro caso 
	
    hrs += (12 * factor);

	format24h = (hrs<10) ? "0"+to_string(hrs)+format24h : to_string(hrs)+format24h;
	
	return format24h;
}



//FALTA
int chocolateDivision(int arr[],int size, int mes, int dia){
    //dia: suma total de las porciones
    //mes: porciones de chocolate
    for(int i; i<(size%mes);i++){

    }
}




/*
MINION GAME

Otro approach para minion game fue el de guardar las letras en una lista y revisar si se encuentran ahi, 
no obstante para este se ocuparian 2 for por lo que seria menos optimizado

*/
void minionGame(string palabra){
    //puntaje[0] Kevin
    //puntaje[1] Stuart
    int puntaje[2]={0,0};

    //BANANA
    for(int contador=0;contador<palabra.length();contador++){
        puntaje[0]+=((palabra[contador]=='A'||palabra[contador]=='E'||palabra[contador]=='I'||palabra[contador]=='O'||palabra[contador]=='U')?
                        palabra.length()-contador:0);
        puntaje[1]+=((palabra[contador]!='A'&&palabra[contador]!='E'&&palabra[contador]!='I'&&palabra[contador]!='O'&&palabra[contador]!='U')?
                        palabra.length()-contador:0);
        //Devuelve la cantidad de palabras que pueden formarse si se encuentra una vocal o una constante

    }
    
    cout<<"Kevin "<<puntaje[0]<<endl;
    cout<<"Stuart "<<puntaje[1]<<endl;
   
}



void cypher(int n, int k, string s){
    //DECODIFICADOR
     /* n es la longitud del string resultado
        Calcular n utilizando k y la longitud de s */
    // int n = s.size()-(k-1);
    int respuesta[n];
    respuesta[0] = s[0];
    
    for(int i = 0; i < n; i++)
    {
        s[i] = (int)s[i]%48;
        
        // Asi se usa solamente un for, para elementos de 1 k-1 y de k en adelante
        if(i<k)
            respuesta[i]=s[i]^s[i-1];
        else
            respuesta[i]=s[i]^s[i-1]^respuesta[i-k];
        
        cout<<"Decode: "<<respuesta[i]<<endl;
        
    }    



}

int pairs(int k, vector<int> arr){
    // Ordenar el array(ascendente)
    sort(arr.begin(), arr.end());

    // {Pointer 2, NULL, Pointer1}
    int pointers[] = {1, 0};
    int resultado = 0;
    int diferencia = 0; 
    while (pointers[1] < arr.size()) {
        //cout<<pointers[0];
        //diferencia de punteros
        if(pointers[0]==arr.size()){
            pointers[0] = 0;
            pointers[1]++;
        }
        diferencia = arr[pointers[0]] - arr[pointers[1]]; //mayor - menor
        
        // Si es lo que busco, aumento pointer2
        if (diferencia == k) {
            resultado++;
            //cout<<"suma";
        }
        pointers[0]++;
    }
    return resultado;
}



int main(){
    //COMPARE TRIPLETS
    //#1
    int a[]= {20,28,50};
    int b[]= {50,60,70};
    cout<<"compareTriplets1: ";
    compareTriplets1(a,b);
    cout<<"compareTriplets2: ";
    compareTriplets2(a,b);
    //#2
    int c[] = {5,6,7};
    int d[] = {3,6,10};
     cout<<"compareTriplets1: ";
    compareTriplets1(c,d);
     cout<<"compareTriplets2: ";
    compareTriplets2(c,d);
    

    cout<<endl<< "Conversion de tiempo"<<endl;

	cout << timeConversion1("08:41:15PM") << endl;
	cout << timeConversion2("12:41:15PM") << endl;


    cout<<endl<< "Juego del minion"<<endl;
    cout<<"ARROZ"<< endl;
    minionGame("ARROZ");
    cout<<"BANANA"<<endl;
    minionGame("BANANA");


    cout<<endl<<"Decodificador"<<endl;
    cypher(7,4,"1110100110");
    cout<<endl<<"Decodificador"<<endl;
    cypher(6,2,"1110001");


    cout<<endl<<"Pairs"<<endl;
    vector<int> arr2 = {1, 5, 3, 4, 2};  //{1,2,3,4,5}
    vector<int> arr1 = {1, 3, 5, 8, 6, 4, 2}; //{1,2,3,4,5,6,8}
    
    cout << "Resultado: " << pairs(2, arr1) << endl;
    cout << "Resultado: " << pairs(2, arr2) << endl;


}



