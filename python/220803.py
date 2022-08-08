# # 계산기
# while True:
#     try:
#         val1 = int(input('값1 : '))
#         oper = input('연산자(+,-,*,/) 입력 : ')
#         val2 = int(input('값2 : '))
#         if oper == '+':
#             print(val1+val2)
#         elif oper == '-':
#             print(val1-val2)
#         elif oper == '*':
#             print(val1*val2)
#         elif oper == '/':
#             print(val1/val2)
#         else:
#             print('오류 다시입력')
#     except:
#         print('오류 다시입력')


# 대문자 소문자 숫자를 세는 프로그램

in_str = input('입력 : ')

str_length = len(in_str)
number = 0
lowercase = 0
uppercase = 0
other = 0


for in_ch in in_str:
    if in_ch>= '0' and in_ch <= '9':
        number += 1
    elif in_ch>= 'a' and in_ch<= 'z':
        lowercase += 1
    elif in_ch>= 'A' and in_ch<= 'Z':
        uppercase += 1
    else:
        other += 1

print(f'''총길이 {str_length}개,숫자 {number}개, 소문자 {lowercase}개, 대문자 {uppercase}개, 그외 {other}개''')
