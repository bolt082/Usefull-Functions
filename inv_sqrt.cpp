float InvSqrt(float x){
     float xhalf = 0.5f*x;
     int i = 0x5f375a86 - ((*(int*)&x)>>1);
     x = (*(float*)&i)*(1.5f-xhalf * (*(float*)&i) * (*(float*)&i));
     return x;
}