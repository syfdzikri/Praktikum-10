#include<math.h>
String dataIn;
String dt[10];
int i;
float al,a,b,c;
boolean parsing=false;
void setup() {
   Serial.begin(9600);
   dataIn="";
   
  Serial.println("Program Menghitung sudut alpha segita siku - siku");
  Serial.println("Format Inputan data harus '*' atau ','");
    Serial.println("Contoh *A*B*C atau ,A,B,C atau *A,B,C");
      Serial.print("A Merupakan sisi Samping B Merupakan sisi depan C merupakan sisi Miring");
}
void loop() {
  if(Serial.available()>0) {
    char inChar = (char)Serial.read();
    dataIn += inChar;
    if (inChar == '\n') {
    parsing = true;
  }
}
 
if(parsing){
    parsingData();
    parsing=false;
    dataIn="";
  }
}
void parsingData(){
int j=0;

//kirim data yang telah diterima sebelumnya
Serial.print("data masuk : ");
Serial.print(dataIn);
Serial.print("\n");

//inisialisasi variabel, (reset isi variabel)
dt[j]="";
//proses parsing data
for(i=1;i<dataIn.length();i++){
//pengecekan tiap karakter dengan karakter (#) dan (,)
if ((dataIn[i] == '*') || (dataIn[i] == ','))
{
//increment variabel j, digunakan untuk merubah index array penampung
j++;
dt[j]="";       //inisialisasi variabel array dt[j]
}
else
{
//proses tampung data saat pengecekan karakter selesai.
dt[j] = dt[j] + dataIn[i];
}
}
b=dt[0].toFloat();
a=dt[1].toFloat();
c=dt[2].toFloat();
al=atan(b/a)*180/3.14;
//kirim data hasil parsing
Serial.print("Panjang A : ");
Serial.print(b);
Serial.print(" cm\n");
Serial.print("Panjang B : ");
Serial.print(a);
Serial.print(" cm\n");
Serial.print("Panjang C : ");
Serial.print(c);
Serial.print(" cm\n");
Serial.print("Sudut alpha : ");
Serial.print(al);
Serial.print(" derajat\n\n");
}

