#include <stdio.h>

void myStrcpy(char * dest, const char * src) {

	while (*src != NULL)
		*dest++ = *src++;

	*dest = '\0';
}

int myStrlen(char *s1)
{
	int cnt = 0;

	while (*s1 != '\0')
	{
		cnt++;
		s1++;
	}
	return	cnt;
}


int myStrcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1<*s2) return(-1);
	else if(*s1>*s2) return(1);
	else return(0);
}


int myAtoi(char * cTarget)
{
	int iChangeValue = 0;

	while (*cTarget != '\0' && (*cTarget >= '0' && *cTarget <= '9'))
	{
		// 현재 문자 변환시켜 기존에 있는 숫자에 더해준다.
		iChangeValue = (iChangeValue * 10) + ((int)*cTarget - (int)'0');
		cTarget++;   // 다음 문자로 이동
	}
	return iChangeValue;
}

int myAtoi2(char *str) {
	int tot = 0;
	while (*str) {    // NULL까지 
		tot = tot * 10 + *str - '0';  // 자리수를 올려주며 수를 가져옴 
		str++;    // 다음 문자 주소로 넘김 
	}
	return tot;
}

void itoa(int num, char *str) {
	int i = 0;
	int radix = 10;  // 진수 
	int deg = 1;
	int cnt = 0;

	while (1) {    // 자리수의 수를 뽑는다 
		if ((num / deg) > 0)
			cnt++;
		else
			break;
		deg *= radix;
	}
	deg /= radix;    // deg가 기존 자리수보다 한자리 높게 카운트 되어서 한번 나누어줌  
					 // EX) 1241 ->    cnt = 4; deg = 1000; 
	for (i = 0; i<cnt; i++) {    // 자리수만큼 순회 
		*(str + i) = num / deg + '0';    // 가장 큰 자리수의 수부터 뽑음 
		num -= ((num / deg) * deg);        // 뽑은 자리수의 수를 없엠 
		deg /= radix;    // 자리수 줄임 
	}
	*(str + i) = '\0';  // 문자열끝널.. 
}




int main()
{
	return 0;
}


