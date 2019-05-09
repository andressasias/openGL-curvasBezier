//Desenvolvido por Andressa Sias

#include"graphics.h"
#include<conio.h>
#include<math.h>
#define TAM 500


void mapeamento(int xtmax, int xtmin, int ytmax, int ytmin, int xumax, int xumin, int yumax, int yumin, float xu, float yu );

float xt, yt;

void mapeamento(int xtmax, int xtmin, int ytmax, int ytmin, int xumax, int xumin, int yumax, int yumin, float xu, float yu ) {
	
	xt = ((xtmax - xtmin) * (xu - xumin))/(xumax - xumin) + xtmin;
    yt = ((ytmin - ytmax) * (yu - yumin))/(yumax - yumin) + ytmax;

}

void desenhaCurva(int px0, int px1, int px2, int px3,int py0, int py1, int py2, int py3, int maxx, int maxy){
	float t=0, px, py;
	while(t<1){
   	px = pow((1-t),3) * px0 + 3 * t * pow((1-t),2) * px1 + 3 * pow(t,2) * (1-t) * px2 + pow(t,3) * px3;
    py = pow((1-t),3) * py0 + 3 * t * pow((1-t),2) * py1 + 3 * pow(t,2) * (1-t) * py2 + pow(t,3) * py3;
    mapeamento(maxx, 0, maxy, 0, 6, 0, 6, 0, px, py);
	putpixel(xt, yt, BLUE);
	t = t + 0.0001;
   }
   getch();
   clearviewport();
}

