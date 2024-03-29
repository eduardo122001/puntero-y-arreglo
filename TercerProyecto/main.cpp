#include <iostream>

using namespace std;


void cambio(int &x,int &y){
    int m=x;
    x=y;
    y=m;
}

void cambiop(int *x ,int *y){
    int m=*x;
    *x=*y;
    *y=m;

}


void imprimir(int *a,int tam){
    int t=0;
    while(tam--){
        cout<<*a<<endl;
        a++;
    }
}
int SumaIte(int *a,int tam){
    int suma=0;
    while(tam--){
        suma+=*a;
        a++;
    }
    return suma;
}

int SumaRec(int *a,int tam){
    if(tam==1)
        return *a;
    else
        return *(a+tam-1) + SumaRec(a,tam-1);
}

void invertir(int *a,int tam){
    int t=0;
    int m=tam/2;
    while(m--){
        cambiop(a+t,a+tam-1-t);
        t++;
    }

}






void invertirRec2(int *a,int tam){
    --tam;
    if((a+1==a+tam-1)||(a+1==a+tam)){
        cambiop(a+tam,a);
        return;}
    else{
        cambiop(a+tam,a);
        return invertirRec2(++a,--tam);

}
}

void burbuja(int *a,int tam){
    for(int i=0;i<tam;++i){

        for(int j=0;j<tam-i;++j){
            if(*(a+j)>*(a+j+1)){
                cambiop(a+j,a+j+1);
            }
        }
    }
}

void insercion(int *a,int tam){
    for(int i=0;i<tam;++i){
        int x=*(a+i);
        int j=i;
        while((j>0)&&(*(a+j-1)>x)){
            *(a+j)=*(a+j-1);
            j-=1;
            *(a+j)=x;
        }
    }
}


int particion(int *a,int ini,int fin){
    int pivote=*(a+fin);
    int index=ini;

    for(int i=ini;i<fin;i++){
    	if(*(a+i)<=pivote){
            cambiop(a+i,a+index);
            index++;
        }
     }
      cambiop(a+fin,a+index);
     return index;
}

void quicksort(int *a,int ini,int fin){
    if(ini<fin){
        int p=particion(a,ini,fin);
        quicksort(a,ini,p-1);
        quicksort(a,p+1,fin);
    }
    else
        return;


}


int main()
{
    int a=12;

    int m[]={9,6,8,3,5,7,2,11,12,4,1,10};
    quicksort(m,0,a);
    //insercion(m,a);
    //burbuja(m,a);
    imprimir(m,a);
    //int t=SumaRec(m,a);
    //cout<<t;







    return 0;
}
