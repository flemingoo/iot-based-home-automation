void PLL_Config() // For 60MHz PCLK
{
	PLL0CFG=0x24;  //Multipler = 5 and divider = 2 =>  CCLK = 12*5 = 60MHz
  PLL0CON=0x01;  //Enable PLL
  PLL0FEED=0xAA; //Feed sequence
  PLL0FEED=0x55;
  while(!(PLL0STAT & 0x0400)) ; //is locked?
  PLL0CON=0x03;  //Connect PLL after PLL is locked
  PLL0FEED=0xAA; //Feed sequence
  PLL0FEED=0x55;
  VPBDIV=0x00;	//VPB=PCLK
}
