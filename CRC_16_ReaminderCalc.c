#include <stdio.h>

int crc_16 = 0x018005; // x16 + x15 + x2 + 1

int count_bits(char input) {
	int count = 0;

	for (int i = 0; i < 8; i++) {
		if (input & (1 << i)) count++;
	}

	return count % 2 ? 1 : 0; // count가 홀수이면 1, 짝수이면 0 리턴
}


int main() {
	int count = 0; // queue 적재 상태 확인
	int queue = 0; // 문자 입력시 하위 8비트에 문자 삽입
	
	unsigned char input = 0, tmp = 0;
	char result[17];
	
	while (1) {
		input = getchar();
		if (input == '\n') break;

		//even parity 우측에 추가
		tmp = input << 1;
		tmp += count_bits(input);
		count++;
		
		// queue가 0 ? ? ? 상태가 되지 않도록 tmp 비트를 하나씩 밀어넣으며 xor 수행
		if(count > 2){
			for(int i=0; i<8; i++){
				queue = (queue << 1) | ((tmp & 0x80) >> 7);
				
				if(queue & 0x10000) queue ^= crc_16;
				tmp = tmp << 1;
			}
			
			count--;
		}
		// queue에 입력받은 문자 삽입
		else queue = (queue << 8) | tmp;
	}
	
	for(int i=0; i<16; i++){
		queue = (queue << 1);

		if(queue & 0x10000) queue ^= crc_16;
	}
	
	for (int i = 0; i < 16; i++) {
		result[i] = (queue & (0x8000 >> i)) ? '1' : '0';
	}
	result[16] = '\0';
	
	printf("%s", result);

	return 0;
}