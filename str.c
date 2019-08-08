
#include "common.h"
#include "str.h"

void str_trim_crlf(char * str)
{
	char *p = &str[strlen(str) - 1];
	//ѭ��ȥ��ĩβ���е�/r/n
	while (*p == '\r' || *p == '\n')
		*p-- = '\0'; //��*p��ֵ��--
}

void str_split(const char * str, char * left, char * right, char c)
{
	//���ص�һ��ָ��c��ָ��
	char *p = strchr(str, c);
	if (p == NULL)
		strcpy(left, str);
	else {
		strncpy(left, str, p - str);
		//while (*(++p) == c);
		//strcpy(right, p);
		strcpy(right, p + 1);
	}

}

int str_all_space(const char * str)
{
	char *p = (char*)str; //no warning
	while (*p) { //ֻҪ��һ�����ǿո�ͷ���
		if (!isspace(*p)) 
			return 0;
		p++;
	}
	return 1;
}

void str_upper(char * str)
{
	//char *p = str;
	while (*str) {
		*str = toupper(*str);
		str++;
	}
		
}

long long str_to_ll(const char * str)
{
	//return atoll(str);
	//long long ret = 0;
	//long long mult = 1;
	//size_t len = strlen(str);
	//size_t i;

	//if (len > 19)
	//	return 0;
	//for (i = 0; i < len; ++i) {
	//	char ch = str[len - (i + 1)];
	//	long long val;
	//	if (ch < '0' || ch > '9')
	//		return 0;
	//	val = ch - '0';
	//	val *= mult;
	//	ret += val;
	//	mult *= 10;
	//}
	//return ret;

	int i;
	long long ret = 0;
	int len = strlen(str);
	if (len > 16)
		return 0;
	for (i = 0; i < len; ++i) {
		char ch = str[len - (i + 1)];
		if (ch < '0' || ch > '9')
			return 0;
		ret += (ch - '0')*pow(10, i);
	}
	return ret;
}


unsigned int str_octal_to_uint(const char * str)
{
	int i;
	unsigned int ret = 0;
	int len = strlen(str);
	if (len > 9)
		return 0;
	for (i = 0; i < len; ++i) {
		char ch = str[len - (i + 1)];
		if (ch < '0' || ch > '7')
			return 0;
		ret += (ch - '0')*pow(8, i);
	}
	return ret;
}
