//============================================================================
// Name        : musaKavus-150101053.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Steam Kutuphanesi C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
struct node{
	int OgrenciNotu;
	struct node* next;
};
struct node* start=NULL; // bu benim baslangic dugumum.
struct node* temp=NULL; // bu benim gecici dugumum.
struct node* q=NULL;    // yazdir fonksiyonumda lazım olacak.

void SonaEkle(int veri){//kendisine gonderilecek parametreyi bagli liste icerisinde en sona eklicek.
	struct node* eklenecek=(struct node*)malloc(sizeof(struct node)); //veri eklicez ya bana bir dügüm ve alan lazım.
	eklenecek->OgrenciNotu=veri;
	eklenecek->next=NULL;
	//bu benim dugumum ama esas mesela nereye eklenecek.

	if(start==NULL){ //start dugumumun adresi null ise
		start=eklenecek; /*benim ilk ekledigim dugum start dugumu olsun.
		yani eger hicbirsey yoksa ilk ekleyecegim dugum start dugumu olsun*/

	}
	else{ //ha eger varsa
		q=start; //q yu starta atıyorum.
		while(q->next!=NULL){ //q nun adresi null olmadigi surece bir sonraki dugume esitle. ki son Notı bulayım.
			q=q->next;
		}
		q->next=eklenecek; //son q->next Noti normalde null. ama ben bunu sona ekleyecegim icin bu  dugume esitlicem.
	}

}
void BasaEkle(int veri){
	struct node* YeniNode=(struct node*)malloc(sizeof(struct node*)); //bellekte alan olusturduk.
	YeniNode->OgrenciNotu=veri; //parametre degerini alacak.
	YeniNode->next=start;
	start=YeniNode;
}
void ArayaEkle(int x,int y){
	struct node* arayaEklenecek=(struct node*)malloc(sizeof(struct node));
	arayaEklenecek->OgrenciNotu=y;
	q=start;
	while(q->next->OgrenciNotu!=x){
		q=q->next;
	}
	struct node* onune=(struct node*)malloc(sizeof(struct node));
	onune=q->next;
	q->next=arayaEklenecek;
	arayaEklenecek->next=onune;
}
void SondanSilme(){
	q=start;
	while(q->next->next!=NULL){
		q=q->next;
	}
	delete q->next;
	q->next=NULL;
}
void BastanSilme(){
	struct node* ikinci=NULL;
	ikinci=start->next;
	delete start;
	start=ikinci;
}
void AradanSilme(int x){
	if(start->OgrenciNotu==x)
	{
		BastanSilme();
	}
	struct node *onceki=NULL;
	struct node* sonraki=NULL;
	q=start;
	while(q->next->OgrenciNotu!=x){
		q=q->next;
	}
	if(q->next==NULL){
		SondanSilme();
	}
	onceki=q;
	sonraki=q->next->next;
	delete q->next;
	onceki->next=sonraki;
}
void TersYazdirma(){
	struct node* temp;
	struct node* prev=NULL;
	q=start;
	while(q!=NULL){
		temp=q->next;
		q->next=prev;
		prev=q;
		q=temp;
	}
	start=prev;
}
void yazdir(){
	q=start; // q degiskenini surekli starta atıyorum ki start degerini bozmiim.
	while(q->next!=NULL){
		cout<<"->"<<q->OgrenciNotu<<" ";
		q=q->next; //sondaki Notı yazdirmiyor bu dongu. o yuzden dongu cikisinda
	}
	cout<<"->"<<q->OgrenciNotu<<"->"<<endl;
}

int main() {
	int secim, sona, basa, x, y;
	while(1==1){
	cout<<"Sona Not Eklemek icin ------->1: "<<endl;
	cout<<"Basa Not Eklemek icin ------->2: "<<endl;
	cout<<"Araya Not Eklemek icin ------->3: "<<endl;
	cout<<"Sondan Not Silmek icin ------->4: "<<endl;
	cout<<"Bastan Not Silmek icin ------->5: "<<endl;
	cout<<"Aradan Not Silmek icin ------->6: "<<endl;
	cout<<"Ters Cevirmek icin -------------->7: "<<endl;
	cout<<"Yapmak istediginiz islemi girin: ";
	cout<<" "<<endl;
	cin>>secim;
	switch(secim){
	case 1: cout<<"Sona Eklemek istediginiz Notu girin..."<<endl;
		cin>>sona;
		SonaEkle(sona);
		yazdir();
		break;

	case 2: cout<<"Basa Eklemek istediginiz Notu girin..."<<endl;
		cin>>basa;
		BasaEkle(basa);
		yazdir();
		break;

	case 3:	cout<<"Hangi notun onune ekleme yapmak istiyorsunuz: ";
		cin>>x;
		cout<<"Hangi notu gireceksiniz: ";
		cin>>y;
		ArayaEkle(x,y);
		yazdir();
		break;

	case 4:
		SondanSilme();
		yazdir();
		break;

	case 5: BastanSilme();
		yazdir();
		break;

	case 6: cout<<"Silinmesini istedigin notu gir: ";
	cin>>secim;
	AradanSilme(secim);
	yazdir();
	break;

	case 7: TersYazdirma();
	yazdir();
	break;
	}
	}
return 0;
}