int main()
{
   int maxx, maxy, poly[10], i, errorcode, nCurvas, resultado = 5, selecionaCurva = -1, guarda;
   int gd = DETECT, gm;
   int px0[TAM], px1[TAM], px2[TAM], px3[TAM];
   int py0[TAM], py1[TAM], py2[TAM], py3[TAM];	

   initgraph(&gd, &gm, " ");
   errorcode=graphresult();
   if(errorcode)
       exit(1);   
   maxx = getmaxx();
   maxy = getmaxy();
	
     
   	//• A criação de mais de uma curva, permitindo a inserção de seus pontos de controle
	printf("Digite Quantas curvas deseja criar:\n");
	scanf("%i", &nCurvas);
   	for (i = 0; i < nCurvas; ++i) {
   		
   		//guardo os pontos em vetores para cada ponto. Por exemplo: um vetor só dos pontos 0 do eixo x
   		printf("--Curva numero %i--\n",i+1);
   		printf("Digite o eixo x do ponto 0:\n");
		scanf("%i", &px0[i]);
		printf("Digite o eixo y do ponto 0:\n");
		scanf("%i", &py0[i]);
		printf("Digite o eixo x do ponto 1:\n");
		scanf("%i", &px1[i]);
		printf("Digite o eixo y do ponto 1:\n");
		scanf("%i", &py1[i]);
		printf("Digite o eixo x do ponto 2:\n");
		scanf("%i", &px2[i]);
		printf("Digite o eixo y do ponto 2:\n");
		scanf("%i", &py2[i]);
		printf("Digite o eixo x do ponto 3:\n");
		scanf("%i", &px3[i]);
		printf("Digite o eixo y do ponto 3:\n");
		scanf("%i", &py3[i]);
    }
    setviewport(0,0,maxx,maxy,1);
	 
    //desenhando as curvas
    for (i = 0; i < nCurvas; ++i) {
    	printf("Desenhando a curva %i. Tecle enter na janela para encerrar o desenho\n", i+1);
    	desenhaCurva(px0[i],px1[i],px2[i],px3[i],py0[i],py1[i],py2[i],py3[i],maxx, maxy);
	}
	printf("Fim dos desenhos das curvas\n");
	
	while(resultado!=0){
		printf("--O que deseja fazer?--\n");
		printf("- Para alterar Curvas, digite 1\n");
		printf("- Para excluir Curvas, digite 2\n");
		printf("- Para encerrar o programa digite 0\n");
		scanf("%i", &resultado);
		//	• A Alteração (substituição) de qualquer ponto de uma determinada curva
		if(resultado==1){
			//setando novamente a variável, porque ela pode ter sido usada antes.
			selecionaCurva=-1;
			printf("Voce criou %i curvas. Digite o numero da curva que quer alterar\n",nCurvas);
			scanf("%i", &selecionaCurva);
			if((selecionaCurva<0)||(selecionaCurva>nCurvas)){
				printf("Numero Invalido\n");
			}else{
				printf("--Alterando a curva numero %i--\n",selecionaCurva);
				selecionaCurva = selecionaCurva - 1;
   				printf("Digite o eixo x do ponto 0:\n");
				scanf("%i", &px0[selecionaCurva]);
				printf("Digite o eixo y do ponto 0:\n");
				scanf("%i", &py0[selecionaCurva]);
				printf("Digite o eixo x do ponto 1:\n");
				scanf("%i", &px1[selecionaCurva]);
				printf("Digite o eixo y do ponto 1:\n");
				scanf("%i", &py1[selecionaCurva]);
				printf("Digite o eixo x do ponto 2:\n");
				scanf("%i", &px2[selecionaCurva]);
				printf("Digite o eixo y do ponto 2:\n");
				scanf("%i", &py2[selecionaCurva]);
				printf("Digite o eixo x do ponto 3:\n");
				scanf("%i", &px3[selecionaCurva]);
				printf("Digite o eixo y do ponto 3:\n");
				scanf("%i", &py3[selecionaCurva]);
   				
				printf("Curva %i alterada\n",selecionaCurva);
				//desenhando as curvas
    			for (i = 0; i < nCurvas; ++i) {
    				printf("Desenhando a curva %i. Tecle enter na janela para encerrar o desenho\n", i+1);
    				desenhaCurva(px0[i],px1[i],px2[i],px3[i],py0[i],py1[i],py2[i],py3[i],maxx, maxy);
				}
				printf("Fim dos desenhos das curvas\n");
				}
		}else if(resultado==2){ //• Exclusão de curvas (e seus pontos de controle)
			//setando novamente a variável, porque ela pode ter sido usada antes.
			selecionaCurva=-1;
			printf("Voce criou %i curvas. Digite o numero da curva que quer excluir\n",nCurvas);
			scanf("%i", &selecionaCurva);
			if((selecionaCurva<0)||(selecionaCurva>nCurvas)){
				printf("Numero Invalido\n");
			}else{
				guarda = selecionaCurva;
				selecionaCurva = selecionaCurva - 1;
				for (i = 0; i < nCurvas; ++i) {
    				if(i==selecionaCurva){
    					px0[i]=px0[i+1];
    					px1[i]=px1[i+1];
    					px2[i]=px2[i+1];
    					px3[i]=px3[i+1];
    					py0[i]=py0[i+1];
    					py1[i]=py1[i+1];
    					py2[i]=py2[i+1];
    					py3[i]=py3[i+1];
    					selecionaCurva=i+1;
					}
				}
				printf("Curva %i excluIda, agora vocE tem %i curvas\n",guarda, nCurvas-1);
				nCurvas = nCurvas - 1;
				//desenhando as curvas
    			for (i = 0; i < nCurvas; ++i) {
    				printf("Desenhando a curva %i. Tecle enter na janela para encerrar o desenho\n", i+1);
    				desenhaCurva(px0[i],px1[i],px2[i],px3[i],py0[i],py1[i],py2[i],py3[i],maxx, maxy);
				}
				printf("Fim dos desenhos das curvas\n");
				}	
			
		}else if(resultado==0){
			break;
		}else{
			printf("Opcao invalida\n");
		}
	}
	printf("Programa encerrado\n");
	
   closegraph();
   return 0;
}
