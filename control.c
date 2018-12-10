/*====================================================
			File Fungsi-Fungsi Control
					WKJEK
					
	By Irfan Budi Satria
=====================================================*/

int choiceH=0, choiceV=0, code=-1, key=-1;  
//Kontroler Axis-H dan Axis-V Keyboard. Lihat Controls() 

void Controls(int cNumVert, int cNumHorz)		//Kontroler Axis-H dan Axis-V Keyboard, masukkan maksimum vertikal dan horizontal
{
    code = getch();	//getch pertama untuk dapatkan code
    
	if (code == 0 || code == 224)	
       key = getch(); //getch kedua untuk dapatkan key
       
    else if(code == 13)		//enter memiliki key dan code yang sama, sehingga bisa di skip di getch kedua
    	key = code;
	    
    switch(key){
    	
	case 75:					//key untuk panah kiri
		
		if(choiceH > 0)			//scrolling opsi choice horizontal, nilai minus
		choiceH--;
		
		else if(choiceH == 0)	//ketika berada di choice pertama, lompat ke choice terakhir
		choiceH = cNumHorz;
		
		break;	
			
	case 80:					//key untuk panah bawah
		
		if(choiceV < cNumVert)		//scrolling opsi choice vertikal, nilai plus
		choiceV++;
		
		else if(choiceV == cNumVert) //ketika berada di choice terakhir, lompat ke choice pertama
		choiceV = 0;
		
		break;
			
	case 72:					//key untuk panah atas
		
		if(choiceV > 0) //scrolling opsi choice vertikal, nilai minus
		choiceV--;	
		
		else if(choiceV == 0)  //ketika berada di choice pertama, lompat ke choice terakhir
		choiceV = cNumVert;
		
		break;
	
	case 77:				//key untuk panah kanan
		
		if(choiceH < cNumHorz)  //scrolling opsi choice horizontal, nilai plus
		choiceH++;
		
		else if(choiceH == cNumHorz) //ketika berada di choice terakhir, lompat ke choice pertama
		choiceH = 0;
		
		break;
		
	case 13:				//key untuk enter
		break;
			
	}
}

void ResetControls()		//Reset Kontroler. Taruh sebelum ada pilihan ganda
{
	choiceH=0; choiceV=0; code=-1; key=-1;
}

