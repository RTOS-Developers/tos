void TaskPlan(void *Tags)
{
	ADC1_Init((uintbus)&UIShowValue.ADC[0]);
	Sensor_Init();
	ISL1208_Init((void *)IO_ISL1208_P);
	DS_Read_Value(&UIShowValue.CH_Value[0],&UIShowValue.CH_Value[1]);
	Tos_TaskDelay(1000);
	DS_Read_Value(&UIShowValue.CH_Value[0],&UIShowValue.CH_Value[1]);
	while(1)
	{
		ISL1208_GetDateTime(&UIShowValue.DateTime);	
		//DeBug("20%02d-%02d-%02d %02d:%02d",UIShowValue.DateTime.Year,UIShowValue.DateTime.Mon,UIShowValue.DateTime.Day,UIShowValue.DateTime.Hour,UIShowValue.DateTime.Min,0);
		Tos_TaskDelay(500);
		DS_Read_Value(&UIShowValue.CH_Value[0],&UIShowValue.CH_Value[1]);
		if(UIShowValue.RunFlag&WRF_RecordEN)Task_Record();
		Task_Plan();
	}
}
void TaskBigShow()
{
	uint8 i=30;
	while(i--)
	{
	IO_Set(1,False);
	IO_Set(0,False);
	Tos_TaskDelay(100);
	IO_Set(1,True);
	IO_Set(0,True);
	Tos_TaskDelay(100);
	}
}
