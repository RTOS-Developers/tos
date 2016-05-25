extern void VisualCOM_Writes(char *Buf,uint16 Length);
void Action_Port_Set(char *Str)
{
	char *P=Str,*T;
	GPIO_TypeDef *GPIOx;
	uint16 GPIO_Pin_x;
	T=Strstr(P,"p");
	if(T)
	{
		
		switch(T[1])
		{
			case 'a':GPIOx=GPIOA;break;
			case 'b':GPIOx=GPIOB;break;
			case 'c':GPIOx=GPIOC;break;
			case 'd':GPIOx=GPIOD;break;
			case 'e':GPIOx=GPIOE;break;
			case 'f':GPIOx=GPIOF;break;
		}
		GPIO_Pin_x=1<<(T[2]-'0');
		T=Strstr(T,",");
		if(T[1]=='0')GPIO_ResetBits(GPIOx,GPIO_Pin_x);
		if(T[1]=='1')GPIO_SetBits(GPIOx,GPIO_Pin_x);
	}
	
}
void Action_Port_Cfg(char *Str)
{
	char *P=Str,*T;
	T=Strstr(P,"pa");
	if(T)
	{
		//GPIO_ResetBits(GPIOC,GPIO_Pin_0)
		return;
	}
	T=Strstr(P,"cfg");
	if(T)
	{
		//Action_Port_Cfg(T);
		return;
	}
	
}
void Action_Port(char *Str)
{
	char *P=Str,*T;
	T=Strstr(P,"set");
	if(T)
	{
		Action_Port_Set(T);
		return;
	}
	T=Strstr(P,"cfg");
	if(T)
	{
		Action_Port_Cfg(T);
		return;
	}
}
void Action_Delay_Ms(char *Str)
{
	char *P=Str,*T;
	uint32 Delay;
	T=Strstr(P,".");
	Delay=GetStringToNumber((uint8*)&T[1]);
	Tos_TaskDelay(Delay);
}
void Action_Delay_S(char *Str)
{
	
}
void Action_Delay(char *Str)
{
	char *P=Str,*T;
	T=Strstr(P,"ms");
	if(T)
	{
		Action_Delay_Ms(T);
		return;
	}
	T=Strstr(P,"s");
	if(T)
	{
		Action_Delay_S(T);
		return;
	}
}
void Bast_Export(char *Str)
{
	char *P=Str,*T;
	T=Strstr(P,"port");
	if(T)
		{
			Action_Port(T);
			return;
		}
	T=Strstr(P,"delay");
	if(T)
		{
			Action_Delay(T);
			return;
		}
}
