
## -Input

  Alphabet(대문자, 소문자)과 숫자로 이루어진 문장을 입력

  문장 길이는 정해져있지 않음
  
  예: abc
  
## - 입력된 각 character를 8bit 값으로 변환

  ASCII 값은 7bit이므로, even parity bit를 추가해 8bit로 변환
  
  even parity는 오른쪽에 추가함

## -CRC-16 식을 이용해 CRC 결과값(remainder값)을 출력함

  CRC-16은 “x16+x15+x2+1” 을 사용함
