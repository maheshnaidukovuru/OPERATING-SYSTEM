#include <LPC214X.H>

#define DS3   1<<13		// P0.13
#define DS4   1<<12		// P0.12
#define SEG_CODE 0xFF<<16     // Segment Data from P0.16 to P0.23

unsigned char const seg_dat[]={0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x67};


void delayms(int n)
{
int i,j;
for(i=0;i<n;i++)
 {for(j=0;j<5035;j++)   //5035 for 60Mhz ** 1007 for 12Mhz
    {;}
 }
}

int main (void)
{
  unsigned char count;
 
PINSEL0 = 0; // Configure Port0 as General Purpose IO => P0.0  to P0.15
PINSEL1 = 0; // Configure Port0 as General Purpose IO => P0.16 to P0.31

IODIR0 = SEG_CODE | DS3 | DS4; //Configure Segment data & Select signal as output

IOSET0 = SEG_CODE | DS3 ;  //Disable DS3 display
IOCLR0 = DS4;  //Enable DS4 Display

count  = 0; //Initialize Count

//Display Count value
IOCLR0 = SEG_CODE;
IOSET0 = seg_dat[count]<<16;

while(1)
 {
   	delayms(1000); //1 sec delay
    count++;              //Increment count
    if(count>9) count=0;  //Limit 0-9

    //Display Count value
    IOCLR0 = SEG_CODE;
    IOSET0 = seg_dat[count]<<16;
	
   }

}
